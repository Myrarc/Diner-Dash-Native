package local.cakemania;

import java.io.*;
import java.util.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;

/** Original configuration values, adapted only from TinyXML syntax to standard XML. */
public final class GameData {
    public interface Source { InputStream open(String path) throws IOException; }
    public static final class Node {
        public final String tag;
        public final Map<String,String> attrs=new LinkedHashMap<>();
        public final List<Node> children=new ArrayList<>();
        Node(String name){tag=name;}
        public String s(String key){return attrs.containsKey(key)?attrs.get(key):"";}
        public String s(String key,String fallback){return attrs.containsKey(key)?attrs.get(key):fallback;}
        public int i(String key,int fallback){return Math.round(f(key,fallback));}
        public float f(String key,float fallback){try{return Float.parseFloat(s(key).replaceAll("[fF]$",""));}catch(NumberFormatException e){return fallback;}}
        public Node first(String name){for(Node n:children)if(n.tag.equals(name))return n;return null;}
        public List<Node> all(String name){List<Node> result=new ArrayList<>();for(Node n:children){if(n.tag.equals(name))result.add(n);result.addAll(n.all(name));}return result;}
        public Node copy(){Node n=new Node(tag);n.attrs.putAll(attrs);for(Node c:children)n.children.add(c.copy());return n;}
        public void merge(Node upgrade){attrs.putAll(upgrade.attrs);if(!upgrade.children.isEmpty()){children.clear();for(Node c:upgrade.children)children.add(c.copy());}}
    }
    public static final class Level {
        public final int number,bakery,month,goal;
        public final String name,bakeryName,music,intro,success,failure;
        public final float duration;
        public final Node environment,paths,avatar,lineup,shop;
        /** Authored screen nodes, retained for the native result/map renderer. */
        public final Node startScreen,successScreen,failureScreen;
        Level(int number,Node bakery,Node month,GameData data) throws Exception {
            this.number=number;this.bakery=(number-1)/12+1;this.month=(number-1)%12;
            name=month.s("name");bakeryName=bakery.s("name");goal=month.i("bk_goal",200);duration=month.f("end_time",160);music=month.s("music");
            environment=data.readConfig(month.s("name_xml_stuff"));paths=data.readConfig(bakery.s("name_xml_pathes"));avatar=data.readConfig(bakery.s("name_xml_avatar"));shop=data.readConfig(bakery.s("name_xml_upgrades")).first("LevelAddEnv");
            if(shop==null||shop.children.isEmpty())throw new IOException("Missing shop upgrades for bakery "+this.bakery);
            Node selected=null;for(Node n:data.readConfig(bakery.s("name_xml_customers")).all("Level"))if(n.i("id",-1)==this.month)selected=n;
            if(selected==null)throw new IOException("Missing customer schedule for "+number);lineup=selected;
            Node screens=data.readConfig("level"+this.bakery+"/level_screens.xml"),screen=null;
            for(Node n:screens.all("SubLevel"))if(n.i("id",-1)==this.month)screen=n;
            if(screen==null)throw new IOException("Missing month text for "+number);
            startScreen=copyOrNull(screen.first("StartScreen"));
            successScreen=copyOrNull(screen.first("EndScreenSuccess"));
            failureScreen=copyOrNull(screen.first("EndScreenFailed"));
            intro=firstText(startScreen);success=firstText(successScreen);failure=firstText(failureScreen);
        }
        private Level(int number,int bakery,int month,int goal,String name,String bakeryName,String music,float duration,
                      Node environment,Node paths,Node avatar,Node lineup,Node shop,
                      Node startScreen,Node successScreen,Node failureScreen){
            this.number=number;this.bakery=bakery;this.month=month;this.goal=goal;
            this.name=name;this.bakeryName=bakeryName;this.music=music;this.duration=duration;
            this.environment=environment;this.paths=paths;this.avatar=avatar;this.lineup=lineup;this.shop=shop;
            this.startScreen=startScreen;this.successScreen=successScreen;this.failureScreen=failureScreen;
            this.intro=firstText(startScreen);this.success=firstText(successScreen);this.failure=firstText(failureScreen);
        }
        private static Node copyOrNull(Node node){return node==null?null:node.copy();}
        private static String firstText(Node screen){if(screen==null)return "";for(Node n:screen.children)if(n.tag.equals("Text"))return n.s("text");return "";}
    }
    /** A level declaration from the supplied endless-mode manifest. */
    public static final class EndlessDefinition {
        public final int bakery;
        public final String name,music,environment,customersEasy,customersNormal,customersHard;
        public final boolean dataPresent;
        EndlessDefinition(int bakery,Node level,GameData data){
            this.bakery=bakery;name=level.s("name");
            Node month=level.first("SubLevel");
            music=month==null?"":month.s("music");
            environment=month==null?"":month.s("name_xml_stuff");
            customersEasy=level.s("name_xml_customers_easy");customersNormal=level.s("name_xml_customers_normal");customersHard=level.s("name_xml_customers_hard");
            dataPresent=data.hasConfig(environment)&&data.hasConfig(customersEasy)&&data.hasConfig(customersNormal)&&data.hasConfig(customersHard);
        }
    }
    private final Source source;
    private final Map<String,Node> configs=new HashMap<>();
    public final Map<String,Node> profiles=new LinkedHashMap<>();
    public final Map<Integer,Node> cakes=new HashMap<>();
    public final List<Level> levels=new ArrayList<>();
    public final List<EndlessDefinition> endless=new ArrayList<>();
    public final List<Node> mapLevels=new ArrayList<>();
    public GameData(Source source) throws Exception {
        this.source=source;
        for(Node n:readConfig("mainconfig/customers.xml").all("Customer"))profiles.put(n.s("guid"),n);
        for(Node n:readConfig("mainconfig/cakes.xml").all("Cake"))cakes.put(n.i("id",-1),n);
        int endlessBakery=0;
        for(Node n:readConfig("mainconfig/levels_endless.xml").all("Level"))endless.add(new EndlessDefinition(endlessBakery++,n,this));
        for(Node n:readConfig("mapscreen/map_env.xml").all("Level"))mapLevels.add(n.copy());
        for(int stage=1;stage<=4;stage++)for(Node b:readConfig("level"+stage+"/level_definitions.xml").all("Level"))for(Node m:b.children)if(m.tag.equals("SubLevel"))levels.add(new Level(levels.size()+1,b,m,this));
        if(levels.size()!=48)throw new IOException("Expected 48 career months");
    }
    public Level level(int number){if(number<1||number>levels.size())throw new IllegalArgumentException("Invalid month");return levels.get(number-1);}
    /**
     * The native tutorial is a separate room.  It uses its own environment,
     * navigation graph and Jill avatar. Native 0041c210 loads the customer
     * positions from a fresh career-level copy (00421d30); its earlier edit
     * of the copied path filename is discarded. Customer schedules stay separate.
     */
    public Level tutorialLevel() throws Exception {
        Node environment=readConfig("tutorialscreen/level_env.xml").copy();
        Node paths=readConfig("tutorialscreen/pathes.xml").copy();
        Node customerPath=paths.first("CustomerPath");customerPath.children.clear();
        for(Node point:level(1).paths.first("CustomerPath").children)customerPath.children.add(point.copy());
        Node avatar=readConfig("tutorialscreen/avatar.xml").copy();
        Node lineup=new Node("Level");lineup.attrs.put("max_on_level","0");
        Node shop=level(1).shop.copy();
        return new Level(0,1,0,0,"Tutorial","Tutorial","music/c.ogg",Float.POSITIVE_INFINITY,
            environment,paths,avatar,lineup,shop,null,null,null);
    }
    public boolean hasConfig(String path){if(path==null||path.isEmpty())return false;try{readConfig(path);return true;}catch(Exception ignored){return false;}}
    public Node tutorialSequence(int id)throws Exception{
        Node levels=readConfig("tutorialscreen/levels.xml");
        for(Node n:levels.all("Level"))if(n.i("id",-1)==id&&!n.s("seq").isEmpty())return readConfig(n.s("seq"));
        return null;
    }
    public List<String> comicImages(int bakery){
        List<String> result=new ArrayList<>();
        try{for(Node n:readConfig("comicsscreen/comics_screen.xml").all("Screen"))if(n.i("idlevel",-1)==bakery&&!n.s("img").isEmpty())result.add(n.s("img"));}catch(Exception ignored){}
        return result;
    }
    public List<Node> mapLevels(){return Collections.unmodifiableList(mapLevels);}
    public Node readConfig(String path) throws Exception {String key=path.toLowerCase(Locale.ROOT);if(!configs.containsKey(key))try(InputStream in=source.open("config/"+key)){configs.put(key,parse(in));}return configs.get(key);}
    public static Node parse(InputStream in) throws Exception {
        DocumentBuilderFactory f=DocumentBuilderFactory.newInstance();f.setExpandEntityReferences(false);
        DocumentBuilder builder=f.newDocumentBuilder();
        builder.setEntityResolver((publicId,systemId)->{throw new org.xml.sax.SAXException("External XML entities are not allowed");});
        return node(builder.parse(in).getDocumentElement());
    }
    private static Node node(Element e){Node n=new Node(e.getTagName());NamedNodeMap a=e.getAttributes();for(int i=0;i<a.getLength();i++)n.attrs.put(a.item(i).getNodeName(),a.item(i).getNodeValue());NodeList children=e.getChildNodes();for(int i=0;i<children.getLength();i++)if(children.item(i) instanceof Element)n.children.add(node((Element)children.item(i)));return n;}
}
