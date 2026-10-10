package local.dinerdash.prototype;

import android.app.Instrumentation;
import android.graphics.*;
import android.os.Bundle;
import android.os.SystemClock;
import android.view.MotionEvent;
import org.json.*;
import java.util.*;

/** Recovered sitter_view/table_view placement and layer rules, on real Android Canvas. */
public final class AndroidGuestTest extends Instrumentation {
    private int checks;
    private final List<String> failures=new ArrayList<>();
    private final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG);
    @Override public void onCreate(Bundle args){super.onCreate(args);start();}
    private void check(boolean ok,String why){checks++;if(!ok)failures.add(why);}
    private boolean same(Bitmap a,Bitmap b){return a.sameAs(b);}
    private Bitmap canvas(){return Bitmap.createBitmap(240,230,Bitmap.Config.ARGB_8888);}
    private void save(Bitmap b,String name)throws Exception{try(java.io.FileOutputStream out=new java.io.FileOutputStream(new java.io.File(getTargetContext().getExternalFilesDir("review"),name+".png"))){b.compress(Bitmap.CompressFormat.PNG,100,out);}}
    private void touch(GameView v,int action,float x,float y){long now=SystemClock.uptimeMillis();MotionEvent e=MotionEvent.obtain(now,now,action,x,y,0);v.onTouchEvent(e);e.recycle();}
    private void levelSixTouch(AssetStore a,GameEngine.Arrival critic){
        runOnMainSync(()->{GameAudio audio=new GameAudio(getTargetContext(),a);try{
            // Synthetic guest timing, with the real 1-6 room and its recovered critic profile.
            GameEngine g=new GameEngine(LevelData.get(6),1);g.paused=false;g.time=critic.time;g.parties.add(new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0,1},"default")));g.parties.add(new GameEngine.Party(1,critic));
            GameView v=new GameView(getTargetContext(),g,new GameView.Listener(){public void update(GameEngine game){}public void finished(GameEngine game){}public void pauseGame(){}public void shop(){}},a,audio);v.layout(0,0,800,600);Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);
            v.draw(new Canvas(b));save(b,"guest-level-1-6-queue");touch(v,MotionEvent.ACTION_DOWN,20,400);check(g.heldParty==1,"The visible second-party critic in level 1-6 must be selectable before the first party");touch(v,MotionEvent.ACTION_MOVE,180,380);v.draw(new Canvas(b));save(b,"guest-level-1-6-critic-drag");touch(v,MotionEvent.ACTION_MOVE,260,315);v.draw(new Canvas(b));save(b,"guest-level-1-6-critic-preview");touch(v,MotionEvent.ACTION_UP,260,315);check(g.party(1).table==0,"Dragging the critic onto a clean two-seat table must seat her");
            touch(v,MotionEvent.ACTION_DOWN,20,480);check(g.heldParty==0,"The remaining default party must still be selectable");touch(v,MotionEvent.ACTION_MOVE,444,290);v.draw(new Canvas(b));save(b,"guest-level-1-6-default-preview");touch(v,MotionEvent.ACTION_UP,444,290);check(g.party(0).table==2,"The default party must seat at level 1-6's four-seat table with matching body and leg positions");check(g.heldParty==-1,"Successful seating must release the held guest");v.draw(new Canvas(b));save(b,"guest-level-1-6-seated");b.recycle();
        }catch(Exception error){throw new RuntimeException(error);}finally{audio.close();}});
    }
    private void draw(Canvas c,AssetStore a,JSONObject f,String cast,String name,JSONObject initial,boolean memberReg){
        JSONObject m=a.member(cast,name);if(m==null){failures.add("Missing reference member "+cast+":"+name);return;}
        c.save();c.translate(AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));c.rotate((float)f.optDouble("rotation"));
        c.scale((f.optInt("xflip")==1?-1:1)*AssetStore.value(initial,"scale",0,1),(f.optInt("yflip")==1?-1:1)*AssetStore.value(initial,"scale",1,1));
        float rx=memberReg?m.optInt("reg_x"):AssetStore.value(f,"regPoint",0,0),ry=memberReg?m.optInt("reg_y"):AssetStore.value(f,"regPoint",1,0);
        c.drawBitmap(a.bitmap(cast,name,true),-rx,-ry,paint);c.restore();
    }
    private void person(Canvas c,AssetStore a,GameEngine.Party p,int index,JSONObject chair,boolean flip,String animation){
        String color=new SpriteRenderer(a).colorName(p.colors[index]),graphic=p.profile.graphic;JSONObject layout=a.layout(graphic.equals("critic")?graphic:graphic+"_"+color),points=a.layouts.optJSONObject("sitter_regpoints");
        c.save();c.translate(AssetStore.value(chair,"loc",0,0),AssetStore.value(chair,"loc",1,0));if(flip)c.scale(-1,1);c.translate(-AssetStore.value(points,graphic,0,0),-AssetStore.value(points,graphic,1,0));
        // held_object precedes body in every recovered sitter layout; arms cover the menu.
        if(animation.equals("deciding")){JSONObject node=AssetStore.child(layout,"held_object"),pose=AssetStore.frame(node,"menu",0,1);draw(c,a,pose,pose.optString("cast"),pose.optString("member"),AssetStore.frame(node,null,0,1),true);}
        JSONObject node=AssetStore.child(layout,"body"),pose=AssetStore.frame(node,animation,p.age,animation.equals("eating")?400:2000);
        if(animation.equals("left")&&(p.profile.graphic.equals("boy")||p.profile.graphic.equals("man")||p.profile.graphic.equals("critic")))pose=AssetStore.frame(node,"leaving",750,750);
        // node_anim's default property list does not animate scale.
        draw(c,a,pose,pose.optString("cast"),pose.optString("member"),AssetStore.frame(node,null,0,1),false);c.restore();
    }
    private Bitmap tableReference(AssetStore a,GameEngine g,String animation){
        Bitmap b=canvas();Canvas c=new Canvas(b);GameEngine.Table t=g.level.tables.get(0);GameEngine.Party p=t.party;JSONObject layout=a.layout(t.colors.length+"top"),first=AssetStore.frame(AssetStore.child(layout,"chair_1"),null,0,1);c.translate(45-AssetStore.value(first,"loc",0,0),145-AssetStore.value(first,"loc",1,0));
        List<JSONObject> nodes=AssetStore.children(layout);Collections.sort(nodes,(x,y)->Double.compare(AssetStore.frame(x,null,0,1).optDouble("z"),AssetStore.frame(y,null,0,1).optDouble("z")));
        // Apply table_view's explicit putBehind calls to the authored child order.
        int[][] pairs=t.colors.length==2?new int[][]{{1,2}}:t.colors.length==4?new int[][]{{1,4},{2,3}}:new int[][]{{6,5},{1,6},{3,4},{2,3}};
        for(int[] pair:pairs){JSONObject moved=AssetStore.child(layout,"sitter_"+pair[0]),next=AssetStore.child(layout,"sitter_"+pair[1]);nodes.remove(moved);nodes.add(nodes.indexOf(next),moved);}
        SpriteRenderer r=new SpriteRenderer(a);
        for(JSONObject n:nodes){String key=n.optString("nodeID");JSONObject f=AssetStore.frame(n,null,0,1);
            if(key.startsWith("chair_")&&key.length()==7)r.frame(c,f,"gfx.diner","chair_none");
            else if(key.equals("table_1"))r.frame(c,f,"gfx.diner","table_"+t.colors.length+"top");
            else if(key.startsWith("leg_")||key.startsWith("sitter_")){int seat=Integer.parseInt(key.substring(key.indexOf('_')+1))-1,index=(seat-p.chairOffset+t.colors.length)%t.colors.length;boolean flip=seat==0||t.colors.length==4&&seat==3||t.colors.length==6&&(seat==4||seat==5);JSONObject chair=AssetStore.frame(AssetStore.child(layout,"chair_"+(seat+1)),null,0,1);
                if(key.startsWith("sitter_"))person(c,a,p,index,chair,flip,animation);
                else if(!animation.equals("left")){String cast="gfx.people."+r.colorName(p.colors[index]),name=p.profile.graphic+"_legs";JSONObject m=a.member(cast,name);c.save();c.translate(AssetStore.value(chair,"loc",0,0),AssetStore.value(chair,"loc",1,0));c.scale((flip?-1:1)*AssetStore.value(f,"scale",0,1),AssetStore.value(f,"scale",1,1));c.drawBitmap(a.bitmap(cast,name,true),-m.optInt("reg_x"),-m.optInt("reg_y"),paint);c.restore();}
            }else if(key.equals("heartrow"))r.hearts(c,p.mood,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));
            else if(key.isEmpty())r.frame(c,f,null,null);
        }return b;
    }
    @Override public void onStart(){Bundle result=new Bundle();try{
        AssetStore a=new AssetStore(getTargetContext());SpriteRenderer r=new SpriteRenderer(a);
        GameEngine.Arrival critic=null;for(GameEngine.Arrival arrival:LevelData.get(6).arrivals)if(arrival.profile.graphic.equals("critic"))critic=arrival;
        check(critic!=null&&critic.time==121000,"Level 1-6 must introduce the recovered food critic at 121 seconds");
        GameEngine.Party p=new GameEngine.Party(0,critic);
        Bitmap sheet=Bitmap.createBitmap(960,230,Bitmap.Config.ARGB_8888);Canvas sc=new Canvas(sheet);sc.drawColor(Color.rgb(220,210,180));
        for(int pose=1;pose<=4;pose++){p.mood=pose==1?1:pose==2?4:7;Bitmap actual=canvas(),expected=canvas();r.standing(new Canvas(actual),p,45,25,pose==4?0:-1);Canvas c=new Canvas(expected);c.translate(45,25);JSONObject f=AssetStore.frame(AssetStore.child(a.layout("waitgroup"),"body_1"),null,0,1);draw(c,a,f,"gfx.people.none","standing_critic_"+pose,f,true);f=AssetStore.frame(AssetStore.child(a.layout("waitgroup"),"heartrow"),null,0,1);r.hearts(c,p.mood,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));check(same(actual,expected),"Food critic queue pose "+pose+" must use gfx.people.none, including drag selection");sc.drawBitmap(actual,(pose-1)*240,0,null);actual.recycle();expected.recycle();}save(sheet,"guest-critic-queue");sheet.recycle();
        for(String profile:new String[]{"default","old_male","business_female","boy","man","critic"})for(int capacity:new int[]{2,4,6})for(String animation:new String[]{"deciding","neutral","left"}){
            GameEngine.Level level=new GameEngine.Level(6,4000,8000);level.stage=1;level.stageId="diner";int[] colors=new int[capacity];for(int i=0;i<capacity;i++)colors[i]=profile.equals("critic")?-1:i%5;level.tables.add(new GameEngine.Table(3,6,new int[capacity]));Arrays.fill(level.tables.get(0).colors,-1);GameEngine g=new GameEngine(level,1);p=new GameEngine.Party(0,new GameEngine.Arrival(0,colors,profile));g.parties.add(p);level.tables.get(0).party=p;p.table=0;p.state=animation.equals("deciding")?GameEngine.State.DECIDING:animation.equals("neutral")?GameEngine.State.WAITING:GameEngine.State.LEAVING;p.age=animation.equals("left")?1500:0;
            for(int offset=0;offset<capacity;offset++){p.chairOffset=offset;Bitmap actual=canvas(),expected=tableReference(a,g,animation);r.table(new Canvas(actual),g,0,45,145);check(same(actual,expected),profile+" "+capacity+" seats "+animation+" offset "+offset+": body/legs must share chair anchors, menus stay behind arms, departed legs hide");if(profile.equals("default")&&offset==0){save(actual,"guest-default-"+capacity+"-"+animation);save(expected,"guest-reference-"+capacity+"-"+animation);}actual.recycle();expected.recycle();}
        }
        levelSixTouch(a,critic);
        result.putString(failures.isEmpty()?"summary":"failure",(failures.isEmpty()?"PASS: ":"FAIL: ")+checks+" installed guest checks; failures="+failures.size()+(failures.isEmpty()?"":"; "+failures.toString()));finish(failures.isEmpty()?-1:0,result);
    }catch(Throwable error){result.putString("failure",error.toString());finish(0,result);}}
}
