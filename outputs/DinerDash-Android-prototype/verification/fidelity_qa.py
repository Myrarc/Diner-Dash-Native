from pathlib import Path
import io
from PIL import Image
import subprocess,xml.etree.ElementTree as E,re,json,time
ADB='/Users/myrarc/Library/Android/sdk/platform-tools/adb';ROOT=Path(__file__).resolve().parent.parent;OUT=ROOT/'work/fidelity-review';OUT.mkdir(exist_ok=True)
def adb(*a):return subprocess.run([ADB,'-s','emulator-5554',*map(str,a)],check=True,capture_output=True).stdout
def tree():
 adb('shell','uiautomator','dump','/sdcard/dd-qa.xml');return E.fromstring(adb('shell','cat','/sdcard/dd-qa.xml'))
def transform():
 w,h=Image.open(io.BytesIO(adb('exec-out','screencap','-p'))).size;s=min(w/800,h/600);return s,(w-800*s)/2,(h-600*s)/2
def tap(x,y):
 s,ox,oy=transform();adb('shell','input','tap',round(ox+x*s),round(oy+y*s))
def swipe(x,y,tx,ty,duration=900):
 s,ox,oy=transform();adb('shell','input','swipe',round(ox+x*s),round(oy+y*s),round(ox+tx*s),round(oy+ty*s),duration)
def shot(name): (OUT/(name+'.png')).write_bytes(adb('exec-out','screencap','-p'))
def state():
 n=next(n for n in tree().iter('node') if n.get('content-desc','').startswith('Restaurant.'));return n.get('content-desc')
def launch(n=None):
 adb('shell','am','force-stop','local.dinerdash.prototype');args=['shell','am','start','-W','-n','local.dinerdash.prototype/.MainActivity'];
 if n is not None:args+=['--ei','qa_level',n]
 adb(*args)
if __name__=='__main__':
 print(transform());tap(427,482);time.sleep(1);print(state());shot('phone-play')
 swipe(20,483,350,365);print(state());shot('phone-seated')
