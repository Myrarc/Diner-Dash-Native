from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import base64
import hashlib
import json
import shutil
import subprocess
import os
from lingo_data import parse_lingo

APP = Path(__file__).resolve().parent.parent.parent
RECOVERY = Path(os.environ.get('DINER_RECOVERY', str(APP.parent / 'DinerDash-recovered')))
ASSETS = APP / 'assets'
WORK = Path(os.environ.get('DINER_IMPORT_WORK', str(APP / '.import-work')))
JAVA = str(Path(os.environ.get('JAVA_HOME', '/opt/homebrew/opt/openjdk@21')) / 'bin/java')
ASSETS.mkdir(exist_ok=True)
WORK.mkdir(parents=True, exist_ok=True)

containers = sorted((RECOVERY / 'reconstructed').rglob('*.cst')) + sorted((RECOVERY / 'reconstructed').rglob('*.dir'))


def extract(source):
    cast = source.stem.replace(' ', '_')
    result = subprocess.run([JAVA, '-Djava.awt.headless=true', '-Xmx1024m', '-cp', str(WORK / 'director-sdk-classes'),
                             'ExtractDinerAssets', str(source), str(ASSETS), cast], capture_output=True, text=True, timeout=180)
    log = WORK / 'asset-extraction-logs' / (cast + '.log')
    log.parent.mkdir(exist_ok=True)
    log.write_text(result.stdout + result.stderr)
    print(result.stdout.strip().splitlines()[-1] if result.stdout.strip() else f'{cast}: exit={result.returncode}', flush=True)
    return source, cast, result.returncode


with ThreadPoolExecutor(max_workers=2) as pool:
    results = list(pool.map(extract, containers))
inventory = []
for source, cast, exit_code in results:
    table = ASSETS / (cast + '.tsv')
    if not table.exists():
        raise RuntimeError(f'Asset inventory missing: {source}, exit={exit_code}')
    for line in table.read_text().splitlines():
        columns = line.split('\t')
        assert len(columns) == 15, columns
        record = dict(zip(['cast', 'chunk_id', 'member_number', 'type', 'name_base64', 'width', 'height', 'bit_depth',
                           'reg_x', 'reg_y', 'path', 'status', 'sample_rate', 'bits_per_sample', 'channels'], columns))
        record['name'] = base64.b64decode(record.pop('name_base64')).decode()
        for key in ['chunk_id', 'member_number', 'width', 'height', 'bit_depth', 'reg_x', 'reg_y', 'sample_rate', 'bits_per_sample', 'channels']:
            record[key] = int(record[key])
        record['source_container'] = source.relative_to(RECOVERY).as_posix()
        if record['path']:
            file = ASSETS / record['path']
            record['bytes'] = file.stat().st_size
            record['sha256'] = hashlib.sha256(file.read_bytes()).hexdigest()
        inventory.append(record)
    table.unlink()

casts = json.loads((RECOVERY / 'embedded-casts.json').read_text())['entries']
aliases = {entry['name']: Path(entry['filePath'].replace('\\', '/')).stem
           for entry in casts if entry['filePath']}
(ASSETS / 'asset-index.json').write_text(json.dumps({'cast_aliases': aliases, 'members': inventory}, separators=(',', ':')) + '\n')

config = {}
for source in sorted((RECOVERY / 'data/ext/conf').glob('*_dump.txt')):
    config[source.stem.removesuffix('_dump')] = parse_lingo(source.read_text())
(ASSETS / 'game-config.json').write_text(json.dumps(config, separators=(',', ':')) + '\n')
layouts = {}
failures = []
for source in sorted((RECOVERY / 'data/ext/layout').glob('*.txt')):
    text = source.read_text()
    if text.lstrip().startswith('['):
        try:
            layouts[source.stem] = parse_lingo(text)
        except (ValueError, AssertionError, IndexError) as error:
            failures.append({'file': source.name, 'error': str(error)})
(ASSETS / 'layouts.json').write_text(json.dumps(layouts, separators=(',', ':')) + '\n')
summary = {'containers': len(results), 'cast_members': len(inventory),
           'images': sum(r['type'] == 'BITMAP' and r['status'] == 'exported' for r in inventory),
           'sounds': sum(r['type'] == 'SOUND' and r['status'] == 'exported' for r in inventory),
           'media_errors': [r for r in inventory if r['status'].startswith('ERROR')],
           'config_records': len(config), 'layout_records': len(layouts), 'layout_parse_failures': failures,
           'libreshockwave_commit': 'b114ae65ec6acd1e576ba5dc37a4f7ace113cb45'}
(APP / 'asset-import-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary, indent=2))
assert not summary['media_errors'], 'Media extraction has unresolved errors'
