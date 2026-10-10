package local.dinerdash.prototype;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.media.*;
import java.util.*;

public final class GameAudio {
    private final Context context;
    private final AssetStore assets;
    private final SoundPool pool=new SoundPool.Builder().setMaxStreams(6).setAudioAttributes(new AudioAttributes.Builder().setUsage(AudioAttributes.USAGE_GAME).setContentType(AudioAttributes.CONTENT_TYPE_MUSIC).build()).build();
    private final Map<String,Integer> sounds=new HashMap<>();
    private MediaPlayer music,queuedMusic;
    private final Random random=new Random();
    private int menuPlays;
    private boolean menuMode,musicPaused;
    private String musicName,queuedName;
    public boolean enabled=true,musicEnabled=true;
    private String song="c";private int segment=1;
    public GameAudio(Context c,AssetStore a){context=c;assets=a;for(String name:new String[]{"sfx_party_arrive_1_snd","sfx_seat_people_snd","sfx_food_ready_1_snd","sfx_pickup_food_1_snd","sfx_clear_dishes_1_snd","sfx_dish_dropoff_1_snd","sfx_deliver_food_1_snd","sfx_deliver_food_2_snd","sfx_bring_check_1_snd","sfx_deliver_order_1_snd","sfx_pencil_write_2","sfx_get_drinks_2_snd","sfx_dropoff_drinks_1_snd","sfx_gain_heart_1","sfx_lose_heart_1","sfx_done_eating_1_snd"}){String path=a.sound(name);if(path!=null)try(AssetFileDescriptor fd=c.getAssets().openFd(path)){sounds.put(name,pool.load(fd,1));}catch(Exception e){android.util.Log.e("DinerAudio","Cannot load "+path,e);}}}
    public void play(String name){Integer id=sounds.get(name);if(enabled&&id!=null)pool.play(id,.7f,.7f,1,0,1);}
    public void startMusic(int stage){stop();menuMode=false;song=new String[]{"c","i","j","c","j"}[(stage-1)%5];segment=1;beginMusic("music_"+song+segment);}
    public void menuMusic(){stop();menuMode=true;menuPlays=2;beginMusic("music_h"+(1+random.nextInt(6)));}
    private void beginMusic(String name){if(!musicEnabled)return;musicName=name;musicPaused=false;
        try{music=prepareMusic(name,0);queueMusic();music.start();}
        catch(Exception e){android.util.Log.e("DinerAudio","Cannot start "+name,e);stop();}}
    private MediaPlayer prepareMusic(String name,int session)throws Exception{
        MediaPlayer p=new MediaPlayer();try(AssetFileDescriptor fd=context.getAssets().openFd("music/"+name+".wav")){
            p.setAudioAttributes(new AudioAttributes.Builder().setUsage(AudioAttributes.USAGE_GAME).setContentType(AudioAttributes.CONTENT_TYPE_MUSIC).build());
            if(session!=0)p.setAudioSessionId(session);
            p.setDataSource(fd.getFileDescriptor(),fd.getStartOffset(),fd.getLength());p.setVolume(.4f,.4f);p.setOnCompletionListener(this::musicCompleted);
            p.setOnErrorListener((failed,what,extra)->{if(failed==music||failed==queuedMusic){android.util.Log.e("DinerAudio","Music playback error "+what+":"+extra);stop();}return true;});
            p.prepare();return p;
        }catch(Exception e){p.release();throw e;}}
    private void queueMusic()throws Exception{
        // music_intro is random 2; gameplay keeps its existing sequence and wrap.
        if(menuMode)queuedName=menuPlays==2?musicName:"music_h"+(1+random.nextInt(6));
        else {int next=segment+1;if(assets.sound("music_"+song+next)==null)next=1;queuedName="music_"+song+next;}
        queuedMusic=prepareMusic(queuedName,music.getAudioSessionId());music.setNextMediaPlayer(queuedMusic);
    }
    private void musicCompleted(MediaPlayer previous){if(previous!=music)return;
        // Android has already started the prepared successor, independent of this callback.
        music=queuedMusic;queuedMusic=null;musicName=queuedName;previous.release();
        if(!musicEnabled||music==null){stop();return;}
        if(menuMode)menuPlays=3-menuPlays;else {segment++;if(assets.sound("music_"+song+segment)==null)segment=1;}
        if(musicPaused&&music.isPlaying())music.pause();
        try{queueMusic();}catch(Exception e){android.util.Log.e("DinerAudio","Cannot queue after "+musicName,e);stop();}}
    public void pause(){musicPaused=true;if(music!=null&&music.isPlaying())music.pause();if(queuedMusic!=null&&queuedMusic.isPlaying())queuedMusic.pause();pool.autoPause();}
    public void resume(){musicPaused=false;if(musicEnabled&&music!=null)music.start();pool.autoResume();}
    public void stop(){MediaPlayer current=music,next=queuedMusic;music=queuedMusic=null;
        if(current!=null){try{current.setNextMediaPlayer(null);}catch(IllegalStateException ignored){/* An errored player still needs release. */}current.release();}
        if(next!=null)next.release();}
    public void close(){stop();pool.release();}
}
