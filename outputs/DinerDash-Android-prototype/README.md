# Diner Dash — Android fidelity rebuild 0.3.12

Install `../DinerDash-Android.apk` over the previous version. The package and local signing certificate are unchanged. Android 6.0 or newer is required; the app has no Internet permission.

This is a native Java/Canvas reconstruction from recovered Lingo and assets. It contains all 50 career schedules and 15 endless restaurant/difficulty variants, 1,898 original bitmap assets, 62 MP3 members, 162 layouts/animations and 206 configuration records. Importing those records does not establish complete original-runtime parity.

## 0.3.12 approved recovered fonts

This release packages the recovered Komika Axis and Mr.B TTFs. Daniel and Daniel Black are excluded at the user's request. Mr.B is used for dynamic HUD, pause, intro, shop, profile and high-score text; Komika Axis is used for the level label and current-player name. Result narrative, shift identifier and score totals retain their existing Android casual face. Original bitmap lettering is unchanged.

Text is measured with the same selected face used to draw it. Shop labels wrap within their recovered text rectangles; long player names and HUD numbers fit their existing columns. Layout positions, colors, gameplay, sprites and audio are unchanged. The face assignments are reconstruction choices informed by the source text records and user-approved comparison; the active font run on every original text member has not been established.

See [current verification](verification.json) for the installed checks, phone/tablet captures and package integrity. This release has not been tested on a physical device or against the Windows runtime.

## Historical 0.3.11 customer patience and scoring audit

Career base patience matches the recovered profiles: ordinary waiting guests lose one heart every ten seconds, businesswomen every six, older men every fifteen and boys every seven. Guests arrive with six hearts; level 1-1 disables passive mood loss. Main tips, action chains, chair bonuses and penalties match the recovered formulas.

Endless ramps previously shortened active patience timers and later seated states through a live global multiplier. Party multipliers and active happy/mad thresholds now retain their original ownership. Current fast-service windows survive ramps; stereo changes apply on the next state entry. No Career constants, scores or sprites changed.

All seven model suites pass 40,946 checks. Five installed suites pass 723 checks, including 36 patience boundaries. APK signature, ZIP integrity, installed byte identity, unchanged assets/resources and eleven before/after preference hashes pass. No physical device, full natural shift or original Windows runtime comparison ran. Save/menu and audio suites were not rerun; their sources are unchanged. See [patience and scoring audit](verification/patience-scoring-0.3.11.md) for exact intervals, scoring examples and remaining seating, upgrade, overflow and critic gaps.

The four embedded fonts are decoded into valid TTF subsets and character sheets in the separate [font comparison bundle](../DinerDash-recovered-fonts/README.md). The comparison bundle contains all four decoded families; 0.3.12 integrates only the two approved faces.

## 0.3.10 waiting customer correction

The 0.3.9 standing-face change was incorrect: Lingo `integer(float)` rounds, so new guests at six hearts should smile. Restoring rounded pose selection repairs waiting and dragged guests. The earlier floor-threshold claim and its incorrect test expectations are withdrawn.

The updated tests use explicit original pose IDs for all ten satisfaction levels and fresh arrivals across all six customer graphics. The 0.3.9 APK fails 30 of 148 regression checks; the corrected APK passes all four relevant installed suites, totaling 687 checks. All six before/after arrival renders and a natural level 1-1 arrival were inspected. This was an arrival check, not a full shift playthrough. No physical device or original Windows runtime was tested.

Only SpriteRenderer.java changes among production Java files; all assets/resources and music are unchanged. Package signature, ZIP integrity and installed APK byte identity pass; all eleven emulator preference files remain byte-identical. Model, save/menu and audio suites were not rerun because their sources are unchanged. See [correction evidence](verification/standing-fix-0.3.10.md) and [current verification](verification.json).

## Historical 0.3.9 gameplay and save bug fixes

This batch fixes shop crashes and exhausted-shop Continue, final-shift score inflation, cancelled/duplicate profiles, five incorrect expert goals, premature endless coffee and wrong station destinations, guest departure/missing-pose rendering (the standing satisfaction change was incorrect and is reverted in 0.3.10), cart fill/reset, Chez Flo tray labels, cancelled multi-touch actions and lost simulation time during frame stalls. Music code and all recovered assets/resources are unchanged; the music-reference comparison is paused.

All six model suites pass 40,910 intent checks, including 12,477 routes across all 65 maps with purchased endless furniture/stations. All six installed Android suites historically passed 797 checks, but the standing-face expectations were incorrect; the corrected 0.3.10 suite exposes that regression. An ordinary emulator touch run completed 1-1, pressed Continue and started playable 1-2 without a crash. The baseline fails 50/65 data checks, 39/101 installed bug checks and four isolated menu/save/profile regressions. The zero-travel campaign bot closes all 50 schedules and reaches 43 goals; it does not verify real difficulty. No physical Android device or original Windows runtime was tested.

See [the audit and remaining gaps](verification/bug-audit-0.3.9.md), [verification metadata](verification.json) and `verification/0.3.9/`. Instrumentation restored fixture saves; the separate touch run advanced the isolated emulator test save after its pre-touch backup failed. Hidden overflow-party/podium behavior, original weighted path selection, tutorial flow, font integration and later cinematics remain unfinished; later timing corrections are documented above.

## Historical 0.3.8 continuous menu and gameplay music

The 0.3.7 MP3 playback included codec padding because the export did not preserve the ediM header timing: skip 1,393 samples and retain the original sample count. Its completion callbacks also restarted/prepared clips after playback ended. New PCM WAV playback copies follow those source boundaries exactly for all 26 music clips, while all original MP3s and other media remain unchanged. A shared controller prepares the successor early and uses [Android native queued playback](https://developer.android.com/reference/android/media/MediaPlayer#setNextMediaPlayer(android.media.MediaPlayer)) with the same audio session. Menu random-two-play choices and existing gameplay ordering/wrap remain unchanged. Both players are released on stop.

Recorded emulator output reproduces interior near-silence of 608-697 ms on the menu and 646-649 ms in gameplay before the fix. New 18-second recordings of each contain no interior near-silence lasting at least 20 ms (absolute PCM amplitude at most 1 in both channels). This is recorded emulator output, not a physical speaker test or human listening assessment. The gameplay recording holds the intro open to isolate BGM from SFX. Recordings, packet timestamps and analysis are in `verification/0.3.8/`.

The installed APK passes 94 audio checks plus 36 Activity/save/menu checks. Native handoffs are tested while the UI thread is blocked for 900 ms; coverage also includes menu repeat/random change, all five restaurants, c1-c8 sequencing, the short c8 wrap, background/resume and Music/SFX settings. All 26 WAVs match exact decoded source PCM slices and are packaged uncompressed. Original media hashes/resources, gameplay and rendering Java are unchanged. Other model/sprite/animation suites were not rerun; prior evidence remains in `verification/0.3.6-verification.json`. ADB incremental installation was unreliable on this emulator, so the runner now installs without it; final installed APK bytes match the signed release. No physical Android device or Windows runtime was tested.

## Historical 0.3.7 main-menu BGM

The original `music_intro` is a text playlist, not an audio file. The old controller requested it as a sound, got null and silently left the main menu without BGM. Its recovered XMED text says `random 2`, followed by `music_h1` through `music_h6`: randomly select one clip, play it twice, then select again. These six original MP3s were already packaged. The menu controller now implements this behavior and logs asset/playback failures. The Music preference remains persistent and independent of SFX.

The 0.3.6 APK fails the new installed main-menu playback check. The final APK passes 28 audio checks with real MediaPlayer decoding and completion callbacks, plus 36 Activity/save/menu checks. Coverage includes repeats, automatic next clip, background/resume, OFF/ON, cold muted launch and gameplay/menu transitions. AudioFlinger shows an active menu track and nonzero rendered output during an ordinary launch. All six MP3s decode successfully with ffmpeg. No audible speaker recording, physical-device playback or Windows runtime comparison was performed. Test saves were restored.

Only GameAudio.java changed among production Java files. All assets/resources and gameplay/rendering Java are byte-identical to 0.3.6. Model and sprite/animation suites were not rerun for this audio-only change; their historical evidence is preserved in `verification/0.3.6-verification.json`. Current evidence is in `verification/0.3.7/`.

## Historical 0.3.6 sprite and animation audit

This batch repairs seven related rendering faults: authored Flo scale causing stretch during movement; Goddess Flo's missing 30-pixel floor registration offset, shadow, layer ordering and incorrect body clock; bar legs drawn over the counter and excessive empty-seat dividers; missing stool bonus flags and wrongly facing table-chair flags; frozen/misplaced table snack bubbles and absent bar bubbles; missing snack-station demand highlights; and an order-wheel animation running at double speed and ending early. Recovered assets/layouts/configuration and app branding are byte-identical to 0.3.5. Gameplay rules are unchanged; the engine adds only a read-only accessor for the existing bar bonus.

The 0.3.5 APK fails 163 of the initial 217 audit checks. The intermediate wheel baseline fails nine timing comparisons, with its installed APK hash verified. The final APK passes 233 audit checks plus the existing 226 guest, 80 animation/input and 36 Continue/save/menu checks: 575 installed Android checks. All four model suites were rerun and pass 35 engine, 53 mechanics, 332 fidelity and 2,989 full-game intent checks. The zero-travel bot closes all 50 schedules and reaches 43 goals; it does not certify real play difficulty. Before/after bar, Flo, Goddess, snack and bonus composites were inspected. Ordinary emulator Activity launches and touch gestures also opened the Goddess room and seated a naturally arrived party at the bar; both captures were inspected. These are short checks, not complete shift playthroughs. Evidence is in `verification/0.3.6/`.

Pixel references follow recovered controller rules on Android Canvas. No Windows runtime comparison or physical-device test was performed. Chez Flo carried-label animation naming and the one-heart mood indicator lifetime remain investigation items; reported queue cancellation, embedded font conversion and cinematic progression remain unresolved.

## Historical 0.3.5 guest sprite repair

Level 1-6 introduces the food critic at 121 seconds. All four of her original standing poses were packaged in `gfx.people.none`, but the renderer requested `gfx.people`, making her invisible in line and while dragged. The lookup now follows the original stander controller. The audit confirms all 104 standing guest variants and 441 seated-layout image references are present.

The original sitter controller snaps both body and legs to the chair. The port instead kept authored leg positions; the four-seat layout even assigns several leg placeholders to different chairs. Both layers now share the runtime chair anchor. Menus/cups draw behind bodies so they do not cover hands, the original body depth ordering is restored, and separate seated legs hide after the departure animation changes pose. Body animations retain initial scale, matching the original animation property list.

The prior 0.3.4 APK fails 208 of 221 new guest checks. The final APK passes 226 installed guest checks across six profiles, 2/4/6-seat tables and every seating offset, including all four critic queue poses and five real View drag checks in the 1-6 room. It also passes the existing 80 installed animation/input checks and 36 Continue/save/menu checks. Before/after composites and all five 1-6 View captures were inspected. The View checks use synthetic guest timing; no complete natural 1-6 playthrough, Windows runtime comparison or physical Android test was performed. Gameplay model code is unchanged and its pure model suites were not rerun. Evidence is in `verification/0.3.5/`.

## Historical 0.3.4 app branding

The application name is exactly **Diner Dash**. Its launcher icon now uses the original wordmark from the recovered title artwork, with native Android adaptive/round icon support and a legacy fallback. The package and signing certificate are unchanged, so the APK updates the existing installation and retains its saves.

The final signed APK was installed on the emulator. The launcher label and icon were inspected, and packaged icon pixels match the resource. All 1,960 media hashes, 62 uncompressed MP3 files, ZIP integrity, version code 7 and the existing signer were verified. Every Java source hash matches 0.3.3. Gameplay and animation tests were not rerun for this resource/metadata change; prior evidence remains in `verification/0.3.3-verification.json`. No physical device was tested. Current branding captures and checks are in `verification/0.3.4/`.

## Historical 0.3.3 chef placement

The third frying frame contained an authored scale of 0.7333 by 0.7037. The original chef controller animates only position and image; its initial unit scale stays fixed. The port applied the later frame's scale, shrinking the chef and leaving a gap above the kitchen ledge. The renderer now retains the initial transform while updating the two animated properties. Original assets and gameplay rules are unchanged.

The previous 0.3.2 APK fails the new third-frame placement regression. The final 0.3.3 APK passes 45 cooking-frame placement checks across all five restaurants, 80 installed animation/input checks in total and 36 installed Activity/save/menu checks. All five room crops were inspected. Evidence and baseline failure are in `verification/0.3.3/`. Existing mechanics model checks were not rerun for this renderer-only change; their prior results remain in `verification/0.3.2-verification.json`. No Windows runtime or physical device was tested.

The reported queue stall remains unresolved. Valid order/dishes/wheel/bus sequences complete under installed View and ordinary emulator touch checks; the user confirms disappearing marks and a free hand, indicating cancellation rather than a retained stalled queue. The exact failed destination still needs identification. Original invalid-action cancellation is retained. Embedded font conversion and restaurant/transformation/ending story flow remain unfinished.

## Historical 0.3.2 mechanics repairs

Bus disposal now accepts unwanted drinks, snacks and food; returned meals recook. Full-handed Flo can deliver coffee at an order-ready table. Held guests retain their last heart until release/cancel/seating; selection alone does not protect them. Occupied dish clearing follows the original scoring and shared empty-payload chain identity. Kitchen completion and empty-tray reuse follow separate FIFO queues, with immediate overflow refill and dead-order cleanup.

The room uses its recovered eighteen-column grid, seafood left blockage and bar footprint. Bar service midpoints round correctly, and all meal displays share dynamically assigned A-H letters. Endless tips defer upgrade eligibility until a scored action. Career saves now preserve star capacity separately from lives, including restaurant changes; New Game resets capacity.

The 0.3.2 APK passed 53 mechanics, 35 engine, 332 fidelity and 2,989 full-game checks, 35 installed Canvas/input checks and 36 installed Activity/save/menu checks. A fresh real emulator touch walkthrough completes 1-1, presses Continue and starts playable 1-2 without a fatal exception. Five targeted captures were inspected. All 50 schedules close; the zero-travel bot reaches 43/50 goals and does not certify difficulty. Evidence is in `verification/0.3.2/`; previous evidence keeps its original APK hash.

The updated audit is `verification/mechanics-audit.md`; the original deep audit is preserved as `verification/mechanics-audit-0.3.1.md`. Twelve of fifteen formerly differing probe observations now match. Three remain: seated and coffee timer ownership, plus quick-seating mood (requires original-runtime confirmation). Weighted A*, tutorial coaching, long-frame timing and the previous source ambiguities also remain. No Windows execution, physical-device play, audible-speaker check or full campaign human playthrough was performed.

## Historical 0.3.1 transition and mechanics audit

Continue after level 1-1 could crash because the chef retained its previous shift's fade origin and animation timestamp. Both reset when a new shift starts. Flo now faces the screen whenever she stops, including carrying poses after left/right approaches; walking remains directional.

This build passes 35 engine, 332 fidelity and 2,989 full-game checks, 28 installed Canvas animation checks, and 32 installed Activity/save/menu checks. Synthetic result fixtures exercise winning transitions 1-1 to 1-2, 1-10 to 2-1 and 5-9 to 5-10, plus retrying 1-5. A real emulator touch walkthrough completes 1-1, presses Continue and starts playable 1-2 without a fatal exception. Historical logs and three inspected screenshots are in `verification/0.3.1/`. Previous captures and review verdicts retain their original 0.3.0 APK identity; they have not been relabeled as new-build evidence. This update has no new independent full visual review or physical-device check.

The 0.3.1 deep audit is preserved in `verification/mechanics-audit-0.3.1.md`. Its runnable Java probes expose 15 source-contract observations that differ, plus eight matching controls. Bus disposal/food return, coffee fallback, held-party protection, occupied dish scoring, ready-food FIFO, timer ownership, navigation occupancy, bar identities, career star capacity and tutorial progression still need work. This build fixes the two newly reported defects; those broader mechanics differences remain unresolved.

## Changes from 0.2.0

The original 800×600 title screen, bitmap menu controls, career/endless maps, help pages, comics, pause and transition panels replace the previous Android dialog shell. The playfield retains its recovered geometry, waiting line, score panel, money jar, star meter, level notepad, clock/fork and pause button. The complete composition fits proportionally inside the available screen.

Drag any visible waiting party onto a compatible table. The held guest determines chair alignment; the table previews the party while held. Releasing outside a valid table returns the party to the line. The recovered active queue enables dragging for every visible party; selecting later parties follows that code. The earlier first-party-only claim was incorrect. Order-wheel, ready-food trays, bus cart, coffee, podium and snack stations have independent touch regions. Dropping tickets spins the wheel; collecting one numbered tray leaves other meals on the counter.

Coffee is absent in career shifts 1-1 through 1-4 and first appears in shift 1-5. Its cup and highlight follow readiness; pickup removes the ready cup and starts its refresh timer. Dynamic stations and the chef are no longer baked into the background cache.

Flo’s carrying animation now resolves the actual directional frame names, while her legs continue their walking cycle. Her stopped pose faces the player after approaching from any direction. Empty-handed Flo enters the recovered yawn, dusting or stretching sequences after a 2–6 second pause; movement or an item cancels idle. The chef advances chop/fry frames during cooking, with the recovered fade-in/out timing. Food payloads use their own original layouts rather than the counter tray layout. Cast lookup uses the first named member, preventing the original duplicate table-number name from displaying 11 for table 1.

Waiting guests use the rounded original mood bands, so their starting satisfaction draws the smiling sprite. Seated guests react to mood increases and decreases using the original happy/angry bodies and heart/annoyance frames. Table collision footprints now start at the first chair and cover the tabletop and right chair; the clear aisle is no longer shifted into the table.

Options use the original labels and ON/OFF artwork without native overprint. Pausing keeps the restaurant behind the chalkboard and restores the recovered pause text. The HUD uses the recovered cyan goal, magenta expert target and white score. Career stars require the recovered expert score, rather than mere completion. Each player now keeps separate career progress; the previous shared save migrates to the selected player. A final lost life ends the run at zero. Four global top-ten tables retain player names for career and each endless difficulty, matching the recovered score categories.

## Playing

Create/select a player through the original title controls, then choose Career or Endless Shift. Drag guests onto tables and match their colors to chairs. Tap a ready table to take its order, tap the wheel to deposit tickets, tap a numbered cooked meal and then its matching table. Give the bill, clear the dishes and carry them to the bus cart. Flo carries two items, or four in the Goddess restaurant; destinations can be queued.

Coffee boosts seated guests’ mood. The podium boosts waiting guests after charging. Serve the requested snack. Repeated actions across distinct tables build scoring chains. Endless goals earn upgrades; the original bitmap shop presents the available choices. System Back pauses an active shift or returns from a menu. Player progress and global settings/high scores are saved locally; an unfinished shift restarts after activity destruction.

## Verification and remaining differences

The delivered package’s logs and captures are under `verification/`; `verification.json` distinguishes model, Canvas and emulator touch checks. The 0.3.0 source passed 35 engine, 329 fidelity and 2,989 full-game assertions, including all 308 career table-to-wheel routes without crossing furniture. All 50 schedules close without stuck parties. A zero-travel service bot reaches 46/50 goals; it does not prove human balance. The 0.3.0 installed APK passed 27 Canvas/view-input checks for carrying, idle cancellation, chef animation, cast lookup, guest mood sprites and second-party selection, plus 18 synthetic Activity save/menu checks. The latter verify migration, player isolation, normal/expert markers, final-life/new-run transitions, score categories and original ON/OFF alpha; the emulator saves are restored afterward. These fixtures do not prove naturally played completion. All 28 historical 0.3.0 real emulator gesture checkpoints passed across phone and simulated tablet layouts: seating preview/cancel/commit, ticket deposit, individual food pickup/delivery, coffee prepare/pickup/refresh and selecting/seating the second waiting party.

The earlier 0.2.0 tutorial and visual-review evidence is historical and does not certify this rebuild. No physical Android device or audible speaker playback was tested in this session. The original 58 Windows files remain unchanged; packaged media hashes, APK ZIP integrity and the preserved signer were verified.

The final constrained visual review resolves the reported controls, receipt readability/bounds and design-record corrections. Its disposition remains **fix** because the original-font portion is unresolved; it does not certify the whole game. The reviewer inspected 37 refreshed captures within those seven corrections; the later six guest captures/four touch checks were verified separately by the parent. Registered reviewer/documenter roles were unavailable, so degraded substitutes were used. The fresh documenter wrote both design files before hitting an account limit; the parent completed JSON, Ruby Psych YAML, reference and structure validation. See `verification/final-verdict.md` and `verification/design-record-validation.json`.

**This is not a verified 1:1 port.** No executable Windows runtime comparison has been performed. Four embedded fonts are now decoded into validated TTF subsets in the separate font comparison bundle. The historical payloads in `verification/recovered-fonts` had an extraction-offset error and are marked accordingly. Komika Axis and Mr.B are integrated in 0.3.12; Daniel-family fields keep their Android fallback at the user's request. Original-runtime font-run styling and rasterization comparison remain pending. Weighted A*, full Director timelines/tutorial coaching, construction effects, complete cinematic/ending progression and exact music sequencing still differ or remain incomplete. The high-score submission skips the original name-confirmation transition, and final career completion exits through the result/high-score path rather than the complete ending comic. Save storage also retains a zero-life run until New Game, whereas the original saves its resume point on level advancement. Food variety uses a deterministic selection rather than the original random selection. The aggregate Canvas description does not provide complete screen-reader control navigation. An ADB-only `qa_level` launch extra opens a shift for verification; it is not exposed as a game-menu practice control.

## Build and tests

Run `python3 build.py` with SDK platform/build-tools 36 and Java 21. Set `ANDROID_HOME` and `JAVA_HOME` when necessary. The build uses standard SDK tools directly, with no Gradle or game-engine dependency. The local build directory is `../../work/android-build`; preserve its `prototype.keystore` to sign updates with the existing certificate. Building elsewhere with a new key requires uninstalling the earlier app. This is a development build, not a Play Store release.

Compile `GameEngine.java`, `LevelData.java`, `tests/GameEngineTest.java`, `tests/FullGameTest.java`, `tests/FidelityTest.java` and `tests/MechanicsTest.java` with a JDK, then run their package-qualified test classes. Android-only animation and synthetic save/menu checks are separate: after building, run `python3 tests/run_animation_test.py` against the emulator selected by `ANDROID_SERIAL` (default `emulator-5554`). It installs a small separate test APK and fails if its instrumentation does not report success. `tools/generate_full_data.py` regenerates imported data. Media recovery tools and attribution are in `tools/asset-recovery/`; recovered Lingo and Ghidra analysis remain in `../DinerDash-recovered.zip`.
