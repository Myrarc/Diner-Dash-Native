# Equipment, input, and queue audit

Baseline: Android 0.1.2. All 48 month environment configs and four upgrade catalogs were inspected for machine types and child controls. Ordinary shape/color/topper Form hit regions, body place/pickup, two-tier tray assembly, disabled-equipment gating, and trash sheet slicing were fixed and checked in the packaged baseline.

## FormShelf targeting

`004440a0`, `0043b1f0`, `00434480`, and `00435820` parse and hit-test FormShelf children. Callback `0044ab40` attaches/picks up the selected child product. Android controls expose bodies and Forms only. CookieOven has four child shelves but represents them as an integer count; direct child selection and independent pointers are absent.

Each supplied DisplayCase upgrade has **one** FormShelf, at `x=0,y=-8,width=85,height=50`. Thus the confirmed difference is missing child hit routing, including the region eight pixels above the body, not a missing four-cake display capacity. All 48 monthly Shelfs collections are empty; standalone Shelf behavior is outside exercised supplied career configurations.

## CookieOven refill phase

Read-only recovered callback `004348d0` scans child product pointers. With none remaining it starts the configured timer on a later update. Timer expiry zeroes it, sets a separate transition timer to1, and immediately subtracts that update's dt from the transition. Products are allocated only when the transition becomes negative. Android creates four cupcakes immediately at production expiry and starts the refill in the last-pickup callback.

Executed final-production-tick fixture: no stock, production remaining `.05`, `dt=.05`. Native expects no available product and transition about `.95`; Android exposes four products. This does not assume how native initial stock is seeded. Constructor/reset tracing did not establish native initial four-cupcake stock. Exact-zero timer edge behavior and original startup/save callbacks remain open.

## Oven phases and animation

`00434020` has five phase boundaries:

| Production time | Boundaries |
| --- | --- |
| T >= 2 | T-2, T-1.8, T-1.6, T-.6, T-.4 |
| T < 2 | 0, .2T, .6T, .65T, .85T |

`00436d50` recycles an old cake in the discard window and creates the new cake after the fresh boundary. Current close/discard/fresh lifecycle anchors match those branches. `00434d30` additionally animates door/body/trash/flame stages and interpolates the cake while baking. Android draws a static image and draws the cake only once ready, omitting intermediate visual phases and `main_door_img` usage.

Native stack gates `00407870`/`00407930` and callback placement branches were reviewed. No new stack discrepancy was proven, so no stacking change is justified by this pass.

## Queue and paths

`00404800` drives arrival callbacks; `0044bf00` resolves clicked targets; `0044d8f0` processes queued clicks. Baseline host tests cover early pickup as a no-op that continues to the next action, and invalid busy/empty Form clicks clearing queued clicks. Broader invalidation during transit, cancellation, free-floor clicks, exact customer associations, and callback delay semantics still need comparison.

Android queue cancellation clears its route but leaves dx/dy until the next tick. This is a local state detail, not a proven native defect. `speed*60` remains provisional. The original graph is recovered; matching graph connectivity alone does not prove native path choice or movement timing.
