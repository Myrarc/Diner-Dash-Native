import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.program.model.listing.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;

/** Export analyzed native code and the evidence needed to navigate it. */
public class ExportCakeMania extends GhidraScript {
    private String clean(Object value){return String.valueOf(value).replace("\t","\\t").replace("\r","\\r").replace("\n","\\n");}
    @Override public void run() throws Exception {
        Path root=Path.of(getScriptArgs()[0]);Files.createDirectories(root.resolve("functions"));Files.createDirectories(root.resolve("assembly-fallback"));
        try(var files=Files.list(root.resolve("functions"))){for(Path p:files.filter(p->p.toString().endsWith(".c")).toList())Files.delete(p);}
        try(var files=Files.list(root.resolve("assembly-fallback"))){for(Path p:files.filter(p->p.toString().endsWith(".asm")).toList())Files.delete(p);}
        Set<Function> priority=new LinkedHashSet<>();
        try(BufferedWriter strings=Files.newBufferedWriter(root.resolve("strings.tsv"));BufferedWriter refs=Files.newBufferedWriter(root.resolve("string-references.tsv"))) {
            strings.write("address\tvalue\n");refs.write("string_address\treference_address\tfunction_address\tfunction_name\tvalue\n");
            DataIterator data=currentProgram.getListing().getDefinedData(true);
            while(data.hasNext()) {
                monitor.checkCancelled();Data d=data.next();if(!d.hasStringValue())continue;
                String value=String.valueOf(d.getValue());strings.write(d.getAddress()+"\t"+clean(value)+"\n");
                var ri=currentProgram.getReferenceManager().getReferencesTo(d.getAddress());
                while(ri.hasNext()) {
                    var r=ri.next();Function f=currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
                    refs.write(d.getAddress()+"\t"+r.getFromAddress()+"\t"+(f==null?"":f.getEntryPoint())+"\t"+(f==null?"":clean(f.getName(true)))+"\t"+clean(value)+"\n");
                    if(f!=null&&value.toLowerCase().matches(".*(\\.dat|\\.xml|patience|max_hearts|start_hearts|menu_hearts|max_layers|cakefill|customerpath|cakelines|cryptdecrypt|resources).*"))priority.add(f);
                }
            }
        }
        List<Function> all=new ArrayList<>();
        try(BufferedWriter index=Files.newBufferedWriter(root.resolve("functions.tsv"));BufferedWriter calls=Files.newBufferedWriter(root.resolve("calls.tsv"))) {
            index.write("address\tname\tbytes\tcalling_convention\texternal\tthunk\tno_return\n");calls.write("caller\tcallee\tcallee_name\n");
            var fi=currentProgram.getFunctionManager().getFunctions(true);
            while(fi.hasNext()) {
                monitor.checkCancelled();Function f=fi.next();
                index.write(f.getEntryPoint()+"\t"+clean(f.getName(true))+"\t"+f.getBody().getNumAddresses()+"\t"+clean(f.getCallingConventionName())+"\t"+f.isExternal()+"\t"+f.isThunk()+"\t"+f.hasNoReturn()+"\n");
                if(!f.isExternal())all.add(f);
                for(Function callee:f.getCalledFunctions(monitor))calls.write(f.getEntryPoint()+"\t"+callee.getEntryPoint()+"\t"+clean(callee.getName(true))+"\n");
            }
        }
        LinkedHashSet<Function> ordered=new LinkedHashSet<>(priority);ordered.addAll(all);
        int passed=0,failed=0;
        DecompInterface decompiler=new DecompInterface();
        try(BufferedWriter combined=Files.newBufferedWriter(root.resolve("CakeMania-pseudocode.c"));BufferedWriter status=Files.newBufferedWriter(root.resolve("decompilation.tsv"))) {
            combined.write("/* Ghidra pseudocode from CakeMania_data.exe. Not original or directly compilable C/C++ source. */\n\n");
            status.write("address\tname\tstatus\terror\n");
            if(!decompiler.openProgram(currentProgram))throw new IOException(decompiler.getLastMessage());
            println("CAKEMANIA_EXPORT_START functions="+ordered.size()+" priority="+priority.size());
            for(Function f:ordered) {
                monitor.checkCancelled();var result=decompiler.decompileFunction(f,15,monitor);
                if(result.decompileCompleted()&&result.getDecompiledFunction()!=null) {
                    String code="/* Address: "+f.getEntryPoint()+"; name: "+f.getName(true)+" */\n"+result.getDecompiledFunction().getC()+"\n";
                    Files.writeString(root.resolve("functions").resolve(f.getEntryPoint()+".c"),code);combined.write(code);passed++;
                    status.write(f.getEntryPoint()+"\t"+clean(f.getName(true))+"\tok\t"+clean(result.getErrorMessage())+"\n");
                }else {
                    failed++;status.write(f.getEntryPoint()+"\t"+clean(f.getName(true))+"\tfailed\t"+clean(result.getErrorMessage())+"\n");
                    StringBuilder assembly=new StringBuilder("; Ghidra assembly fallback. Pseudocode unavailable for "+f.getEntryPoint()+" "+f.getName(true)+"\n; "+clean(result.getErrorMessage())+"\n");
                    var instructions=currentProgram.getListing().getInstructions(f.getBody(),true);
                    while(instructions.hasNext()){Instruction i=instructions.next();assembly.append(i.getAddress()).append("  ");for(byte b:i.getBytes())assembly.append(String.format("%02x ",b&255));assembly.append("  ").append(i.toString()).append('\n');}
                    Files.writeString(root.resolve("assembly-fallback").resolve(f.getEntryPoint()+".asm"),assembly.toString());
                    combined.write("/* Pseudocode failed at "+f.getEntryPoint()+". See assembly-fallback/"+f.getEntryPoint()+".asm and decompilation.tsv. */\n\n");
                }
                if((passed+failed)%100==0){combined.flush();status.flush();println("CAKEMANIA_EXPORT_PROGRESS "+(passed+failed)+"/"+ordered.size()+" failed="+failed);}
            }
        }finally{decompiler.dispose();}
        Files.writeString(root.resolve("summary.txt"),"Program: "+currentProgram.getName()+"\nLanguage: "+currentProgram.getLanguageID()+"\nImage base: "+currentProgram.getImageBase()+"\nAnalyzed functions: "+currentProgram.getFunctionManager().getFunctionCount()+"\nPseudocode exported: "+passed+"\nFailed: "+failed+"\n");
        println("CAKEMANIA_EXPORT_DONE exported="+passed+" failed="+failed);
    }
}
