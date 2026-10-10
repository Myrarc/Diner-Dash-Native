/* Address: 0048b760; name: FUN_0048b760 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_0048b760(undefined4 *param_1)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 uVar4;
  HMODULE hModule;
  void *pvVar5;
  DWORD DVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined1 local_14c [4];
  void *local_148;
  undefined4 local_138;
  uint local_134;
  undefined1 local_130 [4];
  void *local_12c;
  undefined4 local_11c;
  uint local_118;
  CHAR local_114 [256];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_14 = DAT_005b83e8;
  puStack_c = &LAB_0057ce38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = &PTR_FUN_00588280;
  *param_1 = &PTR_LAB_00588fec;
  param_1[1] = &PTR_FUN_00588fdc;
  param_1[9] = 0xf;
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[0x10] = 0xf;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  param_1[0x17] = 0xf;
  param_1[0x16] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x1e] = 0xf;
  param_1[0x1d] = 0;
  *(undefined1 *)(param_1 + 0x19) = 0;
  local_8 = 3;
  uStack_7 = 0;
  FUN_004ba960((LPCRITICAL_SECTION)(param_1 + 0x32));
  local_8 = 4;
  iVar3 = FUN_0047a440();
  param_1[0xbb] = iVar3;
  *(undefined1 *)(iVar3 + 0x15) = 1;
  *(undefined4 *)(param_1[0xbb] + 4) = param_1[0xbb];
  *(undefined4 *)param_1[0xbb] = param_1[0xbb];
  *(undefined4 *)(param_1[0xbb] + 8) = param_1[0xbb];
  param_1[0xbc] = 0;
  local_8 = 5;
  uVar4 = FUN_0047a190();
  param_1[0xbe] = uVar4;
  param_1[0xbf] = 0;
  local_8 = 6;
  uVar4 = FUN_0047a1b0();
  param_1[0xc9] = uVar4;
  param_1[0xca] = 0;
  param_1[0xd6] = 0xf;
  param_1[0xd5] = 0;
  *(undefined1 *)(param_1 + 0xd1) = 0;
  param_1[0xdd] = 0xf;
  param_1[0xdc] = 0;
  *(undefined1 *)(param_1 + 0xd8) = 0;
  param_1[0xee] = 0xf;
  param_1[0xed] = 0;
  *(undefined1 *)(param_1 + 0xe9) = 0;
  local_8 = 10;
  iVar3 = FUN_0047a630();
  param_1[0xfc] = iVar3;
  *(undefined1 *)(iVar3 + 0x11) = 1;
  *(undefined4 *)(param_1[0xfc] + 4) = param_1[0xfc];
  *(undefined4 *)param_1[0xfc] = param_1[0xfc];
  *(undefined4 *)(param_1[0xfc] + 8) = param_1[0xfc];
  param_1[0xfd] = 0;
  local_8 = 0xb;
  uVar4 = FUN_0047a1d0();
  param_1[0x11c] = uVar4;
  param_1[0x11d] = 0;
  param_1[0x135] = 0xf;
  param_1[0x134] = 0;
  *(undefined1 *)(param_1 + 0x130) = 0;
  param_1[0x13c] = 0xf;
  param_1[0x13b] = 0;
  *(undefined1 *)(param_1 + 0x137) = 0;
  local_8 = 0xe;
  FUN_004c5320(param_1 + 0x13d);
  local_8 = 0xf;
  iVar3 = FUN_0047a440();
  param_1[0x14f] = iVar3;
  *(undefined1 *)(iVar3 + 0x15) = 1;
  *(undefined4 *)(param_1[0x14f] + 4) = param_1[0x14f];
  *(undefined4 *)param_1[0x14f] = param_1[0x14f];
  *(undefined4 *)(param_1[0x14f] + 8) = param_1[0x14f];
  param_1[0x150] = 0;
  local_8 = 0x10;
  uVar4 = FUN_0047a1f0();
  param_1[0x153] = uVar4;
  param_1[0x154] = 0;
  local_8 = 0x11;
  iVar3 = FUN_00401b50();
  param_1[0x160] = iVar3;
  *(undefined1 *)(iVar3 + 0x45) = 1;
  *(undefined4 *)(param_1[0x160] + 4) = param_1[0x160];
  *(undefined4 *)param_1[0x160] = param_1[0x160];
  *(undefined4 *)(param_1[0x160] + 8) = param_1[0x160];
  param_1[0x161] = 0;
  local_8 = 0x12;
  iVar3 = FUN_00428f30();
  param_1[0x163] = iVar3;
  *(undefined1 *)(iVar3 + 0x2d) = 1;
  *(undefined4 *)(param_1[0x163] + 4) = param_1[0x163];
  *(undefined4 *)param_1[0x163] = param_1[0x163];
  *(undefined4 *)(param_1[0x163] + 8) = param_1[0x163];
  param_1[0x164] = 0;
  local_8 = 0x13;
  iVar3 = FUN_00428f30();
  param_1[0x166] = iVar3;
  *(undefined1 *)(iVar3 + 0x2d) = 1;
  *(undefined4 *)(param_1[0x166] + 4) = param_1[0x166];
  *(undefined4 *)param_1[0x166] = param_1[0x166];
  *(undefined4 *)(param_1[0x166] + 8) = param_1[0x166];
  param_1[0x167] = 0;
  local_8 = 0x14;
  iVar3 = FUN_0047a480();
  param_1[0x169] = iVar3;
  *(undefined1 *)(iVar3 + 0x39) = 1;
  *(undefined4 *)(param_1[0x169] + 4) = param_1[0x169];
  *(undefined4 *)param_1[0x169] = param_1[0x169];
  *(undefined4 *)(param_1[0x169] + 8) = param_1[0x169];
  param_1[0x16a] = 0;
  local_8 = 0x15;
  iVar3 = FUN_0047a4c0();
  param_1[0x16c] = iVar3;
  *(undefined1 *)(iVar3 + 0x39) = 1;
  *(undefined4 *)(param_1[0x16c] + 4) = param_1[0x16c];
  *(undefined4 *)param_1[0x16c] = param_1[0x16c];
  *(undefined4 *)(param_1[0x16c] + 8) = param_1[0x16c];
  param_1[0x16d] = 0;
  local_8 = 0x16;
  DAT_005ba088 = param_1;
  DAT_005ba094 = LoadLibraryA("version.dll");
  DAT_005ba08c = LoadLibraryA("ddraw.dll");
  DAT_005ba090 = LoadLibraryA("dsound.dll");
  pcVar8 = "GetLastInputInfo";
  hModule = GetModuleHandleA("user32.dll");
  DAT_005ba098 = GetProcAddress(hModule,pcVar8);
  param_1[0x2f] = 0;
  *(undefined1 *)(param_1 + 0x30) = 1;
  param_1[0x31] = 0;
  GetModuleFileNameA((HMODULE)0x0,local_114,0x100);
  pcVar8 = local_114;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401f60(local_130,(undefined4 *)local_114,(int)pcVar8 - (int)(local_114 + 1));
  local_8 = 0x17;
  pvVar5 = FUN_00480f10(local_14c,(int)local_130);
  _local_8 = CONCAT31(uStack_7,0x18);
  FUN_00401e70(param_1 + 0xd7,pvVar5,0,0xffffffff);
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_118) {
    _free(local_12c);
  }
  *(undefined1 *)(param_1 + 0xcb) = 0;
  *(undefined1 *)((int)param_1 + 0x32d) = 1;
  DVar6 = GetTickCount();
  param_1[0xc4] = DVar6;
  *(undefined1 *)(param_1 + 0xc1) = 0;
  FUN_00401f60(param_1 + 10,(undefined4 *)"Product",7);
  FUN_00401f60(param_1 + 0x11,(undefined4 *)"SexyApp",7);
  *(undefined8 *)(param_1 + 0x102) = _DAT_00587c80;
  uVar2 = _DAT_00587c80;
  *(undefined1 *)((int)param_1 + 0x305) = 0;
  *(undefined8 *)(param_1 + 0x104) = uVar2;
  *(undefined1 *)((int)param_1 + 0x306) = 0;
  uVar2 = _DAT_005874d8;
  param_1[0x22] = 0x280;
  *(undefined8 *)(param_1 + 0x10e) = uVar2;
  param_1[0x23] = 0x1e0;
  param_1[0x24] = 0x10;
  *(undefined1 *)((int)param_1 + 0x307) = 1;
  *(undefined1 *)(param_1 + 0xc2) = 1;
  *(undefined1 *)((int)param_1 + 0x309) = 0;
  param_1[0x20] = 0xffffffff;
  param_1[0x21] = 0xffffffff;
  *(undefined1 *)(param_1 + 199) = 0;
  *(undefined1 *)((int)param_1 + 0x31d) = 1;
  param_1[0xc5] = 0;
  param_1[0xcc] = 0;
  param_1[0xce] = 0;
  param_1[0xc6] = 0;
  param_1[0xff] = 10;
  param_1[0xfe] = 0;
  param_1[0x109] = 0;
  param_1[0x10b] = 0;
  param_1[0x10c] = 0;
  param_1[0x10d] = 0;
  *(undefined1 *)((int)param_1 + 0x402) = 1;
  *(undefined1 *)(param_1 + 0x100) = 0;
  *(undefined1 *)((int)param_1 + 0x401) = 0;
  param_1[0x106] = 0;
  *(undefined1 *)(param_1 + 0x110) = 0;
  param_1[0x111] = 0;
  *(undefined1 *)(param_1 + 0x112) = 0;
  *(undefined1 *)((int)param_1 + 0x449) = 0;
  param_1[0x118] = 0;
  param_1[0x117] = 0;
  *(undefined1 *)(param_1 + 0x11e) = 0;
  *(undefined1 *)((int)param_1 + 0x479) = 0;
  *(undefined1 *)((int)param_1 + 0x47a) = 1;
  *(undefined1 *)((int)param_1 + 0x30d) = 0;
  *(undefined1 *)((int)param_1 + 0x47b) = 0;
  *(undefined1 *)((int)param_1 + 0x4a7) = 0;
  *(undefined1 *)(param_1 + 0x12a) = 0;
  *(undefined1 *)((int)param_1 + 0x4a9) = 0;
  *(undefined1 *)((int)param_1 + 0x4a5) = 0;
  *(undefined1 *)(param_1 + 0x129) = 1;
  *(undefined1 *)((int)param_1 + 0x4a6) = 0;
  *(undefined1 *)((int)param_1 + 0x4aa) = 0;
  param_1[300] = 0;
  param_1[0x12d] = 0;
  DVar6 = timeGetTime();
  param_1[0x113] = DVar6;
  DVar6 = timeGetTime();
  param_1[0x114] = DVar6;
  *(undefined1 *)((int)param_1 + 0x4ab) = 1;
  *(undefined1 *)((int)param_1 + 0x30a) = 0;
  *(undefined1 *)((int)param_1 + 0x30b) = 0;
  *(undefined1 *)(param_1 + 0x11f) = 1;
  *(undefined1 *)(param_1 + 299) = 0;
  *(undefined1 *)((int)param_1 + 0x4ad) = 0;
  param_1[0xe6] = 0;
  *(undefined1 *)(param_1 + 0xe7) = 0;
  *(undefined1 *)(param_1 + 0xc3) = 0;
  *(undefined1 *)((int)param_1 + 0x4ae) = 1;
  uVar2 = _DAT_00581df0;
  *(undefined1 *)(param_1 + 0xcf) = 0;
  *(undefined8 *)(param_1 + 0x26) = uVar2;
  *(undefined1 *)((int)param_1 + 0xba) = 0;
  uVar2 = _DAT_00581df0;
  *(undefined1 *)((int)param_1 + 0xbb) = 0;
  *(undefined8 *)(param_1 + 0x28) = uVar2;
  *(undefined1 *)((int)param_1 + 0x555) = 0;
  uVar2 = _DAT_00587c80;
  *(undefined1 *)((int)param_1 + 0x556) = 0;
  *(undefined8 *)(param_1 + 0x2c) = uVar2;
  param_1[0x115] = 0;
  uVar2 = _DAT_00587c80;
  param_1[0xf8] = 0;
  *(undefined8 *)(param_1 + 0x2a) = uVar2;
  param_1[0xf9] = 0;
  *(undefined1 *)(param_1 + 0xfa) = 0;
  *(undefined1 *)((int)param_1 + 0x3e9) = 1;
  param_1[0x151] = 0;
  param_1[0x124] = 0;
  DVar6 = GetTickCount();
  param_1[0x121] = DVar6;
  param_1[0x122] = 0;
  param_1[0x125] = 0;
  param_1[0x123] = 0;
  *(undefined1 *)(param_1 + 0x126) = 0;
  param_1[0x127] = 0;
  param_1[0x120] = 0;
  param_1[0x128] = 0;
  *(undefined1 *)(param_1 + 0xcd) = 0;
  *(undefined1 *)(param_1 + 0x155) = 0;
  param_1[0x16f] = 0;
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)((int)param_1 + 0xb9) = 0;
  param_1[0x156] = 100;
  *(undefined1 *)(param_1 + 0x157) = 0;
  *(undefined1 *)((int)param_1 + 0x55d) = 0;
  param_1[0x158] = 0;
  param_1[0x159] = 0;
  param_1[0x15a] = 0;
  *(undefined1 *)(param_1 + 0x15b) = 0;
  *(undefined1 *)((int)param_1 + 0x56d) = 1;
  *(undefined1 *)((int)param_1 + 0x56e) = 0;
  *(undefined1 *)((int)param_1 + 0x56f) = 0;
  *(undefined1 *)(param_1 + 0x15c) = 0;
  param_1[0x15d] = 6;
  param_1[0x15e] = 0xe;
  param_1[0x1f] = 0;
  iVar3 = 0;
  param_1[0xde] = 0;
  param_1[0xdf] = 0;
  param_1[0xe0] = 0;
  param_1[0xe1] = 0;
  param_1[0xe2] = 0;
  param_1[0xe3] = 0;
  param_1[0xe4] = 0;
  param_1[0xe5] = 0;
  do {
    *(char *)((int)param_1 + iVar3 + 0xe1) = (char)iVar3;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  puVar7 = (undefined4 *)((int)param_1 + 0x1e1);
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar7 = 0xffffffff;
    puVar7 = puVar7 + 1;
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,(undefined4 *)&DAT_005867b0,2);
  local_8 = 0x19;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"DIALOG_BUTTON_OK",0x10);
  _local_8 = CONCAT31(uStack_7,0x1a);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,(undefined4 *)"CANCEL",6);
  local_8 = 0x1b;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"DIALOG_BUTTON_CANCEL",0x14);
  _local_8 = CONCAT31(uStack_7,0x1c);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,(undefined4 *)"Update Check",0xc);
  local_8 = 0x1d;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"UPDATE_CHECK_TITLE",0x12);
  _local_8 = CONCAT31(uStack_7,0x1e);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,
               (undefined4 *)"Checking if there are any updates available for this product ...",0x40
              );
  local_8 = 0x1f;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"UPDATE_CHECK_BODY",0x11);
  _local_8 = CONCAT31(uStack_7,0x20);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,(undefined4 *)"Up to Date",10);
  local_8 = 0x21;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"UP_TO_DATE_TITLE",0x10);
  _local_8 = CONCAT31(uStack_7,0x22);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,
               (undefined4 *)"There are no updates available for this product at this time.",0x3d);
  local_8 = 0x23;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"UP_TO_DATE_BODY",0xf);
  _local_8 = CONCAT31(uStack_7,0x24);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,(undefined4 *)"New Version",0xb);
  local_8 = 0x25;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"NEW_VERSION_TITLE",0x11);
  _local_8 = CONCAT31(uStack_7,0x26);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  local_134 = 0xf;
  local_138 = 0;
  local_148 = (void *)((uint)local_148 & 0xffffff00);
  FUN_00401f60(local_14c,
               (undefined4 *)
               "There is an update available for this product.  Would you like to visit the web site to download it?"
               ,100);
  local_8 = 0x27;
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  FUN_00401f60(local_130,(undefined4 *)"NEW_VERSION_BODY",0x10);
  _local_8 = CONCAT31(uStack_7,0x28);
  FUN_00486820(param_1,local_130,local_14c);
  if (0xf < local_118) {
    _free(local_12c);
  }
  local_118 = 0xf;
  local_11c = 0;
  local_12c = (void *)((uint)local_12c & 0xffffff00);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  FUN_00401f60(param_1 + 0x12f,(undefined4 *)"sexyapp",7);
  pvVar5 = FUN_0041a420(local_14c,param_1 + 0x12f,".dmo");
  local_8 = 0x29;
  FUN_00401e70(param_1 + 0x136,pvVar5,0,0xffffffff);
  local_8 = 0x16;
  if (0xf < local_134) {
    _free(local_148);
  }
  *(undefined1 *)((int)param_1 + 0x4b9) = 0;
  *(undefined1 *)((int)param_1 + 0x4ba) = 0;
  *(undefined1 *)(param_1 + 0x12e) = 0;
  param_1[0x146] = 0;
  param_1[0x147] = 0;
  param_1[0x148] = 0;
  *(undefined1 *)(param_1 + 0x149) = 1;
  *(undefined1 *)(param_1 + 0x14d) = 0;
  param_1[0x145] = 0;
  param_1[0x14a] = 0;
  param_1[0x14b] = 0xffffffff;
  param_1[0x14c] = 0;
  pvVar5 = operator_new(0x1dc);
  local_8 = 0x2a;
  if (pvVar5 == (void *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = FUN_004d8630(pvVar5,param_1);
  }
  local_8 = 0x16;
  param_1[0xb9] = puVar7;
  pvVar5 = operator_new(0xbc);
  _local_8 = CONCAT31(uStack_7,0x2b);
  if (pvVar5 == (void *)0x0) {
    puVar7 = (undefined4 *)0x0;
  }
  else {
    puVar7 = FUN_004ca610(pvVar5,param_1);
  }
  param_1[0x16e] = puVar7;
  param_1[0xc0] = 0;
  DAT_005efe18 = param_1;
  param_1[0x170] = 0;
  param_1[0x171] = 0;
  *(undefined1 *)(param_1 + 0x116) = 0;
  ExceptionList = local_10;
  return param_1;
}


