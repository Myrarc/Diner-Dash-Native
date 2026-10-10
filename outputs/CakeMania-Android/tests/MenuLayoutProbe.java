package local.cakemania;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.os.Bundle;
import java.io.File;
import java.io.FileOutputStream;

/** Button targets must stay centered in the recovered panel rows, including Profiles. */
public final class MenuLayoutProbe extends android.app.Instrumentation {
    private int checks;
    @Override public void onCreate(Bundle args){super.onCreate(args);start();}
    @Override public void onStart(){
        Bundle result=new Bundle();int code=-1;
        try{
            final Throwable[] failure={null};runOnMainSync(()->{try{probe();}catch(Throwable error){failure[0]=error;}});
            if(failure[0]!=null)throw failure[0];
            result.putString("summary","PASS: "+checks+" menu layout checks at 800x600, 1440x1080 and 2280x1080");
        }catch(Throwable error){code=0;result.putString("failure",android.util.Log.getStackTraceString(error));}
        finish(code,result);
    }
    private void check(boolean condition,String message){checks++;if(!condition)throw new AssertionError(message);}
    private void probe()throws Exception{
        MainActivity activity=new MainActivity();activity.data=new GameData(path->getTargetContext().getAssets().open(path));
        AssetStore assets=new AssetStore(getTargetContext());GameView view=new GameView(getTargetContext(),activity,assets);
        Bitmap header=assets.image("IMAGE_BUTTON_MMENU_LAYER0"),row=assets.image("IMAGE_BUTTON_MMENU_LAYER1"),button=assets.image("IMAGE_BUTTON_MMENU_NORMAL");
        check(header.getWidth()==481&&header.getHeight()==168&&row.getHeight()==47&&button.getWidth()==318&&button.getHeight()==39,"Recovered menu dimensions must be the original 47-pixel rows and 318x39 buttons");
        for(int[] size:new int[][]{{800,600},{1440,1080},{2280,1080}})for(String screen:new String[]{"menu","playmenu"}){
            activity.screen=screen;view.layout(0,0,size[0],size[1]);view.rebuildControls();
            int count=screen.equals("menu")?6:4;check(view.controls.size()==count,"Every visible menu choice needs its own row");
            Bitmap image=Bitmap.createBitmap(size[0],size[1],Bitmap.Config.ARGB_8888);view.draw(new Canvas(image));
            try(FileOutputStream out=new FileOutputStream(new File(getTargetContext().getFilesDir(),"menu-layout-"+screen+"-"+size[0]+".png"))){image.compress(Bitmap.CompressFormat.PNG,100,out);}
            for(int i=0;i<count;i++){
                GameView.Control c=view.controls.get(i);float rowTop=184+i*47;
                check(c.w==318&&c.h==39&&c.x+c.w/2==550.5f&&c.y+c.h/2==rowTop+23.5f,"Choice "+c.label+" must be centered in its yellow row, rather than drifting down or overlapping the footer");
                Bitmap nativeRow=assets.image(i%2==0?"IMAGE_BUTTON_MMENU_LAYER1":"IMAGE_BUTTON_MMENU_LAYER2");
                for(int x:new int[]{78,402}){
                    int actual=image.getPixel(Math.round(view.ox+(310+x)*view.scale),Math.round(view.oy+(rowTop+20)*view.scale));
                    int expected=nativeRow.getPixel(x,20);
                    check(colorDistance(actual,expected)<55,"Yellow row artwork must continue beside "+c.label+" at "+size[0]+"x"+size[1]+": "+Integer.toHexString(actual)+" vs "+Integer.toHexString(expected));
                }
            }
            Bitmap footer=assets.image("IMAGE_BUTTON_MMENU_LAYER3");
            int actual=image.getPixel(Math.round(view.ox+360*view.scale),Math.round(view.oy+(184+count*47+70)*view.scale));
            check(colorDistance(actual,footer.getPixel(50,70))<55,"Panel footer must begin after the last button's row");
            image.recycle();
        }
    }
    private static int colorDistance(int a,int b){int d=0;for(int shift:new int[]{0,8,16})d+=Math.abs((a>>shift&255)-(b>>shift&255));return d;}
}
