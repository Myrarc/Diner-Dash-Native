# Career 2-9 Expert input replay

The unchanged 0.3.12 APK earned 15,115 with all 22 parties served and none lost. The installed `GameView` handled 22 guest drags and 136 object taps under a controlled 16 ms clock. See `installed-16.log` and `result-16.png`. `installed-100.log` and `result-100.png` retain a separate 15,105 run at 100 ms. Neither is a real-time human or physical-device playthrough.

`inputs-N.csv` records input times in milliseconds. Seat rows are `time,seat,party,table,chairOffset`; party and table IDs and chair offsets are zero-based. Queue rows are `time,queue,target`; targets use the production GameEngine constants. `expert-inputs.csv` is the installed 16 ms recording. All guest arrays keep their original order; arbitrary guest rotation is not used.

`Level19ExpertReplay.java` and `Level19ExpertFrames.java` generate frame-specific input recordings using a fixed seating plan and service phases. These are verification helpers, not game code. `Level19ReplayCheck.java` is a separate input-only consumer compiled freshly with the production engine. It rejects invisible guests, illegal seating, unusable targets or capacity violations and reconciles chair, service and tip points. `independent.log` records five successful checks, each using its matching clock interval and recording.

From the app source directory, reproduce one independent check with:

```sh
mkdir -p /tmp/diner-expert-check
javac -d /tmp/diner-expert-check src/local/dinerdash/prototype/GameEngine.java src/local/dinerdash/prototype/LevelData.java verification/level-2-9/expert/Level19ReplayCheck.java
java -cp /tmp/diner-expert-check local.dinerdash.prototype.Level19ReplayCheck verification/level-2-9/expert/inputs-16.csv 16
```

`AndroidLevel19ExpertReplay.java` contains the installed instrumentation probe. Its test APK packages `expert-inputs.csv` as an asset and references the installed game's classes rather than bundling an alternate engine. The probe stops automatic frame advancement and explicitly advances the clock, then calls the game's actual touch handler and result callback. It modifies career preferences while checking that the earned Expert score is saved. `save-restore.json` confirms all eleven local emulator preference files were restored from the pre-test backup. This probe should only be run with a save backup.

`integrity.json` identifies the APK and unchanged GameEngine/LevelData bytes. No production files or scoring constants changed. The original-game reference receipt at https://www.youtube.com/watch?v=-1F1AO7pD3M&t=5675s shows level 2-9, 15,285, 22 served, zero lost and Expert. Original Windows execution and comparative timing/ergonomic tests were not performed.
