package local.cakemania;

import android.content.SharedPreferences;
import java.lang.reflect.Proxy;
import java.util.HashMap;
import java.util.Map;

/** Native save fields must survive profile switching and app upgrades. */
public final class CareerStateTest {
    private static void check(boolean ok,String message){if(!ok)throw new AssertionError(message);}
    private static SharedPreferences prefs(Map<String,Object> values){
        SharedPreferences.Editor editor=(SharedPreferences.Editor)Proxy.newProxyInstance(SharedPreferences.Editor.class.getClassLoader(),new Class<?>[]{SharedPreferences.Editor.class},(p,m,a)->{
            if(m.getName().startsWith("put")){values.put((String)a[0],a[1]);return p;}
            if(m.getName().equals("remove")){values.remove(a[0]);return p;}
            if(m.getName().equals("clear")){values.clear();return p;}
            return m.getName().equals("commit")?true:null;
        });
        return (SharedPreferences)Proxy.newProxyInstance(SharedPreferences.class.getClassLoader(),new Class<?>[]{SharedPreferences.class},(p,m,a)->{
            if(m.getName().equals("edit"))return editor;
            if(m.getName().equals("contains"))return values.containsKey(a[0]);
            if(m.getName().equals("getAll"))return new HashMap<>(values);
            if(m.getName().startsWith("get"))return values.getOrDefault(a[0],a[1]);
            return null;
        });
    }
    public static void main(String[] args){
        Map<String,Object> first=new HashMap<>(),second=new HashMap<>();
        first.put("bank",900);first.put("unlocked",17);first.put("current",17);first.put("upgrade2:jill",2);
        CareerState old=CareerState.load("first","Existing",prefs(first));
        check(old.bank==900&&old.current==17&&old.lives==4,"Existing careers retain progress and gain the native four-life default");
        old.lives=1;old.points=1400;old.tutorialComplete=true;old.save(prefs(first));
        CareerState other=CareerState.load("second","New",prefs(second));other.save(prefs(second));
        check(other.bank==0&&other.lives==4&&other.points==0,"A new profile starts with native cash, points and lives");
        CareerState restored=CareerState.load("first","Existing",prefs(first));
        check(restored.lives==1&&restored.points==1400&&restored.tutorialComplete,"Lives, points and tutorial completion survive a profile switch");
        check(first.get("upgrade2:jill").equals(2)&&second.get("upgrade2:jill")==null,"Saving a profile must preserve its upgrades without sharing them");
        restored.reset();restored.save(prefs(first));
        check(CareerState.load("second","New",prefs(second)).lives==4,"Resetting one profile must not change another");
        System.out.println("PASS: existing career fields, native new-profile defaults, profile isolation and life/point/tutorial persistence");
    }
}
