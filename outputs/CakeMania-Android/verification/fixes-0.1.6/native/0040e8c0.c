/* Native address 0040e8c0; read-only Ghidra audit recovery. */

void __thiscall FUN_0040e8c0(void *this,void *param_1)

{
  undefined4 *puVar1;
  
  FUN_0040d9d0((int)this);
  puVar1 = (undefined4 *)(*(int *)((int)this + 0x18) + -4);
  if (puVar1 != (undefined4 *)(*(int *)((int)this + 0x14) + -4)) {
    do {
      FUN_0040d370((void *)*puVar1,param_1);
      puVar1 = puVar1 + -1;
    } while (puVar1 != (undefined4 *)(*(int *)((int)this + 0x14) + -4));
  }
  return;
}

