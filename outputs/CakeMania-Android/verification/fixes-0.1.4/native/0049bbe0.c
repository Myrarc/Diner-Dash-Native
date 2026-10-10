/* Native address 0049bbe0; read-only Ghidra audit recovery. */

void __thiscall
FUN_0049bbe0(void *this,int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar2 = FUN_00560568();
  local_24 = (undefined4)uVar2;
  uVar2 = FUN_00560568();
  local_20 = (undefined4)uVar2;
  local_1c = param_4;
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_18 = param_5;
  local_14 = 0;
  local_10 = 0;
  puVar1 = (undefined4 *)((int)this + 0x20);
  if (*(char *)((int)this + 0x38) == '\0') {
    puVar1 = &DAT_005b5504;
  }
  (**(code **)(**(int **)((int)this + 4) + 0x28))
            (param_1,&local_24,&local_14,(int)this + 0x10,puVar1,*(undefined4 *)((int)this + 0x34),
             *(undefined1 *)((int)this + 0x39));
  return;
}

