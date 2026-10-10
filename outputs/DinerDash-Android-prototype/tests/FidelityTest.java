package local.dinerdash.prototype;

/** Original independent station actions must not silently combine ticket and food pickup. */
public final class FidelityTest {
    private static int checks;
    private static void check(boolean ok,String intent){checks++;if(!ok)throw new AssertionError(intent);}
    public static void main(String[] args){
        for(int n=1;n<=4;n++)check(LevelData.get(n).drinks==null,"Coffee must be absent before career shift 1-5, rather than drawn but disabled");
        check(LevelData.get(5).drinks!=null,"Career shift 1-5 introduces the coffee machine");
        GameEngine g=new GameEngine(LevelData.get(1),1);g.paused=false;g.tick(25000);g.seat(0,0);g.seat(1,1);g.tick(4000);g.perform(0);g.perform(1);g.perform(GameEngine.KITCHEN);
        check(g.ticketTurnAt==g.time,"Ticket deposit starts the visible order wheel's turn animation");
        g.tick(5000);check(g.readyFoodCount()==2,"Each cooked order must occupy its own ready-food slot");
        check(!g.perform(GameEngine.KITCHEN)&&g.hands.isEmpty(),"Clicking the order wheel cannot collect meals from other station hit regions");
        GameEngine.Party tray=g.foodAt(1);check(g.perform(GameEngine.foodTarget(1)),"Clicking the second tray picks that specific meal");
        check(g.hands.size()==1&&g.hands.get(0).party==tray.id&&g.foodAt(0)!=null&&g.foodAt(1)==null,"Picking a tray must leave other ready meals untouched");
        g=new GameEngine(LevelData.get(5),1);g.paused=false;g.tick(1);check(!g.drinkReady&&!g.perform(GameEngine.DRINKS),"Preparing coffee is visible but cannot be picked prematurely");g.tick(9999);check(g.drinkReady&&g.perform(GameEngine.DRINKS),"Ready coffee can be picked from its own station");check(!g.drinkReady,"Pickup removes the ready coffee sprite and starts a fresh timer");g.tick(9999);check(!g.drinkReady,"The coffee machine must stay preparing for the entire refresh interval");g.tick(1);check(g.drinkReady,"The coffee machine becomes clickable again when its refresh completes");
        GameEngine.Level l=new GameEngine.Level(1,1,1);l.tables.add(new GameEngine.Table(6,6,new int[]{0,1}));l.arrivals.add(new GameEngine.Arrival(0,new int[]{0,1,2},true));g=new GameEngine(l,1);g.paused=false;g.tick(1);check(!g.canSeat(0,0)&&!g.seat(0,0),"A drag onto a too-small table must return the whole party to the waiting queue");check(g.waiting().size()==1&&l.tables.get(0).party==null,"A rejected drag preview must not mutate table occupancy");
        g=new GameEngine(LevelData.get(1),1);g.paused=false;g.tick(1);g.queue(0);check(g.facing().equals("right"),"Walking must face the next tile immediately, rather than the previous tile");g.cancelQueue();g.tick(10000);for(String approach:new String[]{"up","down","left","right"}){g.direction=approach;check(g.facing().equals("down"),"A stopped waiter faces the player after any approach: "+approach);}
        g=new GameEngine(LevelData.get(2),1);check(g.blocked(14,5)&&!g.blocked(11,5),"Table 2's right chair occupies column 14; the clear aisle at column 11 must not be mistaken for furniture");
        int routes=0;
        for(int n=1;n<=50;n++)for(int table=0;table<LevelData.get(n).tables.size();table++){
            g=new GameEngine(LevelData.get(n),1);g.paused=false;int[] start=g.destination(table);g.floX=start[0];g.floY=start[1];g.queue(GameEngine.KITCHEN);boolean clipped=false;int steps=0;
            while(g.currentTarget!=GameEngine.NO_TARGET&&steps++<1000){g.tick(25);for(GameEngine.Table t:g.level.tables)if(t.barStart<0&&g.drawX()>=t.x&&g.drawX()<=t.x+2&&g.drawY()>=t.y-1&&g.drawY()<=t.y-2+t.colors.length/2)clipped=true;}
            check(!clipped&&g.floX==g.level.kitchen[0]&&g.floY==g.level.kitchen[1],"Flo must reach the order wheel without crossing a chair or tabletop: shift "+n+", table "+(table+1));routes++;
        }
        g=new GameEngine(LevelData.get(5),1);g.paused=false;g.tick(10000);int tid=0;while(g.level.tables.get(tid).colors.length<g.party(0).colors.length)tid++;g.seat(0,tid);int before=g.party(0).mood;g.perform(GameEngine.DRINKS);g.perform(tid);check(g.party(0).mood>before&&g.party(0).moodChangedAt==g.time&&g.party(0).moodBefore==before,"A service mood increase must notify the seated actor so its happy reaction is visible");
        System.out.println("PASS: "+checks+" original-interaction intent checks; "+routes+" table-to-wheel routes checked for furniture clipping");
    }
}
