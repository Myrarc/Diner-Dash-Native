# Career, order selection, and closing audit

Baseline: Android 0.1.2, SHA-256 `ebbe1484864a44a3387603fa687ab73d8d8296846959dd5e72df8db02a92b674`. This is static native/source tracing plus host probes of the APK-bound Java model.

## Lives and career fields

New native slot `00422b10` initializes four lives. Serializer `00446d50` and parser `00449790` identify `+0x48=cash`, `+0x3c=lives`, `+0x40=career_level`, `+0x44=points`. `0041ba80` copies lives into a new month; `0041d890` deducts a life below the goal and enters a distinct GameOverScreen at zero. Android MainActivity has bank, unlocked/current month, upgrades, and best-month scores, with unlimited failed-month retries and no lives/points/game-over state. This is a confirmed omission.

`0044d570` adds month earnings to cash and points before result handling. `0044d0d0` subtracts them again for a failed retry. `00448ed0` can serialize the pre-rollback values before calling `0044d0d0`, but reachability from every failed-result button has not been resolved. Do not patch Android to retain failed earnings based only on the pre-result add.

## Deferred order generation and weights

`004163a0:75-97` constructs an order after the menu flag is active, when the order list is empty. Android `GameEngine.java:132` constructs it during spawn. The executed `deferred-order` probe observed two components before a menu; native expected zero. This affects RNG consumption and when a display-case candidate can be selected.

`0040f430` builds candidates in active-vector order, fills missing candidates when supplied weight sum is below 100, accumulates intervals, then uses `rand()%100`. It returns an active-vector index; `0040feb0` maps that index back to a component ID. Android `choose()` filters supplied positive IDs and normalizes only their sum, omitting default weights. It returns an ID directly.

Raw assembly confirms `0040f483: FLD [EDI+4]`, followed by `00560568`, sums converted supplied weights. **This helper does not consume RNG.** For active IDs `[7,1,2,3]` and supplied `1,90`, native default weights for the three missing candidates are integer `(100-90)/3 = 3`. Android selected only ID1 in 4,096 deterministic trials; the other candidates remained unreachable. The probe demonstrates the missing-candidate branch, not exact Windows RNG frequencies or active-career difficulty.

Native component-count rules were traced in `0040feb0`. The app's `max_layers` translation should not be called a proven tier bug merely because field names differ: supplied valid counts and active overrides still need a concrete divergent fixture. Exact RNG implementation, active-vector ordering, duplicate-weight edge cases, and unavailable component handling remain open.

## Closing: corrected field identities

`0044d8f0` has several customer/event/closing guards beyond Android's duration plus empty-customers check. However, a first-pass finding mislabeled `param[0x84]/param[0x85]` as Jill's queued actions. These addresses are game `+0x210/+0x214`: customer-manager `+0x14/+0x18`, confirmed by `004121b0` and `004163a0`. **They are active customer pointers.**

The queued-click vector is game `+0x15c/+0x160`, or `param[0x57]/param[0x58]`, processed earlier in `0044d8f0`. The inspected closing conditions do not directly test it. Therefore “native waits for Jill's action queue while Android discards it” is withdrawn as a confirmed mismatch. Android's explicit queue clear at closing is known; original equivalence is unresolved.

Native guard fields `+0xb5/+0xb6/+0x10d/+0x119` and pending manager/timestamp checks still require semantic tracing. A pending-event difference is plausible, but no runtime fixture is claimed for it.
