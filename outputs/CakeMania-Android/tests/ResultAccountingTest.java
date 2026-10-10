package local.cakemania;
import java.io.*;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

public final class ResultAccountingTest {
    private static void check(boolean ok,String message){if(!ok)throw new AssertionError(message);}
    public static void main(String[] args)throws Exception{
        GameData data=new GameData(path->new FileInputStream(new File(args[0],path)));
        GameEngine game=new GameEngine(data,data.level(1),Collections.emptyMap(),3);game.suppressArrivals=true;
        Node profile=data.profiles.get("boy").copy();profile.attrs.put("patience","10");profile.attrs.put("tip","2");
        Customer customer=new Customer(1,0,profile,game.arrivals.get(0));customer.state=CustomerState.CASH;customer.cakePrice=30;game.customers.add(customer);
        game.enqueue(customer);for(int i=0;i<1000&&!game.queue.isEmpty();i++)game.tick(1f/60);
        check(game.cakeRevenue==30&&game.tips==6&&game.money==36,"Results must separate cake revenue from heart-based tips at collection");
        customer=new Customer(2,0,profile,game.arrivals.get(0));customer.remainingPatience=10.01f;game.customers.add(customer);game.tick(.02f);
        check(game.customerLostMoney==50,"Result loss money must include the native pre-menu $50 penalty even when cash clamps to zero");
        Cake cake=new Cake();cake.layers.add(new Layer(1,15));game.station("cakeoven0").cake=cake;game.elapsed=game.level.duration;for(int i=0;i<60&&!game.finished;i++)game.tick(1f/60);
        check(game.cakeLostMoney==30,"Uncollected cakes must report twice their component value at closing");
        System.out.println("PASS: separate cake revenue, tips, customer penalties and closing cake losses");
    }
}
