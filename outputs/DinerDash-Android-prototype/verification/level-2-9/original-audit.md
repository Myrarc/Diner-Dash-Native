# Career 2-9 (level 19) scoring audit

Read-only comparison of the recovered active configuration and the Android data.

## Configuration

- Recovered source: `outputs/DinerDash-recovered/data/ext/conf/career_2_9_dump.txt:1`
  declares `minimumTip=7500`, `bonusGoal=15000`, 22 groups, and 69 customers.
- Port: `outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype/LevelData.java:742-785`
  has the same goals, 22 arrival records, profiles, sizes, and color sequences.
- Source layout has seven tables. The source six-top record lists tile `[8,9]`,
  while the port uses `(8,8)` at `LevelData.java:749`. The port's destination
  calculation uses the table anchor plus `(1,-2)`, matching the source's first
  chair-derived destination, so this representation difference is not proven to
  be a gameplay or scoring defect.
- The source layout's `#podium` field is `<Void>`, but that is not the object
  gate. The same record has a separate top-level `#podium` timing/config block;
  `ParentScript 12 - room_manager.ls:517-529` creates the podium when that
  top-level block is present. The port's podium block at `LevelData.java:752,758`
  is therefore supported by the recovered source.
- The source layout record lists five legacy `foodspot` coordinates, but those do
  not control runtime capacity. `ParentScript 12 - room_manager.ls:116-123`
  populates `foodnodes` from the active background's `food_1...food_5` nodes and
  `:450-468` instantiates only those nodes. The active `bg_tiki` layout contains
  `food_1...food_3`; the port's three slots at `LevelData.java:756` therefore
  match the runtime source for this stage.

## Score math

- Source action values are in `outputs/DinerDash-recovered/data/ext/conf/global_dump.txt:1`:
  ticket 20, food 30, dishes 40, check 50; drinks 0.
- Source chains are implemented in `ParentScript 50 - waiter.ls:269-290`
  and `:300-317,365-388`: a chain starts at base points and multiplies by the
  number of distinct tables once the chain reaches two. The port's
  `GameEngine.java:257-258` matches this, including table identity and the
  occupied-table dish behavior at `:276-277`.
- Source tip formula is `ParentScript 24 - sitterGroup.ls:246-250`:
  `partySize * baseTip + mood * moodTip`; port is `GameEngine.java:252`.
  All 22 groups at mood 6 yield 1,995 tip points; at mood 10, 2,875.
- With no chains and all three scored service actions per group, the level yields
  2,200 action points plus tips, or 4,195 at mood 6 / 5,075 at mood 10. If all
  22 dish clear actions are also scored after parties leave, this becomes 5,075 /
  5,955. A score around 8,600 therefore indicates some chains/bonuses, but does
  not indicate that the expert goal is mathematically unreachable.
- Seven tables permit a theoretical distinct-table chain ceiling of 18,620 for
  the four 22-action chains, before tips. This is only an unconstrained upper
  bound; scheduling, cooking, table reuse, and patience dependencies mean it is
  not a proof of a feasible 15,000 run. The current evidence establishes only
  that the target is not refuted by the point coefficients; an actual chain-policy
  benchmark is required.

## Evidence and conclusion

Existing port verification reached `score=9415 goal=7500 served=22 angry=0` for
shift 19 in `verification/0.3.6/FullGameTest.log:19` and
`verification/0.3.11/FullGameTest.log:19`; another run reached 10,295. Thus the
normal goal is passable with no angry guests, while 15,000 is an expert chain
target. No confirmed scoring-formula mismatch explains 8,600. The source/port
comparison alone does not prove a feasible 15,000 run; a deliberate chain-policy
benchmark is still needed.

## Expert verification, 2026-10-09

This supersedes the earlier unresolved feasibility conclusion. The unchanged installed 0.3.12 APK earned 15,115 from ordinary GameView drags/taps using a controlled 16 ms clock: 22 parties served, zero lost, 4,800 chair points, 7,760 service points and 2,555 tips. Flo used the production pathfinder and two-item capacity; no score, timer, mood or position injection occurred. All guests kept their original order. A separate input-only checker validated five frame-specific recordings at 16, 17, 20, 50 and 100 ms, earning 15,105-15,115. An installed 100 ms replay independently earned 15,105. See `expert/` for inputs, checker, instrumentation source, logs, screenshot and integrity evidence. This verifies attainability, not Windows timing parity or human touch comfort.
