# Review of the 0.1.8 correction

Only MainActivity's story completion branch and GameView's two menu layouts change in production. Version metadata is bumped to 0.1.8/code 9. Engine, fonts, imported assets, career accounting and January's text-screen correction are unchanged.

The six main choices and four Play choices now share the loaded header, row and button dimensions. Each Android target uses the same coordinates as the rendered red button. The panel draws six yellow rows in the main menu instead of five; Profiles no longer occupies the fruit/footer area. The Play menu's synthetic Career heading is removed because it intersected the first button after alignment.

The first tutorial is prepared and paused while comics are shown. Its final Continue now resumes that same room and first click gate, rather than restarting it or showing the empty month/map panel. Story completion outside the pending first tutorial still opens the existing map. Canceling a story and returning to menus retains the existing restart semantics.

Baseline 0.1.7 fails both new assertions. MenuLayoutProbe checks recovered dimensions, row-center targets and native artwork/footer pixels at three resolutions. Its first pixel fixture sampled the transparent side ornament; it was corrected to opaque yellow margins, with no additional production change. FlowAndroidProbe uses actual MotionEvents for comic Continue and Let's Play; its lesson-completion fixture is isolated. Full real-input tutorial execution separately exercises the opening menu and three comics before making and delivering the practice cake.

Native 00455fb0/0041c460 show generic comics completion opening a map. This release deliberately gives the user-requested direct opening lesson route; original Windows runtime parity of that route is not proven. The existing map information panel remains unfinished, and the original menu separately positions its player selector. These limits are recorded in FIDELITY.md rather than presenting this release as full 1:1 parity.

The older menu walkthrough still expected the former Pause label in gameplay. Its assertion and tap now use the original bottom Menu button introduced in 0.1.5. This was a test-fixture correction; no gameplay code changed.
