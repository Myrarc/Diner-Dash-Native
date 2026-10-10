#!/usr/bin/env python3
"""Build a separate instrumentation APK; run real asset and Activity probes."""
from pathlib import Path
import os,subprocess,zipfile,sys
ROOT=Path(__file__).resolve().parents[1]
SDK=Path(os.environ.get('ANDROID_HOME',str(Path.home()/'Library/Android/sdk')))
JDK=Path(os.environ.get('JAVA_HOME','/opt/homebrew/opt/openjdk@21'))
WORK=ROOT.parent.parent/'work/cake-mania-android/build'
OUT=Path(sys.argv[1]) if len(sys.argv)>1 else ROOT/'verification/fixes-0.1.3/android-probes'
OUT.mkdir(parents=True,exist_ok=True)
STAGE=ROOT.parent.parent/'work/cake-mania-android/fix-0.1.3/instrumentation'
CLASSES=STAGE/'classes';CLASSES.mkdir(parents=True,exist_ok=True)
TOOLS=SDK/'build-tools/36.0.0';ANDROID=SDK/'platforms/android-36/android.jar';ADB=SDK/'platform-tools/adb'
def run(args):subprocess.run(list(map(str,args)),check=True)
PROBES=['AndroidAssetProbe','FlowAndroidProbe','MonthTextProbe']
run([JDK/'bin/javac','-cp',str(ANDROID)+os.pathsep+str(WORK/'classes'),'-d',CLASSES,*[ROOT/('tests/'+name+'.java') for name in PROBES]])
run([TOOLS/'d8','--lib',ANDROID,'--classpath',WORK/'classes','--min-api','23','--output',CLASSES,*sorted(CLASSES.rglob('*.class'))])
manifest=STAGE/'AndroidManifest.xml'
manifest.write_text('<manifest xmlns:android="http://schemas.android.com/apk/res/android" package="local.cakemania.tests"><uses-sdk android:minSdkVersion="23" android:targetSdkVersion="30"/><application android:label="Cake Renderer Tests"/>'+''.join('<instrumentation android:name="local.cakemania.'+name+'" android:targetPackage="local.cakemania"/>' for name in PROBES)+'</manifest>')
apk=STAGE/'probes.apk'
run([TOOLS/'aapt2','link','-I',ANDROID,'--manifest',manifest,'-o',apk])
with zipfile.ZipFile(apk,'a') as z:z.write(CLASSES/'classes.dex','classes.dex')
run([TOOLS/'apksigner','sign','--ks',WORK/'prototype.keystore','--ks-pass','pass:android','--key-pass','pass:android',apk])
run([ADB,'install','--no-incremental','-r',apk])
for probe in PROBES:
    text=subprocess.check_output([str(ADB),'shell','am','instrument','-w','local.cakemania.tests/local.cakemania.'+probe],stderr=subprocess.STDOUT,timeout=180).decode()
    (OUT/(probe+'.log')).write_text(text)
    print(text,flush=True)
    assert 'PASS:' in text and 'INSTRUMENTATION_FAILED' not in text and 'failure=' not in text,(probe,text)
(OUT/'jill-matrix.png').write_bytes(subprocess.check_output([str(ADB),'exec-out','run-as','local.cakemania','cat','files/cake-jill-matrix.png']))
for state in range(3):
    (OUT/('month-'+str(state)+'.png')).write_bytes(subprocess.check_output([str(ADB),'exec-out','run-as','local.cakemania','cat','files/cake-month-'+str(state)+'.png']))
print('PASS: Android asset and real Activity integration probes')
