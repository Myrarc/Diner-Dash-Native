package local.cakemania;

/** Pure rules recovered from the native Jill sprite dispatcher. */
public final class SpriteRules {
    private SpriteRules() {}

    /** 0044a630 draws Jill after background 0 up to y=420, otherwise after 1. */
    public static int avatarRenderAfter(float y) { return y <= 420f ? 0 : 1; }

    /** Native 00403460's authored, intentionally asymmetric direction sectors. */
    public static int direction(float dx, float dy) {
        if (dx == 0f && dy == 0f) return 8;
        double degrees = Math.toDegrees(Math.atan2(dy, dx));
        if (degrees < 0d) degrees += 360d;
        if (degrees < 20d) return 3;       // east
        if (degrees < 70d) return 5;       // south-east
        if (degrees < 110d) return 1;      // south
        if (degrees < 160d) return 4;      // south-west
        if (degrees < 200d) return 2;      // west
        if (degrees < 250d) return 6;      // north-west
        if (degrees < 270d) return 0;      // north
        return 7;                          // north-east
    }

    /** Native animation ids append the nine carried-sprite rows after idle. */
    public static int animationId(int direction, boolean carrying) {
        if (direction < 0 || direction > 8) throw new IllegalArgumentException("direction");
        return direction + (carrying ? 9 : 0);
    }

    /** Gameplay projection from native 004059f0 (map-screen projection is different). */
    public static float gameplayProjection(float y) {
        float clamped = Math.max(0f, Math.min(600f, y));
        float raw = 0.7f + 0.3f * clamped / 600f;
        return (float) (Math.floor(raw * 100f + .5f) * .01f);
    }

    /**
     * Native carried-cake projection.  Cake objects start with perspective
     * endpoints .6/.4 (00407740) and FUN_00402df0 scales both by the authored
     * 0.7 at 00581474 before FUN_004017c0 projects the child layers.
     */
    public static float carryCakeProjection(float y) {
        float clamped = Math.max(0f, Math.min(600f, y));
        float raw = 0.28f + 0.14f * clamped / 600f;
        return (float) (Math.floor(raw * 100f + .5f) * .01f);
    }

    /** 00407740 and 004017c0: cakes grow from .4 at the back to .6 at the front. */
    public static float stationCakeProjection(float y) {
        float raw = .4f + .2f * Math.max(0f, Math.min(600f, y)) / 600f;
        return (float) (Math.floor(raw * 100f + .5f) * .01f);
    }

    /** Base Jill layout keeps authored x/y corrections in world pixels. */
    public static float baseX(float x, float frameWidth, float projection, float xDec) {
        return (int) (x - frameWidth * projection / 2f + xDec);
    }

    public static float baseY(float y, float frameHeight, float projection, float yDec) {
        return (int) (y - frameHeight * projection + yDec);
    }

    /** Upgrade offsets and scales are authored in the projected sprite space. */
    public static float overlayX(float baseX, float projection, float xDec) {
        return (int) (baseX + projection * xDec);
    }

    public static float overlayY(float baseY, float projection, float yDec) {
        return (int) (baseY + projection * yDec);
    }

    public static float overlayScale(float projection, float authoredScale) {
        return projection * authoredScale;
    }

    /** Native screen rectangles truncate each projected dimension independently. */
    public static float projectedSize(float frameSize, float projection) {
        return (int) (frameSize * projection);
    }

    /** Native 004040e0 subtracts animation phase and wraps at the first frame. */
    public static float reversePhase(float phase, float dt, int count, float speed) {
        if (count <= 0) return 0f;
        float result = phase - count * speed * Math.max(0f, dt);
        int converted = (int) result; // x87 conversion truncates toward zero.
        return converted >= 0 && converted < count ? result : count - 1;
    }

    /** Converts the native phase to a sheet row without Java's negative modulo. */
    public static int frameIndex(float phase, int count) {
        if (count <= 0) return 0;
        int converted = (int) phase;
        return converted >= 0 && converted < count ? converted : count - 1;
    }

    /** Native idle keeps the last frame for two seconds, then plays backwards. */
    public static int idleFrame(int count, float speed, float idleSeconds) {
        if (count <= 0) return 0;
        if (idleSeconds < 2f) return count - 1;
        float phase = count - 1 - (idleSeconds - 2f) * count * speed;
        return frameIndex(phase, count);
    }
}
