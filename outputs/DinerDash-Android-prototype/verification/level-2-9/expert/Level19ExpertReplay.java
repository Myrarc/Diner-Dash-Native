package local.dinerdash.prototype;
import java.util.*;

/** Bounded scoring experiment; production timers, capacity, scoring and arrivals stay intact. */
public final class Level19ExpertReplay {
    static final int IDLE=0,ORDER=1,FOOD=2,CHECK=3,DISHES=4;
    static int[] planTables,planOffsets,usedTables,usedOffsets;static boolean record;static StringBuilder inputs=new StringBuilder();
    static long orderWait,checkWait;static int orderBatch,checkBatch;static boolean holdFood,holdChecks;
    static int tickStep=100;
    static int phase,chairPoints,actionPoints,tipPoints,actions;
    static void seat(GameEngine g,int capacityPenalty){
        for(GameEngine.Party p:g.waiting()){
            int best=-1,offset=0,rotation=0,value=-100000;if(planTables!=null){best=planTables[p.id];offset=planOffsets[p.id];if(!g.canSeat(p.id,best))continue;}
            for(int id=0;planTables==null&&id<g.level.tables.size();id++){
                GameEngine.Table t=g.level.tables.get(id);if(!g.canSeat(p.id,id)||t.colors.length==6&&p.colors.length<5||t.colors.length==4&&p.colors.length<3)continue;
                for(int start=0;start<t.colors.length;start++)for(int rot=0;rot<1;rot++){
                    int v=-(t.colors.length-p.colors.length)*capacityPenalty;
                    for(int c=0;c<p.colors.length;c++)if(p.colors[(c+rot)%p.colors.length]==t.colors[(start+c)%t.colors.length])v+=100*t.multipliers[(start+c)%t.colors.length];
                    if(v>value){value=v;best=id;offset=start;rotation=rot;}
                }
            }
            if(best>=0){int before=g.score;g.rotation=rotation;g.seat(p.id,best,offset);usedTables[p.id]=best;usedOffsets[p.id]=offset;if(record)inputs.append(g.time).append(",seat,").append(p.id).append(",").append(best).append(",").append(offset).append("\n");chairPoints+=g.score-before;}
        }
    }
    static List<Integer> targets(GameEngine g,int mode){
        List<Integer> out=new ArrayList<>();for(int id=0;id<g.level.tables.size();id++){
            GameEngine.Table t=g.level.tables.get(id);GameEngine.Party p=t.party;
            if(mode==DISHES&&t.dirty&&p==null||p!=null&&(mode==ORDER&&p.state==GameEngine.State.READY||mode==CHECK&&p.state==GameEngine.State.CHECK))out.add(id);
        }
        out.sort((a,b)->Long.compare(g.level.tables.get(b).party==null?0:g.level.tables.get(b).party.age,g.level.tables.get(a).party==null?0:g.level.tables.get(a).party.age));return out;
    }
    static int nearest(GameEngine g,List<Integer> ids){int best=ids.get(0),distance=999;for(int id:ids){int[] d=g.destination(id);int v=Math.abs(d[0]-g.floX)+Math.abs(d[1]-g.floY);if(v<distance){distance=v;best=id;}}return best;}
    static int decide(GameEngine g,long wait,int batch){
        List<Integer> orders=targets(g,ORDER),checks=targets(g,CHECK),dishes=targets(g,DISHES);
        for(GameEngine.Party p:g.parties)if(p.state==GameEngine.State.ORDERED&&p.mood<=2&&g.readyFoodCount()>0)return FOOD;
        if(!checks.isEmpty()&&(checks.size()>=checkBatch||g.level.tables.get(checks.get(0)).party.age>=checkWait||g.level.tables.get(checks.get(0)).party.mood<=2))return CHECK;
        if(!orders.isEmpty()&&(orders.size()>=orderBatch||g.level.tables.get(orders.get(0)).party.age>=orderWait||g.level.tables.get(orders.get(0)).party.mood<=2))return ORDER;
        if(g.readyFoodCount()>0)return FOOD;
        if(!dishes.isEmpty()){
            boolean blocking=false;for(GameEngine.Party p:g.waiting()){boolean room=false;for(int id=0;id<g.level.tables.size();id++)room|=g.canSeat(p.id,id);if(!room)blocking=true;}
            boolean allGone=g.nextArrival==g.level.arrivals.size();for(GameEngine.Party p:g.parties)allGone&=p.state==GameEngine.State.GONE;
            if(dishes.size()>=batch||blocking||allGone)return DISHES;
        }
        return IDLE;
    }
    static void perform(GameEngine g,int target,boolean travel){if(travel){if(record)inputs.append(g.time).append(",queue,").append(target).append("\n");g.queue(target);}else{int before=g.score;g.perform(target);actionPoints+=g.score-before;actions++;}}
    static void schedule(GameEngine g,long wait,int batch,boolean travel){
        if(g.currentTarget!=GameEngine.NO_TARGET||!g.destinations.isEmpty())return;
        if(phase==IDLE)phase=decide(g,wait,batch);
        for(int i=0;i<2;i++){
            if(phase==ORDER||phase==DISHES){List<Integer> ids=targets(g,phase);if(g.hands.size()==g.capacity||ids.isEmpty()&&!g.hands.isEmpty()){perform(g,phase==ORDER?GameEngine.KITCHEN:GameEngine.BUS,travel);return;}if(!ids.isEmpty()){perform(g,nearest(g,ids),travel);return;}}
            if(phase==FOOD){List<Integer> held=new ArrayList<>();for(GameEngine.Item item:g.hands)if(item.type==GameEngine.ItemType.FOOD)held.add(g.party(item.party).table);if(g.readyFoodCount()>0&&g.hands.size()<g.capacity){perform(g,g.firstReadyFoodTarget(),travel);return;}if(!held.isEmpty()){perform(g,nearest(g,held),travel);return;}if(holdFood){for(GameEngine.Party p:g.parties)if(p.state==GameEngine.State.ORDERED)return;}}
            if(phase==CHECK){List<Integer> ids=targets(g,CHECK);if(!ids.isEmpty()){perform(g,nearest(g,ids),travel);return;}if(holdChecks){for(GameEngine.Party p:g.parties)if(p.state==GameEngine.State.EATING)return;}}
            phase=IDLE;if(i==0)phase=decide(g,wait,batch);
        }
    }
    static int run(long wait,int batch,int capacityPenalty,boolean travel,boolean detail){
        GameEngine g=new GameEngine(LevelData.get(19),1234);g.paused=false;usedTables=new int[22];usedOffsets=new int[22];Arrays.fill(usedTables,-1);phase=IDLE;chairPoints=actionPoints=tipPoints=actions=0;
        for(int i=0;i<700000/tickStep&&!g.ended;i++){
            seat(g,capacityPenalty);schedule(g,wait,batch,travel);
            int before=g.score,served=g.served,angry=g.abandoned;g.tick(tickStep);if(detail&&g.abandoned>angry)System.out.println("LOST at="+g.time+" phase="+phase+" hands="+g.handsText()+" current="+g.currentTarget+" message="+g.message);int tips=0;if(g.served>served)for(GameEngine.Party p:g.parties)if(p.state==GameEngine.State.LEAVING&&p.age==0)tips+=GameEngine.tip(p.colors.length,p.mood,p.profile.baseTip,p.profile.moodTip);
            tipPoints+=tips;actionPoints+=g.score-before-tips;
        }
        if(detail)System.out.println("travel="+travel+" wait="+wait+" batch="+batch+" capacityPenalty="+capacityPenalty+" score="+g.score+" goal="+g.goal+" expert="+g.level.expert+" served="+g.served+" angry="+g.abandoned+" ended="+g.ended+" chair="+chairPoints+" action="+actionPoints+" tips="+tipPoints);
        return g.ended?g.score-g.abandoned*100000:-100000000;
    }
    public static void main(String[] args)throws Exception{
        orderWait=24000;checkWait=16000;orderBatch=3;checkBatch=3;holdFood=false;holdChecks=true;
        int best=run(0,2,0,true,false);int[] bestTables=usedTables.clone(),bestOffsets=usedOffsets.clone();Random random=new Random(381822);GameEngine.Level level=LevelData.get(19);
        for(int candidate=0;candidate<2400;candidate++){
            planTables=bestTables.clone();planOffsets=bestOffsets.clone();int mutations=candidate%8==0?3:1;
            for(int mutation=0;mutation<mutations;mutation++){
                int id=random.nextInt(22),capacity=level.tables.get(planTables[id]).colors.length;
                if(random.nextInt(4)==0){List<Integer> eligible=new ArrayList<>();for(int table=0;table<level.tables.size();table++)if(level.tables.get(table).colors.length==capacity)eligible.add(table);planTables[id]=eligible.get(random.nextInt(eligible.size()));}
                planOffsets[id]=random.nextInt(capacity);
            }
            int score=run(0,2,0,true,false);if(score>best){best=score;bestTables=planTables.clone();bestOffsets=planOffsets.clone();System.out.println("candidate="+candidate+" best="+best);}
        }
        planTables=bestTables;planOffsets=bestOffsets;record=true;inputs.setLength(0);run(0,2,0,true,true);
        System.out.println("tables="+Arrays.toString(bestTables));System.out.println("offsets="+Arrays.toString(bestOffsets));java.nio.file.Files.writeString(java.nio.file.Path.of("work/level-2-9/expert-inputs.csv"),inputs.toString());
    }
}
