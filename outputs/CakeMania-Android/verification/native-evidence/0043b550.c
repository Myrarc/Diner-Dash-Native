/* Address: 0043b550; name: FUN_0043b550 */

void __cdecl FUN_0043b550(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  float *pfVar5;
  void *this;
  double dVar6;
  undefined4 in_stack_ffffff20;
  uint in_stack_ffffff24;
  char *pcVar7;
  int *local_b4;
  undefined1 local_b0 [4];
  void *local_ac;
  undefined4 local_9c;
  uint local_98;
  undefined1 local_94 [4];
  void *local_90;
  undefined4 local_80;
  uint local_7c;
  int *local_78;
  int *local_74;
  int *local_70;
  long local_6c;
  long local_68;
  long local_64;
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
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00578074;
  local_c = ExceptionList;
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401f60(local_94,(undefined4 *)&DAT_005815ec,4);
  this = (void *)(param_1 + 0x58);
  local_4 = 0;
  piVar1 = FUN_00404ab0(this,local_94);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
  }
  if (iVar2 != 0) {
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401f60(local_94,(undefined4 *)&DAT_005815ec,4);
    local_4 = 1;
    piVar1 = FUN_00404ab0(this,local_94);
    FUN_00401e70((void *)(param_2 + 0x7c),piVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_7c) {
      _free(local_90);
    }
  }
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  FUN_00401f60(local_94,(undefined4 *)"description",0xb);
  local_4 = 2;
  piVar1 = FUN_00404ab0(this,local_94);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
  }
  if (iVar2 != 0) {
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401f60(local_94,(undefined4 *)"description",0xb);
    local_4 = 3;
    piVar1 = FUN_00404ab0(this,local_94);
    FUN_00401e70((void *)(param_2 + 0x98),piVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_7c) {
      _free(local_90);
    }
  }
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  FUN_00401f60(local_94,(undefined4 *)"ext_description",0xf);
  local_4 = 4;
  piVar1 = FUN_00404ab0(this,local_94);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
  }
  if (iVar2 != 0) {
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401f60(local_94,(undefined4 *)"ext_description",0xf);
    local_4 = 5;
    piVar1 = FUN_00404ab0(this,local_94);
    FUN_00401e70((void *)(param_2 + 0xb4),piVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_7c) {
      _free(local_90);
    }
  }
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  FUN_00401f60(local_94,(undefined4 *)"main_img",8);
  local_4 = 6;
  piVar1 = FUN_00404ab0(this,local_94);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
  }
  if (iVar2 != 0) {
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401f60(local_94,(undefined4 *)"main_img",8);
    local_4 = 7;
    piVar1 = FUN_00404ab0(this,local_94);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    iVar2 = FUN_00433e00((char *)piVar1);
    uVar3 = FUN_00427410(iVar2);
    *(undefined4 *)(param_2 + 4) = uVar3;
    local_4 = 0xffffffff;
    if (0xf < local_7c) {
      _free(local_90);
    }
  }
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  FUN_00401f60(local_94,(undefined4 *)"x_global",8);
  local_4 = 8;
  piVar1 = FUN_00404ab0(this,local_94);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)"height_global",0xd);
    local_4 = 9;
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    FUN_00401f60(local_94,(undefined4 *)"width_global",0xc);
    local_4._0_1_ = 10;
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)"y_global",8);
    local_4._0_1_ = 0xb;
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    FUN_00401f60(local_60,(undefined4 *)"x_global",8);
    local_4 = CONCAT31(local_4._1_3_,0xc);
    local_74 = FUN_00404ab0(this,local_b0);
    if ((uint)local_74[6] < 0x10) {
      local_74 = local_74 + 1;
    }
    else {
      local_74 = (int *)local_74[1];
    }
    local_78 = FUN_00404ab0(this,local_94);
    if ((uint)local_78[6] < 0x10) {
      local_78 = local_78 + 1;
    }
    else {
      local_78 = (int *)local_78[1];
    }
    local_70 = FUN_00404ab0(this,local_44);
    if ((uint)local_70[6] < 0x10) {
      local_70 = local_70 + 1;
    }
    else {
      local_70 = (int *)local_70[1];
    }
    local_b4 = FUN_00404ab0(this,local_60);
    if ((uint)local_b4[6] < 0x10) {
      local_b4 = local_b4 + 1;
    }
    else {
      local_b4 = (int *)local_b4[1];
    }
    local_74 = (int *)_atol((char *)local_74);
    local_78 = (int *)_atol((char *)local_78);
    local_70 = (int *)_atol((char *)local_70);
    lVar4 = _atol((char *)local_b4);
    *(long *)(param_2 + 0x4c) = lVar4;
    *(int **)(param_2 + 0x50) = local_70;
    *(int **)(param_2 + 0x54) = local_78;
    *(int **)(param_2 + 0x58) = local_74;
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
    if (0xf < local_7c) {
      _free(local_90);
    }
    local_7c = 0xf;
    local_80 = 0;
    local_90 = (void *)((uint)local_90 & 0xffffff00);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)&DAT_0058167c,4);
  local_4 = 0xd;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)&DAT_0058167c,4);
    local_4 = 0xe;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    dVar6 = _atof((char *)piVar1);
    *(float *)(param_2 + 100) = (float)dVar6;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)"cake_pt",7);
  local_4 = 0xf;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)"cake_pt",7);
    local_4 = 0x10;
    piVar1 = FUN_00404ab0(this,local_b0);
    pcVar7 = (char *)(in_stack_ffffff24 & 0xffffff00);
    FUN_00401e70(&stack0xffffff20,piVar1,0,0xffffffff);
    pfVar5 = FUN_00439c20((float *)&local_70,in_stack_ffffff20,pcVar7);
    *(float *)(param_2 + 0x3c) = *pfVar5;
    *(float *)(param_2 + 0x40) = pfVar5[1];
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  *(undefined4 *)(param_2 + 0x68) = 0;
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)"purchase_points",0xf);
  local_4 = 0x11;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)"purchase_points",0xf);
    local_4 = 0x12;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    lVar4 = _atol((char *)piVar1);
    *(long *)(param_2 + 0x74) = lVar4;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)"flash",5);
  local_4 = 0x13;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)"flash",5);
    local_4 = 0x14;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    lVar4 = _atol((char *)piVar1);
    *(bool *)(param_2 + 0xd0) = lVar4 != 0;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)&DAT_005816e4,4);
  local_4 = 0x15;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)&DAT_005816e4,4);
    local_4 = 0x16;
    piVar1 = FUN_00404ab0(this,local_b0);
    FUN_00401e70((void *)(param_2 + 0xdc),piVar1,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)"upgr_step",9);
  local_4 = 0x17;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)"upgr_step",9);
    local_4 = 0x18;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    lVar4 = _atol((char *)piVar1);
    *(long *)(param_2 + 0xd8) = lVar4;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  local_70 = *(int **)(param_2 + 0x14);
  local_6c = *(long *)(param_2 + 0x18);
  local_68 = *(long *)(param_2 + 0x1c);
  local_64 = *(long *)(param_2 + 0x20);
  local_98 = 0xf;
  local_9c = 0;
  local_ac = (void *)((uint)local_ac & 0xffffff00);
  FUN_00401f60(local_b0,(undefined4 *)&DAT_00581660,1);
  local_4 = 0x19;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    local_98 = 0xf;
    local_9c = 0;
    local_ac = (void *)((uint)local_ac & 0xffffff00);
    FUN_00401f60(local_b0,(undefined4 *)&DAT_00581660,1);
    local_4 = 0x1a;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    local_70 = (int *)_atol((char *)piVar1);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  FUN_004022f0(local_b0,"y");
  local_4 = 0x1b;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_b0,"y");
    local_4 = 0x1c;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    local_6c = _atol((char *)piVar1);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  FUN_004022f0(local_b0,"height");
  local_4 = 0x1d;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_b0,"height");
    local_4 = 0x1e;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    local_64 = _atol((char *)piVar1);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  FUN_004022f0(local_b0,"width");
  local_4 = 0x1f;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_b0,"width");
    local_4 = 0x20;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    local_68 = _atol((char *)piVar1);
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  *(int **)(param_2 + 0x14) = local_70;
  *(long *)(param_2 + 0x18) = local_6c;
  *(long *)(param_2 + 0x1c) = local_68;
  *(long *)(param_2 + 0x20) = local_64;
  FUN_004022f0(local_b0,"associate_point");
  local_4 = 0x21;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_b0,"associate_point");
    local_4 = 0x22;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    lVar4 = _atol((char *)piVar1);
    *(long *)(param_2 + 0x5c) = lVar4;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  FUN_004022f0(local_b0,"render_after");
  local_4 = 0x23;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_b0,"render_after");
    local_4 = 0x24;
    piVar1 = FUN_00404ab0(this,local_b0);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    lVar4 = _atol((char *)piVar1);
    *(long *)(param_2 + 0x78) = lVar4;
    local_4 = 0xffffffff;
    if (0xf < local_98) {
      _free(local_ac);
    }
  }
  FUN_004022f0(local_b0,"icon");
  local_4 = 0x25;
  piVar1 = FUN_00404ab0(this,local_b0);
  iVar2 = piVar1[5];
  local_4 = 0xffffffff;
  if (0xf < local_98) {
    _free(local_ac);
  }
  if (iVar2 != 0) {
    FUN_004022f0(local_28,"icon");
    local_4 = 0x26;
    piVar1 = FUN_00404ab0(this,local_28);
    if ((uint)piVar1[6] < 0x10) {
      piVar1 = piVar1 + 1;
    }
    else {
      piVar1 = (int *)piVar1[1];
    }
    iVar2 = FUN_00433e00((char *)piVar1);
    uVar3 = FUN_00427410(iVar2);
    *(undefined4 *)(param_2 + 0x10) = uVar3;
    if (0xf < local_10) {
      _free(local_24);
    }
  }
  ExceptionList = local_c;
  return;
}


