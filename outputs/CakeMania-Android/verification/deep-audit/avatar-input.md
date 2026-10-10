# Jill rendering and movement audit

Baseline: Android 0.1.2, SHA-256 `ebbe1484864a44a3387603fa687ab73d8d8296846959dd5e72df8db02a92b674`. Static tracing, including fresh read-only Ghidra C/assembly exports. No Windows or device comparison was performed in this audit.

## Confirmed renderer differences

`GameView.java:123-130` merges an Upgrade's attributes into the selected Animation. Its `image` therefore replaces Jill's complete body with the small shoe overlay. Native `00402df0` draws the base and upgrade separately. All 18 Animation nodes and 54 Upgrade nodes were inspected. The intended directional fixture is eight directions × four shoe variants × two carry states = 64 cases; these are a fixture plan, not 64 executed pixel tests.

Native base rectangle, with projected base scale P:

```text
width  = R(fullImageWidth  * P / columns)
height = R(fullImageHeight * P / rows)
x = R(positionX - fullImageWidth * P / (2*columns) + globalX + base.x_dec)
y = R(positionY - fullImageHeight * P / rows + globalY + base.y_dec)
```

Upgrade rectangle is a separate layer:

```text
x = R(baseX + P*upgrade.x_dec)
y = R(baseY + P*upgrade.y_dec)
width  = R(upgradeImageWidth  * P*upgrade.scale / upgradeColumns)
height = R(upgradeImageHeight * P*upgrade.scale / upgradeRows)
```

Native `004059f0`, called by gameplay constructor `0044c650`, initializes global offsets to `(0,0)` and projection endpoints to `1.0` and `0.7`. Map-screen `0046b420` sets `(2,-10)` and equal `.4` endpoints; those map values must not be reused for gameplay. The projection caller `00402df0` multiplies by100, adds `.5`, calls numeric helper `0055ff20`, then multiplies by `.01` and the base animation scale. These caller constants were read from the PE with their original float/double widths. The helper itself does not contain the hundredths factor; exact Windows rounding outputs remain unverified. Integer conversions use `00560568`; its raw body is an x87 conversion routine, not RNG.

Native `render=0` draws the base before the carried cake; `render=1` draws it after the cake. The upgrade overlay follows both. Current code instead draws cake behind Jill only for North and otherwise in front, omitting the authored `render` flags and base offsets. West and North-West carried animations explicitly use `render=1`.

## Direction and frame phase

`00401130` normalizes angles; `00403460` uses the following boundaries, unlike Android's symmetric 45-degree rounding:

| Degrees | Animation |
| --- | --- |
| [0,20) | 3 East |
| [20,70) | 5 South-East |
| [70,110) | 1 South |
| [110,160) | 4 South-West |
| [160,200) | 2 West |
| [200,250) | 6 North-West |
| [250,270) | 0 North |
| [270,360) | 7 North-East |
| zero vector | 8 Idle |

Carrying adds 9. The unusual exact-270-degree behavior was checked; preserve the observed binary behavior until a Windows comparison proves otherwise.

`004040e0` subtracts `count * animation.speed * dt` from the frame phase and wraps to `count-1`. Native idle holds the final frame for two seconds before continuing. Android starts at frame zero, waits four seconds, advances forward, and uses a hardcoded 12-frame/s walking rate.

| Direction | IDs without/with cake | Count | Authored speed |
| --- | --- | --- | --- |
| N, S | 0/9, 1/10 | 11 | 1.8 |
| W, E | 2/11, 3/12 | 12 | 1.8 |
| SW, SE | 4/13, 5/14 | 10 | 1.8 |
| NW, NE | 6/15, 7/16 | 12 | 1.8 |
| Idle | 8 | 57 | .15 |
| Carry idle | 17 | 40 | .25 |

## Movement uncertainties

`00401680` advances by avatar speed per invocation. `0044d8f0` moves Jill before measuring delta and passes measured delta to animation separately. Android uses provisional `speed*60*dt`. Native update cadence is unresolved; neither 60 Hz nor 100 Hz was established. Do not substitute a guessed conversion.

The recovered graph's Level 1 node11 is `(319,440)` and node18 is `(365,350)`. Android starts at node18; native gameplay's initial node and exact customer destination association remain unproven. Queue cancellation, free-floor clicks, and route corner rounding need a separate native trace.
