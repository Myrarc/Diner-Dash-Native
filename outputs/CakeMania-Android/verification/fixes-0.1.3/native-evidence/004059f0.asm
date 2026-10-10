004059f0  PUSH -0x1
004059f2  PUSH 0x573e1d
004059f7  MOV EAX,FS:[0x0]
004059fd  PUSH EAX
004059fe  MOV dword ptr FS:[0x0],ESP
00405a05  SUB ESP,0xc
00405a08  PUSH EBX
00405a09  PUSH ESI
00405a0a  MOV ESI,ECX
00405a0c  XOR EBX,EBX
00405a0e  PUSH EDI
00405a0f  LEA ECX,[ESI + 0x24]
00405a12  MOV dword ptr [ESP + 0xc],ESI
00405a16  MOV dword ptr [ESI + 0x18],EBX
00405a19  MOV dword ptr [ESI + 0x1c],EBX
00405a1c  CALL 0x00405890
00405a21  LEA EDI,[ESI + 0x9d1c]
00405a27  MOV dword ptr [ESI + 0x9d04],EBX
00405a2d  MOV dword ptr [ESI + 0x9d08],EBX
00405a33  MOV EAX,0xf
00405a38  MOV dword ptr [EDI + 0x18],EAX
00405a3b  MOV dword ptr [EDI + 0x14],EBX
00405a3e  MOV dword ptr [ESP + 0x20],EBX
00405a42  MOV byte ptr [EDI + 0x4],BL
00405a45  MOV dword ptr [ESI + 0x9d50],EAX
00405a4b  MOV dword ptr [ESI + 0x9d4c],EBX
00405a51  MOV byte ptr [ESI + 0x9d3c],BL
00405a57  MOV dword ptr [ESI + 0x9d6c],EAX
00405a5d  MOV dword ptr [ESI + 0x9d68],EBX
00405a63  MOV byte ptr [ESI + 0x9d58],BL
00405a69  MOV dword ptr [ESI + 0x9d88],EAX
00405a6f  MOV dword ptr [ESI + 0x9d84],EBX
00405a75  MOV byte ptr [ESI + 0x9d74],BL
00405a7b  MOV dword ptr [ESI + 0x9d98],EBX
00405a81  MOV dword ptr [ESI + 0x9d9c],EBX
00405a87  MOV dword ptr [ESI + 0x9da4],EBX
00405a8d  MOV dword ptr [ESI + 0x9da8],EBX
00405a93  MOV dword ptr [ESI + 0x9dac],EBX
00405a99  MOV dword ptr [ESI + 0x9dc0],EBX
00405a9f  MOV dword ptr [ESI + 0x9dc4],EBX
00405aa5  MOV dword ptr [ESI + 0x9dc8],EBX
00405aab  LEA EAX,[ESI + 0x9dec]
00405ab1  MOV ECX,0x48
00405ab6  MOV dword ptr [EAX + -0xc],EBX
00405ab9  MOV dword ptr [EAX + -0x8],EBX
00405abc  MOV dword ptr [EAX + -0x4],EBX
00405abf  MOV dword ptr [EAX],EBX
00405ac1  ADD EAX,0x28
00405ac4  DEC ECX
00405ac5  JNZ 0x00405ab6
00405ac7  MOV dword ptr [ESI + 0xa918],EBX
00405acd  MOV dword ptr [ESI + 0xa91c],EBX
00405ad3  MOV dword ptr [ESI + 0xa920],EBX
00405ad9  MOV dword ptr [ESP + 0x10],0x0
00405ae1  MOV EAX,dword ptr [ESP + 0x10]
00405ae5  MOV dword ptr [ESP + 0x14],0x0
00405aed  MOV ECX,dword ptr [ESP + 0x14]
00405af1  MOV dword ptr [ESI + 0xc],0x3f800000
00405af8  MOV dword ptr [ESI],0x40866666
00405afe  MOV dword ptr [ESI + 0x9d14],0x8
00405b08  MOV dword ptr [ESI + 0x18],EAX
00405b0b  MOV dword ptr [ESI + 0x1c],ECX
00405b0e  MOV byte ptr [ESI + 0x14],BL
00405b11  MOV EAX,dword ptr [ESI + 0x9da4]
00405b17  CMP EAX,EBX
00405b19  MOV byte ptr [ESP + 0x20],0x7
00405b1e  JZ 0x00405b29
00405b20  PUSH EAX
00405b21  CALL 0x00560046
00405b29  MOV dword ptr [ESI + 0x9da4],EBX
00405b2f  MOV dword ptr [ESI + 0x9da8],EBX
00405b35  MOV dword ptr [ESI + 0x9dac],EBX
00405b3b  MOV dword ptr [ESI + 0x9cec],0x3f800000
00405b45  MOV dword ptr [ESI + 0xa90c],EBX
00405b4b  MOV dword ptr [ESI + 0x9db0],0x3f800000
00405b55  MOV dword ptr [ESI + 0x9db4],0x3f333333
00405b5f  MOV EAX,dword ptr [ESI + 0x9dc0]
00405b65  CMP EAX,EBX
00405b67  JZ 0x00405b72
00405b69  PUSH EAX
00405b6a  CALL 0x00560046
00405b72  MOV dword ptr [ESI + 0x9dc0],EBX
00405b78  MOV dword ptr [ESI + 0x9dc4],EBX
00405b7e  MOV dword ptr [ESI + 0x9dc8],EBX
00405b84  PUSH 0x4
00405b86  MOV dword ptr [ESP + 0x14],0xbf800000
00405b8e  MOV EDX,dword ptr [ESP + 0x14]
00405b92  MOV dword ptr [ESP + 0x18],0xbf800000
00405b9a  MOV EAX,dword ptr [ESP + 0x18]
00405b9e  PUSH 0x58150c
00405ba3  MOV ECX,EDI
00405ba5  MOV dword ptr [ESI + 0x9cf0],EBX
00405bab  MOV dword ptr [ESI + 0x9cf4],EBX
00405bb1  MOV dword ptr [ESI + 0x9cfc],EBX
00405bb7  MOV dword ptr [ESI + 0x9d00],EBX
00405bbd  MOV dword ptr [ESI + 0x9d04],EDX
00405bc3  MOV dword ptr [ESI + 0x9d08],EAX
00405bc9  MOV dword ptr [ESI + 0x9cf8],EBX
00405bcf  MOV dword ptr [ESI + 0x9d0c],EBX
00405bd5  MOV dword ptr [ESI + 0x9d10],EBX
00405bdb  MOV dword ptr [ESI + 0x20],EBX
00405bde  MOV dword ptr [ESI + 0xa910],EBX
00405be4  MOV dword ptr [ESI + 0x10],EBX
00405be7  MOV dword ptr [ESI + 0x9d18],EBX
00405bed  MOV dword ptr [ESI + 0x4],EBX
00405bf0  CALL 0x00401f60
00405bf5  LEA EAX,[ESI + 0x9df4]
00405bfb  MOV ECX,0x12
00405c00  MOV dword ptr [EAX + -0x28],EBX
00405c03  MOV dword ptr [EAX],EBX
00405c05  MOV dword ptr [EAX + 0x28],EBX
00405c08  MOV dword ptr [EAX + 0x50],EBX
00405c0b  ADD EAX,0xa0
00405c10  DEC ECX
00405c11  JNZ 0x00405c00
00405c13  MOV dword ptr [ESI + 0x8],EBX
00405c16  MOV dword ptr [ESI + 0x9d90],EBX
00405c1c  MOV EAX,dword ptr [ESI + 0xa918]
00405c22  CMP EAX,EBX
00405c24  JZ 0x00405c2f
00405c26  PUSH EAX
00405c27  CALL 0x00560046
00405c2f  MOV dword ptr [ESI + 0xa918],EBX
00405c35  MOV dword ptr [ESI + 0xa91c],EBX
00405c3b  MOV dword ptr [ESI + 0xa920],EBX
00405c41  MOV dword ptr [ESP + 0x10],0x0
00405c49  MOV ECX,dword ptr [ESP + 0x10]
00405c4d  MOV dword ptr [ESP + 0x14],0x0
00405c55  MOV EDX,dword ptr [ESP + 0x14]
00405c59  MOV dword ptr [ESI + 0x9d94],EBX
00405c5f  MOV dword ptr [ESI + 0x9d98],ECX
00405c65  MOV ECX,dword ptr [ESP + 0x18]
00405c69  POP EDI
00405c6a  MOV dword ptr [ESI + 0x9d9c],EDX
00405c70  MOV EAX,ESI
00405c72  POP ESI
00405c73  POP EBX
00405c74  MOV dword ptr FS:[0x0],ECX
00405c7b  ADD ESP,0x18
00405c7e  RET
