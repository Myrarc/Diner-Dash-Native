package local.dinerdash.prototype;

import android.content.Context;
import android.graphics.*;
import android.os.SystemClock;
import android.view.*;
import org.json.*;
import java.util.*;

/** Original 800x600 room and pointer interaction, fitted without changing its geometry. */
public final class GameView extends View {
    public interface Listener { void update(GameEngine game); void finished(GameEngine game); void pauseGame(); void shop(); }
    private GameEngine game;
    private final Listener listener;
    private final SpriteRenderer sprites;
    private final GameAudio audio;
    private final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG);
    private float scale=1,offsetX,offsetY,dragX,dragY;
    private int dragging=-1,pickedGuest,previewTable=-1,previewChair,previewBar=-1;
    private boolean active,notified,touchCancelled;
    private long lastTime;
    private String accessibility="";
    private static final String[] PREFIX={"d","t","s","c","g"};
    public GameView(Context c,GameEngine game,Listener listener,AssetStore assets,GameAudio audio){super(c);this.game=game;this.listener=listener;this.audio=audio;sprites=new SpriteRenderer(assets);setFocusable(true);}
    public void setGame(GameEngine game){this.game=game;notified=false;cancelDrag();lastTime=SystemClock.uptimeMillis();invalidate();}
    public void setActive(boolean a){active=a;if(!a)cancelDrag();lastTime=SystemClock.uptimeMillis();}
    public void updateAccessibility(){StringBuilder s=new StringBuilder("Restaurant. Shift ").append(game.level.number).append(". Score ").append(game.score).append(". Waiting parties: ").append(game.waiting().size()).append(". Food ready: ").append(game.readyFoodCount()).append(". Coffee ").append(game.level.drinks==null?"unavailable":game.drinkReady?"ready":"preparing").append(". Order wheel ").append(game.time-game.ticketTurnAt<1200?"turning":"idle").append(". Flo destination: ").append(game.currentTarget).append(". ").append(game.handsText()).append(". Drag ").append(dragging).append(" preview ").append(previewTable);
        for(int i=0;i<game.level.tables.size();i++){GameEngine.Table t=game.level.tables.get(i);if(t.active)s.append(". Table ").append(i+1).append(": ").append(t.party==null?t.dirty?"DIRTY":"EMPTY":t.party.state.name());}
        String value=s.toString();if(!value.equals(accessibility)){accessibility=value;setContentDescription(value);}}
    private final Runnable frame=new Runnable(){public void run(){long now=SystemClock.uptimeMillis();if(active){long elapsed=Math.max(0,now-lastTime);while(elapsed>0&&!game.paused&&!game.ended){long step=Math.min(100,elapsed);game.tick(step);elapsed-=step;}}lastTime=now;while(!game.sounds.isEmpty())audio.play(game.sounds.remove());listener.update(game);if(game.ended&&!notified){notified=true;listener.finished(game);}invalidate();postOnAnimation(this);}};
    @Override protected void onAttachedToWindow(){super.onAttachedToWindow();lastTime=SystemClock.uptimeMillis();postOnAnimation(frame);}
    @Override protected void onDetachedFromWindow(){removeCallbacks(frame);super.onDetachedFromWindow();}
    @Override protected void onSizeChanged(int w,int h,int oldw,int oldh){scale=Math.min(w/800f,h/600f);offsetX=(w-800*scale)/2;offsetY=(h-600*scale)/2;}
    public static float gx(float x){return 148+(x-1)*37;}
    public static float gy(float y){return 137+(y-1)*37;}
    private void text(Canvas c,String s,float x,float y,float size,int color){text(c,s,x,y,size,color,sprites.assets.mrB);}
    private void text(Canvas c,String s,float x,float y,float size,int color,Typeface face){paint.setColor(color);paint.setTypeface(face);paint.setTextSize(size);paint.setTextAlign(Paint.Align.LEFT);c.drawText(s,x,y,paint);}
    private void fittedText(Canvas c,String s,float x,float y,float width,float size,int color,Typeface face){paint.setTypeface(face);paint.setTextSize(size);float measured=paint.measureText(s);if(measured>width)size*=width/measured;text(c,s,x,y,size,color,face);}
    private void node(Canvas c,String layout,String key,String animation,long time,long ms){sprites.frame(c,AssetStore.frame(AssetStore.child(sprites.assets.layout(layout),key),animation,time,ms),null,null);}
    private String stationLayout(String key){if(key.equals("drinkspot"))return PREFIX[game.level.stage-1]+"_drinks";if(key.startsWith("food_"))return PREFIX[game.level.stage-1]+"_food";if(key.startsWith("snacks_"))return game.level.stage==2?"snacks":PREFIX[game.level.stage-1]+"_snacks";if(key.equals("busspot"))return "bus_new";if(key.equals("ticketspot"))return "ticket";return key;}
    private boolean carried(GameEngine.ItemType type){for(GameEngine.Item i:game.hands)if(i.type==type)return true;return false;}
    private void station(Canvas c,String key,int target){String layout=stationLayout(key);c.save();c.translate(sprites.roomX(game,key),sprites.roomY(game,key));
        GameEngine.Party food=target<=GameEngine.FOOD1?game.foodAt(GameEngine.FOOD1-target):null;
        List<JSONObject> nodes=AssetStore.children(sprites.assets.layout(layout));Collections.sort(nodes,(a,b)->Float.compare(AssetStore.frame(a,null,0,1).optInt("z"),AssetStore.frame(b,null,0,1).optInt("z")));
        for(JSONObject n:nodes){String id=n.optString("nodeID");JSONObject f=AssetStore.frame(n,key.equals("busspot")?"full_"+game.busFull:null,0,1);if(id.equals("mousetrap")||id.equals("poof"))continue;
            if(id.startsWith("checkmark_")){if(sprites.selected(game,target)<Integer.parseInt(id.substring(10)))continue;}
            else if(id.equals("hilite")){boolean hi=target==GameEngine.DRINKS?game.drinkReady:target==GameEngine.KITCHEN?carried(GameEngine.ItemType.TICKET):carried(GameEngine.ItemType.DISHES);if(!hi)continue;c.saveLayerAlpha(null,(int)(90+165*(1+Math.sin(game.time/180.0))/2));sprites.frame(c,f,null,null);c.restore();continue;}
            else if(id.equals("drinks")&&!game.drinkReady)continue;
            else if(target<=GameEngine.FOOD1&&food==null)continue;
            else if(id.equals("tablenum")){sprites.frame(c,f,null,"tablenum_"+game.tableLabel(food.table));continue;}
            else if(key.equals("ticketspot")&&id.isEmpty()&&game.time-game.ticketTurnAt<1200){f=AssetStore.frame(n,"turn",Math.max(0,game.time-game.ticketTurnAt),100);}
            else if(key.startsWith("snacks_")&&id.equals("food")){int i=target==GameEngine.SNACK1?0:1;String snack=game.level.snacks[i];int wanting=0,held=0;for(GameEngine.Party p:game.parties)if(p.state==GameEngine.State.SNACK&&snack.equals(p.wantedSnack))wanting++;for(GameEngine.Item item:game.hands)if(item.type.name().equalsIgnoreCase(snack))held++;sprites.frame(c,f,"gfx.room",snack+(wanting>held?"_hilite":""));continue;}
            sprites.frame(c,f,null,null);
        }c.restore();}
    private void hud(Canvas c){for(String id:new String[]{"","notepad","clockface","quitgame"})node(c,"game_interface",id,null,0,1);
        boolean expert=!game.level.endless&&game.score>=game.goal;
        fittedText(c,(expert?"EXPERT: ":"GOAL: ")+String.format(Locale.US,"%,d",expert?game.level.expert:game.goal),124,44,159,20,expert?0xffff00ff:0xff00ffff,sprites.assets.mrB);fittedText(c,String.format(Locale.US,"%,d",game.score),124,70,150,22,Color.WHITE,sprites.assets.mrB);fittedText(c,game.level.endless?String.valueOf(game.sublevel):game.level.stage+"-"+((game.level.number-1)%10+1),563,64,68,23,0xff272a2f,sprites.assets.komikaAxis);
        c.save();c.translate(37,6);sprites.simple(c,"moneyjar","full_"+Math.min(9,game.score*9/Math.max(1,game.goal)),0,1);c.restore();
        c.save();c.translate(295,21);for(int i=1;i<=Math.min(6,game.totalStars);i++)node(c,"star_meter","star_"+i,i<=game.stars?"full":"empty",0,1);c.restore();
        long end=game.level.arrivals.isEmpty()?1:Math.max(1,game.level.arrivals.get(game.level.arrivals.size()-1).time);int mark=Math.max(1,Math.min(12,(int)(game.time*12/end)));c.save();c.translate(653,7);sprites.simple(c,"fork",String.valueOf(mark),0,1);c.restore();
        if(game.closingAt>=0)node(c,"game_interface","closingtime",null,0,1);
        if(game.level.endless){c.save();c.translate(446,6);for(JSONObject n:AssetStore.children(sprites.assets.layout("upgrade_interface"))){String key=n.optString("nodeID");if(key.equals("new_item")||key.equals("heart")||key.equals("upgradebutton")){if(game.availableUpgrades<=0)continue;}sprites.frame(c,AssetStore.frame(n,key.equals("heart")?"flash":null,game.time,150),null,null);}c.restore();}
    }
    @Override protected void onDraw(Canvas c){super.onDraw(c);c.drawColor(Color.BLACK);c.save();c.translate(offsetX,offsetY);c.scale(scale,scale);c.clipRect(0,0,800,600);sprites.background(c,game);
        sprites.chef(c,game);
        station(c,"ticketspot",GameEngine.KITCHEN);station(c,"busspot",GameEngine.BUS);if(game.level.drinks!=null)station(c,"drinkspot",GameEngine.DRINKS);
        for(int i=0;i<game.foodSlots.length;i++)if(game.foodAt(i)!=null)station(c,"food_"+(i+1),GameEngine.foodTarget(i));for(int i=0;i<game.level.snacks.length;i++)station(c,"snacks_"+(i+1),i==0?GameEngine.SNACK1:GameEngine.SNACK2);
        List<GameEngine.Party> waiting=game.waiting();for(int i=Math.min(7,waiting.size()-1);i>=0;i--){GameEngine.Party p=waiting.get(i);if(p.id==dragging)continue;JSONObject f=AssetStore.frame(AssetStore.child(sprites.assets.layout("waitqueue"),"group_"+(i+1)),null,0,1);sprites.standing(c,p,1+AssetStore.value(f,"loc",0,0)-AssetStore.value(f,"regPoint",0,0),109+AssetStore.value(f,"loc",1,0)-AssetStore.value(f,"regPoint",1,0),-1);}
        if(game.level.podium!=null){c.save();c.translate(sprites.roomX(game,"podium"),sprites.roomY(game,"podium"));for(String k:new String[]{"podium_black","podium"})node(c,"podium",k,null,0,1);if(game.atPodium)node(c,"podium","podium_heart",game.time<game.podiumUntil?"grow_full":"grow",game.podiumChargingAt<0?0:game.time-game.podiumChargingAt,Math.max(1,game.level.podiumCharge/4));if(sprites.selected(game,GameEngine.PODIUM)>0)node(c,"podium","check",null,0,1);c.restore();}
        if(game.level.barColors!=null)drawBar(c);
        List<Integer> order=new ArrayList<>();for(int i=0;i<game.level.tables.size();i++)if(game.level.tables.get(i).active&&game.level.tables.get(i).barStart<0)order.add(i);Collections.sort(order,(a,b)->Integer.compare(game.level.tables.get(a).y,game.level.tables.get(b).y));
        boolean floDrawn=false;for(int id:order){GameEngine.Table t=game.level.tables.get(id);if(!floDrawn&&game.drawY()<t.y){sprites.flo(c,game,gx(game.drawX()),gy(game.drawY()));floDrawn=true;}sprites.table(c,game,id,gx(t.x),gy(t.y),id==previewTable?game.party(dragging):null,previewChair);}if(!floDrawn)sprites.flo(c,game,gx(game.drawX()),gy(game.drawY()));
        for(GameEngine.Popup p:game.popups){GameEngine.Table t=game.level.tables.get(p.table);text(c,(p.amount>0?"+":"")+p.amount,gx(t.x),gy(t.y)-45-(1500-p.remaining)/70f,20,p.amount<0?0xffa52f2f:0xff205538);}
        hud(c);if(dragging>=0&&previewTable<0&&previewBar<0){GameEngine.Party p=game.party(dragging);if(p!=null)sprites.standing(c,p,dragX-(18+21*pickedGuest),dragY-57,pickedGuest);}
        c.restore();}
    private void drawBar(Canvas c){sprites.bar(c,game,gx(game.level.barX),gy(game.level.barY),previewBar>=0?game.party(dragging):null,previewBar);}
    private int[] tableHit(float x,float y){for(int id=game.level.tables.size()-1;id>=0;id--){GameEngine.Table t=game.level.tables.get(id);if(!t.active||t.barStart>=0)continue;JSONObject l=sprites.assets.layout(t.colors.length+"top");JSONObject first=AssetStore.frame(AssetStore.child(l,"chair_1"),null,0,1);float ox=gx(t.x)-AssetStore.value(first,"loc",0,0),oy=gy(t.y)-AssetStore.value(first,"loc",1,0);for(int i=0;i<t.colors.length;i++){RectF b=sprites.bounds(AssetStore.frame(AssetStore.child(l,"mousetile_"+(i+1)),null,0,1));b.offset(ox,oy);if(b.contains(x,y))return new int[]{id,i};}RectF b=sprites.bounds(AssetStore.frame(AssetStore.child(l,"table_1"),null,0,1));b.offset(ox,oy);if(b.contains(x,y)){int nearest=0;float dist=Float.MAX_VALUE;for(int i=0;i<t.colors.length;i++){JSONObject f=AssetStore.frame(AssetStore.child(l,"chair_"+(i+1)),null,0,1);float dx=x-ox-AssetStore.value(f,"loc",0,0),dy=y-oy-AssetStore.value(f,"loc",1,0);if(dx*dx+dy*dy<dist){nearest=i;dist=dx*dx+dy*dy;}}return new int[]{id,nearest};}}return null;}
    private int barHit(float x,float y){if(game.level.barColors==null)return -1;for(int i=0;i<game.level.barColors.length;i++){RectF b=sprites.bounds(AssetStore.frame(AssetStore.child(sprites.assets.layout("bar"),"mousetrap_"+(i+1)),null,0,1));b.offset(gx(game.level.barX)-20,gy(game.level.barY)-105);if(b.contains(x,y))return i;}return -1;}
    private boolean stationHit(String key,float x,float y){RectF b=new RectF();boolean first=true;for(JSONObject n:AssetStore.children(sprites.assets.layout(stationLayout(key)))){String id=n.optString("nodeID");if(id.startsWith("checkmark")||id.equals("hilite")||id.equals("poof"))continue;RectF r=sprites.bounds(AssetStore.frame(n,null,0,1));if(r.isEmpty())continue;if(first){b.set(r);first=false;}else b.union(r);}b.offset(sprites.roomX(game,key),sprites.roomY(game,key));b.inset(-4,-4);return b.contains(x,y);}
    private void preview(float x,float y){previewTable=-1;previewBar=-1;int[] hit=tableHit(x,y);if(hit!=null&&game.canSeat(dragging,hit[0])){previewTable=hit[0];previewChair=(hit[1]-pickedGuest+game.level.tables.get(hit[0]).colors.length)%game.level.tables.get(hit[0]).colors.length;}else{int slot=barHit(x,y);GameEngine.Party p=game.party(dragging);if(slot>=0&&p!=null){int start=Math.max(0,Math.min(game.level.barColors.length-p.colors.length,slot-pickedGuest));if(game.canSeatBar(dragging,start))previewBar=start;}}}
    private void cancelDrag(){dragging=-1;previewTable=-1;previewBar=-1;game.selectedParty=-1;game.heldParty=-1;}
    @Override public boolean onTouchEvent(MotionEvent e){float x=(e.getX()-offsetX)/scale,y=(e.getY()-offsetY)/scale;int action=e.getActionMasked();if(action==MotionEvent.ACTION_CANCEL||e.getPointerCount()>1){touchCancelled=true;cancelDrag();invalidate();return true;}if(game.paused||game.ended)return true;
        if(action==MotionEvent.ACTION_DOWN){touchCancelled=false;dragX=x;dragY=y;List<GameEngine.Party> wait=game.waiting();for(int q=0;q<Math.min(8,wait.size())&&dragging<0;q++){GameEngine.Party p=wait.get(q);JSONObject group=AssetStore.frame(AssetStore.child(sprites.assets.layout("waitqueue"),"group_"+(q+1)),null,0,1);float ox=1+AssetStore.value(group,"loc",0,0)-AssetStore.value(group,"regPoint",0,0),oy=109+AssetStore.value(group,"loc",1,0)-AssetStore.value(group,"regPoint",1,0);for(int i=p.colors.length-1;i>=0;i--){JSONObject f=AssetStore.frame(AssetStore.child(sprites.assets.layout("waitgroup"),"body_"+(i+1)),null,0,1);RectF b=sprites.bounds(f);b.offset(ox,oy);b.inset(-3,-3);if(b.contains(x,y)){dragging=p.id;pickedGuest=i;game.selectedParty=p.id;game.heldParty=p.id;break;}}}updateAccessibility();return true;}
        if(action==MotionEvent.ACTION_MOVE){if(dragging>=0){dragX=x;dragY=y;preview(x,y);updateAccessibility();invalidate();}return true;}
        if(action!=MotionEvent.ACTION_UP||touchCancelled)return true;performClick();if(dragging>=0){preview(x,y);if(previewTable>=0)game.seat(dragging,previewTable,previewChair);else if(previewBar>=0)game.seatBar(dragging,previewBar);cancelDrag();invalidate();return true;}
        if(sprites.bounds(AssetStore.frame(AssetStore.child(sprites.assets.layout("game_interface"),"quitgame"),null,0,1)).contains(x,y)){listener.pauseGame();return true;}
        if(game.level.endless&&game.availableUpgrades>0){RectF upgrade=sprites.bounds(AssetStore.frame(AssetStore.child(sprites.assets.layout("upgrade_interface"),"upgradebutton"),null,0,1));upgrade.offset(446,6);if(upgrade.contains(x,y)){listener.shop();return true;}}
        if(game.level.podium!=null&&stationHit("podium",x,y)){game.queue(GameEngine.PODIUM);return true;}
        for(int i=0;i<game.foodSlots.length;i++)if(game.foodAt(i)!=null&&stationHit("food_"+(i+1),x,y)){game.queue(GameEngine.foodTarget(i));return true;}
        for(String key:new String[]{"ticketspot","busspot","drinkspot"})if((!key.equals("drinkspot")||game.level.drinks!=null)&&stationHit(key,x,y)){game.queue(key.equals("ticketspot")?GameEngine.KITCHEN:key.equals("busspot")?GameEngine.BUS:GameEngine.DRINKS);return true;}
        for(int i=0;i<game.level.snacks.length;i++)if(stationHit("snacks_"+(i+1),x,y)){game.queue(i==0?GameEngine.SNACK1:GameEngine.SNACK2);return true;}
        int[] hit=tableHit(x,y);if(hit!=null)game.queue(hit[0]);else{int b=barHit(x,y);if(b>=0&&game.barTableAt(b)>=0)game.queue(game.barTableAt(b));}invalidate();return true;}
    @Override public boolean performClick(){super.performClick();return true;}
}
