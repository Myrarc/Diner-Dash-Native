/* Native address 0044c650; read-only Ghidra audit recovery. */

/* WARNING: Removing unreachable block (ram,0x0044c704) */

undefined4 * __thiscall FUN_0044c650(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined1 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0057923c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004d87e0(this);
  *(undefined ***)((int)this + 0x80) = &PTR_LAB_00588260;
  *(undefined ***)this = &PTR_FUN_00586c20;
  *(undefined ***)((int)this + 0x80) = &PTR_LAB_00586c04;
  *(undefined4 *)((int)this + 0x8c) = 0;
  *(undefined4 *)((int)this + 0x90) = 0;
  *(undefined4 *)((int)this + 0x94) = 0;
  *(undefined4 *)((int)this + 0x15c) = 0;
  *(undefined4 *)((int)this + 0x160) = 0;
  *(undefined4 *)((int)this + 0x164) = 0;
  local_4._0_1_ = 2;
  local_4._1_3_ = 0;
  FUN_00409ab0((undefined4 *)((int)this + 0x168));
  local_4._0_1_ = 3;
  FUN_0044be80((int)this + 0x1ac);
  local_4._0_1_ = 4;
  FUN_00418020((int)this + 0x1fc);
  *(undefined4 *)((int)this + 0x2c8) = 0;
  *(undefined4 *)((int)this + 0x2cc) = 0;
  *(undefined4 *)((int)this + 0x2d0) = 0;
  *(undefined4 *)((int)this + 0x2c8) = 0;
  *(undefined4 *)((int)this + 0x2cc) = 0;
  *(undefined4 *)((int)this + 0x2d0) = 0;
  *(undefined4 *)((int)this + 0x2c0) = 0x40a00000;
  local_4._0_1_ = 6;
  FUN_0041b6b0((undefined4 *)((int)this + 0x330));
  local_4._0_1_ = 7;
  FUN_0041b720((undefined4 *)((int)this + 0x398));
  *(undefined4 *)((int)this + 0x460) = 0xf;
  *(undefined4 *)((int)this + 0x45c) = 0;
  *(undefined1 *)((int)this + 0x44c) = 0;
  local_4._0_1_ = 9;
  *(undefined4 *)((int)this + 0x84) = param_1;
  *(undefined4 *)((int)this + 0x2e8) = 0;
  *(undefined4 *)((int)this + 0x444) = 0;
  *(undefined4 *)((int)this + 0x43c) = 0;
  *(undefined4 *)((int)this + 0x98) = 0;
  *(undefined4 *)((int)this + 0x440) = 0;
  *(undefined4 *)((int)this + 0x308) = 0;
  puVar1 = operator_new(0xa924);
  local_4._0_1_ = 10;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_004059f0(puVar1);
  }
  *(undefined4 **)((int)this + 0x1a8) = puVar1;
  puVar1[8] = *(undefined4 *)((int)this + 0x84);
  local_4._0_1_ = 9;
  *(undefined1 **)(*(int *)((int)this + 0x1a8) + 0x9db8) = &LAB_0044ab40;
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar2 + 4) = 0;
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0;
    *(undefined4 *)((int)pvVar2 + 0x10) = 0;
    *(undefined4 *)((int)pvVar2 + 0x14) = 0;
    *(undefined4 *)((int)pvVar2 + 0x18) = 0;
    *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
  }
  *(void **)((int)this + 0x1a4) = pvVar2;
  *(undefined4 *)((int)this + 0x2f8) = 0;
  DAT_005ba070 = this;
  *(undefined4 *)((int)this + 0x150) = 0x3f800000;
  *(undefined4 *)((int)this + 0x154) = 0;
  *(undefined4 *)((int)this + 0x2fc) = 0;
  *(undefined4 *)((int)this + 0x300) = 0;
  *(undefined4 *)((int)this + 0x304) = 0;
  local_4 = CONCAT31(local_4._1_3_,9);
  if (*(void **)((int)this + 0x15c) != (void *)0x0) {
    _free(*(void **)((int)this + 0x15c));
  }
  *(undefined4 *)((int)this + 0x15c) = 0;
  *(undefined4 *)((int)this + 0x160) = 0;
  *(undefined4 *)((int)this + 0x164) = 0;
  *(undefined1 *)((int)this + 0x2e4) = 1;
  *(undefined4 *)((int)this + 0x2d4) = 0;
  *(undefined4 *)((int)this + 0x2d8) = 0;
  *(undefined4 *)((int)this + 0x2dc) = 0;
  *(undefined4 *)((int)this + 0x30c) = 0;
  *(undefined4 *)(DAT_005b9f40 + 0x10) = 1;
  *(undefined4 *)(DAT_005b9f40 + 0xc) = 0x10;
  *(undefined4 *)((int)this + 0x24c) = *(undefined4 *)((int)this + 0x84);
  *(undefined4 *)((int)this + 0x1ac) = *(undefined4 *)((int)this + 0x84);
  *(undefined4 *)((int)this + 0x310) = 0;
  *(undefined4 *)((int)this + 0x318) = 0;
  *(undefined4 *)((int)this + 0x31c) = 0;
  *(undefined4 *)((int)this + 800) = 0;
  *(undefined4 *)((int)this + 0x314) = 0;
  *(undefined4 *)((int)this + 0x324) = 0;
  *(undefined4 *)((int)this + 0x328) = 0;
  *(undefined4 *)((int)this + 0x32c) = 0;
  *(undefined4 *)((int)this + 0x430) = 0;
  *(undefined1 *)((int)this + 0x18c) = 1;
  *(undefined1 *)((int)this + 0x434) = 0;
  *(undefined1 *)((int)this + 0x435) = 0;
  *(undefined1 *)((int)this + 0x2e5) = 0;
  *(undefined4 *)((int)this + 0x428) = 0;
  *(undefined1 *)((int)this + 0x42c) = 1;
  *(undefined1 *)((int)this + 0x464) = 0;
  puVar3 = operator_new(0x10);
  if (puVar3 == (undefined1 *)0x0) {
    *(undefined4 *)((int)this + 0x2e0) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + 8) = 0;
    *(undefined4 *)(puVar3 + 4) = 0x40000000;
    *(undefined4 *)(puVar3 + 0xc) = DAT_005b9e38;
    puVar3[1] = 0;
    *puVar3 = 0;
    *(undefined1 **)((int)this + 0x2e0) = puVar3;
  }
  ExceptionList = local_c;
  return this;
}

