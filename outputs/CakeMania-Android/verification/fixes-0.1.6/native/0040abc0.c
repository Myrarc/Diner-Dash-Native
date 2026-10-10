/* Native address 0040abc0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040abc0(void *this,void *param_1)

{
  float *pfVar1;
  float10 fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  float local_20;
  float fStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 local_10 [3];
  int local_4;
  
  FUN_00493670(param_1,1);
  if ((*(float *)((int)this + 0x3c) <= _DAT_0059d334) || (0x1e < *(int *)((int)this + 0x38))) {
    uVar13 = 0xff;
    uVar12 = 0xff;
  }
  else {
    uVar13 = 100;
    uVar12 = 100;
  }
  puVar4 = (undefined4 *)FUN_0048c7b0(local_10,0xff,uVar12,uVar13);
  FUN_00493640(param_1,puVar4);
  local_20 = (float)FUN_00493700(*(int *)((int)this + 0x18));
  uVar10 = FUN_00560568();
  local_20 = (float)uVar10;
  FUN_00493710(*(int *)((int)this + 0x18));
  uVar11 = FUN_00560568();
  iVar5 = (int)uVar11;
  FUN_00493700(*(int *)((int)this + 0x18));
  uVar11 = FUN_00560568();
  iVar6 = (int)uVar11;
  FUN_00493710(*(int *)((int)this + 0x18));
  uVar11 = FUN_00560568();
  iVar7 = (int)uVar11;
  if (*(char *)((int)this + 0x46) == '\0') {
    if (*(char *)((int)this + 0x45) == '\0') {
      iVar8 = *(int *)((int)this + 0x18);
    }
    else {
      iVar8 = *(int *)((int)this + 0x1c);
    }
    FUN_0049bbe0(param_1,iVar8,iVar6,iVar7,(float)uVar10,iVar5);
  }
  puVar4 = (undefined4 *)FUN_0048c7b0(local_10,0,0,0);
  FUN_00493640(param_1,puVar4);
  FUN_00493670(param_1,0);
  if (*(void **)((int)this + 0x48) != (void *)0x0) {
    FUN_0040aaf0(*(void **)((int)this + 0x48),local_10);
    if (((*(char *)((int)this + 0x46) != '\0') && (4 < *(int *)((int)this + 0x70))) &&
       (*(int *)((int)this + 0x70) < 0x10)) {
      FUN_0049ba50(param_1,*(int *)((int)this + 0x50));
    }
    if ((*(char *)((int)this + 0x54) == '\0') && (4 < *(int *)((int)this + 0x70))) {
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9bc8);
      *(undefined1 *)((int)this + 0x54) = 1;
    }
    if ((iVar5 != 0) && (local_4 != 0)) {
      fVar3 = ((float)local_4 * _DAT_00581470) / (float)iVar5;
      *(float *)(*(int *)((int)this + 0x48) + 8) =
           fVar3 * *(float *)(*(int *)((int)this + 0x48) + 8);
      *(float *)(*(int *)((int)this + 0x48) + 0xc) =
           fVar3 * *(float *)(*(int *)((int)this + 0x48) + 0xc);
      pfVar1 = *(float **)((int)this + 0x48);
      if ((pfVar1[0xc] == 0.0) || ((uint)((int)pfVar1[0xd] - (int)pfVar1[0xc] >> 2) < 4)) {
        local_20 = (float)((int)local_20 / 2 + iVar6);
        uVar10 = FUN_00560568();
        local_20 = (float)(int)uVar10;
        fStack_1c = (float)((local_4 + iVar5) / 2 + iVar7);
        *pfVar1 = local_20;
        pfVar1[1] = fStack_1c;
        fVar9 = extraout_ST0;
      }
      else {
        local_20 = (float)((int)local_20 / 2 + iVar6);
        uVar10 = FUN_00560568();
        local_20 = (float)(int)uVar10;
        uVar10 = FUN_00560568();
        fStack_1c = (float)(int)uVar10;
        *pfVar1 = local_20;
        pfVar1[1] = fStack_1c;
        fVar9 = extraout_ST0_00;
      }
      fVar2 = (float10)_DAT_005814a4;
      *(float *)(*(int *)((int)this + 0x48) + 8) =
           (float)((fVar2 / fVar9) * (float10)*(float *)(*(int *)((int)this + 0x48) + 8));
      *(float *)(*(int *)((int)this + 0x48) + 0xc) =
           (float)((fVar2 / fVar9) * (float10)*(float *)(*(int *)((int)this + 0x48) + 0xc));
    }
    if (*(int *)((int)this + 0x70) < 7) {
      uVar10 = FUN_00560568();
      FUN_00406340(*(void **)((int)this + 0x48),param_1,(int)uVar10);
    }
    if (*(char *)((int)this + 0x46) != '\0') {
      if ((*(int *)((int)this + 0x70) < 5) || (0xf < *(int *)((int)this + 0x70))) {
        FUN_00493670(param_1,1);
        puVar4 = (undefined4 *)FUN_0048c7e0(local_10,0xff,0xff,0xff,0x96);
        FUN_00493640(param_1,puVar4);
      }
      iVar5 = *(int *)((int)this + 0x4c);
      fStack_1c = (float)(iVar7 + -0x32);
      local_20 = (float)(iVar6 + 5);
      iStack_18 = 0;
      uStack_14 = 0;
      iStack_18 = FUN_00493700(iVar5);
      iStack_18 = iStack_18 / *(int *)(iVar5 + 0x10);
      uStack_14 = FUN_00493710(iVar5);
      FUN_0049eff0(param_1,*(int *)((int)this + 0x4c),(int)&local_20,*(int *)((int)this + 0x70));
      if ((*(int *)((int)this + 0x70) < 5) || (0xf < *(int *)((int)this + 0x70))) {
        puVar4 = (undefined4 *)FUN_0048c7b0(local_10,0,0,0);
        FUN_00493640(param_1,puVar4);
        FUN_00493670(param_1,0);
      }
    }
  }
  return;
}

