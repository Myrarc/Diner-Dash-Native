/* Native address 00460970; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00460970(void *this,void *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  void *this_00;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char ****ppppcVar9;
  int *piVar10;
  void *pvVar11;
  char ****ppppcVar12;
  int iVar13;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int *extraout_EDX_02;
  int *piVar14;
  undefined8 uVar15;
  double dVar16;
  void **ppvVar17;
  int iVar18;
  undefined4 uVar19;
  void *local_58;
  void *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  char ***pppcStack_2c;
  char ***apppcStack_28 [4];
  uint uStack_18;
  uint uStack_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0057a878;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  puVar5 = (undefined4 *)FUN_0048c7b0(&local_58,0,0,0);
  FUN_00493640(param_1,puVar5);
  FUN_0049b8e0(param_1,0,0,*(undefined4 *)((int)this + 0x34),*(undefined4 *)((int)this + 0x38));
  FUN_0049ba50(param_1,DAT_005b992c);
  FUN_00493670(param_1,1);
  puVar5 = (undefined4 *)FUN_0048c7e0(&local_58,0xff,0xff,0xff,0xff);
  FUN_00493640(param_1,puVar5);
  iVar18 = 0;
  iVar6 = FUN_00493710(DAT_005b9a5c);
  iVar6 = iVar6 / 2;
  iVar7 = FUN_00493700(DAT_005b9a5c);
  iVar7 = iVar7 / 2;
  dVar16 = (double)-*(float *)((int)this + 0x334);
  iVar8 = FUN_00493710(DAT_005b9a5c);
  iVar13 = 0xd5 - iVar8 / 2;
  iVar8 = FUN_00493700(DAT_005b9a5c);
  FUN_0049efb0((int)param_1,DAT_005b9a5c,0x256 - iVar8 / 2,iVar13,dVar16,iVar7,iVar6,iVar18);
  iVar18 = 0;
  iVar6 = FUN_00493710(DAT_005b9be8);
  iVar6 = iVar6 / 2;
  iVar7 = FUN_00493700(DAT_005b9be8);
  iVar7 = iVar7 / 2;
  dVar16 = (double)*(float *)((int)this + 0x334);
  iVar8 = FUN_00493710(DAT_005b9be8);
  iVar13 = 0xd5 - iVar8 / 2;
  iVar8 = FUN_00493700(DAT_005b9be8);
  FUN_0049efb0((int)param_1,DAT_005b9be8,0x256 - iVar8 / 2,iVar13,dVar16,iVar7,iVar6,iVar18);
  FUN_00493670(param_1,0);
  puVar5 = (undefined4 *)FUN_0048c7e0(&local_58,0xff,0xff,0xff,0xff);
  FUN_00493640(param_1,puVar5);
  FUN_0049ba50(param_1,DAT_005b97e0);
  FUN_0049eff0(param_1,*(int *)((int)this + 0x37c),(int)this + 0x35c,*(int *)((int)this + 0x33c));
  FUN_0049eff0(param_1,*(int *)((int)this + 0x380),(int)this + 0x36c,*(int *)((int)this + 0x34c));
  if (*(char *)((int)this + 0x338) == '\0') {
    if (*(int *)((int)this + 0x268) != 0) {
      FUN_0049ba50(param_1,*(int *)((int)this + 0x268));
      FUN_00493710(*(int *)((int)this + 0x268));
    }
    bVar4 = false;
    param_1 = (void *)0x0;
    if (*(int *)((int)this + 0x27c) != 0) {
      do {
        if (bVar4) {
          if (*(int *)((int)this + 0x26c) != 0) {
            FUN_0049ba50(this_00,*(int *)((int)this + 0x26c));
            iVar6 = *(int *)((int)this + 0x26c);
LAB_00460c06:
            FUN_00493710(iVar6);
          }
        }
        else if (*(int *)((int)this + 0x270) != 0) {
          FUN_0049ba50(this_00,*(int *)((int)this + 0x270));
          iVar6 = *(int *)((int)this + 0x270);
          goto LAB_00460c06;
        }
        bVar4 = !bVar4;
        param_1 = (void *)((int)param_1 + 1);
      } while (param_1 < *(void **)((int)this + 0x27c));
    }
    if (*(int *)((int)this + 0x274) != 0) {
      FUN_0049ba50(this_00,*(int *)((int)this + 0x274));
    }
    FUN_00493670(this_00,1);
    puVar5 = (undefined4 *)FUN_0048c7e0(&local_58,0xff,0xff,0xff,0x96);
    FUN_00493640(this_00,puVar5);
    FUN_0049bcd0(this_00,DAT_005b970c,595.0,495.0);
    FUN_00493670(this_00,0);
    puVar5 = (undefined4 *)FUN_0048c7e0(&local_58,0xff,0xff,0xff,0xff);
    FUN_00493640(this_00,puVar5);
    FUN_00493630(this_00,DAT_005b9f04);
    puVar5 = (undefined4 *)FUN_0048c7b0(&local_58,0xc3,0x20,0x26);
    FUN_00493640(this_00,puVar5);
    if (*(int *)((int)this + 0x254) != 0) {
      local_50 = *(undefined4 *)((int)this + 0x238);
      local_4c = *(undefined4 *)((int)this + 0x23c);
      local_54 = (void *)(*(int *)((int)this + 0x234) + *(int *)((int)this + 0xd8));
      local_58 = (void *)(*(int *)((int)this + 0x230) + *(int *)((int)this + 0xd4));
      (**(code **)(*(int *)this + 200))(this_00,&local_58,(int)this + 0x240,0xffffffff,0);
    }
    FUN_00493630(this_00,DAT_005b9f04);
    puVar5 = (undefined4 *)FUN_0048c7b0(&local_58,0,0,200);
    FUN_00493640(this_00,puVar5);
    uStack_14 = 0xf;
    uStack_18 = 0;
    apppcStack_28[0] = (char ***)((uint)apppcStack_28[0] & 0xffffff00);
    FUN_00401f60(&pppcStack_2c,(undefined4 *)"Current Player:",0xf);
    uStack_4 = 0;
    ppppcVar12 = (char ****)apppcStack_28[0];
    if (uStack_14 < 0x10) {
      ppppcVar12 = apppcStack_28;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    local_54 = (void *)((uint)local_54 & 0xffffff00);
    ppppcVar9 = ppppcVar12;
    do {
      cVar1 = *(char *)ppppcVar9;
      ppppcVar9 = (char ****)((int)ppppcVar9 + 1);
    } while (cVar1 != '\0');
    FUN_00401f60(&local_58,ppppcVar12,(int)ppppcVar9 - (int)((int)ppppcVar12 + 1));
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    piVar10 = (int *)FUN_00493620((int)this_00);
    uVar19 = 0x226;
    ppvVar17 = &local_58;
    iVar6 = (**(code **)(*piVar10 + 0x1c))();
    FUN_004936a0(this_00,&uStack_30,0x2b7 - iVar6 / 2,ppvVar17);
    puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
    if (0xf < uStack_44) {
      _free(local_58);
    }
    pvVar11 = FUN_004c1200(&stack0xffffffa4,"%s");
    puStack_8._0_1_ = 2;
    FUN_00401e70(&uStack_30,pvVar11,0,0xffffffff);
    puStack_8._0_1_ = 0;
    if (0xf < uStack_44) {
      _free(local_58);
    }
    if (uStack_18 < 0x10) {
      pppcStack_2c = (char ***)&pppcStack_2c;
    }
    uStack_44 = 0xf;
    uStack_48 = 0;
    local_58 = (void *)((uint)local_58 & 0xffffff00);
    ppppcVar12 = (char ****)pppcStack_2c;
    do {
      cVar1 = *(char *)ppppcVar12;
      ppppcVar12 = (char ****)((int)ppppcVar12 + 1);
    } while (cVar1 != '\0');
    FUN_00401f60(&stack0xffffffa4,pppcStack_2c,(int)ppppcVar12 - (int)((int)pppcStack_2c + 1));
    puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
    piVar10 = (int *)FUN_00493620((int)this_00);
    iVar6 = (**(code **)(*piVar10 + 0x1c))(&stack0xffffffa4,0x23f);
    FUN_004936a0(this_00,&pppcStack_2c,0x2b7 - iVar6 / 2,uVar19);
    uStack_4 = uStack_4 & 0xffffff00;
    if (0xf < uStack_40) {
      _free(local_54);
    }
    if (*(int *)((int)this + 0xdc) == 0xd) {
      puVar5 = (undefined4 *)FUN_0048c7b0(&local_58,0xc3,0x20,0x26);
      FUN_00493640(this_00,puVar5);
      uStack_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00401f60(&local_58,(undefined4 *)"Music volume:",0xd);
      iVar6 = *(int *)((int)this + 0xb4);
      uStack_4 = CONCAT31(uStack_4._1_3_,4);
      if ((iVar6 == 0) || (*(int *)((int)this + 0xb8) - iVar6 >> 2 == 0)) {
        iVar6 = FUN_0045fb00();
      }
      piVar10 = *(int **)((int)this + 0xb4);
      if ((piVar10 == (int *)0x0) || (*(int *)((int)this + 0xb8) - (int)piVar10 >> 2 == 0)) {
        iVar6 = FUN_0045fb00();
      }
      iVar7 = *(int *)((int)this + 0xb4);
      uVar15 = CONCAT44(iVar7,iVar6);
      if ((iVar7 == 0) || (*(int *)((int)this + 0xb8) - iVar7 >> 2 == 0)) {
        uVar15 = FUN_0045fb00();
      }
      FUN_004936a0(this_00,&local_58,*(undefined4 *)(*(int *)((ulonglong)uVar15 >> 0x20) + 0x2c),
                   (*(int *)(*(int *)uVar15 + 0x30) - *(int *)(*piVar10 + 0x38)) + 10);
      uStack_4 = uStack_4 & 0xffffff00;
      if (0xf < uStack_40) {
        _free(local_54);
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00401f60(&local_58,(undefined4 *)"Sound volume:",0xd);
      iVar6 = *(int *)((int)this + 0xb4);
      uStack_4 = CONCAT31(uStack_4._1_3_,5);
      if ((iVar6 == 0) || ((uint)(*(int *)((int)this + 0xb8) - iVar6 >> 2) < 2)) {
        FUN_0045fb00();
        iVar6 = extraout_EDX;
      }
      iVar7 = *(int *)((int)this + 0xb4);
      if ((iVar7 == 0) || ((uint)(*(int *)((int)this + 0xb8) - iVar7 >> 2) < 2)) {
        FUN_0045fb00();
        iVar6 = extraout_EDX_00;
      }
      iVar8 = *(int *)((int)this + 0xb4);
      if ((iVar8 == 0) || ((uint)(*(int *)((int)this + 0xb8) - iVar8 >> 2) < 2)) {
        FUN_0045fb00();
        iVar8 = extraout_ECX;
        iVar6 = extraout_EDX_01;
      }
      FUN_004936a0(this_00,&local_58,*(undefined4 *)(*(int *)(iVar8 + 4) + 0x2c),
                   (*(int *)(*(int *)(iVar6 + 4) + 0x30) - *(int *)(*(int *)(iVar7 + 4) + 0x38)) +
                   10);
      uStack_4 = uStack_4 & 0xffffff00;
      if (0xf < uStack_40) {
        _free(local_54);
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      local_54 = (void *)((uint)local_54 & 0xffffff00);
      FUN_00401f60(&local_58,(undefined4 *)"Full Screen",0xb);
      piVar10 = *(int **)((int)this + 0xc4);
      iVar6 = (int)this + 0xc0;
      uStack_4 = CONCAT31(uStack_4._1_3_,6);
      if ((piVar10 == (int *)0x0) || (*(int *)((int)this + 200) - (int)piVar10 >> 2 == 0)) {
        FUN_0045fb00();
        iVar6 = extraout_ECX_00;
      }
      piVar2 = *(int **)(iVar6 + 4);
      if ((piVar2 == (int *)0x0) || (*(int *)(iVar6 + 8) - (int)piVar2 >> 2 == 0)) {
        FUN_0045fb00();
        iVar6 = extraout_ECX_01;
      }
      piVar3 = *(int **)(iVar6 + 4);
      if ((piVar3 == (int *)0x0) || (*(int *)(iVar6 + 8) - (int)piVar3 >> 2 == 0)) {
        FUN_0045fb00();
        iVar6 = extraout_ECX_02;
      }
      piVar14 = *(int **)(iVar6 + 4);
      if ((piVar14 == (int *)0x0) || (*(int *)(iVar6 + 8) - (int)piVar14 >> 2 == 0)) {
        FUN_0045fb00();
        piVar14 = extraout_EDX_02;
      }
      FUN_004936a0(this_00,&local_58,*(int *)(*piVar3 + 0x2c) + 10 + *(int *)(*piVar14 + 0x34),
                   *(int *)(*piVar2 + 0x38) + -5 + *(int *)(*piVar10 + 0x30));
      uStack_4 = uStack_4 & 0xffffff00;
      if (0xf < uStack_40) {
        _free(local_54);
      }
    }
    iVar6 = *(int *)((int)this + 0x2d0);
    if (iVar6 != *(int *)((int)this + 0x2d4)) {
      do {
        if (*(int *)(iVar6 + 4) != 0) {
          iStack_34 = 0;
          uStack_30 = 0;
          iStack_3c = *(int *)(iVar6 + 8) + *(int *)((int)this + 0xd4);
          iVar7 = *(int *)(iVar6 + 4);
          iStack_38 = *(int *)((int)this + 0xd8) + *(int *)(iVar6 + 0xc);
          iStack_34 = FUN_00493700(iVar7);
          iStack_34 = iStack_34 / *(int *)(iVar7 + 0x10);
          uStack_30 = FUN_00493710(iVar7);
          FUN_0049eff0(this_00,*(int *)(iVar6 + 4),(int)&iStack_3c,*(int *)(iVar6 + 0x18));
        }
        iVar6 = iVar6 + 0x38;
      } while (iVar6 != *(int *)((int)this + 0x2d4));
    }
    uStack_4 = 0xffffffff;
    if (0xf < uStack_14) {
      _free(apppcStack_28[0]);
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    apppcStack_28[0] = (char ***)((uint)apppcStack_28[0] & 0xffffff00);
  }
  if (*(int *)((int)this + 0x2ec) == 5) {
    iVar6 = FUN_00418c60((int)this + 0x1a0);
    if (iVar6 == 0) {
      FUN_00419090((void *)((int)this + 0x1a0),this_00,(int)this + 0x90);
    }
    else if (((*(char *)((int)this + 0x338) != '\0') && (*(int **)((int)this + 0xe0) != (int *)0x0))
            && (iVar6 = (**(code **)(**(int **)((int)this + 0xe0) + 0x108))(1), iVar6 == 0)) {
      FUN_004601d0((int)this);
    }
  }
  else {
    FUN_00418d20((void *)((int)this + 0x138),this_00,(int)this + 0x90);
  }
  ExceptionList = pvStack_c;
  return;
}

