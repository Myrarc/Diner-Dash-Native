package local.cakemania;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.media.*;
import android.util.Log;
import java.util.*;

public final class GameAudio {
    private final Context context;
    private final SoundPool effects;
    private final Map<String,Integer> sounds=new HashMap<>();
    private final Set<Integer> loaded=new HashSet<>();
    private final ArrayDeque<Integer> streams=new ArrayDeque<>();
    private MediaPlayer music;
    private String track="";
    private boolean ready,active=true;
    public boolean enabled=true,musicEnabled=true;
    public float musicVolume=1,soundVolume=.8f;
    public GameAudio(Context c,AssetStore assets){context=c;effects=new SoundPool.Builder().setMaxStreams(8).setAudioAttributes(new AudioAttributes.Builder().setUsage(AudioAttributes.USAGE_GAME).setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION).build()).build();effects.setOnLoadCompleteListener((pool,id,status)->{if(status==0)loaded.add(id);else Log.e("CakeMania","Sound decode failed "+id);});for(Map.Entry<String,String> e:assets.paths.entrySet())if(e.getKey().startsWith("SOUND_"))try(AssetFileDescriptor fd=c.getAssets().openFd(pcmPath(e.getValue()))){sounds.put(e.getKey(),effects.load(fd,1));}catch(Exception ex){throw new IllegalStateException("Missing sound "+e.getKey(),ex);}}
    private static String pcmPath(String original){return "decoded-audio/"+original.substring(0,original.length()-4)+".wav";}
    public boolean musicPlaying(){return music!=null&&ready&&music.isPlaying();}
    public String musicTrack(){return track;}
    public int soundsReady(){return loaded.size();}
    public void play(String id){Integer sound=sounds.get(id);if(enabled&&active&&sound!=null&&loaded.contains(sound)){int stream=effects.play(sound,soundVolume,soundVolume,1,0,1);if(stream!=0){streams.addLast(stream);while(streams.size()>8)streams.removeFirst();}}}
    public void setVolumes(float musicLevel,float soundLevel){musicVolume=Math.max(0,Math.min(1,musicLevel));soundVolume=Math.max(0,Math.min(1,soundLevel));if(music!=null)music.setVolume(musicVolume,musicVolume);for(int stream:streams)effects.setVolume(stream,soundVolume,soundVolume);}
    public void music(String path){if(path.equals(track)&&music!=null){resume();return;}releaseMusic();track=path;if(path.isEmpty())return;try(AssetFileDescriptor fd=context.getAssets().openFd(pcmPath(path))){music=new MediaPlayer();music.setAudioAttributes(new AudioAttributes.Builder().setUsage(AudioAttributes.USAGE_GAME).setContentType(AudioAttributes.CONTENT_TYPE_MUSIC).build());music.setDataSource(fd.getFileDescriptor(),fd.getStartOffset(),fd.getLength());music.setLooping(true);music.setVolume(musicVolume,musicVolume);music.setOnPreparedListener(player->{if(player!=music)return;ready=true;if(active&&musicEnabled)player.start();});music.setOnErrorListener((player,what,extra)->{ready=false;Log.e("CakeMania","Music failed "+track+" "+what+"/"+extra);return true;});music.prepareAsync();}catch(Exception ex){throw new IllegalStateException("Music failed "+path,ex);}}
    public void pause(){active=false;if(music!=null&&ready&&music.isPlaying())music.pause();effects.autoPause();}
    public void resume(){active=true;if(music!=null&&ready){if(musicEnabled&&!music.isPlaying())music.start();else if(!musicEnabled&&music.isPlaying())music.pause();}if(enabled)effects.autoResume();}
    private void releaseMusic(){ready=false;if(music!=null){music.release();music=null;}}
    public void close(){releaseMusic();effects.release();}
}
