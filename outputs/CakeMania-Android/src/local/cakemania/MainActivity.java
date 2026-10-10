package local.cakemania;

import android.app.*;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.*;
import android.view.*;
import android.widget.*;
import java.io.*;
import java.util.*;
import org.json.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

public final class MainActivity extends Activity {
    public GameData data;
    public GameEngine game;
    public GameAudio audio;
    public SharedPreferences saved;
    public String screen="menu";
    public int bank,unlocked=1,careerBakery,storyPage,helpPage;
    public String shopSelection="";
    public int lives=4,points;
    public boolean gameOver;
    public String activeProfileId="player1";
    public String endlessDifficulty="normal";
    public int endlessBakery;
    public final List<String> storyImages=new ArrayList<>();
    public final List<String> profileIds=new ArrayList<>();
    public CareerState career;
    public TutorialController tutorial;
    private GameView view;
    private FrameLayout root,buttons;
    private final Handler handler=new Handler(Looper.getMainLooper());
    private long previous,qaLast;
    private String controlsSignature="";
    private boolean active,qa;
    private float gameTimeRemainder;
    private String pressedGameControl;
    private boolean resultHandled;
    private int tutorialSavedStep=-1;
    private int tutorialSequenceId=-1;
    private final Runnable frame=new Runnable(){public void run(){if(!active)return;long now=System.nanoTime();float dt=previous==0?0:Math.min(.2f,(now-previous)/1000000000f);previous=now;view.clock+=dt;
        if(screen.equals("game")&&game!=null){gameTimeRemainder+=dt;while(gameTimeRemainder>=.01f){gameTimeRemainder-=.01f;game.tick(.01f);if(tutorial!=null){tutorial.tick(.01f);if(tutorial.eventIndex()!=tutorialSavedStep&&!tutorial.complete())tutorialSavedStep=tutorial.eventIndex();boolean needsCompletion=(tutorialSequenceId==0&&!career.tutorialComplete)||(tutorialSequenceId==10&&!career.complexTutorialComplete);if(tutorial.complete()&&needsCompletion&&game.queue.isEmpty())completeTutorialPractice();}}for(String sound:game.sounds)audio.play(sound);game.sounds.clear();if(game.finished)finished();}
        syncControls();view.invalidate();if(qa&&System.currentTimeMillis()-qaLast>250){writeQa();qaLast=System.currentTimeMillis();}handler.postDelayed(this,16);}};
    @Override public void onCreate(Bundle bundle){super.onCreate(bundle);getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);migrateLegacyCareer();loadProfile(activeProfileId);
        try{data=new GameData(path->getAssets().open(path));AssetStore assets=new AssetStore(this);audio=new GameAudio(this,assets);SharedPreferences settings=settings();audio.enabled=settings.getBoolean("sound",true);audio.musicEnabled=settings.getBoolean("music",true);audio.setVolumes(settings.getFloat("musicVolume",1f),settings.getFloat("soundVolume",.8f));
            root=new FrameLayout(this);root.setBackgroundColor(Color.BLACK);buttons=new FrameLayout(this);view=new GameView(this,this,assets);root.addView(view,new FrameLayout.LayoutParams(-1,-1));root.addView(buttons,new FrameLayout.LayoutParams(-1,-1));
            root.setOnApplyWindowInsetsListener((v,insets)->{if(Build.VERSION.SDK_INT>=28&&insets.getDisplayCutout()!=null){android.view.DisplayCutout cut=insets.getDisplayCutout();v.setPadding(cut.getSafeInsetLeft(),cut.getSafeInsetTop(),cut.getSafeInsetRight(),cut.getSafeInsetBottom());}return insets;});setContentView(root);immersive();audio.music("music/mainmenu.ogg");
            qa=getIntent().hasExtra("qa_level");if(qa){start(Math.max(1,Math.min(48,getIntent().getIntExtra("qa_level",1))));show("game");}
        }catch(Exception error){android.util.Log.e("CakeMania","Startup failed",error);new AlertDialog.Builder(this).setTitle("Cake Mania could not start").setMessage(error.toString()).setPositiveButton("Close",(d,w)->finish()).show();}
    }
    private SharedPreferences settings(){return getSharedPreferences("career",MODE_PRIVATE);}
    private SharedPreferences profilePrefs(String id){return getSharedPreferences("career_profile_"+id,MODE_PRIVATE);}
    private void migrateLegacyCareer(){
        SharedPreferences global=settings();String ids=global.getString("profile_ids","");
        if(ids.trim().isEmpty()){
            SharedPreferences legacy=global,profile=profilePrefs("player1");SharedPreferences.Editor e=profile.edit();
            for(Map.Entry<String,?> entry:legacy.getAll().entrySet()){String key=entry.getKey();Object value=entry.getValue();if(key.equals("sound")||key.equals("music")||key.equals("musicVolume")||key.equals("soundVolume"))continue;if(value instanceof Boolean)e.putBoolean(key,(Boolean)value);else if(value instanceof Integer)e.putInt(key,(Integer)value);else if(value instanceof Long)e.putLong(key,(Long)value);else if(value instanceof Float)e.putFloat(key,(Float)value);else if(value instanceof String)e.putString(key,(String)value);}
            if(!profile.contains("profile_name"))e.putString("profile_name","Player 1");e.apply();
            global.edit().putString("profile_ids","player1").putString("active_profile","player1").apply();ids="player1";
        }
        activeProfileId=global.getString("active_profile",ids.split(",")[0]);refreshProfiles();
    }
    private void refreshProfiles(){profileIds.clear();String ids=settings().getString("profile_ids","player1");for(String id:ids.split(",")){String clean=id.trim();if(!clean.isEmpty()&&!profileIds.contains(clean))profileIds.add(clean);}if(profileIds.isEmpty())profileIds.add("player1");if(!profileIds.contains(activeProfileId))activeProfileId=profileIds.get(0);}
    private void loadProfile(String id){activeProfileId=id;refreshProfiles();saved=profilePrefs(activeProfileId);career=CareerState.load(activeProfileId,activeProfileId.equals("player1")?"Player 1":("Player "+(profileIds.indexOf(activeProfileId)+1)),saved);bank=career.bank;unlocked=career.unlocked;lives=career.lives;points=career.points;gameOver=lives<=0;}
    private void saveCareer(){if(career==null)return;career.bank=bank;career.unlocked=unlocked;career.current=game==null?career.current:Math.max(1,Math.min(48,game.level.number));career.lives=lives;career.points=points;career.save(saved);}
    private void saveSettings(){settings().edit().putBoolean("sound",audio.enabled).putBoolean("music",audio.musicEnabled).putFloat("musicVolume",audio.musicVolume).putFloat("soundVolume",audio.soundVolume).apply();}
    public String profileName(String id){return profilePrefs(id).getString("profile_name",id);}
    public List<String> profileNames(){List<String> names=new ArrayList<>();for(String id:profileIds)names.add(profileName(id));return names;}
    public void selectProfile(String id){if(!profileIds.contains(id))return;if(game!=null&&!game.finished&&!screen.equals("profiles")&&!screen.equals("menu"))return;settings().edit().putString("active_profile",id).apply();loadProfile(id);screen="menu";game=null;tutorial=null;controlsSignature="";if(audio!=null)audio.music("music/mainmenu.ogg");if(view!=null){syncControls();view.invalidate();}}
    public void createProfile(String name){if(profileIds.size()>=6){Toast.makeText(this,"You can save up to six players.",Toast.LENGTH_SHORT).show();return;}String clean=name==null?"":name.trim();if(clean.isEmpty())clean="Player "+(profileIds.size()+1);String id="profile"+System.nanoTime();getSharedPreferences("career_profile_"+id,MODE_PRIVATE).edit().putString("profile_name",clean).putInt("lives",4).putInt("current",1).putInt("unlocked",1).apply();profileIds.add(id);settings().edit().putString("profile_ids",join(profileIds)).apply();selectProfile(id);}
    public void createProfileDialog(){final EditText input=new EditText(this);input.setSingleLine(true);input.setHint("Player name");new AlertDialog.Builder(this).setTitle("New player").setView(input).setPositiveButton("Create",(d,w)->createProfile(input.getText().toString())).setNegativeButton("Back",null).show();}
    public void showProfiles(){refreshProfiles();show("profiles");}
    private static String join(List<String> ids){StringBuilder b=new StringBuilder();for(String id:ids){if(b.length()>0)b.append(',');b.append(id);}return b.toString();}
    private void immersive(){getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_FULLSCREEN|View.SYSTEM_UI_FLAG_HIDE_NAVIGATION|View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY|View.SYSTEM_UI_FLAG_LAYOUT_STABLE|View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN|View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION);}
    @Override public void onWindowFocusChanged(boolean focused){super.onWindowFocusChanged(focused);if(focused)immersive();}
    private Map<String,Integer> upgrades(int bakery){Map<String,Integer> result=new LinkedHashMap<>();String prefix="upgrade"+bakery+":";for(Map.Entry<String,?> e:saved.getAll().entrySet())if(e.getKey().startsWith(prefix)&&e.getValue() instanceof Integer)result.put(e.getKey().substring(prefix.length()),(Integer)e.getValue());return result;}
    private void show(String next){gameTimeRemainder=0;screen=next;if(game!=null)game.paused=!next.equals("game");controlsSignature="";syncControls();view.invalidate();}
    private void menu(){show("menu");audio.music("music/mainmenu.ogg");}
    private void start(int number){
        if(lives<=0){gameOver=true;show("gameover");return;}
        if(number==1&&!career.tutorialComplete){startTutorialPractice(0);return;}
        // tutorialscreen level id 10 is authored immediately before the
        // zero-based November month (career level 11).
        if(number==11&&career.tutorialComplete&&!career.complexTutorialComplete){startTutorialPractice(10);return;}
        startNormalMonth(number,true);
    }
    private void startNormalMonth(int number,boolean showIntro){
        career.current=Math.max(1,Math.min(48,number));career.save(saved);
        game=new GameEngine(data,data.level(number),upgrades((number-1)/12+1),System.nanoTime());resultHandled=false;gameOver=false;tutorial=null;tutorialSavedStep=-1;tutorialSequenceId=-1;
        audio.music(game.level.music);show(showIntro?"intro":"game");
    }
    private void startTutorialPractice(int sequenceId){
        try{
            game=new GameEngine(data,data.tutorialLevel(),Collections.emptyMap(),System.nanoTime());
            resultHandled=false;gameOver=false;tutorialSavedStep=0;tutorialSequenceId=sequenceId;career.tutorialStep=0;
            GameData.Node sequence=data.tutorialSequence(sequenceId);if(sequence==null)throw new IOException("Missing tutorial sequence "+sequenceId);
            tutorial=new TutorialController();tutorial.start(sequence,tutorialHost(),0);
            game.suppressArrivals=true;audio.music("music/c.ogg");show("game");
        }catch(Exception error){throw new IllegalStateException("Authored tutorial room unavailable",error);}
    }
    private void completeTutorialPractice(){
        if(tutorial==null||!tutorial.complete())return;
        if(tutorialSequenceId==0)career.tutorialComplete=true;
        else if(tutorialSequenceId==10)career.complexTutorialComplete=true;
        else throw new IllegalStateException("Unsupported tutorial completion id "+tutorialSequenceId);
        career.tutorialStep=0;career.save(saved);tutorial=null;
        // Practice is outside the career ledger.  Begin January at elapsed zero
        // without awarding tutorial money, points, lives or a result.
        // 0041f740 -> 0041f290 -> 0041ba80 opens January's real StartScreen
        // after practice, using the career narrative and goal.
        startNormalMonth(tutorialSequenceId==10?11:1,tutorialSequenceId==0);
    }
    private TutorialController.Host tutorialHost(){return (id,orderText)->{
        if(id!=5)throw new IllegalArgumentException("Unsupported tutorial customer id "+id);
        if(game==null)return;Node arrival=new Node("Customer");arrival.attrs.put("guid","tutor");arrival.attrs.put("time","0");String[] values=orderText==null?new String[0]:orderText.split(",");GameEngine.Customer customer=game.addCustomer(arrival);for(int i=0;i+1<values.length;i+=2)try{int shape=tutorialFormId("CakeOven",Integer.parseInt(values[i]));int frost=tutorialFormId("Froster",Integer.parseInt(values[i+1]));GameEngine.Layer layer=new GameEngine.Layer(shape,15);layer.frost=frost;customer.order.layers.add(layer);}catch(NumberFormatException error){throw new IllegalArgumentException("Malformed tutorial order: "+orderText,error);}
    };}
    /**
     * Tutorial AddCustomer values are selection indices in each machine's
     * active Form vector, not the XML Form id.  This is inferred from the
     * authored click rectangles (sequence0 0,3 clicks Triangle/Red) and the
     * tutorial environment's Form order.  Keeping the translation here also
     * makes an unavailable authored selection fail loudly instead of creating
     * an order Jill cannot produce.
     */
    private int tutorialFormId(String kind,int selection){
        List<Integer> ids=new ArrayList<>();
        if(game!=null)for(Station station:game.stations)if(station.enabled()&&station.kind.equals(kind))for(Node form:station.def.children)if(form.tag.equals("Form")){int id=form.i("id",-1);if(id>=0&&!ids.contains(id))ids.add(id);}
        if(selection<0||selection>=ids.size())throw new IllegalArgumentException("Tutorial "+kind+" selection "+selection+" is unavailable");
        return ids.get(selection);
    }
    private void clearProfileProgress(){for(String key:new ArrayList<>(saved.getAll().keySet()))if(key.startsWith("upgrade")||key.startsWith("best"))saved.edit().remove(key).apply();}
    private void newCareer(){clearProfileProgress();career.reset();career.save(saved);bank=0;unlocked=1;lives=4;points=0;gameOver=false;start(1);storyImages.clear();storyImages.add("IMAGE_COMICS_TUTORIAL_1");storyImages.add("IMAGE_COMICS_TUTORIAL_2");storyImages.add("IMAGE_COMICS_TUTORIAL_3");storyPage=0;audio.music("music/mapscreen.ogg");show("story");}
    private void finished(){
        if(resultHandled)return;resultHandled=true;
        if(game.won){bank+=game.money;points+=game.money;unlocked=Math.max(unlocked,Math.min(48,game.level.number+1));career.current=Math.min(48,game.level.number+1);saved.edit().putInt("best"+game.level.number,Math.max(game.money,saved.getInt("best"+game.level.number,0))).apply();}
        else {lives=Math.max(0,lives-1);gameOver=lives==0;}
        saveCareer();
        if(game.won){career.current=Math.min(48,game.level.number+1);career.save(saved);}
        show(gameOver?"gameover":"result");
    }
    public List<Node> shopChoices(){List<Node> result=new ArrayList<>();if(game==null)return result;Map<String,Integer> base=new HashMap<>();for(Station s:game.stations)base.put(s.guid,s.def.i("upgr_step",0));base.put("jill",game.shoeStep);
        for(String guid:base.keySet()){int min=Integer.MAX_VALUE;Node choice=null;for(Node n:game.level.shop.children)if(n.s("guid").equals(guid)&&n.i("upgr_step",0)>base.get(guid)&&n.i("upgr_step",0)<min){min=n.i("upgr_step",0);choice=n;}if(choice!=null)result.add(choice);}
        Collections.sort(result,(a,b)->{int d=Integer.compare(a.i("purchase_points",0),b.i("purchase_points",0));return d!=0?d:a.s("guid").compareTo(b.s("guid"));});return result;
    }
    public Node selectedShopChoice(){for(Node choice:shopChoices())if(choice.s("guid").equals(shopSelection))return choice;return null;}
    public void syncControls(){if(view==null||buttons==null||view.getWidth()==0)return;view.rebuildControls();StringBuilder signature=new StringBuilder(screen+":"+view.getWidth()+":"+view.getHeight());for(GameView.Control c:view.controls)signature.append('|').append(c.key).append(':').append(c.label).append(':').append(c.x).append(':').append(c.y).append(':').append(c.w).append(':').append(c.h);if(signature.toString().equals(controlsSignature))return;controlsSignature=signature.toString();buttons.removeAllViews();
        for(GameView.Control c:view.controls){
            FrameLayout.LayoutParams p=new FrameLayout.LayoutParams(Math.round(c.w*view.scale),Math.round(c.h*view.scale));p.leftMargin=Math.round(view.ox+c.x*view.scale);p.topMargin=Math.round(view.oy+c.y*view.scale);
            if(c.key.equals("musicSlider")||c.key.equals("soundSlider")){
                SeekBar slider=new SeekBar(this);slider.setMax(100);slider.setProgress(Math.round((c.key.equals("musicSlider")?audio.musicVolume:audio.soundVolume)*100f));slider.setContentDescription(c.label);
                slider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener(){public void onProgressChanged(SeekBar bar,int progress,boolean fromUser){if(!fromUser)return;if(c.key.equals("musicSlider"))audio.setVolumes(progress/100f,audio.soundVolume);else audio.setVolumes(audio.musicVolume,progress/100f);saveSettings();}public void onStartTrackingTouch(SeekBar bar){}public void onStopTrackingTouch(SeekBar bar){}});
                buttons.addView(slider,p);continue;
            }
            Button b=new Button(this);b.setText(c.label);b.setTextColor(Color.TRANSPARENT);b.setBackgroundColor(Color.TRANSPARENT);b.setStateListAnimator(null);b.setPadding(0,0,0,0);b.setMinWidth(0);b.setMinHeight(0);b.setMinimumWidth(0);b.setMinimumHeight(0);b.setContentDescription(c.label);b.setOnClickListener(v->action(c.key));buttons.addView(b,p);
        }
    }
    private void action(String key){audio.play("SOUND_SELECT");if(key.equals("menu")){menu();return;}
        if(screen.equals("menu")){switch(key){case "menu0":show("playmenu");break;case "menu1":show("scores");break;case "menu2":show("options");break;case "menu3":helpPage=0;show("help");break;case "menu4":finish();break;case "menu5":showProfiles();break;}return;}
        if(screen.equals("profiles")){if(key.equals("profile:new")){createProfileDialog();return;}if(key.equals("profile:back")){menu();return;}if(key.startsWith("profile:")){selectProfile(key.substring(8));return;}}
        if(screen.equals("map")){if(key.equals("map:back")){menu();return;}if(key.startsWith("map:level:")){int n=Integer.parseInt(key.substring(10));if(n<=unlocked)start(n);return;}}
        if(screen.equals("endless")){if(key.equals("endless:back")){menu();return;}if(key.startsWith("endless:bakery:")){chooseEndlessBakery(Integer.parseInt(key.substring(15)));return;}if(key.startsWith("endless:difficulty:")){chooseEndlessDifficulty(key.substring(19));return;}if(key.equals("endless:start")){startEndless();return;}}
        if(screen.equals("playmenu")){switch(key){case "play0":if(unlocked>1)new AlertDialog.Builder(this).setTitle("Start a new career?").setMessage("This resets the saved career and upgrades on this device.").setPositiveButton("Start",(d,w)->newCareer()).setNegativeButton("Cancel",null).show();else newCareer();break;case "play1":start(Math.max(1,Math.min(48,saved.getInt("current",1))));break;case "play2":openMap();break;case "play3":menu();break;}return;}
        if(screen.equals("story")&&key.equals("next")){storyPage++;if(storyPage>=storyImages.size()){
            if(tutorialSequenceId==0&&tutorial!=null){audio.music("music/c.ogg");show("game");}
            else openMap();
        }else show("story");return;}
        if(screen.equals("intro")&&key.equals("start")){show("game");return;}
        if(screen.equals("game")){if(key.startsWith("tutorial:")){dispatchTutorialControl(key);return;}if(key.equals("pause")){show("pause");return;}if(key.equals("cancel")){game.clearQueue();return;}
            if(key.startsWith("form:")){String[] target=key.split(":");Station s=game.station(target[1]);if(s!=null&&s.form(Integer.parseInt(target[2]))!=null)game.enqueue(s,Integer.parseInt(target[2]));return;}
            if(key.startsWith("shelf:")){String[] target=key.split(":");if(target.length==3){Station s=game.station(target[1]);try{if(s!=null&&(s.kind.equals("CookieOven")||s.kind.equals("DisplayCase")))game.enqueue(s,-2-Integer.parseInt(target[2]));}catch(NumberFormatException ignored){}}return;}
            if(key.startsWith("station:")){Station s=game.station(key.substring(8));if(s!=null)game.enqueue(s,-1);return;}
            if(key.startsWith("customer:")){int serial=Integer.parseInt(key.substring(9));for(Customer c:game.customers)if(c.serial==serial){if(tutorial!=null&&tutorial.isWaitingForCustomer()&&"tutor".equals(c.profile.s("guid")))tutorial.customerClick(tutorial.waitingCustomerId());game.enqueue(c);break;}return;}}
        if(screen.equals("pause")){if(key.equals("resume"))show("game");else if(key.equals("restart"))start(game.level.number);return;}
        if(screen.equals("gameover")){if(key.equals("restart")){career.lives=4;lives=4;gameOver=false;career.save(saved);start(1);}else if(key.equals("menu"))menu();return;}
        if(screen.equals("result")&&key.equals("next")){if(!game.won)start(game.level.number);else if(game.level.number==48)show("complete");else{shopSelection="";audio.music("music/mapscreen.ogg");show("shop");}return;}
        if(screen.equals("shop")){if(key.equals("continue")){start(game.level.number+1);return;}
            if(key.startsWith("shop:select:")){shopSelection=key.substring(12);audio.play("SOUND_SELECT");}
            else if(key.equals("shop:buy")){Node u=selectedShopChoice();if(u!=null){int price=u.i("purchase_points",0);if(bank>=price){bank-=price;saved.edit().putInt("bank",bank).putInt("upgrade"+game.level.bakery+":"+u.s("guid"),u.i("upgr_step",0)).apply();game.upgrades.put(u.s("guid"),u.i("upgr_step",0));if(u.s("guid").equals("jill"))game.shoeStep=u.i("upgr_step",0);else{Station station=game.station(u.s("guid"));if(station!=null){station.def.merge(u);station.refreshGeometry();}}saveCareer();audio.play("SOUND_LEVEL_BUY");shopSelection="";}}}controlsSignature="";return;}
        if(screen.equals("career")){if(key.equals("bakeryprev"))careerBakery=Math.max(0,careerBakery-1);else if(key.equals("bakerynext"))careerBakery=Math.min(3,careerBakery+1);else if(key.startsWith("level:")){int n=Integer.parseInt(key.substring(6));if(n<=unlocked)start(n);else Toast.makeText(this,"Complete earlier months to unlock this one.",Toast.LENGTH_SHORT).show();}controlsSignature="";return;}
        if(screen.equals("options")){if(key.equals("music")){audio.musicEnabled=!audio.musicEnabled;audio.resume();}if(key.equals("sound")){audio.enabled=!audio.enabled;}if(key.equals("musicVolumeUp"))audio.setVolumes(audio.musicVolume+.1f,audio.soundVolume);if(key.equals("musicVolumeDown"))audio.setVolumes(audio.musicVolume-.1f,audio.soundVolume);if(key.equals("soundVolumeUp"))audio.setVolumes(audio.musicVolume,audio.soundVolume+.1f);if(key.equals("soundVolumeDown"))audio.setVolumes(audio.musicVolume,audio.soundVolume-.1f);saveSettings();controlsSignature="";return;}
        if(screen.equals("help")&&key.equals("helpnext")){helpPage=(helpPage+1)%4;view.invalidate();}
    }
    /** Dispatch a renderer tutorial target through the authored gate and then
     * the same station/customer hit that a normal game control would use. */
    private void dispatchTutorialControl(String key){
        String[] parts=key.split(":");if(parts.length!=3||tutorial==null)return;
        try{float x=Float.parseFloat(parts[1]),y=Float.parseFloat(parts[2]);
            if(tutorial.isWaitingForCustomer())dispatchTutorialCustomer(x,y);
            else if(tutorial.click(x,y))dispatchTutorialPoint(x,y);
        }catch(NumberFormatException error){throw new IllegalArgumentException("Malformed tutorial control "+key,error);}
    }
    private boolean dispatchTutorialCustomer(float x,float y){
        for(Customer customer:new ArrayList<>(game.customers)){if(view.hitsCustomer(customer,x,y)){if(!"tutor".equals(customer.profile.s("guid")))return false;tutorial.customerClick(tutorial.waitingCustomerId());game.enqueue(customer);return true;}}
        return false;
    }
    private boolean dispatchTutorialPoint(float x,float y){
        // The last authored WaitForClick is the tutor's cash pickup. Reuse the
        // normal customer hit rectangle so this click queues collection rather
        // than advancing the script without an underlying game action.
        for(Customer customer:new ArrayList<>(game.customers)){
            Node point=game.customerPoints.get(customer.slot);
            if(point!=null&&view.hitsCustomer(customer,x,y)){
                if(!"tutor".equals(customer.profile.s("guid")))return false;
                game.enqueue(customer);return true;
            }
        }
        for(Station station:game.stations)if(station.enabled()){
            for(Node form:station.def.children)if(form.tag.equals("Form")&&contains(x,y,station.x+form.f("x",0),station.y+form.f("y",0),form.f("width",0),form.f("height",0))){game.enqueue(station,form.i("id",0));return true;}
            for(Node shelf:station.def.children)if(shelf.tag.equals("FormShelf")&&contains(x,y,station.x+shelf.f("x",0),station.y+shelf.f("y",0),shelf.f("width",29),shelf.f("height",29))){game.enqueue(station,-2-shelf.i("id",0));return true;}
            if(contains(x,y,station.x,station.y,station.w,station.h)){game.enqueue(station,-1);return true;}
        }
        return false;
    }
    private static boolean contains(float x,float y,float left,float top,float width,float height){return width>0&&height>0&&x>=left&&x<=left+width&&y>=top&&y<=top+height;}
    /** Renderer hook for authored tutorial hit rectangles. */
    public boolean tutorialClick(float x,float y){return tutorial!=null&&tutorial.click(x,y);}
    public boolean tutorialCustomerClick(int serial){
        if(tutorial==null||!tutorial.isWaitingForCustomer())return false;
        for(Customer c:game==null?Collections.<Customer>emptyList():game.customers)if(c.serial==serial&&"tutor".equals(c.profile.s("guid")))return tutorial.customerClick(tutorial.waitingCustomerId());
        return false;
    }
    public List<TutorialController.Overlay> tutorialOverlays(){return tutorial==null?Collections.emptyList():tutorial.overlays();}
    public boolean tutorialWaiting(){return tutorial!=null&&tutorial.running();}
    public GameData.Node resultScreen(){if(game==null)return null;return game.won?game.level.successScreen:game.level.failureScreen;}
    public String resultText(String text){if(text==null)return "";if(game==null)return text;return text.replace("[%BAKER_GOAL]",""+game.level.goal).replace("[%CUSTOMERS_LOST_MONEY]",""+game.customerLostMoney).replace("[%CAKES_SERVED]",""+game.cakeRevenue).replace("[%CAKES_LOST]",""+game.cakeLostMoney).replace("[%CUSTOMER_TIP]",""+game.tips).replace("[%TOTAL_LEVEL_MONEY]",""+game.money).replace("[%TOTAL_MONEY]",""+bank);}
    public List<GameData.EndlessDefinition> endlessDefinitions(){return Collections.unmodifiableList(data.endless);}
    public boolean endlessDataAvailable(int bakery){return bakery>=0&&bakery<data.endless.size()&&data.endless.get(bakery).dataPresent;}
    public void chooseEndlessBakery(int bakery){if(bakery>=0&&bakery<data.endless.size())endlessBakery=bakery;}
    public void chooseEndlessDifficulty(String difficulty){if("easy".equals(difficulty)||"normal".equals(difficulty)||"hard".equals(difficulty))endlessDifficulty=difficulty;}
    public void startEndless(){if(!endlessDataAvailable(endlessBakery))Toast.makeText(this,"Endless mode data is missing from the supplied game files.",Toast.LENGTH_LONG).show();}
    public List<GameData.Node> mapLevels(){return data.mapLevels();}
    public List<String> availableComicImages(AssetStore assets,int bakery){List<String> result=new ArrayList<>();for(String id:data.comicImages(bakery))if(assets.paths.containsKey(id))result.add(id);return result;}
    public void openMap(){show("map");audio.music("music/mapscreen.ogg");}
    public void openTransitionComics(int bakery,AssetStore assets){storyImages.clear();storyImages.addAll(availableComicImages(assets,bakery));storyPage=0;if(storyImages.isEmpty()){openMap();return;}audio.music("music/mapscreen.ogg");show("story");}
    static int optionalInt(MainActivity activity,String key,int fallback){if(activity==null)return fallback;if(key.equals("lives"))return activity.lives;return fallback;}
    private void writeQa(){try{JSONObject o=new JSONObject();o.put("screen",screen);o.put("profileId",activeProfileId);o.put("profileName",career==null?"":career.name);o.put("profilePrefs","career_profile_"+activeProfileId);o.put("bank",bank);o.put("unlocked",unlocked);o.put("lives",lives);o.put("points",points);o.put("tutorialComplete",career!=null&&career.tutorialComplete);o.put("complexTutorialComplete",career!=null&&career.complexTutorialComplete);o.put("tutorialSequenceId",tutorialSequenceId);o.put("tutorialStep",tutorial==null?0:tutorial.eventIndex());o.put("tutorialEvent",tutorial==null||tutorial.currentEvent()==null?"":tutorial.currentEvent().s("type"));o.put("tutorialEventId",tutorial==null||tutorial.currentEvent()==null?-1:tutorial.currentEvent().i("id",-1));o.put("music",audio.musicEnabled);o.put("sound",audio.enabled);o.put("musicVolume",audio.musicVolume);o.put("soundVolume",audio.soundVolume);o.put("musicPlaying",audio.musicPlaying());o.put("musicTrack",audio.musicTrack());o.put("soundsLoaded",audio.soundsReady());if(game!=null){o.put("level",game.level.number);o.put("elapsed",game.elapsed);o.put("money",game.money);o.put("served",game.served);o.put("lost",game.lost);o.put("queue",game.queue.size());o.put("tvChannel",game.channel);o.put("tvNoise",game.tvNoise);o.put("moving",game.moving());o.put("jillX",game.x);o.put("jillY",game.y);o.put("jillSpeed",game.speed());o.put("message",game.message);o.put("hand",cakeJson(game.hand));JSONArray c=new JSONArray();for(Customer u:game.customers){JSONObject a=new JSONObject();a.put("serial",u.serial);a.put("slot",u.slot);a.put("state",u.state.toString());a.put("cashCollected",u.cashCollected);a.put("departureFrame",u.departureFrame);a.put("bodyVisible",u.spriteVisible());a.put("hearts",u.hearts);a.put("remainingPatience",u.remainingPatience);a.put("order",cakeJson(u.order));c.put(a);}o.put("customers",c);JSONArray stations=new JSONArray();for(Station s:game.stations){JSONObject a=new JSONObject();a.put("guid",s.guid);a.put("kind",s.kind);a.put("enabled",s.enabled());a.put("x",s.x);a.put("y",s.y);a.put("w",s.w);a.put("h",s.h);a.put("cake",cakeJson(s.cake));a.put("remaining",s.remaining);stations.put(a);}o.put("stations",stations);}try(FileOutputStream out=new FileOutputStream(new File(getFilesDir(),"qa-state.json"))){out.write(o.toString().getBytes("UTF-8"));}}catch(Exception e){throw new IllegalStateException("QA state failed",e);}}
    private JSONArray cakeJson(Cake cake)throws Exception{JSONArray a=new JSONArray();if(cake!=null)for(Layer l:cake.layers){JSONObject n=new JSONObject();n.put("shape",l.shape);n.put("frost",l.frost);n.put("decor",l.decor);n.put("price",l.price);a.put(n);}return a;}
    @Override public boolean dispatchTouchEvent(MotionEvent event){
        if(view!=null&&game!=null&&(screen.equals("game")||screen.equals("shop"))){
            int[] origin=new int[2];view.getLocationInWindow(origin);
            float x=(event.getX()-origin[0]-view.ox)/view.scale,y=(event.getY()-origin[1]-view.oy)/view.scale;
            // Resolve physical taps in the same coordinates used to draw the art.
            // Overlay accessibility buttons can be rebuilt while a finger is down.
            if(event.getActionMasked()==MotionEvent.ACTION_DOWN)pressedGameControl=view.gameControlAt(x,y);
            else if(event.getActionMasked()==MotionEvent.ACTION_UP){String key=view.gameControlAt(x,y);if(key!=null&&key.equals(pressedGameControl))action(key);pressedGameControl=null;}
            else if(event.getActionMasked()==MotionEvent.ACTION_CANCEL)pressedGameControl=null;
            return true;
        }
        return super.dispatchTouchEvent(event);
    }
    @Override public void onBackPressed(){if(screen.equals("game"))show("pause");else if(screen.equals("pause"))show("game");else if(screen.equals("menu"))finish();else menu();}
    @Override protected void onResume(){super.onResume();active=true;previous=0;gameTimeRemainder=0;if(audio!=null)audio.resume();if(view!=null)handler.post(frame);}
    @Override protected void onPause(){active=false;handler.removeCallbacks(frame);if(audio!=null)audio.pause();super.onPause();}
    @Override protected void onDestroy(){handler.removeCallbacks(frame);if(audio!=null)audio.close();super.onDestroy();}
}
