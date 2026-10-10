/* Native address 0046f370; read-only Ghidra audit recovery. */

/* WARNING: Removing unreachable block (ram,0x0046f76e) */
/* WARNING: Removing unreachable block (ram,0x0046f693) */
/* WARNING: Removing unreachable block (ram,0x0046f5be) */
/* WARNING: Removing unreachable block (ram,0x0046f53b) */
/* WARNING: Removing unreachable block (ram,0x0046f637) */
/* WARNING: Removing unreachable block (ram,0x0046f712) */
/* WARNING: Removing unreachable block (ram,0x0046f7ed) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046f370(void *this,undefined4 param_1)

{
  undefined8 uVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint unaff_EBX;
  undefined4 local_c4;
  int *piStack_a8;
  undefined4 uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  void *pvStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined1 auStack_84 [4];
  void *local_80;
  uint uStack_7c;
  void *pvStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [4];
  uint uStack_64;
  uint uStack_60;
  void *pvStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  uint uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0057b5f6;
  pvStack_c = ExceptionList;
  _local_c4 = CONCAT44(0x46f39e,local_c4);
  ExceptionList = &pvStack_c;
  local_80 = this;
  pvVar2 = operator_new(0x130);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else if (this == (void *)0x0) {
    _local_c4 = CONCAT44(param_1,0x46f3e2);
    piVar3 = FUN_004d8b60(pvVar2,param_1,0);
  }
  else {
    _local_c4 = CONCAT44(param_1,0x46f3cc);
    piVar3 = FUN_004d8b60(pvVar2,param_1,(int)this + 0x80);
  }
  _local_c4 = _DAT_005878e8;
  local_4 = -1;
  (**(code **)(*DAT_005b9f04 + 0x40))();
  (**(code **)(*piVar3 + 0xe4))();
  uStack_9c = 0xf;
  uStack_a0 = 0;
  FUN_00401f60(&stack0xffffff4c,(undefined4 *)&DAT_00586e18,4);
  pvVar2 = (void *)(local_4 + 0x58);
  uStack_10 = 1;
  piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff4c);
  FUN_00401e70(piVar3 + 0x21,piVar4,0,0xffffffff);
  uStack_10 = 0xffffffff;
  if (0xf < uStack_9c) {
    _free((void *)(unaff_EBX & 0xffffff00));
  }
  iVar6 = *piVar3;
  FUN_0048c7b0(&stack0xffffff4c,0xfd,1,6);
  (**(code **)(iVar6 + 0x4c))(0);
  iVar6 = *piVar3;
  uVar5 = FUN_0048c7b0(&stack0xffffff44,0xfe,0xfe,0xfe);
  (**(code **)(iVar6 + 0x4c))(1,uVar5);
  iVar6 = *piVar3;
  uVar5 = FUN_0048c7b0(&local_c4,0x4d,0x48,0xae);
  (**(code **)(iVar6 + 0x4c))(2,uVar5);
  *(undefined1 *)((int)piVar3 + 0xfb) = 1;
  FUN_00401f60(&stack0xffffff34,(undefined4 *)"img_over",8);
  uStack_28 = 2;
  piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
  uStack_28 = 0xffffffff;
  if (piVar4[5] != 0) {
    FUN_00401f60(&stack0xffffff34,(undefined4 *)"img_over",8);
    uStack_28 = 3;
    piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
    if ((uint)piVar4[6] < 0x10) {
      piVar4 = piVar4 + 1;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
    iVar6 = FUN_00433e00((char *)piVar4);
    iVar6 = FUN_00427410(iVar6);
    piVar3[0x2b] = iVar6;
    uStack_28 = 0xffffffff;
    FUN_00401f60(&stack0xffffff34,(undefined4 *)"img_over",8);
    uStack_28 = 4;
    piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
    if ((uint)piVar4[6] < 0x10) {
      piVar4 = piVar4 + 1;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
    iVar6 = FUN_00433e00((char *)piVar4);
    iVar6 = FUN_00427410(iVar6);
    piVar3[0x2c] = iVar6;
  }
  uStack_28 = 0xffffffff;
  FUN_00401f60(&stack0xffffff34,(undefined4 *)"img_dis",7);
  uStack_28 = 5;
  piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
  uStack_28 = 0xffffffff;
  if (piVar4[5] != 0) {
    FUN_00401f60(&stack0xffffff34,(undefined4 *)"img_dis",7);
    uStack_28 = 6;
    piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
    if ((uint)piVar4[6] < 0x10) {
      piVar4 = piVar4 + 1;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
    iVar6 = FUN_00433e00((char *)piVar4);
    iVar6 = FUN_00427410(iVar6);
    piVar3[0x2d] = iVar6;
  }
  uStack_28 = 0xffffffff;
  FUN_00401f60(&stack0xffffff34,(undefined4 *)&DAT_0058170c,3);
  uStack_28 = 7;
  piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
  uStack_28 = 0xffffffff;
  if (piVar4[5] != 0) {
    FUN_00401f60(&stack0xffffff34,(undefined4 *)&DAT_0058170c,3);
    uStack_28 = 8;
    piVar4 = FUN_00404ab0(pvVar2,&stack0xffffff34);
    if ((uint)piVar4[6] < 0x10) {
      piVar4 = piVar4 + 1;
    }
    else {
      piVar4 = (int *)piVar4[1];
    }
    iVar6 = FUN_00433e00((char *)piVar4);
    iVar6 = FUN_00427410(iVar6);
    piVar3[0x2a] = iVar6;
  }
  uStack_28 = 0xffffffff;
  *(undefined1 *)(piVar3 + 0x1d) = 1;
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  FUN_00401f60(auStack_4c,(undefined4 *)&DAT_00586e28,1);
  uStack_28 = 9;
  uStack_6c = 0xf;
  uStack_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  FUN_00401f60(auStack_84,(undefined4 *)&DAT_00586e2c,1);
  uStack_28._0_1_ = 10;
  uStack_88 = 0xf;
  uStack_8c = 0;
  uStack_9c = uStack_9c & 0xffffff00;
  FUN_00401f60(&uStack_a0,(undefined4 *)&DAT_0058165c,1);
  uStack_28._0_1_ = 0xb;
  uStack_50 = 0xf;
  uStack_54 = 0;
  uStack_64 = uStack_64 & 0xffffff00;
  FUN_00401f60(auStack_68,(undefined4 *)&DAT_00581660,1);
  uStack_28 = CONCAT31(uStack_28._1_3_,0xc);
  piStack_a8 = FUN_00404ab0(pvVar2,auStack_4c);
  if ((uint)piStack_a8[6] < 0x10) {
    piStack_a8 = piStack_a8 + 1;
  }
  else {
    piStack_a8 = (int *)piStack_a8[1];
  }
  piVar4 = FUN_00404ab0(pvVar2,auStack_84);
  if ((uint)piVar4[6] < 0x10) {
    piVar4 = piVar4 + 1;
  }
  else {
    piVar4 = (int *)piVar4[1];
  }
  piVar7 = FUN_00404ab0(pvVar2,&uStack_a0);
  if ((uint)piVar7[6] < 0x10) {
    piVar7 = piVar7 + 1;
  }
  else {
    piVar7 = (int *)piVar7[1];
  }
  piVar8 = FUN_00404ab0(pvVar2,auStack_68);
  if ((uint)piVar8[6] < 0x10) {
    piVar8 = piVar8 + 1;
  }
  else {
    piVar8 = (int *)piVar8[1];
  }
  iVar6 = *piVar3;
  _atol((char *)piStack_a8);
  _atol((char *)piVar4);
  _atol((char *)piVar7);
  _atol((char *)piVar8);
  (**(code **)(iVar6 + 100))();
  if (0xf < uStack_60) {
    _free(pvStack_74);
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < uStack_98) {
    _free(piVar4);
  }
  uStack_98 = 0xf;
  uStack_9c = 0;
  if (0xf < uStack_7c) {
    _free(pvStack_90);
  }
  uStack_7c = 0xf;
  local_80 = (void *)0x0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  uStack_38 = 0xffffffff;
  if (0xf < uStack_44) {
    _free(pvStack_58);
  }
  uVar1 = _DAT_00581df8;
  uStack_44 = 0xf;
  pvStack_48 = (void *)0x0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  if ((iRam000002ff != 0) && (uStack_30 < (uint)(iRam00000303 - iRam000002ff >> 2))) {
    *(int **)(iRam000002ff + uStack_30 * 4) = piVar3;
    (**(code **)(*DAT_005b9f04 + 0x40))(uVar1);
    ExceptionList = pvStack_48;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00418c80();
}

