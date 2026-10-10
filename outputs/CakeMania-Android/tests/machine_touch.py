#!/usr/bin/env python3
"""Native-machine touch regression on a disposable emulator, using actual taps.

qa_level exposes snapshots and enters January; it never executes an action.
The original XML supplies all shape/color hit coordinates. Saved career data is
restored after the stock and purchased-equipment runs, including on failure.
"""
from pathlib import Path
import hashlib
import json
import os
import re
import subprocess
import sys
import time
import xml.etree.ElementTree as ET
from PIL import Image, ImageChops, ImageFilter, ImageStat

APP = Path(__file__).resolve().parents[1]
ADB = str(Path(os.environ.get('ANDROID_HOME', str(Path.home() / 'Library/Android/sdk'))) / 'platform-tools/adb')
PACKAGE = 'local.cakemania'
OUT = Path(sys.argv[1]) if len(sys.argv) > 1 else APP / 'verification/direct-machines/gameplay'
OUT.mkdir(parents=True, exist_ok=True)
config = APP / 'assets/config'
environment = ET.parse(config / 'level1/career/january_env.xml').getroot()
defs = {n.get('guid'): n for n in environment.iter() if n.get('x_global')}
points = ET.parse(config / 'level1/pathes.xml').getroot().find('CustomerPath').findall('Point')
bakery = next(ET.parse(config / 'level1/level_definitions.xml').getroot().iter('Level'))
upgrades = list(ET.parse(config / bakery.get('name_xml_upgrades').lower()).getroot().iter())
actions = []
checks = []
transform = (1, 0, 0)


def adb(*args):
    return subprocess.check_output([ADB, *args], stderr=subprocess.PIPE)


def pref_files():
    try:
        listing = adb('shell', 'run-as', PACKAGE, 'ls', 'shared_prefs').decode()
    except subprocess.CalledProcessError:
        return []
    return sorted(name.strip() for name in listing.splitlines() if name.strip())


def snapshot_prefs():
    return {name: adb('shell', 'run-as', PACKAGE, 'cat', 'shared_prefs/' + name)
            for name in pref_files()}


def write_pref(name, contents):
    path = OUT / ('seed-' + re.sub(r'[^A-Za-z0-9_.-]', '_', name))
    path.write_bytes(contents)
    remote = '/data/local/tmp/' + path.name
    adb('push', str(path), remote)
    adb('shell', 'run-as', PACKAGE, 'mkdir', '-p', 'shared_prefs')
    adb('shell', 'run-as', PACKAGE, 'cp', remote, 'shared_prefs/' + name)
    adb('shell', 'rm', remote)


def restore_prefs(snapshot):
    for name in pref_files():
        adb('shell', 'run-as', PACKAGE, 'rm', 'shared_prefs/' + name)
    for name, contents in snapshot.items():
        write_pref(name, contents)
        (OUT / ('seed-' + re.sub(r'[^A-Za-z0-9_.-]', '_', name))).unlink(missing_ok=True)


def restore_display(original):
    override = re.search(r'Override size:\s*(\d+x\d+)', original)
    adb('shell', 'wm', 'size', override.group(1) if override else 'reset')


def state():
    for _ in range(20):
        try:
            return json.loads(adb('shell', 'run-as', PACKAGE, 'cat', 'files/qa-state.json'))
        except (json.JSONDecodeError, subprocess.CalledProcessError):
            time.sleep(.1)
    raise AssertionError('No valid QA snapshot')


def wait(predicate, timeout=20):
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        value = state()
        if predicate(value):
            return value
        time.sleep(.15)
    raise AssertionError(('Timed out', state()))


def tap(x, y):
    global transform
    # Emulator resize/rotation can settle after launcher entry. Measure the
    # current canvas instead of sending every later tap through a stale size.
    layout = adb('shell', 'dumpsys', 'activity', 'top').decode()
    match = re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', layout)
    assert match, 'Missing game canvas before input'
    left, top, right, bottom = map(int, match.groups())
    scale = min((right-left)/800, (bottom-top)/600)
    transform = (scale, left+((right-left)-scale*800)/2, top+((bottom-top)-scale*600)/2)
    scale, ox, oy = transform
    adb('shell', 'input', 'tap', str(round(ox + x * scale)), str(round(oy + y * scale)))


def station(machine, form=None, definition=None):
    if form is None:
        tap(machine['x'] + machine['w'] / 2, machine['y'] + machine['h'] / 2)
    else:
        f = next(n for n in (definition if definition is not None else defs[machine['guid']]).findall('Form') if int(n.get('id')) == form)
        tap(machine['x'] + float(f.get('x')) + float(f.get('width')) / 2,
            machine['y'] + float(f.get('y')) + float(f.get('height')) / 2)


def customer(c):
    p = points[c['slot']]
    # January's man sprites overlap in the line. Their exposed head/upper
    # torso identifies the chosen guest; a rear guest's feet sit behind the
    # front guest and correctly hit that front guest in the original game.
    if c['state'] == 'CASH':
        tap(float(p.get('x_money'))+16, float(p.get('y_money'))-5)
    else:
        tap(float(p.get('x')), float(p.get('y')) - 140)


def shot(name):
    (OUT / (name + '.png')).write_bytes(adb('exec-out', 'screencap', '-p'))


def verify_trash_frame(name):
    definition = defs['trash']
    scale, ox, oy = transform
    x, y = round(ox + float(definition.get('x_global')) * scale), round(oy + float(definition.get('y_global')) * scale)
    w, h = round(float(definition.get('width_global')) * scale), round(float(definition.get('height_global')) * scale)
    resources = {n.get('id'): n.get('path') for n in ET.parse(APP / 'assets/resources.xml').getroot()}
    source = Image.open(APP / 'assets' / resources[definition.get('main_img')]).convert('RGBA')
    # The original 1x3 sheet must show one normal bin, rather than three compressed frames.
    normal = source.crop((0, 0, source.width, source.height // int(definition.get('hc')))).resize((w, h), Image.Resampling.BILINEAR)
    mask = normal.getchannel('A').point(lambda a: 255 if a == 255 else 0).filter(ImageFilter.MinFilter(5))
    actual = Image.open(OUT / (name + '.png')).convert('RGB').crop((x, y, x + w, y + h))
    error = sum(ImageStat.Stat(ImageChops.difference(actual, normal.convert('RGB')), mask).mean) / 3
    assert error < 20, ('Trash must render one original frame', error)
    return error


def launch():
    global transform
    adb('shell', 'am', 'force-stop', PACKAGE)
    adb('shell', 'am', 'start', '-W', '-n', PACKAGE + '/.MainActivity', '--ei', 'qa_level', '1')
    # am start can return during portrait-to-landscape and navigation-bar removal.
    # A transient canvas size is not the final hit geometry.
    previous_canvas = None
    for _ in range(30):
        time.sleep(.3)
        hierarchy = adb('shell', 'dumpsys', 'activity', 'top').decode()
        match = re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', hierarchy)
        if match:
            canvas = tuple(map(int, match.groups()))
            if canvas == previous_canvas and canvas[2] > canvas[3] and 'ITYPE_NAVIGATION_BAR frame=' in hierarchy and re.search(r'ITYPE_NAVIGATION_BAR frame=.*visible=false', hierarchy):
                break
            previous_canvas = canvas
    assert match, 'Missing game canvas'
    left, top, right, bottom = map(int, match.groups())
    width, height = right - left, bottom - top
    scale = min(width / 800, height / 600)
    transform = (scale, left + (width - scale * 800) / 2, top + (height - scale * 600) / 2)
    assert width > height, ('Emulator did not settle in landscape', width, height)
    wait(lambda s: s['screen'] == 'game')


def verify_form_targets(expected, suffix):
    adb('shell', 'uiautomator', 'dump', '/sdcard/cake-machine.xml')
    xml = adb('shell', 'cat', '/sdcard/cake-machine.xml')
    (OUT / (suffix + '-hierarchy.xml')).write_bytes(xml)
    nodes = [n.attrib for n in ET.fromstring(xml).iter('node') if n.get('package') == PACKAGE and n.get('clickable') == 'true']
    scale, ox, oy = transform
    # Android 11's accessibility dump clips to mAppBounds even with hidden bars.
    # Cross-check the actual laid-out button rectangles before accepting clipped labels.
    layout = adb('shell', 'dumpsys', 'activity', 'top').decode()
    raw = [list(map(int, m)) for m in re.findall(r'android\.widget\.Button\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', layout)]
    visible = list(map(int, re.findall(r'\d+', ET.fromstring(xml).find('node').get('bounds'))))
    count = 0
    for guid, definition in expected.items():
        for f in definition.findall('Form'):
            # Accessible labels differ for the native Name0/Name1 oven placeholders.
            x = float(defs[guid].get('x_global')) + float(f.get('x'))
            y = float(defs[guid].get('y_global')) + float(f.get('y'))
            w, h = float(f.get('width')), float(f.get('height'))
            rx, ry = round(ox + x * scale), round(oy + y * scale)
            bounds = [rx, ry, rx + round(w * scale), ry + round(h * scale)]
            laid_out = [r for r in raw if all(abs(a-b) <= 1 for a, b in zip(r, bounds))]
            clipped = [max(bounds[0], visible[0]), max(bounds[1], visible[1]), min(bounds[2], visible[2]), min(bounds[3], visible[3])]
            matches = [n for n in nodes if all(abs(a-b) <= 1 for a, b in zip(map(int, re.findall(r'\d+', n['bounds'])), clipped))]
            assert len(laid_out) == 1 and len(matches) == 1, (guid, f.attrib, bounds, laid_out, matches)
            count += 1
    assert not any(n.get('content-desc') == 'Cancel' for n in nodes), 'Selection palette must not exist'
    return count


def write_career(xml):
    adb('shell', 'am', 'force-stop', PACKAGE)
    path = OUT / 'temporary-career.xml'
    path.write_bytes(xml)
    adb('push', str(path), '/data/local/tmp/cake-machine-career.xml')
    adb('shell', 'run-as', PACKAGE, 'mkdir', '-p', 'shared_prefs')
    adb('shell', 'run-as', PACKAGE, 'cp', '/data/local/tmp/cake-machine-career.xml', 'shared_prefs/career_profile_player1.xml')


def seed_profile():
    # MainActivity now loads gameplay state from the active profile file.  The
    # legacy global career.xml only contains settings/profile selection.
    write_pref('career.xml', b'''<?xml version="1.0" encoding="utf-8" standalone="yes" ?>
<map>
    <string name="profile_ids">player1</string>
    <string name="active_profile">player1</string>
</map>''')
    write_pref('career_profile_player1.xml', b'''<?xml version="1.0" encoding="utf-8" standalone="yes" ?>
<map>
    <string name="profile_name">Player 1</string>
    <int name="bank" value="0" />
    <int name="unlocked" value="1" />
    <int name="current" value="1" />
    <int name="lives" value="4" />
    <int name="points" value="0" />
    <boolean name="tutorialComplete" value="true" />
    <boolean name="complexTutorialComplete" value="true" />
</map>''')


assert adb('shell', 'getprop', 'ro.kernel.qemu').strip() == b'1', 'This fixture may only reset an emulator career'
adb('shell', 'am', 'force-stop', PACKAGE)
preferences = snapshot_prefs()
(OUT / 'prefs-before.json').write_text(json.dumps({name: data.decode('utf-8', 'replace') for name, data in preferences.items()}, indent=2) + '\n')
display = adb('shell', 'wm', 'size').decode().strip()
rotation = adb('shell', 'settings', 'get', 'system', 'user_rotation').decode().strip()
autorotate = adb('shell', 'settings', 'get', 'system', 'accelerometer_rotation').decode().strip()
try:
    adb('shell', 'wm', 'size', '2280x1080')
    adb('shell', 'wm', 'set-user-rotation', 'lock', '0')
    seed_profile()
    launch()
    s = state()
    assert {m['guid'] for m in s['stations'] if m['enabled']} == {'cakeoven0', 'froster1', 'trash'}, s
    assert verify_form_targets({k: defs[k] for k in ['cakeoven0', 'froster1']}, 'stock') == 8
    shot('phone-january-stock')
    tap(67,573)
    paused=wait(lambda s:s['screen']=='pause');time.sleep(.6)
    assert state()['elapsed']==paused['elapsed'], 'Menu pause must freeze shift time'
    tap(400,275);wait(lambda s:s['screen']=='game')
    checks.append('Original bottom-left Menu responds to real input; pause freezes time and Resume returns to the shift')
    trash_error = verify_trash_frame('phone-january-stock')
    checks.append('Fresh January: one oven, one froster, trash; eight targets match original sprite rectangles')
    checks.append('Trash renders one original normal frame, not the three-frame atlas')
    oven = next(m for m in s['stations'] if m['guid'] == 'cakeoven0')
    station(oven)
    wait(lambda s: not s['queue'])
    assert not next(m for m in state()['stations'] if m['guid'] == 'cakeoven0')['cake']
    checks.append('An empty oven body tap opens no popup and starts no cake')

    target = None
    placed = False
    screenshots = set()
    pending_compaction = None
    cash_block_checked = False
    start = time.monotonic()
    while time.monotonic() - start < 300:
        s = state()
        if s['screen'] == 'result':
            assert s['served'] == 8 and s['lost'] == 0 and s['money'] >= 200, s
            shot('january-result')
            checks.append('All eight January orders served through original shape/color sprite taps; $200 goal reached')
            result = s
            (OUT / 'stock-report.json').write_text(json.dumps({'passed': True, 'apk_sha256': hashlib.sha256((APP.parent / 'CakeMania-Android.apk').read_bytes()).hexdigest(), 'checks': checks, 'january': result, 'actions': actions}, indent=2) + '\n')
            break
        assert s['screen'] == 'game', s
        if s['queue']:
            time.sleep(.2)
            continue
        customers, machines, hand = s['customers'], s['stations'], s['hand']
        if pending_compaction and not any(c['serial']==pending_compaction[0] for c in customers):
            rear=next(c for c in customers if c['serial']==pending_compaction[1])
            assert rear['slot']==0, 'The next guest must advance after front cash is collected'
            shot('queue-advanced');checks.append('Real cash collection releases position one and moves the next customer forward');pending_compaction=None
        if target is not None and not any(c['serial'] == target and c['state'] not in ['HAPPY', 'CASH'] for c in customers):
            target = None
        cash = next((c for c in customers if c['state'] == 'CASH' and not c['cashCollected']), None)
        menu = next((c for c in customers if c['state'] == 'WAIT_MENU'), None)
        action = ''
        if cash:
            if not cash_block_checked and cash['slot']==0 and len(customers)>1:
                rear=next(c for c in customers if c['slot']==1);pending_compaction=(cash['serial'],rear['serial'])
                time.sleep(.7);held=state();departed=next(c for c in held['customers'] if c['serial']==cash['serial'])
                assert not departed['bodyVisible'] and departed['departureFrame']<0 and not departed['cashCollected']
                assert next(c for c in held['customers'] if c['serial']==rear['serial'])['slot']==1, 'Uncollected cash must block advancement'
                shot('cash-blocks-line');checks.append('Served body disappears; uncollected cash still blocks the line after its puff');cash_block_checked=True
            customer(cash); action = 'Collect cash'
        elif menu:
            customer(menu); action = 'Give menu'
        else:
            if target is None:
                target = next((c['serial'] for c in customers if c['state'] == 'ORDER'), None)
            c = next((c for c in customers if c['serial'] == target), None)
            if c:
                if hand:
                    if hand[0]['frost'] < 0:
                        froster = next(m for m in machines if m['guid'] == 'froster1')
                        if not placed:
                            station(froster)
                            wait(lambda s: not s['queue'] and not s['hand'])
                            tray = next(m for m in state()['stations'] if m['guid'] == 'froster1')
                            assert tray['cake'][0]['frost'] == -1 and tray['remaining'] == 0, tray
                            station(tray, c['order'][0]['frost'])
                            wait(lambda s: not s['queue'])
                            tray = next(m for m in state()['stations'] if m['guid'] == 'froster1')
                            assert tray['cake'][0]['frost'] == c['order'][0]['frost'] and tray['remaining'] > 0, tray
                            shot('direct-color-production')
                            placed = True
                            checks.append('Tray tap places raw cake; pictured color tap processes that cake without pickup or popup')
                        else:
                            station(froster, c['order'][0]['frost'])
                        action = 'Frost'
                    else:
                        if 'carry' not in screenshots:
                            shot('carrying-frosted-cake'); screenshots.add('carry')
                        customer(c); action = 'Deliver'
                else:
                    pending = next((m for m in machines if m['cake'] and m['remaining'] == 0), None)
                    if pending:
                        station(pending); action = 'Pick up'
                    else:
                        oven = next(m for m in machines if m['guid'] == 'cakeoven0')
                        if oven['remaining'] == 0 and not any(m['cake'] for m in machines):
                            station(oven, c['order'][0]['shape']); action = 'Bake'
        if action:
            actions.append({'elapsed': s['elapsed'], 'action': action, 'money': s['money']})
            print(action, round(s['elapsed'], 1), s['money'], flush=True)
        time.sleep(.2)
    else:
        raise AssertionError(('January did not finish', state()))

    # The result transition must preserve the awarded ledger and begin the
    # next month cleanly; rendering a result alone cannot catch Continue bugs.
    tap(468, 524)
    wait(lambda s: s['screen'] == 'shop')
    shot('january-shop')
    oven_shop=next(m for m in state()['stations'] if m['guid']=='cakeoven0')
    tap(163+.75*(oven_shop['x']+oven_shop['w']/2),20+.75*(oven_shop['y']+oven_shop['h']/2))
    time.sleep(.3);shot('january-shop-selection')
    tap(122, 572)
    february = wait(lambda s: s['screen'] == 'intro' and s['level'] == 2)
    assert february['bank'] == result['money'] and february['points'] == result['money']
    assert february['lives'] == 4 and february['unlocked'] == 2 and february['elapsed'] == 0, february
    checks.append('January result Continue opens the shop; shop Continue opens fresh February with awarded bank/points and four lives')

    # Activate only two real first-step shop entries. Compare every pictured target
    # and exercise equal color IDs on different frosters, plus the topper sprite.
    write_career(b'''<?xml version="1.0" encoding="utf-8"?><map>
        <string name="profile_name">Player 1</string>
        <int name="bank" value="0"/><int name="unlocked" value="1"/>
        <int name="current" value="1"/><int name="lives" value="4"/><int name="points" value="0"/>
        <boolean name="tutorialComplete" value="true"/><boolean name="complexTutorialComplete" value="true"/>
        <int name="upgrade1:froster0" value="1"/><int name="upgrade1:decorator0" value="1"/>
    </map>''')
    adb('shell', 'wm', 'size', '1440x1080')
    launch()
    expected = {k: defs[k] for k in ['cakeoven0', 'froster1']}
    for guid in ['froster0', 'decorator0']:
        expected[guid] = next(n for n in upgrades if n.get('guid') == guid and n.get('upgr_step') == '1')
    assert verify_form_targets(expected, 'purchased') == 13
    s = state()
    assert {m['guid'] for m in s['stations'] if m['enabled']} == {'cakeoven0', 'froster1', 'froster0', 'decorator0', 'trash'}, s
    shot('tablet-purchased-equipment')
    oven = next(m for m in s['stations'] if m['guid'] == 'cakeoven0')
    station(oven, 1); wait(lambda s: not s['queue'])
    wait(lambda s: next(m for m in s['stations'] if m['guid'] == 'cakeoven0')['remaining'] == 0)
    station(oven); wait(lambda s: not s['queue'] and bool(s['hand']))
    froster = next(m for m in state()['stations'] if m['guid'] == 'froster0')
    station(froster, 1, expected['froster0']); wait(lambda s: not s['queue'])
    s = state()
    assert next(m for m in s['stations'] if m['guid'] == 'froster0')['cake'][0]['frost'] == 1
    assert not next(m for m in s['stations'] if m['guid'] == 'froster1')['cake'], 'Same color ID routed to the wrong machine'
    wait(lambda s: next(m for m in s['stations'] if m['guid'] == 'froster0')['remaining'] == 0)
    station(froster); wait(lambda s: not s['queue'] and bool(s['hand']))
    decorator = next(m for m in state()['stations'] if m['guid'] == 'decorator0')
    station(decorator, 4, expected['decorator0']); wait(lambda s: not s['queue'])
    s = state()
    assert next(m for m in s['stations'] if m['guid'] == 'decorator0')['cake'][0]['decor'] == 4, s
    checks.append('Purchased froster and decorator: thirteen original hit regions, selected machine receives frosting, edge brown-color and ship topper sprite taps work at 1440x1080')
    write_career(b'''<map><string name="profile_name">Player 1</string>
        <int name="lives" value="4"/><int name="unlocked" value="1"/>
        <boolean name="tutorialComplete" value="true"/>
        <boolean name="complexTutorialComplete" value="true"/>
        <int name="upgrade1:cupcake0" value="1"/>
        <int name="upgrade1:displaycase0" value="1"/></map>''')
    launch()
    s = state()
    cookie = next(m for m in s['stations'] if m['guid'] == 'cupcake0')
    cookie_definition = next(n for n in upgrades if n.get('guid') == 'cupcake0' and n.get('upgr_step') == '1')
    def shelf(machine, definition, index, top_edge=False):
        child = next(n for n in definition.findall('FormShelf') if int(n.get('id')) == index)
        tap(machine['x'] + float(child.get('x')) + float(child.get('width')) / 2,
            machine['y'] + float(child.get('y')) + (2 if top_edge else float(child.get('height')) / 2))
    shelf(cookie, cookie_definition, 0)
    wait(lambda s: not s['queue'] and bool(s['hand']))
    assert state()['hand'][0]['shape'] == 8
    trash = next(m for m in state()['stations'] if m['guid'] == 'trash')
    station(trash); wait(lambda s: not s['queue'] and not s['hand'])
    shelf(cookie, cookie_definition, 0); wait(lambda s: not s['queue'])
    assert not state()['hand'], 'An empty cookie slot must not take a different slot'
    shelf(cookie, cookie_definition, 1)
    wait(lambda s: not s['queue'] and bool(s['hand']))
    assert state()['hand'][0]['shape'] == 8
    station(trash); wait(lambda s: not s['queue'] and not s['hand'])
    checks.append('Cookie FormShelf taps select independent slots; tapping the emptied slot does not take another cookie')
    oven = next(m for m in state()['stations'] if m['guid'] == 'cakeoven0')
    station(oven, 1); wait(lambda s: not s['queue'])
    wait(lambda s: next(m for m in s['stations'] if m['guid'] == 'cakeoven0')['remaining'] == 0)
    station(oven); wait(lambda s: not s['queue'] and bool(s['hand']))
    froster = next(m for m in state()['stations'] if m['guid'] == 'froster1')
    station(froster, 2); wait(lambda s: not s['queue'])
    wait(lambda s: next(m for m in s['stations'] if m['guid'] == 'froster1')['remaining'] == 0)
    station(froster); wait(lambda s: not s['queue'] and bool(s['hand']))
    case = next(m for m in state()['stations'] if m['guid'] == 'displaycase0')
    case_definition = next(n for n in upgrades if n.get('guid') == 'displaycase0' and n.get('upgr_step') == '1')
    shelf(case, case_definition, 0, top_edge=True)
    wait(lambda s: not s['queue'] and not s['hand'])
    assert next(m for m in state()['stations'] if m['guid'] == 'displaycase0')['cake']
    shelf(case, case_definition, 0, top_edge=True)
    wait(lambda s: not s['queue'] and bool(s['hand']))
    checks.append('Display-case FormShelf edge outside the parent body accepts placement and pickup through real taps')
finally:
    adb('shell', 'am', 'force-stop', PACKAGE)
    try:
        restore_prefs(preferences)
    finally:
        try:
            restore_display(display)
        finally:
            adb('shell', 'settings', 'put', 'system', 'user_rotation', rotation)
            adb('shell', 'settings', 'put', 'system', 'accelerometer_rotation', autorotate)
    assert snapshot_prefs() == preferences, 'Shared preferences restoration failed'
    assert adb('shell', 'wm', 'size').decode().strip() == display, 'Display restoration failed'
    adb('shell', 'rm', '-f', '/data/local/tmp/cake-machine-career.xml')
    (OUT / 'temporary-career.xml').unlink(missing_ok=True)
    (OUT / 'seed-career.xml').unlink(missing_ok=True)
    (OUT / 'seed-career_profile_player1.xml').unlink(missing_ok=True)

report = {'passed': True, 'apk_sha256': hashlib.sha256((APP.parent / 'CakeMania-Android.apk').read_bytes()).hexdigest(),
          'android_api': adb('shell', 'getprop', 'ro.build.version.sdk').decode().strip(),
          'qa_level_used': True, 'actual_android_taps': True, 'career_restored': True,
          'trash_normal_frame_mean_rgb_error': trash_error,
          'checks': checks, 'january': result, 'actions': actions}
(OUT / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
print('PASS:', checks, flush=True)
