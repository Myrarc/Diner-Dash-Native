/* Native address 00409d40; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00409d40(void *this,void *param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0x28;
  uVar3 = 0x28;
  if (_DAT_00581618 < *(float *)((int)this + 0x14)) {
    FUN_00493710(*(int *)((int)this + 4));
    uVar2 = FUN_00560568();
    uVar1 = (undefined4)uVar2;
    FUN_00493700(*(int *)((int)this + 4));
    uVar2 = FUN_00560568();
    FUN_0049bbe0(param_1,*(int *)((int)this + 4),(int)uVar2,uVar1,uVar3,uVar4);
    return;
  }
  FUN_00493710(*(int *)((int)this + 4));
  uVar2 = FUN_00560568();
  uVar1 = (undefined4)uVar2;
  FUN_00493700(*(int *)((int)this + 4));
  uVar2 = FUN_00560568();
  FUN_0049bbe0(param_1,*(int *)((int)this + 8),(int)uVar2,uVar1,uVar3,uVar4);
  return;
}

