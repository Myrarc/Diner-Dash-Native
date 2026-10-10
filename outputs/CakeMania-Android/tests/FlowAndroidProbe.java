package local.cakemania;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.SystemClock;
import android.view.MotionEvent;
import java.io.File;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Field;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * Bounded integration probe for the real Activity career/result flow.
 *
 * The fixtures use isolated profile slots and are restored before the
 * instrumentation exits. This verifies Android wiring around the already
 * tested engine; it does not claim native Windows parity.
 */
public final class FlowAndroidProbe extends Instrumentation {
    private static final String GLOBAL="career";
    private static final String FAIL_PROFILE="flow_fail_fixture";
    private static final String SUCCESS_PROFILE="flow_success_fixture";
    private Activity activity;
    private Map<String,Map<String,Object>> preferences;
    private int checks;

    @Override public void onCreate(Bundle arguments){super.onCreate(arguments);start();}

    @Override public void onStart(){
        Bundle result=new Bundle();
        int resultCode=-1;
        try{
            Context context=getTargetContext();
            preferences=snapshotPreferences(context);
            seedFixtures(context);
            activity=startActivitySync(new Intent(context,MainActivity.class).addFlags(Intent.FLAG_ACTIVITY_NEW_TASK));
            waitForIdleSync();
            runUi(()->verifyFailedMonths((MainActivity)activity));
            runUi(()->verifySuccessfulMonth((MainActivity)activity));
            runUi(()->verifyTutorialCash((MainActivity)activity));
            runUi(()->verifyCustomerInput((MainActivity)activity));
            waitForIdleSync();
            android.graphics.Bitmap screenshot=getUiAutomation().takeScreenshot();
            try(java.io.FileOutputStream out=new java.io.FileOutputStream(new File(context.getFilesDir(),"customers-activity.png"))){screenshot.compress(android.graphics.Bitmap.CompressFormat.PNG,100,out);}
            verifyNewCareerStory((MainActivity)activity);
            waitForIdleSync();screenshot=getUiAutomation().takeScreenshot();
            try(java.io.FileOutputStream out=new java.io.FileOutputStream(new File(context.getFilesDir(),"cake-intro-after-tutorial.png"))){screenshot.compress(android.graphics.Bitmap.CompressFormat.PNG,100,out);}
            runUi(()->{MainActivity a=(MainActivity)activity;Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);layoutControls(view);tap(a,view,468,497);});waitForIdleSync();
            runUi(()->{MainActivity a=(MainActivity)activity;check("game".equals(a.screen)&&!a.game.paused&&a.game.level.number==1,"Let's Play must enter the same real month after its intro");});
            verifyBakeryStory((MainActivity)activity);
            result.putString("summary","PASS: "+checks+" real Activity career/result checks; fixture profiles and preferences restored");
        }catch(Throwable error){
            resultCode=0;
            result.putString("failure",android.util.Log.getStackTraceString(error));
        }finally{
            try{
                if(activity!=null){runOnMainSync(()->activity.finish());waitForIdleSync();}
            }catch(Throwable ignored){}
            try{restorePreferences(getTargetContext(),preferences);}catch(Throwable restoreError){
                resultCode=0;
                result.putString("restoreFailure",android.util.Log.getStackTraceString(restoreError));
            }
            finish(resultCode,result);
        }
    }

    private interface UiWork { void run() throws Exception; }

    private void verifyCustomerInput(MainActivity a)throws Exception{
        invoke(a,"start",new Class<?>[]{int.class},1);invoke(a,"show",new Class<?>[]{String.class},"game");a.tutorial=null;
        GameEngine g=a.game;g.suppressArrivals=true;g.customers.clear();
        GameData.Node arrival=g.arrivals.get(0).copy();arrival.attrs.put("guid","delivery");GameEngine.Customer front=g.addCustomer(arrival);
        arrival=arrival.copy();arrival.attrs.put("guid","cupid");GameEngine.Customer angel=g.addCustomer(arrival);
        Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);a.syncControls();
        tap(a,view,131,392);
        check(g.queue.size()==1&&g.queue.get(0).customer==angel,"A real Activity tap on Cupid's visible head must bypass the overlapping front customer");
        for(int i=0;i<150&&angel.state==GameEngine.CustomerState.WAIT_MENU;i++)g.tick(.01f);
        check(angel.state==GameEngine.CustomerState.READING&&front.state==GameEngine.CustomerState.WAIT_MENU,"The queued menu must reach Cupid without serving the front customer");
        Set<Integer> poses=new LinkedHashSet<>();for(int i=0;i<1000;i++){g.tick(.01f);poses.add(front.visualFrame);}
        check(poses.size()>5&&front.visualState==0,"Actual engine updates must advance the waiting customer's entire idle sequence");
        float hover=angel.hoverY;g.paused=true;g.tick(1);check(angel.hoverY==hover,"Paused gameplay must freeze the angel's hover motion");a.syncControls();view.invalidate();
    }

    private void runUi(UiWork work)throws Exception{
        final Throwable[] error={null};
        runOnMainSync(()->{try{work.run();}catch(Throwable failure){error[0]=failure;}});
        if(error[0]!=null)throw asException(error[0]);
    }

    private static Exception asException(Throwable error){
        if(error instanceof Exception)return (Exception)error;
        if(error instanceof Error)throw (Error)error;
        return new Exception(error);
    }

    private void verifyFailedMonths(MainActivity a)throws Exception{
        check(a.lives==4,"Failure fixture must begin with four lives");
        for(int attempt=1;attempt<=4;attempt++){
            invoke(a,"start",new Class<?>[]{int.class},1);
            check(a.game!=null&&a.game.level.number==1,"start(1) must create the real January game");
            a.game.finished=true;a.game.won=false;
            invoke(a,"finished",new Class<?>[0]);
            check(a.lives==4-attempt,"A failed month must consume exactly one life: "+attempt);
            check(a.points==0&&a.bank==0,"A failed month must not award points or cash");
        }
        check(a.gameOver&&"gameover".equals(a.screen),"The fourth failed month must enter the distinct game-over screen");
        int lives=a.lives;
        invoke(a,"finished",new Class<?>[0]);
        check(a.lives==lives&&a.gameOver,"Duplicate finished() must not consume another life after game over");
        check(a.getSharedPreferences("career_profile_"+FAIL_PROFILE,0).getInt("lives",-1)==0,
            "The zero-life result must persist in the active profile slot");
    }

    private void verifySuccessfulMonth(MainActivity a)throws Exception{
        // Switch only through the production profile loader; the fixture was
        // seeded before launch and is isolated from the failed profile.
        invoke(a,"loadProfile",new Class<?>[]{String.class},SUCCESS_PROFILE);
        check(a.lives==4&&a.bank==100&&a.points==0,"Success fixture must load its independent profile state");
        invoke(a,"start",new Class<?>[]{int.class},1);
        GameEngine game=a.game;
        game.money=300;game.cakeRevenue=200;game.tips=100;game.customerLostMoney=50;game.cakeLostMoney=30;
        game.finished=true;game.won=true;
        invoke(a,"finished",new Class<?>[0]);
        check(a.bank==400&&a.points==300&&a.unlocked==2,"A $300 win must update bank, points and next-level unlock once");
        check("result".equals(a.screen),"A successful month must open the result screen");
        String text=a.resultText("[%CAKES_SERVED]|[%CUSTOMER_TIP]|[%CUSTOMERS_LOST_MONEY]|[%CAKES_LOST]|[%TOTAL_LEVEL_MONEY]|[%TOTAL_MONEY]");
        check("200|100|50|30|300|400".equals(text),"Result placeholders must keep cake revenue, tips and losses separate: "+text);
        invoke(a,"finished",new Class<?>[0]);
        check(a.bank==400&&a.points==300&&a.unlocked==2,"Duplicate finished() must not award the win twice");
        SharedPreferences saved=a.getSharedPreferences("career_profile_"+SUCCESS_PROFILE,0);
        check(saved.getInt("bank",-1)==400&&saved.getInt("points",-1)==300&&saved.getInt("unlocked",-1)==2,
            "Success cash, points and unlock must persist in the profile slot");
        invoke(a,"action",new Class<?>[]{String.class},"next");
        check("shop".equals(a.screen),"Result Continue must open the native kitchen shop");
        Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);a.syncControls();
        GameEngine.Station decorator=game.station("decorator1");
        tap(a,view,163+.75f*(decorator.x+decorator.w/2),20+.75f*(decorator.y+decorator.h/2));
        check("decorator1".equals(a.shopSelection)&&a.bank==400&&!decorator.enabled(),"Kitchen tap must select the pictured machine without buying it");
        check(a.selectedShopChoice()!=null&&a.selectedShopChoice().i("purchase_points",0)==400,"Selected preview must use the next authored upgrade and price");
        a.syncControls();tap(a,view,122,526);
        check(a.bank==0&&decorator.enabled(),"Buy button must debit exactly $400 and enable the selected kitchen item");
        check(saved.getInt("upgrade1:decorator1",0)==1&&saved.getInt("bank",-1)==0,"A kitchen purchase must persist to the same career slot");
        a.syncControls();tap(a,view,122,572);
        check(a.game.level.number==2&&"intro".equals(a.screen)&&a.game.station("decorator1").enabled(),"Finish must start February with the purchased equipment");
    }
    private void verifyTutorialCash(MainActivity a)throws Exception{
        invoke(a,"startTutorialPractice",new Class<?>[]{int.class},0);
        GameEngine g=a.game;GameData.Node arrival=new GameData.Node("Customer");arrival.attrs.put("guid","tutor");GameEngine.Customer customer=g.addCustomer(arrival);customer.state=GameEngine.CustomerState.CASH;customer.cakePrice=30;customer.departureFrame=-1;
        a.tutorial.start(a.data.tutorialSequence(0),(id,order)->{},66);
        a.syncControls();Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);
        tap(a,view,245,490);
        check(a.tutorial.complete()&&g.queue.size()==1&&g.queue.get(0).customer==customer,"Final tutorial cash tap must both advance the authored gate and queue actual collection");
        for(int i=0;i<2000&&!g.queue.isEmpty();i++)g.tick(.01f);
        check(customer.cashCollected&&g.money==customer.payment(),"The final lesson action must collect the visible coins before career gameplay starts");
        check(!g.level.paths.first("CustomerPath").children.get(0).s("y_money").equals("450")&&g.customerPoints.get(0).i("y_money",0)==496,"Tutorial customer positions must come from the native career-level copy");
    }
    private void verifyNewCareerStory(MainActivity a)throws Exception{
        Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);
        runUi(()->{invoke(a,"newCareer",new Class<?>[]{});check("story".equals(a.screen)&&a.game.level.number==0,"New profiles prepare a separate practice room during the opening comics");});waitForIdleSync();
        for(int i=0;i<a.storyImages.size();i++){final int page=i+1;runUi(()->{layoutControls(view);tap(a,view,662,558);});waitForIdleSync();runUi(()->check(a.storyPage==page,"Each real Continue tap must advance one opening comic"));}
        runUi(()->{
        android.graphics.Bitmap bitmap=android.graphics.Bitmap.createBitmap(view.getWidth(),view.getHeight(),android.graphics.Bitmap.Config.ARGB_8888);view.draw(new android.graphics.Canvas(bitmap));
        try(java.io.FileOutputStream out=new java.io.FileOutputStream(new File(getTargetContext().getFilesDir(),"cake-story-after-comics.png"))){bitmap.compress(android.graphics.Bitmap.CompressFormat.PNG,100,out);}bitmap.recycle();
        check("game".equals(a.screen)&&!a.game.paused,"Opening comics must resume the prepared lesson directly, without an empty intro or month map");
        check(a.tutorial.eventIndex()==3&&a.tutorial.isWaitingForClick()&&a.game.elapsed<2,"Opening comics must preserve the lesson's first authored click gate");
        });waitForIdleSync();runUi(()->{
        check("game".equals(a.screen)&&a.game.level.number==0&&a.tutorial!=null&&!a.game.paused,"New Game must enter the separate practice lesson after its final comic");
        a.tutorial.start(a.data.tutorialSequence(0),(id,order)->{},66);a.tutorial.click(245,490);
        check(a.tutorial.complete()&&a.game.queue.isEmpty(),"The completion fixture must satisfy the lesson gate before transitioning");
        invoke(a,"completeTutorialPractice",new Class<?>[]{});
        check(a.career.tutorialComplete&&a.tutorial==null&&a.game.level.number==1,"Completed practice must return to the real January level");
        check("intro".equals(a.screen)&&a.game.paused&&a.game.elapsed==0,"January narrative and goal must appear before its gameplay timer begins");
        check(a.game.level.startScreen!=null&&!a.game.level.intro.isEmpty()&&"200".equals(a.resultText("[%BAKER_GOAL]")),"The intro must bind original January copy and the career goal rather than tutorial data");
        });
    }
    private static void layoutControls(GameView view){android.view.View parent=(android.view.View)view.getParent();parent.measure(android.view.View.MeasureSpec.makeMeasureSpec(parent.getWidth(),android.view.View.MeasureSpec.EXACTLY),android.view.View.MeasureSpec.makeMeasureSpec(parent.getHeight(),android.view.View.MeasureSpec.EXACTLY));parent.layout(parent.getLeft(),parent.getTop(),parent.getRight(),parent.getBottom());}
    private void verifyBakeryStory(MainActivity a)throws Exception{
        Field field=MainActivity.class.getDeclaredField("view");field.setAccessible(true);GameView view=(GameView)field.get(a);
        runUi(()->{a.openTransitionComics(1,new AssetStore(getTargetContext()));check("story".equals(a.screen),"Later bakery comics must retain their own story route");});waitForIdleSync();
        for(int i=0;i<a.storyImages.size();i++){runUi(()->{layoutControls(view);tap(a,view,662,558);});waitForIdleSync();}
        runUi(()->check("map".equals(a.screen)&&a.tutorial==null,"Later bakery comics must still return to month selection, rather than restarting the first lesson"));
    }
    private static void tap(MainActivity a,GameView view,float x,float y){int[] origin=new int[2];view.getLocationInWindow(origin);float px=origin[0]+view.ox+x*view.scale,py=origin[1]+view.oy+y*view.scale;long time=SystemClock.uptimeMillis();MotionEvent down=MotionEvent.obtain(time,time,MotionEvent.ACTION_DOWN,px,py,0),up=MotionEvent.obtain(time,time+20,MotionEvent.ACTION_UP,px,py,0);try{a.dispatchTouchEvent(down);a.dispatchTouchEvent(up);}finally{down.recycle();up.recycle();}}

    private void check(boolean condition,String message){checks++;if(!condition)throw new AssertionError(message);}

    private static Object invoke(Object target,String name,Class<?>[] types,Object... arguments)throws Exception{
        Method method=target.getClass().getDeclaredMethod(name,types);method.setAccessible(true);
        try{return method.invoke(target,arguments);}catch(InvocationTargetException error){Throwable cause=error.getCause();if(cause instanceof Exception)throw (Exception)cause;if(cause instanceof Error)throw (Error)cause;throw error;}
    }

    private static Map<String,Map<String,Object>> snapshotPreferences(Context context){
        Set<String> names=preferenceNames(context);
        Map<String,Map<String,Object>> result=new LinkedHashMap<>();
        for(String name:names)result.put(name,copyValues(context.getSharedPreferences(name,0).getAll()));
        return result;
    }

    private static Set<String> preferenceNames(Context context){
        Set<String> names=new LinkedHashSet<>();
        File directory=new File(context.getApplicationInfo().dataDir,"shared_prefs");
        String[] files=directory.list();
        if(files!=null)for(String file:files)if(file.endsWith(".xml"))names.add(file.substring(0,file.length()-4));
        // The target package may deny directory listing to the instrumentation
        // process. These are still included so fixture files cannot leak.
        names.add(GLOBAL);names.add("career_profile_"+FAIL_PROFILE);names.add("career_profile_"+SUCCESS_PROFILE);
        String ids=context.getSharedPreferences(GLOBAL,0).getString("profile_ids","");
        for(String id:ids.split(",")){String clean=id.trim();if(!clean.isEmpty())names.add("career_profile_"+clean);}
        return names;
    }

    private static Map<String,Object> copyValues(Map<String,?> source){
        Map<String,Object> copy=new LinkedHashMap<>();
        for(Map.Entry<String,?> entry:source.entrySet()){
            Object value=entry.getValue();
            if(value instanceof Set){Set<String> strings=new LinkedHashSet<>();for(Object item:(Set<?>)value)if(item instanceof String)strings.add((String)item);copy.put(entry.getKey(),strings);}
            else copy.put(entry.getKey(),value);
        }
        return copy;
    }

    private static void seedFixtures(Context context){
        context.getSharedPreferences(GLOBAL,0).edit().clear()
            .putString("profile_ids",FAIL_PROFILE+","+SUCCESS_PROFILE)
            .putString("active_profile",FAIL_PROFILE)
            .putBoolean("music",false).putBoolean("sound",false)
            .putFloat("musicVolume",1f).putFloat("soundVolume",.8f).commit();
        seedProfile(context,FAIL_PROFILE,0,4);
        seedProfile(context,SUCCESS_PROFILE,100,4);
    }

    private static void seedProfile(Context context,String id,int bank,int lives){
        context.getSharedPreferences("career_profile_"+id,0).edit().clear()
            .putString("profile_name",id)
            .putInt("bank",bank).putInt("unlocked",1).putInt("current",1)
            .putInt("lives",lives).putInt("points",0)
            .putBoolean("tutorialComplete",true).putBoolean("complexTutorialComplete",true)
            .commit();
    }

    private static void restorePreferences(Context context,Map<String,Map<String,Object>> saved){
        if(saved==null)return;
        Set<String> names=preferenceNames(context);names.addAll(saved.keySet());
        for(String name:names){
            SharedPreferences.Editor editor=context.getSharedPreferences(name,0).edit().clear();
            Map<String,Object> values=saved.get(name);
            if(values!=null)for(Map.Entry<String,Object> entry:values.entrySet())put(editor,entry.getKey(),entry.getValue());
            if(!editor.commit())throw new IllegalStateException("Could not restore SharedPreferences "+name);
        }
    }

    private static void put(SharedPreferences.Editor editor,String key,Object value){
        if(value instanceof Boolean)editor.putBoolean(key,(Boolean)value);
        else if(value instanceof Integer)editor.putInt(key,(Integer)value);
        else if(value instanceof Long)editor.putLong(key,(Long)value);
        else if(value instanceof Float)editor.putFloat(key,(Float)value);
        else if(value instanceof String)editor.putString(key,(String)value);
        else if(value instanceof Set){Set<String> strings=new LinkedHashSet<>();for(Object item:(Set<?>)value)if(item instanceof String)strings.add((String)item);editor.putStringSet(key,strings);}
    }
}
