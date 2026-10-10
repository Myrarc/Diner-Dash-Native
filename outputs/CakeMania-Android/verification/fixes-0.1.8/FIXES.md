# Cake Mania 0.1.8

APK SHA-256: `042f8a56b137d4c6c94e2a683c11194d10153d91db3de7a933eed25bbce9a43b`.

- Both menu button artwork and Android targets use recovered bitmap dimensions and stay centered in each row; Profiles has its own row before the footer
- New Game resumes the prepared lesson directly after all three comics; later bakery stories still return to the existing map
- January original copy and $200 goal remain paused until Let's Play after the lesson

Verified: 103 menu geometry/pixel checks at three sizes; 144 month text screens; 49 Activity checks; two focused host suites; normal-launch menu/profile/options touch walkthrough; both complete tutorials, including real New Game and comic taps before the first lesson. Baseline 0.1.7 fails both regression assertions. Original profile preference bytes and display settings are restored, and the owned emulator/test package are removed.

Bounded menu and opening-route repair. Actual input follows menus, three comics and the full first lesson; an isolated Activity completion fixture independently checks January transition. Historical verification is retained for its own APKs. Map information, exact original menu structure, Windows and physical Android parity remain unfinished. See `report.json` for boundaries.
