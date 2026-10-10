# Cake Mania 0.1.6

APK SHA-256: `5041cca6eb7b61b0e9d44ad646c624f3e5341c0dfd55f18cf8434d7b0aa68dc0`.

- Customer animation uses native bottom-first physical sheet rows while retaining authored sequence order and timing
- Cupid variants use the original three-second 40–50 pixel hover curve; drawing and body input share the motion
- Waiting customers have no synthetic Menu? bubble or invisible order-area target; orders and cash retain their targets
- Original 23x19 hearts overlap on each customer’s left at native queue-depth and money-y anchors; only active hearts are shown

Seven host suites and five final-APK Android probes pass. All 41 profiles complete two idle cycles. Heart pixels match native positions for four bakeries, all 20 queue positions and zero through five hearts. Real Activity input selects Cupid independently and pause freezes his hover. Original preferences and display settings were restored; the test package and task-owned emulator were removed.

Bounded corrections in an unfinished native-code translation; passing Android and host probes do not establish whole-game 1:1 Windows parity. Windows, physical Android, audible playback, full January and both full tutorials were not rerun in this release. Native animated heart transitions and exact order-bubble artwork remain unfinished. See `report.json` and `../../FIDELITY.md`.
