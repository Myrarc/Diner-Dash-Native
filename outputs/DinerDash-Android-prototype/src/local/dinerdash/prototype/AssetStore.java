package local.dinerdash.prototype;

import android.content.Context;
import android.graphics.*;
import android.util.LruCache;
import org.json.*;
import java.io.*;
import java.util.*;

/** Original cast names and registration points remain available in asset-index.json. */
public final class AssetStore {
    private final Context context;
    private final Map<String,JSONObject> members=new HashMap<>();
    private final Map<String,String> aliases=new HashMap<>();
    public final JSONObject layouts;
    public final Typeface komikaAxis,mrB;
    private final LruCache<String,Bitmap> images=new LruCache<String,Bitmap>(32*1024*1024){@Override protected int sizeOf(String key,Bitmap value){return value.getByteCount();}};
    public AssetStore(Context context){this.context=context;try{
        JSONObject index=read("asset-index.json");JSONObject a=index.getJSONObject("cast_aliases");Iterator<String> keys=a.keys();while(keys.hasNext()){String k=keys.next();aliases.put(k,a.getString(k));}
        JSONArray all=index.getJSONArray("members");for(int i=0;i<all.length();i++){JSONObject m=all.getJSONObject(i);String key=m.getString("cast")+":"+m.getString("name");if(m.optString("status").equals("exported")&&!members.containsKey(key))members.put(key,m);}
        layouts=read("layouts.json");
        komikaAxis=Typeface.createFromAsset(context.getAssets(),"fonts/Komika-Axis.ttf");mrB=Typeface.createFromAsset(context.getAssets(),"fonts/Mr.B.ttf");
    }catch(Exception e){throw new IllegalStateException("Cannot load recovered game assets",e);}}
    private JSONObject read(String name)throws Exception{try(InputStream in=context.getAssets().open(name);ByteArrayOutputStream out=new ByteArrayOutputStream()){byte[] b=new byte[16384];int n;while((n=in.read(b))!=-1)out.write(b,0,n);return new JSONObject(out.toString("UTF-8"));}}
    public JSONObject member(String cast,String name){String alias=aliases.containsKey(cast)?aliases.get(cast):cast;JSONObject m=members.get(alias+":"+name);return m!=null?m:members.get(cast+":"+name);}
    public String sound(String name){JSONObject m=member("sfx",name);return m==null?null:m.optString("path");}
    public Bitmap bitmap(String cast,String name,boolean transparent){String key=cast+":"+name+":"+transparent;Bitmap cached=images.get(key);if(cached!=null)return cached;JSONObject m=member(cast,name);if(m==null)return null;
        try(InputStream in=context.getAssets().open(m.getString("path"))){Bitmap decoded=BitmapFactory.decodeStream(in);if(decoded==null)return null;
            if(transparent){decoded=decoded.copy(Bitmap.Config.ARGB_8888,true);int w=decoded.getWidth(),h=decoded.getHeight();int[] pixels=new int[w*h];decoded.getPixels(pixels,0,w,0,0,w,h);
                String maskName="mask_"+name;
                if(member(cast,maskName)==null)maskName=name+"_mask";
                if(member(cast,maskName)==null&&cast.equals("gfx.screens")){if(name.startsWith("button_hiscore"))maskName=name.endsWith("_on")?"mask_menu_hiscorebutton_rollover":"mask_menu_hiscorebutton";else if(name.startsWith("button_options"))maskName=name.endsWith("_on")?"mask_menu_options_rollover":"mask_menu_options";else if(name.equals("button_endless_on"))maskName="button_endless_mask";}
                Bitmap mask=member(cast,maskName)==null?null:bitmap(cast,maskName,false);
                if(mask!=null){if(mask.getWidth()!=w||mask.getHeight()!=h)mask=Bitmap.createScaledBitmap(mask,w,h,true);int[] matte=new int[w*h];mask.getPixels(matte,0,w,0,0,w,h);for(int i=0;i<pixels.length;i++){int alpha=Color.alpha(pixels[i])*(255-Color.red(matte[i]))/255;pixels[i]=(pixels[i]&0xffffff)|(alpha<<24);}}
                else {boolean opaque=true;for(int pixel:pixels)if(Color.alpha(pixel)!=255){opaque=false;break;}
                    // Exported alpha already defines the matte, including white ON/OFF glyphs.
                    if(opaque)for(int i=0;i<pixels.length;i++){int rgb=pixels[i]&0xffffff;if(rgb==0xff00ff||rgb==0xffffff)pixels[i]=0;}}
                decoded.setPixels(pixels,0,w,0,0,w,h);}
            images.put(key,decoded);return decoded;
        }catch(Exception e){throw new IllegalStateException("Cannot decode asset "+cast+":"+name,e);}}
    public JSONObject layout(String name){return layouts.optJSONObject(name+"_layout");}
    public static List<JSONObject> children(JSONObject node){List<JSONObject> result=new ArrayList<>();if(node==null)return result;JSONObject c=node.optJSONObject("children");if(c==null)return result;Iterator<String> keys=c.keys();while(keys.hasNext()){String key=keys.next();if(!key.equals("__duplicate_entries__")){JSONObject v=c.optJSONObject(key);if(v!=null)result.add(v);}}
        JSONArray dup=c.optJSONArray("__duplicate_entries__");if(dup!=null)for(int i=0;i<dup.length();i++){JSONArray pair=dup.optJSONArray(i);if(pair!=null&&pair.optJSONObject(1)!=null)result.add(pair.optJSONObject(1));}return result;}
    public static JSONObject frame(JSONObject node,String animation,long time,long frameMS){if(node==null)return null;JSONArray frames=node.optJSONArray("frames");if(frames==null||frames.length()==0)return null;List<JSONObject> matching=new ArrayList<>();for(int i=0;i<frames.length();i++){JSONObject f=frames.optJSONObject(i);if(f!=null&&(animation==null||f.optString("animID").equals(animation)))matching.add(f);}if(matching.isEmpty())return frames.optJSONObject(0);return matching.get((int)(time/Math.max(1,frameMS)%matching.size()));}
    public static float value(JSONObject f,String key,int index,float fallback){JSONObject p=f==null?null:f.optJSONObject(key);JSONArray values=p==null?null:p.optJSONArray("values");return values==null?fallback:(float)values.optDouble(index,fallback);}
    public static JSONObject child(JSONObject node,String key){JSONObject c=node==null?null:node.optJSONObject("children");return c==null?null:c.optJSONObject(key);}
}
