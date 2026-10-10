package local.dinerdash.prototype;

import android.app.Instrumentation;
import android.content.*;
import android.media.MediaPlayer;
import android.os.Bundle;
import java.lang.reflect.Field;
import java.util.*;

/** Installed playback callbacks and Activity transitions; original saves are restored. */
public final class AndroidAudioTest extends Instrumentation {
    private int checks;
    private MainActivity activity;
    private GameAudio audio;
    private MenuView menu;
    private void check(boolean ok,String why){checks++;if(!ok)throw new AssertionError(why);}
    private Object field(Object target,String name)throws Exception{Field f=target.getClass().getDeclaredField(name);f.setAccessible(true);return f.get(target);}
    private MediaPlayer player()throws Exception{return (MediaPlayer)field(audio,"music");}
    private MediaPlayer queued()throws Exception{return (MediaPlayer)field(audio,"queuedMusic");}
    private void handoff(String why)throws Exception{MediaPlayer before=player(),next=queued();
        check(next!=null&&!next.isPlaying(),why+": the successor must be prepared in advance");
        check(next.getAudioSessionId()==before.getAudioSessionId(),why+": both clips must share the native audio session");
        runOnMainSync(()->{before.seekTo(before.getDuration()-180);android.os.SystemClock.sleep(900);
            check(next.isPlaying()&&next.getCurrentPosition()>100,why+": the successor must start even while the UI completion callback is blocked");});
        waitForIdleSync();check(player()==next,why+": bookkeeping must adopt the already playing successor");advancing(next,why);}
    private void advancing(MediaPlayer p,String why)throws Exception{check(p!=null&&p.isPlaying(),why+": a player must be running");int before=p.getCurrentPosition();Thread.sleep(250);check(p.getCurrentPosition()>before,why+": Android must decode and advance the music clock");}
    private void restore(SharedPreferences p,Map<String,?> data){SharedPreferences.Editor e=p.edit().clear();for(Map.Entry<String,?> v:data.entrySet()){Object x=v.getValue();if(x instanceof Integer)e.putInt(v.getKey(),(Integer)x);else if(x instanceof Boolean)e.putBoolean(v.getKey(),(Boolean)x);else if(x instanceof String)e.putString(v.getKey(),(String)x);else throw new IllegalStateException("Unexpected save type "+x);}e.commit();}
    @Override public void onCreate(Bundle args){super.onCreate(args);start();}
    @Override public void onStart(){Bundle result=new Bundle();List<SharedPreferences> stores=new ArrayList<>();List<Map<String,?>> backups=new ArrayList<>();try{
        Context c=getTargetContext();stores.add(c.getSharedPreferences("career",0));for(int i=0;i<10;i++)stores.add(c.getSharedPreferences("career_profile_"+i,0));for(SharedPreferences p:stores)backups.add(new HashMap<>(p.getAll()));
        SharedPreferences settings=stores.get(0);settings.edit().putBoolean("music",true).commit();
        activity=(MainActivity)startActivitySync(new Intent(c,MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));audio=(GameAudio)field(activity,"audio");menu=(MenuView)field(activity,"menus");
        check(menu.screen.equals("title_screen"),"A normal launch must reach the main menu");advancing(player(),"The main menu must play its recovered intro playlist");
        check(player().getDuration()>5640&&player().getDuration()<5655,"Menu playback must use the recovered 90352/90353 samples rather than the padded MP3 length");
        String menuClip=(String)field(audio,"musicName");check(menuClip.equals(field(audio,"queuedName")),"random 2 must queue the same menu clip for its second play");
        handoff("The menu repeat");check((Integer)field(audio,"menuPlays")==1&&menuClip.equals(field(audio,"musicName")),"The first completion must retain the selected clip for its second play");
        handoff("The next random menu clip");check((Integer)field(audio,"menuPlays")==2,"After two plays the menu must begin a new two-play selection");
        MediaPlayer paused=player();runOnMainSync(()->callActivityOnPause(activity));int position=paused.getCurrentPosition();Thread.sleep(250);check(!paused.isPlaying()&&Math.abs(paused.getCurrentPosition()-position)<60,"Backgrounding must pause menu music without losing its place");runOnMainSync(()->callActivityOnResume(activity));advancing(paused,"Returning to the app must resume menu music");
        runOnMainSync(()->{activity.menuAction("options_button");activity.menuAction("music_off");});check(player()==null&&queued()==null&&!audio.musicEnabled&&!settings.getBoolean("music",true),"Music OFF must release both current and queued players and persist the setting");
        runOnMainSync(()->activity.menuAction("music_on"));check(settings.getBoolean("music",false),"Music ON must persist across launches");advancing(player(),"Music ON must restart the original menu playlist");
        MediaPlayer musicWithSfxOff=player();runOnMainSync(()->activity.menuAction("sfx_off"));check(!audio.enabled&&player()==musicWithSfxOff&&player().isPlaying(),"SFX OFF must not mute or replace menu BGM");
        runOnMainSync(()->{activity.menuAction("okbutton");menu.show("career_setup");menu.selected=1;activity.menuAction("play_button");});check(menu.screen.equals("startlevel")&&player()!=musicWithSfxOff,"Starting a shift must replace menu music with gameplay music");advancing(player(),"Starting a shift must still play gameplay BGM");
        check(player().getDuration()==6000&&field(audio,"queuedName").equals("music_c2"),"Gameplay must queue c2 using the original 96000-sample c1 length");handoff("The gameplay transition");
        for(int stage:new int[]{1,2,3,4,5}){final int s=stage;runOnMainSync(()->audio.startMusic(s));check(player().getDuration()==6000&&queued().getDuration()==6000,"Every restaurant must prepare its gameplay clips using their original six-second boundaries");handoff("Restaurant "+stage+" music");}
        runOnMainSync(()->audio.startMusic(1));for(int segment=2;segment<=8;segment++){MediaPlayer before=player();runOnMainSync(()->before.seekTo(before.getDuration()-180));long limit=System.currentTimeMillis()+2500;while(player()==before&&System.currentTimeMillis()<limit)Thread.sleep(30);waitForIdleSync();check(field(audio,"musicName").equals("music_c"+segment),"Gameplay must preserve its sequence through c"+segment);}
        check(player().getDuration()==3000&&field(audio,"queuedName").equals("music_c1"),"The short c8 ending must use 48000 samples and prepare the c1 wrap");handoff("The gameplay playlist wrap");check(field(audio,"musicName").equals("music_c1"),"After c8 the gameplay playlist must wrap to c1");
        runOnMainSync(()->{activity.menuAction("okbutton");activity.pauseGame();});check(!player().isPlaying(),"Pausing gameplay must pause its BGM");runOnMainSync(()->activity.menuAction("yesbutton"));check(menu.screen.equals("title_screen"),"Quit shift must return to the main menu");advancing(player(),"Returning from gameplay must restore menu BGM");
        runOnMainSync(()->{activity.menuAction("options_button");activity.menuAction("music_off");activity.finish();});waitForIdleSync();activity=(MainActivity)startActivitySync(new Intent(c,MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));audio=(GameAudio)field(activity,"audio");menu=(MenuView)field(activity,"menus");check(!menu.music&&player()==null,"A saved Music OFF preference must survive a cold launch");
        runOnMainSync(()->{activity.menuAction("options_button");activity.menuAction("music_on");});advancing(player(),"Enabling music after a muted launch must restore BGM");
        result.putString("summary","PASS: "+checks+" installed audio checks; prepared native handoffs tested while UI callbacks blocked; original saves restored");
    }catch(Throwable error){result.putString("failure",error.toString());}finally{if(activity!=null)runOnMainSync(()->activity.finish());waitForIdleSync();for(int i=0;i<backups.size();i++)restore(stores.get(i),backups.get(i));}finish(result.containsKey("failure")?0:-1,result);}
}
