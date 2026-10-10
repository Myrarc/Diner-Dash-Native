package local.dinerdash.prototype;
import java.nio.file.*;
import java.util.*;

/** Independent input-only replay. No policy, teleport, score injection or timer edits. */
public final class Level19ReplayCheck {
    static void require(boolean okay,String reason){if(!okay)throw new AssertionError(reason);}
    static void run(List<String> rows,int step){
        GameEngine g=new GameEngine(LevelData.get(19),1234);g.paused=false;
        int input=0,seats=0,queues=0,chair=0,tips=0,actions=0,maxHands=0,maxQueue=0;
        Set<Integer> seated=new HashSet<>();Map<String,Integer> serviceCounts=new TreeMap<>();
        while(!g.ended&&g.time<700000){
            while(input<rows.size()&&Long.parseLong(rows.get(input).split(",")[0])==g.time){
                String[] e=rows.get(input++).split(",");
                if(e[1].equals("seat")){
                    int party=Integer.parseInt(e[2]),table=Integer.parseInt(e[3]),offset=Integer.parseInt(e[4]);
                    require(g.waiting().indexOf(g.party(party))>=0&&g.waiting().indexOf(g.party(party))<8,"Seat input must address a visible guest at "+g.time);
                    require(seated.add(party)&&g.canSeat(party,table),"Seat input must address a clean, available table at "+g.time);
                    int[] colors=g.party(party).colors.clone();int before=g.score;
                    require(g.seat(party,table,offset),"Seat input rejected at "+g.time);
                    require(Arrays.equals(colors,g.party(party).colors),"Guest order must never be rotated");
                    chair+=g.score-before;seats++;
                }else{
                    require(e[1].equals("queue"),"Only ordinary seating and queue inputs are allowed");
                    int target=Integer.parseInt(e[2]);
                    boolean usable=false;
                    if(target<=GameEngine.FOOD1){GameEngine.Party p=g.foodAt(GameEngine.FOOD1-target);usable=p!=null&&p.foodReady&&g.hands.size()<g.capacity;}
                    else if(target==GameEngine.KITCHEN){for(GameEngine.Item item:g.hands)usable|=item.type==GameEngine.ItemType.TICKET;}
                    else if(target==GameEngine.BUS){for(GameEngine.Item item:g.hands)usable|=item.type==GameEngine.ItemType.DISHES;}
                    else if(target>=0){GameEngine.Table t=g.level.tables.get(target);GameEngine.Party p=t.party;
                        usable=p==null&&t.dirty&&g.hands.size()<g.capacity||p!=null&&(p.state==GameEngine.State.READY||p.state==GameEngine.State.CHECK)&&g.hands.size()<g.capacity;
                        if(p!=null&&p.state==GameEngine.State.ORDERED)for(GameEngine.Item item:g.hands)usable|=item.type==GameEngine.ItemType.FOOD&&item.party==p.id;
                    }
                    require(usable,"Input must address a currently usable object at "+g.time+" target="+target);g.queue(target);
                    require(g.currentTarget!=GameEngine.NO_TARGET||!g.destinations.isEmpty(),"Queue input must start or append a reachable action at "+g.time);queues++;
                }
            }
            long delta=step;
            if(input<rows.size())delta=Math.min(delta,Long.parseLong(rows.get(input).split(",")[0])-g.time);
            require(delta>0,"Inputs must be monotonic");
            Map<Integer,GameEngine.State> states=new HashMap<>();for(GameEngine.Party p:g.parties)states.put(p.id,p.state);
            int target=g.currentTarget;GameEngine.Party targetParty=target>=0?g.level.tables.get(target).party:null;
            String service=target<0?"station":targetParty==null?"dishes":targetParty.state==GameEngine.State.READY?"ticket":targetParty.state==GameEngine.State.CHECK?"check":"food";
            int before=g.score;g.tick(delta);int tickTips=0;
            for(GameEngine.Party p:g.parties)if(states.get(p.id)==GameEngine.State.SCORING&&p.state==GameEngine.State.LEAVING)tickTips+=GameEngine.tip(p.colors.length,p.mood,p.profile.baseTip,p.profile.moodTip);
            tips+=tickTips;int serviceGain=g.score-before-tickTips;actions+=serviceGain;if(serviceGain>0)serviceCounts.merge(service,1,Integer::sum);
            maxHands=Math.max(maxHands,g.hands.size());maxQueue=Math.max(maxQueue,g.destinations.size());
            require(g.hands.size()<=2,"Flo must retain two-item capacity");
        }
        require(input==rows.size()&&seats==22&&g.ended&&g.won&&g.served==22&&g.abandoned==0,"The complete input replay must finish all 22 parties without losses");
        require(g.score==chair+actions+tips,"Every point must reconcile");
        for(String service:new String[]{"ticket","food","check","dishes"})require(serviceCounts.getOrDefault(service,0)==22,"All 22 parties must receive the scored "+service+" action");
        System.out.println("step="+step+" score="+g.score+" expert="+(g.score>=g.level.expert)+" served="+g.served+" lost="+g.abandoned+" ended="+g.ended+" time="+g.time+" seats="+seats+" queues="+queues+" chair="+chair+" action="+actions+" tips="+tips+" maxHands="+maxHands+" maxQueue="+maxQueue+" serviceCounts="+serviceCounts);
    }
    public static void main(String[] args)throws Exception{
        List<String> rows=Files.readAllLines(Path.of(args[0]));run(rows,args.length>1?Integer.parseInt(args[1]):100);
    }
}
