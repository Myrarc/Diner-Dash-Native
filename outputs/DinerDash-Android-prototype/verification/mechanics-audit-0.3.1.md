# Gameplay mechanics audit — 0.3.1

Audited on 2026-10-08. This compares the recovered active Lingo handlers and active ext/conf data with the delivered Java implementation. Fonts and general artwork are outside this audit.

The 1-1 shift was also completed through real emulator touch input, followed by a real Continue tap and playable 1-2. The three screenshots were inspected. [Touch checkpoints](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/0.3.1/continue-touch-checkpoints.json>).

## Evidence boundary

The Java probes execute the current Android model. Their expected results are contracts traced from recovered source, not recordings or execution of the Windows game. A Director/Windows runtime comparison remains necessary for decompiler ambiguities, legacy numeric behavior, callback ordering and apparent bugs in the original. No physical Android device was connected.

The compact probes expose **15 differing observations across the systems below**, plus eight matching controls. This is a count of observations, not 15 independent bugs. The full source and output are [MechanicsAuditProbe.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/MechanicsAuditProbe.java>) and [mechanics-probes.tsv](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/mechanics-probes.tsv>).

## Confirmed Android fixes in this build

- Continue after cooking could reuse the chef's fade origin and animation timestamp after the next shift reset its clock. A deterministic installed-Canvas regression reproduced `ArrayIndexOutOfBoundsException: length=10; index=-1` on 0.3.0. Resetting both values prevents negative frame selection. [Before log](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/verification/continue-crash-before.log>).
- Stopped Flo now faces the screen after any approach, with one or two carried items. Walking still uses directional frames. The original reachDest also assigns down when it arrives on the destination tile; the earlier port kept the last walking direction.
- Installed checks cover winning transitions 1-1 to 1-2, 1-10 to 2-1, and 5-9 to 5-10, plus retrying 1-5 after cooking. They use synthetic result fixtures and MenuView DOWN/UP events, rather than a complete human playthrough.

## Ranked differences

### 1. P1 — Bus cart does not free all supported items

Original accepts dishes, drinks, snacks and food. Returned food is cooked again for a still-seated party. Android accepts only dishes. A mixed four-item payload retains three items, and returned food gets no new cooking timer. This removes the original way to recover from a wrong pickup.

Evidence: [ParentScript 45 - busspot](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 45 - busspot.ls:62>); [ParentScript 42 - kitchen](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 42 - kitchen.ls:185>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:238>).

### 2. P1 — Coffee fallback at an order-ready table

Original first tries to take the order. When Flo has no free hand but carries coffee, it delivers coffee instead. Android returns immediately with hands full. Probe: party stays at mood 4 instead of rising to 7.

Evidence: [ParentScript 28 - sgstate.ready](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 28 - sgstate.ready.ls:48>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:247>).

### 3. P1 — A held party can disappear

Original marks a dragged party as picked up and clamps mood to at least one while held. Android marks selection only; its patience tick can abandon that party during the drag. Probe: one-heart held party becomes GONE instead of remaining WAITING.

Evidence: [ParentScript 7 - waitgroup_drag](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 7 - waitgroup_drag.ls:67>); [ParentScript 24 - sitterGroup](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 24 - sitterGroup.ls:138>); [GameView.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameView.java:81>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:187>).

### 4. P1 — Dish-clearing score differs by occupancy

Original SCORING/LEAVING states call pickUp(dishes) without the table argument, so the waiter does not award the table action bonus on that path. After the party leaves, table.doFloAction supplies the table and scores. Android awards 40 points, plus its chain multiplier, even while the party remains. This makes early clearing more profitable and changes chain identity handling.

Evidence: [ParentScript 32 - sgstate.scoring](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 32 - sgstate.scoring.ls:39>); [ParentScript 33 - sgstate.leaving](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 33 - sgstate.leaving.ls:42>); [ParentScript 13 - table](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 13 - table.ls:324>); [ParentScript 50 - waiter](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 50 - waiter.ls:252>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:243>).

### 5. P1 — Ready-food overflow loses completion order

Original queues completed orders FIFO when the counter is full; freeing a spot fills it immediately from that queue. Android leaves their cooking timestamps active and scans parties in arrival order on the next tick. Probe: a later-completed order from party 3 occupies the freed slot ahead of the earlier-completed order from party 4.

Evidence: [ParentScript 42 - kitchen](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 42 - kitchen.ls:147>); [ParentScript 42 - kitchen](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 42 - kitchen.ls:208>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:177>).

### 6. P1 — Endless timers have different owners

Original ramp updates waiting groups and kitchen speed. A seated group retains its last time multiplier. Its station coffee timer retains the refresh period established when created. Android recalculates seated patience against the global multiplier and uses that multiplier for each coffee refresh. Isolating a 1.0 to 0.5 ramp changes a 10-second patience/coffee interval to 5 seconds. These probes isolate ownership; they do not claim that the actual 0.0015 ramp drops to 0.5 in one step.

Evidence: [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:480>); [ParentScript 12 - room_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 12 - room_manager.ls:180>); [ParentScript 24 - sitterGroup](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 24 - sitterGroup.ls:77>); [ParentScript 46 - drinkspot](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 46 - drinkspot.ls:13>); [ParentScript 46 - drinkspot](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 46 - drinkspot.ls:99>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:208>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:239>).

### 7. P1 — Room occupancy differs beyond tables

Original always builds an 18-column grid, blocks columns 1 and 2 in the first nine rows of the seafood restaurant, and places a three-column bar footprint. Android uses configuration widths 16/17, lacks the seafood strip, and blocks only two bar columns. Three probes demonstrate differing occupied cells. The existing 308 table-to-wheel collision checks do not verify this original occupancy map.

Evidence: [ParentScript 12 - room_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 12 - room_manager.ls:373>); [ParentScript 14 - grid_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 14 - grid_manager.ls:20>); [ParentScript 61 - bar_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 61 - bar_manager.ls:44>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:263>).

### 8. P2 — Bar service point and meal identity differ

Original rounds the middle stool index; Android floors it. A two-person group is serviced one row too high in the probe. Original also allocates letters A-H when bar orders are taken and returns them after delivery. Android derives table letters from stool position while food trays and Flo payloads use the dynamic numeric table index. These identifiers can disagree for the same bar meal.

Evidence: [ParentScript 61 - bar_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 61 - bar_manager.ls:170>); [ParentScript 61 - bar_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 61 - bar_manager.ls:195>); [ParentScript 13 - table](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 13 - table.ls:188>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:272>); [SpriteRenderer.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/SpriteRenderer.java:95>); [GameView.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameView.java:48>).

### 9. P2 — Endless upgrade eligibility triggers on tips too soon

Original scoreTip changes the score without calling endSubLevel; a later addPoints action checks the goal. Android routes the tip through addScore and awards an upgrade immediately. Probe: a tip crossing the goal grants one upgrade; the source contract grants none until a subsequent scored action. Original also has a penalty branch that can retract an accumulated upgrade when the score falls below a goal; Android lacks it.

Evidence: [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:225>); [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:249>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:183>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:226>).

### 10. P2 — Quick seating adds an extra three hearts

Android calls fastService before seating. The recovered drag path goes through sitAtTable and setState(deciding), whose waiting-state exit stops the mood timer without its fast-service result. A separate seat event handler exists, but no caller was found in the recovered runtime scripts. Probe: an unmatched quickly seated party starts deciding at 9 hearts instead of 6. Color-match hearts are separate and already implemented. Verify this source-level discrepancy against the running original before changing balance.

Evidence: [ParentScript 7 - waitgroup_drag](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 7 - waitgroup_drag.ls:142>); [ParentScript 24 - sitterGroup](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 24 - sitterGroup.ls:195>); [ParentScript 26 - sgstate.waiting](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 26 - sgstate.waiting.ls:47>); [ParentScript 26 - sgstate.waiting](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 26 - sgstate.waiting.ls:54>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:128>).

### 11. P2 — Career star capacity is not saved separately

Original tracks totalStars capacity separately from numStars remaining lives and saves both on advancement. Android saves lives only and rebuilds capacity as max(3, lives). After earning capacity 5 and losing a life, the next shift can display capacity 4 rather than 5 with one empty star. A later critic reward can consequently restore fewer lives than the original. Restaurant changes also reset remaining lives while retaining original capacity.

Evidence: [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:187>); [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:463>); [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:764>); [MainActivity.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/MainActivity.java:38>); [MainActivity.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/MainActivity.java:59>).

### 12. P2 — First-shift tutorial completion is replaced

Original runs 24 state-dependent steps checked every 500 ms and starts closing when the tutorial ends. Android has no equivalent step controller; it disables patience per tutorial profile and closes when all scheduled parties are gone. The original guided progression and completion condition are therefore missing, even though the service states and schedule exist.

Evidence: [tutorial_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/tutorial/External/ParentScript 1 - tutorial_manager.ls:44>); [ParentScript 21 - game_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/game/External/ParentScript 21 - game_manager.ls:140>); [GameEngine.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameEngine.java:258>).

### 13. P3 — Long frames slow Android game time

Original forwards the full unpaused frame delta to listeners. Android passes at most 100 ms into the model and discards the rest. Under a long UI/rendering stall, arrivals, patience, cooking and walking all fall behind real time. A scheduler comparison is still needed to match callback ordering, strict timeout boundaries and frame-rate behavior.

Evidence: [time_manager](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-recovered/scripts/ext/events/External/ParentScript 15 - time_manager.ls:56>); [GameView.java](</Users/myrarc/Documents/Codex/2026-10-07/https-github-com-nationalsecurityagency-ghidra-https/outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/GameView.java:30>).

## Original-source quirks requiring executable comparison

- **Weighted random selection:** original draws 1..totalFrequency and tests `r < cumulative`; Android draws 0..total-1 with conventional ranges. In the first Diner Endless sublevel, weights [30,0,0] give the source contract 29 selections of the first type and one selection of the final zero-weight type; Android always selects the first type. The source may contain a genuine original bug. Do not change this from descriptions alone.
- **Juggler/mime upgrade:** Android explicitly multiplies waiting patience by 1.1/1.3/1.5. The recovered handler passes the properties to a mime animation object but does not assign a waiting-state multiplier from them. The upgrade description promises increased patience, so source and description conflict. Verify the executable before removing or changing that effect.
- **Critic reward threshold:** the active customer dump omits heartsRequired, while the recovered script compares mood against that property. Android substitutes zero. A minimum-happiness threshold cannot be inferred responsibly from the text alone.
- **Pending arrival choice:** original preselects the next group and schedules that group's own delay. Android chooses a group when it spawns and then waits using the spawned group's delay. Most sublevels use uniform delays, but three active sublevels have mixed delays; selection/delay correlation and sublevel-change behavior differ there.

## Corrections to earlier findings

The original waitqueue.update calls setFirst(1) on every visible group. waitgroup_view enables each group's mouse listeners. Selecting any visible waiting party follows that active code; the earlier claim that the original restricted selection to the first party was incorrect.

The existence of tableChain/sitterChain properties does not establish an omitted active adjacency-scoring system. The recovered tableChain script is empty, and no active assignment building those neighbor chains was found. Such legacy names are not treated as requirements without reachable handlers.

## Mechanics already aligned in the inspected paths

The active action bases are ticket 20, food 30, dishes 40 and check 50; tips use partySize*baseTip + mood*moodTip. Two consecutive order actions at distinct tables produce 20 + 40 points. Chair matches award 100 times their current multiplier, capped at four, while mismatching a colored chair resets its multiplier. Snacks use the active 75/100/150 point values and pause then resume deciding/eating. Coffee begins at 1-5, and Goddess Flo carries four items. The 1,067 scheduled career parties and all 50 goals/expert thresholds are present. These matches do not establish full difficulty parity, particularly because dish scoring, seating mood and clock ownership differ.

## Recommended repair order

1. Restore bus discard/food-return behavior, order-ready coffee fallback and protection while dragging.
2. Correct occupied dish-clearing bonuses, ready-food FIFO, and original room occupancy/service points.
3. Give timers the same ownership as the original; preserve career star capacity and resolve bar meal labels.
4. Compare source quirks against the executable, then reproduce tutorial, pending arrival selection and upgrade transitions.
5. Reassess campaign/endless difficulty with travel enabled. The existing zero-travel bot winning 46/50 levels does not measure original balance.

## Reproducing the compact audit

Compile the two production model sources and verification/MechanicsAuditProbe.java with a JDK, then run local.dinerdash.prototype.MechanicsAuditProbe. Its output deliberately reports differences; it is not a passing certification test. All production changes in 0.3.1 are limited to the two user-reported animation/transition defects above.
