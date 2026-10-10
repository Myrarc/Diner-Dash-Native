# Cake Mania 0.1.9

The slightly translucent oven cake was caused by the customer order bubble leaving the shared sprite Paint at alpha 235. UI panels now restore the previous paint color and alpha. Original cake textures and bubble transparency are preserved.

APK SHA-256: `5d5eb08ac342b77c8de3719fdd177fccc4d46a813f0d58fb4c120377b99cdc65`.

Verified on the installed API 30 emulator: 28,154 opacity/render assertions, eight oven cake shapes, carried cake/Jill pixels, existing oven/froster/target/occlusion checks and actual menu/bake/pickup/frost/disposal input for all four starting shape/color pairs. Baseline 0.1.8 returns alpha 235 on an original alpha-255 texel. All 838 APK assets and 684 prior archived verification files are unchanged. Career preference bytes and display settings were restored, and the owned emulator and test package were removed.

Full career/tutorial/menu regressions, Windows runtime and physical Android comparison were not repeated. See `report.json` and `review.md` for evidence boundaries.
