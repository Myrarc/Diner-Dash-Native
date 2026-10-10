# Cake Mania native-to-Android audit

The current APK is a playable port with substantial native behavior still missing. The main bottleneck is simplified state handling: logical customer states also drive sprites, display storage bypasses native ordering, career results omit lives, and rendering ignores authored overlays/phases. More screenshot-based adjustments alone will keep producing regressions. Each next fix needs a traced native branch and a fixture that can fail when that branch is absent.

This audit uses the supplied binary and assets, three parallel investigation agents, parent verification, and an independent test review. **No production Java or APK was changed by this audit.** The baseline remains 0.1.2, SHA-256 `ebbe1484864a44a3387603fa687ab73d8d8296846959dd5e72df8db02a92b674`. [APK binding](apk-binding.json) verifies source, compiler DEX, every packaged local asset, original binary and signature. [Structured findings](report.json) contain priorities, source lines, native addresses and uncertainty boundaries.

## Highest-impact findings

| Area | Confirmed difference | Evidence |
| --- | --- | --- |
| Jill | Shoe upgrades replace her body; base/overlay/cake layers, direction boundaries, frame rates and idle timing differ | [Avatar/input](avatar-input.md) |
| Career | Four native lives and terminal game-over handling are absent | [Progression/orders](progression-orders.md) |
| Orders | Generated at arrival; missing default weights; display-case impulse orders absent | [Progression/orders](progression-orders.md), [Customer events](customer-events.md) |
| Customers | Missing cookie eating, positive heart-gain happiness, special events and authored timing ranges | [Customer events](customer-events.md) |
| Equipment | Cupcake door transition, child shelf hit routing and intermediate oven animation missing | [Machine/input](machine-input.md) |
| Flow | Scripted tutorial, named profiles, native map/story/result/HUD flow and endless mode missing | [Flow/shop](flow-shop.md) |
| Audio/runtime | Missing native sound triggers, stale TV upgrade position, repeated-frame cache churn | [Audio/assets](audio-assets.md) |

## Executed native-intent probes

These execute the **APK-bound Java model on the host**, using native expectations traced statically. They are not Windows-vs-Android runtime tests. Synthetic cases isolate a native branch; their impact in active schedules is qualified in the detailed reports.

| Probe | Native expectation | 0.1.2 observation |
| --- | --- | --- |
| Arrival before menu | Empty order | Two components |
| Last production tick of empty CookieOven | Zero available products, door transition active | Four products immediately |
| Active IDs 7/1/2/3, supplied weight 1=90 | Missing IDs retain positive default weights | Only ID1 reachable in 4096 draws |
| get_display=100, displayed 7/3, fallback weights 1/0 | Copy display order 7/3 | Generates fallback 1/0 |
| Purchased Level1 TV x_global=140 | Render/input position 140 | Station position 145 |

All five expose differences; they are deliberately reported as **parity failures**, not passing game-fidelity tests. [Probe source](ParityProbe.java), [results](probe-results.json), and the retained generator allow reproduction. The independent reviewer reran the first four and checked their native expectations. Parent added and executed the geometry probe afterward.

## Coverage and corrections

The exported metadata contains 7,470 functions: 7,468 successful pseudocode exports, two failures, 15,798 direct-call edges and 3,894 string-reference rows. This pass checked selected paths in 123 distinct native routines: 117 in the initial metadata, five supplemental callbacks, and one partial assembly resource binder. [Coverage summary](coverage-summary.json) records these counts. [Function ledger](function-coverage.tsv) leaves every unreviewed function visible. Library/runtime routines are included in the export total; function counts do not prove every gameplay branch was inspected. The failed giant resource binder was checked only for selected assembly bindings; the other failed floating-point helper remains a gap. Virtual callbacks outside the initial metadata were recovered separately with Ghidra in read-only mode.

All six Android source files, all 48 month environment configs, and all four upgrade catalogs were inspected. The 96 normalized config files parse; this is structural validation, not complete semantic tracing of every config tag.

Several first-pass claims were corrected before accepting findings:

- The native vector at game+0x210/0x214 is the **customer list**, not Jill's action queue. Native waiting for all Jill actions at closing is unproven.
- DisplayCase upgrades contain **one** shelf; four shelves belong to CookieOven.
- Native integer helper 00560568 is **not RNG**.
- EATING can be overridden by active MENU logic; fixture logical ORDER isolates it.
- Cupcake expiry subtracts the same tick's delta from the new transition. Native initial stock remains unknown.
- Math.floorMod is backported in the compiled DEX; source API history alone did not establish an Android 23 crash.

## Fix order and unresolved evidence

1. Restore Jill's separate body/upgrade/cake draw layers and authored animation phase. Verify all directions, shoes and carry states with rendered captures.
2. Add an independent customer visual state/timer, native timing segments, and positive/special-event visuals without resetting logical timers.
3. Translate order generation at menu activation, selector candidates and display impulse/reservation semantics. Preserve explicit RNG/active-vector uncertainties.
4. Restore CookieOven transition and shelf input, then oven visual phases and sound timing. Resolve startup stock rather than guessing.
5. Restore lives/results/profile/tutorial/map flow, checking save boundaries and existing-career migration before changing persistent data.

Movement cadence/initial node, exact closing events, failed-month durable saves, final shop owned-item filtering, monthly cake XML fallback, native FPU/pixel rounding, active schedule effects and audible loops remain open. Full Windows execution and physical Android comparison were **not** performed. Previous emulator menu/January/asset checks remain valid for their baseline hash; the fully upgraded host bot's 48 goal passes do not establish affordable progression, human difficulty or 1:1 behavior.
