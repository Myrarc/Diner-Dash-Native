#!/usr/bin/env python3
"""Exercise both recovered lessons with real emulator input; preserve saved profiles."""
from pathlib import Path
import subprocess,json,time,re,sys,hashlib
import xml.etree.ElementTree as ET
APP=Path(__file__).resolve().parents[1]
ADB=str(Path.home()/'Library/Android/sdk/platform-tools/adb'); PKG='local.cakemania'
OUT=Path(sys.argv[1]) if len(sys.argv)>1 else APP/'verification/fixes-0.1.3/tutorial-touch'
OUT.mkdir(parents=True,exist_ok=True)
def adb(*args):return subprocess.check_output([ADB,*args],stderr=subprocess.STDOUT,timeout=20)
def stop():adb('shell','am','force-stop',PKG)
def snapshot():
    adb('shell','run-as',PKG,'mkdir','-p','shared_prefs')
    names=adb('shell','run-as',PKG,'ls','shared_prefs').decode().split()
    return {n:adb('shell','run-as',PKG,'cat','shared_prefs/'+n) for n in names}
def write(name,data):
    p=OUT/'temporary.xml';p.write_bytes(data)
    adb('push',str(p),'/data/local/tmp/cake-tutorial-prefs.xml')
    adb('shell','run-as',PKG,'cp','/data/local/tmp/cake-tutorial-prefs.xml','shared_prefs/'+name)
def state():
    for _ in range(20):
        try:return json.loads(adb('shell','run-as',PKG,'cat','files/qa-state.json'))
        except (json.JSONDecodeError,subprocess.CalledProcessError):time.sleep(.05)
    raise AssertionError('No complete QA snapshot')
def transform():
    top=adb('shell','dumpsys','activity','top').decode()
    m=re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}',top)
    assert m,top
    l,t,r,b=map(int,m.groups());s=min((r-l)/800,(b-t)/600)
    return s,l+((r-l)-s*800)/2,t+((b-t)-s*600)/2
def wait_screen(expected):
    deadline=time.monotonic()+8
    while time.monotonic()<deadline:
        s=state()
        if s['screen']==expected:return s
        time.sleep(.1)
    raise AssertionError(('Expected screen',expected,state()))
def tap_screen(x,y,expected):
    scale,ox,oy=transform()
    adb('shell','input','tap',str(round(ox+x*scale)),str(round(oy+y*scale)))
    time.sleep(.35);return wait_screen(expected)
assert adb('shell','getprop','ro.kernel.qemu').strip()==b'1'
stop(); before=snapshot(); results=[]
display=adb("shell","wm","size").decode()
try:
    adb("shell","wm","size","1440x1080")
    for sequence,month in [(0,1),(10,11)]:
        stop()
        write('career.xml',b'<map><string name="profile_ids">player1</string><string name="active_profile">player1</string></map>')
        write('career_profile_player1.xml',f'<map><string name="profile_name">Player 1</string><int name="unlocked" value="{month}"/><int name="current" value="{month}"/><int name="bank" value="0"/><int name="lives" value="4"/><int name="points" value="0"/><boolean name="tutorialComplete" value="{str(sequence==10).lower()}"/><boolean name="complexTutorialComplete" value="false"/></map>'.encode())
        adb('shell','am','start','-W','-n',PKG+'/.MainActivity','--ei','qa_level',str(month))
        time.sleep(1.5); scale,ox,oy=transform()
        opening_taps=[]
        if sequence==0:
            # QA enables snapshots only; drive the New Game route through its real controls.
            adb('shell','input','keyevent','4');wait_screen('pause')
            tap_screen(400,415,'menu');opening_taps.append('Main Menu')
            tap_screen(550.5,207.5,'playmenu');opening_taps.append('Play')
            tap_screen(550.5,207.5,'story');opening_taps.append('Start New Game')
            for page in range(3):
                tap_screen(662,558,'story' if page<2 else 'game');opening_taps.append('Comic Continue '+str(page+1))
            s=state();assert s['level']==0 and s['tutorialSequenceId']==0 and s['tutorialStep']==3,s
            (OUT/'opening-comics-to-practice.png').write_bytes(adb('exec-out','screencap','-p'))
        events=ET.parse(APP/f'assets/config/tutorialscreen/sequence{sequence}.xml').getroot().find('Sequence').findall('Event')
        points=ET.parse(APP/'assets/config/level1/pathes.xml').getroot().find('CustomerPath').findall('Point')
        tapped=set(); actions=[]; deadline=time.monotonic()+300; delivered=False; cash_ready=False
        while time.monotonic()<deadline:
            s=state()
            if s['tutorialSequenceId']==-1 and s['level']==month:
                assert delivered and cash_ready, ('Practice must actually deliver and reach cash collection',sequence,actions)
                assert s['tutorialComplete'] and (sequence==0 or s['complexTutorialComplete']),s
                assert s['bank']==0 and s['points']==0 and s['lives']==4 and s['served']==0 and s['lost']==0 and s['money']==0,s
                assert s['screen']==('intro' if sequence==0 else 'game'), ('January must show the career narrative after practice; the advanced-lesson flow is unchanged',s)
                if sequence==0:assert s['elapsed']==0, 'The January clock must remain paused until Let\'s Play'
                assert s['elapsed']<2,s
                results.append({'sequence':sequence,'opening_flow_real_taps':opening_taps,'real_taps':actions,'matching_delivery_observed':delivered,'cash_collection_ready_observed':cash_ready,'fresh_month':s})
                (OUT/f'sequence{sequence}-complete.png').write_bytes(adb('exec-out','screencap','-p'))
                break
            assert s['screen']=='game' and s['level']==0,s
            i=s['tutorialStep'];type_=s['tutorialEvent']
            if s['served']==1 and any(c['state'] in ('HAPPY','CASH') for c in s['customers']):delivered=True
            if delivered and any(c['state']=='CASH' for c in s['customers']):cash_ready=True
            if type_ in ('WaitForClick','WaitForCustomerClick') and i not in tapped and not s['queue']:
                # Native gates advance on coordinates even if the action fails.
                # Use a valid player path: wait for the visible product instead
                # of clicking an oven pickup as soon as a Timer expires.
                pickup_events = {0:{11,40,53},10:{21,39,43,55}}[sequence]
                if i in pickup_events:
                    machine = next(m for m in s['stations'] if m['guid']==('cakeoven0' if i in {11,40,21,39} else 'froster1'))
                    if machine['remaining']>0 or not machine['cake']:
                        time.sleep(.15);continue
                if (sequence,i) in {(0,66),(10,68)} and not cash_ready:
                    time.sleep(.15);continue
                if (sequence,i) in {(0,3),(0,29),(0,66),(10,68)}:
                    (OUT/f'sequence{sequence}-step{i}.png').write_bytes(adb('exec-out','screencap','-p'))
                e=events[i]
                if type_=='WaitForClick':x=float(e.get('x'))+float(e.get('w'))/2;y=float(e.get('y'))+float(e.get('h'))/2
                else:
                    c=next(c for c in s['customers']);p=points[c['slot']];x=float(p.get('x'))+33;y=float(p.get('y'))-35
                    if c['state']=='ORDER':
                        assert len(s['hand'])==len(c['order'])==(2 if sequence==10 else 1),s
                        assert [(l['shape'],l['frost'],l['decor']) for l in s['hand']]==[(l['shape'],l['frost'],l['decor']) for l in c['order']],s
                if (sequence,i) in {(0,66),(10,68)}:
                    c=next(c for c in s['customers'] if c['state']=='CASH');p=points[c['slot']]
                    assert float(p.get('x_money'))-4<=x<float(p.get('x_money'))+46 and float(p.get('y_money'))-25<=y<float(p.get('y_money'))+25, 'Final authored gate must hit the actual money'
                scale,ox,oy=transform()
                adb('shell','input','tap',str(round(ox+x*scale)),str(round(oy+y*scale)))
                actions.append({'event':i,'type':type_,'x':x,'y':y,'hand':s['hand']})
                print('Tap',sequence,i,type_,s['hand'],flush=True);time.sleep(.5)
                # Record only accepted authored gates.
                if state()['tutorialStep']!=i:tapped.add(i)
            else:time.sleep(.15)
        else:raise AssertionError(('Tutorial timeout',sequence,state()))
finally:
    stop()
    for name in adb('shell','run-as',PKG,'ls','shared_prefs').decode().split():adb('shell','run-as',PKG,'rm','shared_prefs/'+name)
    for name,data in before.items():write(name,data)
    override=re.search(r"Override size: (\d+x\d+)",display)
    adb("shell","wm","size",override.group(1) if override else "reset")
report={'passed':True,'apk_sha256':hashlib.sha256((APP.parent/'CakeMania-Android.apk').read_bytes()).hexdigest(),'sequences':results,'original_prefs_restored':snapshot()==before}
assert report['original_prefs_restored']
(OUT/'report.json').write_text(json.dumps(report,indent=2)+'\n');print('PASS: both authored tutorials complete through real taps, with separate practice and restored profiles')
