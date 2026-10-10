package local.cakemania;
import java.io.*;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

public final class GameEngineTest {
    private static void check(boolean pass,String message){if(!pass)throw new AssertionError(message);}
    private static void advance(GameEngine g,float seconds){for(int i=0;i<Math.ceil(seconds*60);i++)g.tick(1f/60);}
    private static void drain(GameEngine g){for(int i=0;!g.queue.isEmpty()&&i<6000;i++)g.tick(1f/60);check(g.queue.isEmpty(),"Actions must terminate");}
    private static Map<String,Integer> fullUpgrades(Level l){Map<String,Integer> result=new HashMap<>();for(Node n:l.shop.children)if(n.i("upgr_step",0)>result.getOrDefault(n.s("guid"),0))result.put(n.s("guid"),n.i("upgr_step",0));return result;}
    private static Station formStation(GameEngine g,String kind,int id){for(Station s:g.stations)if(s.kind.equals(kind)&&s.enabled()&&s.form(id)!=null&&s.cake==null&&s.remaining==0)return s;return null;}
    private static Cake single(int shape,int frost){Cake cake=new Cake();Layer layer=new Layer(shape,frost<0?15:30);layer.frost=frost;cake.layers.add(layer);return cake;}
    private static GameEngine fixture(GameData data,int patience){GameEngine g=new GameEngine(data,data.level(1),Collections.singletonMap("tvset0",1),987);g.elapsed=g.level.duration+1;Node p=data.profiles.get("boy").copy();p.attrs.put("patience",""+patience);p.attrs.put("tip","2");p.attrs.put("tv","news,1;");g.customers.add(new Customer(1,0,p,g.arrivals.get(0)));return g;}
    private static void nativeTiming(GameData data){
        GameEngine g=fixture(data,10);Customer c=g.customers.get(0);check(Math.abs(c.remainingPatience-39.99f)<.001f&&c.hearts==3,"Native initialization must preserve nearly four patience intervals while displaying three hearts");
        advance(g,9.5f);check(c.hearts==3,"A partial interval must not discard the customer's remaining fraction of a heart");advance(g,.6f);check(c.hearts==2,"Visible hearts must be the integer quotient of remaining seconds and native patience");
        float before=c.remainingPatience,elapsed=g.elapsed;g.enqueue(c);drain(g);check(Math.abs(c.remainingPatience-(before-(g.elapsed-elapsed)+10))<.04f,"Handing out a menu must add one full native interval without resetting the partial interval");
        c.remainingPatience=10.1f;c.state=CustomerState.WAIT_MENU;g.money=100;g.tick(.2f);check(g.lost==1&&g.money==50,"Leaving before a menu must charge the native $50 penalty at the last heart boundary");
        g=fixture(data,10);c=g.customers.get(0);c.state=CustomerState.ORDER;c.order.layers.add(single(1,0).layers.get(0));c.order.layers.add(single(2,1).layers.get(0));c.order.layers.get(1).decor=4;c.remainingPatience=10.1f;g.money=200;g.tick(.2f);check(g.lost==1&&g.money==75,"A five-component unfinished order must charge five times $25, not a flat penalty");
        g=fixture(data,0);c=g.customers.get(0);advance(g,200);check(g.customers.contains(c)&&c.hearts==3,"A zero-patience profile must keep its fixed starting hearts and never time out");

        g=fixture(data,10);c=g.customers.get(0);Station tv=g.station("tvset0");before=c.remainingPatience;elapsed=g.elapsed;
        g.enqueue(tv,-1);check(g.channel==-1&&g.queue.isEmpty(),"The TV body must not walk Jill or switch the channel");g.enqueue(tv,1);advance(g,.5f);check(g.tvNoise&&g.channel==0&&c.remainingPatience<before,"The first TV button click must begin one second of static without awarding hearts");
        g.enqueue(tv,1);check(g.channel==1&&tv.remaining==1&&g.queue.isEmpty(),"Clicks during static must cycle programs immediately and restart static, without disturbing Jill's queue");advance(g,1.1f);
        check(!g.tvNoise&&Math.abs(c.remainingPatience-(before-(g.elapsed-elapsed)+10))<.04f,"The preferred broadcast must award exactly one native heart interval when static finishes");before=c.remainingPatience;elapsed=g.elapsed;g.enqueue(tv,1);check(g.channel==1&&!g.tvNoise,"A TV click during a broadcast must be ignored");advance(g,3);
        check(Math.abs(c.remainingPatience-(before-(g.elapsed-elapsed)))<.04f,"Broadcast time must neither slow patience decay nor award recurring free hearts");advance(g,tv.remaining+.05f);check(g.channel==-1&&tv.remaining==0,"The TV must turn off after the upgraded shop entry's twenty-second broadcast, rather than loop forever");

        g=fixture(data,10);c=g.customers.get(0);c.state=CustomerState.ORDER;c.order.layers.add(single(1,0).layers.get(0));g.hand=single(1,0);g.enqueue(c);drain(g);check(g.tips==0&&g.money==0&&c.state==CustomerState.HAPPY,"Delivery must store the cake's price and defer tips until cash collection");
        c.remainingPatience=29.5f;before=c.remainingPatience;advance(g,2.1f);check(c.state==CustomerState.CASH&&c.remainingPatience==before,"A served customer must stop losing patience and expose cash after the native two-second delay");tv=g.station("tvset0");g.enqueue(tv,1);g.enqueue(tv,1);advance(g,1.1f);g.enqueue(c);drain(g);check(g.money==36&&g.tips==6,"A TV heart gained after serving must still affect the tip calculated at cash collection");

        g=fixture(data,0);Station oven=g.station("cakeoven0");g.enqueue(oven,1);drain(g);check(oven.cake==null&&oven.remaining>0,"Selecting a shape must begin the native bake cycle before a new base exists");advance(g,6);check(oven.cake!=null&&oven.cake.layers.get(0).shape==1,"The new cake must appear in the final oven phase");advance(g,50);check(oven.cake!=null&&!oven.burnt,"A finished cake must remain safe indefinitely while the oven is idle");
        g.money=100;g.enqueue(oven,2);drain(g);check(oven.cake.layers.get(0).shape==1,"Starting the next bake must initially preserve the old cake");advance(g,4.5f);check(oven.cake==null&&g.money==85&&g.cakesLost==1,"The old cake must be discarded once at the recovered 4.4-second recycling phase, charging its price");advance(g,1);check(oven.cake.layers.get(0).shape==2&&g.money==85,"Recycling must create the newly selected shape without charging the old cake twice");
        g.enqueue(oven,3);drain(g);g.enqueue(oven,-1);drain(g);check(g.hand!=null&&g.hand.layers.get(0).shape==2&&oven.remaining>0,"Jill must be able to rescue the old cake before the next cycle's door-close phase");advance(g,6);check(oven.cake.layers.get(0).shape==3&&g.money==85,"Rescuing an old cake must let the new bake finish without a discard penalty");
        g.enqueue(g.station("trash"),-1);drain(g);check(g.money==70&&g.hand==null,"Discarding a carried cake must charge its actual component prices");
        g.customers.clear();g.tick(.01f);check(g.finished&&g.money==40,"Month-end station leftovers must cost twice their cake price before testing the goal");
    }
    private static void queueTiming(GameData data){
        GameEngine g=fixture(data,0);Customer c=g.customers.get(0);Station oven=g.station("cakeoven0");g.enqueue(oven,1);drain(g);g.enqueue(oven,-1);g.enqueue(c);drain(g);
        check(g.hand==null&&oven.remaining>0&&c.state==CustomerState.READING,"An early oven pickup must be attempted once and leave Jill free to perform the next queued menu action");
        g=fixture(data,0);c=g.customers.get(0);oven=g.station("cakeoven0");g.enqueue(oven,1);drain(g);g.enqueue(oven,2);g.enqueue(c);drain(g);
        check(c.state==CustomerState.WAIT_MENU&&oven.workingForm==1,"A queued shape click that cannot create an action while the oven is busy must clear the remaining queue, not change the active bake");
        g=fixture(data,0);c=g.customers.get(0);g.enqueue(g.station("froster1"),0);g.enqueue(c);drain(g);check(c.state==CustomerState.WAIT_MENU,"An empty frosting button with no carried cake must not invent a waiting job");
        g.enqueue(c);g.enqueue(g.station("tvset0"),1);check(g.queue.size()==1&&g.tvNoise,"A TV button click must preserve Jill's existing action queue");
    }
    private static void machineClicks(GameData data){
        GameEngine g=new GameEngine(data,data.level(1),Collections.emptyMap(),321);
        Set<String> enabled=new HashSet<>();for(Station s:g.stations)if(s.enabled())enabled.add(s.guid);
        check(enabled.equals(new HashSet<>(Arrays.asList("cakeoven0","froster1","trash"))),"January must expose exactly the native starting equipment, not the unpurchased slots");
        g.enqueue(g.station("froster0"),0);check(g.queue.isEmpty(),"Hidden upgrade-zero equipment must never accept a queued action");
        Station froster=g.station("froster1");Cake first=single(1,-1);g.hand=first;
        g.enqueue(froster,-1);drain(g);check(g.hand==null&&froster.cake==first&&first.layers.get(0).frost==-1&&froster.remaining==0,"A tray tap must place the cake without selecting a frosting color or starting production");
        g.enqueue(froster,2);drain(g);check(g.hand==null&&froster.cake==first&&first.layers.get(0).frost==2&&froster.remaining>0&&first.price()==30,"A direct color tap must frost the cake already on that tray, charging the native Form price once");
        advance(g,6);g.enqueue(froster,0);drain(g);check(g.hand==null&&froster.cake==first&&first.layers.get(0).frost==2&&first.price()==30,"A color tap must not pick up or recolor an already frosted cake");
        g.enqueue(froster,-1);drain(g);check(g.hand==first&&froster.cake==null,"Only the tray body picks up a completed cake");
        Station oven=g.station("cakeoven0");oven.cake=single(3,-1);g.enqueue(oven,-1);drain(g);check(g.hand==first&&oven.cake!=null&&first.layers.size()==1,"Jill must not assemble another tier in her hand by clicking an occupied oven");oven.cake=null;
        g.enqueue(froster,-1);drain(g);g.hand=single(3,-1);g.enqueue(froster,1);drain(g);
        check(g.hand==null&&froster.cake==first&&first.layers.size()==2&&first.layers.get(1).frost==1&&first.price()==60,"A color tap with a raw second tier must stack and frost it on the first tier's tray");
        advance(g,6);Cake third=single(2,-1);g.hand=third;g.enqueue(froster,2);drain(g);check(g.hand==third&&first.layers.size()==2,"Native station component limits must reject a third tier without consuming the carried cake");
        GameEngine upgraded=new GameEngine(data,data.level(1),fullUpgrades(data.level(1)),322);Station decorator=upgraded.station("decorator0");
        Cake raw=single(1,-1);upgraded.hand=raw;upgraded.enqueue(decorator,7);drain(upgraded);check(upgraded.hand==raw&&decorator.cake==null,"A decorator must reject an unfrosted cake without taking it out of Jill's hand");
        raw.layers.get(0).frost=0;raw.layers.get(0).price=30;upgraded.enqueue(decorator,-1);drain(upgraded);check(decorator.cake==raw&&decorator.remaining==0,"A decorator tray tap must place a frosted cake without choosing a topper");
        upgraded.enqueue(decorator,7);drain(upgraded);check(decorator.cake==raw&&raw.layers.get(0).decor==7&&raw.price()==30+decorator.form(7).i("price",0),"The selected topper and price must come from this particular machine's original Form");
    }
    private static void equipment(GameData data){
        Level level=data.level(1);check(level.shop.children.size()>20,"Shop must expose equipment entries inside the original LevelAddEnv wrapper");
        GameEngine g=new GameEngine(data,level,fullUpgrades(level),124);
        check(g.shoeStep==3&&g.speed()==600&&g.station("cakeoven0").def.f("time",0)==2,"Purchased shoe and oven steps must actually apply to gameplay");
        check(g.station("decorator0").form(7)!=null&&g.station("decorator1").form(0)!=null,"Decorator upgrades must retain each machine's original topper options");
        GameEngine stock=new GameEngine(data,level,Collections.emptyMap(),124);check(!stock.station("cupcake0").enabled()&&stock.station("cakeoven0").def.f("time",0)==5,"Applying upgrades must not mutate the original month configuration");
        Station microwave=g.station("cupcake0");check(microwave.cookies==4,"An enabled microwave must start with one batch of four cupcakes");advance(g,1.1f);Customer customer=g.customers.get(0);
        for(int i=0;i<4;i++){g.enqueue(microwave,-1);g.enqueue(customer);drain(g);check(g.hand==null,"Serving a cupcake must free Jill's hand");check(microwave.cookies==3-i,"Each pickup must consume exactly one cupcake");check(customer.hearts<=customer.profile.f("max_hearts",5),"Cupcakes must not award hearts above the profile maximum");}
        check(microwave.total==20&&microwave.remaining>0&&microwave.remaining<=20,"The last cupcake must start the upgraded twenty-second refill while Jill walks to serve it");
        g.paused=true;float remaining=microwave.remaining;advance(g,2);check(microwave.remaining==remaining,"Pausing must freeze cupcake production");g.paused=false;
        g.enqueue(microwave,-1);drain(g);check(g.hand==null&&microwave.cookies==0,"A pickup attempted before the batch is ready must complete as a no-op, not grant a sample or wait indefinitely");advance(g,remaining+1);g.enqueue(microwave,-1);drain(g);check(g.hand!=null&&g.hand.layers.get(0).shape==8&&microwave.cookies==3&&g.queue.isEmpty(),"A new pickup after refill must consume exactly one of the four fresh cupcakes");
    }
    private static void core(GameData data){
        GameEngine g=new GameEngine(data,data.level(1),Collections.emptyMap(),123);
        check(g.level.goal==200&&g.level.duration==160,"January must retain original goal/duration");advance(g,11.1f);check(g.customers.size()==2,"Original first two arrivals must be scheduled");
        Customer first=g.customers.get(0),second=g.customers.get(1);g.enqueue(second);g.enqueue(first);drain(g);
        check(first.state!=CustomerState.WAIT_MENU&&second.state!=CustomerState.WAIT_MENU,"Queue must continue after handing out the first menu and permit selecting any customer");
        g.paused=true;float before=g.elapsed,hearts=first.hearts;advance(g,20);check(g.elapsed==before&&first.hearts==hearts,"Pausing must freeze time and patience");g.paused=false;
        advance(g,6);Customer target=first;Layer wanted=target.order.layers.get(0);Station oven=formStation(g,"CakeOven",wanted.shape),froster=formStation(g,"Froster",wanted.frost);
        g.enqueue(oven,wanted.shape);drain(g);advance(g,oven.remaining+.1f);g.enqueue(oven,-1);g.enqueue(froster,wanted.frost);drain(g);advance(g,froster.remaining+.1f);g.enqueue(froster,-1);g.enqueue(target);drain(g);advance(g,2.1f);g.enqueue(target);drain(g);
        check(g.served==1&&g.money>=30&&g.hand==null,"Ready pickup/frost and pickup/delivery chains must retain later actions, with production and cash readiness respected");
        advance(g,.8f);check(!g.customers.contains(target),"Collecting cash must release the slot after the native departure puff finishes");
        Cake wrong=new Cake();Layer a=new Layer(wanted.shape,15);a.frost=(wanted.frost+1)%4;wrong.layers.add(a);g.hand=wrong;int served=g.served;g.enqueue(second);drain(g);
        check(g.hand==wrong&&g.served==served,"A wrong cake must stay in Jill's hand and award nothing");
        for(int from=0;from<g.nodes.length;from++)for(int to=0;to<g.nodes.length;to++){int at=from;for(int n:g.path(from,to)){boolean adjacent=false;for(int edge:g.edges[at])if(edge==n)adjacent=true;check(adjacent,"Jill must follow recovered path connections");at=n;}check(at==to,"Paths must reach their destination");}
    }
    private static void playMonth(GameData data,int number){
        GameEngine g=new GameEngine(data,data.level(number),number==1?Collections.emptyMap():fullUpgrades(data.level(number)),1000+number);
        Customer target=null;
        for(int frame=0;frame<(g.level.duration+500)*60&&!g.finished;frame++){
            g.tick(1f/60);
            if(!g.queue.isEmpty())continue;
            if(target!=null&&!g.customers.contains(target)){g.hand=null;for(Station station:g.stations){station.cake=null;station.remaining=0;}target=null;}
            if(target!=null&&(target.state==CustomerState.HAPPY||target.state==CustomerState.CASH))target=null;
            Customer cash=null,menu=null;for(Customer c:g.customers){if(c.state==CustomerState.CASH)cash=c;if(c.state==CustomerState.WAIT_MENU)menu=c;}
            if(cash!=null){g.enqueue(cash);continue;}if(menu!=null){g.enqueue(menu);continue;}
            if(target==null)for(Customer c:g.customers)if(c.state==CustomerState.ORDER&&(target==null||c.remainingPatience<target.remainingPatience))target=c;
            if(target!=null){Station tv=g.station("tvset0");if(tv!=null&&tv.enabled()&&tv.remaining==0){g.enqueue(tv,1);String desired=target.profile.s("tv").split(",")[0];while(!tv.form(g.channel+1).s("guid").equals(desired))g.enqueue(tv,1);}}
            if(target==null)continue;
            Station microwave=g.station("cupcake0");if(g.hand==null&&microwave!=null&&microwave.enabled()&&microwave.cookies>0&&target.remainingPatience<target.profile.f("patience",20)*3){g.enqueue(microwave,-1);g.enqueue(target);continue;}
            if(g.hand!=null){Cake hand=g.hand;int i=hand.layers.size()-1;Layer top=hand.layers.get(i),want=target.order.layers.get(i);
                if(top.frost<0){Station base=null;for(Station s:g.stations)if(s.kind.equals("Froster")&&s.cake!=null&&s.cake.layers.size()<target.order.layers.size())base=s;if(base!=null){want=target.order.layers.get(1);check(base.form(want.frost)!=null,"The second tier must use a froster with its requested color");g.enqueue(base,want.frost);}else{Station s=formStation(g,"Froster",want.frost);check(s!=null,"Order frosting must be available");g.enqueue(s,want.frost);}}
                else if(hand.layers.size()<target.order.layers.size()){Layer next=target.order.layers.get(hand.layers.size());Station froster=formStation(g,"Froster",next.frost);check(froster!=null,"Layer assembly must happen on a tray that offers the second tier's frosting");g.enqueue(froster,-1);}
                else if(want.decor>=0&&top.decor<0){Station s=formStation(g,"Decoration",want.decor);check(s!=null,"Order decoration must be available");g.enqueue(s,want.decor);}
                else g.enqueue(target);
            }else{boolean working=false;for(Station s:g.stations)if(s.remaining>0&&(s.kind.equals("CakeOven")||s.kind.equals("Froster")||s.kind.equals("Decoration")))working=true;if(working)continue;Station pending=null,base=null;for(Station s:g.stations)if(s.cake!=null&&s.remaining==0){if(s.kind.equals("Froster")&&s.cake.frosted()&&s.cake.layers.size()<target.order.layers.size())base=s;else pending=s;}if(pending!=null)g.enqueue(pending,-1);else{Layer next=target.order.layers.get(base==null?0:base.cake.layers.size());Station oven=formStation(g,"CakeOven",next.shape);if(oven!=null)g.enqueue(oven,next.shape);}}
        }
        check(g.finished,"Month "+number+" must finish after closing and customer cleanup");
        check(g.won,"Month "+number+" should be reachable with upgraded equipment; money="+g.money+" goal="+g.level.goal+" lost="+g.lost);
        System.out.println("Month "+number+": earned="+g.money+" goal="+g.level.goal+" served="+g.served+" lost="+g.lost);
    }
    public static void main(String[] args)throws Exception{File root=new File(args[0]);GameData data=new GameData(path->new FileInputStream(new File(root,path)));check(data.levels.size()==48&&data.profiles.size()==41,"All original career/customer definitions must load");core(data);machineClicks(data);equipment(data);nativeTiming(data);queueTiming(data);for(int month=1;month<=48;month++)playMonth(data,month);System.out.println("PASS: config loading, native starting stock, direct machine body/Form distinctions, tray tier assembly, independent customer selection, native patience/tips/penalties, one-shot TV broadcasts, oven recycling, queued arrival attempts, wrong-cake rejection, pause, path graph, original upgrade application, cupcake batch/refill, and 48-month simulation. Later months use fully upgraded equipment and automated input; this does not establish human difficulty, affordable career progression, or original runtime parity.");}
}
