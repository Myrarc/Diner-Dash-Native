package local.cakemania;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import java.io.FileOutputStream;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Collections;

/** Instrumentation against the installed APK's real Android bitmap cache and renderer. */
public final class AndroidAssetProbe extends android.app.Instrumentation {
    @Override public void onCreate(android.os.Bundle arguments) {
        super.onCreate(arguments);
        android.os.Bundle result=new android.os.Bundle();
        try { runProbe(getTargetContext());result.putString("stream","PASS: cache, volumes, 64 Jill and 615 customer renders");finish(-1,result); }
        catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}
    }
    private void runProbe(Context context) throws Exception {
        AssetStore assets=new AssetStore(context);
        Bitmap first=assets.frame("IMAGE_MMENU_FIRE1",10,1,0);
        if(first!=assets.frame("IMAGE_MMENU_FIRE1",10,1,10))
            throw new AssertionError("An animation loop must reuse the existing cropped frame");
        if(assets.frame("IMAGE_MMENU_FIRE1",10,1,-1)!=assets.frame("IMAGE_MMENU_FIRE1",10,1,9))
            throw new AssertionError("Reverse animation frames must use the same normalized cache key");
        GameAudio audio=new GameAudio(context,assets);
        try {
            audio.setVolumes(-1,2);
            if(audio.musicVolume!=0||audio.soundVolume!=1)throw new AssertionError("Volume bounds");
            audio.setVolumes(.35f,.65f);
            if(audio.musicVolume!=.35f||audio.soundVolume!=.65f)throw new AssertionError("Independent volume levels");
            System.out.println("PASS: loop cache identity, negative frame identity, volume bounds and independent levels");
        } finally { audio.close(); }
        GameData data=new GameData(path->context.getAssets().open(path));
        MainActivity activity=new MainActivity();activity.data=data;
        GameView view=new GameView(context,activity,assets);
        Method drawJill=GameView.class.getDeclaredMethod("drawJill",Canvas.class);
        drawJill.setAccessible(true);
        Field route=GameEngine.class.getDeclaredField("route");route.setAccessible(true);
        Bitmap matrix=Bitmap.createBitmap(8*220,8*300,Bitmap.Config.ARGB_8888);
        Canvas all=new Canvas(matrix);all.drawColor(0xffded6bf);
        Paint label=new Paint();label.setColor(0xff202020);label.setTextSize(16);
        float[] angles={0,45,90,135,180,225,260,315};
        for(int shoes=0;shoes<4;shoes++)for(int carry=0;carry<2;carry++)for(int direction=0;direction<8;direction++){
            GameEngine game=new GameEngine(data,data.level(1),Collections.singletonMap("jill",shoes),7);
            game.x=110;game.y=270;game.dx=(float)Math.cos(Math.toRadians(angles[direction]));game.dy=(float)Math.sin(Math.toRadians(angles[direction]));
            route.set(game,new int[]{0});
            if(carry!=0){game.hand=new GameEngine.Cake();GameEngine.Layer layer=new GameEngine.Layer(1,30);layer.frost=0;game.hand.layers.add(layer);}
            activity.game=game;
            Bitmap tile=Bitmap.createBitmap(220,300,Bitmap.Config.ARGB_8888);
            drawJill.invoke(view,new Canvas(tile));
            int[] pixels=new int[220*300];tile.getPixels(pixels,0,220,0,0,220,300);
            int visible=0;for(int pixel:pixels)if((pixel>>>24)>128)visible++;
            if(visible<1000)throw new AssertionError("Jill body missing: shoes="+shoes+" carry="+carry+" direction="+direction+" pixels="+visible);
            int row=shoes*2+carry;all.drawBitmap(tile,direction*220,row*300,null);
            all.drawText("Shoes "+shoes+" carry "+carry+" dir "+direction,direction*220+4,row*300+20,label);
        }
        try(FileOutputStream out=new FileOutputStream(new java.io.File(context.getFilesDir(),"cake-jill-matrix.png"))){matrix.compress(Bitmap.CompressFormat.PNG,100,out);}
        System.out.println("PASS: Jill body remains present in all 64 direction/carry/shoe combinations");
        Method drawCustomer=GameView.class.getDeclaredMethod("drawCustomer",Canvas.class,GameEngine.Customer.class);drawCustomer.setAccessible(true);
        activity.game=new GameEngine(data,data.level(1),Collections.emptyMap(),7);
        int samples=0;
        for(GameData.Node profile:data.profiles.values())for(int state=0;state<5;state++){
            GameEngine.Customer customer=new GameEngine.Customer(1,0,profile,activity.game.arrivals.get(0));
            String id=new String[]{"ID_NORMAL","ID_MENU","ID_HAPPY","ID_BORED","ID_EATING"}[state];
            GameData.Node image=null;for(GameData.Node n:profile.children)if(n.s("id").equals(id))image=n;
            int count=GameEngine.ints(image.first("Sequence").s("frames")).length;
            for(int frame:new int[]{0,count/2,count-1}){
                customer.visualState=state;customer.visualFrame=frame;
                Bitmap tile=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);
                drawCustomer.invoke(view,new Canvas(tile),customer);
                int[] pixels=new int[800*600];tile.getPixels(pixels,0,800,0,0,800,600);
                int visible=0;for(int pixel:pixels)if((pixel>>>24)>128)visible++;
                if(visible<100)throw new AssertionError("Customer sprite missing: "+profile.s("guid")+" state="+state+" frame="+frame);
                tile.recycle();samples++;
            }
        }
        System.out.println("PASS: "+samples+" customer renders (all 41 profiles, five states, first/middle/last sequence entries)");

    }
}
