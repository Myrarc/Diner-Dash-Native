import com.libreshockwave.DirectorFile;
import com.libreshockwave.chunks.*;
import com.libreshockwave.cast.BitmapInfo;
import com.libreshockwave.bitmap.BitmapDecoder;
import com.libreshockwave.bitmap.Palette;
import com.libreshockwave.audio.SoundConverter;
import com.libreshockwave.tools.scanning.MemberResolver;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.nio.file.*;
import java.util.*;

// Asset decoding uses LibreShockwave and the MIT shockwave-extractor's
// channel-separated 16-bit decoding. No source cast is modified.
public class ExtractDinerAssets {
    static String safe(String value) { return value.replaceAll("[^a-zA-Z0-9_.-]", "_"); }
    public static void main(String[] args) throws Exception {
        Path source = Path.of(args[0]), output = Path.of(args[1]);
        String cast = args[2];
        DirectorFile file = DirectorFile.load(source);
        DirectorFile sharedPeople = null;
        Path peoplePath = source.getParent().resolve("gfx.people.cst");
        if (Files.exists(peoplePath)) sharedPeople = DirectorFile.load(peoplePath);
        Files.createDirectories(output.resolve("images/" + cast));
        Files.createDirectories(output.resolve("sounds/" + cast));
        StringBuilder inventory = new StringBuilder();
        int errors = 0;
        Map<Integer, Integer> slots = new HashMap<>();
        int min = file.getConfig() == null ? 1 : Math.max(1, file.getConfig().minMember());
        if (!file.getCasts().isEmpty()) {
            var ids = file.getCasts().getFirst().memberIds();
            for (int i = 0; i < ids.size(); i++) if (ids.get(i) > 0) slots.put(ids.get(i), i + min);
        }
        for (CastMemberChunk member : file.getCastMembers()) {
            String name = member.name() == null ? "" : member.name();
            String encoded = Base64.getEncoder().encodeToString(name.getBytes(java.nio.charset.StandardCharsets.UTF_8));
            String path = "", status = "metadata";
            int width = 0, height = 0, depth = 0, rx = 0, ry = 0, rate = 0, bits = 0, channels = 0;
            try {
                if (member.isBitmap()) {
                    BitmapInfo info = BitmapInfo.parse(member.specificData());
                    width = info.width(); height = info.height(); depth = info.bitDepth(); rx = info.regX(); ry = info.regY();
                    if (width == 0 || height == 0) {
                        inventory.append(String.join("\t", cast, Integer.toString(member.id()), Integer.toString(slots.getOrDefault(member.id(), -1)),
                            member.memberType().name(), encoded, "0", "0", Integer.toString(depth), Integer.toString(rx), Integer.toString(ry), "", "empty_bitmap", "0", "0", "0")).append('\n');
                        continue;
                    }
                    BufferedImage image;
                    if (depth == 16 || depth == 8) {
                        BitmapChunk chunk = null;
                        for (var entry : file.getKeyTable().getEntriesForOwner(member.id())) {
                            if (entry.fourccString().equals("BITD") && file.getChunk(entry.sectionId()) instanceof BitmapChunk bitmap) chunk = bitmap;
                        }
                        if (chunk == null) throw new IllegalStateException("No bitmap chunk");
                        int scanWidth = BitmapDecoder.calculateScanWidth(width, depth);
                        if (depth == 8) {
                            Palette palette = file.resolvePalette(info.paletteId());
                            boolean local = file.getCastMembers().stream().anyMatch(m -> m.memberType().name().equals("PALETTE") && slots.getOrDefault(m.id(), -1) == info.paletteId() + 1);
                            if (info.paletteId() >= 0 && !local && sharedPeople != null) palette = sharedPeople.resolvePalette(info.paletteId());
                            image = BitmapDecoder.decode(chunk.data(), width, height, depth, palette, true, true, 1000).toBufferedImage();
                        } else {
                        byte[] pixels = BitmapDecoder.decompressRLE(chunk.data(), scanWidth * height);
                        image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
                        for (int y = 0; y < height; y++) for (int x = 0; x < width; x++) {
                            int hi = y * scanWidth + x, lo = y * scanWidth + width + x;
                            if (lo >= pixels.length) throw new IllegalStateException("Truncated bitmap row");
                            int pixel = ((pixels[hi] & 255) << 8) | (pixels[lo] & 255);
                            int r = ((pixel >> 10) & 31) * 255 / 31;
                            int g = ((pixel >> 5) & 31) * 255 / 31;
                            int b = (pixel & 31) * 255 / 31;
                            int alpha = pixel == 0x7fff ? 0 : 255;
                            image.setRGB(x, y, (alpha << 24) | (r << 16) | (g << 8) | b);
                        }
                        }
                    } else image = file.decodeBitmap(member).orElseThrow(() -> new IllegalStateException("Bitmap decoder returned empty")).toBufferedImage();
                    path = "images/" + cast + "/" + member.id() + "_" + safe(name) + ".png";
                    ImageIO.write(image, "PNG", output.resolve(path).toFile()); status = "exported";
                } else if (member.isSound()) {
                    SoundChunk sound = MemberResolver.findSoundForMember(file, member);
                    if (sound == null) throw new IllegalStateException("No sound chunk");
                    rate = sound.sampleRate(); bits = sound.bitsPerSample(); channels = sound.channelCount();
                    byte[] audio = sound.isMp3() ? SoundConverter.extractMp3(sound) : SoundConverter.toWav(sound);
                    if (audio == null || audio.length == 0) throw new IllegalStateException("Empty audio output");
                    path = "sounds/" + cast + "/" + member.id() + "_" + safe(name) + (sound.isMp3() ? ".mp3" : ".wav");
                    Files.write(output.resolve(path), audio); status = "exported";
                }
            } catch (Exception error) { status = "ERROR:" + safe(error.getMessage() == null ? error.toString() : error.getMessage()); errors++; }
            inventory.append(String.join("\t", cast, Integer.toString(member.id()), Integer.toString(slots.getOrDefault(member.id(), -1)),
                member.memberType().name(), encoded, Integer.toString(width), Integer.toString(height), Integer.toString(depth),
                Integer.toString(rx), Integer.toString(ry), path, status, Integer.toString(rate), Integer.toString(bits), Integer.toString(channels))).append('\n');
        }
        Files.writeString(output.resolve(cast + ".tsv"), inventory);
        System.out.println(cast + ": members=" + file.getCastMembers().size() + ", errors=" + errors);
        if (errors > 0) System.exit(2);
    }
}
