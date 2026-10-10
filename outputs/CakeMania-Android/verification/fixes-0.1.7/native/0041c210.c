/* Address: 0041c210; name: FUN_0041c210 */

void __thiscall FUN_0041c210(void *this,int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  LPCSTR pCVar3;
  undefined4 in_stack_fffffe38;
  uint in_stack_fffffe3c;
  undefined1 auStack_19c [200];
  undefined1 auStack_d4 [184];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_005750a4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)((int)this + 0x604) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)((int)this + 0x604))();
  }
  *(undefined4 *)((int)this + 0x604) = 0;
  pvVar1 = operator_new(0x480);
  uStack_4 = 0;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_0044fa40(pvVar1,this);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 **)((int)this + 0x604) = puVar2;
  pvVar1 = FUN_00421d30((void *)((int)this + 0x638),auStack_19c);
  uStack_4 = 1;
  FUN_00401f60((void *)((int)pvVar1 + 0x90),(undefined4 *)"TutorialScreen/pathes.xml",0x19);
  uStack_4 = 0xffffffff;
  FUN_0041b5a0((int)auStack_19c);
  FUN_00451c50(*(void **)((int)this + 0x604),"TutorialScreen/levels.xml",param_1);
  *(int *)(*(int *)((int)this + 0x604) + 0x19c) = (int)this + 0x664;
  *(int *)(*(int *)((int)this + 0x604) + 0x1b0) = (int)this + 0x664;
  *(int *)(*(int *)((int)this + 0x604) + 0x21c) = (int)this + 0x6ac;
  pvVar1 = FUN_00421d30((void *)((int)this + 0x638),auStack_d4);
  uStack_4 = 2;
  if (*(uint *)((int)pvVar1 + 0xa8) < 0x10) {
    pCVar3 = (LPCSTR)((int)pvVar1 + 0x94);
  }
  else {
    pCVar3 = *(LPCSTR *)((int)pvVar1 + 0x94);
  }
  FUN_00410a20((void *)(*(int *)((int)this + 0x604) + 0x1fc),pCVar3);
  uStack_4 = 0xffffffff;
  FUN_0041b5a0((int)auStack_d4);
  FUN_004440a0((void *)(*(int *)((int)this + 0x604) + 0x1ac),"TutorialScreen/level_env.xml",'\x01');
  pvVar1 = (void *)(in_stack_fffffe3c & 0xffffff00);
  FUN_00401f60(&stack0xfffffe38,(undefined4 *)&DAT_0058161c,0);
  FUN_00405c80(*(void **)(*(int *)((int)this + 0x604) + 0x1a8),"TutorialScreen/avatar.xml",
               in_stack_fffffe38,pvVar1);
  pvVar1 = (void *)((uint)pvVar1 & 0xffffff00);
  FUN_00401e70(&stack0xfffffe38,(void *)(*(int *)((int)this + 0x604) + 0x410),0,0xffffffff);
  FUN_0041a4d0((void *)(*(int *)((int)this + 0x604) + 0x368),this,in_stack_fffffe38,pvVar1);
  *(void **)(*(int *)((int)this + 0x604) + 0x300) = this;
  (**(code **)(**(int **)((int)this + 0x604) + 100))();
  FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x604));
  FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x604));
  ExceptionList = pvStack_1c;
  return;
}


