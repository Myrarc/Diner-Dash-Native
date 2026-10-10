package local.dinerdash.prototype;

import android.app.Instrumentation;
import android.os.Bundle;

/** Run source-derived timing boundaries against the installed app's engine. */
public final class AndroidPatienceTest extends Instrumentation {
    @Override public void onCreate(Bundle args){super.onCreate(args);start();}
    @Override public void onStart(){
        Bundle result=new Bundle();
        try {result.putString("result","PASS: "+PatienceTest.runChecks()+" installed patience intent checks");finish(-1,result);}
        catch(Throwable error){result.putString("result","FAIL: "+error);finish(0,result);}
    }
}
