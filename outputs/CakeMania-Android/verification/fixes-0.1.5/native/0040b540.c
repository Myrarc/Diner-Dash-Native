/* Native address 0040b540; read-only Ghidra audit recovery. */

int __thiscall FUN_0040b540(void *this,float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  piVar4 = *(int **)((int)this + 0x14);
  if (piVar4 != *(int **)((int)this + 0x18)) {
    do {
      iVar1 = *piVar4;
      if (*(char *)(iVar1 + 0x26d) != '\0') {
        FUN_00560568();
        FUN_00493700(*(int *)(iVar1 + 0x1c8));
        uVar5 = FUN_00560568();
        iVar1 = *piVar4;
        FUN_00560568();
        FUN_00493710(*(int *)(iVar1 + 0x1c8));
        uVar6 = FUN_00560568();
        iVar1 = FUN_00493700(*(int *)(*piVar4 + 0x1c8));
        iVar2 = FUN_00493710(*(int *)(*piVar4 + 0x1c8));
        uVar3 = FUN_00401010((int)uVar5,(int)uVar6,iVar2,iVar1,param_1,param_2);
        if ((char)uVar3 != '\0') {
          return *piVar4;
        }
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)((int)this + 0x18));
  }
  return 0;
}

