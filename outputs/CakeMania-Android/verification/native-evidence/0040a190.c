/* Address: 0040a190; name: FUN_0040a190 */

void __fastcall FUN_0040a190(int param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  fVar2 = (float)(*(int *)(param_1 + 0x44) * iVar1) + *(float *)(param_1 + 0x328);
  *(float *)(param_1 + 0x328) = fVar2;
  fVar3 = (float)((*(int *)(param_1 + 0x34) + 1) * iVar1);
  if ((fVar3 < fVar2) && (iVar1 != 0)) {
    *(float *)(param_1 + 0x328) = fVar3;
  }
  *(undefined4 *)(param_1 + 800) = 4;
  *(undefined4 *)(param_1 + 0x304) = 0;
  *(undefined4 *)(param_1 + 0x308) = 0;
  (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9744);
  return;
}


