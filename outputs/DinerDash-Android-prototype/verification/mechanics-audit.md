# Gameplay mechanics audit — 0.3.2

Updated on 2026-10-08. This build repairs the service and progression contracts listed below. It retains the 0.3.1 Continue/chef-clock fix and front-facing stopped Flo. Fonts and general artwork are outside this mechanics batch.

## Evidence boundary

The expected contracts come from recovered active Lingo handlers. Tests execute the Java model and installed Android code; they do not execute the Windows game. This is not a verified 1:1 port. No physical Android device, audible speaker playback or full human campaign/endless playthrough was tested.

The previous deep audit is preserved as [0.3.1 audit](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/mechanics-audit-0.3.1.md>). Of its 15 differing probe observations, 12 now match their source contracts; three remain different. The eight previous matching controls still match. This count is a small probe set, not a complete list of remaining work or 12 independent systems. See [current probe output](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/0.3.2/mechanics-probes.tsv>) and [runnable probe](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/0.3.2/MechanicsAuditProbe.java>).

## Repairs in this build

| System | Behavior in 0.3.2 |
| --- | --- |
| Bus cart and returned food | Discards dishes, drinks, snacks and food; retains tickets. Food recooks for a still-seated party, and duplicate tickets do not restart a cooking timer. |
| Coffee at READY tables | With full hands, Flo delivers carried coffee and leaves the order pending. A free hand still gives ticket pickup priority. |
| Held guests | The actual touch drag clamps waiting mood to one heart. Release, cancel, seating and Activity deactivation remove protection. Merely selecting a party grants no immunity. |
| Dish scoring | Clearing while guests pay or leave awards no empty-table bonus. The original shared VOID payload identity contributes once to the dish chain; empty dirty tables retain normal chained points. |
| Kitchen queues | Completed orders wait FIFO by cooking completion, with ticket order breaking equal deadlines. A freed tray refills immediately. Empty trays retain their own FIFO reuse order. Dead customers' queued meals are removed, and overflow orders stop the chef's cooking timer. |
| Room occupancy | Restores the eighteen-column grid, the seafood restaurant's blocked left strip, and the bar's three-column/seven-row footprint. Exact weighted A* and original tie breaking remain unfinished. |
| Bar service and labels | Rounds the service midpoint. Assigns A-H in order-taking order and returns delivered/abandoned letters behind unused letters. Table, tray, carried food and accessible payload description share the same label. |
| Endless score events | Tips credit the score without immediately granting an upgrade. A subsequent scored action checks the strict goal threshold; crossing below the current goal retracts one unspent upgrade as in the recovered progress handler. |
| Career star capacity | Saves earned capacity separately from remaining lives. Continue and restaurant changes retain capacity; New Game resets it. Older saves fall back to the capacity inferable from remaining lives and the level default. Previously lost empty capacity cannot be recovered from a save that never stored it. |

## Source and implementation references

- Bus and food return: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 45 - busspot.ls:62>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:258>).
- READY coffee fallback: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 28 - sgstate.ready.ls:48>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:267>).
- Held-party clamp: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 24 - sitterGroup.ls:138>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:228>).
- Occupied dish clearing: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 32 - sgstate.scoring.ls:39>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:263>).
- Kitchen overflow and tray reuse: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 42 - kitchen.ls:147>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:251>).
- Grid occupancy: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 14 - grid_manager.ls:20>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:283>).
- Bar labels and midpoint: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 61 - bar_manager.ls:185>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:159>).
- Endless tip/action distinction: [recovered handler](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:225>), [Java implementation](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:240>).
- Career capacity: [original advancement](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:479>), [Android save and transition](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/MainActivity.java:38>).

## Verification

- 53 mechanics intent checks, 35 general engine assertions, 332 fidelity checks and 2,989 full-game checks passed. All 50 schedules close, including 1,067 parties; 308 table-to-wheel routes remain clear of furniture.
- The zero-travel bot now reaches 43/50 goals. Correct occupied-dish scoring lowers scores relative to the previous 46/50 result. Its policy clears dishes before guests leave and does not optimize original scoring or account for travel; it is neither a balanced-play benchmark nor proof of original difficulty.
- 35 installed Canvas/input checks passed, including real View touch-down/cancel patience protection, chef clock resets and bar-letter asset/render fixtures.
- 36 installed Activity/save/menu checks passed. Synthetic cooked-result fixtures cover 1-1 → 1-2, 1-10 → 2-1, 5-9 → 5-10 and retrying 1-5. Winning fixtures carry five-star capacity with four lives and verify preservation; restaurant changes refill lives while retaining capacity. Test saves are restored afterward.
- A separate real emulator touch walkthrough completes 1-1, presses Continue and enters playable 1-2 without a fatal exception. This verifies the installed final APK, rather than forcing a result fixture.
- Five captures were inspected: three from the real touch transition and two from synthetic installed Canvas bar-label fixtures. This was targeted verification, with no repeated independent full visual review.
- All 1,960 packaged media hashes match the recovered originals. All 62 MP3 files remain uncompressed; APK CRC, version and the existing signing certificate are verified.

Logs and captures: [verification directory](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/0.3.2>); [touch checkpoints](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/0.3.2/continue-touch-checkpoints.json>).

## Remaining mechanics work

1. **Timer ownership:** seated patience uses the global Endless ramp, and coffee refresh uses the latest global multiplier. Both differ from the recovered object's retained timing. These are the two remaining timing probes. Upgrade-property effects and frame callback ordering also need careful comparison.
2. **Quick-seating happiness:** the port adds three hearts on a fast seat, while the recovered drag path does not show that bonus. A separate unused seat handler exists, so verify the running original before changing this balance rule. This is the third remaining probe.
3. **Pathfinding:** occupancy is corrected, but BFS still differs from the original weighted A*, including tie breaking and route choice.
4. **Tutorial:** the original 24 state-dependent steps, checked every 500 ms, and its closing condition remain missing.
5. **Long frames:** the View still discards elapsed time beyond 100 ms. Scheduler boundaries and callback order remain unverified.
6. **Source ambiguities:** weighted random range boundaries, mime patience effects, critic reward thresholds and preselected arrival delays remain as described in the preserved deep audit. Descriptions alone do not resolve conflicts with reachable source.

Full cinematic/ending progression, construction effects, food variety and exact music sequencing are also incomplete. The repair list above does not claim that presentation parity follows from importing assets.

## Reproduction

Compile `GameEngine.java`, `LevelData.java` and the four `tests/*Test.java` model classes excluding Android-only instrumentation, then run `MechanicsTest`, `GameEngineTest`, `FidelityTest` and `FullGameTest` under `local.dinerdash.prototype`. Build with `python3 build.py`; run `python3 tests/run_animation_test.py` against an emulator. The source archive includes current tests and evidence. The compact mechanics probe intentionally reports three outstanding differences and is not a passing parity certification.
