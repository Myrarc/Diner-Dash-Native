/* Address: 004017c0; name: FUN_004017c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004017c0(void *this,undefined4 *param_1)

{
  undefined2 unaff_DI;
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0xc) - *(float *)((int)this + 8)) * _DAT_005813fc +
                        *(float *)((int)this + 8)) * (float)_DAT_005813f0 + (float)_DAT_005813e8),
               unaff_DI);
  uVar1 = FUN_00560568();
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0xc) - *(float *)((int)this + 8)) * _DAT_005813fc +
                        *(float *)((int)this + 8)) * (float)_DAT_005813f0 + (float)_DAT_005813e8),
               unaff_DI);
  uVar2 = FUN_00560568();
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0xc) - *(float *)((int)this + 8)) * _DAT_005813fc +
                        *(float *)((int)this + 8)) * (float)_DAT_005813f0 + (float)_DAT_005813e8),
               unaff_DI);
  uVar3 = FUN_00560568();
  FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                         (*(float *)((int)this + 0xc) - *(float *)((int)this + 8)) * _DAT_005813fc +
                        *(float *)((int)this + 8)) * (float)_DAT_005813f0 + (float)_DAT_005813e8),
               unaff_DI);
  uVar4 = FUN_00560568();
  *param_1 = (int)uVar1;
  param_1[2] = (int)uVar3;
  param_1[1] = (int)uVar2;
  param_1[3] = (int)uVar4;
  return;
}


