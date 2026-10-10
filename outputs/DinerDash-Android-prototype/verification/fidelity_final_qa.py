import sys,time,json,subprocess
from pathlib import Path
sys.path.insert(0,'work');from fidelity_qa import *
log=[]
def record(label,condition=None):
 value=state();print(label+': '+value,flush=True);log.append({'action':label,'state':value});assert condition is None or condition(value),label

def motion(kind,x,y):
 s,ox,oy=transform();adb('shell','input','motionevent',kind,round(ox+x*s),round(oy+y*s))
def control(layout,key):
 d=json.loads((ROOT/'outputs/DinerDash-Android-prototype/assets/layouts.json').read_text())[layout+'_layout']['children'][key]['frames'][0];x,y=d['loc']['values'];tap(x,y)
def service(prefix):
 launch(1);time.sleep(.8);shot(prefix+'-intro');tap(427,482);time.sleep(.5);shot(prefix+'-play');record(prefix+' coffee locked',lambda s:'Coffee unavailable' in s)
 motion('DOWN',20,483);motion('MOVE',300,320);time.sleep(.1);shot(prefix+'-drag-preview');record(prefix+' chair preview',lambda s:'Drag 0 preview 0' in s);motion('UP',200,580);record(prefix+' invalid drop',lambda s:'Table 1: EMPTY' in s)
 swipe(20,483,300,320);time.sleep(4);shot(prefix+'-seated');record(prefix+' valid drop',lambda s:'Table 1: READY' in s)
 tap(300,320);time.sleep(1);record(prefix+' take order',lambda s:'ticket T1' in s);shot(prefix+'-ticket-carry');tap(302,128);time.sleep(.3);shot(prefix+'-wheel-turn');time.sleep(.35);shot(prefix+'-chef-a');time.sleep(.2);shot(prefix+'-chef-b');time.sleep(4);shot(prefix+'-food-ready');record(prefix+' cooked order',lambda s:'Food ready: 1' in s)
 tap(374,140);time.sleep(1);shot(prefix+'-food-carry');record(prefix+' tray pickup',lambda s:'food T1' in s);tap(300,320);time.sleep(1);shot(prefix+'-food-delivered');record(prefix+' food delivered',lambda s:'Table 1: EATING' in s)
 tap(737,575);shot(prefix+'-pause');adb('shell','input','keyevent','4')
 launch(5);time.sleep(.8);tap(427,482);time.sleep(.5);shot(prefix+'-coffee-preparing');record(prefix+' coffee preparing',lambda s:'Coffee preparing' in s);time.sleep(9);shot(prefix+'-coffee-ready');record(prefix+' coffee ready',lambda s:'Coffee ready' in s);tap(620,132);time.sleep(2);shot(prefix+'-coffee-collected');record(prefix+' coffee picked',lambda s:'Coffee preparing' in s and 'drink' in s);time.sleep(10);shot(prefix+'-coffee-refreshed');record(prefix+' coffee refreshed',lambda s:'Coffee ready' in s)

adb('shell','wm','size','2280x1080');adb('shell','wm','density','440');adb('shell','settings','put','system','font_scale','1.0');launch();time.sleep(1);shot('phone-title');control('title_screen','career_button');time.sleep(.3);shot('phone-career');adb('shell','input','keyevent','4');control('title_screen','options_button');time.sleep(.3);shot('phone-options');adb('shell','input','keyevent','4');control('title_screen','help_button');time.sleep(.3);shot('phone-help')
service('phone')
for n in [11,21,31,41,50]:
 launch(n);time.sleep(.7);tap(427,482);time.sleep(.5);shot('phone-restaurant-'+str((n-1)//10+1)+('-last' if n==50 else ''))
adb('shell','wm','size','2560x1600');adb('shell','wm','density','320');launch();time.sleep(1);shot('tablet-title');service('tablet')
adb('shell','wm','size','2280x1080');adb('shell','wm','density','440');launch();time.sleep(.8)
(OUT/'final-interaction-log.json').write_text(json.dumps(log,indent=2));print('PASS: '+str(len(log))+' installed touch checkpoints',flush=True)
