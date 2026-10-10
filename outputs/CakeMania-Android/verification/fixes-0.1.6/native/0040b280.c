/* Native address 0040b280; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0040b280(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  float10 fVar3;
  
  if ((param_2 < 0) || (5 < param_2)) {
    fVar3 = (float10)_DAT_0059d334;
  }
  else {
    fVar3 = (float10)_DAT_0058141c;
    piVar2 = *(int **)(param_2 * 0x10 + 0xac + param_1);
    piVar1 = *(int **)((param_2 + 0xb) * 0x10 + param_1);
    if (piVar2 != piVar1) {
      do {
        if ((*piVar2 <= param_3) && (param_3 < piVar2[1])) {
          fVar3 = (float10)(float)piVar2[2];
        }
        piVar2 = piVar2 + 3;
      } while (piVar2 != piVar1);
      return fVar3;
    }
  }
  return fVar3;
}

