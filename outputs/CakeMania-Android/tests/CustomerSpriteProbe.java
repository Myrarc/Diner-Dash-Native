package local.cakemania;

import android.content.Context;
import android.graphics.*;
import android.os.Bundle;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/** Native row mapping, complete idle cycles and hovering guests against real APK pixels. */
public final class CustomerSpriteProbe extends android.app.Instrumentation {
    private Context context;
    private AssetStore assets;
    private MainActivity activity;
    private GameView view;
    private Method customerFrame,customerBounds,drawGame,drawOrder;
    private int checks;
    @Override public void onCreate(Bundle arguments){super.onCreate(arguments);Bundle result=new Bundle();try{probe();result.putString("stream","PASS: "+checks+" customer row, idle-cycle, hover, overlap, bubble and left-heart checks");finish(-1,result);}catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}}
    private void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private Method method(String name,Class<?>...types)throws Exception {Method m=GameView.class.getDeclaredMethod(name,types);m.setAccessible(true);return m;}
    private Node image(Customer c,String id){for(Node n:c.profile.children)if(n.s("id").equals(id))return n;throw new AssertionError(id);}
    private Bitmap frame(Customer c,Node image)throws Exception {return (Bitmap)customerFrame.invoke(view,c,image);}
    private RectF bounds(Customer c,Node image)throws Exception {return (RectF)customerBounds.invoke(view,c,image,frame(c,image));}
    private void save(Bitmap b,String name)throws Exception {try(FileOutputStream out=new FileOutputStream(new File(context.getFilesDir(),"customers-"+name+".png"))){b.compress(Bitmap.CompressFormat.PNG,100,out);}}
    private Bitmap room()throws Exception {Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawGame.invoke(view,new Canvas(b));return b;}
    private void probe()throws Exception {
        context=getTargetContext();assets=new AssetStore(context);GameData data=new GameData(p->context.getAssets().open(p));activity=new MainActivity();activity.data=data;activity.screen="game";activity.game=new GameEngine(data,data.level(1),Collections.emptyMap(),7);activity.game.suppressArrivals=true;view=new GameView(context,activity,assets);
        customerFrame=method("customerFrame",Customer.class,Node.class);customerBounds=method("customerSpriteBounds",Customer.class,Node.class,Bitmap.class);drawGame=method("drawGame",Canvas.class);drawOrder=method("drawOrder",Canvas.class,Customer.class);
        GameEngine g=activity.game;Customer front=new Customer(1,0,data.profiles.get("delivery"),g.arrivals.get(0)),angel=new Customer(2,1,data.profiles.get("cupid"),g.arrivals.get(0));g.customers.add(front);g.customers.add(angel);view.rebuildControls();save(room(),"mixed-queue-start");
        String[] ids={"ID_NORMAL","ID_MENU","ID_HAPPY","ID_BORED","ID_EATING"};
        for(Node profile:data.profiles.values())for(int state=0;state<ids.length;state++){
            Customer c=new Customer(3,0,profile,g.arrivals.get(0));c.visualState=state;Node n=image(c,ids[state]);int[] sequence=ints(n.first("Sequence").s("frames"));
            for(int index=0;index<sequence.length;index++){
                c.visualFrame=index;Bitmap expected=assets.frame(n.s("img"),n.i("cols",1),n.i("rows",1),n.i("rows",1)-1-sequence[index]);
                check(frame(c,n).sameAs(expected),profile.s("guid")+" "+ids[state]+" entry "+index+" must use the native reversed sheet row");
            }
        }
        for(Node profile:data.profiles.values()){
            Customer c=new Customer(3,0,profile,g.arrivals.get(0));Node n=image(c,"ID_NORMAL");Set<Integer> rows=new HashSet<>();int[] sequence=ints(n.first("Sequence").s("frames"));Set<Integer> expected=new HashSet<>();for(int authored:sequence)expected.add(n.i("rows",1)-1-authored);int wraps=0,previous=0;
            for(int tick=0;tick<2400&&wraps<2;tick++){
                c.advanceVisual(.01f);if(c.visualFrame<previous)wraps++;previous=c.visualFrame;
                rows.add(n.i("rows",1)-1-sequence[c.visualFrame]);
                check(frame(c,n).sameAs(assets.frame(n.s("img"),n.i("cols",1),n.i("rows",1),n.i("rows",1)-1-sequence[c.visualFrame])),"Idle playback must retain the authored pose at every tick");
            }
            check(wraps==2&&rows.equals(expected)&&rows.size()>1,profile.s("guid")+" must play all idle poses over two complete cycles");
        }
        Node normal=image(angel,"ID_NORMAL");RectF start=bounds(angel,normal);
        check(start.left==97&&start.top==379&&start.width()==58&&start.height()==99,"Cupid must hover forty pixels above the second queue floor anchor, with authored correction and integer bounds");
        check("customer:2".equals(view.gameControlAt(131,392)),"The exposed hovering angel head must receive its own menu tap");
        check("customer:1".equals(view.gameControlAt(139,450)),"The front delivery customer still owns his overlapping torso");
        for(int i=0;i<150;i++)angel.advanceVisual(.01f);RectF high=bounds(angel,normal);check(Math.abs(high.top-369)<=1,"Half-period must raise Cupid another ten pixels using the native squared curve");save(room(),"mixed-queue-high");
        angel.state=CustomerState.CASH;angel.advanceVisual(.4f);check(bounds(angel,normal).equals(high),"The departure effect must retain the last hovering position after the body disappears");angel.state=CustomerState.WAIT_MENU;
        Bitmap orders=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawOrder.invoke(view,new Canvas(orders),front);Node point=g.customerPoints.get(0);int x=point.i("x_money",0),y=point.i("y_money",0),pixels=0;
        for(int yy=y-60;yy<y-10;yy++)for(int xx=x-23;xx<x+71;xx++)if(orders.getPixel(xx,yy)!=0)pixels++;
        check(pixels==0,"Waiting for a menu must not add a synthetic speech bubble or Menu? text");
        verifyHearts(data);
        check(!view.hitsCustomer(front,x+50,y-50),"Removed waiting speech bubbles must not retain an invisible menu target");
        front.state=CustomerState.READING;check(!view.hitsCustomer(front,x+50,y-50),"A reading customer has no order bubble target yet");front.state=CustomerState.ORDER;check(view.hitsCustomer(front,x+50,y-50),"The actual order bubble remains selectable after reading");front.state=CustomerState.WAIT_MENU;
        save(room(),"mixed-queue-final");
    }
    private void verifyHearts(GameData data)throws Exception {
        GameEngine original=activity.game;Bitmap heart=assets.image("IMAGE_HEART");check(heart.getWidth()==23&&heart.getHeight()==19,"Hearts retain the native intrinsic artwork size");
        // Native 0040d9d0 divides the authored first/last money-x delta by
        // the queue length before multiplying by the slot. These fixture
        // anchors also ensure hovering bodies never move their heart rows.
        int[] depthSteps={8,9,7,12};double[] heartOffsets={0,0,13.333334,20,26.666667,33.333334,40};
        int[][] moneyY={{496,425,356,288,216},{488,415,345,280,221},{461,381,311,246,181},{471,401,331,266,201}};
        for(int bakery=0;bakery<4;bakery++){
            GameEngine g=new GameEngine(data,data.level(1+bakery*12),Collections.emptyMap(),7);activity.game=g;
            for(int slot=0;slot<5;slot++)for(int count=0;count<=5;count++){
                Customer c=new Customer(4,slot,data.profiles.get("cupid"),g.arrivals.get(0));c.hearts=count;
                Bitmap expected=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);Canvas canvas=new Canvas(expected);
                for(int index=count+1;index>=2;index--)canvas.drawBitmap(heart,(int)(30-depthSteps[bakery]*slot+heartOffsets[index]),moneyY[bakery][slot]-30,null);
                for(CustomerState state:new CustomerState[]{CustomerState.WAIT_MENU,CustomerState.READING}){
                    c.state=state;Bitmap actual=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawOrder.invoke(view,new Canvas(actual),c);
                    check(actual.sameAs(expected),"Bakery "+(bakery+1)+" slot "+slot+" hearts "+count+" must overlap on the left at native anchors, without faded empty hearts or hover offsets");
                    actual.recycle();
                }
                c.hoverY=50;Bitmap high=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawOrder.invoke(view,new Canvas(high),c);check(high.sameAs(expected),"Heart placement remains fixed while Cupid bobs");high.recycle();expected.recycle();
            }
        }
        activity.game=original;
    }
}
