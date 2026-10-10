/* Native address 0041d290; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0041d290(int *param_1)

{
  char cVar1;
  void *pvVar2;
  LPCSTR ***lpSubKey;
  LSTATUS LVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  undefined1 local_a0 [4];
  void *local_9c;
  undefined4 local_8c;
  uint local_88;
  HKEY local_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  undefined1 local_2c [4];
  LPCSTR **local_28 [5];
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005751e6;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &local_c;
  pvVar2 = FUN_0041a370(local_48,"SOFTWARE\\",(int)(param_1 + 0x18));
  local_4 = 0;
  pvVar2 = FUN_004c0f90(local_64,pvVar2);
  local_4._0_1_ = 1;
  pvVar2 = FUN_0041a420(local_80,pvVar2,"\\");
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_004c0f90(local_2c,pvVar2);
  if (0xf < local_68) {
    _free(local_7c);
  }
  local_68 = 0xf;
  local_6c = 0;
  local_7c = (void *)((uint)local_7c & 0xffffff00);
  if (0xf < local_4c) {
    _free(local_60);
  }
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_4._0_1_ = 4;
  if (0xf < local_30) {
    _free(local_44);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  lpSubKey = (LPCSTR ***)local_28[0];
  if (local_14 < 0x10) {
    lpSubKey = local_28;
  }
  LVar3 = RegOpenKeyExA((HKEY)&DAT_80000002,(LPCSTR)lpSubKey,0,0x20019,&local_84);
  if (LVar3 == 0) {
    local_88 = 0xf;
    local_8c = 0;
    local_9c = (void *)((uint)local_9c & 0xffffff00);
    FUN_00401f60(local_a0,(undefined4 *)"AppFolder",9);
    local_4._0_1_ = 7;
    FUN_004820e0(param_1,local_a0,param_1 + 0x179);
    local_4._0_1_ = 4;
    if (0xf < local_88) {
      _free(local_9c);
    }
  }
  else {
    FUN_0041a720(param_1);
  }
  if (param_1[0x17e] == 0) {
    FUN_0041a720(param_1);
  }
  FUN_00489710(param_1);
  FUN_004cd4e0(param_1[0x16e]);
  if (*(int *)(param_1[0x16e] + 0xb8) == 0) {
    *(undefined1 *)(param_1 + 0x1c8) = 0;
    MessageBoxA((HWND)0x0,"Cannot find data files","Fatal Error",0);
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
LAB_0041d52e:
    if (0xf < local_14) {
      _free(local_28[0]);
    }
    ExceptionList = local_c;
    return;
  }
  FUN_0048aaf0(param_1);
  local_88 = 0xf;
  local_8c = 0;
  local_9c = (void *)((uint)local_9c & 0xffffff00);
  FUN_00401f60(local_a0,(undefined4 *)&DAT_00581e0c,4);
  local_4._0_1_ = 8;
  cVar1 = (**(code **)(*(int *)param_1[0x16e] + 0x10))();
  local_4._0_1_ = 4;
  if (0xf < local_88) {
    _free(local_9c);
  }
  if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
    FUN_00489380(param_1,'\x01');
    if (local_14 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _free(local_28[0]);
    ExceptionList = local_c;
    return;
  }
  uVar4 = FUN_00431c90((int *)param_1[0x16e]);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
    FUN_00489380(param_1,'\x01');
    goto LAB_0041d52e;
  }
  FUN_004022f0(local_a0,"TitleScreen");
  local_4._0_1_ = 9;
  cVar1 = (**(code **)(*(int *)param_1[0x16e] + 0x10))();
  local_4._0_1_ = 4;
  if (0xf < local_88) {
    _free(local_9c);
  }
  if (cVar1 == '\0') {
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
    FUN_00489380(param_1,'\x01');
    goto LAB_0041d856;
  }
  FUN_00476cd0(param_1,0,DAT_005b9a6c);
  FUN_00476cd0(param_1,1,DAT_005b9ddc);
  FUN_00476cd0(param_1,2,DAT_005b9fd4);
  FUN_00476cd0(param_1,3,DAT_005ba01c);
  FUN_00476cd0(param_1,6,DAT_005b9c3c);
  (**(code **)(*DAT_005b9f04 + 0x40))(_DAT_00581df8);
  (**(code **)(*DAT_005ba020 + 0x40))(_DAT_00581df0);
  (**(code **)(*DAT_005b9b10 + 0x40))(_DAT_00581de8);
  (**(code **)(*DAT_005b9e30 + 0x40))(_DAT_00581de0);
  FUN_004781c0(DAT_005ba088,1);
  uVar4 = FUN_004334a0((int *)param_1[0x16e]);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
    FUN_00489380(param_1,'\x01');
    goto LAB_0041d856;
  }
  if ((char)param_1[0x1c8] == '\0') {
LAB_0041d7a4:
    pvVar2 = operator_new(0xf0);
    local_4._0_1_ = 0xc;
    if (pvVar2 == (void *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = FUN_00472f80(pvVar2,param_1);
    }
    param_1[0x186] = (int)piVar7;
    local_4._0_1_ = 4;
    (**(code **)(*piVar7 + 100))(0,0,param_1[0x22]);
    FUN_00401000();
    FUN_004d8dc0((void *)param_1[0xb9],(int *)param_1[0x186]);
    FUN_004d1b90((void *)param_1[0xb9],(int *)param_1[0x186]);
    FUN_004022f0(local_a0,"Game");
    local_4._0_1_ = 0xd;
    iVar6 = FUN_004bd2c0((void *)param_1[0x16e],(int)local_a0);
    param_1[300] = iVar6;
    FUN_0049fbf0((int)local_a0);
  }
  else {
    puVar5 = operator_new(0x30);
    local_4._0_1_ = 10;
    if (puVar5 == (undefined4 *)0x0) {
      iVar6 = 0;
      piVar7 = extraout_ECX;
    }
    else {
      iVar6 = FUN_0041d160(puVar5);
      piVar7 = extraout_ECX_00;
    }
    local_4._0_1_ = 4;
    param_1[0x1c6] = iVar6;
    FUN_00401490(&stack0xffffff48,"data\\config_eng.dat");
    cVar1 = FUN_004d1760((void *)param_1[0x1c6],piVar7);
    if (cVar1 == '\0') {
      puVar5 = (undefined4 *)param_1[0x1c6];
      if (puVar5 != (undefined4 *)0x0) {
        FUN_0041d1b0(puVar5);
        _free(puVar5);
      }
      param_1[0x1c6] = 0;
    }
    else {
      puVar5 = operator_new(0x30);
      local_4._0_1_ = 0xb;
      if (puVar5 == (undefined4 *)0x0) {
        iVar6 = 0;
        piVar7 = extraout_ECX_01;
      }
      else {
        iVar6 = FUN_0041d160(puVar5);
        piVar7 = extraout_ECX_02;
      }
      local_4._0_1_ = 4;
      param_1[0x1c7] = iVar6;
      FUN_00401490(&stack0xffffff48,"data\\music.dat");
      cVar1 = FUN_004d1760((void *)param_1[0x1c7],piVar7);
      if (cVar1 != '\0') goto LAB_0041d7a4;
      puVar5 = (undefined4 *)param_1[0x1c7];
      if (puVar5 != (undefined4 *)0x0) {
        FUN_0041d1b0(puVar5);
        _free(puVar5);
      }
      param_1[0x1c7] = 0;
    }
    MessageBoxA((HWND)0x0,"Cannot find data files","Fatal Error",0);
    *(undefined1 *)((int)param_1 + 0x4a9) = 1;
  }
LAB_0041d856:
  FUN_0049fbf0((int)local_2c);
  ExceptionList = local_c;
  return;
}

