package local.dinerdash.prototype;
import android.app.Instrumentation;
import android.content.*;
import android.graphics.*;
import android.os.Bundle;
import android.view.*;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Synthetic score/result boundary, not a played Expert run. External save backup is restored. */
public final class AndroidLevel19Probe extends Instrumentation {
    MainActivity activity;MenuView menu;int checks;
    Object field(String name)throws Exception{Field f=MainActivity.class.getDeclaredField(name);f.setAccessible(true);return f.get(activity);}
    void check(boolean value,String reason){checks++;if(!value)throw new AssertionError(reason);}
    @Override public void onCreate(Bundle b){super.onCreate(b);start();}
    @Override public void onStart(){Bundle out=new Bundle();try{
        activity=(MainActivity)startActivitySync(new Intent(getTargetContext(),MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));waitForIdleSync();menu=(MenuView)field("menus");
        GameEngine.Level level=LevelData.get(19);check(level.goal==7500&&level.expert==15000,"The installed level must retain separate pass and Expert targets");level.arrivals.clear();GameEngine g=new GameEngine(level,1);g.score=8600;g.served=22;g.paused=false;g.tick(100);g.tick(1500);check(g.ended&&g.won,"The engine must accept 8,600 as a win without Expert");
        Throwable[] error={null};runOnMainSync(()->{try{Field f=MainActivity.class.getDeclaredField("game");f.setAccessible(true);f.set(activity,g);((GameView)field("board")).setActive(false);((GameView)field("board")).setGame(g);activity.finished(g);check(menu.screen.equals("endlevel")&&!menu.gameOver,"A non-expert win must open a normal result");SharedPreferences p=(SharedPreferences)field("progress");check(p.getInt("current",0)==20&&p.getInt("best19",0)>=8600,"A non-expert win must advance to level 2-10");}catch(Throwable e){error[0]=e;}});if(error[0]!=null)throw error[0];waitForIdleSync();Thread.sleep(200);
        Bitmap screenshot=getUiAutomation().takeScreenshot();try(FileOutputStream stream=new FileOutputStream(new File(getTargetContext().getExternalFilesDir("review"),"level-2-9-score-8600-result.png"))){screenshot.compress(Bitmap.CompressFormat.PNG,100,stream);}screenshot.recycle();
        runOnMainSync(()->{try{Bitmap b=Bitmap.createBitmap(menu.getWidth(),menu.getHeight(),Bitmap.Config.ARGB_8888);menu.draw(new Canvas(b));b.recycle();Field f=MenuView.class.getDeclaredField("buttons");f.setAccessible(true);RectF target=((Map<String,RectF>)f.get(menu)).get("continue_button");check(target!=null,"Continue must be offered below the Expert target");float scale=Math.min(menu.getWidth()/800f,menu.getHeight()/600f),x=(menu.getWidth()-800*scale)/2+target.centerX()*scale,y=(menu.getHeight()-600*scale)/2+target.centerY()*scale;long now=android.os.SystemClock.uptimeMillis();for(int type:new int[]{MotionEvent.ACTION_DOWN,MotionEvent.ACTION_UP}){MotionEvent e=MotionEvent.obtain(now,now,type,x,y,0);menu.onTouchEvent(e);e.recycle();}check(((GameEngine)field("game")).level.number==20&&menu.screen.equals("startlevel"),"Continue must start 2-10 after a non-expert win");}catch(Throwable e){error[0]=e;}});if(error[0]!=null)throw error[0];
        runOnMainSync(()->activity.finish());out.putString("summary","PASS: "+checks+" installed level 2-9 non-expert result/Continue checks at score 8,600; synthetic fixture, saves externally restored");finish(-1,out);
    }catch(Throwable e){out.putString("failure",e.toString());finish(1,out);}}
}
