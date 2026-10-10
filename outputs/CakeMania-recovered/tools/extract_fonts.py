#!/usr/bin/env python3
"""Export this game's bitmap font metrics while preserving the original atlases."""
import ast
import json
from pathlib import Path
import re
import sys
from PIL import Image

root = Path(sys.argv[1])
source = root / 'data/images/fonts'
target = root / 'font-data'
target.mkdir(exist_ok=True)
summary = []
for path in sorted(source.glob('*.txt')):
    text = path.read_text(encoding='cp1252')
    values = {}
    for name in ['CharList', 'WidthList', 'RectList', 'OffsetList', 'KerningPairs', 'KerningValues']:
        match = re.search(r'Define\s+' + name + r'\s+(\(.*?\));', text, re.S)
        if match:
            value = ast.literal_eval(match.group(1))
            values[name] = value if isinstance(value, tuple) else (value,)
    atlas_name = re.search(r"LayerSetImage\s+Main\s+'([^']+)'", text).group(1)
    image_path = source / ('_' + atlas_name + '.png')
    with Image.open(image_path) as image:
        size, mode = image.size, image.mode
    assert len(values['CharList']) == len(values['WidthList']) == len(values['RectList']) == len(values['OffsetList'])
    for x, y, width, height in values['RectList']:
        assert x >= 0 and y >= 0 and x + width <= size[0] and y + height <= size[1], (path.name, (x, y, width, height), size)
    assert len(values.get('KerningPairs', ())) == len(values.get('KerningValues', ()))
    glyphs = [{'char': char, 'codepoint': ord(char), 'advance': width, 'rect': rect, 'offset': offset}
              for char, width, rect, offset in zip(values['CharList'], values['WidthList'], values['RectList'], values['OffsetList'])]
    metrics = {name: int(value) for name, value in re.findall(r'LayerSet(Ascent|AscentPadding|LineSpacingOffset|PointSize)\s+Main\s+(-?\d+)', text)}
    space = re.search(r"LayerSetCharWidths\s+Main\s+\(' '\)\s+\((\d+)\)", text)
    data = {'name': path.stem, 'source': str(path.relative_to(root)),
            'source_character_decoding': 'Windows-1252; ASCII mapping directly preserved',
            'atlas': str(image_path.relative_to(root)), 'atlas_size': size, 'atlas_mode': mode,
            'metrics': metrics, 'space_advance': int(space.group(1)) if space else None,
            'glyphs': glyphs, 'kerning': list(zip(values.get('KerningPairs', ()), values.get('KerningValues', ())))}
    (target / (path.stem + '.json')).write_text(json.dumps(data, indent=2, ensure_ascii=False) + '\n')
    summary.append({'font': path.stem, 'glyphs': len(glyphs), 'kerning_pairs': len(data['kerning']), 'atlas': data['atlas'], 'mode': mode})
(root / 'font-verification.json').write_text(json.dumps({
    'checked': len(summary), 'failed': 0,
    'checks': 'Matched character, width, rectangle, and offset counts; checked all glyph rectangles against their atlases and kerning pair/value counts. Windows-1252 interpretation of non-ASCII bytes has not been compared with the original runtime.',
    'fonts': summary}, indent=2) + '\n')
print(f'Exported {len(summary)} bitmap font definitions; all glyph bounds and metric counts verified')
