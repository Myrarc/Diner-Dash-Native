#!/usr/bin/env python3
"""Build and run the small Canvas instrumentation check against an installed APK."""
from pathlib import Path
import os,subprocess,sys,zipfile
root=Path(__file__).resolve().parent.parent
sdk=Path(os.environ.get('ANDROID_HOME',str(Path.home()/'Library/Android/sdk')))
jdk=Path(os.environ.get('JAVA_HOME','/opt/homebrew/opt/openjdk@21'))
build=root.parent.parent/'work/android-build'
b=root.parent.parent/'work/animation-tests'
b.mkdir(exist_ok=True)
tests=['AndroidAnimationTest','AndroidProgressTest','AndroidGuestTest','AndroidSpriteAuditTest','AndroidAudioTest','AndroidBugRegressionTest','AndroidPatienceTest']
selected=sys.argv[1:] or tests
assert all(test in tests for test in selected),'Unknown installed test'
for name in ['classes','dex']:(b/name).mkdir(exist_ok=True)
(b/'AndroidManifest.xml').write_text('<manifest xmlns:android="http://schemas.android.com/apk/res/android" package="local.dinerdash.animationtests"><uses-sdk android:minSdkVersion="23" android:targetSdkVersion="36"/><application/>'+''.join('<instrumentation android:name="local.dinerdash.prototype.'+test+'" android:targetPackage="local.dinerdash.prototype"/>' for test in tests)+'</manifest>')
t=sdk/'build-tools/36.0.0'
def run(args):
 return subprocess.run([str(a) for a in args],check=True,capture_output=True,text=True)
run([jdk/'bin/javac','-cp',str(sdk/'platforms/android-36/android.jar')+os.pathsep+str(build/'classes'),'-d',b/'classes',*[root/('tests/'+test+'.java') for test in tests],root/'tests/PatienceTest.java'])
run([t/'d8','--lib',sdk/'platforms/android-36/android.jar','--min-api','23','--output',b/'dex',*b.glob('classes/**/*.class')])
run([t/'aapt2','link','-I',sdk/'platforms/android-36/android.jar','--manifest',b/'AndroidManifest.xml','-o',b/'unsigned.apk'])
with zipfile.ZipFile(b/'unsigned.apk','a',zipfile.ZIP_DEFLATED) as z:z.write(b/'dex/classes.dex','classes.dex')
run([t/'zipalign','-f','4',b/'unsigned.apk',b/'aligned.apk'])
run([t/'apksigner','sign','--ks',build/'prototype.keystore','--ks-key-alias','prototype','--ks-pass','pass:android','--key-pass','pass:android','--out',b/'tests.apk',b/'aligned.apk'])
adb=[sdk/'platform-tools/adb','-s',os.environ.get('ANDROID_SERIAL','emulator-5554')]
print(run([*adb,'install','--no-incremental','-r',root.parent/'DinerDash-Android.apk']).stdout,flush=True)
print(run([*adb,'install','--no-incremental','-r',b/'tests.apk']).stdout,flush=True)
logs=dict(zip(tests,['animation-test.log','progress-test.log','guest-test.log','sprite-audit-test.log','audio-test.log','bug-regression-test.log','patience-test.log']))
for test in selected:
 filename=logs[test]
 r=run([*adb,'shell','am','instrument','-w','local.dinerdash.animationtests/local.dinerdash.prototype.'+test])
 (b/filename).write_text(r.stdout+r.stderr)
 print(r.stdout+r.stderr,flush=True)
 assert 'PASS:' in r.stdout and 'INSTRUMENTATION_CODE: -1' in r.stdout,test+' failed; read '+filename
