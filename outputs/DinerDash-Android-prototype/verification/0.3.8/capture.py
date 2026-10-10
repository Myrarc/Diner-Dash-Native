from pathlib import Path
import grpc,json,subprocess,sys,wave,time
import emulator_controller_pb2 as pb
w=Path(__file__).resolve().parent;adb=['/Users/myrarc/Library/Android/sdk/platform-tools/adb','-s','emulator-5554'];phase=sys.argv[1]
subprocess.run([*adb,'shell','cmd','media_session','volume','--stream','3','--set','10'],capture_output=True,check=True)
for mode in ['menu','game']:
  subprocess.run([*adb,'shell','am','force-stop','local.dinerdash.prototype'],capture_output=True,check=True)
  cmd=[*adb,'shell','am','start','-n','local.dinerdash.prototype/.MainActivity']
  if mode=='game':cmd+=['--ei','qa_level','1']
  subprocess.run(cmd,capture_output=True,check=True)
  time.sleep(1)
  channel=grpc.insecure_channel('127.0.0.1:8554')
  method=channel.unary_stream('/android.emulation.control.EmulatorController/streamAudio',request_serializer=pb.AudioFormat.SerializeToString,response_deserializer=pb.AudioPacket.FromString)
  call=method(pb.AudioFormat(samplingRate=44100,channels=pb.AudioFormat.Stereo,format=pb.AudioFormat.AUD_FMT_S16),timeout=26)
  chunks=[];packets=[];size=0
  try:
   for p in call:
    packets.append({'timestamp_us':p.timestamp,'samples':len(p.audio)//2});chunks.append(p.audio);size+=len(p.audio)
    if len(packets)==1:print("first packet",p.format,"bytes",len(p.audio),flush=True)
    if size>=18*44100*4:break
  except grpc.RpcError as e:
   print("capture stopped",e.code(),"bytes",size,"packets",len(packets),flush=True)
   if size==0:raise
  finally:call.cancel();channel.close()
  pcm=b''.join(chunks)
  with wave.open(str(w/(phase+'-'+mode+'.wav')),'wb') as f:f.setparams((2,2,44100,0,'NONE','not compressed'));f.writeframes(pcm)
  (w/(phase+'-'+mode+'-packets.json')).write_text(json.dumps(packets,indent=2)+'\n')
  print(phase,mode,len(pcm)//4,'frames',flush=True)
subprocess.run([*adb,'shell','am','force-stop','local.dinerdash.prototype'],capture_output=True,check=True)
