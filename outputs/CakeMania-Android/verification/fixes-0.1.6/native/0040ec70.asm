0040ec70  PUSH ESI
0040ec71  MOV ESI,ECX
0040ec73  LEA EAX,[ESI + 0x14]
0040ec76  ADD EAX,0x8
0040ec79  PUSH EDI
0040ec7a  XOR EDI,EDI
0040ec7c  MOV dword ptr [EAX + -0x8],EDI
0040ec7f  MOV dword ptr [EAX + -0x4],EDI
0040ec82  MOV dword ptr [EAX],EDI
0040ec84  MOV dword ptr [EAX + 0x4],EDI
0040ec87  MOV dword ptr [EAX + 0x8],EDI
0040ec8a  MOV dword ptr [EAX + 0xc],EDI
0040ec8d  ADD EAX,0x8
0040ec90  MOV dword ptr [EAX + 0x8],EDI
0040ec93  MOV dword ptr [EAX + 0xc],EDI
0040ec96  ADD EAX,0x8
0040ec99  MOV dword ptr [EAX + 0x8],EDI
0040ec9c  MOV dword ptr [EAX + 0xc],EDI
0040ec9f  MOV dword ptr [ESI + 0x60],EDI
0040eca2  MOV dword ptr [ESI + 0x64],EDI
0040eca5  MOV dword ptr [ESI + 0x68],EDI
0040eca8  ADD EAX,0x8
0040ecab  MOV dword ptr [ESI + 0x58],EDI
0040ecae  MOV dword ptr [ESI + 0x4c],EDI
0040ecb1  MOV dword ptr [ESI],EDI
0040ecb3  MOV dword ptr [ESI + 0x4],EDI
0040ecb6  MOV dword ptr [ESI + 0x8],EDI
0040ecb9  MOV dword ptr [ESI + 0xc],EDI
0040ecbc  MOV dword ptr [ESI + 0x10],EDI
0040ecbf  MOV dword ptr [ESI + 0x44],0x41a00000
0040ecc6  MOV dword ptr [ESI + 0x40],EDI
0040ecc9  MOV dword ptr [ESI + 0x3c],EDI
0040eccc  MOV dword ptr [ESI + 0x50],0x3db851ec
0040ecd3  MOV dword ptr [ESI + 0x48],EDI
0040ecd6  MOV EAX,dword ptr [ESI + 0x60]
0040ecd9  CMP EAX,EDI
0040ecdb  JZ 0x0040ece6
0040ecdd  PUSH EAX
0040ecde  CALL 0x00560046
0040ece6  MOV dword ptr [ESI + 0x60],EDI
0040ece9  MOV dword ptr [ESI + 0x64],EDI
0040ecec  MOV dword ptr [ESI + 0x68],EDI
0040ecef  POP EDI
0040ecf0  MOV EAX,ESI
0040ecf2  POP ESI
0040ecf3  RET
