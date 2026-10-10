#!/usr/bin/env python3
"""Normal-launch menu/profile touch regression using real Android input."""
from pathlib import Path
import atexit
import hashlib
import json
import os
import re
import subprocess
import sys
import time
import xml.etree.ElementTree as ET

ROOT = Path(__file__).resolve().parents[1]
ADB = str(Path(os.environ.get('ANDROID_HOME', str(Path.home() / 'Library/Android/sdk'))) / 'platform-tools/adb')
PACKAGE = 'local.cakemania'
LAUNCHER = ('shell', 'am', 'start', '-W', '-a', 'android.intent.action.MAIN',
            '-c', 'android.intent.category.LAUNCHER', '-n', PACKAGE + '/.MainActivity')
OUTPUT = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / 'verification/menu-touch'
OUTPUT.mkdir(parents=True, exist_ok=True)
checks = []
sequence = 0
last_controls = None


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
    safe = re.sub(r'[^A-Za-z0-9_.-]', '_', name)
    path = OUTPUT / ('seed-' + safe)
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
        (OUTPUT / ('seed-' + re.sub(r'[^A-Za-z0-9_.-]', '_', name))).unlink(missing_ok=True)


def restore_display(original):
    override = re.search(r'Override size:\s*(\d+x\d+)', original)
    adb('shell', 'wm', 'size', override.group(1) if override else 'reset')


def seed_normal_profile():
    # Gameplay state belongs to the active profile preference file.  The
    # global file only selects that profile and carries audio settings.
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


def controls():
    global sequence, last_controls
    sequence += 1
    adb('shell', 'uiautomator', 'dump', '/sdcard/cake-touch.xml')
    xml = adb('shell', 'cat', '/sdcard/cake-touch.xml')
    (OUTPUT / f'{sequence:02d}.xml').write_bytes(xml)
    # Android SeekBars expose range actions, not the clickable flag.
    nodes = [n.attrib for n in ET.fromstring(xml).iter('node')
             if n.get('package') == PACKAGE and n.get('enabled') == 'true'
             and (n.get('clickable') == 'true' or n.get('class') == 'android.widget.SeekBar')]
    authored = {}
    if set(labels(nodes)) == {'Next', 'Main Menu'}:
        authored = {'Next': (550,536,210,44), 'Main Menu': (30,536,210,44)}
    elif set(labels(nodes)) == {"Let's Play!", 'Main Menu'}:
        authored = {'Main Menu': (30,536,200,44)}
    elif len(nodes) == 49 and '48' in labels(nodes) and 'Back' in labels(nodes):
        authored = {'Back': (30,548,190,40)}
    if any(n['bounds'] == '[0,0][0,0]' and label(n) in authored for n in nodes):
        # API 30 clips accessibility bounds to mAppBounds even when immersive
        # native views extend below that rectangle. Verify the actual views
        # before using their full coordinates for real input.
        hierarchy = adb('shell', 'dumpsys', 'activity', 'top').decode()
        canvas = re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', hierarchy)
        assert canvas, 'Missing immersive canvas'
        l, t, r, b = map(int, canvas.groups())
        s = min((r-l)/800, (b-t)/600)
        ox, oy = l+((r-l)-s*800)/2, t+((b-t)-s*600)/2
        native = [list(map(int, m)) for m in re.findall(r'android\.widget\.Button\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', hierarchy)]
        for n in nodes:
            if label(n) not in authored:
                continue
            x,y,w,h = authored[label(n)]
            rect = [round(ox+x*s), round(oy+y*s), round(ox+x*s)+round(w*s), round(oy+y*s)+round(h*s)]
            assert rect in native, ('Missing full immersive touch target', label(n), rect, native)
            n['bounds'] = f'[{rect[0]},{rect[1]}][{rect[2]},{rect[3]}]'
    for n in nodes:
        x1, y1, x2, y2 = map(int, re.findall(r'\d+', n['bounds']))
        # Some unused machine targets are similarly clipped. A target used by
        # this test must have positive bounds (checked again in tap).
        assert n['bounds'] == '[0,0][0,0]' or (x2 > x1 and y2 > y1), ('Invalid target bounds', n)
    last_controls = nodes
    return nodes


def all_nodes():
    adb('shell', 'uiautomator', 'dump', '/sdcard/cake-touch-all.xml')
    xml = adb('shell', 'cat', '/sdcard/cake-touch-all.xml')
    return [n.attrib for n in ET.fromstring(xml).iter('node') if n.get('package') == PACKAGE]


def label(node):
    return node.get('content-desc') or node.get('text') or ''


def labels(nodes):
    return [label(n) for n in nodes]


def expect(expected):
    nodes = controls()
    actual = labels(nodes)
    assert sorted(actual) == sorted(expected), (actual, expected)
    return nodes


def node_for(label_text, nodes=None):
    nodes = nodes if nodes is not None else last_controls if last_controls is not None else controls()
    matches = [n for n in nodes if label(n).casefold() == label_text.casefold()]
    assert len(matches) == 1, (label_text, labels(nodes))
    return matches[0]


def tap(label_text, nodes=None):
    global last_controls
    target = node_for(label_text, nodes)
    x1, y1, x2, y2 = map(int, re.findall(r'\d+', target['bounds']))
    assert x2 > x1 and y2 > y1, ('Touch target has no area', target)
    adb('shell', 'input', 'tap', str((x1 + x2) // 2), str((y1 + y2) // 2))
    last_controls = None
    time.sleep(.4)


def swipe(label_text, fraction, nodes=None):
    global last_controls
    target = node_for(label_text, nodes)
    x1, y1, x2, y2 = map(int, re.findall(r'\d+', target['bounds']))
    y = (y1 + y2) // 2
    start = x1 + 2
    finish = round(x1 + max(0, min(1, fraction)) * (x2 - x1 - 4))
    adb('shell', 'input', 'swipe', str(start), str(y), str(finish), str(y), '350')
    last_controls = None
    time.sleep(.4)


def pref_float(name, key):
    xml = adb('shell', 'run-as', PACKAGE, 'cat', 'shared_prefs/' + name)
    root = ET.fromstring(xml)
    entry = next((n for n in root if n.get('name') == key), None)
    assert entry is not None, (name, key, xml)
    return float(entry.get('value'))


def cold_launch():
    adb('shell', 'am', 'force-stop', PACKAGE)
    result = adb(*LAUNCHER)
    assert b'Status: ok' in result, result
    time.sleep(1)


prefs_before = snapshot_prefs()
(OUTPUT / 'prefs-before.json').write_text(json.dumps({name: data.decode('utf-8', 'replace') for name, data in prefs_before.items()}, indent=2) + '\n')
display_before = adb('shell', 'wm', 'size').decode().strip()
cleaned = False


def cleanup():
    global cleaned
    if cleaned:
        return
    cleaned = True
    adb('shell', 'am', 'force-stop', PACKAGE)
    try:
        restore_prefs(prefs_before)
    finally:
        restore_display(display_before)
    assert snapshot_prefs() == prefs_before, 'Shared preferences restoration failed'
    assert adb('shell', 'wm', 'size').decode().strip() == display_before, 'Display restoration failed'


atexit.register(cleanup)

MENU = ['Play', 'High Scores', 'Options', 'Help', 'Exit', 'Profiles']
PLAY = ['Start New Game', 'Continue Career', 'Choose Month', 'Back']

seed_normal_profile()
cold_launch()
menu = expect(MENU)
hierarchy = adb('shell', 'dumpsys', 'activity', 'top').decode()
(OUTPUT / 'view-hierarchy.txt').write_text(hierarchy)
match = re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}', hierarchy)
assert match, 'Missing game canvas'
left, top, right, bottom = map(int, match.groups())
width, height = right - left, bottom - top
scale = min(width / 800, height / 600)
ox, oy = left + (width - 800 * scale) / 2, top + (height - 600 * scale) / 2
for index, node in enumerate(menu):
    actual = list(map(int, re.findall(r'\d+', node['bounds'])))
    x, y = round(ox + 391.5 * scale), round(oy + (188 + index * 47) * scale)
    w, h = round(318 * scale), round(39 * scale)
    assert all(abs(a - b) <= 1 for a, b in zip(actual, [x, y, x + w, y + h])), (actual, [x, y, x + w, y + h])
(OUTPUT / 'cold-launch-menu.png').write_bytes(adb('exec-out', 'screencap', '-p'))
checks.append('Normal cold launch: six nonzero touch targets, including Profiles, match the menu controls')

tap('High Scores', menu)
tap('Main Menu', expect(['Main Menu']))
expect(MENU)
checks.append('High Scores opens and returns through touch')

tap('Options')
options = expect(['Music: On', 'Music Volume', 'Sounds: On', 'Sfx Volume', 'Main Menu'])
swipe('Music Volume', .25, options)
swipe('Sfx Volume', .75)
assert abs(pref_float('career.xml', 'musicVolume') - .25) < .08
assert abs(pref_float('career.xml', 'soundVolume') - .75) < .08
tap('Music: On')
tap('Music: Off', expect(['Music: Off', 'Music Volume', 'Sounds: On', 'Sfx Volume', 'Main Menu']))
tap('Sounds: On')
tap('Sounds: Off', expect(['Music: On', 'Music Volume', 'Sounds: Off', 'Sfx Volume', 'Main Menu']))
tap('Main Menu')
tap('Options', expect(MENU))
assert abs(pref_float('career.xml', 'musicVolume') - .25) < .08
assert abs(pref_float('career.xml', 'soundVolume') - .75) < .08
tap('Main Menu')
checks.append('Options SeekBars accept real swipes, toggles work, and volume values persist after leaving and reopening')

tap('Help')
tap('Next', expect(['Next', 'Main Menu']))
tap('Main Menu', expect(['Next', 'Main Menu']))
expect(MENU)
checks.append('Help opens, advances, and returns through touch')

# Profiles are exercised through the native dialog and actual profile buttons.
tap('Profiles')
profile_menu = controls()
assert labels(profile_menu) == ['Player 1', 'New Player', 'Back'], labels(profile_menu)
tap('New Player', profile_menu)
edit = next((n for n in all_nodes() if n.get('class') == 'android.widget.EditText'), None)
assert edit is not None, 'New profile dialog must expose a real text field'
x1, y1, x2, y2 = map(int, re.findall(r'\d+', edit['bounds']))
adb('shell', 'input', 'tap', str((x1 + x2) // 2), str((y1 + y2) // 2))
# Wait for the emulator keyboard to finish changing the dialog geometry.
for _ in range(20):
    if 'mInputShown=true' in adb('shell', 'dumpsys', 'input_method').decode():
        break
    time.sleep(.2)
adb('shell', 'input', 'text', 'Player%sTwo')
time.sleep(.5)
if 'mInputShown=true' in adb('shell', 'dumpsys', 'input_method').decode():
    adb('shell', 'input', 'keyevent', '4')
    time.sleep(.5)
tap('Create', [n for n in all_nodes() if n.get('clickable') == 'true'])
expect(MENU)
tap('Profiles')
profile_menu = controls()
assert labels(profile_menu) == ['Player 1', 'Player Two', 'New Player', 'Back'], labels(profile_menu)
tap('Player Two', profile_menu)
expect(MENU)

# The new profile has its own incomplete tutorial state.  Continue must enter
# the tutorial room, while Player 1 (seeded completed) goes to the intro.
tap('Play')
tap('Continue Career', expect(PLAY))
tutorial_controls = controls()
assert "Let's Play!" not in labels(tutorial_controls), labels(tutorial_controls)
adb('shell', 'input', 'keyevent', '4')
pause = expect(['Resume', 'Restart Month', 'Main Menu'])
tap('Main Menu', pause)
expect(MENU)
tap('Profiles')
profile_menu = controls()
tap('Player 1', profile_menu)
expect(MENU)
tap('Play')
tap('Continue Career', expect(PLAY))
assert labels(expect(["Let's Play!", 'Main Menu'])) == ["Let's Play!", 'Main Menu']
tap('Main Menu')
expect(MENU)
checks.append('Profiles create/select through real input and keep tutorial completion isolated per profile')

# Choose Month now enters the authored map before a level intro.
tap('Play')
tap('Choose Month', expect(PLAY))
month_map = controls()
month_labels = labels(month_map)
assert len(month_map) == 49 and '1' in month_labels and '48' in month_labels and 'Back' in month_labels, month_labels
tap('Back', month_map)
expect(MENU)
checks.append('Choose Month opens the map with all 48 level targets and returns through Back')

tap('Play')
tap('Continue Career', expect(PLAY))
tap("Let's Play!", expect(["Let's Play!", 'Main Menu']))
game = controls()
assert any(label(n) == 'Menu' for n in game), game
tap('Menu', game)
pause = expect(['Resume', 'Restart Month', 'Main Menu'])
tap('Main Menu', pause)
expect(MENU)
checks.append('Continue Career, intro, game, bottom Menu, and Main Menu respond')

adb('shell', 'input', 'keyevent', '3')
time.sleep(.5)
adb(*LAUNCHER)
expect(MENU)
checks.append('Menu touch targets survive background/foreground')
tap('Exit')
assert 'mResumed=true' not in adb('shell', 'dumpsys', 'activity', PACKAGE + '/.MainActivity').decode()
checks.append('Exit closes the activity')

cold_launch()
expect(MENU)
tap('Play')
expect(PLAY)
checks.append('A second normal cold launch still accepts Play')

report = {'passed': True,
          'apk_sha256': hashlib.sha256((ROOT.parent / 'CakeMania-Android.apk').read_bytes()).hexdigest(),
          'android_api': adb('shell', 'getprop', 'ro.build.version.sdk').decode().strip(),
          'display': adb('shell', 'wm', 'size').decode().strip(),
          'canvas': [width, height], 'qa_level_used': False,
          'actual_android_taps': True, 'checks': checks}
(OUTPUT / 'report.json').write_text(json.dumps(report, indent=2) + '\n')
cleanup()
print(json.dumps(report, indent=2), flush=True)

