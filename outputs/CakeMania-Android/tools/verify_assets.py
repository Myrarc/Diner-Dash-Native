#!/usr/bin/env python3
"""Validate imported bytes and animation references before packaging."""
from pathlib import Path
import hashlib
import json
import re
import subprocess
import wave
import xml.etree.ElementTree as ET
from PIL import Image

root = Path(__file__).resolve().parents[1]
assets = root / 'assets'
manifest = json.loads((root / 'asset-preparation.json').read_text())
for name, expected in manifest['asset_sha256'].items():
    actual = hashlib.sha256((assets / name).read_bytes()).hexdigest()
    assert actual == expected, f'Imported asset changed: {name}'

resources = {e.get('id'): e.get('path') for e in ET.parse(assets / 'resources.xml').getroot()}
dimensions = {}
for resource, name in resources.items():
    path = assets / name
    assert path.is_file(), f'Missing resource: {resource}'
    if path.suffix.lower() in {'.png', '.jpg', '.jpeg'}:
        with Image.open(path) as im:
            dimensions[resource] = im.size
            im.verify()

animations = 0
missing = {}
for config in (assets / 'config').rglob('*.xml'):
    document = ET.parse(config)
    for element in document.iter():
        for value in element.attrib.values():
            if re.fullmatch(r'(IMAGE|SOUND)_[A-Z0-9_]+', value):
                if value not in resources:
                    missing.setdefault(value, set()).add(config.relative_to(assets).as_posix())
        if element.tag == 'Image' and element.get('cols') and element.get('rows'):
            cols, rows = int(element.get('cols')), int(element.get('rows'))
            w, h = dimensions[element.get('img')]
            assert cols > 0 and rows > 0 and w // cols > 0 and h // rows > 0
            sequence = element.find('Sequence')
            if sequence is not None:
                for frame in sequence.get('frames').split(','):
                    assert 0 <= int(frame) < cols * rows, f'{config}: invalid sprite frame'
            animations += 1

used = {'IMAGE_MMENU_FIRE'+str(i) for i in range(1,5)}
for source in (root / 'src').rglob('*.java'):
    used.update(re.findall(r'"((?:IMAGE|SOUND)_[A-Z0-9_]+)"', source.read_text()))
    if source.name == 'GameEngine.java':
        used.update('SOUND_'+s for s in re.findall(r'sound\("([A-Z0-9_]+)"\)',source.read_text()))
used.discard('IMAGE_MMENU_FIRE')  # Prefix for the four verified flames.
assert not used - resources.keys(), f'Missing resource used by Android code: {used - resources.keys()}'
for resource, configs in missing.items():
    assert not any(p.startswith('config/level') or p in {'config/mainconfig/cakes.xml','config/mainconfig/customers.xml'} for p in configs), f'Missing gameplay resource: {resource}'

decoded = 0
for original in sorted(list((assets / 'original/sounds').glob('*.ogg')) + list((assets / 'music').glob('*.ogg'))):
    pcm = assets / 'decoded-audio' / original.relative_to(assets).with_suffix('.wav')
    reference = subprocess.run(['ffmpeg','-hide_banner','-loglevel','error','-i',str(original),'-c:a','pcm_s16le','-f','s16le','-'],check=True,capture_output=True).stdout
    with wave.open(str(pcm),'rb') as w:
        assert w.getsampwidth() == 2
        assert w.readframes(w.getnframes()) == reference, f'Decoded audio content changed: {original}'
    decoded += 1

result = {'passed': True, 'imported_files_hashed': len(manifest['asset_sha256']),
          'resource_files_checked': len(resources), 'images_verified': len(dimensions),
          'customer_animation_sequences_checked': animations,
          'decoded_pcm_audio_matched_to_originals': decoded,
          'unresolved_references_in_unused_original_screens': {k:sorted(v) for k,v in sorted(missing.items())}}
print(json.dumps(result, indent=2))
