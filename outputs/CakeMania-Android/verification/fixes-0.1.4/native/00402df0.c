/* Native address 00402df0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00402df0(void *this,void *param_1,char param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int iVar13;
  int *extraout_EDX;
  int *piVar14;
  undefined4 unaff_EDI;
  float10 fVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined2 uVar18;
  float fStack_30;
  float fStack_2c;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  uVar18 = (undefined2)unaff_EDI;
  piVar14 = *(int **)((int)this + 0xa918);
  if (piVar14 != *(int **)((int)this + 0xa91c)) {
    do {
      if (*piVar14 != 0) {
        local_10 = piVar14[1];
        local_c = piVar14[2];
        local_8 = 0;
        local_4 = 0;
        local_8 = FUN_00493700(*piVar14);
        iVar2 = *piVar14;
        local_4 = FUN_00493710(iVar2);
        local_4 = local_4 / *(int *)(iVar2 + 0xc);
        FUN_0049eff0(param_1,iVar2,(int)&local_10,piVar14[5]);
      }
      uVar18 = (undefined2)unaff_EDI;
      piVar14 = piVar14 + 6;
    } while (piVar14 != *(int **)((int)this + 0xa91c));
  }
  iVar2 = *(int *)((int)this + 0x9dc0);
  uVar16 = CONCAT44(*(uint *)((int)this + 0x9d14),iVar2);
  if ((iVar2 == 0) ||
     ((uint)(*(int *)((int)this + 0x9dc4) - iVar2 >> 2) <= *(uint *)((int)this + 0x9d14))) {
    uVar16 = FUN_004023a0();
  }
  iVar2 = *(int *)((int)uVar16 + (int)((ulonglong)uVar16 >> 0x20) * 4);
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  fVar15 = FUN_0055ff20((double)(((*(float *)((int)this + 0x1c) - _DAT_005813f8) *
                                  (*(float *)((int)this + 0x9db4) - *(float *)((int)this + 0x9db0))
                                  * _DAT_005813fc + *(float *)((int)this + 0x9db0)) *
                                 (float)_DAT_005813f0 + (float)_DAT_005813e8),uVar18);
  iVar13 = *(int *)((int)this + 0x9dc0);
  uVar8 = *(uint *)((int)this + 0x9d14);
  fVar1 = (float)(fVar15 * (float10)_DAT_005813e0 * (float10)*(float *)((int)this + 0x9cec));
  if ((iVar13 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar13 >> 2) <= uVar8)) {
    uVar8 = FUN_004023a0();
    iVar13 = extraout_ECX;
  }
  iVar13 = **(int **)(iVar13 + uVar8 * 4);
  if ((*(int *)((int)this + 0x9dc0) == 0) ||
     ((uint)(*(int *)((int)this + 0x9dc4) - *(int *)((int)this + 0x9dc0) >> 2) <= uVar8)) {
    FUN_004023a0();
    iVar13 = extraout_ECX_00;
  }
  FUN_00493700(iVar13);
  uVar17 = FUN_00560568();
  local_20 = (int)uVar17;
  iVar13 = *(int *)((int)this + 0x9dc0);
  uVar8 = *(uint *)((int)this + 0x9d14);
  if ((iVar13 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar13 >> 2) <= uVar8)) {
    uVar8 = FUN_004023a0();
    iVar13 = extraout_ECX_01;
  }
  iVar13 = **(int **)(iVar13 + uVar8 * 4);
  if ((*(int *)((int)this + 0x9dc0) == 0) ||
     ((uint)(*(int *)((int)this + 0x9dc4) - *(int *)((int)this + 0x9dc0) >> 2) <= uVar8)) {
    FUN_004023a0();
    iVar13 = extraout_ECX_02;
  }
  FUN_00493710(iVar13);
  uVar17 = FUN_00560568();
  local_1c = (int)uVar17;
  iVar13 = *(int *)((int)this + 0x9dc0);
  uVar8 = *(uint *)((int)this + 0x9d14);
  if ((iVar13 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar13 >> 2) <= uVar8)) {
    uVar8 = FUN_004023a0();
    iVar13 = extraout_ECX_03;
  }
  iVar13 = **(int **)(iVar13 + uVar8 * 4);
  if ((*(int *)((int)this + 0x9dc0) == 0) ||
     ((uint)(*(int *)((int)this + 0x9dc4) - *(int *)((int)this + 0x9dc0) >> 2) <= uVar8)) {
    FUN_004023a0();
    iVar13 = extraout_ECX_04;
  }
  FUN_00493710(iVar13);
  uVar17 = FUN_00560568();
  local_14 = (undefined4)uVar17;
  iVar13 = *(int *)((int)this + 0x9dc0);
  uVar8 = *(uint *)((int)this + 0x9d14);
  if ((iVar13 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar13 >> 2) <= uVar8)) {
    uVar8 = FUN_004023a0();
    iVar13 = extraout_ECX_05;
  }
  iVar13 = **(int **)(iVar13 + uVar8 * 4);
  if ((*(int *)((int)this + 0x9dc0) == 0) ||
     ((uint)(*(int *)((int)this + 0x9dc4) - *(int *)((int)this + 0x9dc0) >> 2) <= uVar8)) {
    FUN_004023a0();
    iVar13 = extraout_ECX_06;
  }
  FUN_00493700(iVar13);
  uVar17 = FUN_00560568();
  local_18 = (undefined4)uVar17;
  if (*(char *)(iVar2 + 0x24) == '\0') {
    iVar13 = *(int *)((int)this + 0x9dc0);
    if ((iVar13 == 0) ||
       ((uint)(*(int *)((int)this + 0x9dc4) - iVar13 >> 2) <= *(uint *)((int)this + 0x9d14))) {
      FUN_004023a0();
    }
    uVar17 = FUN_00560568();
    FUN_0049eff0(param_1,**(int **)(iVar13 + *(int *)((int)this + 0x9d14) * 4),(int)&local_20,
                 (int)uVar17);
  }
  iVar13 = *(int *)((int)this + 0x9cf0);
  if (iVar13 != 0) {
    fVar3 = *(float *)(iVar13 + 8);
    fVar4 = *(float *)(iVar13 + 0xc);
    fStack_30 = 0.0;
    fStack_2c = 0.0;
    *(float *)(iVar13 + 8) = fVar3 * _DAT_00581474;
    *(float *)(*(int *)((int)this + 0x9cf0) + 0xc) = fVar4 * _DAT_00581474;
    puVar12 = *(undefined4 **)((int)this + 0x9cf0);
    *puVar12 = 0;
    puVar12[1] = 0;
    FUN_004017c0(*(void **)((int)this + 0x9cf0),&local_10);
    pfVar5 = *(float **)((int)this + 0x9cf0);
    fStack_30 = fVar1 * *(float *)(iVar2 + 0x1c) + (float)local_20;
    fStack_2c = fVar1 * *(float *)(iVar2 + 0x20) + (float)local_1c;
    *pfVar5 = fStack_30;
    pfVar5[1] = fStack_2c;
    piVar14 = *(int **)(*(int *)((int)this + 0x9cf0) + 0x30);
    if ((piVar14 == (int *)0x0) ||
       (*(int *)(*(int *)((int)this + 0x9cf0) + 0x34) - (int)piVar14 >> 2 == 0)) {
      FUN_004023a0();
      piVar14 = extraout_EDX;
    }
    if (*(int *)(*piVar14 + 0x2c) != 4) {
      fStack_30 = *(float *)((int)this + 0x9cf0);
      uVar9 = FUN_00493710(DAT_005b9974);
      uVar10 = FUN_00493700(DAT_005b9974);
      FUN_00493710(DAT_005b9974);
      uVar17 = FUN_00560568();
      uVar11 = (undefined4)uVar17;
      FUN_00493700(DAT_005b9974);
      uVar17 = FUN_00560568();
      FUN_0049bbe0(param_1,DAT_005b9974,(int)uVar17,uVar11,uVar10,uVar9);
    }
    FUN_00406450(*(void **)((int)this + 0x9cf0),param_1);
    *(float *)(*(int *)((int)this + 0x9cf0) + 8) = fVar3;
    *(float *)(*(int *)((int)this + 0x9cf0) + 0xc) = fVar4;
  }
  if (*(char *)(iVar2 + 0x24) != '\0') {
    iVar2 = *(int *)((int)this + 0x9dc0);
    uVar8 = *(uint *)((int)this + 0x9d14);
    if ((iVar2 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar2 >> 2) <= uVar8)) {
      FUN_004023a0();
    }
    uVar17 = FUN_00560568();
    FUN_0049eff0(param_1,**(int **)(iVar2 + uVar8 * 4),(int)&local_20,(int)uVar17);
  }
  iVar2 = *(int *)((int)this + 4);
  if (*(int *)((int)this + (iVar2 + *(int *)((int)this + 0x9d14) * 4) * 0x28 + 0x9dcc) != 0) {
    iVar13 = *(int *)((int)this + 0x9d14);
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar17 = FUN_00560568();
    local_10 = (int)uVar17;
    uVar17 = FUN_00560568();
    local_c = (int)uVar17;
    iVar6 = *(int *)((int)this + 4);
    iVar7 = *(int *)((int)this + 0x9d14);
    fStack_30 = (float)FUN_00493710(*(int *)((int)this + (iVar2 + iVar13 * 4) * 0x28 + 0x9dcc));
    uVar17 = FUN_00560568();
    local_4 = (int)uVar17;
    iVar2 = *(int *)((int)this + 4);
    fStack_30 = (float)FUN_00493700(*(int *)((int)this + (iVar6 + iVar7 * 4) * 0x28 + 0x9dcc));
    uVar17 = FUN_00560568();
    local_8 = (undefined4)uVar17;
    if ((iVar2 == 0) && (param_2 != '\0')) {
      FUN_00493670(param_1,1);
      puVar12 = (undefined4 *)FUN_0048c7e0(&fStack_30,0,0,0,0x7a);
      FUN_00493640(param_1,puVar12);
    }
    uVar17 = FUN_00560568();
    FUN_0049eff0(param_1,*(int *)((int)this +
                                 (*(int *)((int)this + 4) + *(int *)((int)this + 0x9d14) * 4) * 0x28
                                 + 0x9dcc),(int)&local_10,(int)uVar17);
    if ((*(int *)((int)this + 4) == 0) && (param_2 != '\0')) {
      FUN_00493670(param_1,0);
      puVar12 = (undefined4 *)FUN_0048c7e0(&fStack_30,0xff,0xff,0xff,0xff);
      FUN_00493640(param_1,puVar12);
    }
  }
  return;
}

