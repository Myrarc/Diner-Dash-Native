package local.cakemania;

import java.io.File;
import java.io.FileInputStream;
import java.util.Collections;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/** Focused regression checks for customer departure effects and queue compaction. */
public final class CustomerLifecycleTest {
    private static void check(boolean value,String message){if(!value)throw new AssertionError(message);}
    private static void advance(GameEngine g,float seconds){for(int i=0;i<Math.ceil(seconds*60);i++)g.tick(1f/60);}
    private static void drain(GameEngine g){for(int i=0;!g.queue.isEmpty()&&i<6000;i++)g.tick(1f/60);check(g.queue.isEmpty(),"Customer action must terminate");}
    private static GameEngine fixture(GameData data){
        GameEngine g=new GameEngine(data,data.level(1),Collections.emptyMap(),431);
        g.suppressArrivals=true;
        g.elapsed=g.level.duration+1;
        return g;
    }
    private static Customer add(GameEngine g){return g.addCustomer(g.arrivals.get(0));}
    private static Cake cake(int shape){Cake result=new Cake();result.layers.add(new Layer(shape,15));return result;}

    private static void servedCustomerLeavesBodyAndCollectsOnce(GameData data){
        GameEngine g=fixture(data);Customer c=add(g);c.state=CustomerState.ORDER;c.order.layers.add(new Layer(1,15));g.hand=cake(1);
        g.enqueue(c);drain(g);
        check(c.state==CustomerState.HAPPY&&c.spriteVisible(),"A delivered customer remains visible during the native happy interval");
        g.tick(2f);check(c.state==CustomerState.HAPPY,"The native happy interval uses a strict greater-than two-second boundary");
        g.tick(.01f);check(c.state==CustomerState.CASH&&!c.spriteVisible()&&c.effectActive()&&c.departureFrame==4,"Cash must hide the body and start the five-frame money puff at frame four");
        int expectedPayment=c.payment();
        g.enqueue(c);drain(g);
        check(c.cashCollected&&g.money==expectedPayment&&g.cakeRevenue==c.cakePrice,"Cash collection must award the payment once while the puff is still active");
        g.enqueue(c);check(g.queue.isEmpty(),"A collected cash customer cannot be queued for a second payment");
        advance(g,.8f);check(!g.customers.contains(c),"The customer slot is released only after collection and the puff complete");
    }

    private static void unhappyCustomerLeavesAndChargesOnce(GameData data){
        GameEngine g=fixture(data);Customer c=add(g);g.money=100;c.remainingPatience=.1f;
        g.tick(.2f);check(c.state==CustomerState.LEAVING&&c.effectActive()&&!c.spriteVisible(),"Patience expiry must enter the native angry-puff departure state");
        check(g.lost==1&&g.money==50,"An unhappy departure must retain the existing menu penalty");
        advance(g,.8f);check(!g.customers.contains(c)&&g.lost==1&&g.money==50,"The angry puff must not charge or count the same customer twice");
    }

    private static void queuePositionsCompactAndRetarget(GameData data){
        GameEngine g=fixture(data);Customer first=add(g),second=add(g),third=add(g);
        first.state=CustomerState.LEAVING;first.departureFrame=-1;
        g.enqueue(third);int oldTarget=g.queue.get(0).node;
        g.tick(.01f);
        check(!g.customers.contains(first)&&second.slot==0&&third.slot==1,"Removing a customer must move later customers into the freed queue positions");
        check(g.queue.size()==1&&g.queue.get(0).customer==third&&g.queue.get(0).node!=oldTarget,"A queued customer action must retarget after its queue position changes");
        Customer cash=second;cash.state=CustomerState.CASH;cash.departureFrame=4;cash.cashCollected=false;
        check(cash.slot==0&&third.slot==1,"An uncollected cash customer must keep its queue slot occupied");
        cash.cashCollected=true;cash.departureFrame=-1;g.tick(.01f);
        check(!g.customers.contains(cash)&&third.slot==0,"Once cash and its puff are complete, the next customer may advance");
    }

    public static void main(String[] args)throws Exception{
        check(args.length>0,"Pass the recovered asset root");
        GameData data=new GameData(path->new FileInputStream(new File(args[0],path)));
        servedCustomerLeavesBodyAndCollectsOnce(data);
        unhappyCustomerLeavesAndChargesOnce(data);
        queuePositionsCompactAndRetarget(data);
        System.out.println("PASS: customer happy/cash and angry departure effects, one-shot payment/penalty, occupied cash slots, queue compaction, and queued-action retargeting");
    }
}
