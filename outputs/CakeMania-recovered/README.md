# Cake Mania recovery tools

This directory contains the scripts used to inspect the supplied 32-bit Windows Cake Mania executable with Ghidra and decode its original archive and font formats. The Android rebuild is in [CakeMania-Android](../CakeMania-Android).

- `tools/ExportCakeMania.java` exports analyzed function pseudocode, calls, strings and assembly fallbacks from an open Ghidra program.
- `tools/RepairCakeManiaReturns.java` repairs the false non-returning metadata found during this executable's analysis.
- `tools/CheckCakeMania.java` checks the imported program.
- `tools/extract_archives.py` decodes the supplied game archives into the destination you choose.
- `tools/extract_fonts.py` exports bitmap-font metrics from those extracted assets; it needs Pillow.

Example archive and font extraction from the repository root:

```sh
python3 outputs/CakeMania-recovered/tools/extract_archives.py /path/to/CakeMania outputs/CakeMania-recovered
python3 outputs/CakeMania-recovered/tools/extract_fonts.py outputs/CakeMania-recovered
```

The Ghidra scripts run through Ghidra's script manager or headless analyzer. Exported pseudocode records the addresses of native functions and is analysis output, not directly recompilable Android source. Selected native evidence is retained with the Android verification reports.

Supply your own Windows game files for a new analysis. The original executable, DAT archives, extracted recovery directory, full pseudocode export and Ghidra project database are excluded from this Git snapshot. The Android project already includes prepared runtime assets, so none of these tools are required for a normal APK build.
