import com.libreshockwave.DirectorFile;
import com.libreshockwave.chunks.*;
import com.libreshockwave.tools.scanning.MemberResolver;
import java.nio.file.*;
public class ReadMusic {
 public static void main(String[] args)throws Exception{
  DirectorFile f=DirectorFile.load(Path.of(args[0]));
  for(var m:f.getCastMembers())if(m.name()!=null&&m.name().startsWith("music_")&&!m.isSound()){
   System.out.println("MEMBER "+m.id()+" "+m.name()+" "+m.memberType());
   var t=MemberResolver.findTextForMember(f,m);
   if(t!=null)System.out.println("TEXT "+t.text().replace('\r','\n'));
   for(var e:f.getKeyTable().getEntriesForOwner(m.id())){
    var c=f.getChunk(e.sectionId());if(c instanceof RawChunk r)Files.write(Path.of("work/menu-audio-0.3.7/"+m.name()+".bin"),r.data());System.out.println(e+" CLASS "+(c==null?"null":c.getClass())+" INFO "+f.getChunkInfo(e.sectionId()));
   }
  }
 }
}
