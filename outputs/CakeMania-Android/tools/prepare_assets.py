#!/usr/bin/env python3
"""Adapt recovered TinyXML documents to Android DOM; preserve all attribute values."""
from pathlib import Path
import re, json, shutil, hashlib, subprocess, xml.etree.ElementTree as ET
from PIL import Image
root=Path(__file__).resolve().parents[1]
recovered=root.parent/'CakeMania-recovered'
assets=root/'assets'
files={p.relative_to(recovered/'data/images').as_posix().lower():p for p in (recovered/'data/images').rglob('*') if p.is_file()}
changes=[]
def normalize(text, resource=False):
    text=re.sub(r'<\?xml[^>]*\?>','',text)
    text=re.sub(r'&(?!#?\w+;)', '&amp;', text)
    if resource:text=re.sub(r'\s+(?:Pallete8|a4r4g4b4)(?=\s|/)', '', text)
    def dedup(m):
        tag=re.sub(r'(?<=")(?=\w+=")',' ',m.group(0));seen={}
        def attr(a):
            k,v=a.group(1),a.group(2)
            if k in seen:
                assert seen[k]==v, f'Contradicting duplicate attribute {k}'
                changes.append(k);return ''
            seen[k]=v;return a.group(0)
        return re.sub(r'\s+(\w+)="([^"]*)"',attr,tag)
    text=re.sub(r'<[^!?][^>]*>',dedup,text)
    t=ET.fromstring('<root>'+text+'</root>')
    return t
count=0
for p in sorted((recovered/'data/config_eng').rglob('*.xml')):
    try:t=normalize(p.read_text())
    except Exception as error:raise RuntimeError(str(p)+': '+str(error)) from error
    out=assets/'config'/p.relative_to(recovered/'data/config_eng').as_posix().lower()
    out.parent.mkdir(parents=True,exist_ok=True)
    ET.ElementTree(t).write(out,encoding='utf-8',xml_declaration=True);count+=1
manifest=normalize((recovered/'data/images/properties/resources.xml').read_text(),True)
resources=ET.Element('resources')
for group in manifest.iter('Resources'):
    path,prefix='',''
    for e in group:
        if e.tag=='SetDefaults':path=e.get('path','');prefix=e.get('idprefix','');continue
        if e.tag not in ['Image','Sound','Font']:continue
        key=prefix+e.get('id',''); candidate=path+'/'+e.get('path','')
        choices=[candidate] if '.' in Path(candidate).name else [candidate+x for x in ['.png','.jpg','.ogg']]
        found=next((files[x.lower()] for x in choices if x.lower() in files),None)
        assert found is not None,(key,candidate)
        relative=found.relative_to(recovered/'data/images')
        ET.SubElement(resources,'resource',id=key,path='original/'+relative.as_posix(),kind=e.tag)
ET.ElementTree(resources).write(assets/'resources.xml',encoding='utf-8',xml_declaration=True)
media=0
for p in sorted((recovered/'data/images').rglob('*')):
    if p.is_file() and p.suffix.lower() in ['.png','.jpg','.ogg','.txt']:
        dst=assets/'original'/p.relative_to(recovered/'data/images');dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,dst);media+=1
for p in sorted((recovered/'data/music/music').glob('*.ogg')):
    dst=assets/'music'/p.name;dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,dst);media+=1
audio=[]
# Android 11's Tremolo decoder aborts on at least one original Vorbis stream.
# Retain the originals and use lossless decoded PCM for Android playback.
for p in sorted(list((assets/'original/sounds').glob('*.ogg'))+list((assets/'music').glob('*.ogg'))):
    dst=assets/'decoded-audio'/p.relative_to(assets).with_suffix('.wav')
    dst.parent.mkdir(parents=True,exist_ok=True)
    subprocess.run(['ffmpeg','-hide_banner','-loglevel','error','-y','-i',str(p),'-c:a','pcm_s16le',str(dst)],check=True)
    audio.append(dst.relative_to(assets).as_posix())
shutil.copytree(recovered/'font-data',assets/'font-data',dirs_exist_ok=True)
# Use the recovered game logo inside a square launcher icon.
logo=Image.open(recovered/'data/images/images/logo.png').convert('RGBA')
icon=Image.new('RGBA',(192,192),(66,25,76,255));logo.thumbnail((184,160));icon.alpha_composite(logo,((192-logo.width)//2,(192-logo.height)//2));icon.save(root/'res/mipmap-xhdpi/ic_launcher.png')
report={'config_documents':count,'resources':len(resources),'original_media_files':media,'decoded_pcm_audio_files':len(audio),'identical_duplicate_attributes_removed':len(changes),'asset_sha256':{p.relative_to(assets).as_posix():hashlib.sha256(p.read_bytes()).hexdigest() for p in sorted(assets.rglob('*')) if p.is_file()}}
(root/'asset-preparation.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps({k:v for k,v in report.items() if k!='asset_sha256'}))
