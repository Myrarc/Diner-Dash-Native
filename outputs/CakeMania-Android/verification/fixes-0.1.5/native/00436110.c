/* Native address 00436110; read-only Ghidra audit recovery. */

undefined4 __thiscall FUN_00436110(void *this,float param_1,float param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  puVar1 = *(undefined4 **)((int)this + 0x34);
  if (puVar1 == *(undefined4 **)((int)this + 0x38)) {
    return 0;
  }
  do {
    uVar3 = FUN_00560568();
    uVar4 = FUN_00560568();
    uVar5 = FUN_00560568();
    uVar6 = FUN_00560568();
    uVar2 = FUN_00401010((int)uVar3,(int)uVar4,(int)uVar5,(int)uVar6,param_1,param_2);
    if ((char)uVar2 != '\0') {
      return *puVar1;
    }
    puVar1 = puVar1 + 1;
  } while (puVar1 != *(undefined4 **)((int)this + 0x38));
  return 0;
}

