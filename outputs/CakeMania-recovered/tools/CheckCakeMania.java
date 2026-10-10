import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.listing.*;
import java.nio.file.*;

/** Audit returning CRT functions and retry the two initial decompiler failures. */
public class CheckCakeMania extends GhidraScript {
    @Override public void run() throws Exception {
        Path root=Path.of(getScriptArgs()[0]);StringBuilder report=new StringBuilder();
        for(String address:new String[]{"00561046","00560041","00560046"}) {
            Function f=currentProgram.getFunctionManager().getFunctionAt(toAddr(address));
            report.append(address+" "+f.getName()+" noReturn="+f.hasNoReturn()+"\n");
            var refs=currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());int count=0;
            while(refs.hasNext()) {
                var ref=refs.next();Instruction i=currentProgram.getListing().getInstructionAt(ref.getFromAddress());
                if(i!=null&&i.getFlowType().isCall()) {
                    count++;if(i.getFlowOverride()!=FlowOverride.NONE)report.append("  call "+i.getAddress()+" override="+i.getFlowOverride()+"\n");
                }
            }
            report.append("  call sites="+count+"\n");
        }
        DecompInterface decompiler=new DecompInterface();
        try {
            if(!decompiler.openProgram(currentProgram))throw new Exception(decompiler.getLastMessage());
            for(String address:new String[]{"004293b0","0056404d"}) {
                Function f=currentProgram.getFunctionManager().getFunctionAt(toAddr(address));
                var result=decompiler.decompileFunction(f,60,monitor);
                if(result.decompileCompleted()&&result.getDecompiledFunction()!=null) {
                    Files.writeString(root.resolve("functions").resolve(address+".c"),"/* Address: "+address+"; name: "+f.getName(true)+"; retry with 60 second timeout */\n"+result.getDecompiledFunction().getC()+"\n");
                    report.append(address+" RETRY_OK\n");
                }else report.append(address+" RETRY_FAILED "+result.getErrorMessage()+"\n");
            }
        }finally{decompiler.dispose();}
        Files.writeString(root.resolve("retry-and-return-audit.txt"),report.toString());println(report.toString());
    }
}
