package local.cakemania;

import java.util.*;

/**
 * Executes the authored TutorialScreen event stream.  The controller owns
 * sequencing and input gates; a renderer can draw the exposed overlays and
 * route its real hit rectangles through click/customerClick.
 */
public final class TutorialController {
    public interface Host { void addCustomer(int id,String orderText); }
    public static final class Overlay {
        public final int id;
        public final String type,text;
        public final float x,y,w,h,angle;
        Overlay(int id,String type,String text,float x,float y,float w,float h,float angle){this.id=id;this.type=type;this.text=text;this.x=x;this.y=y;this.w=w;this.h=h;this.angle=angle;}
    }
    private final List<GameData.Node> events=new ArrayList<>();
    private final Map<String,Overlay> overlays=new LinkedHashMap<>();
    private int index;
    private float timer;
    private boolean waitingTimer,waitingClick,waitingCustomer,complete;
    private int waitingCustomerId=-1;
    private GameData.Node current;
    private Host host;

    public void start(GameData.Node document,Host host){start(document,host,0);}
    public void start(GameData.Node document,Host host,int initialIndex){
        events.clear();overlays.clear();index=0;timer=0;waitingTimer=false;waitingClick=false;waitingCustomer=false;waitingCustomerId=-1;complete=false;current=null;this.host=host;
        if(document!=null){GameData.Node sequence=document.tag.equals("Sequence")?document:document.first("Sequence");if(sequence!=null)events.addAll(sequence.children);}
        int target=Math.max(0,Math.min(events.size(),initialIndex));
        while(index<target){apply(events.get(index),false);index++;}
        advance();
    }
    public boolean running(){return !complete&&!events.isEmpty();}
    public boolean complete(){return complete;}
    public int eventIndex(){return index;}
    public List<Overlay> overlays(){return Collections.unmodifiableList(new ArrayList<>(overlays.values()));}
    public GameData.Node currentEvent(){return current;}
    public boolean isWaitingForClick(){return waitingClick;}
    public boolean isWaitingForCustomer(){return waitingCustomer;}
    /** Authored profile/event id, which is distinct from the runtime customer serial. */
    public int waitingCustomerId(){return waitingCustomer?waitingCustomerId:-1;}

    public void tick(float dt){
        if(complete||dt<=0)return;
        if(waitingTimer){timer+=dt;if(timer>=current.f("float",0)){waitingTimer=false;timer=0;index++;advance();}}
    }
    public boolean click(float x,float y){
        if(!waitingClick||current==null)return false;
        float left=current.f("x",0),top=current.f("y",0),right=left+current.f("w",0),bottom=top+current.f("h",0);
        if(x<left||x>right||y<top||y>bottom)return false;
        waitingClick=false;index++;advance();return true;
    }
    public boolean customerClick(int id){
        if(!waitingCustomer||id!=waitingCustomerId)return false;
        waitingCustomer=false;waitingCustomerId=-1;index++;advance();return true;
    }
    public void skip(){if(!complete){waitingClick=false;waitingCustomer=false;waitingTimer=false;index=events.size();complete=true;current=null;overlays.clear();}}
    private void advance(){
        waitingClick=false;waitingCustomer=false;waitingCustomerId=-1;current=null;
        while(index<events.size()){
            GameData.Node event=events.get(index);String type=event.s("type");current=event;
            if(type.equals("Timer")){waitingTimer=true;timer=0;return;}
            if(type.equals("WaitForClick")){waitingClick=true;return;}
            if(type.equals("WaitForCustomerClick")){waitingCustomer=true;waitingCustomerId=event.i("id",-1);return;}
            apply(event,true);
            index++;
        }
        complete=true;current=null;
    }
    private void apply(GameData.Node event,boolean emitCustomer){
        String type=event.s("type");
        if(type.equals("DrawRectText")){int id=event.i("id",-1);overlays.put(key("DrawRectText",id),new Overlay(id,type,event.s("text"),event.f("x",0),event.f("y",0),event.f("w",0),event.f("h",0),0));}
        else if(type.equals("DrawArrow")){int id=event.i("id",-1);overlays.put(key("DrawArrow",id),new Overlay(id,type,"",event.f("x",0),event.f("y",0),event.f("w",0),event.f("h",0),event.f("float",0)));}
        else if(type.equals("RemoveRectText"))overlays.remove(key("DrawRectText",event.i("id",-1)));
        else if(type.equals("RemoveArrow"))overlays.remove(key("DrawArrow",event.i("id",-1)));
        else if(type.equals("AddCustomer")&&emitCustomer&&host!=null)host.addCustomer(event.i("id",-1),event.s("text"));
    }
    private static String key(String type,int id){return type+":"+id;}
}
