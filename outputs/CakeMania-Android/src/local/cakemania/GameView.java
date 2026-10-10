package local.cakemania;

import android.content.Context;
import android.graphics.*;
import android.view.*;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/* THESIS: Recover the supplied game's equipment interactions from its binary.
 * OWN-WORLD: Preserve original room artwork, machine sprites, colors and fonts.
 * STORY: Give menus, select a pictured shape/color/topper, deliver and collect.
 * FIRST VIEWPORT: Show purchased equipment only; hit targets sit on its sprites.
 * MATERIAL/MOTION: Keep the existing asset renderer and queued movement while
 * consuming authored animation, machine, map and HUD data where recovered.
 */
public final class GameView extends View {
    public static final class Control {
        public final String key,label;public final float x,y,w,h;
        public Control(String key,String label,float x,float y,float w,float h){this.key=key;this.label=label;this.x=x;this.y=y;this.w=w;this.h=h;}
    }
    private final MainActivity activity;
    private final AssetStore assets;
    private final Paint paint=new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG);
    private final List<Node> mapPoints=new ArrayList<>();
    private final Node shopLayout;
    private static final float MENU_X=310,MENU_Y=16;
    public float scale=1,ox,oy,clock;
    public final List<Control> controls=new ArrayList<>();
    public GameView(Context context,MainActivity activity,AssetStore assets){super(context);this.activity=activity;this.assets=assets;try{Node points=activity.data.readConfig("mapscreen/pathes.xml").first("Nodes");if(points!=null)mapPoints.addAll(points.children);shopLayout=activity.data.readConfig("shopcareerscreen/shop_env.xml").first("RenderBackground");}catch(Exception error){throw new IllegalStateException("Missing authored screen layout",error);}setBackgroundColor(Color.BLACK);setImportantForAccessibility(IMPORTANT_FOR_ACCESSIBILITY_NO);}
    @Override protected void onSizeChanged(int w,int h,int oldw,int oldh){scale=Math.min(w/800f,h/600f);ox=(w-800*scale)/2;oy=(h-600*scale)/2;
        // Adding overlay buttons during the parent's layout leaves them unmeasured on cold launch.
        post(activity::syncControls);
    }
    private void text(Canvas c,String s,float x,float y,float size,int color){assets.font("EclatICG16").draw(c,s,x,y,size,color);}
    private void center(Canvas c,String s,float x,float y,float size,int color){assets.font("EclatICG16").center(c,s,x,y,size,color);}
    private void wrap(Canvas c,String s,float x,float y,float w,float size,int color){assets.font("EclatICG16").wrap(c,s,x,y,w,size,color);}
    private void panel(Canvas c,float x,float y,float w,float h,int color){int previous=paint.getColor();paint.setColor(color);c.drawRoundRect(new RectF(x,y,x+w,y+h),12,12,paint);paint.setColor(previous);}
    private void button(Canvas c,Control b){assets.draw(c,"IMAGE_BUTTON_MMENU_NORMAL",b.x,b.y,b.w,b.h);float size=Math.min(25,25*(b.w-20)/Math.max(1,assets.font("EclatICG16").width(b.label,25)));center(c,b.label,b.x+b.w/2,b.y+(b.h-size)/2,size,0xffffedb4);}
    private void control(String key,String text,float x,float y,float w,float h){controls.add(new Control(key,text,x,y,w,h));}
    private void menuControls(String prefix,String[] labels){
        Bitmap header=assets.image("IMAGE_BUTTON_MMENU_LAYER0"),row=assets.image("IMAGE_BUTTON_MMENU_LAYER1"),button=assets.image("IMAGE_BUTTON_MMENU_NORMAL");
        float x=MENU_X+(header.getWidth()-button.getWidth())/2f,y=MENU_Y+header.getHeight()+(row.getHeight()-button.getHeight())/2f;
        for(int i=0;i<labels.length;i++)control(prefix+i,labels[i],x,y+i*row.getHeight(),button.getWidth(),button.getHeight());
    }
    public void rebuildControls(){controls.clear();String screen=activity.screen;GameEngine g=activity.game;
        if(screen.equals("menu"))menuControls("menu",new String[]{"Play","High Scores","Options","Help","Exit","Profiles"});
        else if(screen.equals("playmenu"))menuControls("play",new String[]{"Start New Game","Continue Career","Choose Month","Back"});
        else if(screen.equals("profiles")){for(int i=0;i<activity.profileIds.size();i++)control("profile:"+activity.profileIds.get(i),activity.profileName(activity.profileIds.get(i)),290,150+i*44,320,36);if(activity.profileIds.size()<6)control("profile:new","New Player",290,430,320,38);control("profile:back","Back",290,480,320,38);}
        else if(screen.equals("map")){for(int n=1;n<=48;n++){Node point=mapPointForLevel(n);if(point!=null)control("map:level:"+n,""+n,point.f("x",0)-22,point.f("y",0)-19,44,39);}control("map:back","Back",30,548,190,40);}
        else if(screen.equals("endless")){for(int i=0;i<4;i++)control("endless:bakery:"+i,"Bakery "+(i+1),250,135+i*48,300,38);String[] d={"Easy","Medium","Hard"};for(int i=0;i<3;i++)control("endless:difficulty:"+d[i].toLowerCase(Locale.US),d[i],250,345+i*40,300,32);control("endless:start","Play Endless",250,470,300,40);control("endless:back","Back",30,530,180,40);}
        else if(screen.equals("story")){control("next","Continue",560,536,205,44);control("menu","Main Menu",30,536,205,44);}
        else if(screen.equals("intro")){control("start","Let's Play!",318,473,300,48);control("menu","Main Menu",30,536,200,44);}
        else if(screen.equals("game")&&g!=null){
            boolean tutorial=activity.tutorialWaiting();
            if(!tutorial){control("pause","Menu",6,556,122,34);
            for(Station s:g.stations)if(s.enabled())control("station:"+s.guid,s.def.s("name",s.kind),s.x,s.y,s.w,s.h);
            // Native 0x00434480 / 0x00435820 hit the Form rectangles on each machine.
            // Add these above the body targets so color/shape taps cannot become pickups.
            for(Station s:g.stations)if(s.enabled()&&(s.kind.equals("CakeOven")||s.kind.equals("Froster")||s.kind.equals("Decoration")))for(Node f:s.def.children)if(f.tag.equals("Form"))control("form:"+s.guid+":"+f.i("id",0),s.def.s("name",s.kind)+": "+formName(s,f),s.x+f.f("x",0),s.y+f.f("y",0),f.f("width",0),f.f("height",0));
            // Native 004440a0/0043b1f0 hit each FormShelf child independently.  Keep
            // the key separate from Form: the parent input router can pass the child
            // id to the engine without accidentally treating it as a frosting button.
            for(Station s:g.stations)if(s.enabled()&&(s.kind.equals("CookieOven")||s.kind.equals("DisplayCase")))for(Node shelf:s.def.children)if(shelf.tag.equals("FormShelf"))control("shelf:"+s.guid+":"+shelf.i("id",0),s.s("name",s.kind)+" "+shelf.i("id",0),s.x+shelf.f("x",0),s.y+shelf.f("y",0),shelf.f("width",29),shelf.f("height",29));
            for(Station s:g.stations)if(s.enabled()&&s.kind.equals("TVSet")){Node f=s.def.first("Form");if(f!=null)control("form:"+s.guid+":"+f.i("id",0),"Change TV channel",s.x+f.f("x",0),s.y+f.f("y",0),f.f("width",0),f.f("height",0));}
            for(Customer customer:g.customers)addCustomerControl(customer);
            }else addTutorialTarget(g);
        }
        else if(screen.equals("pause")){control("resume","Resume",250,250,300,50);control("restart","Restart Month",250,320,300,50);control("menu","Main Menu",250,390,300,50);}
        else if(screen.equals("gameover")){control("restart","Restart Career",250,330,300,48);control("menu","Main Menu",250,400,300,48);}
        else if(screen.equals("result")){control("next",g.won?(g.level.number==48?"Finish Career":"Continue"):"Try Again",318,500,300,48);control("menu","Main Menu",30,536,200,44);}
        else if(screen.equals("shop")){
            float x=shopLayout.f("x",163),y=shopLayout.f("y",20),sx=shopLayout.f("scale_x",.75f),sy=shopLayout.f("scale_y",.75f);
            for(Node u:activity.shopChoices()){Station station=g.station(u.s("guid"));if(station!=null)control("shop:select:"+station.guid,u.s("name"),x+sx*station.x,y+sy*station.y,sx*station.w,sy*station.h);else if(u.s("guid").equals("jill")){RectF body=shopJillBounds();control("shop:select:jill",u.s("name"),body.left,body.top,body.width(),body.height());}}
            for(Node b:shopLayout.children)if(b.tag.equals("Button"))control(b.s("guid").equals("finish")?"continue":"shop:buy",b.s("text"),b.f("x",0),b.f("y",0),b.f("w",0),b.f("h",0));
        }
        else if(screen.equals("career")){int bakery=activity.careerBakery;for(int i=0;i<12;i++){int n=bakery*12+i+1;control("level:"+n,activity.data.level(n).name+(n>activity.unlocked?" (locked)":""),60+i%3*235,130+i/3*91,210, 70);}control("bakeryprev","Previous Bakery",30,536,240,44);control("bakerynext","Next Bakery",310,536,230,44);control("menu","Main Menu",570,536,200,44);}
        else if(screen.equals("options")){control("music","Music: "+(activity.audio.musicEnabled?"On":"Off"),310,180,318,39);control("musicSlider","Music Volume",410,240,220,30);control("sound","Sounds: "+(activity.audio.enabled?"On":"Off"),310,325,318,39);control("soundSlider","Sfx Volume",410,385,220,30);control("menu","Main Menu",310,475,318,39);}
        else if(screen.equals("help")){control("helpnext","Next",550,536,210,44);control("menu","Main Menu",30,536,210,44);}
        else if(screen.equals("scores")||screen.equals("complete"))control("menu","Main Menu",250,520,300,48);
    }
    public static String formName(Station s,Node f){if(s.kind.equals("CakeOven")){String[] a={"Tree","Square","Star","Round","Egg","Heart","Pumpkin","Triangle"};return a[Math.min(7,f.i("id",0))];}return f.s("name","Select");}
    private Node mapPointForLevel(int number){int bakery=(number-1)/12,month=(number-1)%12;List<Node> levels=activity.mapLevels();if(bakery<0||bakery>=levels.size())return null;for(Node candle:levels.get(bakery).children)if(candle.tag.equals("Candle")&&candle.i("id",-1)==month){int point=candle.i("point",-1);if(point>=0&&point<mapPoints.size())return mapPoints.get(point);}return null;}
    @Override protected void onDraw(Canvas c){super.onDraw(c);c.save();c.translate(ox,oy);c.scale(scale,scale);c.clipRect(0,0,800,600);String screen=activity.screen;
        if(screen.equals("game")||screen.equals("pause"))drawGame(c);
        else if(screen.equals("menu")||screen.equals("playmenu"))drawMenu(c);
        else if(screen.equals("map"))drawMap(c);
        else if(screen.equals("story"))assets.draw(c,activity.storyImages.get(activity.storyPage),0,0,800,600);
        else if(screen.equals("intro")||screen.equals("result"))drawMonth(c,screen.equals("result"));
        else if(screen.equals("help"))drawHelp(c);
        else if(screen.equals("gameover"))drawGameOver(c);
        else if(screen.equals("complete"))assets.draw(c,"IMAGE_COMICS_FINAL",0,0,800,600);
        else if(screen.equals("shop"))drawShop(c);
        else {assets.draw(c,"IMAGE_BGR0",0,0,800,600);panel(c,20,60,760,525,0xedfff0cf);if(screen.equals("career"))drawCareer(c);else if(screen.equals("profiles"))drawProfiles(c);else if(screen.equals("endless"))drawEndless(c);else if(screen.equals("options"))drawOptions(c);else if(screen.equals("scores"))drawScores(c);else if(screen.equals("complete")){center(c,"The Evans Bakery is saved!",400,130,34,0xff712f37);wrap(c,"You have finished all four bakeries and all 48 career months. Your best earnings are saved on this device.",140,245,520,24,0xff4c2635);}}
        if(screen.equals("pause")){panel(c,120,120,560,405,0xe8fff0cf);center(c,"Paused",400,160,38,0xff712f37);}
        for(Control b:controls)if(!screen.equals("game")&&!screen.equals("shop")&&!screen.equals("map")&&!((screen.equals("options"))&&(b.key.equals("musicSlider")||b.key.equals("soundSlider"))))button(c,b);
        c.restore();
    }
    private void drawMenu(Canvas c){assets.draw(c,"IMAGE_BGR0",0,0,800,600);assets.draw(c,"IMAGE_MMENU_JILL",62,62,272,526);float y=MENU_Y;assets.draw(c,"IMAGE_BUTTON_MMENU_LAYER0",MENU_X,y);y+=assets.image("IMAGE_BUTTON_MMENU_LAYER0").getHeight();int count=activity.screen.equals("menu")?6:4;for(int i=0;i<count;i++){String row=i%2==0?"IMAGE_BUTTON_MMENU_LAYER1":"IMAGE_BUTTON_MMENU_LAYER2";assets.draw(c,row,MENU_X,y);y+=assets.image(row).getHeight();}assets.draw(c,"IMAGE_BUTTON_MMENU_LAYER3",MENU_X,y);
        for(int i=1;i<=4;i++){Bitmap f=assets.frame("IMAGE_MMENU_FIRE"+i,10,1,(int)(clock/0.07f));float[] x={83,129,345,379},yy={10,20,25,10};c.drawBitmap(f,MENU_X+x[i-1],MENU_Y+yy[i-1],paint);}
    }
    private void drawProfiles(Canvas c){center(c,"Select Player",400,112,38,0xff712f37);for(int i=0;i<activity.profileIds.size();i++){String id=activity.profileIds.get(i);float y=176+i*44;text(c,activity.activeProfileId.equals(id)?">":"",245,y,24,0xff712f37);text(c,activity.profileName(id),280,y,22,0xff512432);}}
    private void drawEndless(Canvas c){center(c,"Endless Play",400,105,38,0xff712f37);text(c,"Bakery",255,145,20,0xff512432);text(c,"Difficulty: "+activity.endlessDifficulty,255,330,20,0xff512432);}
    private void drawOptions(Canvas c){center(c,"Options",400,105,38,0xff712f37);text(c,"Music volume: "+Math.round(activity.audio.musicVolume*100)+"%",270,230,18,0xff512432);text(c,"Sfx volume: "+Math.round(activity.audio.soundVolume*100)+"%",270,375,18,0xff512432);drawSlider(c,activity.audio.musicVolume,434,250);drawSlider(c,activity.audio.soundVolume,434,395);}
    private void drawSlider(Canvas c,float value,float x,float y){assets.draw(c,"IMAGE_SLIDER_TRACK",x,y);float thumbX=x+Math.max(0,Math.min(1,value))*(172-20);assets.draw(c,"IMAGE_SLIDER_THUMB",thumbX,y-5);}
    private void addTutorialTarget(GameEngine g){
        TutorialController tutorial=activity.tutorial;if(tutorial==null)return;
        Node event=tutorial.currentEvent();if(event==null)return;
        String type=event.s("type");
        if(type.equals("WaitForClick")){
            float x=event.f("x",0),y=event.f("y",0),w=event.f("w",0),h=event.f("h",0);
            // Flow forwards this key's authored center to tutorialClick, then
            // resolves the same point against the underlying game controls.
            String key=String.format(Locale.US,"tutorial:%.3f:%.3f",x+w/2f,y+h/2f);
            control(key,"",x,y,w,h);
        }else if(type.equals("WaitForCustomerClick")){
            for(Customer customer:g.customers){
                // Tutorial id 5 is the authored profile id, not the runtime
                // serial. The scripted host always marks that profile tutor.
                if(!"tutor".equals(customer.profile.s("guid")))continue;
                addCustomerControl(customer);
            }
        }
    }
    private void drawTutorialOverlays(Canvas c){
        for(TutorialController.Overlay overlay:activity.tutorialOverlays()){
            if(overlay.type.equals("DrawRectText")){
                assets.draw(c,"IMAGE_RECTANGLE",overlay.x,overlay.y,overlay.w,overlay.h);
                assets.font("EclatICG16").wrap(c,overlay.text,overlay.x+10,overlay.y+10,Math.max(1,overlay.w-20),16,0xff512432);
            }else if(overlay.type.equals("DrawArrow")){
                // 0044e130 ignores w/h for arrows; 0049c2f0 rotates with
                // x'=x*cos+y*sin, y'=y*cos-x*sin (opposite Canvas's angle).
                Bitmap arrow=assets.image("IMAGE_ARROW");c.save();c.rotate(-(float)Math.toDegrees(overlay.angle),overlay.x+arrow.getWidth()/2,overlay.y+arrow.getHeight()/2);
                c.drawBitmap(arrow,overlay.x,overlay.y,paint);c.restore();
            }
        }
    }
    private void drawGameOver(Canvas c){assets.draw(c,"IMAGE_GAMEOVER",0,0,800,600);center(c,"GAME OVER",400,70,34,0xff512432);wrap(c,"All lives are gone. Restart the career to try again.",245,180,310,24,0xff512432);}
    private void drawMap(Canvas c){
        assets.draw(c,"IMAGE_MAPSCREEN_BK_LEVEL1",0,0,800,600);
        List<Node> levels=activity.mapLevels();for(int b=0;b<levels.size();b++){Node level=levels.get(b);String background=level.s("img");if(!background.isEmpty())assets.draw(c,background,level.f("x",0),level.f("y",0));for(Node candle:level.children)if(candle.tag.equals("Candle")){int n=b*12+candle.i("id",0)+1;Node point=mapPointForLevel(n);if(point==null)continue;boolean unlocked=n<=activity.unlocked;String icon=level.s(unlocked&&n==activity.unlocked?"img_hl_candle":"img_candle");if(icon.isEmpty())continue;paint.setAlpha(unlocked?255:110);Bitmap ring=assets.image(icon);c.drawBitmap(ring,point.f("x",0)-22,point.f("y",0)-19,paint);paint.setAlpha(255);}}
        assets.draw(c,"IMAGE_MAPSCREEN_BUTTON",30,548,198,41);text(c,"Back",88,560,20,0xff712f37);
    }
    private void drawMonth(Canvas c,boolean result){
        GameEngine g=activity.game;assets.draw(c,"IMAGE_BGR0",0,0,800,600);
        Node authored=result?(g.won?g.level.successScreen:g.level.failureScreen):g.level.startScreen;
        Node image=authored==null?null:authored.first("Image");
        if(image!=null&&!image.s("img").isEmpty())assets.draw(c,image.s("img"),image.f("x",0),image.f("y",0),image.f("w",800),image.f("h",600));
        else assets.draw(c,"IMAGE_BEGINSCREEN",100,8,528,579);
        if(authored!=null){
            // Native 00452ab0/00453a50 choose the font by screen type. The
            // loaders ignore Text font/size; startup 0041d290 scales these fonts.
            AssetStore.BitmapFont font=assets.font(result?"PlainPensleXBold16":"EclatICG16");
            double scale=result?.6666667:(double).95f;
            for(Node n:authored.children)if(n.tag.equals("Text"))font.wrapScreen(c,activity.resultText(n.s("text")),n.f("x",0),n.f("y",0),n.f("w",300),scale,authored.i("spacing",0),Color.BLACK);
        }
        else if(result){wrap(c,g.won?g.level.success:g.level.failure,310,155,310,16,0xff512432);}
    }
    private void drawShop(Canvas c){
        GameEngine g=activity.game;Node selected=activity.selectedShopChoice();
        c.save();c.translate(shopLayout.f("x",163),shopLayout.f("y",20));c.scale(shopLayout.f("scale_x",.75f),shopLayout.f("scale_y",.75f));
        for(Node bg:g.level.environment.first("RenderBackground").children){assets.draw(c,bg.s("img"),bg.f("x",0),bg.f("y",0));for(Station s:g.stations)if(s.def.i("render_after",0)==bg.i("id",0)){
            // 0046fa80 marks unowned equipment; 00434d30 draws it as a dark
            // translucent silhouette. Shop objects have no in-progress cakes.
            if(s.enabled())drawStation(c,new Station(s.def.copy()));
            else if(!s.s("main_img","").isEmpty()){paint.setColorFilter(new PorterDuffColorFilter(0xff000000,PorterDuff.Mode.SRC_IN));paint.setAlpha(122);c.drawBitmap(assets.frame(s.s("main_img",""),s.def.i("wc",1),s.def.i("hc",1),0),null,new RectF(s.x,s.y,s.x+s.w,s.y+s.h),paint);paint.setAlpha(255);paint.setColorFilter(null);}
        }}
        if(selected!=null){Station current=g.station(selected.s("guid"));if(current!=null){Node preview=current.def.copy();preview.merge(selected);c.saveLayerAlpha(null,150);drawStation(c,new Station(preview));c.restore();}}
        c.restore();
        for(Node image:shopLayout.children)if(image.tag.equals("Image")&&!image.s("img").isEmpty())assets.draw(c,image.s("img"),image.f("x",0),image.f("y",0));
        drawShopJill(c);
        if(selected!=null&&!selected.s("icon").isEmpty())assets.draw(c,selected.s("icon"),50,275,150,150);
        for(Node window:shopLayout.children)if(window.tag.equals("Window")){
            String guid=window.s("guid"),value="";
            if(guid.equals("name")&&selected!=null)value=selected.s("name");
            else if(guid.equals("description")&&selected!=null)value=selected.s("description");
            else if(guid.equals("price")&&selected!=null)value=window.s("text")+selected.i("purchase_points",0);
            else if(guid.equals("lives"))value=window.s("text")+activity.lives;
            else if(guid.equals("count"))value=window.s("text")+activity.points;
            else if(guid.equals("money"))value=window.s("text")+activity.bank;
            assets.font("EclatICG16").wrapScreen(c,value,window.f("x",0),window.f("y",0),window.f("w",174),.95,window.i("spacing",0),0xffffffff);
        }
        for(Node b:shopLayout.children)if(b.tag.equals("Button")){boolean enabled=b.s("guid").equals("finish")||(selected!=null&&activity.bank>=selected.i("purchase_points",0));assets.draw(c,b.s(enabled?"img":"img_dis"),b.f("x",0),b.f("y",0),b.f("w",0),b.f("h",0));center(c,b.s("text"),b.f("x",0)+b.f("w",0)/2,b.f("y",0)+8,24,enabled?0xfffeffff:0xffa59da2);}
    }
    private Node shopJillAnimation(){for(Node n:activity.game.level.avatar.first("Avatar").children)if(n.tag.equals("Animation")&&n.i("id",-1)==8)return n;throw new IllegalStateException("Missing shop Jill animation");}
    private RectF shopJillBounds(){Node a=shopJillAnimation();Bitmap frame=assets.frame(a.s("image"),1,a.i("count",1),a.i("count",1)-1);float scale=.75f*SpriteRules.gameplayProjection(440)*a.f("scale",1);return new RectF(430-frame.getWidth()*scale/2,350-frame.getHeight()*scale,430+frame.getWidth()*scale/2,350);}
    private void drawShopJill(Canvas c){Node a=shopJillAnimation();int frame=a.i("count",1)-1;RectF r=shopJillBounds();c.drawBitmap(assets.frame(a.s("image"),1,a.i("count",1),frame),null,r,paint);for(Node u:activity.game.level.avatar.first("Avatar").children)if(u.tag.equals("Upgrade")&&u.i("id",-1)==8&&u.i("idupg",0)==activity.game.shoeStep&&!u.s("image").isEmpty()){Bitmap shoe=assets.frame(u.s("image"),1,u.i("count",a.i("count",1)),frame);float projection=.75f*SpriteRules.gameplayProjection(440)*a.f("scale",1),s=projection*u.f("scale",1),x=r.left+projection*u.f("x_dec",0),y=r.top+projection*u.f("y_dec",0);c.drawBitmap(shoe,null,new RectF(x,y,x+shoe.getWidth()*s,y+shoe.getHeight()*s),paint);}}
    private void drawCareer(Canvas c){center(c,activity.data.level(activity.careerBakery*12+1).bakeryName,400,80,36,0xff712f37);}
    private void drawScores(Canvas c){center(c,"Best Month Earnings",400,100,36,0xff712f37);List<Integer> months=new ArrayList<>();for(int n=1;n<=48;n++)if(activity.saved.getInt("best"+n,0)>0)months.add(n);Collections.sort(months,(a,b)->Integer.compare(activity.saved.getInt("best"+b,0),activity.saved.getInt("best"+a,0)));if(months.isEmpty())center(c,"Finish a month to record your score.",400,240,24,0xff512432);for(int i=0;i<Math.min(8,months.size());i++){int n=months.get(i);Level l=activity.data.level(n);text(c,l.bakeryName+" / "+l.name,90,190+i*37,23,0xff512432);text(c,"$"+activity.saved.getInt("best"+n,0),625,190+i*37,23,0xff512432);}}
    private void drawHelp(Canvas c){assets.draw(c,"IMAGE_BGR0",0,0,800,600);panel(c,35,60,730,460,0xf4fff0cf);center(c,"How to Play",400,82,36,0xff712f37);String[] pages={"Tap a customer to hand out a menu. Once they have read it, their order appears beside the counter.\n\nTap the matching shape button on an oven, then tap its body to pick up the cake when ready. Baking continues while Jill does other jobs.","Tap the matching color on a froster to place and frost a carried cake. Tap its tray to pick it up. A tray tap with a cake in hand only places it. Tap a pictured topper on a decorator when needed.\n\nFor two tiers, leave the first frosted layer on a tray. Bring the second baked layer and tap its frosting color on that machine.","Tap the customer to deliver a matching cake, then tap again to collect the cash.\n\nYou can queue several actions. Customers lose hearts while waiting. Cookies and the television can help once purchased.","Reach the Baker Goal before closing. Serve the remaining customers and collect their payments to finish the month.\n\nBuy equipment between months, then continue your career. Progress, purchases, and best scores are saved on this device."};wrap(c,pages[activity.helpPage%pages.length],85,157,630,28,0xff512432);}
    private void drawGame(Canvas c){GameEngine g=activity.game;if(g==null)return;
        List<Node> bg=g.level.environment.first("RenderBackground").children;
        // 00437d20 draws each background and its render_after equipment, then
        // 0044a630 inserts Jill at layer 0 or 1 according to her floor position.
        for(Node n:bg){int layer=n.i("id",0);assets.draw(c,n.s("img"),n.f("x",0),n.f("y",0));drawEnvironmentAnimations(c,n,g.elapsed);
            for(Station s:g.stations)if(s.def.i("render_after",0)==layer)drawStation(c,s);
            if(layer==SpriteRules.avatarRenderAfter(g.y))drawJill(c);
        }
        List<Customer> sorted=new ArrayList<>(g.customers);Collections.sort(sorted,(a,b)->Integer.compare(b.slot,a.slot));for(Customer customer:sorted)drawCustomer(c,customer);
        // 0044bbe0 calls 004366b0 after customers to restore the last foreground.
        Node foreground=bg.get(bg.size()-1);assets.draw(c,foreground.s("img"),foreground.f("x",0),foreground.f("y",0));
        for(Customer customer:sorted)drawOrder(c,customer);
        for(int i=0;i<g.queue.size();i++){Action a=g.queue.get(i);float xx,yy;if(a.station!=null){Node f=a.station.form(a.form);xx=a.station.x+(f==null?a.station.w/2:f.f("x",0)+f.f("width",0)/2);yy=a.station.y+(f==null?18:f.f("y",0)+f.f("height",0)/2);}else{Node p=g.customerPoints.get(a.customer.slot);xx=p.f("x_money",230)+60;yy=p.f("y_money",500)-20;}panel(c,xx-13,yy-13,28,28,0xffa62039);center(c,""+(i+1),xx,yy-11,22,Color.WHITE);}
        if(g.level.number>0){drawHud(c,g);drawClock(c,g);}
        if(activity.tutorialWaiting())drawTutorialOverlays(c);
    }
    private void drawHud(Canvas c,GameEngine g){
        // The supplied HUD is an authored 800x49 strip at the bottom of the room.
        // Native text is baseline-aligned at y=590; the second draw is its shadow.
        assets.draw(c,"IMAGE_HUD",0,551);
        // 0044c950 centers the 122x34 native Menu image at (67,573).
        assets.draw(c,"IMAGE_BUTTON_MENU",6,556);
        String month=g.level.name;
        hudText(c,month,150,590,0xffffffff);
        hudText(c,"Cash $"+g.money,285,590,0xffffffff);
        hudText(c,g.goalReached?"Baker Goal Complete!":"Baker Goal $"+g.level.goal,430,590,0xffffffff);
        hudText(c,"LIVES",694,590,0xffffffff);
        int lives=optionalInt(activity,"lives",4);
        for(int i=0;i<Math.max(0,Math.min(6,lives));i++){c.save();c.rotate(-(float)Math.toDegrees(i*.349-(lives-1)*.1745),737,650);assets.draw(c,"IMAGE_HUD_STAR",720,550);c.restore();}
    }
    private void drawClock(Canvas c,GameEngine g){
        // 00409ab0 places the original face at (665,-17). 0041ba80 supplies
        // the month duration; 00409c00 pivots the 10x40 hand at (5,35).
        assets.draw(c,"IMAGE_CLOCK",665,-17);float phase=Math.max(0,Math.min(1,g.elapsed/g.level.duration));c.save();c.rotate((float)Math.toDegrees(phase*6.283199787f),725,74);assets.draw(c,"IMAGE_CLOCK_RULER",720,39);c.restore();
    }
    private void hudText(Canvas c,String value,float x,float y,int color){assets.font("EclatICG16").baselineScreen(c,value,x+1,y+1,(double).95f,0xff000000);assets.font("EclatICG16").baselineScreen(c,value,x,y,(double).95f,color);}
    private void drawEnvironmentAnimations(Canvas c,Node parent,float time){for(Node a:parent.children)if(a.tag.equals("ImageAnimation")&&!a.s("curve").isEmpty()){String[] pts=a.s("curve").split(";");if(pts.length<2)continue;int[] from=ints(pts[0]),to=ints(pts[1]);float delay=a.f("starttime",0),duration=Math.max(1,a.f("time",30));if(time<delay)continue;float phase=(time-delay)%duration/duration;Bitmap b=assets.frame(a.s("img"),1,a.i("count",1),(int)((time-delay)/Math.max(.01f,a.f("timing",.1f))));c.drawBitmap(b,from[0]+(to[0]-from[0])*phase,from[1]+(to[1]-from[1])*phase,paint);}}
    private void drawStation(Canvas c,Station s){
        if(!s.enabled())return;
        String id=s.def.s("main_img");
        if(s.kind.equals("CookieOven")){
            float door=s.cookieDoorRemaining;
            id=s.def.s(s.remaining>0?"main_sec_img":(door>0||cookieStockCount(s)>0?"main_thrd_img":"main_img"),id);
        }
        // Trash uses wc=1/hc=3: draw one authored sheet frame, not three bins
        // squeezed into one hit target.
        if(!id.isEmpty())c.drawBitmap(assets.frame(id,s.def.i("wc",1),s.def.i("hc",1),0),null,new RectF(s.x,s.y,s.x+s.w,s.y+s.h),paint);
        if(s.kind.equals("CookieOven")){drawCookieShelves(c,s);return;}
        if(s.kind.equals("TVSet")){Node button=s.def.first("Form"),program=s.form(activity.game.channel+1);if(program!=null){Bitmap frame=activity.game.tvNoise?assets.frame(s.def.s("noise_img"),1,s.def.i("noise_anim_count",4),(int)(clock/.12f)):assets.frame(program.s("image_anim"),1,program.i("count_anim",1),(int)(clock/.12f));c.drawBitmap(frame,null,new RectF(s.x+s.def.f("x_main",19),s.y+s.def.f("y_main",34),s.x+s.def.f("x_main",19)+s.def.f("width_main",49),s.y+s.def.f("y_main",34)+s.def.f("height_main",40)),paint);}if(button!=null)assets.draw(c,button.s("image"),s.x+button.f("x",27),s.y+button.f("y",94),button.f("width",29),button.f("height",24));return;}
        for(Node f:s.def.children)if(f.tag.equals("Form")&&!f.s("image").isEmpty())assets.draw(c,f.s("image"),s.x+f.f("x",0),s.y+f.f("y",0),f.f("width",25),f.f("height",25));
        if(s.kind.equals("CakeOven"))drawOvenPhases(c,s);
        if(s.cake!=null&&!s.kind.equals("CakeOven")){
            if(s.kind.equals("DisplayCase")){Node shelf=s.def.first("FormShelf");if(shelf!=null)cake(c,s.cake,s.x+shelf.f("x",0)+shelf.f("width",85)/2,s.y+shelf.f("y",-8)+shelf.f("height",50),.55f);else cake(c,s.cake,s.x+s.w/2,s.y+50,.65f);}
            else {int[] pt=ints(s.def.s("cake_pt","0,0"));float x=s.x+s.w/2+pt[0],y=s.y+s.h/2+pt[1];cake(c,s.cake,x,y,SpriteRules.stationCakeProjection(y));}
        }
        if(s.remaining>0){Node f=s.form(s.workingForm);if(f!=null&&!f.s("image_anim").isEmpty()&&!f.s("pt_anim").isEmpty()){int[] pt=ints(f.s("pt_anim"));int cols=Math.max(1,f.i("count_anim_vert",1)),rows=Math.max(1,f.i("count_anim",1)),count=cols*rows;Bitmap frame=assets.frame(f.s("image_anim"),cols,rows,(int)((s.total-s.remaining)/Math.max(.01f,s.total)*count));c.drawBitmap(frame,s.x+pt[0],s.y+pt[1],paint);}}
        drawProcessingWheel(c,s);
    }
    private void drawProcessingWheel(Canvas c,Station s){if(s.remaining<=0||s.remaining>=s.total||s.total==0)return;
        // 00434d30 uses DAT_005b9f40 (IMAGE_READYCIRCLE), 16 vertical
        // frames counted backwards as the remaining fraction approaches zero.
        int frame=(int)(15f-15f/s.total*(s.total-s.remaining));c.drawBitmap(assets.frame("IMAGE_READYCIRCLE",1,16,Math.max(0,Math.min(15,frame))),null,new RectF((int)(s.x+s.w/2-15),(int)(s.y+s.h/2-15),(int)(s.x+s.w/2-15)+30,(int)(s.y+s.h/2-15)+30),paint);
    }

    private void drawCookieShelves(Canvas c,Station s){
        int index=0;for(Node shelf:s.def.children)if(shelf.tag.equals("FormShelf")){int id=shelf.i("id",index);if(cookieShelfHasStock(s,id))assets.draw(c,"IMAGE_COOKIE",s.x+shelf.f("x",0),s.y+shelf.f("y",0),shelf.f("width",29),shelf.f("height",29));index++;}
        drawProcessingWheel(c,s);
    }

    private void drawOvenPhases(Canvas c,Station s){
        float phase=Math.max(0f,s.total-s.remaining);
        String overlay=s.remaining==0?"main_door_img":phase<s.freshAt?"main_sec_img":"main_thrd_img";
        // 00434d30 keeps the cabinet and scales interior sprites relative to
        // main_img, at x + .14*w / y + .30*h. These are never whole ovens.
        Bitmap cabinet=assets.image(s.def.s("main_img"));String image=s.def.s(overlay);
        if(!image.isEmpty()){Bitmap part=assets.image(image);float x=(int)(s.x+s.w*.14),y=(int)(s.y+s.h*.30),w=(int)(part.getWidth()*s.w/cabinet.getWidth()),h=(int)(part.getHeight()*s.h/cabinet.getHeight());c.drawBitmap(part,null,new RectF(x,y,x+w,y+h),paint);}
        String trash=s.def.s("main_trash_img");if(!trash.isEmpty())assets.draw(c,trash,s.x,(int)(s.y+s.h*.8),s.w,(int)(s.h*.2));
        int trayFrame=0;
        if(s.remaining>0&&s.cake!=null&&phase>=s.closeAt&&phase<s.closeAt+.2f)trayFrame=(int)((phase-s.closeAt)*5/.2f);
        else if(s.remaining>0&&s.cake!=null&&phase>=s.closeAt+.2f&&phase<s.discardAt)trayFrame=4;
        else if(s.burnt&&phase>=s.discardAt&&phase<s.freshAt)trayFrame=(int)(5-(phase-s.discardAt)*5/(s.freshAt-s.discardAt));
        Bitmap tray=assets.frame("IMAGE_CAKEOVEN_TRAY",1,9,Math.max(0,Math.min(8,trayFrame)));
        float tx=(int)(s.x+s.w*.174),ty=(int)(s.y+s.h*.522),tw=(int)(s.w*.714),th=(int)(s.h*.357);
        c.drawBitmap(tray,null,new RectF(tx,ty,tx+tw,ty+th),paint);
        // The native flame recycles an existing cake, not every empty bake.
        if(s.remaining>0&&s.cake!=null&&phase>=s.closeAt+.4f&&phase<s.discardAt){Bitmap flame=assets.frame("IMAGE_CAKEOVEN_FLAME",1,19,(int)((phase-s.closeAt-.4f)*19/(s.discardAt-s.closeAt-.4f)));float x=(int)(s.x+s.w*.362),y=(int)(s.y+s.h*.2);c.drawBitmap(flame,null,new RectF(x,y,x+(int)(s.w*.391),y+(int)(s.h*.655)),paint);}
        if(s.cake!=null&&(s.remaining==0||phase<s.closeAt+.4f||phase>=s.freshAt)){
            int[] pt=ints(s.def.s("cake_pt","0,0"));float x=s.x+s.w/2+pt[0],y=s.y+s.h/2+pt[1];
            if(s.remaining>0&&phase>=s.freshAt){float retract=1-(phase-s.freshAt)/Math.max(.01f,s.total-s.freshAt);x-=5*retract;y-=25*retract;}
            else if(s.remaining>0&&phase>=s.closeAt+.2f)y+=25*(phase-s.closeAt-.2f)/Math.max(.01f,s.discardAt-s.closeAt-.2f);
            cake(c,s.cake,x,y,SpriteRules.stationCakeProjection(y));
        }
    }
    private boolean cookieShelfHasStock(Station s,int index){return index>=0&&index<s.cookieStock.length&&s.cookieStock[index];}
    private int cookieStockCount(Station s){int count=0;for(boolean present:s.cookieStock)if(present)count++;return count;}
    private static int optionalInt(Object target,String name,int fallback){try{java.lang.reflect.Field f=target.getClass().getField(name);Object value=f.get(target);return value instanceof Number?((Number)value).intValue():fallback;}catch(Exception ignored){return fallback;}}
    private Node customerImage(Customer customer){String state=customer.visualState==1?"ID_MENU":customer.visualState==2?"ID_HAPPY":customer.visualState==3?"ID_BORED":customer.visualState==4?"ID_EATING":customer.state==CustomerState.READING?"ID_MENU":customer.state==CustomerState.HAPPY||customer.state==CustomerState.CASH?"ID_HAPPY":customer.hearts==1?"ID_BORED":"ID_NORMAL";for(Node n:customer.profile.children)if(n.s("id").equals(state))return n;throw new IllegalStateException("Missing customer animation "+state);}
    // 00410fe0 reverses the sequence; 0040d370 reverses its index again, then
    // converts the authored bottom-first pose number to a physical sheet row.
    private Bitmap customerFrame(Customer customer,Node image){int[] order=ints(image.first("Sequence").s("frames"));return assets.frame(image.s("img"),image.i("cols",1),image.i("rows",1),image.i("rows",1)-1-order[Math.floorMod(customer.visualFrame,Math.max(1,order.length))]);}
    private RectF customerSpriteBounds(Customer customer,Node image,Bitmap frame){return customerSpriteBounds(customer,image,frame,customer.slot);}
    private RectF customerSpriteBounds(Customer customer,Node image,Bitmap frame,int slot){Node point=activity.game.customerPoints.get(slot);float projection=image.f("scale",1);int x=(int)(point.f("x",130)-frame.getWidth()*projection/2+customer.hoverX+image.f("xdec",0)),y=(int)(point.f("y",500)-frame.getHeight()*projection-customer.hoverY+image.f("ydec",0));return new RectF(x,y,x+(int)(frame.getWidth()*projection),y+(int)(frame.getHeight()*projection));}
    private RectF customerOrderBounds(Customer customer){Node p=activity.game.customerPoints.get(customer.slot);float x=p.f("x_money",230),y=p.f("y_money",500);return customer.state==CustomerState.CASH?new RectF(x-4,y-25,x+46,y+25):new RectF(x-23,y-83,x+71,y);}
    private void addCustomerControl(Customer customer){if(customer.state==CustomerState.LEAVING||customer.cashCollected)return;Node image=customerImage(customer);RectF r=customer.state==CustomerState.CASH?customerOrderBounds(customer):customerSpriteBounds(customer,image,customerFrame(customer,image));if(customer.state==CustomerState.ORDER)r.union(customerOrderBounds(customer));control("customer:"+customer.serial,customer.profile.s("name")+", "+customer.state+", "+customer.hearts+" hearts",r.left,r.top,r.width(),r.height());}
    public boolean hitsCustomer(Customer customer,float x,float y){
        if(customer.state==CustomerState.LEAVING||customer.cashCollected)return false;
        if((customer.state==CustomerState.ORDER||customer.state==CustomerState.CASH)&&customerOrderBounds(customer).contains(x,y))return true;
        if(!customer.spriteVisible())return false;
        // 0040b2e0 uses the normal sprite rectangle, including transparent
        // pixels. Keep the target stable when a temporary animation changes.
        for(Node image:customer.profile.children)if(image.s("id").equals("ID_NORMAL"))return customerSpriteBounds(customer,image,assets.frame(image.s("img"),image.i("cols",1),image.i("rows",1),0)).contains(x,y);
        return false;
    }
    /** Match the artwork in game coordinates, including overlapping customer sprites. */
    public String gameControlAt(float x,float y){
        for(Control c:controls)if((c.key.equals("pause")||c.key.equals("cancel"))&&new RectF(c.x,c.y,c.x+c.w,c.y+c.h).contains(x,y))return c.key;
        if(activity.screen.equals("game")){List<Customer> front=new ArrayList<>(activity.game.customers);Collections.sort(front,(a,b)->Integer.compare(a.slot,b.slot));
        for(Customer customer:front)if(customer.state==CustomerState.CASH&&hitsCustomer(customer,x,y))for(Control c:controls)if(c.key.equals("customer:"+customer.serial))return c.key;
        for(Customer customer:front)if(customer.state!=CustomerState.CASH&&hitsCustomer(customer,x,y))for(Control c:controls)if(c.key.equals("customer:"+customer.serial))return c.key;}
        for(int i=controls.size()-1;i>=0;i--){Control c=controls.get(i);if(!c.key.startsWith("customer:")&&new RectF(c.x,c.y,c.x+c.w,c.y+c.h).contains(x,y))return c.key;}
        return null;
    }
    private void drawCustomer(Canvas c,Customer customer){Node image=customerImage(customer);Bitmap frame=customerFrame(customer,image);
        if(customer.spriteVisible())c.drawBitmap(frame,null,customerSpriteBounds(customer,image,frame),paint);
        else if(customer.effectActive()){
            // 004163a0 captures the last body center; 0040d370 draws a five-row
            // puff at its intrinsic size and alpha 200, including after line movement.
            RectF body=customerSpriteBounds(customer,image,frame,customer.departureSlot);Bitmap puff=assets.frame(customer.state==CustomerState.LEAVING?"IMAGE_CUST_PUFF_ANGRY":"IMAGE_CUST_PUFF_HAPPY",1,5,customer.departureFrame);
            paint.setAlpha(200);c.drawBitmap(puff,(int)(body.centerX()-puff.getWidth()/2f),(int)(body.centerY()-puff.getHeight()/2f),paint);paint.setAlpha(255);
        }
    }
    private void drawOrder(Canvas c,Customer customer){GameEngine g=activity.game;Node p=g.customerPoints.get(customer.slot);float x=p.f("x_money",230),y=p.f("y_money",500);
        if(customer.state==CustomerState.CASH){if(!customer.cashCollected)assets.draw(c,(int)(g.elapsed/.35f)%2==0?"IMAGE_MONEY":"IMAGE_MONEY_FL",(int)(x-4),(int)(y-25),40,40);return;}
        if(customer.state==CustomerState.LEAVING||customer.state==CustomerState.HAPPY)return;
        // 0040d9d0 computes queue depth by integer division; 0040d370 and
        // 0040b790 place intrinsic, overlapping hearts on the customer's left.
        int depthStep=(g.customerPoints.get(0).i("x_money",230)-g.customerPoints.get(g.customerPoints.size()-1).i("x_money",230))/g.customerPoints.size();
        for(int i=0;i<customer.hearts;i++)c.drawBitmap(assets.image("IMAGE_HEART"),(int)((customer.hearts-i+1)*20*(double)(1f/3f)+30-depthStep*customer.slot),(int)(y-30),paint);
        if(customer.state==CustomerState.ORDER){panel(c,x-23,y-66,94,65,0xebffffef);cake(c,customer.order,x+24,y-13,.43f);}
    }
    private float jillPhase;
    private float jillFrameClock;
    private int jillFrameAnimation=-1;
    private boolean jillWasMoving;
    private void drawJill(Canvas c){
        GameEngine g=activity.game;int direction=g.moving()?SpriteRules.direction(g.dx,g.dy):8;boolean carrying=g.hand!=null;int id=SpriteRules.animationId(direction,carrying);
        Node avatar=g.level.avatar.first("Avatar"),anim=null;for(Node n:avatar.children)if(n.tag.equals("Animation")&&n.i("id",-1)==id)anim=n;if(anim==null)throw new IllegalStateException("Missing Jill animation "+id);
        int count=Math.max(1,anim.i("count",1));float now=clock;
        // MainActivity keeps advancing the view clock while the pause overlay is
        // visible.  Preserve the native pause invariant by consuming that clock
        // edge without advancing Jill's authored frame phase.
        float dt=g.paused?0f:Math.max(0f,now-jillFrameClock);jillFrameClock=now;int frame;
        if(g.moving()){
            if(jillFrameAnimation!=id||!jillWasMoving)jillPhase=count-1;
            jillPhase=SpriteRules.reversePhase(jillPhase,dt,count,anim.f("speed",.15f));frame=SpriteRules.frameIndex(jillPhase,count);
        }else{
            if(jillFrameAnimation!=id||jillWasMoving||g.idleTime()<2f)jillPhase=count-1;
            else jillPhase=SpriteRules.reversePhase(jillPhase,dt,count,anim.f("speed",.15f));
            frame=g.idleTime()<2f?count-1:SpriteRules.frameIndex(jillPhase,count);
        }
        jillFrameAnimation=id;jillWasMoving=g.moving();
        Bitmap bodyFrame=assets.frame(anim.s("image"),1,count,frame);Bitmap bodySheet=assets.image(anim.s("image"));float projection=SpriteRules.gameplayProjection(g.y)*anim.f("scale",1);float frameW=bodySheet.getWidth(),frameH=bodySheet.getHeight()/Math.max(1,count);
        float baseX=SpriteRules.baseX(g.x,frameW,projection,anim.f("x_dec",0)),baseY=SpriteRules.baseY(g.y,frameH,projection,anim.f("y_dec",0));
        float bodyW=SpriteRules.projectedSize(frameW,projection),bodyH=SpriteRules.projectedSize(frameH,projection);
        RectF bodyRect=new RectF(baseX,baseY,baseX+bodyW,baseY+bodyH);
        float cakeX=baseX+projection*anim.f("x_cake",30),cakeY=baseY+projection*anim.f("y_cake",70);
        // Native render=1 places the carried cake behind Jill; render=0 places
        // it in front. The authored flag is per animation (NW and W are 1).
        float carryScale=SpriteRules.carryCakeProjection(cakeY);
        if(carrying&&anim.i("render",0)!=0)cake(c,g.hand,cakeX,cakeY,carryScale);
        c.drawBitmap(bodyFrame,null,bodyRect,paint);
        if(carrying&&anim.i("render",0)==0)cake(c,g.hand,cakeX,cakeY,carryScale);
        Node upgrade=null;for(Node n:avatar.children)if(n.tag.equals("Upgrade")&&n.i("id",-1)==id&&n.i("idupg",0)==g.shoeStep){upgrade=n;break;}
        if(upgrade!=null&&!upgrade.s("image").isEmpty()){
            int upgradeCount=Math.max(1,upgrade.i("count",count));Bitmap shoe=assets.frame(upgrade.s("image"),1,upgradeCount,frame);
            Bitmap shoeSheet=assets.image(upgrade.s("image"));float shoeScale=SpriteRules.overlayScale(projection,upgrade.f("scale",1));float shoeX=SpriteRules.overlayX(baseX,projection,upgrade.f("x_dec",0)),shoeY=SpriteRules.overlayY(baseY,projection,upgrade.f("y_dec",0));
            float shoeW=SpriteRules.projectedSize(shoeSheet.getWidth(),shoeScale),shoeH=SpriteRules.projectedSize(shoeSheet.getHeight()/Math.max(1,upgradeCount),shoeScale);
            c.drawBitmap(shoe,null,new RectF(shoeX,shoeY,shoeX+shoeW,shoeY+shoeH),paint);
        }
    }
    private void cake(Canvas c,Cake cake,float center,float bottom,float scale){float y=bottom;for(Layer layer:cake.layers){Node definition=activity.data.cakes.get(layer.shape);if(definition==null)throw new IllegalStateException("Unknown cake shape");if(layer.shape==8){assets.draw(c,"IMAGE_COOKIE",center-20,bottom-20,40,30);return;}Node base=definition.first("CakeBase");Bitmap b=assets.image(base.s("image"));c.drawBitmap(b,null,new RectF(center-b.getWidth()*scale/2,y-b.getHeight()*scale,center+b.getWidth()*scale/2,y),paint);y-=base.f("height",22)*scale;
            if(layer.frost>=0){for(Node n:definition.children)if(n.tag.equals("CakeFrost")&&n.i("id",-1)==layer.frost){Bitmap f=assets.image(n.s("image"));float fy=y+n.f("height_d",12)*scale;c.drawBitmap(f,null,new RectF(center-f.getWidth()*scale/2,fy-f.getHeight()*scale,center+f.getWidth()*scale/2,fy),paint);y-=n.f("height",15)*scale;}}
            if(layer.decor>=0){for(Node n:definition.children)if(n.tag.equals("CakeDecoration")&&n.i("id",-1)==layer.decor){Bitmap d=assets.image(n.s("image"));float dy=y+n.f("height_d",30)*scale;c.drawBitmap(d,null,new RectF(center-d.getWidth()*scale/2,dy-d.getHeight()*scale,center+d.getWidth()*scale/2,dy),paint);}}
        }}
}
