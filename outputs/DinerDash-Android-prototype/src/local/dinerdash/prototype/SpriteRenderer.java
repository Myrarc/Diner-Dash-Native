package local.dinerdash.prototype;

import android.graphics.*;
import org.json.*;
import java.util.*;

/** Composites the original Director layout frames on the Android canvas. */
public final class SpriteRenderer {
    public final AssetStore assets;
    private final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG);
    private Bitmap background;
    private String backgroundKey="";
    private GameEngine animatedGame,chefGame;
    private long nextIdle,idleStarted=-1,observedActivity=-1;
    private int idleType=1,idleLoops=1;
    private boolean chefCooking;
    private long chefChanged,chefCycle;
    private int chefLoops=1;
    private float chefAlpha,chefFrom;
    private String chefAnimation="chop";
    private final Random animationRandom=new Random();
    private final Map<GameEngine.Party,JSONObject[]> guestPoses=new WeakHashMap<>();
    private static final String[] COLORS={"red","blue","green","yellow","purple"};
    private static final String[] BG={"bg_diner","bg_tiki","bg_seafood","bg_chez","bg_goddess"};
    public SpriteRenderer(AssetStore a){assets=a;}
    public String colorName(int color){return color>=0?COLORS[color]:color==-2?"grey":"none";}
    public void image(Canvas c,String cast,String name,float x,float y,boolean flip){JSONObject m=assets.member(cast,name);if(m==null)return;Bitmap b=assets.bitmap(cast,name,true);if(b==null)return;c.save();c.translate(x,y);if(flip)c.scale(-1,1);c.drawBitmap(b,-m.optInt("reg_x"),-m.optInt("reg_y"),paint);c.restore();}
    public void frame(Canvas c,JSONObject f,String castOverride,String memberOverride){frame(c,f,castOverride,memberOverride,f);}
    private void frame(Canvas c,JSONObject f,String castOverride,String memberOverride,JSONObject initial){if(f==null)return;String cast=castOverride==null?f.optString("cast"):castOverride,name=memberOverride==null?f.optString("member"):memberOverride;if(name.isEmpty()||cast.equals("gfx.layout"))return;
        boolean transparent=f.optInt("ink")!=0;Bitmap b=assets.bitmap(cast,name,transparent);if(b==null)return;float x=AssetStore.value(f,"loc",0,0),y=AssetStore.value(f,"loc",1,0),rx=AssetStore.value(f,"regPoint",0,0),ry=AssetStore.value(f,"regPoint",1,0);
        JSONObject info=assets.member(cast,name);if(memberOverride!=null&&info!=null){rx=info.optInt("reg_x");ry=info.optInt("reg_y");}
        c.save();c.translate(x,y);c.rotate((float)f.optDouble("rotation"));c.scale((f.optInt("xflip")==1?-1:1)*AssetStore.value(initial,"scale",0,1),(f.optInt("yflip")==1?-1:1)*AssetStore.value(initial,"scale",1,1));paint.setAlpha(f.optInt("blend",100)*255/100);c.drawBitmap(b,-rx,-ry,paint);paint.setAlpha(255);c.restore();
    }
    private boolean decoration(GameEngine game,String key){int state=1;try{state=Integer.parseInt(game.level.bgState.substring(6));}catch(Exception ignored){}
        if(key.equals("closing_sign")||key.equals("chef")||key.equals("drinkspot")||key.equals("ticketspot")||key.equals("busspot")||key.equals("podium")||key.equals("mime")||key.startsWith("food_")||key.startsWith("snacks_"))return false;
        if(key.startsWith("remove_")){int version=Character.digit(key.charAt(7),10);return version>=state;}
        if(key.matches("tiki_[234]"))return Character.digit(key.charAt(5),10)<=state;
        if(key.startsWith("bg_seafood_")||key.startsWith("bg_chez_")){char version=key.charAt(key.startsWith("bg_chez_")?8:11);return Character.digit(version,10)<=state;}
        if(key.startsWith("crack_"))return Character.digit(key.charAt(6),10)==state-1;
        if(key.equals("bg_1"))return false;return true;
    }
    public void background(Canvas c,GameEngine g){String key=g.level.stage+":"+g.level.bgState;
        if(!key.equals(backgroundKey)){backgroundKey=key;background=Bitmap.createBitmap(800,600,Bitmap.Config.ARGB_8888);renderBackground(new Canvas(background),g);}
        c.drawBitmap(background,0,0,paint);
    }
    private void renderBackground(Canvas c,GameEngine g){List<JSONObject> children=AssetStore.children(assets.layout(BG[g.level.stage-1]));Collections.sort(children,(a,b)->Float.compare(z(a),z(b)));
        for(JSONObject node:children){String key=node.optString("nodeID");if(!decoration(g,key))continue;JSONObject f=AssetStore.frame(node,null,0,1);if(f!=null&&f.optString("cast").startsWith("gfx.")&&!f.optString("cast").equals("gfx.layout"))frame(c,f,null,null);}
    }
    private float z(JSONObject node){JSONObject f=AssetStore.frame(node,null,0,1);return f==null?0:(float)f.optDouble("z");}
    public void simple(Canvas c,String layout,String animation,long time,long ms){List<JSONObject> children=AssetStore.children(assets.layout(layout));Collections.sort(children,(a,b)->Float.compare(z(a),z(b)));for(JSONObject child:children)frame(c,AssetStore.frame(child,animation,time,ms),null,null);}
    public void person(Canvas c,GameEngine.Party party,int customer,float x,float y,boolean flip,boolean legs,long time,String stage){String graphic=party.profile.graphic,color=colorName(party.colors[customer]);JSONObject layout=assets.layout(graphic.equals("critic")?graphic:graphic+"_"+color);if(layout==null)layout=assets.layout(graphic+"_blue");if(layout==null)return;
        JSONObject points=assets.layouts.optJSONObject("sitter_regpoints");JSONObject rp=points==null?null:points.optJSONObject(graphic);float rx=rp==null?25:AssetStore.value(points,graphic,0,25),ry=rp==null?85:AssetStore.value(points,graphic,1,85);
        c.save();c.translate(x,y);if(flip)c.scale(-1,1);
        boolean showLegs=!departed(party);
        if(legs&&showLegs)image(c,"gfx.people."+color,graphic+"_legs",0,0,false);
        c.translate(-rx,-ry);String animation;
        switch(party.state){case DECIDING:animation="deciding";break;case READY:case CHECK:case SNACK:animation="ready";break;case EATING:animation="eating";break;case LEAVING:animation=departed(party)?"left":"leaving";break;case DITCHING:animation=departed(party)?"ditched":"ditching";break;case SCORING:animation=party.mood>7?"happy":party.mood<4?"mad":"neutral";break;default:animation=party.foodPickedUp?"prefood":"neutral";}
        boolean reacting=party.moodChangedAt>=0&&time-party.moodChangedAt<(party.mood>party.moodBefore?400:500)&&party.state!=GameEngine.State.SCORING&&party.state!=GameEngine.State.LEAVING&&party.state!=GameEngine.State.DITCHING;
        if(reacting)animation=party.mood>party.moodBefore?"happy":"mad";
        if(party.drinkUntil>time)animation="drinking";
        // Original held_object is behind the body, so the hands cover menus and cups.
        if(animation.equals("deciding")||animation.equals("drinking"))frame(c,AssetStore.frame(AssetStore.child(layout,"held_object"),animation.equals("deciding")?"menu":"drink",0,1),animation.equals("drinking")?"gfx."+stage:null,null);
        JSONObject body=AssetStore.child(layout,"body");
        // sitter_view uses node_anim's default properties, which exclude scale.
        long animationAge=reacting?time-party.moodChangedAt:party.age;
        boolean exit=party.state==GameEngine.State.LEAVING||party.state==GameEngine.State.DITCHING;
        if(exit&&departed(party))animationAge-=departureDuration(party);
        frame(c,guestFrame(party,customer,body,animation,animationAge,exit?750:animation.equals("eating")?400:2000),null,null,AssetStore.frame(body,null,0,1));
        if(reacting){JSONObject face=AssetStore.frame(AssetStore.child(layout,"face"),null,0,1);c.save();c.translate(AssetStore.value(face,"loc",0,0)-AssetStore.value(face,"regPoint",0,0),AssetStore.value(face,"loc",1,0)-AssetStore.value(face,"regPoint",1,0));simple(c,"status_anim",party.mood>party.moodBefore?"better":"worse",time-party.moodChangedAt,100);c.restore();}
        c.restore();
    }
    private List<JSONObject> guestFrames(JSONObject node,String animation){List<JSONObject> result=new ArrayList<>();JSONArray frames=node.optJSONArray("frames");for(int i=0;i<frames.length();i++){JSONObject f=frames.optJSONObject(i);if(animation.equals(f.optString("animID")))result.add(f);}return result;}
    private long departureDuration(GameEngine.Party p){String graphic=p.profile.graphic;JSONObject layout=assets.layout(graphic.equals("critic")?graphic:graphic+"_blue");return Math.max(1,guestFrames(AssetStore.child(layout,"body"),p.state==GameEngine.State.DITCHING?"ditching":"leaving").size())*750L;}
    private boolean departed(GameEngine.Party p){return (p.state==GameEngine.State.LEAVING||p.state==GameEngine.State.DITCHING)&&p.age>=departureDuration(p);}
    private JSONObject guestFrame(GameEngine.Party p,int customer,JSONObject body,String animation,long age,long ms){
        JSONObject[] previous=guestPoses.get(p);if(previous==null){previous=new JSONObject[p.colors.length];guestPoses.put(p,previous);}
        List<JSONObject> frames=guestFrames(body,animation);JSONObject pose;
        // node_anim stops on absent IDs, preserving the last visual properties.
        if(frames.isEmpty()&&(animation.equals("left")||animation.equals("ditched"))){frames=guestFrames(body,animation.equals("left")?"leaving":"ditching");pose=frames.get(frames.size()-1);}
        else if(frames.isEmpty())pose=previous[customer]==null?AssetStore.frame(body,null,0,1):previous[customer];
        else {long index=Math.max(0,age)/ms;pose=frames.get(animation.equals("eating")?(int)(index%frames.size()):(int)Math.min(index,frames.size()-1));}
        previous[customer]=pose;return pose;
    }
    public void table(Canvas c,GameEngine g,int id,float originX,float originY){table(c,g,id,originX,originY,null,0);}
    public void table(Canvas c,GameEngine g,int id,float originX,float originY,GameEngine.Party preview,int previewOffset){GameEngine.Table t=g.level.tables.get(id);GameEngine.Party party=preview==null?t.party:preview;int offset=preview==null?(party==null?0:party.chairOffset):previewOffset;JSONObject layout=assets.layout(t.colors.length+"top");if(layout==null)return;JSONObject first=AssetStore.frame(AssetStore.child(layout,"chair_1"),null,0,1);float left=AssetStore.value(first,"loc",0,25),top=AssetStore.value(first,"loc",1,89);
        c.save();c.translate(originX-left,originY-top);List<JSONObject> children=AssetStore.children(layout);Collections.sort(children,(a,b)->Float.compare(z(a),z(b)));
        if(party!=null){int[][] behind=t.colors.length==2?new int[][]{{1,2}}:t.colors.length==4?new int[][]{{1,4},{2,3}}:new int[][]{{6,5},{1,6},{3,4},{2,3}};
            for(int[] pair:behind){JSONObject body=AssetStore.child(layout,"sitter_"+pair[0]),next=AssetStore.child(layout,"sitter_"+pair[1]);children.remove(body);children.add(children.indexOf(next),body);}}
        for(JSONObject n:children){String key=n.optString("nodeID");JSONObject f=AssetStore.frame(n,null,0,1);if(f==null)continue;
            if(key.startsWith("chair_")&&key.length()==7){int chair=Character.digit(key.charAt(6),10)-1;if(chair>=0&&chair<t.colors.length)frame(c,f,"gfx."+g.level.stageId,"chair_"+colorName(t.colors[chair]));}
            else if(key.equals("table_1"))frame(c,f,"gfx."+g.level.stageId,"table_"+t.colors.length+"top");
            else if(key.startsWith("sitter_")){int chair=Integer.parseInt(key.substring(7))-1;GameEngine.Party p=party;if(p!=null){int index=(chair-offset+t.colors.length)%t.colors.length;JSONObject anchor=AssetStore.frame(AssetStore.child(layout,"chair_"+(chair+1)),null,0,1);if(index<p.colors.length)person(c,p,index,AssetStore.value(anchor,"loc",0,0),AssetStore.value(anchor,"loc",1,0),chair==0||t.colors.length==4&&chair==3||t.colors.length==6&&(chair==4||chair==5),false,g.time,g.level.stageId);}}
            else if(key.startsWith("leg_")){int chair=Integer.parseInt(key.substring(4))-1;GameEngine.Party p=party;if(p!=null&&!departed(p)){int index=(chair-offset+t.colors.length)%t.colors.length;if(index<p.colors.length){JSONObject anchor=AssetStore.frame(AssetStore.child(layout,"chair_"+(chair+1)),null,0,1);c.save();c.translate(AssetStore.value(anchor,"loc",0,0)-AssetStore.value(f,"loc",0,0),AssetStore.value(anchor,"loc",1,0)-AssetStore.value(f,"loc",1,0));frame(c,f,"gfx.people."+colorName(p.colors[index]),p.profile.graphic+"_legs");c.restore();}}}
            else if(key.startsWith("chairnum_")){int chair=Integer.parseInt(key.substring(9))-1;if(party==null&&t.multipliers[chair]>1){JSONObject seat=AssetStore.frame(AssetStore.child(layout,"chair_"+(chair+1)),null,0,1);frame(c,f,"gfx.room",colorName(t.colors[chair])+"_"+t.multipliers[chair]+(seat.optInt("xflip")==1?"_flip":""));}}
            else if(key.equals("heartrow")&&party!=null)hearts(c,party.mood,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));
            else if((key.equals("tablenum_bg")||key.equals("tablenum"))&&party!=null&&party.state==GameEngine.State.ORDERED)frame(c,f,null,key.equals("tablenum")?"big_tablenum_"+(id+1):null);
            else if(key.equals("tablenum_hilite")&&party!=null&&party.state==GameEngine.State.ORDERED&&hasFood(g,party.id))frame(c,f,null,null);
            else if(key.equals("check")&&party!=null&&party.state==GameEngine.State.SCORING)frame(c,f,null,null);
            else if(key.startsWith("checkmark_")){int count=Integer.parseInt(key.substring(10));if(selected(g,id)>=count)frame(c,f,null,null);}
            else if(key.equals("bubble")&&party!=null&&party.state==GameEngine.State.SNACK)bubble(c,AssetStore.frame(AssetStore.child(layout,"chair_2"),null,0,1),f,party);
            else if(key.equals("dirty")&&t.dirty&&(t.party==null||t.party.state==GameEngine.State.SCORING||t.party.state==GameEngine.State.LEAVING||t.party.state==GameEngine.State.DITCHING))frame(c,f,null,null);
            else if(key.isEmpty())frame(c,f,null,null);
            else if(key.startsWith("setting_")&&party!=null){int chair=Integer.parseInt(key.substring(8))-1,index=(chair-offset+t.colors.length)%t.colors.length;if(index<party.colors.length)setting(c,f,chair==0||t.colors.length==4&&chair==3||t.colors.length==6&&(chair==4||chair==5),g,party,index);}

        }c.restore();
    }
    private void setting(Canvas c,JSONObject f,boolean left,GameEngine g,GameEngine.Party p,int index){c.save();c.translate(AssetStore.value(f,"loc",0,0)-AssetStore.value(f,"regPoint",0,0),AssetStore.value(f,"loc",1,0)-AssetStore.value(f,"regPoint",1,0));JSONObject layout=assets.layout(left?"setting_left":"setting_right");
        if(p.state==GameEngine.State.READY)frame(c,AssetStore.frame(AssetStore.child(layout,"menu_closed"),null,0,1),null,null);
        if(p.state==GameEngine.State.EATING||p.state==GameEngine.State.CHECK){JSONObject food=AssetStore.frame(AssetStore.child(layout,"food"),null,0,1);c.save();c.translate(AssetStore.value(food,"loc",0,0)-AssetStore.value(food,"regPoint",0,0),AssetStore.value(food,"loc",1,0)-AssetStore.value(food,"regPoint",1,0));int type=g.level.stage==5?(p.id+index)%4:g.level.stage-1;simple(c,"food_"+(type*3+(p.id+index)%3+1),p.state==GameEngine.State.EATING?"eating":"empty",p.age,Math.max(1,p.stateDuration/4));c.restore();}c.restore();
    }
    private void bubble(Canvas c,JSONObject anchor,JSONObject f,GameEngine.Party party){c.save();c.translate(AssetStore.value(anchor,"loc",0,0),AssetStore.value(anchor,"loc",1,0));c.scale((f.optInt("xflip")==1?-1:1)*AssetStore.value(f,"scale",0,1),AssetStore.value(f,"scale",1,1));c.translate(-AssetStore.value(f,"regPoint",0,0),-AssetStore.value(f,"regPoint",1,0));
        frame(c,AssetStore.frame(AssetStore.child(assets.layout("bubble"),"bubble"),"bubble",party.age,500),null,null);frame(c,AssetStore.frame(AssetStore.child(assets.layout("bubble"),"food"),party.wantedSnack,0,1),null,null);c.restore();}
    public void bar(Canvas c,GameEngine g,float x,float y,GameEngine.Party preview,int previewStart){JSONObject layout=assets.layout("bar");c.save();c.translate(x-20,y-105);List<JSONObject> nodes=AssetStore.children(layout);Collections.sort(nodes,(a,b)->Float.compare(z(a),z(b)));
        for(JSONObject n:nodes){String key=n.optString("nodeID");JSONObject f=AssetStore.frame(n,null,0,1);if(f==null)continue;if(key.equals("bg")){frame(c,f,g.level.stage==5?"gfx.goddess":"gfx.diner",null);continue;}int split=key.lastIndexOf('_');if(split<0)continue;int slot;try{slot=Integer.parseInt(key.substring(split+1))-1;}catch(NumberFormatException e){continue;}if(slot<0||slot>=g.level.barColors.length)continue;
            int tid=g.barTableAt(slot);GameEngine.Table t=tid<0?null:g.level.tables.get(tid);GameEngine.Party party=t==null?null:t.party;int index=t==null?0:slot-t.barStart;if(party==null&&preview!=null&&slot>=previewStart&&slot<previewStart+preview.colors.length){party=preview;index=slot-previewStart;}
            if(key.startsWith("stool_"))frame(c,f,"gfx.room","stool_"+colorName(g.level.barColors[slot]));
            else if(key.startsWith("stoolnum_")&&party==null&&g.barMultiplier(slot)>1)frame(c,f,"gfx.room",colorName(g.level.barColors[slot])+"_"+g.barMultiplier(slot)+"_flip");
            else if(key.startsWith("legs_")&&party!=null&&!departed(party)){JSONObject stool=AssetStore.frame(AssetStore.child(layout,"stool_"+(slot+1)),null,0,1);c.save();c.translate(AssetStore.value(stool,"loc",0,0)-AssetStore.value(f,"loc",0,0),AssetStore.value(stool,"loc",1,0)-AssetStore.value(f,"loc",1,0));frame(c,f,"gfx.people."+colorName(party.colors[index]),party.profile.graphic+"_legs");c.restore();}
            else if(key.startsWith("sitter_")&&party!=null)person(c,party,index,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0),true,false,g.time,g.level.stageId);
            else if(key.startsWith("setting_")&&party!=null)setting(c,f,true,g,party,index);
            else if(key.startsWith("dirty_")&&t!=null&&t.dirty)frame(c,f,null,null);
            else if(key.startsWith("divider_")&&g.barTableAt(slot)!=g.barTableAt(slot+1))frame(c,f,null,null);
        }
        for(int id=0;id<g.level.tables.size();id++){GameEngine.Table t=g.level.tables.get(id);GameEngine.Party party=t.party;if(!t.active||t.barStart<0||party==null)continue;JSONObject a=AssetStore.frame(AssetStore.child(layout,"tablestuff_"+(t.barStart+1)),null,0,1),b=AssetStore.frame(AssetStore.child(layout,"tablestuff_"+(t.barStart+t.colors.length)),null,0,1);c.save();c.translate(AssetStore.value(a,"loc",0,0),(AssetStore.value(a,"loc",1,0)+AssetStore.value(b,"loc",1,0))/2);
            for(JSONObject n:AssetStore.children(assets.layout("bar_tablestuff"))){String key=n.optString("nodeID");JSONObject f=AssetStore.frame(n,null,0,1);if(key.equals("heartrow"))hearts(c,party.mood,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));else if(key.startsWith("tablenum")&&party.state==GameEngine.State.ORDERED){if(!key.equals("tablenum_hilite")||hasFood(g,party.id))frame(c,f,null,key.equals("tablenum")?"big_tablenum_"+g.tableLabel(id):null);}else if(key.equals("check")&&party.state==GameEngine.State.SCORING)frame(c,f,null,null);else if(key.startsWith("checkmark_")&&selected(g,id)>=Integer.parseInt(key.substring(10)))frame(c,f,null,null);}c.restore();
            if(party.state==GameEngine.State.SNACK)bubble(c,AssetStore.frame(AssetStore.child(layout,"stool_"+(t.barStart+(t.colors.length+1)/2)),null,0,1),AssetStore.frame(AssetStore.child(assets.layout("bar_tablestuff"),"bubble"),null,0,1),party);
        }c.restore();
    }
    public RectF bounds(JSONObject f){if(f==null)return new RectF();JSONObject m=assets.member(f.optString("cast"),f.optString("member"));float w=m==null?AssetStore.value(f,"rect",2,0)-AssetStore.value(f,"rect",0,0):m.optInt("width"),h=m==null?AssetStore.value(f,"rect",3,0)-AssetStore.value(f,"rect",1,0):m.optInt("height");float x=AssetStore.value(f,"loc",0,0),y=AssetStore.value(f,"loc",1,0),rx=AssetStore.value(f,"regPoint",0,0),ry=AssetStore.value(f,"regPoint",1,0);float sx=AssetStore.value(f,"scale",0,1),sy=AssetStore.value(f,"scale",1,1);return new RectF(x-rx*sx,y-ry*sy,x+(w-rx)*sx,y+(h-ry)*sy);}
    public JSONObject room(GameEngine g){return assets.layout(BG[g.level.stage-1]);}
    public JSONObject roomFrame(GameEngine g,String key){return AssetStore.frame(AssetStore.child(room(g),key),null,0,1);}
    public float roomX(GameEngine g,String key){JSONObject f=roomFrame(g,key);return AssetStore.value(f,"loc",0,0)-AssetStore.value(f,"regPoint",0,0);}
    public float roomY(GameEngine g,String key){JSONObject f=roomFrame(g,key);return AssetStore.value(f,"loc",1,0)-AssetStore.value(f,"regPoint",1,0);}
    public int selected(GameEngine g,int target){int n=g.currentTarget==target?1:0;for(Integer t:g.destinations)if(t==target)n++;return Math.min(3,n);}
    public boolean hasFood(GameEngine g,int id){for(GameEngine.Item i:g.hands)if(i.type==GameEngine.ItemType.FOOD&&i.party==id)return true;return false;}
    public void hearts(Canvas c,int mood,float x,float y){for(int i=mood;i>=1;i--)image(c,"gfx.people","heart",x-26+52-i*5-2+3,y,false);}
    // Director integer(float) rounds; six-heart arrivals must use the smiling standing pose.
    public void standing(Canvas c,GameEngine.Party p,float x,float y,int picked){JSONObject layout=assets.layout("waitgroup");c.save();c.translate(x,y);for(int i=0;i<p.colors.length;i++){JSONObject f=AssetStore.frame(AssetStore.child(layout,"body_"+(i+1)),null,0,1);String name="standing_"+p.profile.graphic+"_"+(i==picked?4:Math.max(1,Math.min(3,(int)Math.round(p.mood/3.3)+1)));frame(c,f,"gfx.people."+colorName(p.colors[i]),name);}JSONObject f=AssetStore.frame(AssetStore.child(layout,"heartrow"),null,0,1);hearts(c,p.mood,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));c.restore();}
    public void chef(Canvas c,GameEngine g){if(chefGame!=g){chefGame=g;chefCooking=false;chefAlpha=0;chefFrom=0;chefChanged=g.time;chefCycle=g.time;}boolean cooking=false;for(GameEngine.Party p:g.parties)if(p.cookingUntil>0&&g.time<p.cookingUntil)cooking=true;
        if(chefCooking!=cooking){chefCooking=cooking;chefFrom=chefAlpha;chefChanged=g.time;if(cooking)startChef(g.time);}
        float fraction=Math.min(1,(g.time-chefChanged)/(float)(cooking?400:750));chefAlpha=chefFrom+((cooking?1:0)-chefFrom)*fraction;if(chefAlpha<=0)return;
        if(cooking&&g.time-chefCycle>=(chefAnimation.equals("chop")?5:4)*100*chefLoops)startChef(g.time);
        JSONObject f=roomFrame(g,"chef");c.save();c.translate(AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0));c.saveLayerAlpha(null,Math.round(chefAlpha*255));
        // chef.ls animates only loc/member; later frames must retain the initial transform.
        List<JSONObject> nodes=AssetStore.children(assets.layout("chef"));Collections.sort(nodes,(a,b)->Float.compare(z(a),z(b)));
        for(JSONObject n:nodes){JSONObject base=AssetStore.frame(n,null,0,1),pose=AssetStore.frame(n,chefAnimation,g.time-chefCycle,100);c.save();c.translate(AssetStore.value(pose,"loc",0,0)-AssetStore.value(base,"loc",0,0),AssetStore.value(pose,"loc",1,0)-AssetStore.value(base,"loc",1,0));frame(c,base,null,pose.optString("member"));c.restore();}
        c.restore();c.restore();
    }
    private void startChef(long time){chefCycle=time;chefAnimation=animationRandom.nextBoolean()?"chop":"fry";chefLoops=2+animationRandom.nextInt(4);}
    public void flo(Canvas c,GameEngine g,float x,float y){String name=g.level.stage==5?"flo_goddess":"flo";JSONObject layout=assets.layout(name);if(layout==null)return;
        if(animatedGame!=g){animatedGame=g;idleStarted=-1;observedActivity=-1;}
        boolean moving=g.moving();String direction=g.facing();long phase=moving?g.stepTime():0,frameMS=Math.max(1,g.speed/3);
        if(observedActivity!=g.lastActivityAt||moving||!g.hands.isEmpty()||g.atPodium){observedActivity=g.lastActivityAt;idleStarted=-1;nextIdle=g.time+2000+animationRandom.nextInt(4000)+1;}
        if(!moving&&g.hands.isEmpty()&&!g.atPodium&&g.time>=nextIdle&&idleStarted<0){idleStarted=g.time;int r=animationRandom.nextInt(4)+1;idleType=Math.min(3,r);idleLoops=idleType==1?1:idleType==2?2+animationRandom.nextInt(2):1+animationRandom.nextInt(5);}
        if(idleStarted>=0){long length=(idleType==1?11*150:idleType==2?4*100:13*100)*idleLoops;if(g.time-idleStarted>=length){idleStarted=-1;nextIdle=g.time+2000+animationRandom.nextInt(4000)+1;}}
        JSONObject body=AssetStore.child(layout,"body"),base=AssetStore.frame(body,null,0,1);
        c.save();c.translate(x-AssetStore.value(base,"loc",0,0),y-AssetStore.value(base,"loc",1,0)-30);
        String legAnimation=direction+(moving?"_"+(g.walkStep%2):"_stop");
        String bodyAnimation=g.hands.isEmpty()?legAnimation:direction+"_carry_"+Math.min(2,g.hands.size())+(moving?"":"_stop");
        if(g.level.stage==5){frame(c,AssetStore.frame(AssetStore.child(layout,""),null,0,1),null,null);frame(c,AssetStore.frame(AssetStore.child(layout,"head"),"head_anim",g.time,200),null,null);frame(c,AssetStore.frame(body,"body_anim",g.time,100),null,null,base);frame(c,AssetStore.frame(AssetStore.child(layout,"arms"),"carry_"+g.hands.size(),0,1),null,null);}
        else if(g.atPodium){frame(c,AssetStore.frame(body,"podium_2",g.time-g.lastActivityAt,100),null,null,base);}
        else if(idleStarted>=0){frame(c,AssetStore.frame(body,"idle_"+idleType,g.time-idleStarted,idleType==1?150:100),null,null,base);}
        else {frame(c,AssetStore.frame(AssetStore.child(layout,"legs"),legAnimation,phase,frameMS),null,null);frame(c,AssetStore.frame(body,bodyAnimation,phase,frameMS),null,null,base);}
        for(int i=0;i<Math.min(g.capacity,g.hands.size());i++){GameEngine.Item item=g.hands.get(i);JSONObject n=AssetStore.child(layout,(item.type==GameEngine.ItemType.FOOD?"food_":"payload_")+(i+1));JSONObject f=AssetStore.frame(n,g.level.stage==5?null:direction+(moving?"":"_stop"),phase,frameMS);
            if(item.type==GameEngine.ItemType.FOOD){c.save();c.translate(AssetStore.value(f,"loc",0,0)-AssetStore.value(f,"regPoint",0,0),AssetStore.value(f,"loc",1,0)-AssetStore.value(f,"regPoint",1,0));for(String k:new String[]{"tray","","tablenum"}){JSONObject ff=AssetStore.frame(AssetStore.child(assets.layout("food_payload"),k),g.level.stage==4&&!k.equals("tray")?"chez":g.level.stageId,0,1);GameEngine.Party p=g.party(item.party);frame(c,ff,null,k.equals("tablenum")&&p!=null?"tablenum_"+g.tableLabel(p.table):null);}c.restore();}
            else {String mem=item.type==GameEngine.ItemType.TICKET?"ticket_payload":item.type==GameEngine.ItemType.DISHES?"dishes_payload":item.type==GameEngine.ItemType.DRINK?"drink_flo":item.type.name().toLowerCase(Locale.ROOT)+"_payload";frame(c,f,item.type==GameEngine.ItemType.DRINK?"gfx."+g.level.stageId:"gfx.room",mem);}
        }c.restore();
    }
}
