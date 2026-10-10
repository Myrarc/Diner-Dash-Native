package local.dinerdash.prototype;
import android.app.Instrumentation;
import android.content.Intent;
import android.graphics.*;
import android.os.Bundle;
import android.view.View;
import java.io.*;
import java.lang.reflect.*;
import java.util.*;

/** Installed font/layout fixtures only; no purchases, scores or preferences are written. */
public final class AndroidFontProbe extends Instrumentation {
    private MainActivity activity;
    private MenuView menu;
    private GameView board;
    private AssetStore assets;
    private String viewport;
    private final StringBuilder report=new StringBuilder();
    private Object field(String name)throws Exception{Field f=MainActivity.class.getDeclaredField(name);f.setAccessible(true);return f.get(activity);}
    @Override public void onCreate(Bundle b){super.onCreate(b);viewport=b.getString("viewport","phone");start();}
    private void capture(String name)throws Exception{waitForIdleSync();Thread.sleep(200);Bitmap b=getUiAutomation().takeScreenshot();try(FileOutputStream out=new FileOutputStream(new File(getTargetContext().getExternalFilesDir("review"),"fonts-"+viewport+"-"+name+".png"))){b.compress(Bitmap.CompressFormat.PNG,100,out);}b.recycle();}
    private void show(String screen,GameEngine g)throws Exception{runOnMainSync(()->{board.setActive(false);board.setGame(g);board.setVisibility(View.VISIBLE);menu.game=g;menu.show(screen);});capture(screen);}
    private void width(String label,String s,float size,float limit,Typeface face){Paint p=new Paint();p.setTypeface(face);p.setTextSize(size);report.append(label).append('\t').append(s).append('\t').append(p.measureText(s)).append('\t').append(limit).append('\n');}
    @Override public void onStart(){Bundle out=new Bundle();try{
        activity=(MainActivity)startActivitySync(new Intent(getTargetContext(),MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));waitForIdleSync();menu=(MenuView)field("menus");board=(GameView)field("board");assets=(AssetStore)field("assets");
        width("goal","EXPERT: 100,000",20,159,assets.mrB);width("title","Christopher Montgomery",17,166,assets.komikaAxis);width("profile","Christopher Montgomery",22,268,assets.mrB);
        for(String type:new String[]{"drinks","shoes","oven","podium","stereo","maitred"})for(int i=0;LevelData.upgrade(type,i)!=null;i++){String name=LevelData.upgrade(type,i).name;width("choice",name,18,184,assets.mrB);width("inventory",name,16,237,assets.mrB);}
        int longest=1;for(int i=2;i<=50;i++)if(LevelData.get(i).intro.length()>LevelData.get(longest).intro.length())longest=i;
        runOnMainSync(()->{menu.profile="Christopher Montgomery";menu.profiles[0]=menu.profile;menu.show("title_screen");board.setVisibility(View.GONE);});capture("title");
        runOnMainSync(()->menu.show("login"));capture("login");
        runOnMainSync(()->{menu.hiscoreMode=2;menu.scoreNames[2][0]=menu.profile;menu.scoreValues[2][0]=999999;menu.show("hiscore");});capture("hiscore");
        GameEngine g=new GameEngine(LevelData.get(longest),1);g.paused=true;menu.intro=g.level.intro;show("startlevel",g);
        g=new GameEngine(LevelData.get(50),1);g.paused=true;g.score=g.goal;show("pause",g);
        final GameEngine hud=g;runOnMainSync(()->{menu.setVisibility(View.GONE);board.setGame(hud);board.setVisibility(View.VISIBLE);board.setActive(false);});capture("hud");
        g.won=false;g.served=23;g.abandoned=4;g.score=13000;menu.result="We didn't earn enough this shift. Use the coffee to make customers happier and earn bigger tips.";menu.totalScore=123456;show("endlevel",g);
        g=new GameEngine(LevelData.endless(1,1),1);g.paused=true;g.availableUpgrades=1;for(String type:new String[]{"drinks","shoes","oven","podium","stereo","maitred"}){int count=0;while(LevelData.upgrade(type,count)!=null)count++;g.upgrades.put(type,count);}menu.upgradeChoices=Arrays.asList(LevelData.upgrade("drinks",2),LevelData.upgrade("stereo",2),LevelData.upgrade("podium",3));show("endless_shop",g);
        try(FileWriter writer=new FileWriter(new File(getTargetContext().getExternalFilesDir("review"),"font-widths-"+viewport+".tsv"))){writer.write(report.toString());}
        out.putString("summary","PASS: two packaged fonts loaded; eight installed screens captured; native text widths recorded");runOnMainSync(()->activity.finish());finish(-1,out);
    }catch(Throwable e){out.putString("failure",e.toString());finish(1,out);}}
}
