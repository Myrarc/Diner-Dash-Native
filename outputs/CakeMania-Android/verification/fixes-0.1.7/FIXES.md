# Cake Mania 0.1.7

APK SHA-256: `cd998f0e9251a13639204b997bd189663e97703c3667bc9780964bf35bb04dc5`.

Opening comics forced an intro while the prepared engine was a tutorial level without StartScreen, producing an empty notebook. Fonts and career copy were already present.

- Opening comic Continue opens the original month map; selecting January starts the practice lesson
- Completing the first practice lesson opens the real January intro with original narrative and $200 goal; clock remains paused until Let's Play

All 144 month text layouts, 48 Activity checks, two host suites and both full real-input tutorial runs pass. The old APK fails the new opening-flow assertion and reproduces the blank screenshot. Original preference bytes and display settings were restored; the test package and task-owned emulator were removed.

Bounded opening-flow correction. The real-input tutorials complete through gameplay; the Activity probe also uses an isolated completed-lesson fixture to verify the intro transition. Successful checks do not establish whole-game Windows parity. Windows and physical Android comparisons were not run. Other test boundaries are recorded in `report.json`.
