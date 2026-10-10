00411c20  PUSH -0x1
00411c22  PUSH 0x57461d
00411c27  MOV EAX,FS:[0x0]
00411c2d  PUSH EAX
00411c2e  MOV dword ptr FS:[0x0],ESP
00411c35  SUB ESP,0xc
00411c38  PUSH EBX
00411c39  PUSH EBP
00411c3a  XOR EBX,EBX
00411c3c  PUSH ESI
00411c3d  MOV ESI,ECX
00411c3f  MOV dword ptr [ESI],EBX
00411c41  MOV dword ptr [ESI + 0x4],EBX
00411c44  LEA EBP,[ESI + 0x18]
00411c47  PUSH EDI
00411c48  MOV dword ptr [ESI + 0x8],EBX
00411c4b  MOV dword ptr [ESI + 0xc],EBX
00411c4e  MOV EDI,0xf
00411c53  MOV dword ptr [EBP + 0x18],EDI
00411c56  MOV dword ptr [EBP + 0x14],EBX
00411c59  MOV dword ptr [ESP + 0x10],ESI
00411c5d  MOV byte ptr [EBP + 0x4],BL
00411c60  MOV dword ptr [ESP + 0x24],EBX
00411c64  LEA EAX,[ESI + 0x6c]
00411c67  MOV ECX,0x5
00411c6c  LEA ESP,[ESP]
00411c70  MOV dword ptr [EAX],EBX
00411c72  MOV dword ptr [EAX + 0x4],EBX
00411c75  ADD EAX,0x8
00411c78  DEC ECX
00411c79  JNZ 0x00411c70
00411c7b  PUSH 0x41fb40
00411c80  PUSH 0x44be70
00411c85  PUSH 0x5
00411c87  PUSH 0x10
00411c89  LEA EAX,[ESI + 0xa8]
00411c8f  PUSH EAX
00411c90  CALL 0x00560979
00411c95  PUSH 0x41fb40
00411c9a  PUSH 0x44be70
00411c9f  PUSH 0x5
00411ca1  PUSH 0x10
00411ca3  LEA ECX,[ESI + 0xf8]
00411ca9  PUSH ECX
00411caa  MOV byte ptr [ESP + 0x38],0x1
00411caf  CALL 0x00560979
00411cb4  LEA ECX,[ESI + 0x150]
00411cba  MOV byte ptr [ESP + 0x24],0x2
00411cbf  CALL 0x004107f0
00411cc4  MOV EDX,dword ptr [0x005b9e8c]
00411cca  MOV dword ptr [ESI + 0x1c8],EDX
00411cd0  MOV EAX,[0x005b9660]
00411cd5  MOV dword ptr [ESI + 0x1cc],EAX
00411cdb  MOV dword ptr [ESI + 0x1d8],EBX
00411ce1  MOV dword ptr [ESI + 0x1c4],EBX
00411ce7  MOV ECX,dword ptr [0x005b9c00]
00411ced  MOV dword ptr [ESI + 0x1d0],ECX
00411cf3  MOV EDX,ECX
00411cf5  MOV dword ptr [ESI + 0x1d4],0xffffffff
00411cff  MOV dword ptr [ESI + 0x1e8],EBX
00411d05  MOV dword ptr [ESI + 0x1e4],0x3d8f5c29
00411d0f  LEA ECX,[ESI + 0x1ec]
00411d15  MOV byte ptr [ESP + 0x24],0x3
00411d1a  MOV dword ptr [EDX + 0xc],0x8
00411d21  CALL 0x0040ec70
00411d26  MOV dword ptr [ESI + 0x294],EDI
00411d2c  MOV dword ptr [ESI + 0x290],EBX
00411d32  MOV byte ptr [ESI + 0x280],BL
00411d38  MOV dword ptr [ESI + 0x2a0],EBX
00411d3e  MOV dword ptr [ESI + 0x2a4],EBX
00411d44  MOV dword ptr [ESI + 0x2a8],EBX
00411d4a  LEA EDI,[ESI + 0x2ac]
00411d50  MOV dword ptr [EDI + 0x4],EBX
00411d53  MOV dword ptr [EDI + 0x8],EBX
00411d56  MOV dword ptr [EDI + 0xc],EBX
00411d59  MOV dword ptr [ESI + 0x2c4],EBX
00411d5f  MOV dword ptr [ESI + 0x2c8],EBX
00411d65  MOV dword ptr [ESI + 0x2cc],EBX
00411d6b  MOV dword ptr [ESI + 0x310],EBX
00411d71  MOV dword ptr [ESI + 0x314],EBX
00411d77  MOV dword ptr [ESI + 0x318],EBX
00411d7d  MOV dword ptr [ESP + 0x18],0x0
00411d85  MOV ECX,dword ptr [ESP + 0x18]
00411d89  PUSH 0x4
00411d8b  MOV dword ptr [ESP + 0x18],0x0
00411d93  MOV EAX,dword ptr [ESP + 0x18]
00411d97  MOV dword ptr [ESI + 0x4],ECX
00411d9a  PUSH 0x5816bc
00411d9f  MOV ECX,EBP
00411da1  MOV byte ptr [ESP + 0x2c],0x9
00411da6  MOV dword ptr [ESI],EAX
00411da8  MOV dword ptr [ESI + 0x14],EBX
00411dab  CALL 0x00401f60
00411db0  MOV dword ptr [ESI + 0x34],0x1
00411db7  MOV dword ptr [ESI + 0x48],EBX
00411dba  MOV dword ptr [ESI + 0x38],EBX
00411dbd  MOV dword ptr [ESI + 0x3c],EBX
00411dc0  MOV dword ptr [ESI + 0x4c],0x2
00411dc7  MOV dword ptr [ESI + 0x40],EBX
00411dca  MOV dword ptr [ESI + 0x44],EBX
00411dcd  MOV dword ptr [ESI + 0x64],EBX
00411dd0  MOV dword ptr [ESI + 0x58],EBX
00411dd3  MOV dword ptr [ESI + 0x5c],EBX
00411dd6  MOV dword ptr [ESI + 0x60],EBX
00411dd9  MOV dword ptr [ESI + 0x68],EBX
00411ddc  MOV EAX,0x3f800000
00411de1  MOV dword ptr [ESI + 0x264],EAX
00411de7  MOV dword ptr [ESI + 0x268],EAX
00411ded  MOV EDX,dword ptr [0x005b962c]
00411df3  MOV dword ptr [ESI + 0x148],EDX
00411df9  MOV EAX,[0x005b9e8c]
00411dfe  MOV dword ptr [ESI + 0x14c],EAX
00411e04  MOV EAX,dword ptr [ESI + 0x19c]
00411e0a  MOV dword ptr [ESI + 0x328],EBX
00411e10  MOV dword ptr [ESI + 0x50],0x40400000
00411e17  MOV dword ptr [ESI + 0x54],0x40000000
00411e1e  MOV ECX,dword ptr [0x005b9ec8]
00411e24  MOV dword ptr [ESI + 0x168],ECX
00411e2a  MOV EDX,dword ptr [0x005b9db8]
00411e30  MOV dword ptr [ESI + 0x16c],EDX
00411e36  FILD dword ptr [EAX + 0x10]
00411e39  MOV byte ptr [ESI + 0x26c],BL
00411e3f  MOV byte ptr [ESI + 0x26d],BL
00411e45  FDIVR float ptr [0x005814a8]
00411e4b  MOV byte ptr [ESI + 0x26f],BL
00411e51  MOV byte ptr [ESI + 0x26e],BL
00411e57  MOV byte ptr [ESI + 0x270],BL
00411e5d  MOV dword ptr [ESI + 0x298],EBX
00411e63  FSTP float ptr [ESI + 0x1b8]
00411e69  MOV EAX,dword ptr [ESI + 0x2a0]
00411e6f  CMP EAX,EBX
00411e71  JZ 0x00411e7c
00411e73  PUSH EAX
00411e74  CALL 0x00560046
00411e7c  MOV dword ptr [ESI + 0x2a0],EBX
00411e82  MOV dword ptr [ESI + 0x2a4],EBX
00411e88  MOV dword ptr [ESI + 0x2a8],EBX
00411e8e  OR EBP,0xffffffff
00411e91  MOV dword ptr [ESI + 0x278],EBP
00411e97  MOV dword ptr [ESI + 0x304],EBX
00411e9d  MOV dword ptr [ESI + 0x308],EBX
00411ea3  MOV dword ptr [ESI + 0x2bc],EBX
00411ea9  MOV EAX,dword ptr [ESI + 0x310]
00411eaf  CMP EAX,EBX
00411eb1  JZ 0x00411ebc
00411eb3  PUSH EAX
00411eb4  CALL 0x00560046
00411ebc  MOV ECX,EDI
00411ebe  MOV dword ptr [ESI + 0x310],EBX
00411ec4  MOV dword ptr [ESI + 0x314],EBX
00411eca  MOV dword ptr [ESI + 0x318],EBX
00411ed0  CALL 0x0040e650
00411ed5  MOV dword ptr [ESI + 0x320],EBX
00411edb  MOV dword ptr [ESI + 0x324],EBX
00411ee1  MOV dword ptr [ESI + 0x274],0xfffffffe
00411eeb  MOV dword ptr [ESI + 0x31c],EBX
00411ef1  MOV dword ptr [ESI + 0x2d4],EBX
00411ef7  MOV dword ptr [ESI + 0x2d0],EBX
00411efd  MOV dword ptr [ESI + 0x2d8],EBX
00411f03  MOV EAX,dword ptr [ESI + 0x2c4]
00411f09  CMP EAX,EBX
00411f0b  JZ 0x00411f16
00411f0d  PUSH EAX
00411f0e  CALL 0x00560046
00411f16  MOV ECX,dword ptr [ESP + 0x1c]
00411f1a  MOV dword ptr [ESI + 0x2c4],EBX
00411f20  MOV dword ptr [ESI + 0x2c8],EBX
00411f26  MOV dword ptr [ESI + 0x2cc],EBX
00411f2c  POP EDI
00411f2d  MOV dword ptr [ESI + 0x258],EBP
00411f33  MOV dword ptr [ESI + 0x25c],EBP
00411f39  MOV byte ptr [ESI + 0x260],BL
00411f3f  MOV dword ptr [ESI + 0x2e0],EBX
00411f45  MOV dword ptr [ESI + 0x8],EBX
00411f48  MOV dword ptr [ESI + 0xc],EBX
00411f4b  MOV byte ptr [ESI + 0x300],BL
00411f51  MOV dword ptr [ESI + 0x230],0x41a00000
00411f5b  MOV dword ptr [ESI + 0x2e4],0x3f000000
00411f65  MOV dword ptr [ESI + 0x2dc],0xff
00411f6f  MOV EAX,ESI
00411f71  POP ESI
00411f72  POP EBP
00411f73  POP EBX
00411f74  MOV dword ptr FS:[0x0],ECX
00411f7b  ADD ESP,0x18
00411f7e  RET
