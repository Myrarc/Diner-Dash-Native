import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.app.decompiler.DecompInterface;
import java.nio.file.*;
import java.util.*;

/** Correct a verified false no-return inference, without patching executable bytes. */
public class RepairCakeManiaReturns extends GhidraScript {
    @Override public void run() throws Exception {
        StringBuilder report=new StringBuilder("Assembly evidence: _free at 0x561046 returns through __SEH_epilog at 0x5610b1 and RET at 0x5610b6. Both delete thunks jump to this function.\n");
        // The discovered-no-return heuristic reintroduced the verified false flag.
        currentProgram.getOptions(Program.ANALYSIS_PROPERTIES).setBoolean("Non-Returning Functions - Discovered",false);
        report.append("Disabled discovered-no-return heuristic for this analyzed program; previously identified real no-return functions are retained.\n");
        Set<Function> functions=new LinkedHashSet<>();
        for(String address:new String[]{"00561046","00560041","00560046"}) {
            Function f=currentProgram.getFunctionManager().getFunctionAt(toAddr(address));
            if(f==null||!f.getName().equals("_free"))throw new Exception("Unexpected CRT function at "+address);
            report.append(address+" original noReturn="+f.hasNoReturn()+"\n");functions.add(f);
            f.setNoReturn(false);f.setSignatureSource(SourceType.USER_DEFINED);
        }
        int repaired=0;
        for(Function f:functions) {
            var refs=currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint());
            while(refs.hasNext()) {
                var r=refs.next();Instruction i=currentProgram.getListing().getInstructionAt(r.getFromAddress());
                if(i!=null&&i.getFlowType().isCall()&&i.getFlowOverride()==FlowOverride.CALL_RETURN) {
                    report.append("Cleared call-return override "+i.getAddress()+"\n");i.setFlowOverride(FlowOverride.NONE);repaired++;
                }
            }
        }
        analyzeChanges(currentProgram);
        for(Function f:functions)if(f.hasNoReturn())throw new Exception("Returning CRT function was marked no-return again");
        DecompInterface decompiler=new DecompInterface();
        try {
            if(!decompiler.openProgram(currentProgram))throw new Exception(decompiler.getLastMessage());
            Function parser=currentProgram.getFunctionManager().getFunctionAt(toAddr("00414200"));
            var result=decompiler.decompileFunction(parser,30,monitor);
            if(!result.decompileCompleted()||result.getDecompiledFunction()==null)throw new Exception("Customer parser verification failed: "+result.getErrorMessage());
            String code=result.getDecompiledFunction().getC();
            if(code.contains("Subroutine does not return"))throw new Exception("Incorrect no-return truncation remains in customer parser");
            report.append("Customer parser regenerated without false no-return truncation.\n");
        }finally{decompiler.dispose();}
        report.append("Cleared overrides: "+repaired+"\nExecutable bytes unchanged; corrected analysis metadata only.\n");
        Files.writeString(Path.of(getScriptArgs()[0]).resolve("return-metadata-repair.txt"),report.toString());
        println("CAKEMANIA_RETURN_METADATA_REPAIRED calls="+repaired);
    }
}
