/* Native address 00409c00; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00409c00(void *this,void *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  FUN_0049ba50(param_1,*(int *)((int)this + 0x18));
  fVar1 = -((*(float *)this * _DAT_00581610) / *(float *)((int)this + 4));
  if (*(char *)((int)this + 0x24) != '\0') {
    fVar1 = _DAT_0059d334;
  }
  iVar8 = 0;
  iVar7 = 0x23;
  iVar6 = 5;
  dVar5 = (double)fVar1;
  FUN_00493710(*(int *)((int)this + 0x18));
  uVar4 = FUN_00560568();
  iVar3 = *(int *)((int)this + 0x20);
  iVar2 = FUN_00493710(*(int *)((int)this + 0x14));
  iVar3 = ((iVar3 - (int)uVar4) - iVar2) + 0x13;
  FUN_00493700(*(int *)((int)this + 0x18));
  FUN_00493700(*(int *)((int)this + 0x14));
  uVar4 = FUN_00560568();
  FUN_0049efb0((int)param_1,*(int *)((int)this + 0x14),(int)uVar4,iVar3,dVar5,iVar6,iVar7,iVar8);
  if (*(char *)((int)this + 0x30) != '\0') {
    iVar3 = -0x99 - *(int *)((int)this + 0x20);
    if (0 < iVar3) {
      FUN_0049bbe0(param_1,DAT_005b964c,*(undefined4 *)((int)this + 0x1c),0,100,0x50);
      return;
    }
    FUN_0049bbe0(param_1,DAT_005b964c,*(undefined4 *)((int)this + 0x1c),iVar3,100,0x50);
  }
  return;
}

