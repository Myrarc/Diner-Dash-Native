0049c2f0  PUSH EBP
0049c2f1  MOV EBP,ESP
0049c2f3  SUB ESP,0x74
0049c2f6  FLD double ptr [EBP + 0x18]
0049c2f9  MOV EAX,dword ptr [EBP + 0x10]
0049c2fc  FLD ST0
0049c2fe  MOV ECX,dword ptr [EBP + 0x8]
0049c301  FCOS
0049c303  MOV EDX,dword ptr [EBP + 0xc]
0049c306  MOV dword ptr [EBP + 0x10],0x4b189680
0049c30d  MOV dword ptr [EBP + -0xc],0xcb189680
0049c314  MOV dword ptr [EBP + 0x1c],0x4b189680
0049c31b  FSTP float ptr [EBP + -0x4]
0049c31e  FSIN
0049c320  FSTP float ptr [EBP + -0x8]
0049c323  FILD dword ptr [EAX + 0x8]
0049c326  FST float ptr [EBP + -0x20]
0049c329  FSTP float ptr [EBP + -0x1c]
0049c32c  FILD dword ptr [EAX + 0xc]
0049c32f  FST float ptr [EBP + -0x3c]
0049c332  FSTP float ptr [EBP + -0x38]
0049c335  FLD float ptr [0x005894b8]
0049c33b  FLD float ptr [EBP + 0x24]
0049c33e  FCHS
0049c340  FST float ptr [EBP + -0x14]
0049c343  FLD float ptr [EBP + 0x28]
0049c346  FCHS
0049c348  FST float ptr [EBP + -0x10]
0049c34b  FLD float ptr [EBP + -0x8]
0049c34e  FMUL ST1
0049c350  FLD ST2
0049c352  FMUL float ptr [EBP + -0x4]
0049c355  FADDP
0049c357  FADD float ptr [EBP + 0x24]
0049c35a  FADD float ptr [ECX]
0049c35c  FSTP float ptr [EBP + -0x24]
0049c35f  FMUL float ptr [EBP + -0x4]
0049c362  FADD float ptr [EBP + 0x28]
0049c365  FXCH
0049c367  FMUL float ptr [EBP + -0x8]
0049c36a  FSUBP
0049c36c  FADD float ptr [EDX]
0049c36e  FST float ptr [EBP + -0x44]
0049c371  FLD float ptr [EBP + -0x24]
0049c374  FCOMP float ptr [0x005894b4]
0049c37a  FNSTSW AX
0049c37c  TEST AH,0x5
0049c37f  JP 0x0049c387
0049c381  MOV EAX,dword ptr [EBP + -0x24]
0049c384  MOV dword ptr [EBP + 0x10],EAX
0049c387  FLD float ptr [EBP + -0x24]
0049c38a  FCOMP float ptr [0x005894b8]
0049c390  FNSTSW AX
0049c392  TEST AH,0x41
0049c395  JNZ 0x0049c39d
0049c397  MOV EAX,dword ptr [EBP + -0x24]
0049c39a  MOV dword ptr [EBP + -0xc],EAX
0049c39d  FCOM float ptr [0x005894b4]
0049c3a3  FNSTSW AX
0049c3a5  TEST AH,0x5
0049c3a8  JP 0x0049c3ad
0049c3aa  FST float ptr [EBP + 0x1c]
0049c3ad  FCOMP float ptr [0x005894b8]
0049c3b3  FNSTSW AX
0049c3b5  TEST AH,0x41
0049c3b8  JNZ 0x0049c3bf
0049c3ba  FSTP ST0
0049c3bc  FLD float ptr [EBP + -0x44]
0049c3bf  FLD float ptr [EBP + -0x20]
0049c3c2  FSUB float ptr [EBP + 0x24]
0049c3c5  FLD float ptr [EBP + -0x10]
0049c3c8  FLD float ptr [EBP + -0x8]
0049c3cb  FMUL ST1
0049c3cd  FLD ST2
0049c3cf  FMUL float ptr [EBP + -0x4]
0049c3d2  FADDP
0049c3d4  FADD float ptr [EBP + 0x24]
0049c3d7  FADD float ptr [ECX]
0049c3d9  FSTP float ptr [EBP + -0x20]
0049c3dc  FMUL float ptr [EBP + -0x4]
0049c3df  FADD float ptr [EBP + 0x28]
0049c3e2  FXCH
0049c3e4  FMUL float ptr [EBP + -0x8]
0049c3e7  FSUBP
0049c3e9  FADD float ptr [EDX]
0049c3eb  FST float ptr [EBP + -0x40]
0049c3ee  FLD float ptr [EBP + -0x20]
0049c3f1  FCOMP float ptr [EBP + 0x10]
0049c3f4  FNSTSW AX
0049c3f6  TEST AH,0x5
0049c3f9  JP 0x0049c401
0049c3fb  MOV EAX,dword ptr [EBP + -0x20]
0049c3fe  MOV dword ptr [EBP + 0x10],EAX
0049c401  FLD float ptr [EBP + -0x20]
0049c404  FCOMP float ptr [EBP + -0xc]
0049c407  FNSTSW AX
0049c409  TEST AH,0x41
0049c40c  JNZ 0x0049c414
0049c40e  MOV EAX,dword ptr [EBP + -0x20]
0049c411  MOV dword ptr [EBP + -0xc],EAX
0049c414  FCOM float ptr [EBP + 0x1c]
0049c417  FNSTSW AX
0049c419  TEST AH,0x5
0049c41c  JP 0x0049c421
0049c41e  FST float ptr [EBP + 0x1c]
0049c421  FCOMP
0049c423  FNSTSW AX
0049c425  TEST AH,0x41
0049c428  JNZ 0x0049c42f
0049c42a  FSTP ST0
0049c42c  FLD float ptr [EBP + -0x40]
0049c42f  FLD float ptr [EBP + -0x1c]
0049c432  FSUB float ptr [EBP + 0x24]
0049c435  FLD float ptr [EBP + -0x3c]
0049c438  FSUB float ptr [EBP + 0x28]
0049c43b  FLD float ptr [EBP + -0x8]
0049c43e  FMUL ST1
0049c440  FLD ST2
0049c442  FMUL float ptr [EBP + -0x4]
0049c445  FADDP
0049c447  FADD float ptr [EBP + 0x24]
0049c44a  FADD float ptr [ECX]
0049c44c  FSTP float ptr [EBP + -0x1c]
0049c44f  FMUL float ptr [EBP + -0x4]
0049c452  FADD float ptr [EBP + 0x28]
0049c455  FXCH
0049c457  FMUL float ptr [EBP + -0x8]
0049c45a  FSUBP
0049c45c  FADD float ptr [EDX]
0049c45e  FST float ptr [EBP + -0x3c]
0049c461  FLD float ptr [EBP + -0x1c]
0049c464  FCOMP float ptr [EBP + 0x10]
0049c467  FNSTSW AX
0049c469  TEST AH,0x5
0049c46c  JP 0x0049c474
0049c46e  MOV EAX,dword ptr [EBP + -0x1c]
0049c471  MOV dword ptr [EBP + 0x10],EAX
0049c474  FLD float ptr [EBP + -0x1c]
0049c477  FCOMP float ptr [EBP + -0xc]
0049c47a  FNSTSW AX
0049c47c  TEST AH,0x41
0049c47f  JNZ 0x0049c487
0049c481  MOV EAX,dword ptr [EBP + -0x1c]
0049c484  MOV dword ptr [EBP + -0xc],EAX
0049c487  FCOM float ptr [EBP + 0x1c]
0049c48a  FNSTSW AX
0049c48c  TEST AH,0x5
0049c48f  JP 0x0049c494
0049c491  FST float ptr [EBP + 0x1c]
0049c494  FCOMP
0049c496  FNSTSW AX
0049c498  TEST AH,0x41
0049c49b  JNZ 0x0049c4a2
0049c49d  FSTP ST0
0049c49f  FLD float ptr [EBP + -0x3c]
0049c4a2  FLD float ptr [EBP + -0x14]
0049c4a5  FLD float ptr [EBP + -0x38]
0049c4a8  FSUB float ptr [EBP + 0x28]
0049c4ab  FLD float ptr [EBP + -0x8]
0049c4ae  FMUL ST1
0049c4b0  FLD ST2
0049c4b2  FMUL float ptr [EBP + -0x4]
0049c4b5  FADDP
0049c4b7  FADD float ptr [EBP + 0x24]
0049c4ba  FADD float ptr [ECX]
0049c4bc  FSTP float ptr [EBP + -0x18]
0049c4bf  FMUL float ptr [EBP + -0x4]
0049c4c2  FADD float ptr [EBP + 0x28]
0049c4c5  FXCH
0049c4c7  FMUL float ptr [EBP + -0x8]
0049c4ca  FSUBP
0049c4cc  FADD float ptr [EDX]
0049c4ce  FST float ptr [EBP + -0x38]
0049c4d1  FLD float ptr [EBP + -0x18]
0049c4d4  FCOMP float ptr [EBP + 0x10]
0049c4d7  FNSTSW AX
0049c4d9  TEST AH,0x5
0049c4dc  JP 0x0049c4e4
0049c4de  MOV ECX,dword ptr [EBP + -0x18]
0049c4e1  MOV dword ptr [EBP + 0x10],ECX
0049c4e4  FLD float ptr [EBP + -0x18]
0049c4e7  FCOMP float ptr [EBP + -0xc]
0049c4ea  FNSTSW AX
0049c4ec  TEST AH,0x41
0049c4ef  JNZ 0x0049c4f7
0049c4f1  MOV EDX,dword ptr [EBP + -0x18]
0049c4f4  MOV dword ptr [EBP + -0xc],EDX
0049c4f7  FCOM float ptr [EBP + 0x1c]
0049c4fa  FNSTSW AX
0049c4fc  TEST AH,0x5
0049c4ff  JP 0x0049c504
0049c501  FST float ptr [EBP + 0x1c]
0049c504  FCOMP
0049c506  FNSTSW AX
0049c508  TEST AH,0x41
0049c50b  JNZ 0x0049c512
0049c50d  FSTP ST0
0049c50f  FLD float ptr [EBP + -0x38]
0049c512  MOV EAX,dword ptr [EBP + 0x14]
0049c515  FILD dword ptr [EAX]
0049c517  LEA ECX,[EBP + -0x74]
0049c51a  FSTP double ptr [EBP + -0x54]
0049c51d  FILD dword ptr [EAX + 0x4]
0049c520  FSTP double ptr [EBP + -0x4c]
0049c523  FILD dword ptr [EAX + 0x8]
0049c526  FSTP double ptr [EBP + -0x44]
0049c529  FILD dword ptr [EAX + 0xc]
0049c52c  LEA EAX,[EBP + -0x54]
0049c52f  PUSH EAX
0049c530  PUSH ECX
0049c531  FSTP double ptr [EBP + -0x3c]
0049c534  LEA ECX,[EBP + -0x34]
0049c537  FLD float ptr [EBP + 0x10]
0049c53a  FSTP double ptr [EBP + -0x34]
0049c53d  FLD float ptr [EBP + 0x1c]
0049c540  FSTP double ptr [EBP + -0x2c]
0049c543  FLD float ptr [EBP + -0xc]
0049c546  FSUB float ptr [EBP + 0x10]
0049c549  FSTP double ptr [EBP + -0x24]
0049c54c  FSUB float ptr [EBP + 0x1c]
0049c54f  FSTP double ptr [EBP + -0x1c]
0049c552  CALL 0x00498520
0049c557  FLD double ptr [EBP + -0x64]
0049c55a  FCOMP double ptr [0x00587c80]
0049c560  FNSTSW AX
0049c562  TEST AH,0x41
0049c565  JNP 0x0049c590
0049c567  FLD double ptr [EBP + -0x5c]
0049c56a  FCOMP double ptr [0x00587c80]
0049c570  FNSTSW AX
0049c572  TEST AH,0x41
0049c575  JNP 0x0049c590
0049c577  PUSH ESI
0049c578  PUSH EDI
0049c579  MOV EDI,dword ptr [EBP + 0x20]
0049c57c  MOV ECX,0x8
0049c581  LEA ESI,[EBP + -0x74]
0049c584  MOVSD.REP ES:EDI,ESI
0049c586  POP EDI
0049c587  MOV AL,0x1
0049c589  POP ESI
0049c58a  MOV ESP,EBP
0049c58c  POP EBP
0049c58d  RET 0x24
0049c590  XOR AL,AL
0049c592  MOV ESP,EBP
0049c594  POP EBP
0049c595  RET 0x24
