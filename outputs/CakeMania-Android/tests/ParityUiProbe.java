package local.cakemania;

import android.content.Context;
import android.graphics.*;
import android.os.Bundle;
import java.io.*;
import java.lang.reflect.Method;
import java.util.Collections;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/** Checks original artwork and input ownership at the visible native coordinates. */
public final class ParityUiProbe extends android.app.Instrumentation {
    private Context context;
    private MainActivity activity;
    private GameView view;
    private AssetStore assets;
    private int checks;
    @Override public void onCreate(Bundle args){super.onCreate(args);Bundle result=new Bundle();try{probe();result.putString("stream","PASS: "+checks+" native HUD, clock, wheel, arrow and cash geometry checks");finish(-1,result);}catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}}
    private void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private Bitmap draw(String method,Class<?>[] types,Object...args)throws Exception {Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);Method m=GameView.class.getDeclaredMethod(method,types);m.setAccessible(true);Object[] all=new Object[args.length+1];all[0]=new Canvas(b);System.arraycopy(args,0,all,1,args.length);m.invoke(view,all);return b;}
    private void save(Bitmap b,String name)throws Exception {try(FileOutputStream out=new FileOutputStream(new File(context.getFilesDir(),"parity-"+name+".png"))){b.compress(Bitmap.CompressFormat.PNG,100,out);}}
    private void opaqueMatch(Bitmap actual,Bitmap source,int x,int y,String why){int n=0;for(int yy=0;yy<source.getHeight();yy++)for(int xx=0;xx<source.getWidth();xx++)if((source.getPixel(xx,yy)>>>24)==255&&x+xx>=0&&y+yy>=0&&x+xx<800&&y+yy<600){check(actual.getPixel(x+xx,y+yy)==source.getPixel(xx,yy),why);n++;}check(n>20,why+" needs opaque source pixels");}
    private void probe()throws Exception {
        context=getTargetContext();assets=new AssetStore(context);GameData data=new GameData(p->context.getAssets().open(p));activity=new MainActivity();activity.data=data;activity.screen="game";activity.lives=4;activity.game=new GameEngine(data,data.level(1),Collections.emptyMap(),7);activity.game.suppressArrivals=true;view=new GameView(context,activity,assets);view.rebuildControls();GameEngine g=activity.game;
        Bitmap hud=draw("drawHud",new Class<?>[]{Canvas.class,GameEngine.class},g);save(hud,"hud");opaqueMatch(hud,assets.image("IMAGE_BUTTON_MENU"),6,556,"Original Menu button must retain its authored size and bottom-left position");
        check("pause".equals(view.gameControlAt(67,573)),"The pictured Menu must open pause");check(!"pause".equals(view.gameControlAt(745,25)),"An invisible prototype Pause target must not remain over the room");
        for(int x=252;x<285;x++)for(int y=568;y<594;y++)check(hud.getPixel(x,y)==assets.image("IMAGE_HUD").getPixel(x,y-551),"January must leave a clear gap before Cash");
        Bitmap clock=draw("drawClock",new Class<?>[]{Canvas.class,GameEngine.class},g);save(clock,"clock-start");opaqueMatch(clock,assets.image("IMAGE_CLOCK_RULER"),720,39,"Opening clock hand must point to twelve at its native anchor");
        g.elapsed=g.level.duration/4;Bitmap quarter=draw("drawClock",new Class<?>[]{Canvas.class,GameEngine.class},g);save(quarter,"clock-quarter");int changedRight=0,changedLeft=0;Bitmap face=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);new Canvas(face).drawBitmap(assets.image("IMAGE_CLOCK"),665,-17,null);
        for(int y=69;y<80;y++)for(int x=690;x<760;x++)if(quarter.getPixel(x,y)!=face.getPixel(x,y)){if(x>732)changedRight++;if(x<718)changedLeft++;}check(changedRight>40&&changedLeft<20,"After a quarter shift the hand must move clockwise toward three, using this month's duration");g.elapsed=0;
        Station oven=g.station("cakeoven0");oven.total=5;oven.remaining=4;Bitmap wheel=draw("drawProcessingWheel",new Class<?>[]{Canvas.class,Station.class},oven);Bitmap expected=Bitmap.createBitmap(30,30,Bitmap.Config.ARGB_8888);new Canvas(expected).drawBitmap(assets.frame("IMAGE_READYCIRCLE",1,16,12),null,new RectF(0,0,30,30),new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG));opaqueMatch(wheel,expected,(int)(oven.x+oven.w/2-15),(int)(oven.y+oven.h/2-15),"Processing must show recovered wheel frame twelve after one fifth of production");save(wheel,"wheel");oven.remaining=0;
        activity.tutorial=new TutorialController();Node lesson=data.readConfig("tutorialscreen/sequence0.xml");activity.tutorial.start(lesson,(id,order)->{});Bitmap arrow=draw("drawTutorialOverlays",new Class<?>[]{Canvas.class});save(arrow,"arrow");
        // The first arrow targets the oven's square button at (475,140).
        // Its tip is below its shaft; the former clockwise rotation pointed at the wall.
        check((arrow.getPixel(475,119)>>>24)>100&&(arrow.getPixel(457,100)>>>24)<100,"The tutorial arrow must point down toward the square cake button");
        activity.tutorial=null;Customer front=new Customer(1,0,data.profiles.get(g.arrivals.get(0).s("guid")),g.arrivals.get(0)),rear=new Customer(2,1,front.profile,g.arrivals.get(1));g.customers.add(front);g.customers.add(rear);front.state=CustomerState.CASH;front.departureFrame=-1;view.rebuildControls();Node p=g.customerPoints.get(0);float x=p.f("x_money",0),y=p.f("y_money",0);
        check("customer:1".equals(view.gameControlAt(x+16,y-5)),"Visible money must collect the departed customer's payment");check(view.hitsCustomer(front,x+45,y+24),"Cash hit area retains native 50x50 bounds around its 40x40 drawing");check(!view.hitsCustomer(front,139,445),"The departed body must not retain an invisible customer target");check("customer:2".equals(view.gameControlAt(131,378)),"Cash must not prevent selecting the exposed rear guest");
        Bitmap hidden=draw("drawCustomer",new Class<?>[]{Canvas.class,Customer.class},front);int opaque=0;for(int yy=0;yy<600;yy++)for(int xx=0;xx<800;xx++)if(hidden.getPixel(xx,yy)!=0)opaque++;check(opaque==0,"A served customer must not remain idle after the departure puff completes");
        Bitmap cash=draw("drawOrder",new Class<?>[]{Canvas.class,Customer.class},front);save(cash,"cash");check((cash.getPixel((int)x+42,(int)y)>>>24)==0,"Cash label and unscaled money artwork must not extend beyond the original 40x40 drawing");front.cashCollected=true;view.rebuildControls();check(!view.hitsCustomer(front,x+16,y-5),"Collected money cannot receive a second payment tap");
        save(draw("drawGame",new Class<?>[]{Canvas.class}),"room");
    }
}
