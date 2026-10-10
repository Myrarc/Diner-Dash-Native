package local.dinerdash.prototype;

/** Keep an active mood timer stable; difficulty ramps belong to waiting state objects. */
public final class PatienceTest {
    private static int checks;
    private static void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private static void advance(GameEngine g,long ms){for(long t=0;t<ms;t+=100)g.tick(Math.min(100,ms-t));}
    private static GameEngine game(String type,boolean endless){
        GameEngine.Level l=new GameEngine.Level(2,100000,200000);l.height=16;
        l.tables.add(new GameEngine.Table(5,6,new int[]{-1,-1}));
        l.arrivals.add(new GameEngine.Arrival(0,new int[]{0,0},type));
        GameEngine g=new GameEngine(l,1);g.paused=false;g.tick(1);
        g.party(0).age=g.party(0).moodAge=0;
        if(endless){l.endless=true;g.nextRandomAt=Long.MAX_VALUE;g.nextRamp=5001;l.rampMS=5000;l.decrease=.5;l.minMultiplier=.1;}
        return g;
    }
    private static void careerIntervals(){
        String[] types={"default","business_female","old_male","boy"};
        int[] intervals={10000,6000,15000,7000};
        for(int i=0;i<types.length;i++){
            GameEngine g=game(types[i],false);GameEngine.Party p=g.party(0);
            advance(g,intervals[i]-1);check(p.mood==6,types[i]+" must keep six hearts until its authored waiting interval");
            g.tick(1);check(p.mood==5,types[i]+" must lose exactly one heart at the interval boundary");
            advance(g,intervals[i]*5L-1);check(p.mood==1&&g.abandoned==0,types[i]+" must retain its last heart before six full intervals");
            g.tick(1);check(p.mood==0&&g.abandoned==1,types[i]+" must abandon only when its last heart expires");
        }
        GameEngine g=game("default_tutorial",false);advance(g,180000);
        check(g.party(0).mood==6&&g.abandoned==0,"Tutorial arrivals must never lose hearts to an idle patience timer");
        g=game("default",false);g.seat(0,0);int before=g.party(0).mood;
        advance(g,14000);check(g.party(0).state==GameEngine.State.READY&&g.party(0).mood==before,"Choosing menus is a one-shot timer and must not drain hearts");
        advance(g,9999);check(g.party(0).mood==before,"READY must start a fresh ten-second patience interval");
        g.tick(1);check(g.party(0).mood==before-1,"READY must lose its first heart ten seconds after menus close");
    }
    private static void retainedWaitingTimer(){
        GameEngine g=game("default",true);GameEngine.Party p=g.party(0);
        advance(g,5000);check(g.timeMultiplier==.5,"Fixture must ramp Endless difficulty halfway through the waiting interval");
        check(p.mood==6,"A difficulty ramp must not retroactively expire an active waiting timer");
        advance(g,4999);check(p.mood==6,"Existing waiting interval must retain ten seconds after a ramp");
        g.tick(1);check(p.mood==5,"A waiting party must lose its heart at the old interval boundary");
        g.nextRamp=Long.MAX_VALUE;g.seat(0,0);
        check(p.stateDuration==1400,"Waiting state objects must receive ramps for the party's next state timer");
    }
    private static void retainedSeatedTimer(){
        GameEngine g=game("default",true);GameEngine.Party p=g.party(0);
        g.nextRamp=20001;g.seat(0,0);advance(g,14000);int before=p.mood;
        advance(g,6000);check(g.timeMultiplier==.5,"Fixture must ramp during READY");
        check(p.mood==before,"An Endless ramp must not shorten a seated party's active mood interval");
        advance(g,3999);check(p.mood==before,"Seated party must retain its original ten-second interval");
        g.tick(1);check(p.mood==before-1,"Seated heart loss must occur at the retained boundary");
        g.nextRamp=Long.MAX_VALUE;g.perform(0);before=p.mood;
        advance(g,10999);check(p.mood==before,"Seated parties must retain their general multiplier in later ORDERED states");
        g.tick(1);check(p.mood==before-1,"ORDERED must retain the eleven-second source interval");
    }
    private static void retainedHappyThreshold(){
        GameEngine g=game("default",true);GameEngine.Party p=g.party(0);
        g.nextRamp=16001;g.seat(0,0);advance(g,14000);p.mood=3;
        advance(g,3000);g.perform(0);
        check(p.mood==6,"A ramp must not erase the current READY timer's four-second fast-service window");
        g=game("default",true);p=g.party(0);g.nextRamp=Long.MAX_VALUE;g.seat(0,0);advance(g,14000);
        g.availableUpgrades=1;g.applyUpgrade(LevelData.upgrade("stereo",0));int before=p.mood;
        advance(g,9999);check(p.mood==before,"A purchased stereo must not rebuild an existing mood timer");
        g.tick(1);check(p.mood==before-1,"Existing READY timer must expire at ten seconds despite the new stereo");
        g.perform(0);before=p.mood;advance(g,12099);
        check(p.mood==before,"A newly entered ORDERED timer must use the stereo's 1.1 patience multiplier");
        g.tick(2);check(p.mood==before-1,"The upgraded ORDERED interval must expire within one millisecond of 12.1 seconds");
    }
    public static int runChecks(){checks=0;careerIntervals();retainedWaitingTimer();retainedSeatedTimer();retainedHappyThreshold();return checks;}
    public static void main(String[] args){System.out.println("PASS: "+runChecks()+" patience intent checks");}
}
