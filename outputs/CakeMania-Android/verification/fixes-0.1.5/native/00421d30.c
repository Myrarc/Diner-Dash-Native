/* Native address 00421d30; read-only Ghidra audit recovery. */

void * __thiscall FUN_00421d30(void *this,void *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)((int)this + 0xdc) == 0) {
    iVar2 = *(int *)((int)this + 0xb0);
    if ((iVar2 == 0) ||
       ((uint)((*(int *)((int)this + 0xb4) - iVar2) / 0xbc) <= *(uint *)((int)this + 0xd4))) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    iVar2 = *(uint *)((int)this + 0xd4) * 0xbc + 0xac + iVar2;
  }
  else {
    if (*(int *)((int)this + 0xdc) != 1) {
      FUN_00421b80((int)param_1);
      return param_1;
    }
    iVar2 = *(int *)((int)this + 0xc0);
    if ((iVar2 == 0) ||
       ((uint)((*(int *)((int)this + 0xc4) - iVar2) / 0xcc) <= *(uint *)((int)this + 0xd4))) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    iVar2 = *(uint *)((int)this + 0xd4) * 0xcc + 0xbc + iVar2;
  }
  iVar1 = *(int *)(iVar2 + 4);
  uVar3 = *(int *)((int)this + 0xd8) - 1;
  if ((iVar1 == 0) || ((uint)((*(int *)(iVar2 + 8) - iVar1) / 200) <= uVar3)) {
    FUN_0041fc10();
  }
  FUN_00420ed0(param_1,(undefined4 *)(uVar3 * 200 + iVar1));
  return param_1;
}

