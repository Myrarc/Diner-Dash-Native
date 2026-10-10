package local.dinerdash.prototype;

import java.util.*;

/** Native port of the recovered service states and active configuration. */
public final class GameEngine {
    public static final int KITCHEN=-1, BUS=-2, DRINKS=-3, PODIUM=-4, SNACK1=-5, SNACK2=-6, FOOD1=-10, NO_TARGET=-99;
    private static final int GRID_WIDTH=18;
    public enum State { WAITING, DECIDING, READY, ORDERED, EATING, CHECK, SCORING, LEAVING, DITCHING, SNACK, GONE }
    public enum ItemType { TICKET, FOOD, DISHES, CHECK, DRINK, SOMOSA, PAPADOM, BREAD, CRAB }
    public static final class Profile {
        public final String id, graphic;
        public final int baseTip,moodTip,penalty,timeMood,colorMood,heartsRequired;
        public final int[] duration,happy,mad,minimum;
        Profile(String id,String graphic,int base,int mood,int penalty,int tm,int cm,int hr,int[] d,int[] h,int[] m,int[] min) {
            this.id=id;this.graphic=graphic;baseTip=base;moodTip=mood;this.penalty=penalty;timeMood=tm;colorMood=cm;heartsRequired=hr;
            duration=d;happy=h;mad=m;minimum=min;
        }
    }
    public static final class Level {
        public final int number,goal,expert;
        public int stage=1,width=16,height=13,difficulty=1,stars=3,barX,barY,snackPercent;
        public String name="Flo's Diner",stageId="diner",bgState="state_1",intro="",succeed="",fail="";
        public int[] kitchen={5,3},bus={15,3},drinks, podium,barColors;
        public int[] drinkPosition={14,3},podiumPosition={1,11};
        public int[][] foodPositions={{7,3},{9,3},{11,3}},snackPositions={{16,6},{16,9}};
        public String[] snacks={};
        public long podiumCharge=6000,podiumActive=2000,podiumDelay=8000,rampMS=5500;
        public int podiumMood=3;
        public boolean endless;
        public double startMultiplier=1,minMultiplier=.1,decrease=.0015;
        public final List<Table> tables=new ArrayList<>(),tableUpgrades=new ArrayList<>();
        public final List<Arrival> arrivals=new ArrayList<>();
        public final List<Sublevel> sublevels=new ArrayList<>();
        public Level(int n,int g,int e) { number=n;goal=g;expert=e; }
    }
    public static final class Arrival {
        public final long time;
        public final int[] colors;
        public final boolean tutorial;
        public final Profile profile;
        public Arrival(long t,int[] c,boolean tutorial) { this(t,c,tutorial?"default_tutorial":"default"); }
        public Arrival(long t,int[] c,String type) { time=t;colors=c;profile=LevelData.profile(type);tutorial=type.equals("default_tutorial"); }
    }
    public static final class Table {
        public final int x,y;
        public final int[] colors,multipliers;
        public Party party;
        public boolean dirty,active=true;
        public int barStart=-1;
        public String orderLabel;
        public Table(int x,int y,int[] c) { this.x=x;this.y=y;colors=c.clone();multipliers=new int[c.length];Arrays.fill(multipliers,1); }
    }
    public static final class Party {
        public final int id;
        public final int[] colors;
        public final Profile profile;
        public final boolean tutorial;
        public State state=State.WAITING,previous;
        public int mood=6,moodBefore=6,table=-1,chairOffset,foodSlot=-1;
        public long age,moodAge,cookingUntil,cookingOrder,stateDuration,snackAt=-1,resumeDuration,waitingSince,drinkUntil,moodChangedAt=-1;
        public String wantedSnack;
        public boolean foodReady,foodPickedUp;
        public double timeMultiplier=1,happyInterval,madInterval;
        Party(int id,Arrival a) { this.id=id;colors=a.colors.clone();profile=a.profile;tutorial=a.tutorial;happyInterval=Math.max(profile.minimum[0],profile.happy[0]);madInterval=Math.max(profile.minimum[0],profile.mad[0]); }
    }
    public static final class Item {
        public final ItemType type;public final int party;public final int mood;
        Item(ItemType t,int p) { this(t,p,0); } Item(ItemType t,int p,int m) { type=t;party=p;mood=m; }
    }
    public static final class Popup { public final int table,amount; public long remaining=1500; Popup(int t,int a){table=t;amount=a;} }
    public static final class GroupChoice { public final String type;public final int weight,delay; GroupChoice(String t,int w,int d){type=t;weight=w;delay=d;} }
    public static final class Sublevel { public final int goal;public int[] colors={0,1,2,3,4};public final List<GroupChoice> groups=new ArrayList<>(); Sublevel(int g){goal=g;} }
    public static final class Upgrade { public final String type,name,description;public final double[] values;Upgrade(String t,String n,String d,double[] v){type=t;name=n;description=d;values=v;} }

    public final Level level;
    public final List<Party> parties=new ArrayList<>();
    public final List<Item> hands=new ArrayList<>();
    public final int[] foodSlots;
    public final ArrayDeque<Integer> destinations=new ArrayDeque<>();
    public final List<Popup> popups=new ArrayList<>();
    public final ArrayDeque<String> sounds=new ArrayDeque<>();
    public final Map<String,Integer> upgrades=new HashMap<>();
    public long lastActivityAt,ticketTurnAt=-10000;
    public int walkStep;
    public long time,closingAt=-1,drinkReadyAt, nextRandomAt, nextRamp, podiumUntil, podiumChargingAt=-1;
    public int nextArrival,score,served,abandoned,selectedParty=-1,heldParty=-1,currentTarget=NO_TARGET,floX=5,floY=3,stars,totalStars=3;
    public int goal,sublevel=1,availableUpgrades,tableUpgrade,rotation,capacity=2;
    public boolean paused=true,ended,won,drinkReady,atPodium;
    public String message="Tap a waiting party, then a clean table.",direction="down";
    public double timeMultiplier=1,waitingPatience=1,seatedPatience=1;
    public long speed=100,cookMS=5000,drinkMS=10000;
    public int drinkMood=3;
    private final ArrayList<int[]> path=new ArrayList<>();
    private final ArrayDeque<Integer> readyFood=new ArrayDeque<>();
    private final ArrayDeque<Integer> emptyFoodSpots=new ArrayDeque<>();
    private final ArrayDeque<String> barLetters=new ArrayDeque<>();
    private final Random random;
    private int pathIndex,partySequence;
    private long movement;
    private long cookingSequence;
    public int busFull;
    private int busDrops;
    private long busResetAt=-1;
    private ItemType chainType;
    private final Set<Integer> chain=new HashSet<>();
    private int[] barMultipliers;

    public GameEngine(Level l) { this(l, System.nanoTime()); }
    public GameEngine(Level l,long seed) {
        level=l;foodSlots=new int[l.foodPositions.length];Arrays.fill(foodSlots,-1);for(int slot=0;slot<foodSlots.length;slot++)emptyFoodSpots.add(slot);random=new Random(seed);goal=l.goal;stars=l.stars;totalStars=stars;capacity=l.stage==5?4:2;
        floX=l.kitchen[0];floY=l.kitchen[1];
        if (l.barColors!=null) { barMultipliers=new int[l.barColors.length];Arrays.fill(barMultipliers,1);for(char letter='A';letter<='H';letter++)barLetters.add(String.valueOf(letter)); }
        if (l.endless) { timeMultiplier=l.startMultiplier;goal=l.sublevels.get(0).goal;nextRandomAt=0;nextRamp=l.rampMS; }
        drinkReadyAt=(long)(drinkMS*timeMultiplier);
    }
    public Party party(int id) { for(Party p:parties)if(p.id==id)return p;return null; }
    public List<Party> waiting() { List<Party> r=new ArrayList<>();for(Party p:parties)if(p.state==State.WAITING)r.add(p);return r; }
    public static int foodTarget(int slot){return FOOD1-slot;}
    public Party foodAt(int slot){return slot>=0&&slot<foodSlots.length?party(foodSlots[slot]):null;}
    public int firstReadyFoodTarget(){for(int i=0;i<foodSlots.length;i++)if(foodSlots[i]>=0)return foodTarget(i);return NO_TARGET;}
    public boolean canSeat(int id,int tid){Party p=party(id);if(p==null||p.state!=State.WAITING||tid<0||tid>=level.tables.size())return false;Table t=level.tables.get(tid);return t.active&&t.party==null&&!t.dirty&&p.colors.length<=t.colors.length;}
    public boolean canSeatBar(int id,int start){Party p=party(id);if(p==null||p.state!=State.WAITING||level.barColors==null||start<0||start+p.colors.length>level.barColors.length)return false;for(int i=start;i<start+p.colors.length;i++)if(barTableAt(i)>=0)return false;return true;}
    public int readyFoodCount(){int n=0;for(Party p:parties)if(p.foodReady)n++;return n;}
    public int chainCount(){return chain.size();}
    public boolean moving(){return currentTarget!=NO_TARGET&&pathIndex<path.size();}
    public String facing(){if(moving()){int[] tile=path.get(pathIndex);return tile[0]<floX?"left":tile[0]>floX?"right":tile[1]<floY?"up":"down";}return "down";}
    public long stepTime(){return movement;}
    public float drawX(){return pathIndex>=path.size()?floX:floX+(path.get(pathIndex)[0]-floX)*movement/(float)speed;}
    public float drawY(){return pathIndex>=path.size()?floY:floY+(path.get(pathIndex)[1]-floY)*movement/(float)speed;}
    public void select(int id){Party p=party(id);if(p!=null&&p.state==State.WAITING){selectedParty=selectedParty==id?-1:id;rotation=0;message="Tap a clean table. Tap a chair to align the colors.";}}
    public void rotate(){if(selectedParty>=0){Party p=party(selectedParty);rotation=(rotation+1)%p.colors.length;message="Party rotated. Choose a chair to place the first guest.";}else cancelQueue();}
    public boolean seat(int id,int table){return seat(id,table,0);}
    public boolean seat(int id,int tid,int offset){
        if(paused||ended||tid<0||tid>=level.tables.size())return false;
        Party p=party(id);Table t=level.tables.get(tid);
        if(p==null||p.state!=State.WAITING)return false;
        if(!t.active||t.party!=null||t.dirty||p.colors.length>t.colors.length){message="Choose a clean table with enough chairs.";return false;}
        fastService(p);p.chairOffset=((offset%t.colors.length)+t.colors.length)%t.colors.length;
        int matches=0;
        for(int i=0;i<p.colors.length;i++){
            int ci=(p.chairOffset+i)%t.colors.length,color=p.colors[(i+rotation)%p.colors.length];
            if(color==t.colors[ci])matches++;
            if(color<0||t.colors[ci]==-2)continue;
            if(color!=t.colors[ci]){t.colors[ci]=color;t.multipliers[ci]=1;}
            else {addScore(100*t.multipliers[ci],tid);t.multipliers[ci]=Math.min(4,t.multipliers[ci]+1);}
        }
        if(rotation>0){int[] copy=p.colors.clone();for(int i=0;i<copy.length;i++)p.colors[i]=copy[(i+rotation)%copy.length];}
        mood(p,matches*p.profile.colorMood);p.table=tid;t.party=p;setState(p,State.DECIDING);selectedParty=-1;if(heldParty==id)heldParty=-1;rotation=0;
        sound("sfx_seat_people_snd");message="Guests seated. Wait for their order.";return true;
    }
    public boolean seatBar(int id,int start){
        Party p=party(id);if(p==null||level.barColors==null)return false;
        int count=p.colors.length;start=Math.max(0,Math.min(start,level.barColors.length-count));
        if(count>level.barColors.length)return false;
        for(int i=start;i<start+count;i++)if(barTableAt(i)>=0){message="The party needs adjacent clean stools.";return false;}
        Table t=new Table(level.barX+1,level.barY+start,Arrays.copyOfRange(level.barColors,start,start+count));t.barStart=start;
        System.arraycopy(barMultipliers,start,t.multipliers,0,count);
        int tid=-1;for(int i=0;i<level.tables.size();i++)if(!level.tables.get(i).active){tid=i;break;}
        if(tid<0){tid=level.tables.size();level.tables.add(t);}else level.tables.set(tid,t);
        boolean success=seat(id,tid,0);if(!success)t.active=false;else syncBar(t);return success;
    }
    public int barTableAt(int slot){for(int i=0;i<level.tables.size();i++){Table t=level.tables.get(i);if(t.active&&t.barStart>=0&&slot>=t.barStart&&slot<t.barStart+t.colors.length)return i;}return -1;}
    public int barMultiplier(int slot){return barMultipliers[slot];}
    public String tableLabel(int id){Table t=level.tables.get(id);return t.barStart<0?String.valueOf(id+1):t.orderLabel!=null?t.orderLabel:String.valueOf(101+t.barStart);}
    private void syncBar(Table t){if(t.barStart>=0){System.arraycopy(t.colors,0,level.barColors,t.barStart,t.colors.length);System.arraycopy(t.multipliers,0,barMultipliers,t.barStart,t.colors.length);}}
    public void queue(int target){
        if(paused||ended||target==NO_TARGET||target>=level.tables.size()||target<SNACK2&&(target>FOOD1||target<=FOOD1-foodSlots.length))return;
        if(target==DRINKS&&level.drinks==null||target==PODIUM&&level.podium==null||target==SNACK1&&level.snacks.length<1||target==SNACK2&&level.snacks.length<2)return;
        if(destinations.size()>=5){message="Five actions queued. Let Flo catch up.";return;}
        atPodium=false;podiumChargingAt=-1;destinations.add(target);if(currentTarget==NO_TARGET)nextDestination();
    }
    public void cancelQueue(){destinations.clear();selectedParty=-1;message="Pending actions cleared.";}
    public void tick(long delta){
        if(paused||ended||delta<=0)return;time+=delta;
        if(level.endless){
            while(time>=nextRamp){timeMultiplier=Math.max(level.minMultiplier,timeMultiplier-level.decrease);nextRamp+=level.rampMS;
                // Original ramps update queued groups' state objects, never active timers or seated groups.
                for(Party p:parties)if(p.state==State.WAITING)p.timeMultiplier=timeMultiplier;
            }
            if(time>=nextRandomAt){Arrival a=randomArrival();addParty(a);nextRandomAt=time+Math.max(1,a.time);}
        }else while(nextArrival<level.arrivals.size()&&level.arrivals.get(nextArrival).time<=time)addParty(level.arrivals.get(nextArrival++));
        if(level.drinks!=null&&!drinkReady&&time>=drinkReadyAt)drinkReady=true;
        if(busResetAt>=0&&time>=busResetAt){busResetAt=-1;updateBusFull();}
        if(atPodium&&level.podium!=null){
            if(time>=podiumUntil){if(podiumChargingAt<0)podiumChargingAt=time;if(time-podiumChargingAt>=level.podiumCharge){for(Party p:waiting())mood(p,level.podiumMood);podiumUntil=time+level.podiumActive+level.podiumDelay;podiumChargingAt=-1;sound("sfx_gain_heart_1");message="Podium: waiting guests gained hearts.";}}
        }
        List<Party> completed=new ArrayList<>();
        for(Party p:parties)if(p.cookingUntil>0&&time>=p.cookingUntil)completed.add(p);
        Collections.sort(completed,(a,b)->{int cmp=Long.compare(a.cookingUntil,b.cookingUntil);return cmp!=0?cmp:Long.compare(a.cookingOrder,b.cookingOrder);});
        for(Party p:completed){p.cookingUntil=0;readyFood.add(p.id);}
        while(!readyFood.isEmpty()&&!emptyFoodSpots.isEmpty()){int slot=emptyFoodSpots.remove();if(foodSlots[slot]<0)fillFoodSpot(slot);}
        int waitingIndex=0;
        for(Party p:parties){
            if(p.state==State.GONE)continue;
            boolean hidden=p.state==State.WAITING&&waitingIndex++>=8;
            if(hidden)continue;
            p.age+=delta;
            switch(p.state){
            case DECIDING:case EATING:
                if(p.snackAt>=0&&p.age>=p.snackAt){p.previous=p.state;p.resumeDuration=Math.max(p.profile.minimum[p.state.ordinal()],p.stateDuration-p.snackAt);p.wantedSnack=level.snacks[random.nextInt(level.snacks.length)];setState(p,State.SNACK);}
                else if(p.age>=p.stateDuration){setState(p,p.state==State.DECIDING?State.READY:State.CHECK);if(p.state==State.CHECK)sound("sfx_done_eating_1_snd");}break;
            case SCORING:
                if(p.age>=p.stateDuration){int amount=tip(p.colors.length,p.mood,p.profile.baseTip,p.profile.moodTip);score+=amount;popups.add(new Popup(p.table,amount));served++;if(p.profile.id.equals("critic")&&p.mood>=p.profile.heartsRequired){totalStars=Math.min(5,totalStars+1);stars=totalStars;sound("sfx_gain_heart_1");}setState(p,State.LEAVING);}break;
            case LEAVING:case DITCHING:
                if(p.age>=1500){Table t=level.tables.get(p.table);t.party=null;setState(p,State.GONE);if(t.barStart>=0&&!t.dirty){syncBar(t);t.active=false;}}break;
            case WAITING:case READY:case ORDERED:case CHECK:case SNACK:
                if(!p.tutorial){p.moodAge+=delta;if(p.moodAge>=p.madInterval){mood(p,-1);if(p.mood==0)abandon(p);else if(p.state==State.SNACK)resumeSnack(p,false);}}break;
            default:break;
            }
        }
        if(currentTarget!=NO_TARGET){
            movement+=delta;
            while(movement>=speed&&pathIndex<path.size()){movement-=speed;walkStep++;lastActivityAt=time;int[] tile=path.get(pathIndex++);direction=tile[0]<floX?"left":tile[0]>floX?"right":tile[1]<floY?"up":"down";floX=tile[0];floY=tile[1];}
            if(pathIndex==path.size()){boolean ok=perform(currentTarget);currentTarget=NO_TARGET;path.clear();pathIndex=0;movement=0;if(!ok)destinations.clear();nextDestination();}
        }
        for(Iterator<Popup> i=popups.iterator();i.hasNext();){Popup p=i.next();p.remaining-=delta;if(p.remaining<=0)i.remove();}
        checkClosing();
    }
    private void addParty(Arrival a){Party p=new Party(partySequence++,a);p.timeMultiplier=timeMultiplier;p.waitingSince=time;setState(p,State.WAITING);parties.add(p);sound("sfx_party_arrive_1_snd");}
    private Arrival randomArrival(){
        Sublevel s=level.sublevels.get(Math.min(sublevel,level.sublevels.size())-1);int total=0;for(GroupChoice g:s.groups)total+=g.weight;
        int choice=random.nextInt(Math.max(1,total));GroupChoice chosen=s.groups.get(0);
        for(GroupChoice g:s.groups){choice-=g.weight;if(choice<0){chosen=g;break;}}
        int size=random.nextBoolean()?2:3+random.nextInt(2);int[] colors=new int[size];Profile p=LevelData.profile(chosen.type);
        for(int i=0;i<size;i++)colors[i]=p.graphic.equals("critic")?-1:s.colors[random.nextInt(s.colors.length)];
        return new Arrival(chosen.delay,colors,chosen.type);
    }
    private double interval(Party p,long base){double patience=p.state==State.WAITING?waitingPatience:(p.state==State.READY||p.state==State.ORDERED||p.state==State.CHECK||p.state==State.SNACK?seatedPatience:1);return Math.max(p.profile.minimum[p.state.ordinal()],base*p.timeMultiplier*patience);}
    private long timer(Party p,long base){return (long)Math.ceil(interval(p,base));}
    private void setState(Party p,State state){
        if(p.table>=0){Table t=level.tables.get(p.table);if(t.barStart>=0){if(p.state==State.ORDERED&&state!=State.ORDERED&&t.orderLabel!=null){barLetters.add(t.orderLabel);t.orderLabel=null;}if(state==State.ORDERED&&t.orderLabel==null)t.orderLabel=barLetters.remove();}}
        p.state=state;p.age=0;p.moodAge=0;p.snackAt=-1;if(state==State.LEAVING||state==State.DITCHING||state==State.GONE)killFood(p);if(state==State.GONE)return;p.stateDuration=timer(p,p.profile.duration[state.ordinal()]);
        // State entry starts mood_timer with fixed happy/mad thresholds; mood changes only reset elapsed time.
        p.happyInterval=interval(p,p.profile.happy[state.ordinal()]);p.madInterval=interval(p,p.profile.mad[state.ordinal()]);
        if(state==State.SCORING)p.stateDuration=timer(p,Math.max(1000,p.profile.duration[state.ordinal()]));
        if(state==State.EATING){level.tables.get(p.table).dirty=true;}
        if((state==State.DECIDING||state==State.EATING)&&level.snacks.length>0&&p.stateDuration>=2000&&random.nextInt(100)+1<level.snackPercent){int raw=p.profile.duration[state.ordinal()];p.snackAt=2000+random.nextInt(Math.max(1,raw-2000))+1;}
    }
    private void resumeSnack(Party p,boolean fast){if(fast)fastService(p);State resume=p.previous;long remaining=p.resumeDuration;p.wantedSnack=null;setState(p,resume);p.snackAt=-1;p.stateDuration=remaining;}
    private void mood(Party p,int d){int before=p.mood;p.mood=Math.max(p.id==heldParty&&p.state==State.WAITING?1:0,Math.min(10,p.mood+d));p.moodAge=0;if(p.mood!=before){p.moodBefore=before;p.moodChangedAt=time;}}
    private void fastService(Party p){if(!p.tutorial&&p.age<p.happyInterval)mood(p,p.profile.timeMood);}
    private void abandon(Party p){
        abandoned++;addScore(-p.profile.penalty,p.table);killFood(p);
        for(Iterator<Item> i=hands.iterator();i.hasNext();)if(i.next().party==p.id)i.remove();
        if(p.table>=0)setState(p,State.DITCHING);else setState(p,State.GONE);
        if(selectedParty==p.id)selectedParty=-1;
        if(heldParty==p.id)heldParty=-1;
        if(level.endless&&--stars<=0){ended=true;won=false;}
        sound("sfx_lose_heart_1");message="A party left angry: "+p.profile.penalty+" point penalty.";
    }
    public static int tip(int size,int mood,int base,int bonus){return size*base+mood*bonus;}
    private void addScore(int amount,int table){int oldscore=score;score=Math.max(0,score+amount);if(table>=0&&amount!=0)popups.add(new Popup(table,amount));
        if(level.endless&&score<goal&&oldscore>=goal)availableUpgrades=Math.max(0,availableUpgrades-1);
        if(level.endless&&score>goal){availableUpgrades++;sublevel++;if(sublevel<=level.sublevels.size())goal=level.sublevels.get(sublevel-1).goal;else {int last=level.sublevels.size()-1;goal=level.sublevels.get(last).goal+(sublevel-level.sublevels.size())*(level.sublevels.get(last).goal-level.sublevels.get(last-1).goal);}}
    }
    private void chainMode(ItemType t){if(chainType!=t){chain.clear();chainType=t;}}
    private void actionScore(ItemType t,int table,int base){chainMode(t);chain.add(table);addScore(base*Math.max(1,chain.size()),table);}
    private Item item(ItemType type,int party){for(Item i:hands)if(i.type==type&&(party<0||i.party==party))return i;return null;}
    private boolean pickup(ItemType type,int party,int mood){if(hands.size()>=capacity)return fullHands();chainMode(type);hands.add(new Item(type,party,mood));return true;}
    private boolean fullHands(){message="Hands full ("+capacity+" items). Visit Kitchen or Dishes.";return false;}
    private void startCooking(Party p){if(p.cookingUntil>0)return;p.cookingUntil=time+(long)(cookMS*timeMultiplier);p.cookingOrder=cookingSequence++;p.foodPickedUp=false;}
    private void fillFoodSpot(int slot){if(readyFood.isEmpty())return;Party p=party(readyFood.remove());p.foodReady=true;p.foodSlot=slot;foodSlots[slot]=p.id;sound("sfx_food_ready_1_snd");}
    private void emptyFoodSpot(int slot){foodSlots[slot]=-1;if(readyFood.isEmpty())emptyFoodSpots.add(slot);else fillFoodSpot(slot);}
    private void killFood(Party p){readyFood.remove(p.id);p.cookingUntil=0;p.foodReady=false;p.foodPickedUp=false;if(p.foodSlot>=0){int slot=p.foodSlot;p.foodSlot=-1;emptyFoodSpot(slot);}}
    private boolean serveDrink(Party p){Item drink=item(ItemType.DRINK,-1);if(drink==null)return false;hands.remove(drink);chainMode(ItemType.DRINK);mood(p,drink.mood);p.drinkUntil=time+1000;sound("sfx_dropoff_drinks_1_snd");message="Drink served: +"+drink.mood+" hearts.";return true;}
    boolean perform(int target){
        lastActivityAt=time;
        if(target==KITCHEN)return kitchen();
        if(target<=FOOD1&&target>FOOD1-foodSlots.length){int slot=FOOD1-target;Party p=foodAt(slot);if(p==null||!p.foodReady)return false;if(!pickup(ItemType.FOOD,p.id,0))return false;p.foodReady=false;p.foodPickedUp=true;p.foodSlot=-1;emptyFoodSpot(slot);sound("sfx_pickup_food_1_snd");message="Food collected for table "+tableLabel(p.table)+".";return true;}
        if(target==BUS){boolean done=false;for(Iterator<Item> i=hands.iterator();i.hasNext();){Item it=i.next();if(it.type==ItemType.TICKET||it.type==ItemType.CHECK)continue;if(it.type==ItemType.FOOD){Party p=party(it.party);if(p!=null){p.foodPickedUp=false;p.foodReady=false;if(p.table>=0&&level.tables.get(p.table).party==p)startCooking(p);}}i.remove();done=true;}if(done){busDrops++;updateBusFull();sound("sfx_dish_dropoff_1_snd");}message=done?"Items dropped off. Returned food will be cooked again.":"Nothing to drop off.";return done;}
        if(target==DRINKS){if(!drinkReady){message="Drinks are still preparing.";return false;}if(!pickup(ItemType.DRINK,-1,drinkMood))return false;drinkReady=false;drinkReadyAt=time+(long)(drinkMS*timeMultiplier);sound("sfx_get_drinks_2_snd");message="Drink collected. Tap a seated party for a mood boost.";return true;}
        if(target==PODIUM){atPodium=true;chain.clear();chainType=null;podiumChargingAt=-1;message="Flo is chatting at the podium. Stay to charge hearts.";return true;}
        if(target==SNACK1||target==SNACK2){String snack=level.snacks[target==SNACK1?0:1];boolean ok=pickup(ItemType.valueOf(snack.toUpperCase(Locale.ROOT)),-1,0);if(ok)message="Deliver "+snack+" to the party asking for it.";return ok;}
        if(target<0||target>=level.tables.size())return false;Table t=level.tables.get(target);if(!t.active)return false;Party p=t.party;
        if(t.dirty&&(p==null||p.state==State.SCORING||p.state==State.LEAVING||p.state==State.DITCHING)){
            if(!pickup(ItemType.DISHES,-1,0))return false;t.dirty=false;if(p==null)actionScore(ItemType.DISHES,target,40);else chain.add(-1);if(t.barStart>=0&&p==null){syncBar(t);t.active=false;}sound("sfx_clear_dishes_1_snd");message="Dishes collected. Drop them off at Dishes.";return true;
        }
        if(p==null){message="Seat a party here first.";return false;}
        if(p.state==State.READY){if(!pickup(ItemType.TICKET,p.id,0))return serveDrink(p);actionScore(ItemType.TICKET,target,20);fastService(p);setState(p,State.ORDERED);sound("sfx_pencil_write_2");message="Order taken. Visit Kitchen to start cooking.";return true;}
        if(p.state==State.ORDERED){Item food=item(ItemType.FOOD,p.id);if(food!=null){hands.remove(food);actionScore(ItemType.FOOD,target,30);fastService(p);setState(p,State.EATING);sound("sfx_deliver_food_1_snd");message="Food served.";return true;}}
        if(p.state==State.CHECK){if(hands.size()>=capacity)return fullHands();actionScore(ItemType.CHECK,target,50);fastService(p);setState(p,State.SCORING);sound("sfx_bring_check_1_snd");message="Bill delivered. Clear the dishes.";return true;}
        if(p.state==State.SNACK){Item snack=item(ItemType.valueOf(p.wantedSnack.toUpperCase(Locale.ROOT)),-1);if(snack!=null){hands.remove(snack);chainMode(snack.type);int pts=snack.type==ItemType.CRAB?75:snack.type==ItemType.BREAD?100:150;addScore(pts,target);resumeSnack(p,true);sound("sfx_deliver_food_2_snd");message="Snack served.";return true;}}
        if(p.state==State.DECIDING||p.state==State.EATING||p.state==State.ORDERED||p.state==State.SNACK){if(serveDrink(p))return true;}
        message=p.state==State.ORDERED?"Bring this table's food or a drink.":p.state==State.SNACK?"This party wants "+p.wantedSnack+".":"The party is still choosing, eating, or leaving.";return false;
    }
    private void updateBusFull(){busFull=Math.min(2,busDrops);if(busDrops>=2){busDrops=0;busResetAt=time+1500;}}
    private boolean kitchen(){
        boolean done=false;for(Iterator<Item> i=hands.iterator();i.hasNext();){Item it=i.next();if(it.type==ItemType.TICKET){Party p=party(it.party);if(p!=null&&p.state==State.ORDERED)startCooking(p);i.remove();done=true;}}
        if(done){ticketTurnAt=time;sound("sfx_deliver_order_1_snd");}message=done?"Orders dropped off. Collect the numbered ready food tray.":"Cooking takes "+cookMS/1000+" seconds. Return when food is ready.";return done;
    }
    private void checkClosing(){if(level.endless||nextArrival!=level.arrivals.size())return;for(Party p:parties)if(p.state!=State.GONE)return;
        boolean dirty=false;for(Table t:level.tables)dirty|=t.active&&t.dirty;
        if(closingAt<0){closingAt=time+(dirty?10000:1250);message="Closing time. Clear the remaining dishes.";}else if(!dirty&&closingAt>time+1250)closingAt=time+1250;
        if(time>=closingAt){ended=true;won=score>=goal;}
    }
    public boolean blocked(int x,int y){if(x<1||y<3||x>GRID_WIDTH||y>level.height)return true;
        if(level.stageId.equals("finedining")&&x<=2&&y<=9)return true;
        if(level.barColors!=null&&x>=level.barX&&x<=level.barX+2&&y>=level.barY&&y<level.barY+level.barColors.length-1)return true;
        // The first chair anchors the left edge, followed by the table and right chair.
        for(Table t:level.tables)if(t.active&&t.barStart<0&&x>=t.x&&x<=t.x+2&&y>=t.y-1&&y<t.y-1+t.colors.length/2)return true;
        return false;
    }
    private void nextDestination(){if(destinations.isEmpty())return;lastActivityAt=time;currentTarget=destinations.remove();int[] dest=destination(currentTarget);path.clear();pathIndex=0;movement=0;
        if(dest==null||!findPath(dest[0],dest[1])){message="That destination is blocked.";currentTarget=NO_TARGET;destinations.clear();}
    }
    public int[] destination(int target){if(target==KITCHEN)return level.kitchen;if(target==BUS)return level.bus;if(target==DRINKS)return level.drinks;if(target==PODIUM)return level.podium;if(target==SNACK1)return level.snackPositions[0];if(target==SNACK2)return level.snackPositions[1];if(target<=FOOD1&&target>FOOD1-foodSlots.length)return level.foodPositions[FOOD1-target];
        if(target<0||target>=level.tables.size())return null;Table t=level.tables.get(target);return t.barStart>=0?new int[]{level.barX+3,t.y+Math.round((t.colors.length-1)/2f)}:new int[]{t.x+1,t.y-2};}
    // Breadth-first search on the small recovered four-neighbor grid. Furniture is impassable.
    private boolean findPath(int dx,int dy){
        int w=GRID_WIDTH+1,h=level.height+1;int[][] prev=new int[h][w];for(int[] row:prev)Arrays.fill(row,-1);
        ArrayDeque<int[]> todo=new ArrayDeque<>();todo.add(new int[]{floX,floY});prev[floY][floX]=floY*w+floX;int[] found=null;int[][] dirs={{0,-1},{1,0},{0,1},{-1,0}};
        while(!todo.isEmpty()){int[] n=todo.remove();if(n[0]==dx&&n[1]==dy||blocked(dx,dy)&&Math.abs(n[0]-dx)+Math.abs(n[1]-dy)<=1){found=n;break;}
            for(int[] d:dirs){int x=n[0]+d[0],y=n[1]+d[1];if(x<1||y<3||x>GRID_WIDTH||y>level.height||prev[y][x]>=0||blocked(x,y))continue;prev[y][x]=n[1]*w+n[0];todo.add(new int[]{x,y});}}
        if(found==null)return false;int x=found[0],y=found[1];while(x!=floX||y!=floY){path.add(0,new int[]{x,y});int p=prev[y][x];x=p%w;y=p/w;}return true;
    }
    public List<Upgrade> upgradeChoices(){List<Upgrade> choices=new ArrayList<>();if(availableUpgrades<=0)return choices;
        if(tableUpgrade<level.tableUpgrades.size())choices.add(new Upgrade("table","New table","Add a table to this restaurant",new double[0]));
        List<Upgrade> power=new ArrayList<>();for(String type:new String[]{"podium","maitred","drinks","shoes","oven","stereo"}){Upgrade u=LevelData.upgrade(type,upgrades.containsKey(type)?upgrades.get(type):0);if(u!=null)power.add(u);}
        Collections.shuffle(power,random);for(Upgrade u:power){if(choices.size()==3)break;choices.add(u);}return choices;
    }
    public void applyUpgrade(Upgrade u){if(availableUpgrades<=0)return;availableUpgrades--;double[] v=u.values;
        if(u.type.equals("table")){Table source=level.tableUpgrades.get(tableUpgrade++);level.tables.add(new Table(source.x,source.y,source.colors));return;}
        int next=upgrades.containsKey(u.type)?upgrades.get(u.type)+1:1;upgrades.put(u.type,next);
        switch(u.type){case "podium":level.podium=level.podiumPosition.clone();level.podiumCharge=(long)v[0];level.podiumActive=(long)v[1];level.podiumDelay=(long)v[2];level.podiumMood=(int)v[3];break;
        case "drinks":level.drinks=level.drinkPosition.clone();drinkMS=(long)v[4];drinkMood=(int)v[3];drinkReadyAt=time+(long)(drinkMS*timeMultiplier);break;
        case "shoes":speed=(long)v[5];break;case "oven":cookMS=(long)v[6];break;case "maitred":waitingPatience=v[7];break;case "stereo":seatedPatience=v[7];break;}
    }
    private void sound(String s){if(sounds.size()<20)sounds.add(s);}
    public String handsText(){if(hands.isEmpty())return "Hands free ("+capacity+" slots)";StringBuilder s=new StringBuilder("Carrying ");for(Item i:hands){if(s.length()>9)s.append(" + ");s.append(i.type.name().toLowerCase(Locale.ROOT));Party p=party(i.party);if(p!=null)s.append(" T").append(tableLabel(p.table));}return s.toString();}
}
