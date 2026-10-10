from pathlib import Path
import array,json,wave
w=Path(__file__).resolve().parent;result={}
for phase in ['before','after']:
 result[phase]={}
 for mode in ['menu','game']:
  p=w/(phase+'-'+mode+'.wav')
  with wave.open(str(p),'rb') as f:
   rate=f.getframerate();channels=f.getnchannels();count=f.getnframes();a=array.array('h',f.readframes(count))
  assert rate==44100 and channels==2 and count>17*rate
  spans=[];start=None;active_first=None;active_last=None
  for i in range(0,len(a),channels):
   frame=i//channels;quiet=max(abs(x) for x in a[i:i+channels])<=1
   if not quiet:active_first=frame if active_first is None else active_first;active_last=frame
   if quiet and start is None:start=frame
   elif not quiet and start is not None:
    if frame-start>=rate*.02:spans.append({'start_s':round(start/rate,6),'duration_ms':round(1000*(frame-start)/rate,3),'initial_silence':start==0})
    start=None
  interior=[s for s in spans if not s['initial_silence']]
  result[phase][mode]={'duration_s':count/rate,'near_silence_threshold':1,'interior_spans_over_20ms':interior,'max_interior_near_silence_ms':max((s['duration_ms'] for s in interior),default=0),'peak_pcm16':max(map(abs,a))}
  assert max(map(abs,a))>100
for mode in ['menu','game']:
 assert result['before'][mode]['max_interior_near_silence_ms']>=500
 assert result['after'][mode]['max_interior_near_silence_ms']==0,'Unexpected output pause in '+mode
(w/'recorded-gap-analysis.json').write_text(json.dumps(result,indent=2)+'\n')
print(json.dumps(result,indent=2))
print('PASS: recorded menu and gameplay each contain >17s of audio; old pauses exceed 500ms; new output has no interior near-silence lasting 20ms')
