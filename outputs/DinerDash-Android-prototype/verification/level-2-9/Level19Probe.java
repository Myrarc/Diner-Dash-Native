package local.dinerdash.prototype;
import java.util.*;

/** Bounded scoring experiment; production timers, capacity, scoring and arrivals stay intact. */
public final class Level19Probe {
    static final int IDLE=0,ORDER=1,FOOD=2,CHECK=3,DISHES=4;
    static int phase,chairPoints,actionPoints,tipPoints,actions;
    static void seat(GameEngine g,int capacityPenalty){
        for(GameEngine.Party p:g.waiting()){
            int best=-1,offset=0,rotation=0,value=-100000;
            for(int id=0;id<g.level.tables.size();id++){
                GameEngine.Table t=g.level.tables.get(id);if(!g.canSeat(p.id,id))continue;
                for(int start=0;start<t.colors.length;start++)for(int rot=0;rot<p.colors.length;rot++){
                    int v=-(t.colors.length-p.colors.length)*capacityPenalty;
                    for(int c=0;c<p.colors.length;c++)if(p.colors[(c+rot)%p.colors.length]==t.colors[(start+c)%t.colors.length])v+=100*t.multipliers[(start+c)%t.colors.length];
                    if(v>value){value=v;best=id;offset=start;rotation=rot;}
                }
            }
            if(best>=0){int before=g.score;g.rotation=rotation;g.seat(p.id,best,offset);chairPoints+=g.score-before;}
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
        if(!checks.isEmpty()&&(checks.size()>=batch||g.level.tables.get(checks.get(0)).party.age>=wait))return CHECK;
        if(!orders.isEmpty()&&(orders.size()>=batch||g.level.tables.get(orders.get(0)).party.age>=wait))return ORDER;
        if(g.readyFoodCount()>0)return FOOD;
        if(!dishes.isEmpty())return DISHES;
        if(!checks.isEmpty()&&orders.isEmpty())return CHECK;
        return IDLE;
    }
    static void perform(GameEngine g,int target,boolean travel){if(travel)g.queue(target);else{int before=g.score;g.perform(target);actionPoints+=g.score-before;actions++;}}
    static void schedule(GameEngine g,long wait,int batch,boolean travel){
        if(g.currentTarget!=GameEngine.NO_TARGET||!g.destinations.isEmpty())return;
        if(phase==IDLE)phase=decide(g,wait,batch);
        for(int i=0;i<2;i++){
            if(phase==ORDER||phase==DISHES){List<Integer> ids=targets(g,phase);if(g.hands.size()==g.capacity||ids.isEmpty()&&!g.hands.isEmpty()){perform(g,phase==ORDER?GameEngine.KITCHEN:GameEngine.BUS,travel);return;}if(!ids.isEmpty()){perform(g,nearest(g,ids),travel);return;}}
            if(phase==FOOD){List<Integer> held=new ArrayList<>();for(GameEngine.Item item:g.hands)if(item.type==GameEngine.ItemType.FOOD)held.add(g.party(item.party).table);if(g.readyFoodCount()>0&&g.hands.size()<g.capacity){perform(g,g.firstReadyFoodTarget(),travel);return;}if(!held.isEmpty()){perform(g,nearest(g,held),travel);return;}}
            if(phase==CHECK){List<Integer> ids=targets(g,CHECK);if(!ids.isEmpty()){perform(g,nearest(g,ids),travel);return;}}
            phase=IDLE;if(i==0)phase=decide(g,wait,batch);
        }
    }
    static int run(long wait,int batch,int capacityPenalty,boolean travel,boolean detail){
        GameEngine g=new GameEngine(LevelData.get(19),1234);g.paused=false;phase=IDLE;chairPoints=actionPoints=tipPoints=actions=0;
        for(int i=0;i<7000&&!g.ended;i++){
            seat(g,capacityPenalty);schedule(g,wait,batch,travel);
            int before=g.score,served=g.served;g.tick(100);int tips=0;if(g.served>served)for(GameEngine.Party p:g.parties)if(p.state==GameEngine.State.LEAVING&&p.age==0)tips+=GameEngine.tip(p.colors.length,p.mood,p.profile.baseTip,p.profile.moodTip);
            tipPoints+=tips;actionPoints+=g.score-before-tips;
        }
        if(detail)System.out.println("travel="+travel+" wait="+wait+" batch="+batch+" capacityPenalty="+capacityPenalty+" score="+g.score+" goal="+g.goal+" expert="+g.level.expert+" served="+g.served+" angry="+g.abandoned+" ended="+g.ended+" chair="+chairPoints+" action="+actionPoints+" tips="+tipPoints);
        return g.ended&&g.abandoned==0?g.score:-1;
    }
    public static void main(String[] args){
        for(boolean travel:new boolean[]{false,true}){
            int best=-1,chosenBatch=0,chosenPenalty=0;long chosenWait=0;
            for(long wait:new long[]{0,4000,8000,12000,20000})for(int batch:new int[]{2,4,7})for(int penalty:new int[]{0,30,150}){int score=run(wait,batch,penalty,travel,false);if(score>best){best=score;chosenWait=wait;chosenBatch=batch;chosenPenalty=penalty;}}
            if(best>=0)run(chosenWait,chosenBatch,chosenPenalty,travel,true);else System.out.println("No no-loss completed candidate with travel="+travel);
        }
        GameEngine.Level l=LevelData.get(19);l.arrivals.clear();GameEngine g=new GameEngine(l,1);g.score=8600;g.paused=false;g.tick(100);g.tick(1500);if(!g.ended||!g.won||g.score>=g.level.expert)throw new AssertionError("8,600 must pass the normal goal without earning Expert");System.out.println("PASS: 8,600 clears Career 2-9 normal goal, without Expert");
    }
}
