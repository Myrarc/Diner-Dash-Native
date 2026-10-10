0044c650  PUSH -0x1
0044c652  PUSH 0x57923c
0044c657  MOV EAX,FS:[0x0]
0044c65d  PUSH EAX
0044c65e  MOV dword ptr FS:[0x0],ESP
0044c665  SUB ESP,0x8
0044c668  PUSH EBX
0044c669  PUSH ESI
0044c66a  MOV ESI,ECX
0044c66c  PUSH EDI
0044c66d  MOV dword ptr [ESP + 0x10],ESI
0044c671  CALL 0x004d87e0
0044c676  MOV dword ptr [ESI + 0x80],0x588260
0044c680  XOR EBX,EBX
0044c682  MOV dword ptr [ESI],0x586c20
0044c688  MOV dword ptr [ESI + 0x80],0x586c04
0044c692  MOV dword ptr [ESP + 0x1c],EBX
0044c696  MOV dword ptr [ESI + 0x8c],EBX
0044c69c  MOV dword ptr [ESI + 0x90],EBX
0044c6a2  MOV dword ptr [ESI + 0x94],EBX
0044c6a8  MOV dword ptr [ESI + 0x15c],EBX
0044c6ae  MOV dword ptr [ESI + 0x160],EBX
0044c6b4  MOV dword ptr [ESI + 0x164],EBX
0044c6ba  LEA ECX,[ESI + 0x168]
0044c6c0  MOV byte ptr [ESP + 0x1c],0x2
0044c6c5  CALL 0x00409ab0
0044c6ca  LEA EDI,[ESI + 0x1ac]
0044c6d0  MOV ECX,EDI
0044c6d2  MOV byte ptr [ESP + 0x1c],0x3
0044c6d7  CALL 0x0044be80
0044c6dc  LEA ECX,[ESI + 0x1fc]
0044c6e2  MOV byte ptr [ESP + 0x1c],0x4
0044c6e7  CALL 0x00418020
0044c6ec  MOV EAX,EBX
0044c6ee  CMP EAX,EBX
0044c6f0  MOV dword ptr [ESI + 0x2c8],EBX
0044c6f6  MOV dword ptr [ESI + 0x2cc],EBX
0044c6fc  MOV dword ptr [ESI + 0x2d0],EBX
0044c702  JZ 0x0044c70d
0044c704  PUSH EAX
0044c705  CALL 0x00560046
0044c70d  MOV dword ptr [ESI + 0x2c8],EBX
0044c713  MOV dword ptr [ESI + 0x2cc],EBX
0044c719  MOV dword ptr [ESI + 0x2d0],EBX
0044c71f  MOV dword ptr [ESI + 0x2c0],0x40a00000
0044c729  LEA ECX,[ESI + 0x330]
0044c72f  MOV byte ptr [ESP + 0x1c],0x6
0044c734  CALL 0x0041b6b0
0044c739  LEA ECX,[ESI + 0x398]
0044c73f  MOV byte ptr [ESP + 0x1c],0x7
0044c744  CALL 0x0041b720
0044c749  MOV dword ptr [ESI + 0x460],0xf
0044c753  MOV dword ptr [ESI + 0x45c],EBX
0044c759  MOV byte ptr [ESI + 0x44c],BL
0044c75f  MOV EAX,dword ptr [ESP + 0x24]
0044c763  PUSH 0xa924
0044c768  MOV byte ptr [ESP + 0x20],0x9
0044c76d  MOV dword ptr [ESI + 0x84],EAX
0044c773  MOV dword ptr [ESI + 0x2e8],EBX
0044c779  MOV dword ptr [ESI + 0x444],EBX
0044c77f  MOV dword ptr [ESI + 0x43c],EBX
0044c785  MOV dword ptr [ESI + 0x98],EBX
0044c78b  MOV dword ptr [ESI + 0x440],EBX
0044c791  MOV dword ptr [ESI + 0x308],EBX
0044c797  CALL 0x0055e970
0044c79c  ADD ESP,0x4
0044c79f  MOV dword ptr [ESP + 0x24],EAX
0044c7a3  CMP EAX,EBX
0044c7a5  MOV byte ptr [ESP + 0x1c],0xa
0044c7aa  JZ 0x0044c7b5
0044c7ac  MOV ECX,EAX
0044c7ae  CALL 0x004059f0
0044c7b3  JMP 0x0044c7b7
0044c7b5  XOR EAX,EAX
0044c7b7  MOV ECX,dword ptr [ESI + 0x84]
0044c7bd  MOV dword ptr [ESI + 0x1a8],EAX
0044c7c3  MOV dword ptr [EAX + 0x20],ECX
0044c7c6  MOV EAX,dword ptr [ESI + 0x1a8]
0044c7cc  PUSH 0x20
0044c7ce  MOV byte ptr [ESP + 0x20],0x9
0044c7d3  MOV dword ptr [EAX + 0x9db8],0x44ab40
0044c7dd  CALL 0x0055e970
0044c7e2  ADD ESP,0x4
0044c7e5  CMP EAX,EBX
0044c7e7  JZ 0x0044c800
0044c7e9  MOV dword ptr [EAX + 0x4],EBX
0044c7ec  MOV dword ptr [EAX + 0x8],EBX
0044c7ef  MOV dword ptr [EAX + 0xc],EBX
0044c7f2  MOV dword ptr [EAX + 0x10],EBX
0044c7f5  MOV dword ptr [EAX + 0x14],EBX
0044c7f8  MOV dword ptr [EAX + 0x18],EBX
0044c7fb  MOV dword ptr [EAX + 0x1c],EBX
0044c7fe  JMP 0x0044c802
0044c800  XOR EAX,EAX
0044c802  MOV dword ptr [ESI + 0x1a4],EAX
0044c808  MOV dword ptr [ESI + 0x2f8],EBX
0044c80e  MOV dword ptr [0x005ba070],ESI
0044c814  MOV dword ptr [ESI + 0x150],0x3f800000
0044c81e  MOV dword ptr [ESI + 0x154],EBX
0044c824  MOV dword ptr [ESI + 0x2fc],EBX
0044c82a  MOV dword ptr [ESI + 0x300],EBX
0044c830  MOV dword ptr [ESI + 0x304],EBX
0044c836  MOV EAX,dword ptr [ESI + 0x15c]
0044c83c  CMP EAX,EBX
0044c83e  MOV byte ptr [ESP + 0x1c],0x9
0044c843  JZ 0x0044c84e
0044c845  PUSH EAX
0044c846  CALL 0x00560046
0044c84e  MOV dword ptr [ESI + 0x15c],EBX
0044c854  MOV dword ptr [ESI + 0x160],EBX
0044c85a  MOV dword ptr [ESI + 0x164],EBX
0044c860  MOV ECX,0x1
0044c865  MOV byte ptr [ESI + 0x2e4],CL
0044c86b  MOV dword ptr [ESI + 0x2d4],EBX
0044c871  MOV dword ptr [ESI + 0x2d8],EBX
0044c877  MOV dword ptr [ESI + 0x2dc],EBX
0044c87d  MOV dword ptr [ESI + 0x30c],EBX
0044c883  MOV EDX,dword ptr [0x005b9f40]
0044c889  MOV dword ptr [EDX + 0x10],ECX
0044c88c  MOV EAX,[0x005b9f40]
0044c891  MOV dword ptr [EAX + 0xc],0x10
0044c898  MOV EAX,dword ptr [ESI + 0x84]
0044c89e  PUSH 0x10
0044c8a0  MOV dword ptr [ESI + 0x24c],EAX
0044c8a6  MOV dword ptr [EDI],EAX
0044c8a8  MOV dword ptr [ESI + 0x310],EBX
0044c8ae  MOV dword ptr [ESI + 0x318],EBX
0044c8b4  MOV dword ptr [ESI + 0x31c],EBX
0044c8ba  MOV dword ptr [ESI + 0x320],EBX
0044c8c0  MOV dword ptr [ESI + 0x314],EBX
0044c8c6  MOV dword ptr [ESI + 0x324],EBX
0044c8cc  MOV dword ptr [ESI + 0x328],EBX
0044c8d2  MOV dword ptr [ESI + 0x32c],EBX
0044c8d8  MOV dword ptr [ESI + 0x430],EBX
0044c8de  MOV byte ptr [ESI + 0x18c],CL
0044c8e4  MOV byte ptr [ESI + 0x434],BL
0044c8ea  MOV byte ptr [ESI + 0x435],BL
0044c8f0  MOV byte ptr [ESI + 0x2e5],BL
0044c8f6  MOV dword ptr [ESI + 0x428],EBX
0044c8fc  MOV byte ptr [ESI + 0x42c],CL
0044c902  MOV byte ptr [ESI + 0x464],BL
0044c908  CALL 0x0055e970
0044c90d  ADD ESP,0x4
0044c910  CMP EAX,EBX
0044c912  JZ 0x0044c934
0044c914  MOV dword ptr [EAX + 0x8],EBX
0044c917  MOV dword ptr [EAX + 0x4],0x40000000
0044c91e  MOV ECX,dword ptr [0x005b9e38]
0044c924  MOV dword ptr [EAX + 0xc],ECX
0044c927  MOV byte ptr [EAX + 0x1],BL
0044c92a  MOV byte ptr [EAX],BL
0044c92c  MOV dword ptr [ESI + 0x2e0],EAX
0044c932  JMP 0x0044c93a
0044c934  MOV dword ptr [ESI + 0x2e0],EBX
0044c93a  MOV ECX,dword ptr [ESP + 0x14]
0044c93e  POP EDI
0044c93f  MOV EAX,ESI
0044c941  POP ESI
0044c942  POP EBX
0044c943  MOV dword ptr FS:[0x0],ECX
0044c94a  ADD ESP,0x14
0044c94d  RET 0x4
