/* Address: 00407870; name: FUN_00407870 */

uint __thiscall FUN_00407870(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  
  if ((*(int *)((int)this + 0x30) != 0) &&
     (*(int *)((int)this + 0x34) - *(int *)((int)this + 0x30) >> 2 != 0)) {
    uVar1 = *(uint *)((int)this + 0x34);
    if ((((*(int *)(*(int *)(uVar1 - 4) + 0x2c) == 3) ||
         ((*(int *)(*(int *)(uVar1 - 4) + 0x2c) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) ||
        ((*(int *)(*(int *)(uVar1 - 4) + 0x2c) == 1 && (*(int *)(param_1 + 0x2c) == 1)))) ||
       ((*(int *)(param_1 + 0x2c) == 2 &&
        (uVar1 = *(uint *)(*(int *)(uVar1 - 4) + 0x2c), uVar1 != 0)))) {
      return uVar1 & 0xffffff00;
    }
  }
  if ((*(int *)((int)this + 0x30) == 0) ||
     (*(int *)((int)this + 0x34) - *(int *)((int)this + 0x30) >> 2 == 0)) {
    uVar4 = FUN_00560568();
    *(int *)((int)this + 0x28) = (int)uVar4;
    uVar4 = FUN_00560568();
    iVar2 = (int)uVar4;
  }
  else {
    *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + *(int *)(param_1 + 0x10);
    uVar4 = FUN_00560568();
    iVar2 = (int)uVar4;
    if (iVar2 <= *(int *)((int)this + 0x24)) goto LAB_00407915;
  }
  *(int *)((int)this + 0x24) = iVar2;
LAB_00407915:
  uVar3 = FUN_00407820((void *)((int)this + 0x2c),&param_1);
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


