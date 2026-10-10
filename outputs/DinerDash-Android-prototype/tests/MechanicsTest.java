package local.dinerdash.prototype;

/** Recovered service contracts: recover wrong pickups without losing orders or earning extra points. */
public final class MechanicsTest {
    private static int checks;
    private static void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private static GameEngine game(int count,int slots){
        GameEngine.Level l=new GameEngine.Level(1,100000,200000);l.height=16;
        l.foodPositions=new int[slots][2];for(int i=0;i<slots;i++)l.foodPositions[i]=new int[]{7+2*i,3};
        for(int i=0;i<count;i++){l.tables.add(new GameEngine.Table(5+4*(i%3),6+4*(i/3),new int[]{-1,-1}));l.arrivals.add(new GameEngine.Arrival(0,new int[]{0,0},false));}
        GameEngine g=new GameEngine(l,1);g.paused=false;g.tick(1);return g;
    }
    private static GameEngine ready(int count,int slots){GameEngine g=game(count,slots);for(int i=0;i<count;i++)check(g.seat(i,i),"Fixture parties must sit at separate clean tables");g.tick(g.party(0).stateDuration);return g;}
    private static GameEngine overflow(){
        GameEngine g=ready(4,2);g.perform(0);g.perform(1);g.perform(GameEngine.KITCHEN);g.tick(5000);
        check(g.readyFoodCount()==2,"Both counter slots must fill before testing overflow");
        g.perform(3);g.perform(GameEngine.KITCHEN);g.tick(1000);g.perform(2);g.perform(GameEngine.KITCHEN);g.tick(5000);return g;
    }
    public static void main(String[] args){
        GameEngine g=game(1,2);g.seat(0,0);g.party(0).state=GameEngine.State.ORDERED;g.capacity=10;
        for(GameEngine.ItemType type:new GameEngine.ItemType[]{GameEngine.ItemType.DISHES,GameEngine.ItemType.DRINK,GameEngine.ItemType.SOMOSA,GameEngine.ItemType.PAPADOM,GameEngine.ItemType.BREAD,GameEngine.ItemType.CRAB,GameEngine.ItemType.FOOD})g.hands.add(new GameEngine.Item(type,type==GameEngine.ItemType.FOOD?0:-1));
        g.hands.add(new GameEngine.Item(GameEngine.ItemType.TICKET,0));
        check(g.perform(GameEngine.BUS),"The cart must accept every supported unwanted item, including food");
        check(g.hands.size()==1&&g.hands.get(0).type==GameEngine.ItemType.TICKET,"Disposal must free hands while retaining order tickets for the kitchen");
        check(g.party(0).cookingUntil==g.time+5000&&!g.party(0).foodPickedUp,"A returned meal must recook for its still-seated customer");
        long deadline=g.party(0).cookingUntil;g.tick(1000);g.perform(GameEngine.KITCHEN);
        check(g.party(0).cookingUntil==deadline,"A duplicate ticket must not restart an already cooking meal");
        g.tick(4000);check(g.readyFoodCount()==1,"The returned meal must reappear after the full cooking interval");
        check(g.perform(g.firstReadyFoodTarget())&&g.perform(0)&&g.party(0).state==GameEngine.State.EATING,"Disposal and recooking must leave the original customer serviceable");
        g.hands.add(new GameEngine.Item(GameEngine.ItemType.FOOD,999));check(g.perform(GameEngine.BUS)&&g.hands.isEmpty(),"An orphaned meal must be discardable without inventing a new order");

        g=ready(2,2);g.party(0).mood=4;g.hands.add(new GameEngine.Item(GameEngine.ItemType.TICKET,1));g.hands.add(new GameEngine.Item(GameEngine.ItemType.DRINK,-1,3));
        check(g.perform(0)&&g.party(0).mood==7,"Full-handed Flo must deliver carried coffee to an order-ready table");
        check(g.party(0).state==GameEngine.State.READY&&g.hands.size()==1&&g.hands.get(0).type==GameEngine.ItemType.TICKET,"Coffee fallback must keep the order pending and preserve unrelated payloads");
        g=ready(1,2);g.hands.add(new GameEngine.Item(GameEngine.ItemType.DRINK,-1,3));
        check(g.perform(0)&&g.party(0).state==GameEngine.State.ORDERED&&g.hands.get(0).type==GameEngine.ItemType.DRINK,"With a free hand, taking the order has priority over coffee");
        g=ready(1,2);g.hands.add(new GameEngine.Item(GameEngine.ItemType.BREAD,-1));g.hands.add(new GameEngine.Item(GameEngine.ItemType.DISHES,-1));
        check(!g.perform(0)&&g.party(0).state==GameEngine.State.READY&&g.hands.size()==2,"A full-handed visit without coffee must fail without consuming items");

        g=game(2,2);g.party(0).mood=g.party(1).mood=1;g.heldParty=0;g.selectedParty=1;g.tick(30000);
        check(g.party(0).state==GameEngine.State.WAITING&&g.party(0).mood==1,"A held guest must keep its last heart even after a patience timeout");
        check(g.party(1).state==GameEngine.State.GONE&&g.abandoned==1,"Selection alone must not protect an unheld guest from abandonment");
        g.heldParty=-1;g.tick(10000);check(g.party(0).state==GameEngine.State.GONE,"Releasing a guest must restore ordinary patience behavior");

        g=overflow();check(g.party(2).cookingUntil==0&&g.party(3).cookingUntil==0,"Completed overflow orders must stop cooking so the chef can rest");
        check(g.perform(GameEngine.foodTarget(0))&&g.foodAt(0).id==3,"Freeing a tray must immediately show the first completed overflow meal");
        check(g.perform(GameEngine.foodTarget(1))&&g.foodAt(1).id==2,"Later completed food must follow in completion order, independent of guest arrival order");
        g=overflow();g.party(3).mood=1;g.party(3).moodAge=g.party(3).profile.mad[GameEngine.State.ORDERED.ordinal()]-1;g.tick(1);
        check(g.party(3).state==GameEngine.State.DITCHING,"The overflow fixture must abandon the first queued meal's party");
        g.perform(GameEngine.foodTarget(0));check(g.foodAt(0).id==2,"Abandonment must remove a queued meal so it cannot block a live customer's food");
        g=ready(3,3);g.perform(0);g.perform(GameEngine.KITCHEN);g.tick(5000);g.perform(GameEngine.foodTarget(0));g.perform(0);g.perform(1);g.perform(GameEngine.KITCHEN);g.tick(5000);
        check(g.party(1).foodSlot==1&&g.foodAt(0)==null,"A freed tray must join behind trays already empty, preserving the recovered kitchen's spot order");

        g=game(3,2);g.seat(0,0);g.party(0).state=GameEngine.State.SCORING;g.level.tables.get(0).dirty=true;
        int score=g.score;check(g.perform(0)&&g.score==score,"Clearing while the party pays must not award the empty-table dish bonus");
        g.level.tables.get(1).dirty=true;g.perform(1);check(g.score-score==80,"Occupied clearing contributes one shared empty payload identity to the later dish chain");
        g.perform(GameEngine.BUS);g.party(0).state=GameEngine.State.LEAVING;g.level.tables.get(0).dirty=true;score=g.score;g.perform(0);
        check(g.score==score&&g.chainCount()==2,"Clearing another occupied table must not add a second empty identity or extra points");
        g.level.tables.get(2).dirty=true;g.perform(2);check(g.score-score==120,"A genuinely empty dirty table must still earn its normal chained clearing bonus");

        g=new GameEngine(LevelData.get(1),1);check(!g.blocked(17,10)&&!g.blocked(18,10)&&g.blocked(19,10),"The recovered room grid has eighteen columns even when a layout declares sixteen");
        g=new GameEngine(LevelData.get(21),1);check(g.blocked(1,5)&&g.blocked(2,9)&&!g.blocked(2,10),"The seafood restaurant's left strip must stay blocked only through row nine");
        g=new GameEngine(LevelData.get(34),1);check(g.blocked(g.level.barX+2,g.level.barY)&&!g.blocked(g.level.barX,g.level.barY+7),"The bar obstacle must occupy its original three-column, seven-row shape");
        GameEngine.Level bar=LevelData.get(34);bar.arrivals.clear();bar.snacks=new String[0];for(int i=0;i<3;i++)bar.arrivals.add(new GameEngine.Arrival(0,new int[]{0,0},true));
        g=new GameEngine(bar,1);g.paused=false;g.tick(1);g.seatBar(0,4);g.seatBar(1,0);g.seatBar(2,2);g.tick(4000);
        check(g.destination(g.party(0).table)[1]==bar.barY+5,"An even-sized bar party must use the rounded middle stool for its service position");
        g.perform(g.party(0).table);g.perform(g.party(1).table);
        check(g.tableLabel(g.party(0).table).equals("A")&&g.tableLabel(g.party(1).table).equals("B"),"Bar meal letters must follow order-taking order rather than stool location");
        g.perform(GameEngine.KITCHEN);g.tick(5000);g.perform(GameEngine.foodTarget(g.party(0).foodSlot));
        check(g.tableLabel(g.party(0).table).equals("A")&&g.handsText().contains("food TA"),"A bar meal must retain the same label from table to kitchen tray to carried payload and its accessible description");
        g.perform(g.party(0).table);g.perform(g.party(2).table);
        check(g.tableLabel(g.party(2).table).equals("C")&&g.tableLabel(g.party(1).table).equals("B"),"Delivered letters must return behind unused letters without renaming outstanding meals");

        g=ready(2,2);g.level.endless=true;g.nextRandomAt=g.nextRamp=Long.MAX_VALUE;g.goal=100;g.score=99;
        for(int goal:new int[]{100,1000}){GameEngine.Sublevel sub=new GameEngine.Sublevel(goal);sub.groups.add(new GameEngine.GroupChoice("default",1,10000));g.level.sublevels.add(sub);}
        g.party(0).state=GameEngine.State.SCORING;g.party(0).stateDuration=1;g.tick(1);
        check(g.score>100&&g.availableUpgrades==0&&g.sublevel==1,"A tip crossing the Endless goal must wait for the next scored action to award an upgrade");
        g.perform(1);check(g.availableUpgrades==1&&g.sublevel==2&&g.goal==1000,"The next scored service action must check the accumulated score and advance the Endless goal");
        g.score=1000;g.party(1).mood=1;g.party(1).moodAge=g.party(1).profile.mad[GameEngine.State.ORDERED.ordinal()]-1;g.tick(1);
        check(g.score<g.goal&&g.availableUpgrades==0,"A penalty crossing below the current goal must retract one unspent upgrade as in the recovered score-progress handler");
        System.out.println("PASS: "+checks+" mechanics intent checks");
    }
}
