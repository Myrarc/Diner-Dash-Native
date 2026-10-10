# Asset recovery provenance

The APK already includes the exported media and parsed configurations. These tools are optional for repeating extraction; they are not needed to build the APK.

- LibreShockwave: https://github.com/bmdragos/LibreShockwave, commit `b114ae65ec6acd1e576ba5dc37a4f7ace113cb45` (as used by shockwave-extractor's submodule).
- shockwave-extractor: https://github.com/bmdragos/shockwave-extractor. Its MIT license accompanies the channel-separated 16-bit decoding adapted in `ExtractDinerAssets.java`.
- `lingo_data.py` parses serialized recovered Lingo values deterministically.
- `import_diner_assets.py` reads rebuilt containers from the separate recovered deliverable and writes media/config/layout inventories. Set `DINER_RECOVERY` to the extracted `DinerDash-recovered` folder and `DINER_IMPORT_WORK` to a scratch folder containing `director-sdk-classes` compiled from the pinned SDK, its `MemberResolver`, and `ExtractDinerAssets.java`. Java 21 is required.
- `verify_assets.py` checks PNG dimensions/integrity/hashes and fully decodes MP3s with FFmpeg/FFprobe. It requires Pillow and those commands.

The extractor resolves local customer palettes or the shared `gfx.people` palette, preserving cast member names, registration points and member/chunk identifiers. Legacy font, shape and film-loop members are retained in the recovered Director containers; this APK uses native fonts and controls.
