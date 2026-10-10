0049bd40  PUSH EBP
0049bd41  MOV EBP,ESP
0049bd43  SUB ESP,0x10
0049bd46  FLD float ptr [EBP + 0xc]
0049bd49  MOV EAX,ECX
0049bd4b  FADD float ptr [EAX + 0x8]
0049bd4e  PUSH EBX
0049bd4f  PUSH ESI
0049bd50  MOV ESI,dword ptr [EBP + 0x24]
0049bd53  FSTP float ptr [EBP + 0xc]
0049bd56  XOR ECX,ECX
0049bd58  CMP ESI,ECX
0049bd5a  FLD float ptr [EBP + 0x10]
0049bd5d  FADD float ptr [EAX + 0xc]
0049bd60  PUSH EDI
0049bd61  FSTP float ptr [EBP + 0x10]
0049bd64  JNZ 0x0049bdc0
0049bd66  MOV EDX,dword ptr [EBP + 0x8]
0049bd69  MOV ESI,dword ptr [EDX + 0x4]
0049bd6c  CMP byte ptr [EAX + 0x38],CL
0049bd6f  MOV dword ptr [EBP + -0x8],ESI
0049bd72  MOV ESI,dword ptr [EDX + 0x8]
0049bd75  MOV dword ptr [EBP + -0x4],ESI
0049bd78  MOV dword ptr [EBP + -0x10],ECX
0049bd7b  MOV dword ptr [EBP + -0xc],ECX
0049bd7e  LEA ESI,[EAX + 0x20]
0049bd81  JNZ 0x0049bd88
0049bd83  MOV ESI,0x5b5504
0049bd88  MOV EBX,dword ptr [EBP + 0x20]
0049bd8b  FLD double ptr [EBP + 0x14]
0049bd8e  MOV ECX,dword ptr [EAX + 0x4]
0049bd91  PUSH EBX
0049bd92  MOV EBX,dword ptr [EBP + 0x1c]
0049bd95  MOV EDI,dword ptr [ECX]
0049bd97  PUSH EBX
0049bd98  MOV EBX,dword ptr [EAX + 0x34]
0049bd9b  SUB ESP,0x8
0049bd9e  FSTP double ptr [ESP]
0049bda1  PUSH EBX
0049bda2  PUSH ESI
0049bda3  ADD EAX,0x10
0049bda6  PUSH EAX
0049bda7  LEA EAX,[EBP + -0x10]
0049bdaa  PUSH EAX
0049bdab  MOV EAX,dword ptr [EBP + 0x10]
0049bdae  PUSH EAX
0049bdaf  MOV EAX,dword ptr [EBP + 0xc]
0049bdb2  PUSH EAX
0049bdb3  PUSH EDX
0049bdb4  CALL dword ptr [EDI + 0x24]
0049bdb7  POP EDI
0049bdb8  POP ESI
0049bdb9  POP EBX
0049bdba  MOV ESP,EBP
0049bdbc  POP EBP
0049bdbd  RET 0x20
0049bdc0  CMP byte ptr [EAX + 0x38],CL
0049bdc3  LEA EDX,[EAX + 0x20]
0049bdc6  JNZ 0x0049bdcd
0049bdc8  MOV EDX,0x5b5504
0049bdcd  MOV EBX,dword ptr [EBP + 0x20]
0049bdd0  FLD double ptr [EBP + 0x14]
0049bdd3  MOV ECX,dword ptr [EAX + 0x4]
0049bdd6  MOV EDI,dword ptr [ECX]
0049bdd8  PUSH EBX
0049bdd9  MOV EBX,dword ptr [EBP + 0x1c]
0049bddc  PUSH EBX
0049bddd  MOV EBX,dword ptr [EAX + 0x34]
0049bde0  SUB ESP,0x8
0049bde3  FSTP double ptr [ESP]
0049bde6  PUSH EBX
0049bde7  PUSH EDX
0049bde8  MOV EDX,dword ptr [EBP + 0x10]
0049bdeb  ADD EAX,0x10
0049bdee  PUSH EAX
0049bdef  MOV EAX,dword ptr [EBP + 0xc]
0049bdf2  PUSH ESI
0049bdf3  PUSH EDX
0049bdf4  MOV EDX,dword ptr [EBP + 0x8]
0049bdf7  PUSH EAX
0049bdf8  PUSH EDX
0049bdf9  CALL dword ptr [EDI + 0x24]
0049bdfc  POP EDI
0049bdfd  POP ESI
0049bdfe  POP EBX
0049bdff  MOV ESP,EBP
0049be01  POP EBP
0049be02  RET 0x20
