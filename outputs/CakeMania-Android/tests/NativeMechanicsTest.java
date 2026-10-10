package local.cakemania;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/** Focused regression checks for behavior recovered from the native binary. */
public final class NativeMechanicsTest {
    private static void check(boolean ok,String message){if(!ok)throw new AssertionError(message);}
    private static GameData data(String root)throws Exception{return new GameData(path->new FileInputStream(new File(root,path)));}
    private static Map<String,Integer> fullUpgrades(Level level){Map<String,Integer> result=new HashMap<>();for(Node n:level.shop.children)if(n.i("upgr_step",0)>result.getOrDefault(n.s("guid"),0))result.put(n.s("guid"),n.i("upgr_step",0));return result;}
    private static void advance(GameEngine g,float seconds){for(int i=0;i<Math.ceil(seconds*60);i++)g.tick(1f/60);}
    private static void drain(GameEngine g){for(int i=0;i<100000&&!g.queue.isEmpty();i++)g.tick(1f/60);check(g.queue.isEmpty(),"queued action did not complete");}
    private static Customer fixture(GameData d,GameEngine g,String guid){Node p=d.profiles.get(guid).copy();p.attrs.put("patience","0");return new Customer(1,0,p,g.arrivals.get(0));}

    private static void nativeGeometryAndWeights(GameData d)throws Exception{
        Level level=d.level(1);GameEngine upgraded=new GameEngine(d,level,fullUpgrades(level),9);
        GameEngine stock=new GameEngine(d,level,Collections.emptyMap(),9);stock.suppressArrivals=true;
        check(stock.speed()==200f,"native speed 2 moves two pixels every 10 ms, independent of display refresh rate");
        stock.enqueue(stock.station("cakeoven0"),-1);
        for(int i=0;i<30;i++)stock.tick(.01f);
        check(stock.queue.isEmpty()&&stock.x==390f&&stock.y==297f,"the 59 pixel walk from the start to the oven must finish in 0.30 seconds");
        check(upgraded.station("tvset0").x==140f,"merged TV upgrade geometry must refresh the hit/render rectangle");
        Method choose=GameEngine.class.getDeclaredMethod("choose",String.class,List.class,int.class);choose.setAccessible(true);
        @SuppressWarnings("unchecked") List<Integer> available=Arrays.asList(7,1,2,3);Set<Integer> selected=new HashSet<>();
        for(int i=0;i<4096;i++)selected.add((Integer)choose.invoke(upgraded,"1,90;",available,1));
        check(selected.contains(7)&&selected.contains(2)&&selected.contains(3),"missing native candidate weights must receive the recovered default residue");
    }

    private static void nativeDeferredOrder(GameData d){
        GameEngine g=new GameEngine(d,d.level(1),Collections.emptyMap(),11);g.suppressArrivals=true;
        Customer c=g.addCustomer(g.arrivals.get(0).copy());g.enqueue(c);drain(g);
        check(c.state==CustomerState.READING&&c.order.layers.isEmpty(),"handing out a menu must enter the native reading state before an order exists");
        g.tick(1f/60);check(c.state==CustomerState.READING&&!c.order.layers.isEmpty(),"native order generation must run on the first reading tick while the menu is active");
        List<Layer> generated=new ArrayList<>(c.order.layers);advance(g,c.profile.f("menu",5)+.1f);
        check(c.state==CustomerState.ORDER&&c.order.layers.equals(generated),"menu completion must retain the order generated during reading");
    }

    private static void nativeCookieShelves(GameData d){
        GameEngine g=new GameEngine(d,d.level(1),fullUpgrades(d.level(1)),13);g.suppressArrivals=true;Station oven=g.station("cupcake0");check(oven!=null&&oven.cookies==4,"enabled CookieOven must expose four independent products");
        g.enqueue(oven,-2);drain(g);check(g.hand!=null&&!oven.cookieStock[0]&&oven.cookies==3,"FormShelf id zero must pick only its own cupcake");g.hand=null;
        for(int i=1;i<4;i++){g.enqueue(oven,-2-i);drain(g);g.hand=null;}
        check(oven.cookies==0&&oven.remaining==0&&oven.cookieRefillPending,"last shelf pickup must defer the native refill start until the following update");g.tick(.01f);check(oven.remaining==oven.total&&oven.remaining>0&&!oven.cookieRefillPending,"the next update must start, but not advance, the refill timer");advance(g,oven.remaining+.5f);check(oven.cookies==0&&oven.cookieDoorRemaining>0,"refill must include the one-second door phase");advance(g,1.1f);check(oven.cookies==4&&oven.cookieDoorRemaining==0,"door phase must allocate all four independent shelf products");
        oven.setCookieStock(0);oven.remaining=.25f;oven.total=20;oven.cookieDoorRemaining=0;g.tick(.25f);check(oven.remaining==0&&oven.cookieDoorRemaining==0,"an exact refill timer expiry must remain closed; native opens the door only after a strict underflow");oven.remaining=.01f;g.tick(.05f);check(oven.cookieDoorRemaining>.94f&&oven.cookieDoorRemaining<.96f,"a near-expiry timer must open the native one-second door and consume this frame's elapsed time");
    }

    private static void nativeVisualAndEvents(GameData d){
        GameEngine g=new GameEngine(d,d.level(1),Collections.emptyMap(),17);g.suppressArrivals=true;Customer c=fixture(d,g,"boy");
        for(Iterator<Node> it=c.profile.children.iterator();it.hasNext();)if(it.next().tag.equals("Image"))it.remove();
        Node normal=new Node("Image");normal.attrs.put("id","ID_NORMAL");Node normalSequence=new Node("Sequence");normalSequence.attrs.put("frames","0,1,2,3");normal.children.add(normalSequence);Node firstTiming=new Node("Timing");firstTiming.attrs.put("framestart","0");firstTiming.attrs.put("frameend","2");firstTiming.attrs.put("time",".2");normal.children.add(firstTiming);Node secondTiming=new Node("Timing");secondTiming.attrs.put("framestart","2");secondTiming.attrs.put("frameend","4");secondTiming.attrs.put("time",".8");normal.children.add(secondTiming);c.profile.children.add(normal);
        Node happy=new Node("Image");happy.attrs.put("id","ID_HAPPY");Node happySequence=new Node("Sequence");happySequence.attrs.put("frames","0");happy.children.add(happySequence);c.profile.children.add(happy);
        Node menu=new Node("Image");menu.attrs.put("id","ID_MENU");Node menuSequence=new Node("Sequence");menuSequence.attrs.put("frames","0");menu.children.add(menuSequence);c.profile.children.add(menu);c.state=CustomerState.READING;g.customers.add(c);g.tick(.01f);check(c.visualState==1,"reading customers must force the native menu visual");c.setVisual(0);c.visualFrame=1;c.visualElapsed=0;c.advanceVisual(.1f);check(c.visualFrame==1,"visual timing boundaries must use strict greater-than elapsed checks");c.advanceVisual(.01f);check(c.visualFrame==2,"the first timing segment must advance after its exact interval");c.advanceVisual(.4f);check(c.visualFrame==2,"the second timing segment must apply its own slower frame interval");c.advanceVisual(.01f);check(c.visualFrame==3,"visual timing must select the segment containing the current frame");c.setVisual(2);c.advanceVisual(.2f);check(c.visualState==0&&c.visualFrame==0,"temporary non-menu visual sequences must return to normal when their range ends");

        Node sourceProfile=d.profiles.get("boy").copy();sourceProfile.attrs.put("guid","santa");sourceProfile.attrs.put("patience","0");Node startMessage=new Node("Message");startMessage.attrs.put("xtime","atstart");sourceProfile.children.add(startMessage);Node recipientProfile=d.profiles.get("boy").copy();recipientProfile.attrs.put("guid","recipient");recipientProfile.attrs.put("patience","10");recipientProfile.attrs.put("xtrahearts","santa,1;");Customer source=new Customer(2,1,sourceProfile,g.arrivals.get(0));Customer recipient=new Customer(3,2,recipientProfile,g.arrivals.get(0));g.customers.add(source);g.customers.add(recipient);float before=recipient.remainingPatience;g.tick(.01f);check(recipient.remainingPatience>before+9,"atstart xtraheart must broadcast from the source profile GUID to every active recipient");float after=recipient.remainingPatience;g.tick(.01f);check(recipient.remainingPatience<after&&recipient.remainingPatience>after-.02f,"atstart broadcast must fire exactly once");check(recipient.visualState==2,"positive xtraheart event must select the temporary happy visual");

        GameEngine timedGame=new GameEngine(d,d.level(1),Collections.emptyMap(),18);timedGame.suppressArrivals=true;Node timedProfile=d.profiles.get("boy").copy();timedProfile.attrs.put("guid","timed");timedProfile.attrs.put("patience","0");Node timedMessage=new Node("Message");timedMessage.attrs.put("xtime","1");timedProfile.children.add(timedMessage);Node timedRecipientProfile=d.profiles.get("boy").copy();timedRecipientProfile.attrs.put("guid","timed-recipient");timedRecipientProfile.attrs.put("patience","10");timedRecipientProfile.attrs.put("xtrahearts","timed,1;");Customer timedSource=new Customer(4,0,timedProfile,timedGame.arrivals.get(0));Customer timedRecipient=new Customer(5,1,timedRecipientProfile,timedGame.arrivals.get(0));timedGame.customers.add(timedSource);timedGame.customers.add(timedRecipient);float timedBefore=timedRecipient.remainingPatience;timedGame.tick(1);check(Math.abs(timedRecipient.remainingPatience-(timedBefore-1))<.02f,"timed message must not fire at exact period equality");timedGame.tick(.01f);check(timedRecipient.remainingPatience>timedBefore+8,"timed message must fire after, and only after, strict period expiry");float timedAfter=timedRecipient.remainingPatience;timedGame.tick(.99f);check(timedRecipient.remainingPatience<timedAfter&&timedRecipient.remainingPatience>timedAfter-1.01f,"timed event elapsed must reset after firing");timedGame.tick(.02f);check(timedRecipient.remainingPatience>timedAfter+8,"timed message must recur after each strict period");

        GameEngine servedGame=new GameEngine(d,d.level(1),Collections.emptyMap(),19);servedGame.suppressArrivals=true;Node servedProfile=d.profiles.get("boy").copy();servedProfile.attrs.put("guid","served");servedProfile.attrs.put("patience","0");Node servedMessage=new Node("Message");servedMessage.attrs.put("xtime","atserved");servedProfile.children.add(servedMessage);Node servedRecipientProfile=d.profiles.get("boy").copy();servedRecipientProfile.attrs.put("guid","served-recipient");servedRecipientProfile.attrs.put("patience","100");servedRecipientProfile.attrs.put("xtrahearts","served,1;");Customer served=new Customer(6,0,servedProfile,servedGame.arrivals.get(0));served.state=CustomerState.ORDER;served.order.layers.add(new Layer(1,15));Customer servedRecipient=new Customer(7,1,servedRecipientProfile,servedGame.arrivals.get(0));servedGame.customers.add(served);servedGame.customers.add(servedRecipient);Cake servedCake=new Cake();servedCake.layers.add(new Layer(1,15));servedGame.hand=servedCake;float servedBefore=servedRecipient.remainingPatience;servedGame.enqueue(served);drain(servedGame);check(servedRecipient.remainingPatience>servedBefore+90,"atserved message must broadcast once when the order is delivered");float servedAfter=servedRecipient.remainingPatience;servedGame.enqueue(served);drain(servedGame);check(servedRecipient.remainingPatience<servedAfter&&servedRecipient.remainingPatience>servedAfter-.1f,"atserved message must not broadcast again");
    }

    private static void nativeOneShotSounds(GameData d){
        GameEngine g=new GameEngine(d,d.level(1),Collections.emptyMap(),19);g.money=g.level.goal;g.tick(.01f);g.tick(.01f);int goals=0;for(String s:g.sounds)if(s.equals("SOUND_BAKERGOALREACHED"))goals++;check(goals==1,"goal sound must latch once when the goal is reached");g.elapsed=g.level.duration;g.tick(.01f);g.tick(.01f);int closed=0;for(String s:g.sounds)if(s.equals("SOUND_CLOSED"))closed++;check(closed==1,"closing sound must latch once after closing time");
        GameEngine ovenGame=new GameEngine(d,d.level(1),Collections.emptyMap(),20);ovenGame.suppressArrivals=true;Station oven=ovenGame.station("cakeoven0");ovenGame.enqueue(oven,1);drain(ovenGame);advance(ovenGame,4.7f);int doors=0;for(String s:ovenGame.sounds)if(s.equals("SOUND_CAKEOVEN_DOOROPEN"))doors++;check(doors==1&&oven.cake!=null,"cake oven door sound must fire once when the fresh cake phase creates the cake");advance(ovenGame,2);doors=0;for(String s:ovenGame.sounds)if(s.equals("SOUND_CAKEOVEN_DOOROPEN"))doors++;check(doors==1,"cake oven door sound must not repeat while the cake remains in place");
    }

    private static void nativeAngryTransition(GameData d){
        GameEngine g=new GameEngine(d,d.level(1),Collections.emptyMap(),21);g.suppressArrivals=true;Node profile=d.profiles.get("boy").copy();profile.attrs.put("patience","10");Customer c=new Customer(1,0,profile,g.arrivals.get(0));c.state=CustomerState.ORDER;g.customers.add(c);
        g.tick(10);check(c.hearts==2&&!g.sounds.contains("SOUND_CUSTOMER_ANGRY"),"the native angry transition must wait until the customer reaches one heart");g.tick(10);int angry=0;for(String sound:g.sounds)if(sound.equals("SOUND_CUSTOMER_ANGRY"))angry++;check(c.hearts==1&&c.visualState==3&&angry==1,"crossing into exactly one heart must set the bored/angry visual and emit one angry sound");g.tick(.1f);angry=0;for(String sound:g.sounds)if(sound.equals("SOUND_CUSTOMER_ANGRY"))angry++;check(c.hearts==1&&c.visualState==3&&angry==1,"remaining at one heart must not repeat the angry sound");c.remainingPatience+=10;g.tick(.01f);check(c.hearts==2&&c.visualState==0,"recovering above one heart must clear the angry visual");c.remainingPatience-=10;g.tick(.01f);angry=0;for(String sound:g.sounds)if(sound.equals("SOUND_CUSTOMER_ANGRY"))angry++;check(c.hearts==1&&angry==2,"a later native transition back into one heart may emit once again after recovery");
    }

    public static void main(String[] args)throws Exception{GameData d=data(args[0]);nativeGeometryAndWeights(d);nativeDeferredOrder(d);nativeCookieShelves(d);nativeVisualAndEvents(d);nativeOneShotSounds(d);nativeAngryTransition(d);System.out.println("PASS: native geometry, missing candidate weights, deferred orders, cookie FormShelf/door refill, independent customer visual/event state, angry transitions, and one-shot goal/closing sounds");}
}
