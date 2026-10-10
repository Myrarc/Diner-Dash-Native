#!/usr/bin/env python3
"""Tap every stock cake/color sprite, including operating machines, on an emulator."""
from pathlib import Path
import hashlib,json,re,subprocess,sys,time
import xml.etree.ElementTree as ET

APP=Path(__file__).resolve().parents[1]
ADB=str(Path.home()/'Library/Android/sdk/platform-tools/adb');PKG='local.cakemania'
OUT=Path(sys.argv[1]) if len(sys.argv)>1 else APP/'verification/fixes-0.1.4/selection-touch'
OUT.mkdir(parents=True,exist_ok=True)
def adb(*args):return subprocess.check_output([ADB,*args],stderr=subprocess.STDOUT,timeout=20)
def prefs():
    return {n:adb('shell','run-as',PKG,'cat','shared_prefs/'+n) for n in adb('shell','run-as',PKG,'ls','shared_prefs').decode().split()}
def write(name,data):
    p=OUT/'temporary.xml';p.write_bytes(data);adb('push',str(p),'/data/local/tmp/cake-selection-prefs.xml');adb('shell','run-as',PKG,'cp','/data/local/tmp/cake-selection-prefs.xml','shared_prefs/'+name)
def state():
    for _ in range(20):
        try:return json.loads(adb('shell','run-as',PKG,'cat','files/qa-state.json'))
        except (json.JSONDecodeError,subprocess.CalledProcessError):time.sleep(.05)
    raise AssertionError('No complete QA snapshot')
def wait(predicate):
    deadline=time.monotonic()+20
    while time.monotonic()<deadline:
        s=state()
        if predicate(s):return s
        time.sleep(.15)
    raise AssertionError(('Selection did not finish',state()))
def tap(x,y):
    text=adb('shell','dumpsys','activity','top').decode();m=re.search(r'local\.cakemania\.GameView\{[^\n]*? (\d+),(\d+)-(\d+),(\d+)\}',text);assert m,'Missing Canvas'
    l,t,r,b=map(int,m.groups());scale=min((r-l)/800,(b-t)/600);ox=l+((r-l)-scale*800)/2;oy=t+((b-t)-scale*600)/2
    adb('shell','input','tap',str(round(ox+x*scale)),str(round(oy+y*scale)))
def machine(s,guid):return next(m for m in s['stations'] if m['guid']==guid)
def form(guid,form_id):
    n=defs[guid];f=next(f for f in n.findall('Form') if int(f.get('id'))==form_id)
    tap(float(n.get('x_global'))+float(f.get('x'))+float(f.get('width'))/2,float(n.get('y_global'))+float(f.get('y'))+float(f.get('height'))/2)
def body(guid):
    m=machine(state(),guid);tap(m['x']+m['w']/2,m['y']+m['h']/2)
def shot(name):(OUT/(name+'.png')).write_bytes(adb('exec-out','screencap','-p'))

env=ET.parse(APP/'assets/config/level1/career/january_env.xml').getroot();defs={n.get('guid'):n for n in env.iter() if n.get('x_global')}
assert adb('shell','getprop','ro.kernel.qemu').strip()==b'1','Disposable emulator required'
adb('shell','am','force-stop',PKG);before=prefs();results=[]
try:
    write('career.xml',b'<map><string name="profile_ids">player1</string><string name="active_profile">player1</string></map>')
    write('career_profile_player1.xml',b'<map><int name="lives" value="4"/><boolean name="tutorialComplete" value="true"/><boolean name="complexTutorialComplete" value="true"/></map>')
    adb('shell','am','start','-W','-n',PKG+'/.MainActivity','--ei','qa_level','1');time.sleep(2)
    for shape,color in [(7,0),(1,3),(2,1),(3,2)]:
        form('cakeoven0',shape)
        wait(lambda s:not s['queue'] and machine(s,'cakeoven0')['remaining']>0);shot('oven-'+str(shape)+'-cooking')
        ready=wait(lambda s:machine(s,'cakeoven0')['remaining']==0 and bool(machine(s,'cakeoven0')['cake']))
        shot('oven-'+str(shape)+'-ready')
        assert machine(ready,'cakeoven0')['cake'][0]['shape']==shape,'Shape sprite selected the wrong cake'
        body('cakeoven0');carried=wait(lambda s:not s['queue'] and bool(s['hand']));assert carried['hand'][0]['shape']==shape
        form('froster1',color)
        frosted=wait(lambda s:not s['queue'] and machine(s,'froster1')['remaining']>0);assert machine(frosted,'froster1')['cake'][0]['frost']==color,'Color sprite selected the wrong frosting';shot('frost-'+str(color)+'-working')
        wait(lambda s:machine(s,'froster1')['remaining']==0)
        body('froster1');carried=wait(lambda s:not s['queue'] and bool(s['hand']));assert carried['hand'][0]['shape']==shape and carried['hand'][0]['frost']==color
        body('trash');wait(lambda s:not s['queue'] and not s['hand'])
        results.append({'shape':shape,'color':color,'bake_pickup_frost_pickup_trash':True});print('PASS: direct sprite taps',shape,color,flush=True)
finally:
    adb('shell','am','force-stop',PKG)
    for n in prefs():adb('shell','run-as',PKG,'rm','shared_prefs/'+n)
    for n,data in before.items():write(n,data)
    assert prefs()==before,'Career restoration failed'
    adb('shell','rm','-f','/data/local/tmp/cake-selection-prefs.xml');(OUT/'temporary.xml').unlink(missing_ok=True)
(OUT/'report.json').write_text(json.dumps({'passed':True,'apk_sha256':hashlib.sha256((APP.parent/'CakeMania-Android.apk').read_bytes()).hexdigest(),'actual_android_taps':True,'all_four_shapes_and_colors':results,'career_restored':True},indent=2)+'\n')
