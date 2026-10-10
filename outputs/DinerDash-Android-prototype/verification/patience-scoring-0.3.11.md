# Customer patience and scoring — 0.3.11

Career base patience matches the recovered active configuration. The confirmed
faster-anger bug was in Endless: each tick recalculated an active timer from
the latest global difficulty. The original keeps fixed mood-timer thresholds
and retains each seated party's general multiplier. 0.3.11 corrects these rules.

## Career timing at multiplier 1.0

Guests arrive with six of ten hearts. Each passive timeout removes one heart.
The queue-departure examples assume no drag protection, podium or mood bonuses.

| Customer | Waiting: one lost heart | Ready/check | Ordered | Leaves an untouched queue |
|---|---:|---:|---:|---:|
| Default young woman | 10 s | 10 s | 11 s | 60 s |
| Businesswoman | 6 s | 6 s | 6.6 s | 36 s |
| Older man | 15 s | 15 s | 16.5 s | 90 s |
| Boy | 7 s | 10 s | 11 s | 42 s |

Default customers spend 14 seconds choosing and 14 seconds eating; these
one-shot states do not drain hearts. READY starts a fresh ten-second loss
interval. Level 1-1 disables passive mood loss. Coffee adds three hearts and
resets elapsed patience; matching chairs add one heart per match. Other
profile variants retain their own recovered values.

Seated customers briefly play an angry reaction on any decrease in mood,
even while several hearts remain. Original `sitter_view.updateMood` does this
too. Waiting faces use 0.3.10's corrected rounded bands: 5–10 smile, 2–4 use
the middle face, and 1 uses the angry face.

## Fixed timer ownership

Passive states apply general and patience multipliers when starting
`mood_timer`. A mood change resets elapsed time without changing thresholds.
Endless ramps update queued groups' state properties. Room multiplier changes
update the kitchen, not seated groups. Stereo updates state properties for
future timer entries without rebuilding the current timer.

The port now initializes a party multiplier on arrival, updates queued groups
on ramps, retains seated multipliers and snapshots active happy/mad thresholds
on state entry. Fractional deadlines use the first elapsed millisecond that
reaches the source threshold. No profile constants, scoring formulas, sprite
selection or Career difficulty values changed.

Example: a READY party's ten-second interval stays ten seconds when global
difficulty changes to 0.5. Previously it immediately became five seconds,
possibly losing a heart at the ramp itself. Active fast-service windows are
also retained, and new passive states use any purchased stereo multiplier.

## Scoring checked

Original `sitterGroup.calculateTip` is `party size × baseTip + mood × moodTip`.
Default values are 10 and 10: two guests tip 80 at six hearts or 120 at ten.
The mood portion is per party, not multiplied again by guest count.

Order/food/dish/check base points are 20/30/40/50. Repeating an action across
distinct table identities increases its chain multiplier. Occupied-table
clearing contributes to a chain but awards no empty-table dish points.
Matching chairs award 100 times their persistent multiplier, capped at ×4.
Snacks award 150/150/100/75 without chaining; coffee gives no direct points.
These formulas and call-site rules match the port.

Default angry-party penalties are 500, once per party; later variants differ.
The critic's active penalty is 4,000. Existing data checks cover goals/expert
thresholds. No scoring change was needed for this correction.

## Remaining gaps

- Quick seating grants +3 hearts in the port. The recovered drag path calls
  `sitAtTable` directly, bypassing the defined `#seat` happiness handler.
  This extra bonus increases tolerance and remains a separate fidelity gap.
- Maître d' data advertises `patienceMultiplier`, but its recovered handler
  never reads it; it starts a mime animation. The port's extra waiting bonus
  increases tolerance. This implementation-versus-description conflict is
  retained separately from the faster-anger fix.
- Hidden overflow parties lack a distinct NEW state. Queue admission/timer
  starts and preselected pending Endless arrivals remain incomplete. Queued
  party multipliers now update, but this does not establish admission parity.
- Critic `heartsRequired` is absent from recovered active data; Java uses zero.
  Original `addStar` bookkeeping also differs. Original runtime evidence is
  needed before choosing a threshold or claiming critic progression parity.
- Coffee refresh multiplier ownership remains a separate gap. Music reference
  comparison remains paused at the user's request.

## Verification

The baseline fails the assertion that an active waiting timer survives an
Endless ramp. The fixed source passes 36 new patience checks: four profiles,
tutorial immunity, state entry, seated multiplier retention, fast-service
windows and stereo timing. All six existing model suites pass too: **40,946
model checks total**. The zero-travel bot closes all 50 schedules and reaches
43 goals; this does not verify human difficulty.

The installed signed APK passes 36 timing checks plus 687 existing animation,
guest, sprite and bug checks: **723 installed checks**. Installed APK bytes
match the release; all 1,993 asset/resource entries match 0.3.10. All eleven
preferences match before/after the final emulator pass. GameEngine.java is
the only changed production Java file. Evidence is in `0.3.11/`.

No full natural shift, physical device or original Windows runtime test ran.
Save/menu and audio suites were not rerun because their sources are unchanged;
their historical results are not fresh evidence.

## Original references

Under `DinerDash-recovered/scripts/ext/game/External`:

- `ParentScript 24 - sitterGroup.ls`: 95–108 timer start/stop; 134–149 mood
  reset; 195–212 direct seating; 246–250 tip formula.
- `ParentScript 34 - mood_timer.ls`: 17–42 threshold updates and elapsed ticks.
- `ParentScript 26/28/29/31/41`: passive state-entry thresholds.
- `ParentScript 21 - game_manager.ls`: 481–484 ramp targets; 561–573 upgrades;
  766–769 critic star bookkeeping.
- `ParentScript 12 - room_manager.ls`: 180–183 room/kitchen multiplier.
- `ParentScript 8/9`: seated mood reactions and rounded standing faces.

Generated profiles: `src/local/dinerdash/prototype/LevelData.java:12–18`.
Four embedded fonts are decoded separately in
`../../DinerDash-recovered-fonts/`; they are not integrated into this APK.
