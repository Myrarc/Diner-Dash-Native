package local.dinerdash.prototype;

/** Source-derived contracts expose outstanding port differences; this is not a Windows runtime. */
public final class MechanicsAuditProbe {
    static int differences, matches;
    static void compare(String id,Object expected,Object actual){boolean same=expected.toString().equals(actual.toString());if(same)matches++;else differences++;System.out.println(id+"\t"+expected+"\t"+actual+"\t"+(same?"match":"different"));}
    static GameEngine basic(boolean endless){GameEngine.Level l=new GameEngine.Level(1,100,1000);l.height=16;l.endless=endless;l.drinks=new int[]{13,3};l.tables.add(new GameEngine.Table(5,6,new int[]{-1,-1}));l.tables.add(new GameEngine.Table(12,6,new int[]{-1,-1}));l.tables.add(new GameEngine.Table(10,10,new int[]{-1,-1}));if(endless){GameEngine.Sublevel a=new GameEngine.Sublevel(100),b=new GameEngine.Sublevel(1000);a.groups.add(new GameEngine.GroupChoice("default",1,10000));b.groups.add(new GameEngine.GroupChoice("default",1,10000));l.sublevels.add(a);l.sublevels.add(b);}GameEngine g=new GameEngine(l,1);g.paused=false;g.nextRandomAt=Long.MAX_VALUE;for(int i=0;i<3;i++)g.parties.add(new GameEngine.Party(i,new GameEngine.Arrival(0,new int[]{0,0},false)));return g;}
    static GameEngine.Party seated(GameEngine g,int id,GameEngine.State state){GameEngine.Party p=g.party(id);p.table=id;p.state=state;p.stateDuration=1000;g.level.tables.get(id).party=p;return p;}
    public static void main(String[] args){
        GameEngine g=basic(false);g.capacity=4;seated(g,0,GameEngine.State.ORDERED);g.hands.add(new GameEngine.Item(GameEngine.ItemType.DRINK,-1,3));g.hands.add(new GameEngine.Item(GameEngine.ItemType.BREAD,-1));g.hands.add(new GameEngine.Item(GameEngine.ItemType.FOOD,0));g.hands.add(new GameEngine.Item(GameEngine.ItemType.DISHES,-1));g.perform(GameEngine.BUS);compare("bus_discards_all_supported_payloads",0,g.hands.size());compare("bus_returns_food_for_recooking",5000,g.party(0).cookingUntil);
        g=basic(false);GameEngine.Party p=seated(g,0,GameEngine.State.READY);p.mood=4;g.hands.add(new GameEngine.Item(GameEngine.ItemType.TICKET,1));g.hands.add(new GameEngine.Item(GameEngine.ItemType.DRINK,-1,3));boolean served=g.perform(0);compare("ready_full_hands_coffee",true,served);compare("ready_full_hands_coffee_mood",7,p.mood);
        g=basic(false);seated(g,0,GameEngine.State.SCORING);g.level.tables.get(0).dirty=true;int before=g.score;g.perform(0);compare("occupied_dish_clear_points",0,g.score-before);
        g=basic(false);p=g.party(0);p.mood=1;g.selectedParty=0;g.tick(10000);compare("held_waiting_party_survives",GameEngine.State.WAITING,p.state);
        g=basic(false);g.level.foodPositions=new int[][]{{7,3},{9,3},{11,3}};for(int i=0;i<3;i++){p=seated(g,i,GameEngine.State.ORDERED);p.foodReady=true;p.foodSlot=i;g.foodSlots[i]=i;}GameEngine.Party earlier=new GameEngine.Party(3,new GameEngine.Arrival(0,new int[]{0,0},false)),later=new GameEngine.Party(4,new GameEngine.Arrival(0,new int[]{0,0},false));earlier.state=later.state=GameEngine.State.ORDERED;earlier.cookingUntil=12000;later.cookingUntil=11000;g.parties.add(earlier);g.parties.add(later);g.tick(13000);g.perform(GameEngine.foodTarget(0));g.tick(1);compare("ready_food_completion_fifo",4,g.foodAt(0).id);
        g=basic(true);g.level.rampMS=1000;g.level.decrease=.5;g.level.minMultiplier=.5;g.nextRamp=1000;p=seated(g,0,GameEngine.State.READY);g.tick(5500);compare("seated_patience_frozen_across_ramp",6,p.mood);
        g=basic(true);g.timeMultiplier=.5;g.drinkReady=true;g.perform(GameEngine.DRINKS);compare("coffee_refresh_frozen_at_station_creation",10000,g.drinkReadyAt-g.time);
        g=basic(true);g.score=99;seated(g,0,GameEngine.State.SCORING);g.tick(1000);compare("tip_alone_defers_endless_upgrade",0,g.availableUpgrades);
        g=basic(false);g.seat(0,0);compare("unmatched_quick_seat_mood",6,g.party(0).mood);
        g=new GameEngine(LevelData.get(1),1);compare("original_eighteen_column_grid",false,g.blocked(17,10));g=new GameEngine(LevelData.get(21),1);compare("seafood_left_aisle_blocked",true,g.blocked(1,5));
        g=new GameEngine(LevelData.get(34),1);compare("bar_third_occupied_column",true,g.blocked(g.level.barX+2,g.level.barY));g.paused=false;g.parties.add(new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0,0},true)));g.seatBar(0,0);compare("bar_two_guest_service_midpoint",g.level.barY+1,g.destination(g.party(0).table)[1]);
        compare("tip_formula",120,GameEngine.tip(2,10,10,10));
        g=basic(false);seated(g,0,GameEngine.State.READY);seated(g,1,GameEngine.State.READY);g.perform(0);g.perform(1);compare("two_distinct_order_chain_points",60,g.score);
        g=new GameEngine(LevelData.get(5),1);compare("coffee_unlock_1_5",true,g.level.drinks!=null);compare("goddess_four_hand_capacity",4,new GameEngine(LevelData.get(41),1).capacity);
        for(String d:new String[]{"up","down","left","right"}){g.direction=d;compare("stopped_facing_"+d,"down",g.facing());}
        System.out.println("SUMMARY\t"+differences+" source-contract differences\t"+matches+" controls matched");
    }
}
