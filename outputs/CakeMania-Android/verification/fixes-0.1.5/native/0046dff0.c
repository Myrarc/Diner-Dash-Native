/* Native address 0046dff0; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0046dff0(void *this,void *param_1)

{
  uint uVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  double dVar12;
  int iVar13;
  uint uStack_360;
  int local_348;
  void *pvStack_344;
  int iStack_340;
  int iStack_33c;
  undefined4 uStack_334;
  uint uStack_330;
  undefined4 uStack_32c;
  int iStack_328;
  undefined4 uStack_324;
  undefined4 uStack_320;
  undefined1 auStack_31c [4];
  void *pvStack_318;
  undefined4 uStack_308;
  uint uStack_304;
  undefined1 auStack_300 [4];
  void *pvStack_2fc;
  undefined4 uStack_2ec;
  uint uStack_2e8;
  undefined1 auStack_2e4 [4];
  void *pvStack_2e0;
  undefined4 uStack_2d0;
  uint uStack_2cc;
  undefined1 auStack_2c8 [4];
  void *pvStack_2c4;
  undefined4 uStack_2b4;
  uint uStack_2b0;
  undefined1 auStack_2ac [4];
  void *pvStack_2a8;
  undefined4 uStack_298;
  uint uStack_294;
  char acStack_290 [128];
  char acStack_210 [128];
  char acStack_190 [128];
  char acStack_110 [128];
  char acStack_90 [128];
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_0057b522;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)FUN_0048c7b0(&local_348,0,0,0);
  FUN_00493640(param_1,puVar3);
  FUN_0049b8e0(param_1,0,0,*(undefined4 *)((int)this + 0x34),*(undefined4 *)((int)this + 0x38));
  FUN_004785c0(*(int *)((int)this + 0x17c));
  FUN_00437d20((void *)((int)this + 0x84),param_1,FUN_00401000);
  if (*(int *)((int)this + 0x2d8) != 0) {
    FUN_0049bcd0(param_1,*(int *)((int)this + 0x2d8),(float)*(int *)((int)this + 0x2e4),
                 (float)*(int *)((int)this + 0x2e8));
  }
  if ((*(int *)((int)this + 0x2c4) != 0) || (*(int *)((int)this + 0x2b8) != 0)) {
    FUN_00493670(param_1,1);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0x7a);
    FUN_00493640(param_1,puVar3);
    iVar13 = 0;
    iVar4 = FUN_00493710(DAT_005b99a4);
    iVar4 = iVar4 / 2;
    iVar5 = FUN_00493700(DAT_005b99a4);
    iVar5 = iVar5 / 2;
    dVar12 = (double)-*(float *)((int)this + 0x2d0);
    iVar6 = FUN_00493710(DAT_005b99a4);
    iVar8 = 0x15e - iVar6 / 2;
    iVar6 = FUN_00493700(DAT_005b99a4);
    FUN_0049efb0((int)param_1,DAT_005b99a4,0x7d - iVar6 / 2,iVar8,dVar12,iVar5,iVar4,iVar13);
    iVar13 = 0;
    iVar4 = FUN_00493710(DAT_005b9798);
    iVar4 = iVar4 / 2;
    iVar5 = FUN_00493700(DAT_005b9798);
    iVar5 = iVar5 / 2;
    dVar12 = (double)*(float *)((int)this + 0x2d0);
    iVar6 = FUN_00493710(DAT_005b9798);
    iVar8 = 0x15e - iVar6 / 2;
    iVar6 = FUN_00493700(DAT_005b9798);
    FUN_0049efb0((int)param_1,DAT_005b9798,0x7d - iVar6 / 2,iVar8,dVar12,iVar5,iVar4,iVar13);
    FUN_00493670(param_1,0);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar3);
    if (*(int *)((int)this + 0x2b8) != 0) {
      FUN_00493670(param_1,1);
      puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0x96);
      FUN_00493640(param_1,puVar3);
      (**(code **)(**(int **)((int)this + 0x2b8) + 8))
                (param_1,*(undefined4 *)((int)this + 0x420),*(undefined4 *)((int)this + 0x424),
                 *(undefined4 *)((int)this + 0x428),*(undefined4 *)((int)this + 0x42c));
      FUN_00493670(param_1,0);
      puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0xff);
      FUN_00493640(param_1,puVar3);
    }
  }
  if (((*(int *)((int)this + 0x2c4) != 0) && (*(int *)((int)this + 0x2b8) == 0)) &&
     (iVar4 = *(int *)(*(int *)((int)this + 0x2c4) + 8), iVar4 != 0)) {
    FUN_0049bbe0(param_1,iVar4,0x32,0x113,0x96,0x96);
  }
  if ((*(int *)((int)this + 0x2b8) != 0) &&
     (iVar4 = *(int *)(*(int *)((int)this + 0x2b8) + 0x10), iVar4 != 0)) {
    FUN_0049bbe0(param_1,iVar4,0x32,0x113,0x96,0x96);
  }
  if (*(int *)((int)this + 0x174) != 0) {
    FUN_00493670(param_1,1);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0x7a);
    FUN_00493640(param_1,puVar3);
    iVar13 = 0;
    iVar4 = FUN_00493710(DAT_005b9a8c);
    iVar4 = iVar4 / 2;
    iVar5 = FUN_00493700(DAT_005b9a8c);
    iVar5 = iVar5 / 2;
    dVar12 = (double)-*(float *)((int)this + 0x2d0);
    iVar6 = FUN_00493710(DAT_005b9a8c);
    iVar8 = 0x16a - iVar6 / 2;
    iVar6 = FUN_00493700(DAT_005b9a8c);
    FUN_0049efb0((int)param_1,DAT_005b9a8c,0x1ad - iVar6 / 2,iVar8,dVar12,iVar5,iVar4,iVar13);
    FUN_00493670(param_1,0);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_348,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar3);
    FUN_00493710(DAT_005b9cc4);
    FUN_00493700(DAT_005b9cc4);
    FUN_0049ba50(param_1,DAT_005b9cc4);
    iVar4 = *(int *)((int)this + 0x174);
    *(undefined4 *)(iVar4 + 0x18) = 0x43d70000;
    *(undefined4 *)(iVar4 + 0x1c) = 0x43af0000;
    FUN_00402df0(*(void **)((int)this + 0x174),param_1,'\0');
    FUN_004040e0(*(void **)((int)this + 0x174),0.01);
  }
  iVar4 = *(int *)((int)this + 0x178);
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x18) = 0x43d70000;
    *(undefined4 *)(iVar4 + 0x1c) = 0x43c80000;
  }
  iVar4 = *(int *)((int)this + 0x2c0);
  if (((iVar4 != 0) || (*(int *)((int)this + 0x2cc) != 0)) && (*(int *)((int)this + 0x2fc) != 0)) {
    local_348 = 0;
    pvStack_344 = (void *)0x0;
    iStack_340 = 0;
    iStack_33c = 0;
    if (iVar4 == 0) {
      iVar4 = *(int *)((int)this + 0x2cc);
      iVar5 = *(int *)(iVar4 + 0x9dc0);
      uVar11 = CONCAT44(iVar5,iVar4);
      uVar1 = *(uint *)(iVar4 + 0x9d14);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar4 + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        uVar11 = FUN_004023a0();
      }
      iVar5 = (int)uVar11;
      iVar4 = **(int **)((int)((ulonglong)uVar11 >> 0x20) + uVar1 * 4);
      if ((*(int *)(iVar5 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar5 + 0x9dc4) - *(int *)(iVar5 + 0x9dc0) >> 2) <=
          *(uint *)(iVar5 + 0x9d14))) {
        iVar5 = FUN_004023a0();
      }
      FUN_004010d0(iVar5);
      FUN_00493710(iVar4);
      iVar4 = *(int *)((int)this + 0x2cc);
      iVar5 = *(int *)(iVar4 + 0x9dc0);
      uVar11 = CONCAT44(iVar5,iVar4);
      uVar1 = *(uint *)(iVar4 + 0x9d14);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar4 + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        uVar11 = FUN_004023a0();
      }
      iVar5 = (int)uVar11;
      iVar4 = **(int **)((int)((ulonglong)uVar11 >> 0x20) + uVar1 * 4);
      if ((*(int *)(iVar5 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar5 + 0x9dc4) - *(int *)(iVar5 + 0x9dc0) >> 2) <=
          *(uint *)(iVar5 + 0x9d14))) {
        iVar5 = FUN_004023a0();
      }
      FUN_004010d0(iVar5);
      FUN_00493700(iVar4);
      iVar4 = *(int *)((int)this + 0x2cc);
      iVar5 = *(int *)(iVar4 + 0x9dc0);
      uVar1 = *(uint *)(iVar4 + 0x9d14);
      if ((iVar5 == 0) || ((uint)(*(int *)(iVar4 + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        iVar5 = FUN_004023a0();
      }
      iVar5 = **(int **)(iVar5 + uVar1 * 4);
      if ((*(int *)(iVar4 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar4 + 0x9dc4) - *(int *)(iVar4 + 0x9dc0) >> 2) <=
          *(uint *)(iVar4 + 0x9d14))) {
        FUN_004023a0();
      }
      if ((*(int *)(iVar4 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar4 + 0x9dc4) - *(int *)(iVar4 + 0x9dc0) >> 2) <=
          *(uint *)(iVar4 + 0x9d14))) {
        FUN_004023a0();
      }
      FUN_00560568();
      FUN_00493700(iVar5);
      FUN_004010d0(iVar4);
      uVar10 = FUN_00560568();
      local_348 = (int)uVar10;
      iVar4 = *(int *)((int)this + 0x2cc);
      iVar5 = *(int *)(iVar4 + 0x9dc0);
      uVar11 = CONCAT44(*(uint *)(iVar4 + 0x9d14),iVar5);
      if ((iVar5 == 0) ||
         ((uint)(*(int *)(iVar4 + 0x9dc4) - iVar5 >> 2) <= *(uint *)(iVar4 + 0x9d14))) {
        uVar11 = FUN_004023a0();
      }
      iVar5 = **(int **)((int)uVar11 + (int)((ulonglong)uVar11 >> 0x20) * 4);
      if ((*(int *)(iVar4 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar4 + 0x9dc4) - *(int *)(iVar4 + 0x9dc0) >> 2) <=
          *(uint *)(iVar4 + 0x9d14))) {
        FUN_004023a0();
      }
      if ((*(int *)(iVar4 + 0x9dc0) == 0) ||
         ((uint)(*(int *)(iVar4 + 0x9dc4) - *(int *)(iVar4 + 0x9dc0) >> 2) <=
          *(uint *)(iVar4 + 0x9d14))) {
        FUN_004023a0();
      }
      FUN_00560568();
      FUN_00493710(iVar5);
      FUN_004010d0(iVar4);
      uVar10 = FUN_00560568();
      local_348 = local_348 + 10;
      pvStack_344 = (void *)((int)uVar10 + 0x50);
    }
    else if (*(int *)(iVar4 + 0x60) == 8) {
      FUN_00560568();
      uVar10 = FUN_00560568();
      local_348 = (int)uVar10;
      FUN_00560568();
      uVar10 = FUN_00560568();
      pvStack_344 = (void *)uVar10;
    }
    else {
      FUN_00560568();
      uVar10 = FUN_00560568();
      local_348 = (int)uVar10;
      FUN_00560568();
      uVar10 = FUN_00560568();
      pvStack_344 = (void *)uVar10;
    }
    iVar4 = *(int *)((int)this + 0x2fc);
    iStack_340 = *(int *)(iVar4 + 4) / *(int *)(iVar4 + 0x10);
    iStack_33c = *(int *)(iVar4 + 8) / *(int *)(iVar4 + 0xc);
    uVar10 = FUN_00560568();
    FUN_0049eff0(param_1,iVar4,(int)&local_348,(int)uVar10);
    fVar2 = *(float *)((int)this + 0x194) + _DAT_00585f98;
    *(float *)((int)this + 0x194) = fVar2;
    if ((float)*(int *)(*(int *)((int)this + 0x2fc) + 0xc) <= fVar2) {
      *(undefined4 *)((int)this + 0x194) = 0;
    }
  }
  puVar3 = (undefined4 *)((int)this + 0x220);
  iVar4 = FUN_00418c60((int)puVar3);
  if (iVar4 == 0) {
    *puVar3 = *(undefined4 *)((int)this + 0x17c);
    FUN_00419090(puVar3,param_1,(int)this + 0x2ec);
  }
  if (*(int *)((int)this + 0x2d4) != 0) {
    FUN_0049bcd0(param_1,*(int *)((int)this + 0x2d4),(float)*(int *)((int)this + 0x2dc),
                 (float)*(int *)((int)this + 0x2e0));
  }
  uStack_360 = 0;
  do {
    uStack_294 = 0xf;
    uStack_298 = 0;
    pvStack_2a8 = (void *)((uint)pvStack_2a8 & 0xffffff00);
    iStack_4 = 0;
    if (uStack_360 == 0) {
      if (*(int *)((int)this + 0x2b8) != 0) {
        FUN_00401e70(auStack_2ac,(void *)(*(int *)((int)this + 0x2b8) + 0x98),0,0xffffffff);
      }
      if (*(int *)((int)this + 0x2c4) != 0) {
        FUN_00401e70(auStack_2ac,(void *)(*(int *)((int)this + 0x2c4) + 0x9d54),0,0xffffffff);
      }
    }
    else if (uStack_360 == 1) {
      if (*(int *)((int)this + 0x2b8) != 0) {
        FUN_00401e70(auStack_2ac,(void *)(*(int *)((int)this + 0x2b8) + 0x7c),0,0xffffffff);
      }
      if (*(int *)((int)this + 0x2c4) != 0) {
        FUN_00401e70(auStack_2ac,(void *)(*(int *)((int)this + 0x2c4) + 0x9d38),0,0xffffffff);
      }
    }
    else if (uStack_360 == 2) {
      if (*(int *)((int)this + 0x2b8) != 0) {
        _sprintf(acStack_290,"%d",*(undefined4 *)(*(int *)((int)this + 0x2b8) + 0x74));
        pvVar7 = FUN_0041a420(&local_348,(void *)((int)this + 0x398),acStack_290);
        iStack_4._0_1_ = 1;
        FUN_00401e70(auStack_2ac,pvVar7,0,0xffffffff);
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        if (0xf < uStack_330) {
          _free(pvStack_344);
        }
        uStack_330 = 0xf;
        uStack_334 = 0;
        pvStack_344 = (void *)((uint)pvStack_344 & 0xffffff00);
      }
      if (*(int *)((int)this + 0x2c4) != 0) {
        _sprintf(acStack_110,"%d",*(undefined4 *)(*(int *)((int)this + 0x2c4) + 0x9d8c));
        pvVar7 = FUN_0041a420(auStack_31c,(void *)((int)this + 0x398),acStack_110);
        iStack_4._0_1_ = 2;
        FUN_00401e70(auStack_2ac,pvVar7,0,0xffffffff);
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        if (0xf < uStack_304) {
          _free(pvStack_318);
        }
        uStack_304 = 0xf;
        uStack_308 = 0;
        pvStack_318 = (void *)((uint)pvStack_318 & 0xffffff00);
      }
    }
    else if (uStack_360 == 3) {
      iVar4 = FUN_00421870((void *)(*(int *)((int)this + 0x17c) + 0x638));
      _sprintf(acStack_210,"%d",*(undefined4 *)(iVar4 + 0x3c));
      pvVar7 = FUN_0041a420(auStack_300,(void *)((int)this + 0x3b4),acStack_210);
      iStack_4._0_1_ = 3;
      FUN_00401e70(auStack_2ac,pvVar7,0,0xffffffff);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      if (0xf < uStack_2e8) {
        _free(pvStack_2fc);
      }
      uStack_2e8 = 0xf;
      uStack_2ec = 0;
      pvStack_2fc = (void *)((uint)pvStack_2fc & 0xffffff00);
    }
    else if (uStack_360 == 4) {
      if (*(int *)((int)this + 0x17c) != 0) {
        iVar4 = FUN_00421870((void *)(*(int *)((int)this + 0x17c) + 0x638));
        _sprintf(acStack_190,"%d",*(undefined4 *)(iVar4 + 0x44));
        pvVar7 = FUN_0041a420(auStack_2e4,(void *)((int)this + 0x3d0),acStack_190);
        iStack_4._0_1_ = 4;
        FUN_00401e70(auStack_2ac,pvVar7,0,0xffffffff);
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        if (0xf < uStack_2cc) {
          _free(pvStack_2e0);
        }
        uStack_2cc = 0xf;
        uStack_2d0 = 0;
        pvStack_2e0 = (void *)((uint)pvStack_2e0 & 0xffffff00);
      }
    }
    else if ((uStack_360 == 5) && (*(int *)((int)this + 0x17c) != 0)) {
      iVar4 = FUN_00421870((void *)(*(int *)((int)this + 0x17c) + 0x638));
      _sprintf(acStack_90,"%d",*(undefined4 *)(iVar4 + 0x48));
      pvVar7 = FUN_0041a420(auStack_2c8,(void *)((int)this + 0x3ec),acStack_90);
      iStack_4._0_1_ = 5;
      FUN_00401e70(auStack_2ac,pvVar7,0,0xffffffff);
      iStack_4 = (uint)iStack_4._1_3_ << 8;
      if (0xf < uStack_2b0) {
        _free(pvStack_2c4);
      }
      uStack_2b0 = 0xf;
      uStack_2b4 = 0;
      pvStack_2c4 = (void *)((uint)pvStack_2c4 & 0xffffff00);
    }
    iVar4 = 0;
    if (uStack_360 == 0) {
      uVar9 = *(undefined4 *)(DAT_005b9e30 + 0x10);
      *(undefined4 *)(DAT_005b9e30 + 0x10) = *(undefined4 *)((int)this + 0x408);
      FUN_00493630(param_1,DAT_005b9e30);
      iVar4 = (**(code **)(*(int *)this + 0xcc))();
    }
    else {
      uVar9 = *(undefined4 *)(DAT_005b9f04 + 0x10);
      *(undefined4 *)(DAT_005b9f04 + 0x10) = *(undefined4 *)((int)this + uStack_360 * 4 + 0x408);
      FUN_00493630(param_1,DAT_005b9f04);
    }
    FUN_00493640(param_1,&DAT_005b5504);
    if (iVar4 == 0) {
      (**(code **)(*(int *)this + 200))
                (param_1,(void *)((uStack_360 + 0x30) * 0x10 + (int)this),auStack_2ac,0xffffffff,0);
      *(undefined4 *)(DAT_005b9f04 + 0x10) = uVar9;
    }
    else {
      iVar5 = (uStack_360 + 0x30) * 0x10;
      uStack_32c = *(undefined4 *)(iVar5 + (int)this);
      uStack_324 = *(undefined4 *)((int)this + iVar5 + 8);
      uStack_320 = *(undefined4 *)((int)this + iVar5 + 0xc);
      iStack_328 = (*(int *)(uStack_360 * 0x10 + 0x30c + (int)this) / 2 - iVar4 / 2) +
                   *(int *)((int)this + uStack_360 * 0x10 + 0x304);
      (**(code **)(*(int *)this + 200))(param_1,&uStack_32c,auStack_2ac);
      *(undefined4 *)(DAT_005b9e30 + 0x10) = uVar9;
    }
    iStack_4 = 0xffffffff;
    if (0xf < uStack_294) {
      _free(pvStack_2a8);
    }
    uStack_360 = uStack_360 + 1;
    uStack_294 = 0xf;
    uStack_298 = 0;
    pvStack_2a8 = (void *)((uint)pvStack_2a8 & 0xffffff00);
  } while (uStack_360 < 6);
  if (*(char *)((int)this + 0x2b4) == '\0') {
    iVar4 = FUN_00418c60((int)this + 0x220);
    if (iVar4 == 0) {
      FUN_00419090((void *)((int)this + 0x220),param_1,(int)this + 0x2ec);
    }
  }
  else {
    FUN_00418d20((void *)((int)this + 0x1b8),param_1,(int)this + 0x2ec);
  }
  ExceptionList = pvStack_c;
  return;
}

