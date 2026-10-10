/* Address: 00419b40; name: FUN_00419b40 */

void __thiscall FUN_00419b40(void *this,int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (piVar1 = *(int **)(param_1 + 0x30); piVar1 != *(int **)(param_1 + 0x34); piVar1 = piVar1 + 1)
  {
    iVar3 = iVar3 - *(int *)(*piVar1 + 0x24);
  }
  iVar2 = *(int *)((int)this + 0x10) + iVar3;
  *(int *)((int)this + 0x10) = iVar2;
  if (iVar2 < 0) {
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  FUN_00419ab0(this,iVar3,param_2,param_3);
  return;
}


