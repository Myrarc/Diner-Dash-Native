package local.cakemania;

import java.io.*;
import java.util.*;

/** Focused regression checks for native flow data, tutorial gating, and result placeholders. */
public final class FlowRulesTest {
    private static void check(boolean value,String message){if(!value)throw new AssertionError(message);}
    private static int[] formIds(GameEngine.Station station){List<Integer> ids=new ArrayList<>();for(GameData.Node form:station.def.children)if(form.tag.equals("Form"))ids.add(form.i("id",-1));int[] result=new int[ids.size()];for(int i=0;i<result.length;i++)result[i]=ids.get(i);return result;}
    public static void main(String[] args)throws Exception{
        if(args.length>0){
            File root=new File(args[0]);GameData data=new GameData(path->new FileInputStream(new File(root,path)));
            check(data.levels.size()==48&&data.mapLevels().size()==4,"Career and authored map manifests must remain complete");
            check(data.endless.size()==4&&!data.endless.get(0).dataPresent,"Endless mode must expose the manifest boundary when referenced files are absent");
            check(data.comicImages(0).size()==3&&data.comicImages(2).contains("IMAGE_COMICS_2"),"Comic transitions must come from the authored manifest");
            GameData.Level tutorial=data.tutorialLevel();
            check(tutorial.number==0&&tutorial.environment.all("CakeOven").get(0).i("x_global",-1)==365,"Tutorial must use its authored oven room, not January");
            check(tutorial.environment.all("Froster").get(0).i("x_global",-1)==440&&tutorial.environment.all("Trash").get(0).i("x_global",-1)==606,"Tutorial machine coordinates must come from tutorialscreen/level_env.xml");
            check(tutorial.paths.first("Nodes").children.size()==20&&tutorial.paths.first("Nodes").children.get(0).f("x",-1)==310&&tutorial.avatar.first("Avatar").f("speed",0)==2f,"Tutorial must use its authored walking graph and avatar");
            GameData.Node front=tutorial.paths.first("CustomerPath").children.get(0);check(front.i("x",0)==139&&front.i("y_money",0)==496,"Native tutorial customer positions come from the freshly copied career path");
            for(int sequence:new int[]{0,10}){GameData.Node gate=null;for(GameData.Node event:data.tutorialSequence(sequence).all("Event"))if(event.s("type").equals("WaitForClick"))gate=event;float x=gate.f("x",0)+gate.f("w",0)/2,y=gate.f("y",0)+gate.f("h",0)/2;check(x>=front.f("x_money",0)-4&&x<front.f("x_money",0)+46&&y>=front.f("y_money",0)-25&&y<front.f("y_money",0)+25,"The final tutorial cash gate must intersect visible money, instead of completing without collection");}
            GameEngine practice=new GameEngine(data,tutorial,Collections.emptyMap(),7);
            int[] shapeIds=formIds(practice.station("cakeoven0")),frostIds=formIds(practice.station("froster1"));
            check(Arrays.equals(shapeIds,new int[]{7,1,2,3})&&Arrays.equals(frostIds,new int[]{0,3,1,2}),"Tutorial active Form vectors must preserve authored selection order");
            GameData.Node arrival=new GameData.Node("Customer");arrival.attrs.put("guid","tutor");
            GameEngine.Customer tutor=practice.addCustomer(arrival);
            GameEngine.Layer forced=new GameEngine.Layer(shapeIds[0],15);forced.frost=frostIds[3];tutor.order.layers.add(forced);
            check("tutor".equals(tutor.profile.s("guid"))&&tutor.order.layers.size()==1&&tutor.order.layers.get(0).shape==7&&tutor.order.layers.get(0).frost==2,"Tutorial AddCustomer 0,3 must map to producible Triangle/Red forms");
            GameData.Node add10=null;for(GameData.Node event:data.tutorialSequence(10).all("Event"))if(event.s("type").equals("AddCustomer")){add10=event;break;}
            check(add10!=null&&add10.s("text").equals("2,1,3,3,"),"The authored complex tutorial order must remain 2,1,3,3");
            check(shapeIds[2]==2&&frostIds[1]==3&&shapeIds[3]==3&&frostIds[3]==2,"Complex tutorial indices must produce Star/Cream then Circle/Red with the supplied stations");
            check(data.level(1).number==1&&data.level(1).environment!=tutorial.environment,"January must remain a separate normal career level");
        }
        String xml="<root><Sequence><Event type='DrawRectText' id='1' x='10' y='20' w='30' h='40' text='Welcome'/><Event type='DrawArrow' id='1' x='1' y='2' w='3' h='4'/><Event type='Timer' float='1.5'/><Event type='AddCustomer' id='5' text='0,3,'/><Event type='WaitForCustomerClick' id='5'/><Event type='RemoveRectText' id='1'/><Event type='WaitForClick' x='100' y='100' w='20' h='20'/></Sequence></root>";
        TutorialController controller=new TutorialController();List<String> added=new ArrayList<>();
        controller.start(GameData.parse(new ByteArrayInputStream(xml.getBytes("UTF-8"))), (id,order)->added.add(id+":"+order));
        check(controller.overlays().size()==2&&controller.isWaitingForClick()==false,"Script must expose both authored overlays and stop at its timer");
        controller.tick(1.49f);check(added.isEmpty(),"Timer must not fire before its authored duration");
        controller.tick(.01f);check(added.size()==1&&controller.isWaitingForCustomer()&&controller.waitingCustomerId()==5,"Timer must advance to AddCustomer then wait for authored customer id 5");
        check(!controller.customerClick(4),"A different customer cannot bypass the native WaitForCustomerClick gate");
        check(controller.customerClick(5),"The authored customer must release the tutorial gate");
        check(controller.overlays().size()==1&&controller.overlays().get(0).type.equals("DrawArrow")&&controller.isWaitingForClick(),"RemoveRectText must remove only its own overlay before the next click gate");
        check(!controller.click(0,0)&&controller.click(110,110),"WaitForClick must honor the authored rectangle");
        check(controller.complete(),"Tutorial must complete after its final authored event");
        System.out.println("PASS: authored tutorial timer, customer gate, overlay removal, and hit rectangle");
    }
}
