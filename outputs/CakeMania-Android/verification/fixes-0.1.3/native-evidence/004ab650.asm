004ab650  PUSH EBP
004ab651  MOV EBP,ESP
004ab653  MOV EAX,FS:[0x0]
004ab659  PUSH -0x1
004ab65b  PUSH 0x57d691
004ab660  PUSH EAX
004ab661  MOV EAX,0x10b0
004ab666  MOV dword ptr FS:[0x0],ESP
004ab66d  CALL 0x00560db0
004ab672  PUSH EDI
004ab673  MOV EDI,ECX
004ab675  MOV EAX,dword ptr [EDI + 0x14]
004ab678  MOV CL,byte ptr [EAX + 0x50]
004ab67b  TEST CL,CL
004ab67d  MOV dword ptr [EBP + -0x38],EDI
004ab680  JZ 0x004abbad
004ab686  PUSH ESI
004ab687  LEA ECX,[EDI + 0x30]
004ab68a  CALL 0x004a04e0
004ab68f  MOV EAX,dword ptr [EDI + 0x14]
004ab692  XOR ESI,ESI
004ab694  MOV dword ptr [EDI + 0x4],ESI
004ab697  MOV dword ptr [EDI + 0x8],ESI
004ab69a  MOV dword ptr [EDI + 0xc],ESI
004ab69d  MOV dword ptr [EDI + 0x10],ESI
004ab6a0  MOV ECX,dword ptr [EAX + 0x170]
004ab6a6  MOV ECX,dword ptr [ECX]
004ab6a8  CMP ECX,dword ptr [EAX + 0x170]
004ab6ae  MOV dword ptr [EBP + -0x2c],ECX
004ab6b1  MOV byte ptr [EBP + -0xd],0x1
004ab6b5  JZ 0x004abbac
004ab6bb  PUSH EBX
004ab6bc  LEA ESP,[ESP]
004ab6c0  MOV EBX,dword ptr [EBP + -0x2c]
004ab6c3  MOV EAX,dword ptr [EDI + 0x18]
004ab6c6  MOV ECX,dword ptr [EBX + 0x12060]
004ab6cc  ADD EBX,0x8
004ab6cf  CMP EAX,ECX
004ab6d1  JL 0x004abb94
004ab6d7  MOV ECX,dword ptr [EBX + 0x1205c]
004ab6dd  CMP EAX,ECX
004ab6df  JLE 0x004ab6ea
004ab6e1  CMP ECX,-0x1
004ab6e4  JNZ 0x004abb94
004ab6ea  MOV byte ptr [EBP + -0xe],0x1
004ab6ee  MOV dword ptr [EBP + -0x18],ESI
004ab6f1  MOV dword ptr [EBP + -0x14],ESI
004ab6f4  MOV EAX,dword ptr [EBX + 0x8]
004ab6f7  CMP EAX,ESI
004ab6f9  JZ 0x004ab755
004ab6fb  MOV ECX,dword ptr [EBX + 0xc]
004ab6fe  SUB ECX,EAX
004ab700  MOV EAX,0x92492493
004ab705  IMUL ECX
004ab707  ADD EDX,ECX
004ab709  MOV ECX,dword ptr [EBP + -0x18]
004ab70c  SAR EDX,0x4
004ab70f  MOV EAX,EDX
004ab711  SHR EAX,0x1f
004ab714  ADD EAX,EDX
004ab716  CMP ECX,EAX
004ab718  JNC 0x004ab755
004ab71a  MOV EAX,dword ptr [EBX + 0x8]
004ab71d  MOV ECX,dword ptr [EBP + -0x14]
004ab720  MOV ESI,dword ptr [EDI + 0x24]
004ab723  ADD EAX,ECX
004ab725  MOV ECX,dword ptr [EDI + 0x20]
004ab728  PUSH EAX
004ab729  PUSH ESI
004ab72a  PUSH ECX
004ab72b  LEA ECX,[EBP + -0x54]
004ab72e  PUSH ECX
004ab72f  CALL 0x0049f850
004ab734  MOV ECX,dword ptr [EAX]
004ab736  ADD ESP,0x10
004ab739  CMP ECX,ESI
004ab73b  JNZ 0x004ab741
004ab73d  MOV byte ptr [EBP + -0xe],0x0
004ab741  MOV ECX,dword ptr [EBP + -0x18]
004ab744  MOV EAX,dword ptr [EBP + -0x14]
004ab747  INC ECX
004ab748  ADD EAX,0x1c
004ab74b  MOV dword ptr [EBP + -0x18],ECX
004ab74e  MOV dword ptr [EBP + -0x14],EAX
004ab751  XOR ESI,ESI
004ab753  JMP 0x004ab6f4
004ab755  MOV dword ptr [EBP + -0x18],ESI
004ab758  MOV dword ptr [EBP + -0x14],ESI
004ab75b  JMP 0x004ab760
004ab760  MOV EAX,dword ptr [EDI + 0x20]
004ab763  CMP EAX,ESI
004ab765  JZ 0x004ab7c1
004ab767  MOV ECX,dword ptr [EDI + 0x24]
004ab76a  SUB ECX,EAX
004ab76c  MOV EAX,0x92492493
004ab771  IMUL ECX
004ab773  ADD EDX,ECX
004ab775  MOV ECX,dword ptr [EBP + -0x18]
004ab778  SAR EDX,0x4
004ab77b  MOV EAX,EDX
004ab77d  SHR EAX,0x1f
004ab780  ADD EAX,EDX
004ab782  CMP ECX,EAX
004ab784  JNC 0x004ab7c1
004ab786  MOV EAX,dword ptr [EDI + 0x20]
004ab789  MOV ECX,dword ptr [EBP + -0x14]
004ab78c  MOV ESI,dword ptr [EBX + 0x1c]
004ab78f  ADD EAX,ECX
004ab791  MOV ECX,dword ptr [EBX + 0x18]
004ab794  PUSH EAX
004ab795  PUSH ESI
004ab796  PUSH ECX
004ab797  LEA EDX,[EBP + -0x58]
004ab79a  PUSH EDX
004ab79b  CALL 0x0049f850
004ab7a0  MOV ECX,dword ptr [EAX]
004ab7a2  ADD ESP,0x10
004ab7a5  CMP ECX,ESI
004ab7a7  JZ 0x004ab7ad
004ab7a9  MOV byte ptr [EBP + -0xe],0x0
004ab7ad  MOV ECX,dword ptr [EBP + -0x18]
004ab7b0  MOV EAX,dword ptr [EBP + -0x14]
004ab7b3  INC ECX
004ab7b4  ADD EAX,0x1c
004ab7b7  MOV dword ptr [EBP + -0x18],ECX
004ab7ba  MOV dword ptr [EBP + -0x14],EAX
004ab7bd  XOR ESI,ESI
004ab7bf  JMP 0x004ab760
004ab7c1  MOV AL,byte ptr [EBP + -0xe]
004ab7c4  TEST AL,AL
004ab7c6  JZ 0x004abb94
004ab7cc  MOV dword ptr [EBP + 0xffffef44],0x589470
004ab7d6  LEA EAX,[EBP + 0xffffef5c]
004ab7dc  MOV ECX,0x100
004ab7e1  MOV dword ptr [EAX + -0x8],ESI
004ab7e4  MOV dword ptr [EAX + -0x4],ESI
004ab7e7  MOV dword ptr [EAX],ESI
004ab7e9  MOV dword ptr [EAX + 0x4],ESI
004ab7ec  ADD EAX,0x10
004ab7ef  DEC ECX
004ab7f0  JNZ 0x004ab7e1
004ab7f2  MOV dword ptr [EBP + 0xffffef4c],ESI
004ab7f8  MOV byte ptr [EBP + 0xffffef50],0x0
004ab7ff  LEA ECX,[EDI + 0x30]
004ab802  MOV dword ptr [EBP + -0x4],ESI
004ab805  MOV ESI,dword ptr [ECX + 0x4]
004ab808  MOV EDX,dword ptr [ESI + 0x4]
004ab80b  LEA EAX,[EBP + 0xffffef44]
004ab811  PUSH EAX
004ab812  PUSH EDX
004ab813  PUSH ESI
004ab814  CALL 0x0049f660
004ab819  PUSH 0x1
004ab81b  LEA ECX,[EDI + 0x30]
004ab81e  MOV dword ptr [EBP + -0x20],EAX
004ab821  CALL 0x004a3d40
004ab826  FLD double ptr [0x005874d8]
004ab82c  MOV EAX,dword ptr [EBP + -0x20]
004ab82f  FSTP double ptr [EBP + -0x40]
004ab832  MOV dword ptr [ESI + 0x4],EAX
004ab835  MOV ECX,dword ptr [EAX + 0x4]
004ab838  MOV dword ptr [ECX],EAX
004ab83a  MOV EAX,dword ptr [EDI + 0x34]
004ab83d  MOV ESI,dword ptr [EAX + 0x4]
004ab840  MOV dword ptr [ESI + 0xc],EBX
004ab843  FLD double ptr [EDI + 0x40]
004ab846  MOV EAX,dword ptr [EDI + 0x40]
004ab849  FSTP double ptr [EBP + -0x34]
004ab84c  TEST EAX,EAX
004ab84e  MOV dword ptr [EBP + -0x4],0xffffffff
004ab855  MOV dword ptr [EBP + 0xffffef44],0x589470
004ab85f  JNZ 0x004ab8ca
004ab861  CMP dword ptr [EDI + 0x44],0x3ff00000
004ab868  JNZ 0x004ab8ca
004ab86a  MOV EAX,dword ptr [EBX + 0x12060]
004ab870  TEST EAX,EAX
004ab872  JZ 0x004ab879
004ab874  CMP dword ptr [EDI + 0x18],EAX
004ab877  JNZ 0x004ab8ca
004ab879  MOV ECX,dword ptr [EBX + 0x12044]
004ab87f  MOV dword ptr [ESI + 0x10],ECX
004ab882  MOV byte ptr [ESI + 0x14],0x0
004ab886  ADD ESI,0x18
004ab889  MOV dword ptr [EBP + -0x1c],ESI
004ab88c  LEA EAX,[EBX + 0x24]
004ab88f  MOV dword ptr [EBP + -0x14],0x100
004ab896  MOV EDX,EAX
004ab898  MOV ECX,dword ptr [EDX]
004ab89a  MOV dword ptr [ESI],ECX
004ab89c  MOV ECX,dword ptr [EDX + 0x4]
004ab89f  MOV dword ptr [ESI + 0x4],ECX
004ab8a2  MOV ECX,dword ptr [EDX + 0x8]
004ab8a5  MOV dword ptr [ESI + 0x8],ECX
004ab8a8  MOV EDX,dword ptr [EDX + 0xc]
004ab8ab  MOV ECX,dword ptr [EBP + -0x14]
004ab8ae  MOV dword ptr [ESI + 0xc],EDX
004ab8b1  MOV ESI,dword ptr [EBP + -0x1c]
004ab8b4  ADD ESI,0x10
004ab8b7  ADD EAX,0x120
004ab8bc  DEC ECX
004ab8bd  MOV dword ptr [EBP + -0x1c],ESI
004ab8c0  MOV dword ptr [EBP + -0x14],ECX
004ab8c3  JNZ 0x004ab896
004ab8c5  JMP 0x004abb03
004ab8ca  MOV EAX,dword ptr [EBX + 0x12060]
004ab8d0  TEST EAX,EAX
004ab8d2  MOV dword ptr [EBP + -0x20],EAX
004ab8d5  JZ 0x004ab8e6
004ab8d7  FILD dword ptr [EBP + -0x20]
004ab8da  FSTP double ptr [EBP + -0x40]
004ab8dd  FILD dword ptr [EDI + 0x18]
004ab8e0  FMUL double ptr [EDI + 0x40]
004ab8e3  FSTP double ptr [EBP + -0x34]
004ab8e6  PUSH 0x4c
004ab8e8  CALL 0x0055e970
004ab8ed  ADD ESP,0x4
004ab8f0  MOV dword ptr [EBP + -0x24],EAX
004ab8f3  XOR ECX,ECX
004ab8f5  CMP EAX,ECX
004ab8f7  MOV dword ptr [EBP + -0x4],0x1
004ab8fe  JZ 0x004ab915
004ab900  MOV ECX,dword ptr [EDI + 0x14]
004ab903  MOV EDX,dword ptr [ECX + 0x58]
004ab906  PUSH EDX
004ab907  MOV ECX,EAX
004ab909  CALL 0x004a7a90
004ab90e  MOV dword ptr [EBP + -0x20],EAX
004ab911  XOR ECX,ECX
004ab913  JMP 0x004ab918
004ab915  MOV dword ptr [EBP + -0x20],ECX
004ab918  FLD double ptr [0x005874d8]
004ab91e  LEA EAX,[ESI + 0x18]
004ab921  FDIV double ptr [EBP + -0x40]
004ab924  MOV dword ptr [EBP + -0x4],0xffffffff
004ab92b  MOV dword ptr [EBP + -0x18],ECX
004ab92e  MOV dword ptr [EBP + -0x1c],ECX
004ab931  MOV dword ptr [EBP + -0x14],EAX
004ab934  LEA EDI,[EBX + 0x2c]
004ab937  MOV dword ptr [EBP + -0x28],0x100
004ab93e  FLD double ptr [EBP + -0x34]
004ab941  FILD dword ptr [EDI + 0x4]
004ab944  FMUL ST1
004ab946  FMUL ST2
004ab948  CALL 0x00560568
004ab94d  FILD dword ptr [EDI]
004ab94f  MOV dword ptr [EBP + -0x24],EAX
004ab952  FMUL ST1
004ab954  FMUL ST2
004ab956  CALL 0x00560568
004ab95b  MOV ECX,dword ptr [EBP + -0x18]
004ab95e  MOV EDX,dword ptr [EBP + -0x14]
004ab961  MOV dword ptr [EDX],ECX
004ab963  XOR ECX,ECX
004ab965  MOV dword ptr [EDX + 0x4],ECX
004ab968  MOV ECX,dword ptr [EBP + -0x24]
004ab96b  MOV dword ptr [EDX + 0x8],EAX
004ab96e  MOV dword ptr [EDX + 0xc],ECX
004ab971  CMP ECX,dword ptr [EBP + -0x1c]
004ab974  JLE 0x004ab979
004ab976  MOV dword ptr [EBP + -0x1c],ECX
004ab979  MOV ECX,dword ptr [EBP + -0x18]
004ab97c  ADD ECX,EAX
004ab97e  MOV EAX,dword ptr [EBP + -0x28]
004ab981  MOV dword ptr [EBP + -0x18],ECX
004ab984  MOV ECX,dword ptr [EBP + -0x14]
004ab987  ADD ECX,0x10
004ab98a  ADD EDI,0x120
004ab990  DEC EAX
004ab991  MOV dword ptr [EBP + -0x14],ECX
004ab994  MOV dword ptr [EBP + -0x28],EAX
004ab997  JNZ 0x004ab941
004ab999  MOV EAX,dword ptr [EBP + -0x1c]
004ab99c  FSTP ST0
004ab99e  MOV EDI,dword ptr [EBP + -0x20]
004ab9a1  FSTP ST0
004ab9a3  MOV ECX,dword ptr [EBP + -0x18]
004ab9a6  PUSH EAX
004ab9a7  MOV dword ptr [ESI + 0x10],EDI
004ab9aa  MOV byte ptr [ESI + 0x14],0x1
004ab9ae  MOV EDX,dword ptr [EDI]
004ab9b0  PUSH ECX
004ab9b1  MOV ECX,EDI
004ab9b3  CALL dword ptr [EDX + 0x70]
004ab9b6  PUSH EDI
004ab9b7  LEA ECX,[EBP + 0xffffff54]
004ab9bd  CALL 0x004a05d0
004ab9c2  LEA EDX,[EBX + 0x24]
004ab9c5  MOV dword ptr [EBP + -0x4],0x2
004ab9cc  MOV dword ptr [EBP + -0x1c],EDX
004ab9cf  ADD ESI,0x20
004ab9d2  MOV dword ptr [EBP + -0x28],0x100
004ab9d9  LEA ESP,[ESP]
004ab9e0  MOV EAX,dword ptr [EBX + 0x12044]
004ab9e6  TEST EAX,EAX
004ab9e8  JZ 0x004aba63
004ab9ea  FILD dword ptr [ESI + -0x4]
004ab9ed  FADD float ptr [EBP + 0xffffff60]
004ab9f3  CALL 0x00560568
004ab9f8  FILD dword ptr [ESI + -0x8]
004ab9fb  MOV dword ptr [EBP + -0x24],EAX
004ab9fe  FADD float ptr [EBP + 0xffffff5c]
004aba04  CALL 0x00560568
004aba09  MOV dword ptr [EBP + -0x50],EAX
004aba0c  MOV EAX,dword ptr [EBP + -0x24]
004aba0f  MOV dword ptr [EBP + -0x4c],EAX
004aba12  MOV EAX,dword ptr [ESI]
004aba14  MOV dword ptr [EBP + -0x48],EAX
004aba17  MOV EAX,dword ptr [ESI + 0x4]
004aba1a  MOV dword ptr [EBP + -0x44],EAX
004aba1d  MOV AL,byte ptr [EBP + -0x74]
004aba20  TEST AL,AL
004aba22  JZ 0x004aba2f
004aba24  LEA ECX,[EBP + 0xffffff74]
004aba2a  MOV dword ptr [EBP + -0x20],ECX
004aba2d  JMP 0x004aba36
004aba2f  MOV dword ptr [EBP + -0x20],0x5b5504
004aba36  MOV EAX,dword ptr [EBP + -0x73]
004aba39  MOV ECX,dword ptr [EBP + 0xffffff58]
004aba3f  MOV EDX,dword ptr [ECX]
004aba41  PUSH EAX
004aba42  MOV EAX,dword ptr [EBP + -0x78]
004aba45  PUSH EAX
004aba46  MOV EAX,dword ptr [EBP + -0x20]
004aba49  PUSH EAX
004aba4a  LEA EAX,[EBP + 0xffffff64]
004aba50  PUSH EAX
004aba51  MOV EAX,dword ptr [EBP + -0x1c]
004aba54  PUSH EAX
004aba55  LEA EAX,[EBP + -0x50]
004aba58  PUSH EAX
004aba59  MOV EAX,dword ptr [EBX + 0x12044]
004aba5f  PUSH EAX
004aba60  CALL dword ptr [EDX + 0x28]
004aba63  MOV ECX,dword ptr [EBP + -0x1c]
004aba66  MOV EAX,dword ptr [EBP + -0x28]
004aba69  ADD ECX,0x120
004aba6f  ADD ESI,0x10
004aba72  DEC EAX
004aba73  MOV dword ptr [EBP + -0x1c],ECX
004aba76  MOV dword ptr [EBP + -0x28],EAX
004aba79  JNZ 0x004ab9e0
004aba7f  MOV ECX,dword ptr [EBP + -0x38]
004aba82  MOV AL,byte ptr [ECX + 0x48]
004aba85  TEST AL,AL
004aba87  JZ 0x004abaac
004aba89  MOV ESI,dword ptr [EDI + 0x8]
004aba8c  MOV EDX,dword ptr [EDI]
004aba8e  IMUL ESI,dword ptr [EDI + 0x4]
004aba92  MOV ECX,EDI
004aba94  CALL dword ptr [EDX + 0x74]
004aba97  TEST ESI,ESI
004aba99  JLE 0x004abaac
004aba9b  JMP 0x004abaa0
004abaa0  OR dword ptr [EAX],0xffffff
004abaa6  ADD EAX,0x4
004abaa9  DEC ESI
004abaaa  JNZ 0x004abaa0
004abaac  MOV EAX,dword ptr [EDI]
004abaae  MOV ECX,EDI
004abab0  CALL dword ptr [EAX + 0x80]
004abab6  MOV ECX,dword ptr [EBP + -0x60]
004abab9  MOV dword ptr [EBP + 0xffffff54],0x589560
004abac3  MOV EAX,dword ptr [ECX]
004abac5  MOV dword ptr [ECX],ECX
004abac7  MOV ECX,dword ptr [EBP + -0x60]
004abaca  MOV dword ptr [ECX + 0x4],ECX
004abacd  MOV ECX,dword ptr [EBP + -0x60]
004abad0  XOR EDI,EDI
004abad2  CMP EAX,ECX
004abad4  MOV dword ptr [EBP + -0x4],0xffffffff
004abadb  MOV dword ptr [EBP + -0x5c],EDI
004abade  JZ 0x004abaf4
004abae0  MOV ESI,dword ptr [EAX]
004abae2  PUSH EAX
004abae3  CALL 0x00560046
004abaf4  PUSH ECX
004abaf5  CALL 0x00560046
004abb03  FLD double ptr [0x005874d8]
004abb09  FDIV double ptr [EBP + -0x40]
004abb0c  FILD dword ptr [EBX + 0x12064]
004abb12  FMUL double ptr [EBP + -0x34]
004abb15  FMUL ST1
004abb17  CALL 0x00560568
004abb1c  CMP EAX,dword ptr [EDI + 0x4]
004abb1f  JLE 0x004abb24
004abb21  MOV dword ptr [EDI + 0x4],EAX
004abb24  MOV EAX,dword ptr [EBX + 0x1206c]
004abb2a  TEST EAX,EAX
004abb2c  MOV dword ptr [EBP + -0x24],EAX
004abb2f  JZ 0x004abb36
004abb31  FILD dword ptr [EBP + -0x24]
004abb34  JMP 0x004abb3c
004abb36  FILD dword ptr [EBX + 0x12070]
004abb3c  FMUL double ptr [EBP + -0x34]
004abb3f  FMUL ST1
004abb41  CALL 0x00560568
004abb46  CMP EAX,dword ptr [EDI + 0xc]
004abb49  JLE 0x004abb4e
004abb4b  MOV dword ptr [EDI + 0xc],EAX
004abb4e  FILD dword ptr [EBX + 0x12068]
004abb54  FMUL double ptr [EBP + -0x34]
004abb57  FMUL ST1
004abb59  CALL 0x00560568
004abb5e  MOV CL,byte ptr [EBP + -0xd]
004abb61  TEST CL,CL
004abb63  JNZ 0x004abb6a
004abb65  CMP EAX,dword ptr [EDI + 0x8]
004abb68  JGE 0x004abb6d
004abb6a  MOV dword ptr [EDI + 0x8],EAX
004abb6d  FILD dword ptr [EBX + 0x12074]
004abb73  FMUL double ptr [EBP + -0x34]
004abb76  FMUL ST1
004abb78  CALL 0x00560568
004abb7d  FSTP ST0
004abb7f  MOV CL,byte ptr [EBP + -0xd]
004abb82  TEST CL,CL
004abb84  JNZ 0x004abb8b
004abb86  CMP EAX,dword ptr [EDI + 0x10]
004abb89  JLE 0x004abb8e
004abb8b  MOV dword ptr [EDI + 0x10],EAX
004abb8e  MOV byte ptr [EBP + -0xd],0x0
004abb92  XOR ESI,ESI
004abb94  MOV ECX,dword ptr [EBP + -0x2c]
004abb97  MOV EAX,dword ptr [ECX]
004abb99  MOV EDX,dword ptr [EDI + 0x14]
004abb9c  CMP EAX,dword ptr [EDX + 0x170]
004abba2  MOV dword ptr [EBP + -0x2c],EAX
004abba5  JNZ 0x004ab6c0
004abbab  POP EBX
004abbac  POP ESI
004abbad  MOV ECX,dword ptr [EBP + -0xc]
004abbb0  POP EDI
004abbb1  MOV dword ptr FS:[0x0],ECX
004abbb8  MOV ESP,EBP
004abbba  POP EBP
004abbbb  RET
