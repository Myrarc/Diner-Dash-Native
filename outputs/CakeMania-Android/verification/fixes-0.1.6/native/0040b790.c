/* Native address 0040b790; read-only Ghidra audit recovery. */

void __thiscall FUN_0040b790(void *this,void *param_1)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  piVar2 = *(int **)((int)this + 0x60);
  if (piVar2 != *(int **)((int)this + 100)) {
    do {
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        local_8 = 0;
        local_4 = 0;
        uVar3 = FUN_00560568();
        local_10 = (undefined4)uVar3;
        local_c = *(int *)((int)this + 0x40) + piVar2[3];
        local_8 = *(undefined4 *)(iVar1 + 4);
        local_4 = *(int *)(iVar1 + 8) / *(int *)(iVar1 + 0xc);
        FUN_0049eff0(param_1,iVar1,(int)&local_10,piVar2[1]);
      }
      piVar2 = piVar2 + 6;
    } while (piVar2 != *(int **)((int)this + 100));
  }
  return;
}

