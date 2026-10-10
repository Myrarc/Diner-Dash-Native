/* Native address 0040d370; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040d370(void *this,void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined2 unaff_DI;
  float10 fVar7;
  float10 fVar8;
  ulonglong uVar9;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = *(int *)((int)this + 800);
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0x268) - *(float *)((int)this + 0x264)) *
                         _DAT_005813fc + *(float *)((int)this + 0x264)) * (float)_DAT_005813f0 +
                       (float)_DAT_005813e8),unaff_DI);
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0x268) - *(float *)((int)this + 0x264)) *
                         _DAT_005813fc + *(float *)((int)this + 0x264)) * (float)_DAT_005813f0 +
                       (float)_DAT_005813e8),unaff_DI);
  FUN_00493710(*(int *)((int)this + iVar1 * 4 + 0x58));
  FUN_00493700(*(int *)((int)this + iVar1 * 4 + 0x58));
  if (*(char *)((int)this + 0x300) == '\0') {
    uVar9 = FUN_00560568();
    local_30 = (float)uVar9;
    local_34 = (float)(int)local_30;
    iVar2 = FUN_00493710(*(int *)((int)this + iVar1 * 4 + 0x58));
    local_30 = ((float)iVar2 * *(float *)((int)this + iVar1 * 4 + 0x94)) /
               (float)*(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0xc);
    fVar7 = FUN_0040a4b0((int)this);
    local_28 = (float)((float10)local_34 - fVar7 * (float10)local_30);
    uVar9 = FUN_00560568();
    local_30 = (float)uVar9;
    local_34 = (float)(int)local_30;
    iVar2 = FUN_00493700(*(int *)((int)this + iVar1 * 4 + 0x58));
    local_30 = ((float)iVar2 * *(float *)((int)this + iVar1 * 4 + 0x94)) /
               (float)*(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0x10);
    fVar8 = FUN_0040a4b0((int)this);
    iVar2 = *(int *)((int)this + 0x58);
    fVar7 = (float10)_DAT_00581420;
    local_1c = local_28;
    *(float *)((int)this + 0x154) = local_28;
    local_2c = local_28;
    local_30 = (float)((float10)local_34 - fVar8 * (float10)local_30 * fVar7);
    *(float *)((int)this + 0x150) = local_30;
    local_20 = local_30;
    iVar3 = FUN_00493710(iVar2);
    local_28 = (float)iVar3;
    fVar7 = FUN_0040a4b0((int)this);
    local_30 = (float)((fVar7 * (float10)local_28 * (float10)*(float *)((int)this + 0x94) *
                       (float10)_DAT_0058141c) / (float10)*(int *)(iVar2 + 0xc) + (float10)local_1c)
    ;
    iVar2 = FUN_00493700(iVar2);
    local_28 = (float)iVar2;
    fVar7 = FUN_0040a4b0((int)this);
    *(float *)((int)this + 0x164) = local_30;
    *(float *)((int)this + 0x160) =
         (float)(fVar7 * (float10)local_28 * (float10)*(float *)((int)this + 0x94) *
                 (float10)(float)s_Afff_y_money_00581647._1_4_ + (float10)local_20);
    local_28 = (float)*(int *)((int)this + 0x1dc);
    local_24 = (float)*(int *)((int)this + 0x1e0);
    *(float *)((int)this + 0x158) = local_28;
    *(undefined1 *)((int)this + 0x195) = *(undefined1 *)((int)this + 0x270);
    *(float *)((int)this + 0x15c) = local_24;
    if (*(char *)((int)this + 0x26d) != '\0') {
      if (_DAT_0059d334 <= *(float *)((int)this + 0x54)) {
        *(undefined1 *)((int)this + 0x196) = 1;
        FUN_0040abc0((float *)((int)this + 0x150),param_1);
      }
      else {
        FUN_00409d40((void *)((int)this + 0x1c4),param_1);
        if (*(char *)((int)this + 0x196) != '\0') {
          *(undefined1 *)((int)this + 0x196) = 0;
          *(int *)((int)this + 0x1d4) = *(int *)(*(int *)((int)this + 0x1d0) + 0xc) + -1;
        }
      }
    }
    if (_DAT_0059d334 <= *(float *)((int)this + 0x54)) {
      iVar2 = *(int *)((int)this + 0x308);
      fVar7 = FUN_0040b280((int)this,iVar1,iVar2);
      if (fVar7 < (float10)*(float *)((int)this + 0x304)) {
        *(undefined4 *)((int)this + 0x304) = 0;
        *(int *)((int)this + 0x308) = iVar2 + 1;
      }
      iVar3 = iVar1 * 0x10;
      iVar2 = *(int *)((int)this + iVar3 + 0xfc);
      iVar5 = *(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0xc) + -1;
      if ((iVar2 != 0) && (*(int *)((int)this + iVar3 + 0x100) - iVar2 >> 2 != 0)) {
        if (iVar2 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)((int)this + iVar3 + 0x100) - iVar2 >> 2;
        }
        iVar5 = iVar5 + -1;
      }
      if ((iVar5 < *(int *)((int)this + 0x308)) &&
         (*(undefined4 *)((int)this + 0x308) = 0, *(int *)((int)this + 800) != 1)) {
        *(undefined4 *)((int)this + 800) = 0;
      }
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      local_34 = local_20;
      local_30 = local_1c;
      FUN_0040b140(this,&local_34,&local_30);
      uVar9 = FUN_00560568();
      local_10 = (int)uVar9;
      uVar9 = FUN_00560568();
      local_c = (int)uVar9;
      iVar2 = FUN_00493700(*(int *)((int)this + iVar1 * 4 + 0x58));
      local_28 = ((float)iVar2 * *(float *)((int)this + iVar1 * 4 + 0x94)) /
                 (float)*(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0x10);
      FUN_0040a4b0((int)this);
      uVar9 = FUN_00560568();
      local_8 = (int)uVar9;
      iVar2 = FUN_00493710(*(int *)((int)this + iVar1 * 4 + 0x58));
      local_28 = ((float)iVar2 * *(float *)((int)this + iVar1 * 4 + 0x94)) /
                 (float)*(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0xc);
      FUN_0040a4b0((int)this);
      uVar9 = FUN_00560568();
      local_4 = (int)uVar9;
      *(float *)((int)this + 8) = (float)(local_8 / 2 + local_10);
      local_28 = (float)(local_4 / 2 + local_c);
      uVar6 = iVar5 - *(int *)((int)this + 0x308);
      *(float *)((int)this + 0xc) = (float)(int)local_28;
      iVar2 = *(int *)((int)this + iVar3 + 0xfc);
      if ((iVar2 != 0) && (uVar6 < (uint)(*(int *)((int)this + iVar3 + 0x100) - iVar2 >> 2))) {
        if ((iVar2 == 0) || ((uint)(*(int *)((int)this + iVar3 + 0x100) - iVar2 >> 2) <= uVar6)) {
                    /* WARNING: Subroutine does not return */
          FUN_00406800();
        }
        uVar6 = (*(int *)(*(int *)((int)this + iVar1 * 4 + 0x58) + 0xc) -
                *(int *)(iVar2 + uVar6 * 4)) - 1;
      }
      if ((*(char *)((int)this + 0x270) == '\0') || (*(char *)((int)this + 0x196) != '\0')) {
        if ((iVar1 == 3) && (*(char *)((int)this + 0x196) == '\0')) {
          FUN_0040a790(this,param_1,3);
        }
        else {
          FUN_0049eff0(param_1,*(int *)((int)this + iVar1 * 4 + 0x58),(int)&local_10,uVar6);
        }
      }
      else {
        FUN_0040a590(this,param_1,iVar1);
      }
    }
    if ((*(float *)((int)this + 0x50) < _DAT_0059d334 !=
         (*(float *)((int)this + 0x50) == _DAT_0059d334)) && (*(char *)((int)this + 0x26d) == '\0'))
    {
      FUN_0040abc0((void *)((int)this + 0x150),param_1);
    }
    uVar9 = FUN_00560568();
    *(int *)((int)this + 0x228) = 0x1e - *(int *)((int)this + 0x10);
    *(int *)((int)this + 0x22c) = (int)uVar9;
    if (*(char *)((int)this + 0x26d) == '\0') {
      FUN_0040b790((void *)((int)this + 0x1ec),param_1);
      return;
    }
  }
  else {
    if (*(int *)((int)this + 0x2e8) != 0) {
      local_10 = *(int *)((int)this + 0x2f0);
      local_c = *(int *)((int)this + 0x2f4);
      local_8 = 0;
      local_4 = 0;
      local_8 = FUN_00493700(*(int *)((int)this + 0x2e8));
      local_4 = FUN_00493710(*(int *)((int)this + 0x2e8));
      local_4 = local_4 / *(int *)(*(int *)((int)this + 0x2e8) + 0xc);
      FUN_00493670(param_1,1);
      puVar4 = (undefined4 *)FUN_0048c7e0(&local_20,0xff,0xff,0xff,200);
      FUN_00493640(param_1,puVar4);
      FUN_0049eff0(param_1,*(int *)((int)this + 0x2e8),(int)&local_10,*(int *)((int)this + 0x2ec));
      FUN_00493670(param_1,0);
      puVar4 = (undefined4 *)FUN_0048c7e0(&local_20,0xff,0xff,0xff,0xff);
      FUN_00493640(param_1,puVar4);
    }
    if ((*(char *)((int)this + 0x26d) != '\0') && (*(float *)((int)this + 0x54) < _DAT_0059d334)) {
      FUN_00409d40((void *)((int)this + 0x1c4),param_1);
      if (*(char *)((int)this + 0x196) != '\0') {
        *(undefined1 *)((int)this + 0x196) = 0;
        *(int *)((int)this + 0x1d4) = *(int *)(*(int *)((int)this + 0x1d0) + 0xc) + -1;
      }
    }
  }
  return;
}

