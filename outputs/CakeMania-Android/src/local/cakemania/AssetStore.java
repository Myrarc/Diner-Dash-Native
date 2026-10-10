package local.cakemania;

import android.content.Context;
import android.graphics.*;
import android.util.LruCache;
import java.io.*;
import java.util.*;
import org.json.*;
import static local.cakemania.GameData.*;

public final class AssetStore {
    private final Context context;
    public final Map<String,String> paths=new LinkedHashMap<>();
    private final LruCache<String,Bitmap> bitmaps=new LruCache<String,Bitmap>(24*1024*1024){protected int sizeOf(String k,Bitmap b){return b.getByteCount();}};
    private final LruCache<String,Bitmap> frames=new LruCache<String,Bitmap>(12*1024*1024){protected int sizeOf(String k,Bitmap b){return b.getByteCount();}};
    private final Map<String,BitmapFont> fonts=new HashMap<>();
    public AssetStore(Context context) throws Exception {this.context=context;try(InputStream in=context.getAssets().open("resources.xml")){for(Node n:GameData.parse(in).children)paths.put(n.s("id"),n.s("path"));}}
    public Bitmap image(String id){return bitmap(paths.containsKey(id)?paths.get(id):id);}
    private Bitmap bitmap(String path){Bitmap b=bitmaps.get(path);if(b!=null)return b;try(InputStream in=context.getAssets().open(path)){BitmapFactory.Options o=new BitmapFactory.Options();o.inScaled=false;b=BitmapFactory.decodeStream(in,null,o);if(b==null)throw new IOException("Unsupported image "+path);
            // The original font atlases store coverage in RGB on an opaque black background.
            if(path.startsWith("original/fonts/_")){int[] pixels=new int[b.getWidth()*b.getHeight()];b.getPixels(pixels,0,b.getWidth(),0,0,b.getWidth(),b.getHeight());for(int i=0;i<pixels.length;i++)pixels[i]=((pixels[i]>>>16&255)<<24)|0xffffff;b=Bitmap.createBitmap(pixels,b.getWidth(),b.getHeight(),Bitmap.Config.ARGB_8888);}
            bitmaps.put(path,b);return b;}catch(IOException e){throw new IllegalStateException("Missing recovered image: "+path,e);}}
    public Bitmap frame(String id,int cols,int rows,int number){int n=Math.floorMod(number,cols*rows);String key=id+":"+cols+":"+rows+":"+n;Bitmap f=frames.get(key);if(f!=null)return f;Bitmap b=image(id);int w=b.getWidth()/cols,h=b.getHeight()/rows;f=Bitmap.createBitmap(b,n%cols*w,n/cols*h,w,h);frames.put(key,f);return f;}
    public void draw(Canvas c,String id,float x,float y){c.drawBitmap(image(id),x,y,null);}
    public void draw(Canvas c,String id,float x,float y,float w,float h){c.drawBitmap(image(id),null,new RectF(x,y,x+w,y+h),null);}
    public BitmapFont font(String name){if(!fonts.containsKey(name))try{fonts.put(name,new BitmapFont(name));}catch(Exception e){throw new IllegalStateException("Could not load original font "+name,e);}return fonts.get(name);}
    public final class BitmapFont {
        private final Map<Character,JSONObject> glyphs=new HashMap<>();
        private final Map<String,Integer> kerning=new HashMap<>();
        private final Bitmap atlas;
        private final int height,space,ascent;
        BitmapFont(String name) throws Exception {
            String json;try(InputStream in=context.getAssets().open("font-data/"+name+".json")){ByteArrayOutputStream out=new ByteArrayOutputStream();byte[] b=new byte[4096];int n;while((n=in.read(b))!=-1)out.write(b,0,n);json=out.toString("UTF-8");}
            JSONObject o=new JSONObject(json);String path=o.getString("atlas").replace("data/images/","original/");atlas=bitmap(path);height=atlas.getHeight();space=o.getInt("space_advance");ascent=o.getJSONObject("metrics").optInt("Ascent",height);
            JSONArray g=o.getJSONArray("glyphs");for(int i=0;i<g.length();i++){JSONObject a=g.getJSONObject(i);glyphs.put((char)a.getInt("codepoint"),a);}
            JSONArray k=o.getJSONArray("kerning");for(int i=0;i<k.length();i++){JSONArray a=k.getJSONArray(i);kerning.put(a.getString(0),a.getInt(1));}
        }
        public float width(String text,float size){float advance=0;for(int i=0;i<text.length();i++){JSONObject g=glyphs.get(text.charAt(i));advance+=g==null?space:g.optInt("advance",space);if(i>0)advance+=kerning.containsKey(text.substring(i-1,i+1))?kerning.get(text.substring(i-1,i+1)):0;}return advance*size/height;}
        public void draw(Canvas c,String text,float x,float top,float size,int color){Paint p=new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG);p.setColorFilter(new PorterDuffColorFilter(color,PorterDuff.Mode.SRC_IN));float scale=size/height;
            for(int i=0;i<text.length();i++){char ch=text.charAt(i);if(i>0&&kerning.containsKey(text.substring(i-1,i+1)))x+=kerning.get(text.substring(i-1,i+1))*scale;JSONObject g=glyphs.get(ch);if(g==null){x+=space*scale;continue;}JSONArray r=g.optJSONArray("rect"),off=g.optJSONArray("offset");int gx=r.optInt(0),gy=r.optInt(1),w=r.optInt(2),h=r.optInt(3);float dx=x+off.optInt(0)*scale,dy=top+off.optInt(1)*scale;c.drawBitmap(atlas,new Rect(gx,gy,gx+w,gy+h),new RectF(dx,dy,dx+w*scale,dy+h*scale),p);x+=g.optInt("advance",space)*scale;}
        }
        public void center(Canvas c,String text,float x,float y,float size,int color){draw(c,text,x-width(text,size)/2,y,size,color);}
        public void baseline(Canvas c,String text,float x,float y,int color){draw(c,text,x,y-ascent,height,color);}
        public void baselineScreen(Canvas c,String text,float x,float y,double scale,int color){drawScreen(c,text,x,y-(int)(ascent*scale),scale,color);}
        public float wrap(Canvas c,String text,float x,float top,float width,float size,int color){float y=top;for(String para:text.split("\n",-1)){String line="";for(String word:para.split(" ")){if(!line.isEmpty()&&width(line+" "+word,size)>width){draw(c,line,x,y,size,color);y+=size+5;line=word;}else line+=line.isEmpty()?word:" "+word;}draw(c,line,x,y,size,color);y+=size+5;}return y;}
        // Native ImageFont scales into an integer atlas (004ab650) and converts
        // each advance/kerning separately (0049fc20), using truncation. Keeping
        // fractional advances changes paragraph wrapping in long month intros.
        public void wrapScreen(Canvas c,String text,float x,float top,float width,double scale,int spacing,int color){
            float y=top;int step=(int)(height*scale)+spacing;
            for(String para:text.split("\n",-1)){String line="";for(String word:para.split(" ")){if(!line.isEmpty()&&screenWidth(line+" "+word,scale)>width){drawScreen(c,line,x,y,scale,color);y+=step;line=word;}else line+=line.isEmpty()?word:" "+word;}drawScreen(c,line,x,y,scale,color);y+=step;}
        }
        private int screenWidth(String text,double scale){int advance=0;for(int i=0;i<text.length();i++){JSONObject g=glyphs.get(text.charAt(i));advance+=(int)((g==null?space:g.optInt("advance",space))*scale);if(i>0)advance+=(int)(kerning.getOrDefault(text.substring(i-1,i+1),0)*scale);}return advance;}
        private void drawScreen(Canvas c,String text,float x,float top,double scale,int color){
            Paint p=new Paint(Paint.ANTI_ALIAS_FLAG|Paint.FILTER_BITMAP_FLAG);p.setColorFilter(new PorterDuffColorFilter(color,PorterDuff.Mode.SRC_IN));
            for(int i=0;i<text.length();i++){
                if(i>0)x+=(int)(kerning.getOrDefault(text.substring(i-1,i+1),0)*scale);
                JSONObject g=glyphs.get(text.charAt(i));if(g==null){x+=(int)(space*scale);continue;}
                JSONArray r=g.optJSONArray("rect"),off=g.optJSONArray("offset");int gx=r.optInt(0),gy=r.optInt(1),w=r.optInt(2),h=r.optInt(3);
                float dx=x+(int)(off.optInt(0)*scale),dy=top+(int)(off.optInt(1)*scale);
                c.drawBitmap(atlas,new Rect(gx,gy,gx+w,gy+h),new RectF(dx,dy,dx+(int)(w*scale),dy+(int)(h*scale)),p);x+=(int)(g.optInt("advance",space)*scale);
            }
        }
    }
}
