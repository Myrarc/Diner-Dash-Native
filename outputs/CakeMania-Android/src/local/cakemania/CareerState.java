package local.cakemania;

import android.content.SharedPreferences;
import java.util.*;

/**
 * Persistent state for one native Player/Slot record.
 *
 * Settings remain in the global career preference file.  A CareerState only
 * owns gameplay progress, so creating or resetting a profile cannot erase
 * audio preferences or another profile's upgrades.
 */
public final class CareerState {
    public static final int MAX_LEVEL=48;
    public final String id;
    public String name;
    public int bank,unlocked=1,current=1,lives=4,points;
    public boolean tutorialComplete;
    /** Completion for tutorialscreen level id 10 (the November sequence). */
    public boolean complexTutorialComplete;
    public int tutorialStep;

    public CareerState(String id,String name){this.id=id;this.name=name;}

    public static CareerState load(String id,String fallbackName,SharedPreferences prefs){
        CareerState state=new CareerState(id,prefs.getString("profile_name",fallbackName));
        state.bank=Math.max(0,prefs.getInt("bank",0));
        state.unlocked=Math.max(1,Math.min(MAX_LEVEL,prefs.getInt("unlocked",1)));
        state.current=Math.max(1,Math.min(MAX_LEVEL,prefs.getInt("current",1)));
        state.lives=Math.max(0,Math.min(4,prefs.getInt("lives",4)));
        state.points=Math.max(0,prefs.getInt("points",0));
        state.tutorialComplete=prefs.getBoolean("tutorialComplete",false);
        state.complexTutorialComplete=prefs.getBoolean("complexTutorialComplete",false);
        // An incomplete practice room has no serialisable world snapshot.
        // Only completion is durable; an interrupted practice always restarts
        // from its authored first event.
        state.tutorialStep=0;
        return state;
    }

    public void save(SharedPreferences prefs){
        prefs.edit().putString("profile_name",name).putInt("bank",bank)
            .putInt("unlocked",unlocked).putInt("current",current)
            .putInt("lives",lives).putInt("points",points)
            .putBoolean("tutorialComplete",tutorialComplete)
            .putBoolean("complexTutorialComplete",complexTutorialComplete).apply();
    }

    public void reset(){bank=0;unlocked=1;current=1;lives=4;points=0;tutorialComplete=false;complexTutorialComplete=false;tutorialStep=0;}
}
