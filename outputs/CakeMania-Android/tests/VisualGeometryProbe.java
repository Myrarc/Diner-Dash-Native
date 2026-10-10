package local.cakemania;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import java.io.File;
import java.io.FileOutputStream;
import java.lang.reflect.Method;
import java.util.Collections;
import static local.cakemania.GameEngine.*;
import static local.cakemania.GameData.*;

/** Uses the installed renderer and asset pixels, rather than calculated tap centers alone. */
public final class VisualGeometryProbe extends android.app.Instrumentation {
    private Context context;
    private AssetStore assets;
    private MainActivity activity;
    private GameView view;
    private Method drawStation,drawGame;
    @Override public void onCreate(android.os.Bundle arguments){
        super.onCreate(arguments);android.os.Bundle result=new android.os.Bundle();
        try { probe();result.putString("stream","PASS: oven states, four shapes, four frosting strips, visible customer hits and counter depth");finish(-1,result); }
        catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}
    }
    private void check(boolean value,String message){if(!value)throw new AssertionError(message);}
    private void save(Bitmap image,String name)throws Exception {try(FileOutputStream out=new FileOutputStream(new File(context.getFilesDir(),"visual-"+name+".png"))){image.compress(Bitmap.CompressFormat.PNG,100,out);}}
    private Bitmap room()throws Exception {Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawGame.invoke(view,new Canvas(b));return b;}
    private Bitmap machine(Station station)throws Exception {Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);drawStation.invoke(view,new Canvas(b),station);return b;}
    private Cake cake(int shape){Cake cake=new Cake();cake.layers.add(new Layer(shape,15));return cake;}
    private void probe()throws Exception {
        context=getTargetContext();assets=new AssetStore(context);GameData data=new GameData(path->context.getAssets().open(path));
        activity=new MainActivity();activity.data=data;activity.screen="game";activity.game=new GameEngine(data,data.level(1),Collections.emptyMap(),7);activity.game.suppressArrivals=true;
        view=new GameView(context,activity,assets);view.rebuildControls();
        drawStation=GameView.class.getDeclaredMethod("drawStation",Canvas.class,Station.class);drawStation.setAccessible(true);
        drawGame=GameView.class.getDeclaredMethod("drawGame",Canvas.class);drawGame.setAccessible(true);
        Station oven=null,froster=null;for(Station s:activity.game.stations){if(s.guid.equals("cakeoven0"))oven=s;if(s.guid.equals("froster1"))froster=s;}
        check(oven!=null&&froster!=null,"January equipment");
        Bitmap idle=machine(oven),matrix=Bitmap.createBitmap(4*180,2*280,Bitmap.Config.ARGB_8888);Canvas canvas=new Canvas(matrix);canvas.drawColor(0xffe4ddcb);
        float[] phases={-1,1,3.1f,3.3f,3.7f,4.5f,4.8f,5};
        for(int i=0;i<phases.length;i++){
            oven.total=5;oven.closeAt=3;oven.discardAt=4.4f;oven.freshAt=4.6f;oven.remaining=phases[i]<0?0:5-phases[i];oven.cake=i==0||i==1||i==5?null:cake(1);oven.burnt=i==5;oven.workingForm=1;
            Bitmap image=machine(oven);
            for(Node f:oven.def.children)if(f.tag.equals("Form")){
                int x=(int)(oven.x+f.f("x",0)+f.f("width",0)/2),y=(int)(oven.y+f.f("y",0)+f.f("height",0)/2);
                check((image.getPixel(x,y)>>>24)>128,"Shape must stay visible during oven phase "+phases[i]);
                check(idle.getPixel(x,y)==image.getPixel(x,y),"Cooking must not replace the shape-button artwork");
                check(("form:"+oven.guid+":"+f.i("id",0)).equals(view.gameControlAt(x,y)),"Visible shape must select its own form");
            }
            canvas.save();canvas.translate((i%4)*180-oven.x+20,(i/4)*280-oven.y+20);canvas.drawBitmap(image,0,0,null);canvas.restore();image.recycle();
        }
        save(matrix,"oven-states");oven.remaining=0;oven.cake=null;
        Bitmap frosting=Bitmap.createBitmap(4*180,280,Bitmap.Config.ARGB_8888);Canvas frostingCanvas=new Canvas(frosting);frostingCanvas.drawColor(0xffe4ddcb);int index=0;
        for(Node f:froster.def.children)if(f.tag.equals("Form")){
            int cols=f.i("count_anim_vert",1),rows=f.i("count_anim",1);Bitmap frame=assets.frame(f.s("image_anim"),cols,rows,16);
            check(frame.getWidth()>=108&&frame.getWidth()<=121&&frame.getHeight()>=145,"Frosting animation must crop a single horizontal frame");
            int x=(int)(froster.x+f.f("x",0)+f.f("width",0)/2),y=(int)(froster.y+f.f("y",0)+f.f("height",0)/2);
            check(("form:"+froster.guid+":"+f.i("id",0)).equals(view.gameControlAt(x,y)),"Visible frosting color must select its own form");
            froster.cake=cake(1);froster.cake.layers.get(0).frost=f.i("id",0);froster.workingForm=f.i("id",0);froster.total=5;froster.remaining=2.5f;
            Bitmap image=machine(froster);frostingCanvas.save();frostingCanvas.translate(index*180-froster.x+15,160-froster.y);frostingCanvas.drawBitmap(image,0,0,null);frostingCanvas.restore();index++;image.recycle();
        }
        save(frosting,"froster-states");froster.remaining=0;froster.cake=null;
        Customer customer=new Customer(1,0,data.profiles.get(activity.game.arrivals.get(0).s("guid")),activity.game.arrivals.get(0));
        activity.game.customers.add(customer);view.rebuildControls();
        check("customer:1".equals(view.gameControlAt(139,445)),"A visible customer torso must receive the menu tap");
        check("customer:1".equals(view.gameControlAt(172,551)),"Native normal-sprite rectangle must also accept the leg/paper area");
        Customer rear=new Customer(2,1,customer.profile,activity.game.arrivals.get(1));activity.game.customers.add(rear);view.rebuildControls();
        check("customer:2".equals(view.gameControlAt(131,378)),"Exposed rear guest can be selected without serving the front guest");
        check("customer:1".equals(view.gameControlAt(164,483)),"The front guest owns the visible overlapping torso");
        activity.game.customers.clear();activity.game.customers.add(rear);activity.game.customers.add(customer);view.rebuildControls();
        check("customer:1".equals(view.gameControlAt(139,446)),"A refilled front slot must stay clickable after the previous guest leaves");
        Bitmap stock=room();save(stock,"stock-room");activity.game.customers.clear();view.rebuildControls();Bitmap noCustomers=room();
        Node last=activity.game.level.environment.first("RenderBackground").children.get(3);Bitmap foreground=assets.image(last.s("img"));int foregroundPixels=0;
        for(int y=0;y<foreground.getHeight()&&y+last.i("y",0)<600;y++)for(int x=0;x<foreground.getWidth()&&x+last.i("x",0)<800;x++)if((foreground.getPixel(x,y)>>>24)==255){int xx=x+last.i("x",0),yy=y+last.i("y",0);check(stock.getPixel(xx,yy)==noCustomers.getPixel(xx,yy),"Native foreground must cover customer sprites");foregroundPixels++;}
        check(foregroundPixels>300,"Foreground checked using opaque original artwork");
        activity.game.x=440;activity.game.y=400;Bitmap behind=room();save(behind,"jill-behind-counter");
        activity.game.x=-1000;Bitmap empty=room();Bitmap counter=assets.image("IMAGE_LEVEL1_BG2");int checked=0;
        for(int y=319;y<Math.min(600,319+counter.getHeight());y++)for(int x=396;x<Math.min(800,396+counter.getWidth());x++)if((counter.getPixel(x-396,y-319)>>>24)==255){check(behind.getPixel(x,y)==empty.getPixel(x,y),"Opaque center counter must cover Jill at y=400");checked++;}
        check(checked>1000,"Counter occlusion checked against actual opaque artwork");activity.game.x=460;activity.game.y=475;activity.game.hand=cake(1);save(room(),"jill-front-carry");
    }
}
