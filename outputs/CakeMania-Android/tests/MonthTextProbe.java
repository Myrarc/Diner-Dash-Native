package local.cakemania;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.os.Bundle;
import java.io.File;
import java.io.FileOutputStream;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import static local.cakemania.GameData.*;

/** The native loaders ignore Text font/size attributes; month text must keep
 * the narrative separate from goal/earnings rows on every authored screen. */
public final class MonthTextProbe extends android.app.Instrumentation {
    @Override public void onCreate(Bundle arguments){
        super.onCreate(arguments);Bundle result=new Bundle();
        try{int count=verify(getTargetContext());result.putString("stream","PASS: "+count+" month text screens; ignored XML font/size and narrative separation");finish(-1,result);}
        catch(Throwable error){result.putString("stream",android.util.Log.getStackTraceString(error));finish(1,result);}
    }
    private int verify(Context context)throws Exception{
        GameData data=new GameData(path->context.getAssets().open(path));
        AssetStore assets=new AssetStore(context);
        MainActivity activity=new MainActivity();activity.data=data;activity.bank=400;
        GameView view=new GameView(context,activity,assets);
        Method draw=GameView.class.getDeclaredMethod("drawMonth",Canvas.class,boolean.class);draw.setAccessible(true);
        int count=0;
        for(int number=1;number<=48;number++)for(int state=0;state<3;state++){
            GameEngine game=new GameEngine(data,data.level(number),Collections.emptyMap(),7);
            game.won=state==1;game.money=300;game.cakeRevenue=240;game.tips=60;activity.game=game;
            Node screen=state==0?game.level.startScreen:state==1?game.level.successScreen:game.level.failureScreen;
            List<Node> original=new ArrayList<>(screen.children);
            Bitmap full=render(draw,view,state!=0);
            // Poison obsolete attributes. Their presence must not alter native
            // layout; this regression fails the previous size-multiplier path.
            List<Node> poisoned=new ArrayList<>();
            for(Node n:original){Node copy=n.copy();if(copy.tag.equals("Text")){copy.attrs.put("size","1000");copy.attrs.put("font","FONT_CREAMPUFF");}poisoned.add(copy);}
            screen.children.clear();screen.children.addAll(poisoned);
            Bitmap alternate=render(draw,view,state!=0);
            if(!full.sameAs(alternate))throw new AssertionError("Text font/size must be ignored: month="+number+" state="+state);
            alternate.recycle();screen.children.clear();screen.children.addAll(original);
            if(number==1){try(FileOutputStream out=new FileOutputStream(new File(context.getFilesDir(),"cake-month-"+state+".png"))){full.compress(Bitmap.CompressFormat.PNG,100,out);}}
            full.recycle();
            Node paragraph=screen.first("Text");if(paragraph==null)throw new AssertionError("Missing paragraph");
            // Native 004a7230 wraps by width and does not clip by Rect.h.
            // The next goal/statistics row (or Continue) is the real boundary.
            float limit=state==0?473:500;
            // Isolate the narrative over exactly the same recovered artwork.
            screen.children.removeIf(n->n.tag.equals("Text"));
            Bitmap background=render(draw,view,state!=0);
            screen.children.add(paragraph);Bitmap narrative=render(draw,view,state!=0);
            int[] base=new int[800*600],pixels=new int[800*600];
            background.getPixels(base,0,800,0,0,800,600);narrative.getPixels(pixels,0,800,0,0,800,600);
            int visible=0,bottom=-1;
            for(int y=0;y<600;y++)for(int x=0;x<800;x++)if(base[y*800+x]!=pixels[y*800+x]){visible++;bottom=y;}
            // Atlas rows contain transparent padding. Compare with the first
            // visible ink of the following text, not its padded rectangle top.
            screen.children.remove(paragraph);
            for(Node n:original)if(n.tag.equals("Text")&&n!=paragraph&&n.f("y",0)>paragraph.f("y",0))screen.children.add(n);
            Bitmap following=render(draw,view,state!=0);following.getPixels(pixels,0,800,0,0,800,600);
            for(int y=0;y<600;y++)for(int x=0;x<800;x++)if(base[y*800+x]!=pixels[y*800+x])limit=Math.min(limit,y);
            if(visible<20||bottom>=limit)throw new AssertionError("Narrative must fit before goal/statistics: month="+number+" state="+state+" bottom="+bottom+" limit="+limit);
            background.recycle();narrative.recycle();following.recycle();screen.children.clear();screen.children.addAll(original);count++;
        }
        return count;
    }
    private static Bitmap render(Method draw,GameView view,boolean result)throws Exception{
        Bitmap bitmap=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);draw.invoke(view,new Canvas(bitmap),result);return bitmap;
    }
}
