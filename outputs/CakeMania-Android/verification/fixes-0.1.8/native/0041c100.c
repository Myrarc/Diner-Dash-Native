/* Native address 0041c100; read-only Ghidra audit recovery. */

void __thiscall FUN_0041c100(void *this,undefined ***param_1)

{
  void *pvVar1;
  undefined4 *this_00;
  undefined4 in_stack_ffffffcc;
  uint in_stack_ffffffd0;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00574dbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)((int)this + 0x62c) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)((int)this + 0x62c))();
  }
  *(undefined4 *)((int)this + 0x62c) = 0;
  pvVar1 = operator_new(0x210);
  uStack_4 = 0;
  if (pvVar1 == (void *)0x0) {
    this_00 = (undefined4 *)0x0;
  }
  else {
    this_00 = FUN_0041b7d0(pvVar1,this);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 **)((int)this + 0x62c) = this_00;
  FUN_00456610(this_00,"ComicsScreen/comics_screen.xml",param_1);
  pvVar1 = (void *)(in_stack_ffffffd0 & 0xffffff00);
  FUN_00401e70(&stack0xffffffcc,(void *)(*(int *)((int)this + 0x62c) + 0x180),0,0xffffffff);
  FUN_0041a4d0((void *)(*(int *)((int)this + 0x62c) + 0xec),this,in_stack_ffffffcc,pvVar1);
  *(void **)(*(int *)((int)this + 0x62c) + 0x84) = this;
  pvVar1 = *(void **)((int)this + 0x8c);
  (**(code **)(**(int **)((int)this + 0x62c) + 100))();
  FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x62c));
  FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x62c));
  ExceptionList = pvVar1;
  return;
}

