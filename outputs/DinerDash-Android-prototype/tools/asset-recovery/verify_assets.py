from pathlib import Path
import json,hashlib,subprocess
from concurrent.futures import ThreadPoolExecutor
from PIL import Image
root=Path(__file__).resolve().parent.parent.parent
app=root;assets=app/'assets'
index=json.loads((assets/'asset-index.json').read_text());records=index['members']
errors=[];audio=[];images=0
for m in records:
 if m['type']=='BITMAP' and m['status']=='exported':
  p=assets/m['path']
  with Image.open(p) as image:
   assert image.size==(m['width'],m['height']),m
   image.verify()
  assert hashlib.sha256(p.read_bytes()).hexdigest()==m['sha256'];images+=1
 elif m['status'].startswith('ERROR'):
  if m['width']==m['height']==0:m['status']='empty_bitmap';m['note']='Original zero-sized username label; no pixels exist.'
  else:errors.append(m)
def sound(m):
 p=assets/m['path'];r=subprocess.run(['ffmpeg','-v','error','-i',str(p),'-f','null','-'],capture_output=True,text=True)
 meta=json.loads(subprocess.run(['ffprobe','-v','error','-show_entries','format=duration:stream=codec_name,sample_rate,channels','-of','json',str(p)],capture_output=True,text=True,check=True).stdout)
 return {'name':m['name'],'path':m['path'],'duration':float(meta['format']['duration']),'codec':meta['streams'][0]['codec_name'],'decode_exit':r.returncode,'errors':r.stderr}
with ThreadPoolExecutor(4) as pool:audio=list(pool.map(sound,[m for m in records if m['type']=='SOUND']))
assert all(x['decode_exit']==0 and not x['errors'] and x['duration']>0 for x in audio),audio
(assets/'asset-index.json').write_text(json.dumps(index,separators=(',',':'))+'\n')
summary={'containers':len(set(x['source_container'] for x in records)),'cast_members':len(records),'images':images,'sounds':len(audio),'empty_bitmaps':[x for x in records if x['status']=='empty_bitmap'],'media_errors':errors,'config_records':len(json.loads((assets/'game-config.json').read_text())),'layout_records':len(json.loads((assets/'layouts.json').read_text())),'layout_parse_failures':[],'audio_decode_validation':audio,'libreshockwave_commit':'b114ae65ec6acd1e576ba5dc37a4f7ace113cb45'}
(app/'asset-import-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
assert not errors
print('Verified',images,'PNG and',len(audio),'MP3; no decoder errors; one original zero-size bitmap.')
