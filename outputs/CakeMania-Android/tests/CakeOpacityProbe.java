package local.cakemania;

import android.content.Context;
import android.graphics.*;
import java.io.*;
import java.lang.reflect.Method;
import java.util.Collections;
import static local.cakemania.GameEngine.*;
import static local.cakemania.GameData.*;

/** Order bubbles must not make subsequent cakes or room sprites translucent. */
public final class CakeOpacityProbe extends android.app.Instrumentation {
    private int checks;
    private void check(boolean value,String message){if(!value)throw new AssertionError(message);checks++;}
    private Cake cake(int shape){Cake cake=new Cake();cake.layers.add(new Layer(shape,15));return cake;}
    private Bitmap render(Method method,GameView view,Object... arguments)throws Exception {
        Bitmap image=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);
        Object[] args=new Object[arguments.length+1];args[0]=new Canvas(image);System.arraycopy(arguments,0,args,1,arguments.length);
        method.invoke(view,args);return image;
    }
    private void save(Context context,Bitmap image,String name)throws Exception {
        try(FileOutputStream out=new FileOutputStream(new File(context.getFilesDir(),"opacity-"+name+".png"))){image.compress(Bitmap.CompressFormat.PNG,100,out);}
    }
    @Override public void onCreate(android.os.Bundle arguments){super.onCreate(arguments);android.os.Bundle result=new android.os.Bundle();
        try {probe();result.putString("stream","PASS: "+checks+" checks; original opaque cake interiors, repeated order-bubble frames, oven/carry rendering and translucent panel pixels");finish(-1,result);}
        catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}
    }
    private void probe()throws Exception {
        Context context=getTargetContext();AssetStore assets=new AssetStore(context);GameData data=new GameData(path->context.getAssets().open(path));
        MainActivity activity=new MainActivity();activity.data=data;activity.screen="game";activity.game=new GameEngine(data,data.level(1),Collections.emptyMap(),7);activity.game.suppressArrivals=true;
        GameView fresh=new GameView(context,activity,assets),view=new GameView(context,activity,assets);
        Method drawGame=GameView.class.getDeclaredMethod("drawGame",Canvas.class),drawStation=GameView.class.getDeclaredMethod("drawStation",Canvas.class,Station.class),drawCake=GameView.class.getDeclaredMethod("cake",Canvas.class,Cake.class,float.class,float.class,float.class),drawJill=GameView.class.getDeclaredMethod("drawJill",Canvas.class),panel=GameView.class.getDeclaredMethod("panel",Canvas.class,float.class,float.class,float.class,float.class,int.class);
        for(Method m:new Method[]{drawGame,drawStation,drawCake,drawJill,panel})m.setAccessible(true);
        Station oven=activity.game.station("cakeoven0");oven.cake=cake(1);oven.remaining=0;
        Customer customer=new Customer(1,0,data.profiles.get(activity.game.arrivals.get(0).s("guid")),activity.game.arrivals.get(0));customer.state=CustomerState.ORDER;customer.order.layers.clear();customer.order.layers.add(new Layer(1,15));activity.game.customers.add(customer);
        // Capture the freshly ready oven cake after the real order panel ran once.
        render(drawGame,view).recycle();Bitmap room=render(drawGame,view);save(context,room,"room");room.recycle();
        Bitmap expected=render(drawStation,fresh,oven),actual=render(drawStation,view,oven);save(context,expected,"oven-reference");save(context,actual,"oven-after-orders");
        // Preserve the authored transparency of the panel itself.
        Bitmap bubble=render(panel,view,10f,10f,100f,100f,0xebffffef);check(Color.alpha(bubble.getPixel(50,50))==235,"Order bubble must keep its intended opacity");bubble.recycle();
        for(int shape=0;shape<8;shape++){
            Bitmap base=assets.image(data.cakes.get(shape).first("CakeBase").s("image")),drawn=render(drawCake,view,cake(shape),200f,200f,1f);
            int interiors=0;for(int y=0;y<base.getHeight();y++)for(int x=0;x<base.getWidth();x++)if(Color.alpha(base.getPixel(x,y))==255){
                int alpha=Color.alpha(drawn.getPixel(200-base.getWidth()/2+x,200-base.getHeight()+y));
                // Odd-width images start at a half pixel; use even-width shapes for exact texel checks.
                if(base.getWidth()%2==0){check(alpha==255,"Cake shape "+shape+" interior must remain opaque after an order bubble; got alpha "+alpha);interiors++;}
            }
            if(base.getWidth()%2==0)check(interiors>5000,"Check the original cake interior, not just an outline");
            drawn.recycle();oven.cake=cake(shape);
            expected.recycle();actual.recycle();expected=render(drawStation,fresh,oven);actual=render(drawStation,view,oven);
            check(expected.sameAs(actual),"Ready oven cake and cabinet must match clean rendering for shape "+shape);
            // The next frame must not depend on the previous customer's order panel.
            render(drawGame,view).recycle();
        }
        expected.recycle();actual.recycle();
        activity.game.hand=cake(1);activity.game.x=460;activity.game.y=475;Bitmap carry=render(drawGame,view);save(context,carry,"carry");carry.recycle();
        Bitmap cleanCarry=render(drawJill,fresh),afterOrders=render(drawJill,view);check(cleanCarry.sameAs(afterOrders),"Jill and her carried cake must retain their authored pixels after orders");cleanCarry.recycle();afterOrders.recycle();
        for(int color:new int[]{0xedfff0cf,0xe8fff0cf,0xf4fff0cf,0xffa62039}){
            render(panel,view,10f,10f,100f,100f,color).recycle();
            Bitmap clean=render(drawCake,fresh,cake(1),200f,200f,1f),after=render(drawCake,view,cake(1),200f,200f,1f);
            check(clean.sameAs(after),"UI panel color must not alter subsequent cake pixels");clean.recycle();after.recycle();
        }
    }
}
