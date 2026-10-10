# Audio, assets, and local implementation audit

## APK and assets

The audit verifies both versioned/canonical 0.1.2 APK hashes, all six production Java hashes against build-summary.json, classes.dex against the retained compiler output, APK signature, and every current local asset against its packaged bytes. `apk-binding.json` records the result. These checks establish which implementation was examined; they do not execute native Windows code.

The previous package asset report checked 838 imported files, 608 images, 205 customer animation sequences, and 51 decoded PCM clips against originals. This audit rechecks APK byte binding; it does not repeat the original audio decoder comparison. Nine font resource definitions are recovered; recovering a font does not make the prototype's text layout/sizing match the native UI.

Original unused screen declarations reference unresolved IMAGE_COMICS_2/3/4, IMAGE_CREDITS_SCREEN, IMAGE_MAPSCREEN_BUTTON_DIS, and IMAGE_NONE. These remain explicit asset/loader gaps; original files are preserved. Do not invent replacements and label them recovered.

## Missing sound event timing

Failed giant resource binder `004293b0` has retained assembly. A conservative parser links literal resource pushes to following global stores; it is partial extraction, not a review of all branches.

| Native global | Resource | Use |
| --- | --- | --- |
| 005b9bfc | SOUND_COOKIE_START | Refill start in recovered 004348d0 |
| 005b9c48 | SOUND_COOKIE_READY | Production expiry in recovered 004348d0 |
| 005b9ec0 | SOUND_CAKEOVEN_DOOROPEN | New-cake phase in 00436d50 |
| 005b97f0 | SOUND_BAKERGOALREACHED | Pending goal event in 0044d8f0 |
| 005b98bc | SOUND_CLOSED | Time/closing draw branch in 0044bbe0 |

Android emits COOKIE_READY only at its instant refill completion, has no COOKIE_START or oven-door phase event, and has no goal-reached/closing sound dispatch. Clips are packaged; trigger/state timing is missing. Exact pending goal/closing timing and sound mixing still require more tracing. Cookie door-open clip identity was also recovered, but its full invocation path has not been established.

Main menu music uses the original mainmenu.ogg-derived PCM path; per-month music comes from the original definitions. Android playback flags were checked in the existing 0.1.2 emulator report. The emulator was launched without audio output; neither these flags nor byte-correct PCM prove audible volume, seamless loops or Windows mixing behavior. Native has continuous music/SFX volume preferences and sliders; Android only has toggles and a fixed effect volume.

## Geometry retained before upgrade merge

`GameEngine.Station` captures x/y/w/h in final fields before applying upgrade definitions. Most supplied machine geometry is unchanged. The Level1 purchased TV explicitly changes x_global from145 to140, while the renderer and controls still use Station.x=145 after def.x_global becomes140. The fifth host probe demonstrates that internal configuration/render divergence. Changing associated path points is already consumed from the merged def, so those changes are not the same bug.

## Cache and feedback

`AssetStore.frame()` builds its cache key with the unnormalized frame number, then applies modulo for cropping. For a ten-frame image, requests0 and10 crop the same pixels but create different cache entries. Menu/environment animation callers pass increasing frame numbers, causing repeated allocation/cache churn across loops. LRU limits bound memory; this is not an unbounded leak. Allocation rate and device performance have not been profiled.

MainActivity's action() plays SELECT immediately, and game enqueue() queues another SELECT for the frame loop. The two caller paths can therefore play the same clip twice for one gameplay tap. This local duplication is established by source paths; its audible impact and original feedback policy were not measured. It is recorded as secondary local work, not proof of native music-loop behavior.
