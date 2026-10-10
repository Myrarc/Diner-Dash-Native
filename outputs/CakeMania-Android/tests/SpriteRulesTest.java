package local.cakemania;

/** Host-side regression checks for the native Jill direction and phase rules. */
public final class SpriteRulesTest {
    private static void check(boolean ok, String message) {
        if (!ok) throw new AssertionError(message);
    }

    public static void main(String[] args) {
        check(SpriteRules.direction(0, 0) == 8, "zero movement is idle");
        check(SpriteRules.direction(1, 0) == 3, "east sector");
        check(SpriteRules.direction(0, 1) == 1, "south sector");
        check(SpriteRules.direction(-1, 0) == 2, "west sector");
        check(SpriteRules.direction(0, -1) == 7, "native exact 270-degree boundary");
        for (int direction = 0; direction < 9; direction++) {
            check(SpriteRules.animationId(direction, false) == direction, "base animation id " + direction);
            check(SpriteRules.animationId(direction, true) == direction + 9, "carried animation id " + direction);
        }
        check(SpriteRules.gameplayProjection(0) == .7f, "top projection endpoint");
        check(SpriteRules.gameplayProjection(600) == 1f, "bottom projection endpoint");
        check(SpriteRules.avatarRenderAfter(420f) == 0, "Jill at the native depth boundary stays behind the central counter");
        check(SpriteRules.avatarRenderAfter(420.01f) == 1, "Jill below the boundary stands in front of the central counter");
        check(SpriteRules.carryCakeProjection(0) == .28f, "carried cake top endpoint");
        check(SpriteRules.carryCakeProjection(600) == .42f, "carried cake bottom endpoint");
        check(SpriteRules.carryCakeProjection(300) == .35f, "carried cake midpoint is rounded to hundredths");
        check(Math.abs(SpriteRules.stationCakeProjection(0)-.4f)<.00001f, "native station cake is smaller at the back of the room");
        check(Math.abs(SpriteRules.stationCakeProjection(600)-.6f)<.00001f, "native station cake is larger at the front of the room");
        check(SpriteRules.baseX(300, 98, .7f, 5) == 270, "base x truncates projected body and keeps correction unscaled");
        check(SpriteRules.baseY(400, 99, .7f, 5) == 335, "base y truncates projected body and keeps correction unscaled");
        check(SpriteRules.overlayX(270, .7f, 5) == 273, "shoe x truncates scaled authored offset");
        check(SpriteRules.overlayY(335, .7f, 5) == 338, "shoe y truncates scaled authored offset");
        check(Math.abs(SpriteRules.overlayScale(.7f, 1.05f) - .735f) < .00001f, "shoe scale follows projection");
        check(SpriteRules.projectedSize(99, .7f) == 69, "projected body dimension truncates independently");
        check(SpriteRules.reversePhase(0f, 1f, 10, 1.8f) > 0f, "reverse phase wraps");
        check(SpriteRules.idleFrame(57, .15f, 1.99f) == 56, "idle holds its last frame");
        check(SpriteRules.idleFrame(57, .15f, 2.01f) == 55, "idle begins reverse playback after two seconds");
        check(SpriteRules.idleFrame(57, .15f, 2.2f) < 56, "idle then runs backwards");
        System.out.println("PASS: native Jill sprite rules");
    }
}
