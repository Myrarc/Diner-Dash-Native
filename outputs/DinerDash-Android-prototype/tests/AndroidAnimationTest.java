package local.dinerdash.prototype;

import android.app.Instrumentation;
import android.graphics.*;
import android.os.Bundle;
import android.os.SystemClock;
import android.view.MotionEvent;
import org.json.JSONObject;
import java.util.*;

/** Runs against the installed APK's assets and Android Canvas, not desktop graphics stubs. */
public final class AndroidAnimationTest extends Instrumentation {
    private int checks;
    @Override public void onCreate(Bundle args){super.onCreate(args);start();}
    private void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private Bitmap flo(SpriteRenderer r,GameEngine g){Bitmap b=Bitmap.createBitmap(240,220,Bitmap.Config.ARGB_8888);r.flo(new Canvas(b),g,120,170);return b;}
    private int hash(Bitmap b){int[] pixels=new int[b.getWidth()*b.getHeight()];b.getPixels(pixels,0,b.getWidth(),0,0,b.getWidth(),b.getHeight());return Arrays.hashCode(pixels);}
    private Bitmap standing(SpriteRenderer r,GameEngine.Party p){Bitmap b=Bitmap.createBitmap(140,180,Bitmap.Config.ARGB_8888);r.standing(new Canvas(b),p,5,20,-1);return Bitmap.createBitmap(b,0,35,140,140);}
    private void touch(GameView v,int action,float x,float y){long now=SystemClock.uptimeMillis();MotionEvent e=MotionEvent.obtain(now,now,action,x,y,0);v.onTouchEvent(e);e.recycle();}
    private void save(Bitmap bitmap,String name){try(java.io.FileOutputStream out=new java.io.FileOutputStream(new java.io.File(getTargetContext().getExternalFilesDir("review"),name+".png"))){bitmap.compress(Bitmap.CompressFormat.PNG,100,out);}catch(java.io.IOException error){throw new RuntimeException(error);}}
    private void chefPlacement(AssetStore a)throws Exception{
        java.lang.reflect.Field animation=SpriteRenderer.class.getDeclaredField("chefAnimation"),loops=SpriteRenderer.class.getDeclaredField("chefLoops");animation.setAccessible(true);loops.setAccessible(true);
        for(int stage=1;stage<=5;stage++)for(String mode:new String[]{"fry","chop"}){
            GameEngine g=new GameEngine(LevelData.get((stage-1)*10+1),1);GameEngine.Party p=new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0,0},true));p.cookingUntil=100000;g.parties.add(p);SpriteRenderer r=new SpriteRenderer(a);
            Bitmap actual=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888),expected=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);r.chef(new Canvas(actual),g);animation.set(r,mode);loops.setInt(r,100);
            int count=mode.equals("fry")?4:5;JSONObject anchor=r.roomFrame(g,"chef"),body=AssetStore.child(a.layout("chef"),"body");
            for(int frame=0;frame<count;frame++){
                g.time=(count+frame)*100;actual.eraseColor(Color.TRANSPARENT);r.chef(new Canvas(actual),g);expected.eraseColor(Color.TRANSPARENT);Canvas reference=new Canvas(expected);reference.translate(AssetStore.value(anchor,"loc",0,0),AssetStore.value(anchor,"loc",1,0));
                for(JSONObject n:AssetStore.children(a.layout("chef")))if(!n.optString("nodeID").equals("body"))r.frame(reference,AssetStore.frame(n,null,0,1),null,null);
                JSONObject pose=AssetStore.frame(body,mode,frame*100,100),member=a.member(pose.optString("cast"),pose.optString("member"));
                // Recovered chef.ls animates loc/member only; the first frame's unit scale stays fixed.
                reference.drawBitmap(a.bitmap(pose.optString("cast"),pose.optString("member"),true),AssetStore.value(pose,"loc",0,0)-member.optInt("reg_x"),AssetStore.value(pose,"loc",1,0)-member.optInt("reg_y"),null);
                if(hash(actual)!=hash(expected)){save(actual,"chef-placement-failure");save(expected,"chef-placement-expected");}
                check(hash(actual)==hash(expected),"Chef "+mode+" frame "+frame+" in restaurant "+stage+" must retain its original scale and stay anchored at the kitchen ledge");
                if(mode.equals("fry")&&frame==2){Bitmap room=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);Canvas canvas=new Canvas(room);r.background(canvas,g);canvas.drawBitmap(actual,0,0,null);save(room,"chef-placement-stage-"+stage);room.recycle();}
            }
            actual.recycle();expected.recycle();
        }
    }
    @Override public void onStart(){Bundle result=new Bundle();try{
        AssetStore a=new AssetStore(getTargetContext());SpriteRenderer r=new SpriteRenderer(a);GameEngine g=new GameEngine(LevelData.get(1),1);
        chefPlacement(a);
        check(a.member("gfx.numbers","big_tablenum_1").getString("path").contains("570_"),"Director name lookup must use the first cast member so table 1 does not show 11");
        Set<Integer> poses=new HashSet<>();
        for(int count=1;count<=2;count++)for(String dir:new String[]{"up","down","left","right"}){
            g.direction=dir;g.hands.clear();for(int i=0;i<count;i++)g.hands.add(new GameEngine.Item(GameEngine.ItemType.FOOD,0));
            // Every stopped approach faces the player; walking frames remain directional.
            poses.add(hash(flo(r,g)));
            for(String suffix:new String[]{"","_stop"}){String anim=dir+"_carry_"+count+suffix;JSONObject f=AssetStore.frame(AssetStore.child(a.layout("flo"),"body"),anim,100,100);check(anim.equals(f.getString("animID")),"Every carry direction must resolve an actual frame instead of silently falling back to the first upward pose");}
        }
        g=new GameEngine(LevelData.get(1),1);g.direction="down";r=new SpriteRenderer(a);int stopped=hash(flo(r,g));boolean idled=false;
        for(int i=1;i<=80;i++){g.time=i*250;idled|=hash(flo(r,g))!=stopped;}
        check(idled,"Flo must leave the stopped pose for her recovered idle sequence after waiting");
        g.hands.add(new GameEngine.Item(GameEngine.ItemType.TICKET,0));Bitmap carried=flo(r,g);SpriteRenderer fresh=new SpriteRenderer(a);check(hash(carried)==hash(flo(fresh,g)),"Picking up an item must cancel idle so Flo can carry it immediately");
        g=new GameEngine(LevelData.get(1),1);g.parties.add(new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0,0},true)));g.parties.get(0).cookingUntil=5000;r=new SpriteRenderer(a);
        Set<Integer> cooking=new HashSet<>();for(int i=0;i<12;i++){g.time=100+i*100;Bitmap b=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);r.chef(new Canvas(b),g);if(i>=4)cooking.add(hash(b));}
        check(cooking.size()>1,"An active order must advance the chef's visible cooking frames");
        g.parties.get(0).cookingUntil=0;g.time=5000;r.chef(new Canvas(Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888)),g);g.time=5750;Bitmap hidden=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);r.chef(new Canvas(hidden),g);Bitmap blank=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);check(hash(hidden)==hash(blank),"The chef must fade out when the last order finishes rather than loop forever");
        GameEngine nextShift=new GameEngine(LevelData.get(2),1);Bitmap nextChef=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);r.chef(new Canvas(nextChef),nextShift);check(hash(nextChef)==hash(blank),"Continuing after cooking must reset the chef's fade and timeline before the next shift's clock starts at zero");
        check(poses.size()==2,"Stopped carrying must use a front-facing pose for either one or two items, regardless of approach direction");
        GameEngine.Party guest=new GameEngine.Party(0,new GameEngine.Arrival(0,new int[]{0},true));guest.mood=10;Bitmap expected=Bitmap.createBitmap(140,180,Bitmap.Config.ARGB_8888);Canvas ec=new Canvas(expected);ec.translate(5,20);r.frame(ec,AssetStore.frame(AssetStore.child(a.layout("waitgroup"),"body_1"),null,0,1),"gfx.people.red","standing_young_female_3");int smile=hash(Bitmap.createBitmap(expected,0,35,140,140));
        check(hash(standing(r,guest))==smile,"Full hearts must draw the original smiling guest sprite");guest.mood=6;check(hash(standing(r,guest))==smile,"New arrivals at six hearts must smile, matching the original rounded standing-pose threshold");guest.mood=1;check(hash(standing(r,guest))!=smile,"A nearly depleted party must still draw its angry sprite");
        final GameEngine selectable=new GameEngine(LevelData.get(1),1);selectable.paused=false;selectable.tick(25000);final GameAudio audio=new GameAudio(getTargetContext(),a);
        runOnMainSync(()->{try{GameView v=new GameView(getTargetContext(),selectable,new GameView.Listener(){public void update(GameEngine g){}public void finished(GameEngine g){}public void pauseGame(){}public void shop(){}},a,audio);v.layout(0,0,800,600);touch(v,MotionEvent.ACTION_DOWN,20,400);check(selectable.selectedParty==1,"Touching the exposed second waiting party must select it even while the first party waits");touch(v,MotionEvent.ACTION_MOVE,GameView.gx(5),GameView.gy(6));touch(v,MotionEvent.ACTION_UP,GameView.gx(5),GameView.gy(6));check(selectable.party(1).table==0&&selectable.party(0).state==GameEngine.State.WAITING,"Dragging party two must seat that party and leave party one in line");check(selectable.heldParty==-1,"Seating must release drag protection immediately");
            GameEngine held=new GameEngine(LevelData.get(2),1);held.paused=false;held.tick(1);held.party(0).mood=1;
            v.setGame(held);JSONObject queue=AssetStore.frame(AssetStore.child(a.layout("waitqueue"),"group_1"),null,0,1);RectF guestHit=new SpriteRenderer(a).bounds(AssetStore.frame(AssetStore.child(a.layout("waitgroup"),"body_1"),null,0,1));guestHit.offset(1+AssetStore.value(queue,"loc",0,0)-AssetStore.value(queue,"regPoint",0,0),109+AssetStore.value(queue,"loc",1,0)-AssetStore.value(queue,"regPoint",1,0));
            touch(v,MotionEvent.ACTION_DOWN,guestHit.centerX(),guestHit.centerY());check(held.heldParty==0,"The actual guest touch region must activate held-party protection");held.tick(30000);check(held.party(0).state==GameEngine.State.WAITING&&held.party(0).mood==1,"A real View drag must keep an impatient guest alive while held");touch(v,MotionEvent.ACTION_CANCEL,guestHit.centerX(),guestHit.centerY());check(held.heldParty==-1,"Android cancellation must release protection without seating");held.tick(10000);check(held.party(0).state==GameEngine.State.GONE,"A cancelled drag must not leave guests immune to abandonment");
            GameEngine.Level barLevel=LevelData.get(34);barLevel.arrivals.clear();barLevel.snacks=new String[0];for(int i=0;i<2;i++)barLevel.arrivals.add(new GameEngine.Arrival(0,new int[]{0,0},true));GameEngine bar=new GameEngine(barLevel,1);bar.paused=false;bar.tick(1);bar.seatBar(0,4);bar.seatBar(1,0);bar.tick(4000);bar.perform(bar.party(0).table);bar.perform(bar.party(1).table);bar.perform(GameEngine.KITCHEN);bar.tick(5000);
            check(a.member("gfx.numbers","big_tablenum_A")!=null&&a.member("gfx.numbers","tablenum_A")!=null,"The installed assets must provide the same bar letter at table and tray sizes");v.setGame(bar);Bitmap barFrame=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);v.draw(new Canvas(barFrame));save(barFrame,"mechanics-bar-trays");bar.perform(GameEngine.foodTarget(bar.party(0).foodSlot));v.draw(new Canvas(barFrame));save(barFrame,"mechanics-bar-carry");check(bar.handsText().contains("food TA")&&bar.tableLabel(bar.party(0).table).equals("A"),"A rendered carried bar meal must keep the letter still shown at its destination");barFrame.recycle();}finally{audio.close();}});
        result.putString("summary","PASS: "+checks+" installed-asset animation checks; carrying poses="+poses.size()+", chef frames="+cooking.size());finish(-1,result);
    }catch(Throwable error){result.putString("failure",error.toString());finish(0,result);}}
}
