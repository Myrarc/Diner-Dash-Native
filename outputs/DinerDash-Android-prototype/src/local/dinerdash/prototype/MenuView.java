package local.dinerdash.prototype;

import android.content.Context;
import android.graphics.*;
import android.os.SystemClock;
import android.view.*;
import org.json.*;
import java.util.*;

/** Bitmap screen controls keep their Director layout positions and registration points. */
public final class MenuView extends View {
    public interface Listener { void menuAction(String action); }
    private final SpriteRenderer sprites;
    private final Listener listener;
    private final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Map<String,RectF> buttons=new LinkedHashMap<>();
    public String screen="title_screen",underlay="title_screen",profile="",intro="",result="";
    public String[] profiles=new String[10];
    public int selected=1,current=1,unlocked=1,page=1,profileSlot,hiscoreMode;
    public boolean music=true,sfx=true,fullscreen=true,gameOver;
    public final boolean[] experts=new boolean[50];
    public final String[][] scoreNames=new String[4][10];
    public final int[][] scoreValues=new int[4][10];
    public int totalScore;
    public GameEngine game;
    public List<GameEngine.Upgrade> upgradeChoices=Collections.emptyList();
    private float scale=1,offsetX,offsetY;
    private String pressed="";
    private long opened;
    public MenuView(Context c,AssetStore assets,Listener listener){super(c);sprites=new SpriteRenderer(assets);this.listener=listener;Arrays.fill(profiles,"");setFocusable(true);}
    public void show(String name){screen=name;pressed="";opened=SystemClock.uptimeMillis();setVisibility(VISIBLE);invalidate();setContentDescription("Diner Dash "+name);}
    @Override protected void onSizeChanged(int w,int h,int oldw,int oldh){scale=Math.min(w/800f,h/600f);offsetX=(w-800*scale)/2;offsetY=(h-600*scale)/2;}
    private Typeface textFace(){return screen.equals("startlevel")||screen.equals("login")||screen.equals("hiscore")||screen.equals("endless_shop")?sprites.assets.mrB:Typeface.create("casual",Typeface.NORMAL);}
    private void text(Canvas c,String s,float x,float y,float size,int color){text(c,s,x,y,size,color,textFace());}
    private void text(Canvas c,String s,float x,float y,float size,int color,Typeface face){paint.setTypeface(face);paint.setTextSize(size);paint.setTextAlign(Paint.Align.LEFT);paint.setColor(color);c.drawText(s,x,y,paint);}
    private void fittedText(Canvas c,String s,float x,float y,float width,float size,int color,Typeface face){paint.setTypeface(face);paint.setTextSize(size);float measured=paint.measureText(s);if(measured>width)size*=width/measured;text(c,s,x,y,size,color,face);}
    private void paragraph(Canvas c,String s,float x,float y,float width,float size){String[] lines=s.replace('\r','\n').split("\n",-1);paint.setTypeface(textFace());paint.setTextSize(size);for(String line:lines){String row="";for(String word:line.split(" ")){if(!row.isEmpty()&&paint.measureText(row+" "+word)>width){text(c,row,x,y,size,screen.equals("startlevel")?0xffffffff:0xff34342e);y+=size*1.15f;row=word;}else row+=(row.isEmpty()?"":" ")+word;}text(c,row,x,y,size,screen.equals("startlevel")?0xffffffff:0xff34342e);y+=size*1.15f;}}
    private void receiptText(Canvas c){List<String> rows=new ArrayList<>();float size=21,lineHeight;paint.setTypeface(Typeface.create("casual",Typeface.NORMAL));
        do{rows.clear();paint.setTextSize(size);for(String line:result.replace('\r','\n').split("\n",-1)){String row="";for(String word:line.split(" ")){if(!row.isEmpty()&&paint.measureText(row+" "+word)>243){rows.add(row);row=word;}else row+=(row.isEmpty()?"":" ")+word;}rows.add(row);}lineHeight=paint.getFontSpacing();if(rows.size()*lineHeight<=81||size<=10)break;size--;}while(true);
        float y=249-paint.ascent();c.save();c.clipRect(327,249,570,330);for(String row:rows){text(c,row,327,y,size,0xff34342e);y+=lineHeight;}c.restore();}
    private boolean visible(String layout,String id){if(id.equals("anchor")||id.equals("mousetrap")||id.equals("fadeout")||id.startsWith("const_anim")||id.startsWith("sparkle")||id.startsWith("statue_")&&!id.equals("statue_cover")||id.equals("unlockall_button")||id.equals("lockall_button"))return false;
        if(layout.equals("title_screen")&&(id.equals("username_txt")||id.equals("user_bg")||id.equals("login_button")))return !profile.isEmpty();
        if(layout.equals("career_setup")){if(id.equals("newgame_button"))return selected!=current||selected==1||gameOver;if(id.equals("play_button"))return selected==current&&selected!=1&&!gameOver;if(id.startsWith("rest_")&&id.length()==6)return Integer.parseInt(id.substring(5))<=(unlocked-1)/10+1;if(id.equals("statue_cover")||id.equals("rest5_dots"))return unlocked>40;if(id.startsWith("lvlbutton_")){String[] v=id.split("_");return (Integer.parseInt(v[1])-1)*10+Integer.parseInt(v[2])<=unlocked;}}
        if(layout.equals("endless_setup")){if(id.equals("diff_dialog"))return false;if(id.startsWith("rest_")&&id.length()==6)return Integer.parseInt(id.substring(5))<=(unlocked-1)/10+1;if(id.equals("statue_cover"))return unlocked>40;}
        if(layout.equals("help")){if(id.equals("previous"))return page>1;if(id.equals("next"))return page<6;if(id.equals("version"))return false;if(id.equals("credits"))return page!=6;if(id.equals("instructions"))return page==6;}
        if(layout.equals("login")&&id.equals("ok"))return false;
        if(layout.equals("hiscore")){if(id.equals("leftarrow"))return hiscoreMode>0;if(id.equals("rightarrow"))return hiscoreMode<3;}
        if(layout.equals("endless_shop")){if(id.equals("check"))return false;if(id.equals("continue_button"))return upgradeChoices.isEmpty();if(id.matches("item_[1-3]"))return Integer.parseInt(id.substring(5))<=upgradeChoices.size();}
        if(layout.equals("endlevel_window")){if(id.equals("flo_win"))return game.won;if(id.equals("flo_lose"))return !game.won;if(id.equals("continue_button"))return game.won&&!gameOver;if(id.equals("tryagain_button"))return !game.won&&!gameOver;if(id.equals("quit_button"))return gameOver;if(id.equals("expert_star"))return game.score>=game.level.expert&&game.won;}
        return true;
    }
    private String normalMember(String layout,String id,JSONObject f){if(layout.equals("endless_shop")&&id.matches("item_[1-3]"))return "endshop_"+upgradeChoices.get(Integer.parseInt(id.substring(5))-1).type;if(layout.equals("career_setup")&&id.startsWith("lvlbutton_")){String[] a=id.split("_");int n=(Integer.parseInt(a[1])-1)*10+Integer.parseInt(a[2]);String type=n==current&&n!=1&&!gameOver?"lvlcontinue":experts[n-1]?"leveldot_star":"leveldot";return type+(n==selected?"_selected":"_normal");}
        if(layout.equals("career_setup")||layout.equals("endless_setup")){if(id.equals("menu_button"))return "button_back_to_menu";}
        if(layout.equals("options")&&id.contains("_")){String[] parts=id.split("_");boolean on=parts[0].equals("music")?music:parts[0].equals("sfx")?sfx:fullscreen;if(parts[1].equals("on")||parts[1].equals("off"))return "opt_"+parts[1]+((on==parts[1].equals("on"))?"_hilite":"");}
        if(layout.equals("login")&&id.equals("box_"+(profileSlot+1)))return "login_selected";
        return f.optString("member");}
    private String rollover(String member){if(member.equals("button_new_game"))return "button_new_game_up";if(member.equals("opt_ok"))return "opt_ok_rollover";if(member.startsWith("pause"))return member.replace("_off","_on");if(member.endsWith("_normal"))return member.replace("_normal","_rollover");if(member.startsWith("diff_"))return member.replace("_off","_on");if(member.startsWith("login_"))return member+"_up";String on=member+"_on";return sprites.assets.member("gfx.screens",on)==null?member:on;}
    private boolean control(String id){return id.matches("item_[1-3]")||id.endsWith("button")||id.endsWith("_button")||id.startsWith("lvlbutton_")||id.startsWith("diff_")&&!id.equals("diff_dialog")||id.startsWith("box_")||Arrays.asList("cancel","delete","play","ok","closediff","instructions","credits","next","previous","rightarrow","leftarrow","arrow","music_on","music_off","sfx_on","sfx_off","fs_on","fs_off","rest_1","rest_2","rest_3","rest_4","rest_5").contains(id);}
    private void drawLayout(Canvas c,String name,float dx,float dy){JSONObject layout=sprites.assets.layout(name);List<JSONObject> nodes=AssetStore.children(layout);Collections.sort(nodes,(a,b)->Float.compare(z(a),z(b)));long t=SystemClock.uptimeMillis()-opened;c.save();c.translate(dx,dy);
        for(JSONObject n:nodes){String id=n.optString("nodeID");if(!visible(name,id))continue;String animation=name.equals("help")?(page==6?"credits":String.valueOf(page)):name.equals("comic")?"page_"+page:name.equals("startlevel_window")?"level_"+game.level.stage+"_"+((game.level.number-1)%10+1):null;
            long ms=150,time=t;if(name.equals("title_screen")){if(id.equals("eyes")){animation="blink";time=t%3600<280?t%3600:0;ms=40;}if(id.equals("hair")){animation="wave";time=t%2600<1400?t%2600:0;ms=200;}}
            JSONObject f=AssetStore.frame(n,animation,time,ms);if(f==null)continue;String mem=normalMember(name,id,f);String action=id;
            boolean button=control(id)&&(!name.equals("career_setup")||!id.startsWith("rest_"))&&(!name.equals("title_screen")||id.endsWith("_button"));if(button){RectF b=sprites.bounds(f);b.offset(dx,dy);buttons.put(action,b);if(pressed.equals(action))mem=rollover(mem);}
            sprites.frame(c,f,null,mem.equals(f.optString("member"))?null:mem);
        }c.restore();}
    private float z(JSONObject n){JSONObject f=AssetStore.frame(n,null,0,1);return f==null?0:(float)f.optDouble("z");}
    @Override protected void onDraw(Canvas c){super.onDraw(c);buttons.clear();if(!screen.equals("pause")&&!screen.equals("startlevel")&&!screen.equals("endlevel")&&!screen.equals("endless_shop"))c.drawColor(Color.BLACK);c.save();c.translate(offsetX,offsetY);c.scale(scale,scale);c.clipRect(0,0,800,600);
        if(screen.equals("options")||screen.equals("quit")||screen.equals("endless_difficulty")){drawLayout(c,underlay,0,0);paint.setColor(0x66000000);c.drawRect(0,0,800,600,paint);buttons.clear();}
        if(screen.equals("pause")||screen.equals("startlevel")||screen.equals("endlevel")||screen.equals("endless_shop")){paint.setColor(0x44000000);c.drawRect(0,0,800,600,paint);}
        if(screen.equals("startlevel")){drawLayout(c,"startlevel_window",75,28);paragraph(c,intro,210,134,365,22);text(c,"GOAL: "+game.goal,240,425,25,0xffffffff);}
        else if(screen.equals("endlevel")){drawLayout(c,"endlevel_window",38,19);receiptText(c);text(c,String.valueOf(game.served),325,220,22,0xff30302a,sprites.assets.mrB);text(c,String.valueOf(game.abandoned),410,220,22,0xff30302a,sprites.assets.mrB);text(c,game.level.stage+"-"+((game.level.number-1)%10+1),498,216,22,0xff30302a);text(c,String.format(Locale.US,"%,d",game.score),472,479,23,0xff30302a);text(c,String.format(Locale.US,"%,d",totalScore),430,523,23,0xff30302a);}
        else drawLayout(c,screen,0,0);
        if(screen.equals("endless_shop")){for(int i=0;i<upgradeChoices.size();i++){JSONObject f=AssetStore.frame(AssetStore.child(sprites.assets.layout("endless_shop"),"itemname_"+(i+1)),null,0,1);float x=AssetStore.value(f,"loc",0,0),width=AssetStore.value(f,"rect",2,0)-AssetStore.value(f,"rect",0,0);if(i<2){JSONObject next=AssetStore.frame(AssetStore.child(sprites.assets.layout("endless_shop"),"itemname_"+(i+2)),null,0,1);width=Math.min(width,AssetStore.value(next,"loc",0,0)-x-4);}paragraph(c,upgradeChoices.get(i).name,x,AssetStore.value(f,"loc",1,0)+19,width,18);}if(pressed.startsWith("item_"))paragraph(c,upgradeChoices.get(Integer.parseInt(pressed.substring(5))-1).description,179,123,450,18);
            for(String type:new String[]{"drinks","shoes","oven","podium","stereo","maitred"}){int count=game.upgrades.containsKey(type)?game.upgrades.get(type):0;GameEngine.Upgrade u=count==0?null:LevelData.upgrade(type,count-1);JSONObject f=AssetStore.frame(AssetStore.child(sprites.assets.layout("endless_shop"),"text_"+type),null,0,1);paragraph(c,u==null?"None":u.name,AssetStore.value(f,"loc",0,0),AssetStore.value(f,"loc",1,0)+18,AssetStore.value(f,"rect",2,0)-AssetStore.value(f,"rect",0,0),16);}}
        if(screen.equals("title_screen")&&!profile.isEmpty())fittedText(c,profile,491,585,166,17,Color.BLACK,sprites.assets.komikaAxis);
        if(screen.equals("options"))for(int y:new int[]{274,314,354})text(c,"/",464,y+20,22,Color.WHITE,sprites.assets.mrB);
        if(screen.equals("pause")){paint.setTypeface(sprites.assets.mrB);paint.setTextSize(36);paint.setColor(Color.WHITE);paint.setTextAlign(Paint.Align.CENTER);c.drawText("game paused",414,255,paint);paint.setTextSize(18);c.drawText("( If you quit, you may resume later",415,390,paint);c.drawText("at the start of this level )",415,410,paint);paint.setTextAlign(Paint.Align.LEFT);}
        if(screen.equals("login")){for(int i=0;i<10;i++)fittedText(c,profiles[i].isEmpty()?"New Player":profiles[i],260,138+i*40,268,22,0xff30302a,sprites.assets.mrB);}
        if(screen.equals("hiscore")){text(c,new String[]{"Flo's career","endless (easy)","endless (medium)","endless (hard)"}[hiscoreMode],207,151,28,Color.WHITE);for(int i=0;i<10;i++){JSONObject nf=AssetStore.frame(AssetStore.child(sprites.assets.layout("hiscore"),"name_"+(i+1)),null,0,1),sf=AssetStore.frame(AssetStore.child(sprites.assets.layout("hiscore"),"score_"+(i+1)),null,0,1);fittedText(c,(i+1)+". "+scoreNames[hiscoreMode][i],AssetStore.value(nf,"loc",0,0),AssetStore.value(nf,"loc",1,0)+19,AssetStore.value(nf,"rect",2,0)-AssetStore.value(nf,"rect",0,0),22,Color.WHITE,sprites.assets.mrB);text(c,String.valueOf(scoreValues[hiscoreMode][i]),AssetStore.value(sf,"loc",0,0),AssetStore.value(sf,"loc",1,0)+19,22,Color.WHITE);}}
        c.restore();postInvalidateDelayed(40);}
    @Override public boolean onTouchEvent(MotionEvent e){float x=(e.getX()-offsetX)/scale,y=(e.getY()-offsetY)/scale;int a=e.getActionMasked();if(a==MotionEvent.ACTION_DOWN){pressed="";for(Map.Entry<String,RectF> b:buttons.entrySet())if(b.getValue().contains(x,y))pressed=b.getKey();invalidate();return true;}if(a==MotionEvent.ACTION_CANCEL){pressed="";invalidate();return true;}if(a==MotionEvent.ACTION_UP){String key=pressed;pressed="";RectF b=buttons.get(key);if(b!=null&&b.contains(x,y)){performClick();listener.menuAction(key);}invalidate();return true;}return true;}
    @Override public boolean performClick(){super.performClick();return true;}
}
