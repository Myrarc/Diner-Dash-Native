import com.libreshockwave.DirectorFile;
import com.libreshockwave.chunks.*;
import com.libreshockwave.tools.scanning.MemberResolver;
import java.nio.file.*;
public class ReadSound {
 public static void main(String[] args)throws Exception{
  DirectorFile f=DirectorFile.load(Path.of(args[0]));
  for(var m:f.getCastMembers())if(m.name()!=null&&m.name().startsWith("music_")&&m.isSound()){
   System.out.println("MEMBER "+m.id()+" "+m.name()+" "+m.memberType());
   var sound=MemberResolver.findSoundForMember(f,m);
   System.out.println("RATE "+sound.sampleRate()+" count "+sound.sampleCount());
   for(var e:f.getKeyTable().getEntriesForOwner(m.id())){
    var c=f.getChunk(e.sectionId());System.out.println(e.fourccString()+" "+c+" info "+f.getChunkInfo(e.sectionId()));
    if(c instanceof RawChunk r)Files.write(Path.of("work/music-loops-0.3.8/"+m.name()+"-"+e.fourccString().trim()+".bin"),r.data());
   }
   Files.write(Path.of("work/music-loops-0.3.8/"+m.name()+"-snd.bin"),sound.audioData());

  }
 }
}
