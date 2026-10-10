"""Read recovered literal Lingo property lists without executing Lingo."""
import json
import re

TOKEN = re.compile(r'\s*(\(member\s+\d+\s+of\s+castLib\s+\d+\)|<Void>|#[A-Za-z_]\w*|"(?:[^"\\]|\\.)*"|-?\d+(?:\.\d+)?|[A-Za-z_]\w*|[\[\]():,])', re.I)


def parse_lingo(text):
    tokens = []
    position = 0
    while position < len(text.rstrip()):
        match = TOKEN.match(text, position)
        if not match:
            raise ValueError(f'Unrecognized Lingo literal at {position}: {text[position:position+80]}')
        tokens.append(match.group(1))
        position = match.end()
    index = 0

    def parse():
        nonlocal index
        token = tokens[index]
        index += 1
        if token == '[':
            if tokens[index] == ':':
                assert tokens[index + 1] == ']'
                index += 2
                return {}
            properties = index + 1 < len(tokens) and tokens[index + 1] == ':'
            result = {} if properties else []
            while tokens[index] != ']':
                if properties:
                    key = parse()
                    assert tokens[index] == ':'
                    index += 1
                    value = parse()
                    if key in result:
                        result.setdefault('__duplicate_entries__', []).append([key, value])
                    else:
                        result[key] = value
                else:
                    result.append(parse())
                if tokens[index] != ',':
                    break
                index += 1
            assert tokens[index] == ']'
            index += 1
            return result
        if token.lower() in ('<void>', 'void'):
            return None
        if token.startswith('(member'):
            numbers = [int(n) for n in re.findall(r'\d+', token)]
            return {'__type__': 'member', 'number': numbers[0], 'cast_number': numbers[1]}
        if token.startswith('#'):
            return token[1:]
        if token.startswith('"'):
            return json.loads(token, strict=False)
        if token.lower() in ('point', 'rect', 'rgb', 'color', 'paletteindex'):
            assert tokens[index] == '('
            index += 1
            values = []
            while tokens[index] != ')':
                values.append(parse())
                if tokens[index] != ',':
                    break
                index += 1
            assert tokens[index] == ')'
            index += 1
            return {'__type__': token.lower(), 'values': values}
        if re.fullmatch(r'-?\d+(\.\d+)?', token):
            return float(token) if '.' in token else int(token)
        if token.lower() in ('true', 'false'):
            return token.lower() == 'true'
        raise ValueError('Unrecognized scalar: ' + token)

    result = parse()
    if index != len(tokens):
        raise ValueError('Extra tokens: ' + ' '.join(tokens[index:index+20]))
    return result
