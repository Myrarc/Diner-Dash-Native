# Cake Mania 0.1.4 visual and input corrections

APK SHA-256: `792c3a14e68c7c24a34b423fecd29fe6e05daaea4cf540ba776f3eeeacb1169b`.

- Oven interior overlays retain cabinet dimensions and fixed shape buttons
- Frosting strips crop 33 horizontal frames
- Customer torso/normal-rectangle targets and front-slot overlap priority
- Gameplay taps use Canvas coordinates with Form/Shelf priority
- Native 10 ms movement cadence and 200 ms backlog cap
- Jill center-counter depth and final foreground occlusion
- Authored station cake anchors and corrected cake perspective direction

Final APK: six host suites, asset integrity, eight oven states, four real shape/color production runs, both real-input practice lessons, 64 Jill renders, 615 customer renders and 22 Activity checks pass. Original preferences and display settings were restored.

The full January and purchased-machine pass is separately bound to the routing candidate. The final change is the foreground redraw shown in `candidate-to-final.patch`; final input/render checks were rerun.

This is a bounded correction pass, not a claim of whole-game 1:1 parity. Remaining Windows/device, interpolation, carry, routing, save, resource and audio boundaries are listed in `report.json` and `../../FIDELITY.md`.
