/* Address: 0043df60; name: FUN_0043df60 */

undefined4 * __cdecl FUN_0043df60(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  float *pfVar8;
  long *plVar9;
  void *this;
  undefined4 in_stack_ffffff28;
  uint in_stack_ffffff2c;
  char *pcVar10;
  int *local_ac;
  undefined1 local_a8 [4];
  void *local_a4;
  undefined4 local_94;
  uint local_90;
  undefined4 *local_8c;
  int *local_88;
  undefined1 local_84 [4];
  void *local_80;
  undefined4 local_70;
  uint local_6c;
  int *local_68 [2];
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00578220;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_8c = operator_new(0x100);
  local_4 = 0;
  if (local_8c == (undefined4 *)0x0) {
    local_8c = (undefined4 *)0x0;
  }
  else {
    FUN_00438050(local_8c);
    *local_8c = &PTR_FUN_005860dc;
    local_8c[0xd] = 0;
    local_8c[0x18] = 4;
    local_8c[0xe] = 0;
    *(undefined1 *)(local_8c + 0x1c) = 0;
    *(undefined1 *)((int)local_8c + 0xd2) = 1;
  }
  local_4 = 0xffffffff;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  FUN_00401f60(local_84,(undefined4 *)&DAT_005815ec,4);
  this = (void *)(param_1 + 0x58);
  local_4 = 1;
  piVar3 = FUN_00404ab0(this,local_84);
  FUN_00401e70(local_8c + 0x1f,piVar3,0,0xffffffff);
  local_4 = 0xffffffff;
  if (0xf < local_6c) {
    _free(local_80);
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  FUN_00401f60(local_84,(undefined4 *)"main_img",8);
  local_4 = 2;
  piVar3 = FUN_00404ab0(this,local_84);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  iVar4 = FUN_00433e00((char *)piVar3);
  uVar5 = FUN_00427410(iVar4);
  local_8c[1] = uVar5;
  local_4 = 0xffffffff;
  if (0xf < local_6c) {
    _free(local_80);
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"height_global",0xd);
  local_4 = 3;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  FUN_00401f60(local_84,(undefined4 *)"width_global",0xc);
  local_4._0_1_ = 4;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)"y_global",8);
  local_4._0_1_ = 5;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)"x_global",8);
  local_4 = CONCAT31(local_4._1_3_,6);
  local_88 = FUN_00404ab0(this,local_a8);
  if ((uint)local_88[6] < 0x10) {
    local_88 = local_88 + 1;
  }
  else {
    local_88 = (int *)local_88[1];
  }
  local_68[0] = FUN_00404ab0(this,local_84);
  if ((uint)local_68[0][6] < 0x10) {
    local_68[0] = local_68[0] + 1;
  }
  else {
    local_68[0] = (int *)local_68[0][1];
  }
  local_ac = FUN_00404ab0(this,local_44);
  if ((uint)local_ac[6] < 0x10) {
    local_ac = local_ac + 1;
  }
  else {
    local_ac = (int *)local_ac[1];
  }
  piVar3 = FUN_00404ab0(this,local_60);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  local_88 = (int *)_atol((char *)local_88);
  local_68[0] = (int *)_atol((char *)local_68[0]);
  lVar6 = _atol((char *)local_ac);
  lVar7 = _atol((char *)piVar3);
  puVar2 = local_8c;
  plVar9 = local_8c + 0x13;
  *plVar9 = lVar7;
  local_8c[0x14] = lVar6;
  local_8c[0x15] = local_68[0];
  local_8c[0x16] = local_88;
  if (0xf < local_48) {
    _free(local_5c);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_6c) {
    _free(local_80);
  }
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  uVar5 = puVar2[0x14];
  local_8c[5] = *plVar9;
  uVar1 = puVar2[0x15];
  local_8c[6] = uVar5;
  uVar5 = puVar2[0x16];
  local_8c[7] = uVar1;
  local_8c[8] = uVar5;
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"associate_point",0xf);
  local_4 = 7;
  piVar3 = FUN_00404ab0(this,local_a8);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  lVar6 = _atol((char *)piVar3);
  puVar2 = local_8c;
  local_8c[0x17] = lVar6;
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"purchase_points",0xf);
  local_4 = 8;
  piVar3 = FUN_00404ab0(this,local_a8);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  lVar6 = _atol((char *)piVar3);
  puVar2[0x1d] = lVar6;
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  puVar2[0x19] = 0;
  puVar2[0x1a] = 0;
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"cake_pt",7);
  local_4 = 9;
  piVar3 = FUN_00404ab0(this,local_a8);
  pcVar10 = (char *)(in_stack_ffffff2c & 0xffffff00);
  FUN_00401e70(&stack0xffffff28,piVar3,0,0xffffffff);
  pfVar8 = FUN_00439c20((float *)local_68,in_stack_ffffff28,pcVar10);
  puVar2[0xf] = *pfVar8;
  puVar2[0x10] = pfVar8[1];
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"flash",5);
  local_4 = 10;
  piVar3 = FUN_00404ab0(this,local_a8);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  lVar6 = _atol((char *)piVar3);
  *(bool *)(puVar2 + 0x34) = lVar6 != 0;
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)&DAT_005816e4,4);
  local_4 = 0xb;
  piVar3 = FUN_00404ab0(this,local_a8);
  iVar4 = piVar3[5];
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  if (iVar4 != 0) {
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    FUN_00401f60(local_a8,(undefined4 *)&DAT_005816e4,4);
    local_4 = 0xc;
    piVar3 = FUN_00404ab0(this,local_a8);
    FUN_00401e70(puVar2 + 0x37,piVar3,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_90) {
      _free(local_a4);
    }
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)"upgr_step",9);
  local_4 = 0xd;
  piVar3 = FUN_00404ab0(this,local_a8);
  iVar4 = piVar3[5];
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  if (iVar4 != 0) {
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    FUN_00401f60(local_a8,(undefined4 *)"upgr_step",9);
    local_4 = 0xe;
    piVar3 = FUN_00404ab0(this,local_a8);
    if ((uint)piVar3[6] < 0x10) {
      piVar3 = piVar3 + 1;
    }
    else {
      piVar3 = (int *)piVar3[1];
    }
    lVar6 = _atol((char *)piVar3);
    puVar2[0x36] = lVar6;
    local_4 = 0xffffffff;
    if (0xf < local_90) {
      _free(local_a4);
    }
  }
  local_90 = 0xf;
  local_94 = 0;
  local_a4 = (void *)((uint)local_a4 & 0xffffff00);
  FUN_00401f60(local_a8,(undefined4 *)&DAT_00586180,4);
  local_4 = 0xf;
  piVar3 = FUN_00404ab0(this,local_a8);
  iVar4 = piVar3[5];
  local_4 = 0xffffffff;
  if (0xf < local_90) {
    _free(local_a4);
  }
  if (iVar4 != 0) {
    local_90 = 0xf;
    local_94 = 0;
    local_a4 = (void *)((uint)local_a4 & 0xffffff00);
    FUN_00401f60(local_a8,(undefined4 *)&DAT_00586180,4);
    local_4 = 0x10;
    piVar3 = FUN_00404ab0(this,local_a8);
    if ((uint)piVar3[6] < 0x10) {
      piVar3 = piVar3 + 1;
    }
    else {
      piVar3 = (int *)piVar3[1];
    }
    iVar4 = FUN_00433e00((char *)piVar3);
    uVar5 = FUN_00427410(iVar4);
    puVar2[4] = uVar5;
    local_4 = 0xffffffff;
    if (0xf < local_90) {
      _free(local_a4);
    }
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401f60(local_28,(undefined4 *)"render_after",0xc);
  local_4 = 0x11;
  piVar3 = FUN_00404ab0(this,local_28);
  if ((uint)piVar3[6] < 0x10) {
    piVar3 = piVar3 + 1;
  }
  else {
    piVar3 = (int *)piVar3[1];
  }
  lVar6 = _atol((char *)piVar3);
  puVar2[0x1e] = lVar6;
  if (0xf < local_10) {
    _free(local_24);
  }
  ExceptionList = local_c;
  return puVar2;
}


