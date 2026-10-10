package local.cakemania;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import static local.cakemania.GameData.*;
import static local.cakemania.GameEngine.*;

/** Audit probes against the source bound to APK 0.1.2; mismatches are reported, never hidden. */
public final class ParityProbe {
    private static void require(boolean condition,String message){if(!condition)throw new AssertionError(message);}
    private static void observation(String id,String expected,String actual,boolean matches){
        System.out.println("{\"id\":\""+id+"\",\"native_expected\":"+expected+",\"apk_source_observed\":"+actual+",\"matches\":"+matches+"}");
    }
    private static Cake cake(int shape,int frost){Cake c=new Cake();Layer l=new Layer(shape,30);l.frost=frost;c.layers.add(l);return c;}
    private static Customer sentinel(GameEngine g){Node p=g.data.profiles.get("boy").copy();p.attrs.put("patience","0");Customer c=new Customer(900,0,p,g.arrivals.get(0));c.state=CustomerState.ORDER;g.customers.add(c);return c;}
    public static void main(String[] args)throws Exception {
        GameData data=new GameData(path->new FileInputStream(new File(args[0],path)));
        GameEngine g=new GameEngine(data,data.level(1),Collections.emptyMap(),123);
        g.tick(1.1f);require(g.customers.size()==1,"Order probe requires January's first arrival");
        Customer c=g.customers.get(0);require(c.state==CustomerState.WAIT_MENU,"Order probe must run before handing out a menu");
        observation("deferred-order", "0", ""+c.order.components(),c.order.components()==0);

        g=new GameEngine(data,data.level(1),Collections.singletonMap("cupcake0",1),124);
        g.elapsed=g.level.duration+1;sentinel(g);
        Station microwave=g.station("cupcake0");require(microwave.enabled(),"Refill probe requires a purchased CookieOven");
        // Reach the final production tick of an exhausted batch without assuming native initial stock.
        microwave.cookies=0;microwave.remaining=.05f;microwave.total=microwave.def.f("time",40);
        g.tick(.05f);
        observation("cupcake-door-transition", "0", ""+microwave.cookies,microwave.cookies==0);

        g=new GameEngine(data,data.level(1),Collections.emptyMap(),125);
        Method choose=GameEngine.class.getDeclaredMethod("choose",String.class,List.class,int.class);choose.setAccessible(true);
        Set<Integer> selected=new TreeSet<>();for(int i=0;i<4096;i++)selected.add((Integer)choose.invoke(g,"1,90;",Arrays.asList(7,1,2,3),1));
        // Native fills missing active IDs with a positive default weight when supplied weight sum is below100.
        observation("missing-weight-candidates", "[1,2,3,7]",selected.toString(),selected.equals(new TreeSet<>(Arrays.asList(1,2,3,7))));

        g=new GameEngine(data,data.level(1),Collections.singletonMap("displaycase0",1),126);
        Station display=g.station("displaycase0");require(display!=null&&display.enabled(),"Impulse probe requires a purchased display case");
        display.cake=cake(7,3);
        Node arrival=g.arrivals.get(0).copy();arrival.attrs.put("get_display","100");arrival.attrs.put("cake","1,100;");arrival.attrs.put("frost","0,100;");
        c=new Customer(901,0,data.profiles.get("boy"),arrival);
        Method generate=GameEngine.class.getDeclaredMethod("generateOrder",Customer.class);generate.setAccessible(true);generate.invoke(g,c);
        require(c.order.layers.size()==1,"Impulse probe requires a single-tier generated order");Layer l=c.order.layers.get(0);
        observation("display-impulse-order", "[7,3]", "["+l.shape+","+l.frost+"]",l.shape==7&&l.frost==3);

        g=new GameEngine(data,data.level(1),Collections.singletonMap("tvset0",1),127);
        Station tv=g.station("tvset0");float configuredX=tv.def.f("x_global",-1);
        require(configuredX==140,"Geometry probe requires the Level1 purchased TV's original x_global=140");
        observation("upgrade-geometry", ""+(int)configuredX,""+(int)tv.x,tv.x==configuredX);
    }
}
