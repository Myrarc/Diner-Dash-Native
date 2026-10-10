package local.dinerdash.prototype;
import java.nio.file.*;
public final class Level19ExpertFrames {
    public static void main(String[] args)throws Exception {
        Level19ExpertReplay.planTables=new int[]{2,3,1,3,6,4,2,2,4,1,6,0,4,1,3,0,2,3,4,6,2,3};
        Level19ExpertReplay.planOffsets=new int[]{2,1,0,0,0,0,3,0,3,1,0,0,1,0,3,0,3,1,2,0,2,0};
        Level19ExpertReplay.orderWait=28000;Level19ExpertReplay.checkWait=12000;
        Level19ExpertReplay.orderBatch=2;Level19ExpertReplay.checkBatch=3;
        Level19ExpertReplay.holdFood=false;Level19ExpertReplay.holdChecks=true;
        for(int step:new int[]{100,50,20,16,17}){
            Level19ExpertReplay.tickStep=step;Level19ExpertReplay.record=true;Level19ExpertReplay.inputs.setLength(0);
            System.out.println("step="+step);Level19ExpertReplay.run(0,1,0,true,true);
            Files.writeString(Path.of("work/level-2-9/expert-frame-"+step+"-inputs.csv"),Level19ExpertReplay.inputs.toString());
        }
    }
}
