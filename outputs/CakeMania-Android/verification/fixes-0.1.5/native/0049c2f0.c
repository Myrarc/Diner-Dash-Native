/* Native address 0049c2f0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0049c2f0(float *param_1,float *param_2,float param_3,int *param_4,undefined4 param_5,
            float param_6,undefined4 *param_7,float param_8,float param_9)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined2 extraout_var;
  undefined4 uVar7;
  int iVar8;
  double *pdVar9;
  float10 fVar10;
  double local_78 [2];
  double local_68;
  double local_60;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_3;
  dVar3 = (double)CONCAT44(param_6,param_5);
  fVar10 = (float10)fcos((float10)dVar3);
  param_3 = 1e+07;
  local_10 = -1e+07;
  param_6 = 1e+07;
  local_8 = (float)fVar10;
  fVar10 = (float10)fsin((float10)dVar3);
  local_c = (float)fVar10;
  fVar1 = (float)*(int *)((int)fVar2 + 8);
  fVar2 = (float)*(int *)((int)fVar2 + 0xc);
  local_18 = -param_8;
  local_14 = -param_9;
  fVar4 = local_18 * local_8 + local_c * local_14 + param_8 + *param_1;
  fVar5 = ((local_14 * local_8 + param_9) - local_18 * local_c) + *param_2;
  if (fVar4 < _DAT_005894b4) {
    param_3 = fVar4;
  }
  if (_DAT_005894b8 < fVar4) {
    local_10 = fVar4;
  }
  if (fVar5 < _DAT_005894b4) {
    param_6 = fVar5;
  }
  fVar4 = _DAT_005894b8;
  if (_DAT_005894b8 < fVar5) {
    fVar4 = fVar5;
  }
  fVar5 = fVar1 - param_8;
  fVar6 = fVar5 * local_8 + local_c * local_14 + param_8 + *param_1;
  fVar5 = ((local_14 * local_8 + param_9) - fVar5 * local_c) + *param_2;
  if (fVar6 < param_3) {
    param_3 = fVar6;
  }
  if (local_10 < fVar6) {
    local_10 = fVar6;
  }
  if (fVar5 < param_6) {
    param_6 = fVar5;
  }
  if (fVar4 < fVar5) {
    fVar4 = fVar5;
  }
  fVar1 = fVar1 - param_8;
  fVar6 = fVar2 - param_9;
  fVar5 = fVar1 * local_8 + local_c * fVar6 + param_8 + *param_1;
  fVar1 = ((fVar6 * local_8 + param_9) - fVar1 * local_c) + *param_2;
  if (fVar5 < param_3) {
    param_3 = fVar5;
  }
  if (local_10 < fVar5) {
    local_10 = fVar5;
  }
  if (fVar1 < param_6) {
    param_6 = fVar1;
  }
  if (fVar4 < fVar1) {
    fVar4 = fVar1;
  }
  fVar2 = fVar2 - param_9;
  fVar5 = local_18 * local_8 + local_c * fVar2 + param_8 + *param_1;
  fVar1 = ((fVar2 * local_8 + param_9) - local_18 * local_c) + *param_2;
  if (fVar5 < param_3) {
    param_3 = fVar5;
  }
  if (local_10 < fVar5) {
    local_10 = fVar5;
  }
  if (fVar1 < param_6) {
    param_6 = fVar1;
  }
  if (fVar4 < fVar1) {
    fVar4 = fVar1;
  }
  local_58 = (double)*param_4;
  local_50 = (double)param_4[1];
  local_48 = (double)param_4[2];
  local_40 = (double)param_4[3];
  local_38 = (double)param_3;
  local_30 = (double)param_6;
  local_28 = (double)(local_10 - param_3);
  local_20 = (double)(fVar4 - param_6);
  FUN_00498520(&local_38,local_78,&local_58);
  uVar7 = CONCAT22(extraout_var,
                   (ushort)(local_68 < _DAT_00587c80) << 8 |
                   (ushort)(NAN(local_68) || NAN(_DAT_00587c80)) << 10 |
                   (ushort)(local_68 == _DAT_00587c80) << 0xe);
  if (local_68 < _DAT_00587c80 == (local_68 == _DAT_00587c80)) {
    uVar7 = CONCAT22(extraout_var,
                     (ushort)(local_60 < _DAT_00587c80) << 8 |
                     (ushort)(NAN(local_60) || NAN(_DAT_00587c80)) << 10 |
                     (ushort)(local_60 == _DAT_00587c80) << 0xe);
    if (local_60 < _DAT_00587c80 == (local_60 == _DAT_00587c80)) {
      pdVar9 = local_78;
      for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
        *param_7 = *(undefined4 *)pdVar9;
        pdVar9 = (double *)((int)pdVar9 + 4);
        param_7 = param_7 + 1;
      }
      return CONCAT31((int3)((uint)uVar7 >> 8),1);
    }
  }
  return uVar7;
}

