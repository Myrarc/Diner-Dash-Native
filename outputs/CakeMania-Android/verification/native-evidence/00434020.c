/* Address: 00434020; name: FUN_00434020 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00434020(int param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  
  *(undefined4 *)(DAT_005b9c08 + 0xc) = 9;
  *(undefined4 *)(DAT_005b9c08 + 0x10) = 1;
  *(undefined4 *)(DAT_005b97b4 + 0xc) = 0x13;
  *(undefined4 *)(DAT_005b97b4 + 0x10) = 1;
  fVar2 = *(float *)(param_1 + 100) - _DAT_005814a8;
  bVar1 = fVar2 < _DAT_0059d334;
  *(float *)(param_1 + 0x108) = fVar2;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x108) = 0;
    fVar2 = *(float *)(param_1 + 100) * _DAT_00585f9c;
    *(float *)(param_1 + 0x10c) = fVar2;
    fVar3 = *(float *)(param_1 + 100) * _DAT_00585f98 + fVar2;
    *(float *)(param_1 + 0x110) = fVar3;
    fVar3 = *(float *)(param_1 + 100) * _DAT_00585f94 + fVar3;
    *(float *)(param_1 + 0x114) = fVar3;
    *(float *)(param_1 + 0x118) = fVar3 + fVar2;
    return;
  }
  fVar2 = fVar2 + _DAT_00585f9c;
  *(float *)(param_1 + 0x10c) = fVar2;
  fVar2 = fVar2 + _DAT_00585f9c;
  *(float *)(param_1 + 0x110) = fVar2;
  fVar2 = fVar2 + _DAT_005814a4;
  *(float *)(param_1 + 0x114) = fVar2;
  *(float *)(param_1 + 0x118) = fVar2 + _DAT_00585f9c;
  return;
}


