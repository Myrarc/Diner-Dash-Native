/* Native address 00434480. Recovered in read-only Ghidra session. */

uint __thiscall Recovered_00434480(int param_1,float param_2,float param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = *(int **)(param_1 + 0x28);
  if (piVar2 != *(int **)(param_1 + 0x2c)) {
    do {
      iVar1 = *piVar2;
      uVar3 = FUN_00401010(*(int *)(iVar1 + 0x38) + *(int *)(param_1 + 0x4c),
                           *(int *)(iVar1 + 0x3c) + *(int *)(param_1 + 0x50),*(int *)(iVar1 + 0x40),
                           *(int *)(iVar1 + 0x44),param_2,param_3);
      if ((char)uVar3 != '\0') {
        *(undefined1 *)(*piVar2 + 0x69) = 1;
        return CONCAT31((int3)((uint)piVar2 >> 8),1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(param_1 + 0x2c));
  }
  return (uint)piVar2 & 0xffffff00;
}

