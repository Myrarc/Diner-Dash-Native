package local.dinerdash.prototype;

import java.util.*;

public final class FullGameTest {
    private static int checks;
    private static void check(boolean truth,String reason){checks++;if(!truth)throw new AssertionError(reason);}
    private static void advance(GameEngine g,long ms){for(long t=0;t<ms;t+=100)g.tick(Math.min(100,ms-t));}
    private static GameEngine game(int n){GameEngine g=new GameEngine(LevelData.get(n),1234);g.paused=false;g.tick(1);return g;}
    private static void finishDirect(GameEngine g){
        for(int frame=0;frame<15000&&!g.ended;frame++){
            for(GameEngine.Party p:g.waiting()){
                int best=-1,bestValue=-1000,offset=0;
                for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);if(!t.active||t.barStart>=0||t.dirty||t.party!=null||t.colors.length<p.colors.length)continue;
                    for(int start=0;start<t.colors.length;start++){int value=-(t.colors.length-p.colors.length)*30;for(int c=0;c<p.colors.length;c++)if(p.colors[c]==t.colors[(start+c)%t.colors.length])value+=100*t.multipliers[(start+c)%t.colors.length];if(value>bestValue){best=id;bestValue=value;offset=start;}}}
                if(best>=0)g.seat(p.id,best,offset);else if(g.level.barColors!=null)for(int start=0;start<8;start++)if(g.seatBar(p.id,start))break;
            }
            // Zero travel isolates service/timer correctness from the independently tested queue/path.
            g.perform(GameEngine.BUS);
            for(GameEngine.Item item:new ArrayList<>(g.hands))if(item.type==GameEngine.ItemType.FOOD)g.perform(g.party(item.party).table);
            g.perform(GameEngine.KITCHEN);
            for(int slot=0;slot<g.foodSlots.length;slot++)if(g.foodAt(slot)!=null)g.perform(GameEngine.foodTarget(slot));
            for(GameEngine.Item item:new ArrayList<>(g.hands))if(item.type==GameEngine.ItemType.FOOD)g.perform(g.party(item.party).table);
            for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);if(!t.active)continue;if(t.party!=null&&t.party.state==GameEngine.State.READY){g.perform(id);if(g.hands.size()==g.capacity)g.perform(GameEngine.KITCHEN);}}
            g.perform(GameEngine.KITCHEN);
            for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);if(!t.active)continue;if(t.party!=null&&t.party.state==GameEngine.State.CHECK)g.perform(id);}
            for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);if(t.active&&t.dirty&&(t.party==null||t.party.state==GameEngine.State.LEAVING||t.party.state==GameEngine.State.SCORING)){g.perform(id);if(g.hands.size()==g.capacity)g.perform(GameEngine.BUS);}}
            for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);if(t.active&&t.party!=null&&t.party.state==GameEngine.State.SNACK){String snack=t.party.wantedSnack;g.perform(snack.equals(g.level.snacks[0])?GameEngine.SNACK1:GameEngine.SNACK2);g.perform(id);}}
            g.tick(100);
        }
    }
    public static void main(String[] args){
        int allParties=0,allTables=0,wins=0;
        for(int n=1;n<=50;n++){
            GameEngine g=game(n);check(g.level.stage==(n-1)/10+1,"Career stage mapping must preserve all five restaurants");
            check(g.level.goal>0&&!g.level.arrivals.isEmpty(),"Every recovered shift must have a goal and arrivals: "+n);
            long last=-1;for(GameEngine.Arrival a:g.level.arrivals){check(a.time>=last,"Arrival delays must accumulate in source order");last=a.time;}
            int max=0;for(GameEngine.Table t:g.level.tables){max=Math.max(max,t.colors.length);allTables++;check(t.colors.length==2||t.colors.length==4||t.colors.length==6,"Original table capacity must survive import");}
            for(GameEngine.Arrival a:g.level.arrivals)check(a.colors.length<=Math.max(max,g.level.barColors==null?0:8),"No scheduled party may exceed available capacity");
            for(int id=0;id<g.level.tables.size();id++){g.queue(id);advance(g,10000);check(g.currentTarget==GameEngine.NO_TARGET,"All table service positions must be reachable: "+n+":"+id);}
            g=game(n);finishDirect(g);check(g.ended,"Every finite schedule must close without a stuck party: "+n);allParties+=g.level.arrivals.size();if(g.won)wins++;
            System.out.println("Shift "+n+": score="+g.score+" goal="+g.goal+" served="+g.served+" angry="+g.abandoned+" ended="+g.ended);
        }
        GameEngine.Profile old=LevelData.profile("old_male"),business=LevelData.profile("business_female"),critic=LevelData.profile("critic");
        check(old.baseTip==5&&old.duration[1]==21000&&old.mad[0]==15000,"Seniors must retain slower service and greater patience");
        check(business.baseTip==15&&business.mad[0]==6000,"Businesswomen must retain their impatient higher-tip profile");
        check(critic.penalty==4000,"A critic's penalty must come from the active customer dump");
        GameEngine drinks=game(5);check(drinks.level.drinks!=null,"Drink station begins at the original career unlock");advance(drinks,10000);check(drinks.perform(GameEngine.DRINKS),"Drinks become available after refresh and occupy a hand");int dt=0;while(drinks.level.tables.get(dt).colors.length<drinks.party(0).colors.length)dt++;check(drinks.seat(0,dt),"Drink test needs a table with enough chairs");int mood=drinks.party(0).mood;check(drinks.perform(dt)&&drinks.party(0).mood==Math.min(10,mood+3),"Drinks boost mood without taking the order during menu selection");
        GameEngine god=game(50);check(god.capacity==4,"Goddess Flo must carry four items");check(god.seatBar(0,1),"Bar must accept a party in adjacent stools");check(!god.seatBar(1,2),"An overlapping bar segment must reject seating");
        GameEngine snack=game(50);int st=0;while(snack.level.tables.get(st).colors.length<snack.party(0).colors.length)st++;snack.seat(0,st);advance(snack,14000);boolean requested=snack.party(0).state==GameEngine.State.SNACK;if(requested){String wanted=snack.party(0).wantedSnack;int before=snack.score;snack.perform(wanted.equals(snack.level.snacks[0])?GameEngine.SNACK1:GameEngine.SNACK2);snack.perform(st);check(snack.party(0).state==GameEngine.State.DECIDING&&snack.score-before==150,"Serving the requested snack scores and resumes the interrupted menu timer");}else check(snack.party(0).state==GameEngine.State.READY,"A deterministic menu timer must still finish if no snack was selected");
        for(int stage=1;stage<=5;stage++)for(int difficulty=1;difficulty<=3;difficulty++){GameEngine e=new GameEngine(LevelData.endless(stage,difficulty),1);e.paused=false;e.tick(1);check(e.waiting().size()==1,"Every endless map must generate its opening group");double before=e.timeMultiplier;advance(e,e.level.rampMS);check(e.timeMultiplier<before,"Endless difficulty must ramp from its recovered starting multiplier");check(e.level.sublevels.size()==9,"Every endless map must retain nine goal/arrival tables");e.availableUpgrades=1;List<GameEngine.Upgrade> options=e.upgradeChoices();check(options.size()==3,"Shop offers one new table and two distinct powerups when possible");int tables=e.level.tables.size();e.applyUpgrade(options.get(0));check(e.level.tables.size()==tables+1&&e.availableUpgrades==0,"Choosing a table spends a single earned upgrade");}
        GameEngine e=new GameEngine(LevelData.endless(1,1),1);e.availableUpgrades=6;for(String type:new String[]{"shoes","oven","drinks","podium","stereo","maitred"})e.applyUpgrade(LevelData.upgrade(type,0));check(e.speed==90&&e.cookMS==4000&&e.level.drinks!=null&&e.level.podium!=null,"Speed, oven and station upgrades must affect gameplay");check(e.waitingPatience==1.1&&e.seatedPatience==1.1,"Patience upgrades must affect their intended customer states");
        e=new GameEngine(LevelData.endless(1,1),1);e.paused=false;advance(e,300000);check(e.ended&&e.stars==0,"An unattended endless shift must end after losing its stars");
        System.out.println("PASS: "+checks+" intent checks; "+allParties+" career parties, "+allTables+" career tables; zero-travel bot reached "+wins+"/50 goals.");
    }
}
