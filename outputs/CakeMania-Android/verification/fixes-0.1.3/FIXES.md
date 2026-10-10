# Cake Mania 0.1.3 correction checkpoint

This release translates the confirmed audit differences below. It is not verified as a complete 1:1 port.

APK SHA-256: `aa141dfcbaa4826e5713236f58f50421b17ce45616b83beacddd51554feb17b3`

Six host suites, Android bitmap/render probes, 144 month text screens and 22 Activity accounting/persistence checks passed. The real-touch reports cover menus/profiles/options, both scripted practice lessons, January service and purchased machine/shelf controls. All 838 asset bytes match the APK; 51 decoded PCM files match the original samples.

| Audit item | Status | Change and remaining boundary |
| --- | --- | --- |
| F01: Jill shoe overlay replaces her body | fixed | Body and shoe overlays render separately.  |
| F02: Lives and terminal game-over flow missing | partial | Four lives, terminal game-over, once-only bank/points/unlock accounting and persistence. Exact native failed-save order, restart semantics and game-over animation remain untraced. |
| F03: Display-case impulse order selection missing | partial | Native display impulse selection copies and reserves an eligible candidate, including duplicate rejection. Native consumption of the source cake after copying remains unknown. |
| F04: Scripted tutorial flow missing | partial | Both supplied scripted practice lessons run in their original room outside the career ledger, preserving the native input-driven gates. Order selection-index translation is inferred from authored controls; incomplete practice restarts and native mid-lesson resume is unresolved. Like the native code, a gate can advance on a failed early click; the passing player path waits for visible product readiness. |
| F05: Special-customer heart events ignored | fixed | Authored start, served and periodic heart events broadcast by source GUID.  |
| F06: Order selection omits missing-candidate weights | fixed | Missing-candidate weights use remaining percentage; explicit zero weights and native tail selection are preserved.  |
| F07: Order generation happens before menu activation | fixed | Customer order generation begins on menu reading activation.  |
| F08: Cupcake refill omits native transition phase | partial | Empty microwave starts refill on the following tick, with strict-negative timer and door phases. Initial enabled stock of four remains unproven against the native constructor. |
| F09: Cookie-eating and positive TV visual states missing | fixed | Independent normal/menu/happy/bored/eating state transitions and temporary sequence endings.  |
| F10: Customer timing ranges and sequence endings ignored | fixed | All authored timing ranges, default interval, strict one-frame advancement and sequence endings.  |
| F11: Jill idle/frame direction/rates differ | fixed | Asymmetric direction sectors, reverse phase/truncation, two-second idle hold and paused animation.  |
| F12: Jill perspective, carry anchors and render flags differ | partial | Native perspective, cake scale, body/shoe offsets and cake behind/front render flags. Exact native child carry anchors, cake composition and Windows FPU/pixel rounding remain unresolved. |
| F13: Oven intermediate visual phases missing | partial | Oven intermediate production/door/pickup visual phases are rendered. Exact native animation positioning and timing have not been compared with Windows execution. |
| F14: FormShelf hit routing and independent cookie slots missing | fixed | Direct FormShelf selection, independent cookie slots and display shelf routing outside the parent body.  |
| F15: Named profiles and native save-slot flow missing | partial | Up to six named profiles isolate progression, purchases, lives and practice completion; audio settings are shared. Native record layout, save-slot UI and mid-month persistence remain unresolved. |
| F16: Native map/comic/results/HUD flow simplified | partial | Authored map, result data and HUD labels are translated; intro/result fonts use recovered startup scales, integer metrics and screen spacing, ignoring obsolete XML font/size attributes. Available comics are retained. Other screen font scaling/placement, exact menu/result animations, Windows font resampling, star fan/native clock and missing intermediate comics remain open. |
| F17: Endless mode and original volume controls missing | partial | Music and SFX levels have independent live sliders and persisted settings. Endless mode is blocked by missing supplied endless level/customer files. |
| F18: Native machine and goal sound events missing | fixed | Translated oven/cookie/goal/closing sound events and one-shot boundaries. Audible mix and seamless loops have not been listened to or compared. |
| F19: Purchased TV position retains stale base geometry | fixed | Purchased station definitions refresh active geometry, including TV position.  |
| F20: Equivalent repeated sprite frames use different cache keys | fixed | Frame indices normalize before cache keys; loops and reverse frames reuse the same Bitmap.  |

See `report.json` and linked test reports for hash-bound evidence. The original 0.1.2 audit is preserved.

No Windows execution, physical Android run, audible loop comparison, affordable full-career or human-difficulty validation was performed. Referenced endless data and intermediate comic resources are absent from the supplied archives.
