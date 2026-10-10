/* Native address 00403460; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00403460(void *this,float param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  int iVar2;
  int extraout_EDX;
  float10 fVar3;
  
  if (*(float *)((int)this + 0x10) == _DAT_0059d334) {
    fVar3 = FUN_00401130(param_1 - param_3,param_2 - param_4);
    iVar2 = 0;
    if (*(int *)((int)this + 0x9cf0) != 0) {
      iVar2 = *(int *)((int)this + 0x9d18);
    }
    if ((((float10)_DAT_0059d334 <= fVar3) &&
        (fVar3 < (float10)_DAT_0058148c != (fVar3 == (float10)_DAT_0058148c))) ||
       ((float10)_DAT_00581404 <= fVar3)) {
      *(int *)((int)this + 0x9d14) = iVar2 + 3;
    }
    if (((float10)_DAT_0058148c <= fVar3) &&
       (fVar3 < (float10)_DAT_00581488 != (fVar3 == (float10)_DAT_00581488))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 5;
    }
    if (((float10)_DAT_00581488 <= fVar3) &&
       (fVar3 < (float10)_DAT_00581484 != (fVar3 == (float10)_DAT_00581484))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 1;
    }
    if (((float10)_DAT_00581484 <= fVar3) &&
       (fVar3 < (float10)_DAT_00581480 != (fVar3 == (float10)_DAT_00581480))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 4;
    }
    if (((float10)_DAT_00581480 <= fVar3) &&
       (fVar3 < (float10)_DAT_0058147c != (fVar3 == (float10)_DAT_0058147c))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 2;
    }
    if (((float10)_DAT_0058147c <= fVar3) &&
       (fVar3 < (float10)_DAT_00581478 != (fVar3 == (float10)_DAT_00581478))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 6;
    }
    if (((float10)_DAT_00581478 <= fVar3) &&
       (fVar3 < (float10)_DAT_0058140c != (fVar3 == (float10)_DAT_0058140c))) {
      *(int *)((int)this + 0x9d14) = iVar2;
    }
    if (((float10)_DAT_0058140c <= fVar3) &&
       (fVar3 < (float10)_DAT_00581404 != (fVar3 == (float10)_DAT_00581404))) {
      *(int *)((int)this + 0x9d14) = iVar2 + 7;
    }
    if (fVar3 == (float10)_DAT_00581414) {
      *(int *)((int)this + 0x9d14) = iVar2 + 8;
    }
  }
  iVar2 = *(int *)((int)this + 0x9dc0);
  uVar1 = *(uint *)((int)this + 0x9d14);
  if ((iVar2 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar2 >> 2) <= uVar1)) {
    FUN_004023a0();
    iVar2 = extraout_EDX;
  }
  *(undefined4 *)((int)this + 0x9cec) = *(undefined4 *)(*(int *)(iVar2 + uVar1 * 4) + 8);
  return;
}

