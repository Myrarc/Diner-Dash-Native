package local.cakemania;

import java.util.*;
import static local.cakemania.GameData.*;

public final class GameEngine {
    public enum CustomerState { WAIT_MENU, READING, ORDER, HAPPY, CASH, LEAVING }
    public static final class Layer {
        public int shape,frost=-1,decor=-1,price;
        Layer(int shape,int price){this.shape=shape;this.price=price;}
    }
    public static final class Cake {
        public final List<Layer> layers=new ArrayList<>();
        public int price(){int p=0;for(Layer l:layers)p+=l.price;return p;}
        public int components(){int n=0;for(Layer l:layers)n+=1+(l.frost>=0?1:0)+(l.decor>=0?1:0);return n;}
        public boolean frosted(){for(Layer l:layers)if(l.frost<0)return false;return !layers.isEmpty();}
    }
    public static final class Station {
        public final Node def;
        public final String kind,guid;
        public float x,y,w,h;
        public Cake cake;
        public float remaining,total,closeAt,discardAt,freshAt;
        public boolean burnt;
        public boolean impulseReserved;
        public boolean cookieRefillPending,doorSoundPlayed;
        public int cookies;
        /** Native CookieOven keeps four independent FormShelf products and a separate door timer. */
        public final boolean[] cookieStock=new boolean[4];
        public float cookieDoorRemaining;
        public int workingForm=-1;
        Station(Node def){this.def=def;kind=def.tag;guid=def.s("guid");refreshGeometry();}
        public void refreshGeometry(){x=def.f("x_global",0);y=def.f("y_global",0);w=def.f("width_global",100);h=def.f("height_global",90);}
        public void setCookieStock(int count){Arrays.fill(cookieStock,false);for(int i=0;i<cookieStock.length&&i<count;i++)cookieStock[i]=true;cookies=Math.max(0,Math.min(cookieStock.length,count));cookieRefillPending=false;}
        public void syncCookieCount(){int count=0;for(boolean present:cookieStock)if(present)count++;cookies=count;}
        public int firstCookie(){for(int i=0;i<cookieStock.length;i++)if(cookieStock[i])return i;return -1;}
        public int cookieSlot(int form){return form<=-2?-form-2:-1;}
        public boolean enabled(){return def.i("upgr_step",0)>0;}
        public String s(String key,String fallback){return def.s(key,fallback);}
        public Node form(int id){for(Node f:def.children)if(f.tag.equals("Form")&&f.i("id",-2)==id)return f;return null;}
    }
    public static final class Customer {
        public final int serial;
        /** Queue position. The native customer vector compacts this after a real removal. */
        public int slot;
        public final Node profile,arrival;
        public final Cake order=new Cake();
        public CustomerState state=CustomerState.WAIT_MENU;
        public float remainingPatience,stateTime;
        public float arrivalAge;
        public int hearts,cakePrice;
        /** Native visual state is independent from the logical service state. */
        public int visualState,visualFrame;
        public float visualElapsed;
        /** Authored customer motion (Cupid's hover), shared by drawing and input. */
        public float hoverX,hoverY;
        private final float[][] hoverCurve;
        private final float hoverPeriod,hoverLength;
        private float hoverTime;
        /** Remaining frame in the native five-frame happy/angry puff, or -1 when idle. */
        public int departureFrame=-1;
        /** Queue position captured when the body disappears; the puff does not follow compaction. */
        public int departureSlot=-1;
        /** Cash is awarded once, while the money puff still owns this queue slot. */
        public boolean cashCollected;
        private float departureElapsed;
        private boolean startEventFired,servedEventFired;
        private float timedEventElapsed;
        private boolean angryThreshold;
        private boolean lostPenaltyCharged;
        Customer(int serial,int slot,Node profile,Node arrival){this.serial=serial;this.slot=slot;this.profile=profile;this.arrival=arrival;
            // 0x00414d80 / 0x00412970: retain the partial heart interval in seconds.
            int patience=profile.i("patience",20);remainingPatience=(profile.i("start_hearts",3)+1)*(patience==0?100:patience)-.01f;updateHearts();
            Node animation=profile.first("Animation");hoverPeriod=animation==null?0:animation.f("time",0);String[] points=animation==null?new String[0]:animation.s("curve").split(";");hoverCurve=new float[points.length][2];float length=0;
            for(int i=0;i<points.length;i++){int[] point=ints(points[i]);hoverCurve[i][0]=point[0];hoverCurve[i][1]=point[1];if(i>0)length+=(float)Math.hypot(hoverCurve[i][0]-hoverCurve[i-1][0],hoverCurve[i][1]-hoverCurve[i-1][1]);}
            hoverLength=length;advanceHover(0);}
        private void updateHearts(){int patience=profile.i("patience",20);hearts=Math.min(profile.i("max_hearts",5),patience==0?profile.i("start_hearts",3):(int)(remainingPatience/patience));}
        private void addHearts(int count,boolean cookie){int patience=profile.i("patience",20);if(patience==0)return;remainingPatience=Math.min(remainingPatience+count*patience,(profile.i("max_hearts",5)+1)*patience-(cookie?0:.01f));updateHearts();}
        public int payment(){updateHearts();return cakePrice+hearts*profile.i("tip",1);}
        public void setVisual(int state){if(visualState!=state){visualState=state;visualFrame=0;visualElapsed=0;}}
        private Node visualImage(){String id=visualState==1?"ID_MENU":visualState==2?"ID_HAPPY":visualState==3?"ID_BORED":visualState==4?"ID_EATING":"ID_NORMAL";for(Node n:profile.children)if(n.tag.equals("Image")&&n.s("id").equals(id))return n;return null;}
        private void advanceHover(float dt){
            if(hoverPeriod<=0||hoverCurve.length<2)return;
            hoverTime+=dt;if(hoverTime>hoverPeriod)hoverTime=0;
            // 0040b140 folds the second half of the period, then squares time.
            float t=hoverTime>=hoverPeriod*.5f?hoverTime-hoverPeriod:hoverTime,distance=t*t*hoverLength/(hoverPeriod*hoverPeriod*.25f);
            hoverX=hoverY=0;
            for(int i=1;i<hoverCurve.length;i++){float[] from=hoverCurve[i-1],to=hoverCurve[i];float length=(float)Math.hypot(to[0]-from[0],to[1]-from[1]);if(distance<=length&&length>0){float phase=distance/length;hoverX=from[0]+(to[0]-from[0])*phase;hoverY=from[1]+(to[1]-from[1])*phase;return;}distance-=length;}
        }
        public void advanceVisual(float dt){
            // The departure puff retains the last visible customer position.
            if(dt<=0)return;if(spriteVisible())advanceHover(dt);Node image=visualImage();if(image==null)return;Node sequence=image.first("Sequence");if(sequence==null)return;int[] frames=ints(sequence.s("frames"));if(frames.length==0)return;
            float interval=.1f;for(Node timing:image.children)if(timing.tag.equals("Timing")){int start=timing.i("framestart",0),end=timing.i("frameend",frames.length);if(start<=visualFrame&&visualFrame<end){float duration=timing.f("time",0);interval=duration/(end>start?end-start:1);if(interval<=0)interval=.1f;break;}}
            visualElapsed+=dt;if(visualElapsed>interval){visualElapsed=0;visualFrame++;if(visualFrame>=frames.length){if(visualState==1||visualState==0){visualFrame=0;}else{visualState=0;visualFrame=0;}}}
        }
        private boolean fireStartEvent(){if(startEventFired)return false;startEventFired=true;return true;}
        private boolean fireServedEvent(){if(servedEventFired)return false;servedEventFired=true;return true;}
        private boolean timedEventDue(float dt,float period){if(period<=0)return false;timedEventElapsed+=dt;if(period<timedEventElapsed){timedEventElapsed=0;return true;}return false;}
        /** The customer body disappears when the native money/angry puff starts. */
        public boolean spriteVisible(){return state!=CustomerState.CASH&&state!=CustomerState.LEAVING;}
        /** The native puff is rendered independently of the customer body. */
        public boolean effectActive(){return (state==CustomerState.CASH||state==CustomerState.LEAVING)&&departureFrame>=0;}
        private void startDeparturePuff(){departureFrame=4;departureSlot=slot;departureElapsed=0;}
        private void advanceDeparturePuff(float dt){
            if(departureFrame<0||dt<=0)return;
            departureElapsed+=dt;
            if(departureElapsed>.1f){departureElapsed=0;departureFrame--;}
        }
        private boolean readyForRemoval(){return departureFrame<0&&(state==CustomerState.LEAVING||(state==CustomerState.CASH&&cashCollected));}
    }
    public static final class Action {
        public final Station station;
        public final Customer customer;
        public final int form;
        /** Destination node is mutable because customer queue positions compact. */
        public int node;
        private boolean begun;
        Action(Station s,Customer c,int form,int node){station=s;customer=c;this.form=form;this.node=node;}
    }
    public final GameData data;
    public final Level level;
    public final List<Station> stations=new ArrayList<>();
    public final List<Customer> customers=new ArrayList<>();
    public final List<Action> queue=new ArrayList<>();
    public final List<String> sounds=new ArrayList<>();
    public final Map<String,Integer> upgrades;
    public final List<Node> arrivals;
    public final float[][] nodes;
    public final int[][] edges;
    public final List<Node> customerPoints;
    private final Random random;
    private int arrivalIndex,nextCustomer,node,routeIndex;
    private float nextArrival,idleTime;
    private int[] route=new int[0];
    public float elapsed,x,y,dx,dy;
    public int money,served,lost,cakesLost,tips,channel=-1,shoeStep;
    public int cakeRevenue,cakeLostMoney,customerLostMoney;
    public Cake hand;
    public boolean paused,finished,won,tvNoise,suppressArrivals,goalReached,closedSound;
    public String message="Tap a customer to hand out a menu.";

    public GameEngine(GameData data,Level level,Map<String,Integer> upgrades,long seed){
        this.data=data;this.level=level;this.upgrades=new LinkedHashMap<>(upgrades);random=new Random(seed);
        for(Node n:level.environment.all("CakeOven"))stations.add(new Station(n.copy()));
        for(String tag:new String[]{"Froster","Decoration","Trash","CookieOven","DisplayCase","TVSet","Shelf"})for(Node n:level.environment.all(tag))stations.add(new Station(n.copy()));
        for(Node u:level.shop.all("Avatar"))if(u.i("upgr_step",0)<=upgradeStep("jill",0))shoeStep=Math.max(shoeStep,u.i("upgr_step",0));
        for(Station s:stations){int step=upgradeStep(s.guid,s.def.i("upgr_step",0));for(Node u:level.shop.all(s.kind))if(u.s("guid").equals(s.guid)&&u.i("upgr_step",0)>s.def.i("upgr_step",0)&&u.i("upgr_step",0)<=step)s.def.merge(u);s.refreshGeometry();}
        for(Station s:stations)if(s.kind.equals("CookieOven")&&s.enabled())s.setCookieStock(4);
        List<Node> pts=level.paths.first("Nodes").children;nodes=new float[pts.size()][2];for(Node p:pts){int id=p.i("id",-1);nodes[id][0]=p.f("x",0);nodes[id][1]=p.f("y",0);}
        edges=new int[nodes.length][];for(Node c:level.paths.first("Connections").children)edges[c.i("id",-1)]=ints(c.s("data"));
        for(int i=0;i<edges.length;i++)if(edges[i]==null)edges[i]=new int[0];
        customerPoints=level.paths.first("CustomerPath").children;
        node=18<nodes.length?18:0;x=nodes[node][0];y=nodes[node][1];arrivals=level.lineup.children;
        nextArrival=arrivals.isEmpty()?Float.POSITIVE_INFINITY:arrivals.get(0).f("time",1);
    }
    public int upgradeStep(String guid,int base){return Math.max(base,upgrades.containsKey(guid)?upgrades.get(guid):0);}
    public static int[] ints(String text){if(text.isEmpty())return new int[0];String[] a=text.split(",");int[] r=new int[a.length];for(int i=0;i<a.length;i++)r[i]=Integer.parseInt(a[i].trim());return r;}
    public Station station(String guid){for(Station s:stations)if(s.guid.equals(guid))return s;return null;}
    // 00401680 moves by authored speed each update; 0048b760 sets a 10 ms update interval.
    public float speed(){Node avatar=level.avatar.first("Avatar");float speed=avatar.f("speed",2);for(Node n:level.shop.all("Avatar"))if(n.i("upgr_step",0)==shoeStep)speed=n.f("speed",speed);return speed*100;}
    public float idleTime(){return idleTime;}
    public boolean moving(){return routeIndex<route.length;}
    public void enqueue(Station station,int form){if(finished||paused)return;if(!station.enabled()){message="Buy this equipment between months.";return;}
        // 0x00435ea0 changes the TV immediately; it never sends Jill to a normal TV button.
        if(station.kind.equals("TVSet")){if(station.form(form)!=null&&(tvNoise||station.remaining==0)){channel=tvNoise?(channel+1)%3:0;tvNoise=true;station.remaining=station.total=1;sound("TV_NOISE");}return;}
        // Native child-pointer clicks still resolve through the machine's
        // associate point; the shelf index selects the product at execution.
        int target=station.def.i("associate_point",nearest(station.x+station.w/2,station.y+station.h));
        queue.add(new Action(station,null,form,target));}
    public void enqueue(Customer customer){
        if(finished||paused||!customers.contains(customer)||customer.state==CustomerState.LEAVING||customer.cashCollected)return;
        Node p=customerPoints.get(customer.slot);queue.add(new Action(null,customer,-1,nearest(p.f("x_money",230)+85,p.f("y_money",400)+20)));
    }
    public void clearQueue(){queue.clear();route=new int[0];routeIndex=0;message="Queued actions cancelled.";}
    public void tick(float dt){
        if(paused||finished||dt<=0)return;elapsed+=dt;idleTime+=dt;
        for(Station s:stations)if(s.kind.equals("CookieOven")&&s.enabled()){
            boolean startedRefill=false;
            // 0x004348d0 starts a refill whenever all four child products are
            // absent and both native timers are idle.  A pickup leaves those
            // values idle; therefore this branch runs on the following tick.
            if(s.cookies==0&&s.remaining==0&&s.cookieDoorRemaining==0){s.remaining=s.total=s.def.f("time",40);s.cookieRefillPending=false;startedRefill=true;sound("COOKIE_START");}
            if(!startedRefill&&s.cookies==0&&s.remaining>0){float remaining=s.remaining-dt;s.remaining=remaining;if(remaining<0){s.remaining=0;s.cookieDoorRemaining=1;sound("COOKIE_READY");}}
            if(s.cookieDoorRemaining>0){s.cookieDoorRemaining-=dt;if(s.cookieDoorRemaining<0){s.setCookieStock(4);s.cookieDoorRemaining=0;message="Four fresh cupcakes are ready.";}}
        }
        for(Station s:stations)if(s.kind.equals("CakeOven")&&s.remaining>0){
            s.remaining=Math.max(0,s.remaining-dt);float phase=s.total-s.remaining;
            // 0x00434020 / 0x00436d50 recycle an old cake during the next cycle, not while idle.
            if(s.cake!=null&&phase>=s.discardAt&&phase<s.freshAt){discard(s.cake,1);s.cake=null;s.burnt=true;sound("TRASH");}
            if(s.cake==null&&phase>s.freshAt&&s.remaining>0){s.cake=new Cake();s.cake.layers.add(new Layer(s.workingForm,s.form(s.workingForm).i("price",15)));s.burnt=false;if(!s.doorSoundPlayed){s.doorSoundPlayed=true;sound("CAKEOVEN_DOOROPEN");}}
            if(s.remaining==0){sound("GCAKEREADY");message="CakeOven is ready.";}
        }
        for(Station s:stations)if((s.kind.equals("Froster")||s.kind.equals("Decoration"))&&s.cake!=null&&s.remaining>0){s.remaining=Math.max(0,s.remaining-dt);if(s.remaining==0){sound("GCAKEREADY");message=s.kind+" is ready.";}}
        Station tv=station("tvset0");if(tv!=null&&tv.enabled()&&tv.remaining>0){tv.remaining-=dt;if(tv.remaining<=0){if(tvNoise){tvNoise=false;tv.remaining=tv.total=tv.def.f("time",5);Node program=tv.form(channel+1);sounds.add(program.s("sfx"));for(Customer c:customers)for(String entry:c.profile.s("tv").split(";")){String[] value=entry.split(",");if(value.length==2&&value[0].equals(program.s("guid"))){int count=Integer.parseInt(value[1]);c.addHearts(count,false);if(count>0)c.setVisual(2);}}}else{tv.remaining=0;channel=-1;}}}
        spawn();
        for(Customer c:new ArrayList<>(customers)){
            boolean wasDeparting=c.state==CustomerState.CASH||c.state==CustomerState.LEAVING;
            c.stateTime+=dt;
            c.arrivalAge+=dt;
            dispatchSpecialEvents(c,dt);
            if(c.state==CustomerState.READING&&c.order.layers.isEmpty())generateOrder(c);
            if(c.state==CustomerState.READING&&c.stateTime>=c.profile.f("menu",5)){c.state=CustomerState.ORDER;c.stateTime=0;c.setVisual(0);message="An order is ready. Match the cake in the bubble.";}
            if(c.state==CustomerState.HAPPY&&c.stateTime>2){
                // The original keeps the happy customer visible for a strict
                // two-second interval, then hides the body and starts the
                // five-frame money puff at frame 4.
                c.state=CustomerState.CASH;c.stateTime=0;c.setVisual(2);c.startDeparturePuff();
            }
            if(c.state==CustomerState.READING)c.setVisual(1);else if(c.state==CustomerState.HAPPY)c.setVisual(2);else if(c.state==CustomerState.LEAVING)c.setVisual(3);
            c.advanceVisual(dt);
            if(c.state==CustomerState.CASH||c.state==CustomerState.LEAVING){
                if(wasDeparting)c.advanceDeparturePuff(dt);
                if(c.readyForRemoval())removeCustomer(c);
                continue;
            }
            if(c.state==CustomerState.WAIT_MENU||c.state==CustomerState.READING||c.state==CustomerState.ORDER){
                int patience=c.profile.i("patience",20),previousHearts=c.hearts;if(patience!=0)c.remainingPatience-=dt;c.updateHearts();
                // Native 0x00412970 emits the angry cue only on the downward
                // transition into exactly one heart.  A recovery clears the
                // latch so a later transition can legitimately fire again.
                if(c.hearts>1)c.angryThreshold=false;
                if(c.hearts<previousHearts&&c.hearts==1&&!c.angryThreshold){c.angryThreshold=true;c.setVisual(3);String angrySound=c.profile.s("sound_angry");if(!angrySound.isEmpty())sounds.add(angrySound);}
                else if(c.visualState==0&&c.hearts==1)c.setVisual(3);else if(c.visualState==3&&c.hearts>1)c.setVisual(0);
                if(patience!=0&&c.remainingPatience<patience&&!c.lostPenaltyCharged){
                    c.lostPenaltyCharged=true;
                    lost++;int penalty=c.state==CustomerState.WAIT_MENU?50:c.order.components()*25;customerLostMoney+=penalty;money=Math.max(0,money-penalty);
                    c.state=CustomerState.LEAVING;c.stateTime=0;c.setVisual(3);c.startDeparturePuff();sound("CUSTOMER_LOST");message="A customer left unhappy.";
                }
            }
        }
        move(dt);
        if(!goalReached&&money>=level.goal){goalReached=true;sound("BAKERGOALREACHED");}
        if(!closedSound&&elapsed>=level.duration){closedSound=true;sound("CLOSED");}
        if(elapsed>=level.duration&&customers.isEmpty()){for(Station s:stations)if(s.cake!=null)discard(s.cake,2);finished=true;won=money>=level.goal;queue.clear();sound(won?"WINLEVEL":"LOSELIFE");}
    }
    private void discard(Cake cake,int multiplier){int penalty=cake.price()*multiplier;cakeLostMoney+=penalty;money=Math.max(0,money-penalty);cakesLost++;}
    private void spawn(){
        if(suppressArrivals||elapsed>=level.duration)return;
        int capacity=Math.min(customerPoints.size(),level.lineup.i("max_on_level",4));
        while(arrivalIndex<arrivals.size()&&elapsed>=nextArrival&&customers.size()<capacity){
            Node a=arrivals.get(arrivalIndex);Node p=data.profiles.get(a.s("guid"));if(p==null)throw new IllegalStateException("Unknown customer "+a.s("guid"));
            Customer c=new Customer(++nextCustomer,customers.size(),p,a);c.arrivalAge=0;customers.add(c);dispatchSpecialEvents(c,0);sound("CUSTOMER_ARRIVES");
            arrivalIndex++;nextArrival+=arrivalIndex<arrivals.size()?arrivals.get(arrivalIndex).f("time",10):Float.POSITIVE_INFINITY;
        }
    }
    /** Adds a configured customer immediately for the native scripted tutorial/endless dispatcher. */
    public Customer addCustomer(Node arrival){
        if(arrival==null)throw new IllegalArgumentException("arrival");Node p=data.profiles.get(arrival.s("guid"));if(p==null)throw new IllegalArgumentException("Unknown customer "+arrival.s("guid"));
        Customer c=new Customer(++nextCustomer,customers.size(),p,arrival);customers.add(c);dispatchSpecialEvents(c,0);return c;
    }
    /**
     * Native customer storage is an ordered vector. Removing a customer shifts
     * every later customer into the freed queue position; a cash customer is
     * therefore left in the vector until its money is collected and its puff
     * completes.
     */
    private void removeCustomer(Customer departing){
        if(!customers.remove(departing))return;
        for(int i=0;i<customers.size();i++)customers.get(i).slot=i;
        updateQueuedCustomerTargets();
    }
    private void updateQueuedCustomerTargets(){
        boolean activeChanged=false;
        for(int i=0;i<queue.size();i++){
            Action action=queue.get(i);if(action.customer==null)continue;
            Node point=customerPoints.get(action.customer.slot);
            int target=nearest(point.f("x_money",230)+85,point.f("y_money",400)+20);
            if(action.node!=target){action.node=target;if(i==0)activeChanged=true;}
        }
        if(activeChanged){route=new int[0];routeIndex=0;dx=dy=0;}
    }
    private void dispatchSpecialEvents(Customer c,float dt){
        Node messageNode=c.profile.first("Message");if(messageNode==null)return;String xtime=messageNode.s("xtime");
        if("atstart".equalsIgnoreCase(xtime)&&c.fireStartEvent()){broadcastHeartEvent(c.profile.s("guid"));message=c.profile.s("message",c.profile.s("name","Customer")+" has arrived.");}
        if(isNumeric(xtime)&&c.timedEventDue(dt,messageNode.f("xtime",0)))broadcastHeartEvent(c.profile.s("guid"));
    }
    private static boolean isNumeric(String value){try{Float.parseFloat(value);return true;}catch(NumberFormatException e){return false;}}
    private void dispatchServedEvent(Customer c){Node n=c.profile.first("Message");if(n!=null&&"atserved".equalsIgnoreCase(n.s("xtime"))&&c.fireServedEvent())broadcastHeartEvent(c.profile.s("guid"));}
    private void broadcastHeartEvent(String sourceGuid){for(Customer recipient:new ArrayList<>(customers))for(String pair:recipient.profile.s("xtrahearts").split(";")){String[] value=pair.split(",");if(value.length!=2||!value[0].equals(sourceGuid))continue;try{int count=Integer.parseInt(value[1]);recipient.addHearts(count,false);if(count>0){recipient.setVisual(2);sound("CUSTOMER_HAPPY");}}catch(NumberFormatException ignored){}break;}}
    private List<Integer> available(String kind){Set<Integer> ids=new LinkedHashSet<>();for(Station s:stations)if(s.enabled()&&s.kind.equals(kind))for(Node f:s.def.children)if(f.tag.equals("Form"))ids.add(f.i("id",0));return new ArrayList<>(ids);}
    private int choose(String weights,List<Integer> available,int fallback){
        if(available.isEmpty())return fallback;
        // 0x0040f430 counts and sums authored pairs before filtering them through
        // the active-form table.  An authored zero therefore differs from an
        // absent entry and must remain a zero-weight candidate.
        Map<Integer,Integer> supplied=new LinkedHashMap<>();int authoredCount=0,sum=0;
        for(String pair:weights.split(";")){
            String[] a=pair.split(",");if(a.length!=2)continue;
            try{int id=Integer.parseInt(a[0].trim()),v=Integer.parseInt(a[1].trim());authoredCount++;sum+=v;supplied.put(id,supplied.getOrDefault(id,0)+v);}catch(NumberFormatException ignored){}
        }
        int defaultWeight=0;
        if(available.size()!=authoredCount&&sum<100){int missing=available.size()-authoredCount;if(missing>0)defaultWeight=(100-sum)/missing;}
        boolean nonZero=false;for(int id:available){int weight=supplied.containsKey(id)?supplied.get(id):defaultWeight;if(weight!=0){nonZero=true;break;}}
        if(!nonZero)return available.get(random.nextInt(available.size()));
        int roll=random.nextInt(100),cursor=0;
        for(int id:available){int weight=supplied.containsKey(id)?supplied.get(id):defaultWeight;cursor+=weight;if(roll<cursor)return id;}
        // The native tail falls through to the last candidate when the authored
        // total leaves a residue; it does not draw a second random value.
        return available.get(available.size()-1);
    }
    private void generateOrder(Customer c){
        if(!c.order.layers.isEmpty())return;
        if(displayImpulse(c))return;
        int maximum=c.arrival.i("max_layers",c.profile.i("max_layers",2));// Native 0x0040feb0 uses component counts 4/5 for two tiers, and 3/5 for a topper.
        int layers=maximum>=4?2:1;
        List<Integer> shapes=available("CakeOven"),frosts=available("Froster"),decor=available("Decoration");
        for(int i=0;i<layers;i++){Layer l=new Layer(choose(c.arrival.s("cake"),shapes,1),15);l.frost=choose(c.arrival.s("frost"),frosts,0);c.order.layers.add(l);}
        if(!decor.isEmpty()&&(maximum==3||maximum>=5))c.order.layers.get(layers-1).decor=choose(c.arrival.s("decor"),decor,-1);
    }
    private boolean displayImpulse(Customer c){
        Station display=station("displaycase0");if(display==null||display.cake==null||display.impulseReserved)return false;
        int chance=c.arrival.i("get_display",c.profile.i("get_display",display.def.i("get_display",20)));if(random.nextInt(100)>chance)return false;
        Cake candidate=display.cake;int components=candidate.components();if(components!=2&&components!=4&&components!=3&&components!=5)return false;if((components==3||components==5)&&candidate.layers.get(candidate.layers.size()-1).decor<0)return false;
        for(Customer other:customers)if(other!=c&&!other.order.layers.isEmpty()&&matches(candidate,other.order))return false;
        // Native 0x0040feb0 copies the candidate and marks it; the recovered branch does
        // not prove whether the source is consumed, so retain the cake and reserve it once.
        c.order.layers.addAll(copyLayers(candidate));display.impulseReserved=true;return true;
    }
    private static List<Layer> copyLayers(Cake source){List<Layer> copy=new ArrayList<>();for(Layer l:source.layers){Layer n=new Layer(l.shape,l.price);n.frost=l.frost;n.decor=l.decor;copy.add(n);}return copy;}
    private int nearest(float x,float y){int best=0;float distance=Float.MAX_VALUE;for(int i=0;i<nodes.length;i++){float d=(nodes[i][0]-x)*(nodes[i][0]-x)+(nodes[i][1]-y)*(nodes[i][1]-y);if(d<distance){distance=d;best=i;}}return best;}
    public int[] path(int from,int to){
        float[] distance=new float[nodes.length];Arrays.fill(distance,Float.POSITIVE_INFINITY);int[] prev=new int[nodes.length];Arrays.fill(prev,-1);boolean[] visited=new boolean[nodes.length];distance[from]=0;
        for(int pass=0;pass<nodes.length;pass++){int u=-1;for(int i=0;i<nodes.length;i++)if(!visited[i]&&(u<0||distance[i]<distance[u]))u=i;if(u<0||Float.isInfinite(distance[u]))break;if(u==to)break;visited[u]=true;for(int v:edges[u]){float d=distance[u]+(float)Math.hypot(nodes[u][0]-nodes[v][0],nodes[u][1]-nodes[v][1]);if(d<distance[v]){distance[v]=d;prev[v]=u;}}}
        if(from==to)return new int[0];if(prev[to]<0)throw new IllegalStateException("Unreachable path node "+to);List<Integer> reversed=new ArrayList<>();for(int n=to;n!=from;n=prev[n])reversed.add(n);int[] result=new int[reversed.size()];for(int i=0;i<result.length;i++)result[i]=reversed.get(result.length-i-1);return result;
    }
    private void move(float dt){
        if(queue.isEmpty()){dx=dy=0;return;}
        Action a=queue.get(0);
        if(a.customer!=null&&!customers.contains(a.customer)){complete();return;}
        if(!a.begun){a.begun=true;Station s=a.station;
            // 0x0044bf00 / 0x0044d8f0: resolve queued clicks when they become active.
            if(s!=null&&a.form>=0&&(s.kind.equals("CakeOven")&&s.remaining>0||(s.kind.equals("Froster")||s.kind.equals("Decoration"))&&hand==null&&s.cake==null)){clearQueue();message="No action is available on that button yet.";return;}
        }
        if(routeIndex>=route.length&&node!=a.node){route=path(node,a.node);routeIndex=0;}
        float budget=speed()*dt;
        while(routeIndex<route.length){int n=route[routeIndex];float vx=nodes[n][0]-x,vy=nodes[n][1]-y,d=(float)Math.hypot(vx,vy);dx=vx;dy=vy;idleTime=0;if(d>budget){x+=vx/d*budget;y+=vy/d*budget;return;}x=nodes[n][0];y=nodes[n][1];node=n;routeIndex++;budget-=d;}
        // 0x00404800 / 0x0044ab40 invoke the arrival callback once, including a busy-machine no-op.
        dx=dy=0;execute(a);complete();
    }
    private void complete(){if(!queue.isEmpty())queue.remove(0);route=new int[0];routeIndex=0;idleTime=0;}
    private void sound(String id){sounds.add("SOUND_"+id);}
    private boolean execute(Action a){
        if(a.customer!=null)return service(a.customer);
        Station s=a.station;Node form=s.form(a.form);
        if(s.kind.equals("CakeOven")){
            if(form!=null){if(s.remaining>0)return false;s.remaining=s.total=s.def.f("time",5);s.closeAt=Math.max(0,s.total-2);s.discardAt=s.total>=2?s.closeAt+1.4f:s.total*.65f;s.freshAt=s.total>=2?s.closeAt+1.6f:s.total*.85f;s.burnt=false;s.doorSoundPlayed=false;s.workingForm=a.form;sound("CAKEOVEN_WORK");message="Cake is baking.";return true;}
            if(s.cake==null){if(s.remaining>0)return false;if(hand!=null&&hand.layers.size()==1&&hand.layers.get(0).frost<0){s.cake=hand;hand=null;s.remaining=0;s.burnt=false;sound("PLACEDOWN");}return true;}
            if(s.remaining>0&&s.total-s.remaining>=s.closeAt)return false;
            if(hand==null)hand=s.cake;else{message="Put down the cake you are carrying first.";return true;}
            s.cake=null;sound("PICKUP");message="Carry the cake to a frosting machine.";return true;
        }
        if(s.kind.equals("Froster")||s.kind.equals("Decoration")){
            if(s.remaining>0)return false;
            // Native callback 0x0044ab40: body taps place/pick up; Form taps process.
            if(form==null&&hand==null){if(s.cake!=null){hand=s.cake;s.cake=null;sound("PICKUP");message="Cake picked up.";}return true;}
            if(hand!=null){
                if(s.cake==null){Layer top=hand.layers.get(hand.layers.size()-1);if(top.decor>=0||(s.kind.equals("Decoration")&&top.frost<0)){message="This cake cannot go on this machine.";return true;}s.cake=hand;hand=null;sound("PLACEDOWN");}
                else{
                    // 0x0044ab40 / 0x00407930 assemble layers on a tray, never in Jill's hand.
                    Layer base=s.cake.layers.get(s.cake.layers.size()-1);
                    boolean stack=s.cake.layers.size()==1&&base.frost>=0&&base.decor<0&&hand.layers.size()==1;
                    if(form!=null)stack=stack&&s.kind.equals("Froster")&&hand.layers.get(0).frost<0;
                    if(!stack){message="Put down the cake you are carrying first.";return true;}
                    s.cake.layers.addAll(hand.layers);hand=null;sound("PLACEDOWN");
                }
            }
            if(s.cake==null){message="Bring a cake to this machine.";return true;}if(form==null){message="Cake placed on the tray.";return true;}
            Layer top=s.cake.layers.get(s.cake.layers.size()-1);
            if(s.kind.equals("Froster")){if(top.frost>=0){message="This layer is already frosted.";return true;}top.frost=a.form;sound("FROSTER");}
            else{if(top.frost<0){message="Frost the cake before decorating it.";return true;}if(top.decor>=0){message="This cake already has a decoration.";return true;}top.decor=a.form;sound("DECORATOR");}
            top.price+=form.i("price",s.kind.equals("Froster")?15:10);s.remaining=s.def.f("time",5);s.total=s.remaining;s.workingForm=a.form;return true;
        }
        if(s.kind.equals("Trash")){if(hand!=null){if(hand.layers.get(0).shape!=8)discard(hand,1);hand=null;sound("TRASH");}return true;}
        if(s.kind.equals("DisplayCase")||s.kind.equals("Shelf")){if(s.cake!=null&&hand==null){hand=s.cake;s.cake=null;sound("PICKUP");}else if(s.cake==null&&hand!=null){s.cake=hand;hand=null;sound("PLACEDOWN");}return true;}
        if(s.kind.equals("CookieOven")){if(hand!=null){message="Put down the cake you are carrying first.";return true;}int slot=s.cookieSlot(a.form);if(slot<0)slot=s.firstCookie();if(slot<0||slot>=s.cookieStock.length||!s.cookieStock[slot])return false;s.cookieStock[slot]=false;s.syncCookieCount();hand=new Cake();hand.layers.add(new Layer(8,0));if(s.cookies==0){s.cookieRefillPending=true;s.remaining=s.total=0;s.cookieDoorRemaining=0;}sound("PICKUP");message="Give the cupcake to a waiting customer.";return true;}
        return true;
    }
    private boolean service(Customer c){
        if(c.state==CustomerState.CASH){
            if(c.cashCollected)return false;
            int payment=c.payment();cakeRevenue+=c.cakePrice;tips+=payment-c.cakePrice;money+=payment;c.cashCollected=true;sound("CASH");message="Collected $"+payment+".";
            // Keep the customer in the vector until the independent money puff
            // completes; the next tick removes it and compacts the line.
            return true;
        }
        if(c.state==CustomerState.LEAVING){message="This customer has left.";return false;}
        if(hand!=null&&hand.layers.get(0).shape==8){c.addHearts(c.profile.i("cookie",1),true);c.setVisual(4);c.visualElapsed=0;c.visualFrame=0;hand=null;sound("CUSTOMER_EAT");return true;}
        if(c.state==CustomerState.WAIT_MENU){c.state=CustomerState.READING;c.stateTime=0;c.setVisual(1);c.addHearts(c.profile.i("menu_hearts",1),false);sound("PAPER");message="Customer is choosing a cake.";return true;}
        if(c.state==CustomerState.READING)return false;
        if(c.state==CustomerState.ORDER&&hand!=null){if(!matches(hand,c.order)){message="Wrong cake. Match every shape, frosting and decoration.";sound("WRONG_CAKE");return true;}c.cakePrice=hand.price();hand=null;served++;c.state=CustomerState.HAPPY;c.stateTime=0;c.setVisual(2);dispatchServedEvent(c);sound("CUSTOMER_HAPPYLEAVING");message="Order served. Collect the payment.";return true;}
        if(c.state==CustomerState.ORDER)message="Bring the cake shown in this customer's order.";
        return c.state!=CustomerState.HAPPY;
    }
    public static boolean matches(Cake cake,Cake order){if(cake.layers.size()!=order.layers.size())return false;for(int i=0;i<cake.layers.size();i++){Layer a=cake.layers.get(i),b=order.layers.get(i);if(a.shape!=b.shape||a.frost!=b.frost||a.decor!=b.decor)return false;}return true;}
}
