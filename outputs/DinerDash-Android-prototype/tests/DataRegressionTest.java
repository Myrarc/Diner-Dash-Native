package local.dinerdash.prototype;

import java.util.*;

/** Missing career goals and Endless purchases must follow the recovered configuration rules. */
public final class DataRegressionTest {
    private static int checks;
    private static final List<String> failures=new ArrayList<>();
    private static void check(boolean ok,String why){checks++;if(!ok)failures.add(why);}
    public static void main(String[] args){
        // game_manager.ls defaults absent bonusGoal to twice minimumTip, rather than a fixed score.
        int[] levels={12,14,16,36,46},expert={8000,10000,12000,14000,20000};
        for(int i=0;i<levels.length;i++)check(LevelData.get(levels[i]).expert==expert[i],"Career shift "+levels[i]+" must use its recovered default expert goal "+expert[i]);
        // All five recovered background drinkspot/podium frames map to these cells, including destination offsets.
        int[] drink={14,3},podium={1,11};
        for(int stage=1;stage<=5;stage++)for(int difficulty=1;difficulty<=3;difficulty++){
            GameEngine.Level l=LevelData.endless(stage,difficulty);String setting="Endless "+stage+"-"+difficulty;
            check(l.drinks==null,setting+" must earn the drink station through an upgrade instead of receiving it at start");
            check(l.podium==null,setting+" must earn the podium through an upgrade instead of receiving it at start");
            GameEngine g=new GameEngine(l,1);g.availableUpgrades=2;
            g.applyUpgrade(LevelData.upgrade("drinks",0));
            check(Arrays.equals(g.destination(GameEngine.DRINKS),drink),setting+" drink upgrade must use the recovered background destination "+Arrays.toString(drink));
            g.applyUpgrade(LevelData.upgrade("podium",0));
            check(Arrays.equals(g.destination(GameEngine.PODIUM),podium),setting+" podium upgrade must use the recovered background destination "+Arrays.toString(podium));
        }
        if(!failures.isEmpty()){for(String failure:failures)System.err.println("FAIL: "+failure);throw new AssertionError(failures.size()+" of "+checks+" data intent checks failed");}
        System.out.println("PASS: "+checks+" data intent checks; five expert defaults and all 15 Endless settings");
    }
}
