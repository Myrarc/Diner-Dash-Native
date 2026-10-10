package local.dinerdash.prototype;
import android.app.Instrumentation;
import android.content.*;
import android.graphics.*;
import android.os.Bundle;
import android.view.*;
import org.json.*;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Installed input replay with a controlled clock and ordinary GameView touch events. */
public final class AndroidLevel19ExpertReplay extends Instrumentation {
    MainActivity activity;GameView board;MenuView menu;GameEngine g;SpriteRenderer sprites;
    int checks,seats,queues;String result;
    Object field(Object owner,String name)throws Exception{Field f=owner.getClass().getDeclaredField(name);f.setAccessible(true);return f.get(owner);}
    void check(boolean okay,String reason){checks++;if(!okay)throw new AssertionError(reason);}
    void event(int action,float x,float y)throws Exception{
        float scale=(Float)field(board,"scale"),ox=(Float)field(board,"offsetX"),oy=(Float)field(board,"offsetY");
        long now=android.os.SystemClock.uptimeMillis();MotionEvent e=MotionEvent.obtain(now,now,action,ox+x*scale,oy+y*scale,0);board.onTouchEvent(e);e.recycle();
    }
    int[] tableHit(float x,float y)throws Exception{Method m=GameView.class.getDeclaredMethod("tableHit",float.class,float.class);m.setAccessible(true);return (int[])m.invoke(board,x,y);}
    boolean stationHit(String key,float x,float y)throws Exception{Method m=GameView.class.getDeclaredMethod("stationHit",String.class,float.class,float.class);m.setAccessible(true);return (Boolean)m.invoke(board,key,x,y);}
    RectF chairBounds(int table,int chair)throws Exception{
        GameEngine.Table t=g.level.tables.get(table);JSONObject layout=sprites.assets.layout(t.colors.length+"top");
        JSONObject first=AssetStore.frame(AssetStore.child(layout,"chair_1"),null,0,1);
        RectF b=sprites.bounds(AssetStore.frame(AssetStore.child(layout,"mousetile_"+(chair+1)),null,0,1));
        b.offset(GameView.gx(t.x)-AssetStore.value(first,"loc",0,0),GameView.gy(t.y)-AssetStore.value(first,"loc",1,0));return b;
    }
    void seat(int party,int table,int offset)throws Exception{
        GameEngine.Party p=g.party(party);int q=g.waiting().indexOf(p);check(q>=0&&q<8,"Guest must be visible and waiting");
        JSONObject group=AssetStore.frame(AssetStore.child(sprites.assets.layout("waitqueue"),"group_"+(q+1)),null,0,1);
        float ox=1+AssetStore.value(group,"loc",0,0)-AssetStore.value(group,"regPoint",0,0),oy=109+AssetStore.value(group,"loc",1,0)-AssetStore.value(group,"regPoint",1,0);
        boolean picked=false;
        for(int guest=0;guest<p.colors.length&&!picked;guest++){
            RectF b=sprites.bounds(AssetStore.frame(AssetStore.child(sprites.assets.layout("waitgroup"),"body_"+(guest+1)),null,0,1));b.offset(ox,oy);
            for(float y=b.top+3;y<b.bottom-2&&!picked;y+=5)for(float x=b.left+3;x<b.right-2&&!picked;x+=5){
                event(MotionEvent.ACTION_DOWN,x,y);if((Integer)field(board,"dragging")==party)picked=true;else event(MotionEvent.ACTION_CANCEL,x,y);
            }
        }
        check(picked,"An ordinary touch must be able to pick the requested guest "+party);
        int grabbed=(Integer)field(board,"pickedGuest"),chair=(offset+grabbed)%g.level.tables.get(table).colors.length;
        RectF target=chairBounds(table,chair);float x=target.centerX(),y=target.centerY();int[] hit=tableHit(x,y);
        check(hit!=null&&hit[0]==table&&hit[1]==chair,"Drop coordinate must identify the requested chair");
        int[] colors=p.colors.clone();event(MotionEvent.ACTION_MOVE,x,y);event(MotionEvent.ACTION_UP,x,y);
        check(p.table==table&&p.chairOffset==offset&&p.state==GameEngine.State.DECIDING,"Touch drag must seat the intended party and offset");
        check(Arrays.equals(colors,p.colors),"The touch replay must preserve guest order");seats++;
    }
    void queue(int target)throws Exception{
        float x,y;
        if(target>=0){RectF b=chairBounds(target,0);x=b.centerX();y=b.centerY();}
        else {
            String key=target==GameEngine.KITCHEN?"ticketspot":target==GameEngine.BUS?"busspot":"food_"+(GameEngine.FOOD1-target+1);
            Method m=GameView.class.getDeclaredMethod("stationLayout",String.class);m.setAccessible(true);String layout=(String)m.invoke(board,key);
            RectF b=new RectF();boolean first=true;
            for(JSONObject n:AssetStore.children(sprites.assets.layout(layout))){String id=n.optString("nodeID");if(id.startsWith("checkmark")||id.equals("hilite")||id.equals("poof"))continue;RectF r=sprites.bounds(AssetStore.frame(n,null,0,1));if(r.isEmpty())continue;if(first){b.set(r);first=false;}else b.union(r);}
            b.offset(sprites.roomX(g,key),sprites.roomY(g,key));x=b.centerX();y=b.centerY();check(stationHit(key,x,y),"Station coordinate must hit "+key);
        }
        event(MotionEvent.ACTION_DOWN,x,y);event(MotionEvent.ACTION_UP,x,y);
        check(g.currentTarget==target||!g.destinations.isEmpty()&&g.destinations.peekLast()==target,"Touch must queue target "+target+" at "+g.time+" actual="+g.currentTarget+" pending="+g.destinations+" point="+x+","+y+" food="+Arrays.toString(g.foodSlots));queues++;
    }
    void screenshot(String name)throws Exception{
        Bitmap image=getUiAutomation().takeScreenshot();try(FileOutputStream out=new FileOutputStream(new File(getTargetContext().getExternalFilesDir("review"),name))){image.compress(Bitmap.CompressFormat.PNG,100,out);}image.recycle();
    }
    @Override public void onCreate(Bundle bundle){super.onCreate(bundle);start();}
    @Override public void onStart(){Bundle out=new Bundle();try{
        List<String> inputs=new ArrayList<>();try(BufferedReader r=new BufferedReader(new InputStreamReader(getContext().getAssets().open("expert-inputs.csv")))){for(String row;(row=r.readLine())!=null;)inputs.add(row);}
        activity=(MainActivity)startActivitySync(new Intent(getTargetContext(),MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));waitForIdleSync();
        Throwable[] failure={null};runOnMainSync(()->{try{
            board=(GameView)field(activity,"board");menu=(MenuView)field(activity,"menus");sprites=(SpriteRenderer)field(board,"sprites");board.setActive(false);
            g=new GameEngine(LevelData.get(19),1234);Field f=MainActivity.class.getDeclaredField("game");f.setAccessible(true);f.set(activity,g);board.setGame(g);g.paused=false;board.setVisibility(View.VISIBLE);menu.setVisibility(View.GONE);
            check(g.level.expert==15000&&g.capacity==2,"Installed configuration must retain target and carrying limit");
            int input=0;
            while(!g.ended&&g.time<700000){
                while(input<inputs.size()&&Long.parseLong(inputs.get(input).split(",")[0])==g.time){String[] e=inputs.get(input++).split(",");if(e[1].equals("seat"))seat(Integer.parseInt(e[2]),Integer.parseInt(e[3]),Integer.parseInt(e[4]));else queue(Integer.parseInt(e[2]));}
                long delta=16;if(input<inputs.size())delta=Math.min(delta,Long.parseLong(inputs.get(input).split(",")[0])-g.time);check(delta>0,"Input timestamps must remain monotonic");g.tick(delta);check(g.hands.size()<=2,"Replay must retain the two-item limit");g.sounds.clear();
            }
            check(input==inputs.size()&&seats==22&&queues==136,"All recorded player inputs must be consumed");
            check(g.ended&&g.won&&g.score>=15000&&g.served==22&&g.abandoned==0,"Natural engine outcome must earn Expert with no lost customers");
            result="score="+g.score+" served="+g.served+" lost="+g.abandoned+" chairs preserved; seats="+seats+" queues="+queues+" controlled step=16ms";
            activity.finished(g);check(menu.screen.equals("endlevel")&&menu.game.score>=menu.game.level.expert,"The played result must qualify for the Expert graphic");
            SharedPreferences progress=(SharedPreferences)field(activity,"progress");check(progress.getInt("best19",0)>=15000,"The played Expert result must be saved");
        }catch(Throwable error){failure[0]=error;}});if(failure[0]!=null)throw failure[0];waitForIdleSync();screenshot("level-2-9-expert-touch-result.png");
        runOnMainSync(()->activity.finish());out.putString("summary","PASS: installed 2-9 Expert input replay; "+result+"; preferences backed up and restored externally");finish(-1,out);
    }catch(Throwable error){out.putString("failure",error.toString());finish(1,out);}}
}
