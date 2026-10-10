0049bbe0  PUSH EBP
0049bbe1  MOV EBP,ESP
0049bbe3  SUB ESP,0x20
0049bbe6  FILD dword ptr [EBP + 0xc]
0049bbe9  PUSH EBX
0049bbea  PUSH ESI
0049bbeb  MOV ESI,ECX
0049bbed  FADD float ptr [ESI + 0x8]
0049bbf0  PUSH EDI
0049bbf1  CALL 0x00560568
0049bbf6  FILD dword ptr [EBP + 0x10]
0049bbf9  MOV dword ptr [EBP + -0x20],EAX
0049bbfc  FADD float ptr [ESI + 0xc]
0049bbff  CALL 0x00560568
0049bc04  MOV ECX,dword ptr [EBP + 0x18]
0049bc07  MOV dword ptr [EBP + -0x1c],EAX
0049bc0a  MOV EAX,dword ptr [EBP + 0x14]
0049bc0d  MOV dword ptr [EBP + -0x18],EAX
0049bc10  MOV EAX,dword ptr [EBP + 0x8]
0049bc13  MOV EDX,dword ptr [EAX + 0x4]
0049bc16  MOV dword ptr [EBP + -0x8],EDX
0049bc19  MOV EDX,dword ptr [EAX + 0x8]
0049bc1c  MOV dword ptr [EBP + -0x14],ECX
0049bc1f  XOR ECX,ECX
0049bc21  MOV dword ptr [EBP + -0x4],EDX
0049bc24  CMP byte ptr [ESI + 0x38],CL
0049bc27  MOV dword ptr [EBP + -0x10],ECX
0049bc2a  MOV dword ptr [EBP + -0xc],ECX
0049bc2d  LEA EDI,[ESI + 0x20]
0049bc30  JNZ 0x0049bc37
0049bc32  MOV EDI,0x5b5504
0049bc37  MOV ECX,dword ptr [ESI + 0x4]
0049bc3a  MOV EDX,dword ptr [ECX]
0049bc3c  XOR EBX,EBX
0049bc3e  MOV BL,byte ptr [ESI + 0x39]
0049bc41  ADD ESI,0x10
0049bc44  PUSH EBX
0049bc45  MOV EBX,dword ptr [ESI + 0x24]
0049bc48  PUSH EBX
0049bc49  PUSH EDI
0049bc4a  PUSH ESI
0049bc4b  LEA ESI,[EBP + -0x10]
0049bc4e  PUSH ESI
0049bc4f  LEA ESI,[EBP + -0x20]
0049bc52  PUSH ESI
0049bc53  PUSH EAX
0049bc54  CALL dword ptr [EDX + 0x28]
0049bc57  POP EDI
0049bc58  POP ESI
0049bc59  POP EBX
0049bc5a  MOV ESP,EBP
0049bc5c  POP EBP
0049bc5d  RET 0x14
