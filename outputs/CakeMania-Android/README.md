# Cake Mania for Android — 0.1.9

An installable native Java/Canvas translation of the supplied Windows game. Install `../CakeMania-Android-0.1.9.apk` over the previous build to retain the saved career. The app is **Cake Mania**, package `local.cakemania`, requires Android 6.0 or later, and runs offline in landscape. Its saves are separate from Diner Dash.

This checkpoint fixes slightly translucent oven cakes and other sprites after customer orders appear. The order bubble previously left the shared bitmap paint at 235/255 opacity. UI panels now restore that paint's original color and alpha after drawing. Original cake art, its edge transparency and the bubble's intended opacity are preserved. The port remains an unfinished translation of selected native code.

## Play

1. Choose **Play → Start New Game** and continue through the opening comics into the practice lesson. Choose Month opens the map separately.
2. Complete the recovered practice lesson for a new profile, read the January intro, and choose Let's Play. Tap a customer to give a menu; their order appears after reading.
3. Tap the required shape pictured on the oven. When baking finishes, tap the oven body to pick up the base.
4. Tap the required color pictured on a froster. This places and processes a carried cake; an empty tray body can also place it first. After production finishes, tap the tray body to pick up. Use the pictured topper button on a purchased decorator when required.
5. Deliver the matching cake and collect the customer's money after their happy state. Jill executes numbered jobs in order. Early pickup attempts do not automatically wait for production; tap again when ready.
6. Meet the original monthly cash goal, buy equipment, and Continue. **Continue Career** reloads the saved month and purchases.

Two tiers assemble on a machine tray: place a frosted cake, bring another plain base to that tray, then choose the top tier's frosting. A decorator rejects an unfrosted cake. Cupcakes restore patience; the upgraded microwave holds four and refills after the last is taken. The TV button starts a one-second noise interval; clicks during noise choose a program, while clicks during the broadcast are ignored. Preferred programs give a one-time heart gain. The original bottom-left **Menu** opens pause and freezes time.

## Included and remaining work

The app imports 838 original media assets, including nine decoded bitmap fonts, customer/Jill animation sheets, sound effects, six music files, opening comics and the final illustration. It loads all four bakery configurations and 48 career definitions with their goals, durations, customer profiles, schedules, path graphs, machine prices and upgrades. Android uses losslessly decoded PCM copies of music streams; original media remains intact.

Menus, results, shopping, map selection, separate saved profiles, best earnings, sound options and pause are playable. In the shop, tap equipment in the kitchen to preview its next upgrade, then Buy; Finish starts the next month. Uncollected cash holds a customer position even after the customer body disappears. Collecting it allows the following customers to advance after the departure effect finishes. The map center information/preview panel, exact machine/menu/result/game-over animation curves, native save-slot/resume behavior, free-floor/corner movement, starting cookie stock and display-source consumption remain unresolved. The supplied archives do not contain the referenced endless level files or intermediate bakery comic images; these features have not been fabricated. Saves resume at the beginning of a month after process termination. An unfinished practice lesson restarts from its beginning.

`FIDELITY.md` records translated rules, native addresses, tests and remaining gaps. `PRODUCT.md` records the user's original-game authority. Successful tests of this app do not establish whole-game Windows equivalence.

## Verification

The final 0.1.9 APK is identified by `build-summary.json` and `verification/fixes-0.1.9/report.json`. CakeOpacityProbe reproduces alpha 235 on 0.1.8 and checks opaque source pixels, all eight oven cake shapes, repeated frames, carried cake/Jill pixels and UI panel transparency on the corrected APK. The existing oven/froster geometry probe and actual Android shape/color taps are also checked. Career preferences and emulator display settings are restored. Menu, tutorial, full career, Windows and physical-device comparisons were not repeated for this change.

The historical 0.1.8 APK is identified by `build-summary.json` and `verification/fixes-0.1.8/report.json`. Menu geometry and recovered row pixels are checked at 800x600, 1440x1080 and 2280x1080. Real emulator input checks the main menu and Play menu, the three comic Continue buttons, direct lesson entry, January intro and Let's Play. Later bakery stories retain their separate map route. Month text rendering, full practice lessons and the focused host checks are recorded in the versioned report. Earlier releases remain historical evidence for their own APKs.

The historical 0.1.6 APK is identified by its versioned package metadata and `verification/fixes-0.1.6/report.json`. Five Android probes pass, including 27,086 customer frame/idle/hover/overlap/bubble/left-heart checks, 615 customer renders, 64 Jill cases, 3,948 HUD/clock/wheel/arrow/cash checks, and 35 real Activity flow checks. The mixed-customer Activity tap selects Cupid independently, and paused gameplay freezes his hover. All 41 profiles complete two idle cycles; every authored sequence entry maps to the native physical sprite row. Heart pixels match native anchors for all 20 queue positions across four bakeries, with zero through five hearts and a fixed position during hovering. Seven host suites also pass against the final production classes. Original preference bytes and display settings are restored after testing.

Seven host suites cover customer lifecycle and queue retargeting, native mechanics, sprite rules, tutorial flow, profile saves, separate accounting, and automated service across all 48 months. Later-month fixtures use fully upgraded equipment; they do not establish affordable progression or human difficulty.

Historical 0.1.5 verification applies to its own APK: Android probes check original HUD/clock/wheel/arrow/cash pixels and hit targets, oven/frosting geometry, counter occlusion, the bitmap cache, 615 customer renders, 64 Jill cases and 31 Activity career/result/shop checks. Real input checks cover the bottom Menu, cash blocking and queue advancement, full January service, result/shop/February transitions, purchased machinery and both tutorials. The versioned report binds the evidence to the tested APK. Profile preferences and emulator display settings are restored after verification. Earlier versioned reports remain historical evidence for their own APKs.

Physical Android hardware, other Android versions and the Windows runtime have not been compared. The emulator ran without audible output; music flags and sample checks do not prove listening quality or seamless loops. Historical 0.1.0/0.1.1 reports remain evidence for their own APK hashes.

## Build and tests

The build uses Android SDK platform/build-tools 36 and JDK 21, without Gradle or a game engine. Override `ANDROID_HOME` and `JAVA_HOME` if needed.

```sh
python3 build.py
mkdir -p /tmp/cake-mania-tests
javac -d /tmp/cake-mania-tests src/local/cakemania/GameData.java src/local/cakemania/GameEngine.java tests/GameEngineTest.java
java -cp /tmp/cake-mania-tests local.cakemania.GameEngineTest assets
python3 tools/verify_assets.py
# With the APK installed on a disposable Android emulator:
python3 tests/menu_touch.py verification/direct-machines/normal-launch
python3 tests/machine_touch.py
python3 tests/tutorial_touch.py
python3 tools/run_visual_probe.py
```

The gameplay screenshot check requires Python Pillow. It refuses to reset career fixtures on a non-emulator device. `qa_level` only enters a month and exposes snapshots; game actions use actual Android input. The menu test uses normal launcher entry. The APK is debuggable and signed with the existing local development key, not a Play Store release. The source archive excludes that private key.

`tools/prepare_assets.py` preserves original media and adapts TinyXML syntax for Android XML parsing. Font coverage becomes alpha in memory when drawn. `asset-preparation.json` records imported hashes. Recovery provenance is in the sibling `CakeMania-recovered` directory; selected native routines and constants are also copied into `verification/native-evidence/`.
