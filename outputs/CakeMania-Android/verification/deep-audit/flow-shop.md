# Shop, profiles, screens, and tutorial audit

Baseline: Android 0.1.2. Findings concern native flow; this pass made no production/save changes.

Native has named Player records, multiple Slot records, current-player selection, tutorial progress and upgrade vectors, serialized to playerslots.xml. Android has a single global SharedPreferences career and clears it for a new career. New-profile native defaults (cash0, four lives, level0, points0) are confirmed; reset semantics for an existing named profile remain unresolved.

Native menu definition includes load-saved-game, profile selection, endless play/difficulty/bakery layers, and volume sliders. Android's menu offers its own simplified career/choose-month flow and boolean sound/music toggles. The missing game modes/profile flow are confirmed. Windows full-screen/cursor controls require an Android platform decision, rather than blind duplication of desktop-specific controls.

`0041c460` loads the native map. `00456610` supports multiple comics stages. `00451c50`/`00450f20` execute scripted tutorial events including AddCustomer, Timer, WaitForClick, and DrawArrow. Android shows three initial tutorial comic images, static help pages, and generic intro/results/shop/career screens. No map or scripted tutorial state machine exists. Some original comic/credits resources are absent from the supplied recovered resource table; loading their declarations without resolving them would crash.

Shop purchase cost gates and in-memory debits were traced in `0046de00`, `0046eed0`, and `00470e60`. Android checks available bank and applies costs/upgrades. A Level1 froster0 purchase costs600: cash1000 should become400, cash500 must reject. Native durable-save dispatch after purchases remains indirect; do not claim immediate native persistence established.

Android exposes the next higher upgrade per GUID. Native `0046fa80` builds current-step-plus-one thresholds, `00444a00` feeds them to `00443740`, and that parser admits entries up to the threshold. Final owned-item filtering is unresolved, so raw candidate differences do not yet prove a visible shop-choice bug.

Original HUD, result/shop/map/menu positions and authored font sizing are not matched by the prototype UI. The current generic best-month list differs from native profile/career high scores. All 48 host-simulated goal passes used a bot with free full upgrades in later months; they do not prove affordability, native career progression, or human difficulty.
