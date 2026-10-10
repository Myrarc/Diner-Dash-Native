#!/usr/bin/env python3
"""Decode music using the original ediM delay and sample count; keep the MP3s intact."""
from pathlib import Path
import hashlib,json,re,struct,subprocess,wave
root=Path(__file__).resolve().parent.parent
source=root.parent/'DinerDash-recovered/reconstructed/snd/sfx.cst'
data=source.read_bytes();index=json.loads((root/'assets/asset-index.json').read_text())
out=root/'assets/music';out.mkdir(exist_ok=True)
records=[]
for m in index['members']:
    if m['cast']!='sfx' or not re.fullmatch(r'music_[chij][1-8]',m['name']) or m['status']!='exported':continue
    # Match the exact original MP3 payload inside its 320-byte ediM header.
    mp3=(root/'assets'/m['path']).read_bytes();assert hashlib.sha256(mp3).hexdigest()==m['sha256']
    offset=data.find(b'\0\0\0\0'+mp3);assert offset>=320 and data.find(b'\0\0\0\0'+mp3,offset+1)==-1
    header,kind,rate,bitrate,delay,frames=struct.unpack_from('>6I',data,offset-320)
    assert (header,kind,rate,delay)==(320,3,16000,1393) and frames>0
    pcm=subprocess.run(['ffmpeg','-v','error','-i',str(root/'assets'/m['path']),'-f','s16le','-ac','1','-ar',str(rate),'-'],capture_output=True,check=True).stdout
    trimmed=pcm[delay*2:(delay+frames)*2];assert len(trimmed)==frames*2
    p=out/(m['name']+'.wav')
    with wave.open(str(p),'wb') as f:f.setparams((1,2,rate,0,'NONE','not compressed'));f.writeframes(trimmed)
    with wave.open(str(p),'rb') as f:assert f.getnframes()==frames and f.readframes(frames)==trimmed
    records.append({'name':m['name'],'mp3_path':m['path'],'mp3_sha256':m['sha256'],'source_header_offset':offset-320,'sample_rate':rate,'bitrate':bitrate,'skip_samples':delay,'sample_count':frames,'untrimmed_sample_count':len(pcm)//2,'removed_tail_samples':len(pcm)//2-delay-frames,'path':p.relative_to(root/'assets').as_posix(),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()})
assert len(records)==26 and sum(p.stat().st_size for p in out.glob('*.wav'))<5_000_000
(root/'verification/music-loop-assets.json').write_text(json.dumps({'source':str(source.relative_to(root.parent)),'source_sha256':hashlib.sha256(data).hexdigest(),'records':records},indent=2)+'\n')
print('PASS: 26 music loops match original ediM sample boundaries and decoded PCM; original MP3 hashes intact')
