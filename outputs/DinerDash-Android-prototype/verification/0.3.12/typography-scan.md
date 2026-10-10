# Diner Dash font integration scan

Scope: read-only scan for the user-approved integration of `Komika Axis` and
`Mr.B`. Daniel and Daniel Black are excluded. The fixed 800x600 composition,
copy, controls, and current body/receipt fallback remain authoritative.

## Mechanical scan

Command:

```sh
node /Users/myrarc/.agents/skills/impeccable/scripts/detect.mjs --json --scope type \
  outputs/DinerDash-Android-prototype/src/local/dinerdash/prototype
```

Result: `[]`.

## Dynamic Java findings

- `GameView.java:36` uses one shared helper with `casual` bold for HUD goals,
  scores, level labels, and popup amounts. If these are the custom display
  roles, load one of the recovered faces there; keep the body/receipt helper
  separate.
- `MenuView.java:33` uses one shared helper with `casual` normal for all
  dynamic menu text. Do not globally replace this helper: `paragraph()` at
  `MenuView.java:34` measures with its own `Paint`, and `receiptText()` at
  `MenuView.java:35-37` measures and clips a fixed 243x81 logical-pixel field.
  A shared helper that switches to a custom face after measurement will wrap
  or clip inconsistently.
- Keep `paragraph()` and `receiptText()` on the current fallback as requested,
  or make each helper set and measure the same face. The receipt's clip is
  `(327,249)-(570,330)` after the result-panel translation.
- `MenuView.java:70-71` draws endless-shop names and descriptions dynamically;
  descriptions should remain body fallback. `MenuView.java:72,75-76` draws
  player names and high-score rows without a width clip, so preserve the
  existing fallback unless a dedicated custom role is intentionally bounded.
- `MenuView.java:74` uses fixed baselines for the pause heading and note. If
  the heading moves to a recovered face, retain the baseline and center; do
  not alter the logical panel geometry.
- `MainActivity.java:40` uses a native `EditText` for profile entry. This is an
  input bridge outside the Canvas typography scope; the rendered profile name
  still follows `MenuView.java:72`.

## Font constraints

Both recovered TTFs contain all printable ASCII characters. At 22 logical px,
all start-level strings wrapped by the existing 365 px width remain within
that width when measured and drawn with the same face; the widest lines are
approximately 365 px. Do not measure with `casual` and draw with a recovered
face. Komika Axis has ascent/descent `2825/-517` at 2048 units; Mr.B has
`1638/-95`, so `Paint` line spacing and vertical ink bounds differ materially.

## Existing verification gap

The Java tests cover game state, sprites, and screenshot capture, but no test
asserts the selected Typeface, measured text width, or text clipping. The
existing `FidelityTest`, `AndroidProgressTest`, and `AndroidGuestTest` do not
provide font-family or glyph-layout evidence. Visual comparison of the shipped
APK remains required after integration.
