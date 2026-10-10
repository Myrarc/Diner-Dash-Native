package local.dinerdash.prototype;

import java.util.*;

/** Valid mixed actions must survive the queue, and every furniture route must remain walkable. */
public final class MovementRegressionTest {
    private static int checks,routes;
    private static void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private static void mixedQueue(){
        GameEngine.Level l=LevelData.get(1);l.arrivals.clear();GameEngine g=new GameEngine(l,1);g.paused=false;
        GameEngine.Party p=new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0,0},true));p.table=0;p.state=GameEngine.State.READY;g.parties.add(p);l.tables.get(0).party=p;l.tables.get(1).dirty=true;
        g.queue(0);g.queue(1);g.queue(GameEngine.KITCHEN);boolean continued=false;
        for(int i=0;g.currentTarget!=GameEngine.NO_TARGET&&i<2000;i++){g.tick(25);if(p.state==GameEngine.State.ORDERED&&g.currentTarget==1)continued=true;}
        check(continued,"Taking an order with a free hand must continue to the queued dirty table");
        check(!l.tables.get(1).dirty,"The queued dirty-table visit must collect the dishes");
        check(p.cookingUntil>g.time,"The queued wheel visit must deposit the ticket and start cooking");
        check(g.currentTarget==GameEngine.NO_TARGET&&g.destinations.isEmpty(),"All three successful queued actions must finish without leftover marks");
        check(g.hands.size()==1&&g.hands.get(0).type==GameEngine.ItemType.DISHES,"Wheel deposit must retain the collected dishes for the cart");
    }
    private static void routes(){
        for(int setting=1;setting<=65;setting++){
            GameEngine.Level l=setting<=50?LevelData.get(setting):LevelData.endless((setting-51)/3+1,(setting-51)%3+1);l.arrivals.clear();
            GameEngine g=new GameEngine(l,1);g.paused=false;g.nextRandomAt=g.nextRamp=Long.MAX_VALUE;
            if(l.endless){g.availableUpgrades=2;g.applyUpgrade(LevelData.upgrade("drinks",0));g.applyUpgrade(LevelData.upgrade("podium",0));for(GameEngine.Table t:l.tableUpgrades)l.tables.add(new GameEngine.Table(t.x,t.y,t.colors));}
            g.parties.add(new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0},true))); // Keep an otherwise empty career shift open.
            List<Integer> targets=new ArrayList<>(Arrays.asList(GameEngine.KITCHEN,GameEngine.BUS));if(l.drinks!=null)targets.add(GameEngine.DRINKS);if(l.podium!=null)targets.add(GameEngine.PODIUM);
            for(int i=0;i<l.snacks.length;i++)targets.add(i==0?GameEngine.SNACK1:GameEngine.SNACK2);for(int i=0;i<g.foodSlots.length;i++)targets.add(GameEngine.foodTarget(i));for(int i=0;i<l.tables.size();i++)targets.add(i);
            for(int from:targets)for(int to:targets){int[] a=g.destination(from),b=g.destination(to);if(g.blocked(a[0],a[1]))continue;g.floX=a[0];g.floY=a[1];g.queue(to);check(g.currentTarget==to,"Destination must be reachable: map "+setting+", "+from+" -> "+to);boolean clipped=false;
                for(int i=0;g.currentTarget!=GameEngine.NO_TARGET&&i<3000;i++){g.tick(25);clipped|=g.blocked(g.floX,g.floY);}
                check(!clipped,"Furniture must remain impassable on map "+setting+", "+from+" -> "+to);
                check(g.currentTarget==GameEngine.NO_TARGET&&(g.floX==b[0]&&g.floY==b[1]||g.blocked(b[0],b[1])&&Math.abs(g.floX-b[0])+Math.abs(g.floY-b[1])<=1),"Flo must complete the route at the station/service tile on map "+setting+", "+from+" -> "+to);routes++;
            }
        }
    }
    public static void main(String[] args){mixedQueue();routes();System.out.println("PASS: "+checks+" movement/queue intent checks; "+routes+" routes across all 65 maps including purchased Endless stations/tables");}
}
