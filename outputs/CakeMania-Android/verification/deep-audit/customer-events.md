# Customer, TV, and display-case audit

Baseline: Android 0.1.2. Patience reservoir math, menu/cookie caps, cake-price summing, tips at collection, served-customer decay freeze, and the generic month-end `2x` leftover penalty are already represented in the current model. This audit does not label them missing.

## Missing visual states and authored timing

Native cookie callback `0040a190` adds cookie heart time, sets visual state4/ID_EATING, and resets only visual timer/frame. `00412970` continues patience and menu timing independently. `0040d370` finishes a non-menu visual sequence by restoring normal state0. Android has only logical states WAIT_MENU/READING/ORDER/HAPPY/CASH and never selects ID_EATING.

A visible-eating fixture should use logical ORDER. READING can override the eating visual back to MENU in native `00412970`; a promise that all logical states display the full eating sequence would be incorrect. Hearts and logical timers must remain independent of visual changes.

Native timing parser `00410e80` computes `time/(frameend-framestart)` for each segment, and `0040b280` applies it on the half-open interval `[framestart,frameend)`, with a `.1s` fallback. `0040d370` advances one frame when visual elapsed exceeds that interval, resets elapsed, and does not advance multiple frames in one draw. Android instead scales the full Sequence length by the first Timing.time and loops indefinitely. Business ID_EATING has ten sequence entries and timing `0..9,time=1.2`: native timed frames use about `.1333s`, Android's formula uses `.12s`. The final default-duration frame and draw quantization mean total native sequence duration is not simply Timing.time.

TV completed-program handler `004392a0 -> 004121b0` adds matching heart intervals and sets a temporary happy visual for positive awards. Android awards matching heart time but lacks that independent happy visual. Served customers and active MENU visuals can override this state; fixture logical ORDER isolates it.

## Special events

`00414200` parses xtrahearts and `00414d80` parses Message xtime. `00412970` dispatches atstart/atserved or timed events to `004121b0`; matching customers receive signed heart intervals and positive temporary happy visuals. Positive numeric timers reset and may recur; do not describe them as necessarily one-shot.

Android retains the XML Nodes but consumes neither xtrahearts nor Message. Supplied Granny variants have atstart messages; Woman variants have ten-second messages. Many profiles react to Santa/Dracula names. The missing infrastructure is certain; which supplied schedule events are impactful remains a separate configuration/reachability question. A synthetic atstart Santa plus a customer with `xtrahearts=santa,1` tests the branch without claiming a supplied level spawns that exact message.

## Display-case impulse orders

`0040feb0:59-140` rolls get_display, examines eligible completed display candidates, rejects orders duplicated by another customer, copies a selected cake into the order, and marks the display candidate. Two/four-component cakes are eligible; three/five-component cakes require a final decoration component. Six-plus are rejected. Weighted generation is the fallback.

Android uses one generic DisplayCase cake but has no impulse-order branch. In the executed synthetic probe, the case held shape7/frost3, get_display was100, and normal weights requested shape1/frost0. Android generated `[1,0]`; native branch expected `[7,3]`. Parser `00417240:154-157,268-291` initializes get_display to20 and supports an explicit override. This is binary evidence beyond the shop's “20%” text, although the selector uses an inclusive comparison and exact probability/reservation/consumption behavior still needs tracing.

The current generic DisplayCase cake already participates in `GameEngine.tick`'s `2x` month-end price deduction. Supplied upgrades declare **one** DisplayCase FormShelf, not four display slots. Four separate shelves belong to CookieOven.

## Remaining customer uncertainties

Arrival min/max intervals versus explicit schedule times, exact entrance/departure geometry, Cash-plus-held-cookie action precedence, sound/heart flashes, visual perspectives and hit regions need more tracing or a native runtime comparison.
