#!/usr/bin/env python3
"""Build with the standard Android SDK tools; no Gradle dependency."""
from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import zipfile

root = Path(__file__).resolve().parent
sdk = Path(os.environ.get('ANDROID_HOME', str(Path.home() / 'Library/Android/sdk')))
jdk = Path(os.environ.get('JAVA_HOME', '/opt/homebrew/opt/openjdk@21'))
build = Path(os.environ.get('BUILD_DIR', str(root.parent.parent / 'work/cake-mania-android/build'))).resolve()
build.mkdir(parents=True, exist_ok=True)
tools = sdk / 'build-tools/36.0.0'
android = sdk / 'platforms/android-36/android.jar'
assert android.is_file(), 'Android SDK platform 36 is required'
log = []


def run(args):
    result = subprocess.run([str(a) for a in args], text=True, capture_output=True,
                            env={**os.environ, 'JAVA_HOME': str(jdk)})
    log.append(' '.join(str(a) for a in args) + '\n' + result.stdout + result.stderr)
    (build / 'build.log').write_text('\n'.join(log))
    if result.returncode:
        raise RuntimeError(result.stdout + result.stderr)


for directory in ['classes', 'dex']:
    destination = build / directory
    if destination.exists():
        shutil.rmtree(destination)
    destination.mkdir()
run([tools / 'aapt2', 'compile', '--dir', root / 'res', '-o', build / 'resources.zip'])
run([tools / 'aapt2', 'link', '-I', android, '--manifest', root / 'AndroidManifest.xml',
     '-A', root / 'assets', '-0', 'mp3', '-0', 'wav', '-0', 'ogg', '-o', build / 'resources.apk', build / 'resources.zip'])
run([jdk / 'bin/javac', '-encoding', 'UTF-8', '-source', '8', '-target', '8', '-classpath', android,
     '-d', build / 'classes', *sorted((root / 'src').rglob('*.java'))])
run([tools / 'd8', '--lib', android, '--min-api', '23', '--output', build / 'dex',
     *sorted((build / 'classes').rglob('*.class'))])
shutil.copy2(build / 'resources.apk', build / 'unsigned.apk')
with zipfile.ZipFile(build / 'unsigned.apk', 'a', zipfile.ZIP_DEFLATED) as apk:
    for dex in (build / 'dex').glob('*.dex'):
        apk.write(dex, dex.name)
run([tools / 'zipalign', '-f', '4', build / 'unsigned.apk', build / 'aligned.apk'])
key = build / 'prototype.keystore'
if not key.exists():
    run([jdk / 'bin/keytool', '-genkeypair', '-noprompt', '-keystore', key, '-storepass', 'android',
         '-keypass', 'android', '-alias', 'prototype', '-keyalg', 'RSA', '-keysize', '2048',
         '-validity', '10000', '-dname', 'CN=Cake Mania Android', '-storetype', 'JKS'])
apk = root.parent / 'CakeMania-Android.apk'
run([tools / 'apksigner', 'sign', '--ks', key, '--ks-key-alias', 'prototype',
     '--ks-pass', 'pass:android', '--key-pass', 'pass:android', '--out', apk, build / 'aligned.apk'])
run([tools / 'apksigner', 'verify', '--verbose', '--print-certs', apk])
run([tools / 'aapt', 'dump', 'badging', apk])
shutil.copy2(build / 'build.log', root / 'build.log')
summary = {'package': 'local.cakemania', 'version': '0.1.9', 'min_sdk': 23,
           'target_sdk': 36, 'bytes': apk.stat().st_size,
           'apk_sha256': hashlib.sha256(apk.read_bytes()).hexdigest(),
           'signature_verified': True, 'signing': 'local prototype key, not a Play release',
           'source_sha256': {p.relative_to(root).as_posix(): hashlib.sha256(p.read_bytes()).hexdigest()
                             for p in sorted((root / 'src').rglob('*.java'))}}
(root / 'build-summary.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary, indent=2))
