/* Native address 00434a60; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00434a60(void *this,void *param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float local_10;
  float local_c;
  
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,1);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_10,0,0,0,0x7a);
    FUN_00493640(param_1,puVar3);
  }
  iVar1 = *(int *)((int)this + 4);
  if ((iVar1 != 0) &&
     (((*(char *)((int)this + 0xd1) == '\0' && (*(char *)((int)this + 0xd0) != '\0')) ||
      (*(char *)((int)this + 0xd0) == '\0')))) {
    uVar6 = FUN_00560568();
    uVar4 = (undefined4)uVar6;
    uVar6 = FUN_00560568();
    uVar7 = (undefined4)uVar6;
    FUN_00560568();
    uVar6 = FUN_00560568();
    uVar8 = (undefined4)uVar6;
    FUN_00560568();
    uVar6 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar1,(int)uVar6,uVar8,uVar7,uVar4);
  }
  piVar5 = *(int **)((int)this + 0x28);
  if (piVar5 != *(int **)((int)this + 0x2c)) {
    do {
      iVar1 = *piVar5;
      pfVar2 = *(float **)(iVar1 + 0xac);
      if (pfVar2 != (float *)0x0) {
        local_10 = (float)*(int *)(iVar1 + 0x40) * _DAT_00581420 +
                   (float)(*(int *)(iVar1 + 0x38) + *(int *)((int)this + 0x4c));
        local_c = (float)(*(int *)(iVar1 + 0x44) + *(int *)(iVar1 + 0x3c) +
                         *(int *)((int)this + 0x50));
        *pfVar2 = local_10;
        pfVar2[1] = local_c;
        FUN_00406570(*(void **)(*piVar5 + 0xac),param_1);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != *(int **)((int)this + 0x2c));
  }
  iVar1 = *(int *)((int)this + 8);
  if ((iVar1 != 0) &&
     (((*(char *)((int)this + 0xd1) == '\0' && (*(char *)((int)this + 0xd0) != '\0')) ||
      (*(char *)((int)this + 0xd0) == '\0')))) {
    uVar6 = FUN_00560568();
    uVar4 = (undefined4)uVar6;
    uVar6 = FUN_00560568();
    uVar7 = (undefined4)uVar6;
    FUN_00560568();
    uVar6 = FUN_00560568();
    uVar8 = (undefined4)uVar6;
    FUN_00560568();
    uVar6 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar1,(int)uVar6,uVar8,uVar7,uVar4);
  }
  piVar5 = *(int **)((int)this + 0x28);
  if (piVar5 != *(int **)((int)this + 0x2c)) {
    do {
      if (*(char *)(*piVar5 + 0x69) != '\0') {
        uVar8 = 0x1e;
        uVar7 = 0x1e;
        FUN_00560568();
        uVar6 = FUN_00560568();
        uVar4 = (undefined4)uVar6;
        FUN_00560568();
        uVar6 = FUN_00560568();
        FUN_0049bbe0(param_1,DAT_005b9618,(int)uVar6,uVar4,uVar7,uVar8);
      }
      piVar5 = piVar5 + 1;
    } while (piVar5 != *(int **)((int)this + 0x2c));
  }
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,0);
    puVar3 = (undefined4 *)FUN_0048c7e0(&local_10,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar3);
  }
  return;
}

