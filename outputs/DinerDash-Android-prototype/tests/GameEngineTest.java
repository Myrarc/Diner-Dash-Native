package local.dinerdash.prototype;

public final class GameEngineTest {
    private static int assertions;
    private static void check(boolean truth, String why) {
        assertions++;
        if (!truth) throw new AssertionError(why);
    }
    private static GameEngine game(int number) {
        GameEngine game = new GameEngine(LevelData.get(number)); game.paused = false; game.tick(1); return game;
    }
    private static void advance(GameEngine game, long ms) { for (long t = 0; t < ms; t += 100) game.tick(Math.min(100, ms - t)); }
    private static boolean carrying(GameEngine game, GameEngine.ItemType type) {
        for (GameEngine.Item item : game.hands) if (item.type == type) return true;
        return false;
    }
    private static void play(GameEngine game) {
        for (int i = 0; i < 6000 && !game.ended; i++) {
            for (GameEngine.Party party : game.waiting()) {
                for (int t = 0; t < game.level.tables.size(); t++) {
                    GameEngine.Table table = game.level.tables.get(t);
                    if (table.party == null && !table.dirty) { game.seat(party.id, t); break; }
                }
            }
            if (game.currentTarget == GameEngine.NO_TARGET && game.destinations.isEmpty()) {
                int target = GameEngine.NO_TARGET;
                if (carrying(game, GameEngine.ItemType.DISHES)) target = GameEngine.BUS;
                else if (carrying(game, GameEngine.ItemType.FOOD)) {
                    for (GameEngine.Item item : game.hands) if (item.type == GameEngine.ItemType.FOOD) { target = game.party(item.party).table; break; }
                } else if (carrying(game, GameEngine.ItemType.TICKET)) target = GameEngine.KITCHEN;
                else if (game.readyFoodCount() > 0) target = game.firstReadyFoodTarget();
                else {
                    for (int t = 0; t < game.level.tables.size(); t++) {
                        GameEngine.Table table = game.level.tables.get(t);
                        if (table.dirty || (table.party != null && (table.party.state == GameEngine.State.READY || table.party.state == GameEngine.State.CHECK))) {
                            target = t; break;
                        }
                    }
                }
                if (target != GameEngine.NO_TARGET) game.queue(target);
            }
            game.tick(100);
        }
    }
    public static void main(String[] args) {
        check(GameEngine.tip(2, 6, 10, 10) == 80, "Mood affects the whole party's tip, not every customer separately");
        GameEngine game = game(1);
        game.paused = true; long time = game.time; game.tick(30000);
        check(game.time == time && game.parties.size() == 1, "Pausing must freeze both arrivals and customer timers");
        game.paused = false; check(game.seat(0, 0), "A clean table must accept a fitting party");
        advance(game, 4000); check(game.party(0).state == GameEngine.State.READY, "Tutorial profile uses a four-second decision timer");
        check(game.perform(0), "Flo takes an order from a ready table");
        check(game.score == 20 && game.hands.size() == 1, "Taking an order scores once and occupies a hand");
        check(!game.perform(0) && game.party(0).state == GameEngine.State.ORDERED, "Food cannot be served merely by tapping an ordered table");
        check(game.perform(GameEngine.KITCHEN), "The order must reach the kitchen before cooking starts");
        advance(game, 4999); check(game.readyFoodCount() == 0, "Food cannot be ready before the recovered five-second cooking delay");
        advance(game, 1); check(game.readyFoodCount() == 1, "Cooking completion exposes food for pickup");
        check(game.perform(game.firstReadyFoodTarget()) && carrying(game, GameEngine.ItemType.FOOD), "Cooked food must be picked up before delivery");
        check(!game.perform(1) && carrying(game, GameEngine.ItemType.FOOD), "A wrong-table visit must retain the matching table's food");
        check(game.perform(0) && game.party(0).state == GameEngine.State.EATING, "Matching food advances service to eating");
        advance(game, 4000); check(game.party(0).state == GameEngine.State.CHECK, "Eating completion makes the bill available");
        check(game.perform(0), "Bill delivery starts payment");
        advance(game, 1000); check(game.served == 1 && game.score == 180, "Tips credit automatically after payment");
        check(game.perform(0) && !game.level.tables.get(0).dirty, "Dish pickup must unlock eventual table reuse");
        check(game.perform(GameEngine.BUS) && game.hands.isEmpty(), "Dish dropoff frees carried capacity");

        GameEngine crowded = game(2);
        crowded.hands.add(new GameEngine.Item(GameEngine.ItemType.DISHES, -1));
        crowded.hands.add(new GameEngine.Item(GameEngine.ItemType.DISHES, -1));
        crowded.seat(0, 0); advance(crowded, 14000);
        crowded.queue(0); crowded.queue(1); advance(crowded, 3000);
        check(crowded.destinations.isEmpty() && crowded.hands.size() == 2, "Failed full-hands actions clear queued destinations without losing items");

        GameEngine angry = game(2); advance(angry, 60000);
        check(angry.party(0).state == GameEngine.State.GONE && angry.abandoned >= 1 && angry.score == 0,
              "Ignored customers leave and their penalties must not make score negative");

        GameEngine.Level matching = new GameEngine.Level(1, 0, 0);
        matching.tables.add(new GameEngine.Table(5, 6, new int[] {0}));
        int[] colors = {0, 0, 0, 0, 0, 1, 1};
        for (int color : colors) matching.arrivals.add(new GameEngine.Arrival(0, new int[] {color}, true));
        GameEngine chairs = new GameEngine(matching); chairs.paused = false; chairs.tick(1);
        int[] bonuses = {100, 200, 300, 400, 400, 0, 100};
        for (int i = 0; i < bonuses.length; i++) {
            int before = chairs.score; chairs.seat(i, 0);
            check(chairs.score - before == bonuses[i], "Chair loyalty must grow, cap at four, and reset on a color change: " + i);
            chairs.party(i).state = GameEngine.State.GONE; matching.tables.get(0).party = null;
        }
        GameEngine chains = game(1); advance(chains, 25000);
        chains.seat(0, 0); chains.seat(1, 1); advance(chains, 4000);
        chains.perform(0); chains.perform(1);
        check(chains.score == 60, "Taking orders from two distinct tables pays 20 then 40");
        chains.queue(GameEngine.KITCHEN);
        for (int i = 0; i < 8; i++) chains.queue(GameEngine.BUS);
        check(chains.destinations.size() == 5, "The queue limit excludes the destination Flo is already walking toward");

        for (int n = 1; n <= 3; n++) {
            GameEngine shift = game(n); play(shift);
            check(shift.ended && shift.won, "Each shipped level must be completable with normal queued service: " + n);
            check(shift.served == shift.level.arrivals.size() && shift.abandoned == 0, "Attentive play must serve all scheduled parties: " + n);
            System.out.println("Level " + n + ": score=" + shift.score + ", served=" + shift.served + ", simulated_ms=" + shift.time);
        }
        System.out.println("PASS: " + assertions + " gameplay intent assertions");
    }
}
