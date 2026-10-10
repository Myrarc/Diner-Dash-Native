#!/usr/bin/env python3
"""Recover this Cake Mania build's DAT entries without changing original files.

Native evidence: 0x4d0810 reads the directory, 0x4d1760 reads its XML entries,
0x4d0970 reads a member, and 0x52b8f0 performs CryptoAPI RC4 then zlib.
The password literal at 0x58c790 is hashed with MD5. The Base provider uses
five digest bytes followed by eleven zero salt bytes as the RC4 key.
"""
from pathlib import Path, PurePosixPath
import argparse
from collections import Counter
import hashlib
import json
import struct
import xml.etree.ElementTree as ET
import zlib

PASSWORD = b'Error reading stream file data pcK'
KEY = hashlib.md5(PASSWORD).digest()[:5] + bytes(11)
MAX_MEMBER = 16 * 1024 * 1024


def rc4(data, key=KEY):
    state = list(range(256))
    j = 0
    for i in range(256):
        j = (j + state[i] + key[i % len(key)]) & 255
        state[i], state[j] = state[j], state[i]
    output = bytearray(len(data))
    i = j = 0
    for n, value in enumerate(data):
        i = (i + 1) & 255
        j = (j + state[i]) & 255
        state[i], state[j] = state[j], state[i]
        output[n] = value ^ state[(state[i] + state[j]) & 255]
    return bytes(output)


def decode(block, limit):
    stream = zlib.decompressobj()
    raw = stream.decompress(rc4(block), limit + 1)
    if len(raw) > limit or not stream.eof or stream.unused_data or stream.unconsumed_tail:
        raise ValueError('Invalid, truncated, oversized, or trailing compressed data')
    return raw


def member_path(path, name):
    value = PurePosixPath((path + name).replace('\\', '/'))
    if not name or value.is_absolute() or '..' in value.parts or ':' in str(value):
        raise ValueError('Unsafe archive member path')
    return value


def extract(archive, destination):
    data = archive.read_bytes()
    if len(data) < 4:
        raise ValueError('Missing archive header')
    table_size = struct.unpack_from('<I', data)[0]
    base = table_size + 4
    if not 0 < table_size < len(data) - 4:
        raise ValueError('Directory range is outside the archive')
    directory = decode(data[4:base], 1024000)
    # The game's archive XML includes a final 0xff byte. Preserve it on disk.
    xml = directory[:-1] if directory.endswith(b'\xff') else directory
    root = ET.fromstring(xml)
    if root.tag != 'root' or any(node.tag != 'file' for node in root):
        raise ValueError('Unexpected directory schema')
    entries = []
    seen = set()
    position = 0
    for node in root:
        path = member_path(node.attrib['path'], node.attrib['name'])
        start, size, real = (int(node.attrib[k]) for k in ('position', 'size', 'real_size'))
        if path in seen or start != position or size <= 0 or not 0 <= real <= MAX_MEMBER or base + start + size > len(data):
            raise ValueError(f'Invalid or overlapping member: {path}')
        seen.add(path)
        raw = decode(data[base + start:base + start + size], real)
        if len(raw) != real:
            raise ValueError(f'Decoded member size mismatch: {path}')
        target = destination.joinpath(*path.parts)
        target.parent.mkdir(parents=True, exist_ok=True)
        if target.exists() and target.read_bytes() != raw:
            raise ValueError(f'Refusing to replace different recovered content: {target}')
        target.write_bytes(raw)
        entries.append({'path': str(path), 'position': start, 'compressed_bytes': size,
                        'bytes': real, 'sha256': hashlib.sha256(raw).hexdigest()})
        position += size
    if base + position != len(data):
        raise ValueError('Archive has unaccounted payload bytes')
    return directory, {'archive': archive.name, 'sha256': hashlib.sha256(data).hexdigest(),
                       'bytes': len(data), 'directory_bytes': table_size, 'entries': entries,
                       'extensions': dict(Counter(Path(x['path']).suffix for x in entries))}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('game_directory', type=Path)
    parser.add_argument('output_directory', type=Path)
    args = parser.parse_args()
    assert rc4(b'Plaintext', b'Key').hex() == 'bbf316e8d940af0ad3', 'RC4 known-answer check failed'
    assert member_path('MainConfig/', 'customers.xml') == PurePosixPath('MainConfig/customers.xml')
    for unsafe in ('../escape', '/absolute', 'C:\\escape'):
        try:
            member_path('', unsafe)
        except ValueError:
            pass
        else:
            raise AssertionError('Member path validation failed')
    directories = args.output_directory / 'archive-directories'
    directories.mkdir(parents=True, exist_ok=True)
    reports = []
    for name in ('config_eng', 'images', 'music'):
        directory, report = extract(args.game_directory / 'data' / (name + '.dat'), args.output_directory / 'data' / name)
        (directories / (name + '.xml')).write_bytes(directory)
        reports.append(report)
        print(name, ':', len(report['entries']), 'entries; all zlib checksums, declared sizes, and archive ranges verified', flush=True)
    (args.output_directory / 'assets-manifest.json').write_text(json.dumps({'archives': reports}, indent=2) + '\n')


if __name__ == '__main__':
    main()
