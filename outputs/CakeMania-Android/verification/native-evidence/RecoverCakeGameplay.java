import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.listing.Function;
import java.nio.file.*;

/** Recover gameplay callbacks and form hit tests missed by initial function discovery. */
public class RecoverCakeGameplay extends GhidraScript {
    @Override public void run() throws Exception {
        Path root=Path.of(getScriptArgs()[0]);Files.createDirectories(root);
        DecompInterface d=new DecompInterface();
        try {
            if(!d.openProgram(currentProgram))throw new Exception(d.getLastMessage());
            for(String address:new String[]{"00434480","00435820","0044ab40","0044e5d0","00436fa0","00433fe0"}) {
                var entry=toAddr(address);
                Function f=getFunctionAt(entry);
                if(f==null){disassemble(entry);f=createFunction(entry,"Recovered_"+address);}
                if(f==null)throw new Exception("Could not define "+address);
                var result=d.decompileFunction(f,60,monitor);
                if(!result.decompileCompleted())throw new Exception(address+": "+result.getErrorMessage());
                Files.writeString(root.resolve(address+".c"),"/* Native address "+address+". Recovered in read-only Ghidra session. */\n"+result.getDecompiledFunction().getC());
                println(address+" "+f.getBody().getNumAddresses()+" bytes exported");
            }
        } finally { d.dispose(); }
    }
}
