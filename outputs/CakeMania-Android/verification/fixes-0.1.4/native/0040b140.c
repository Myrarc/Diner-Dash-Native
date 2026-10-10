/* Address: 0040b140; name: FUN_0040b140 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040b140(void *this,float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  
  if ((*(int *)((int)this + 0x2c4) != 0) &&
     (*(int *)((int)this + 0x2c8) - *(int *)((int)this + 0x2c4) >> 3 != 0)) {
    fVar1 = *(float *)((int)this + 0x2d4);
    if (*(float *)((int)this + 0x2d0) * _DAT_00581420 <= *(float *)((int)this + 0x2d4)) {
      fVar1 = fVar1 - *(float *)((int)this + 0x2d0);
    }
    pfVar5 = *(float **)((int)this + 0x2c4);
    pfVar4 = (float *)(*(int *)((int)this + 0x2c8) + -8);
    fVar1 = (fVar1 * *(float *)((int)this + 0x2d8) * fVar1) /
            (*(float *)((int)this + 0x2d0) * *(float *)((int)this + 0x2d0) * _DAT_0058163c);
    fVar3 = _DAT_0059d334;
    if (pfVar5 != pfVar4) {
      while ((fVar2 = SQRT((*pfVar5 - pfVar5[2]) * (*pfVar5 - pfVar5[2]) +
                           (pfVar5[1] - pfVar5[3]) * (pfVar5[1] - pfVar5[3])), fVar1 < fVar3 ||
             (fVar2 + fVar3 < fVar1))) {
        pfVar5 = pfVar5 + 2;
        fVar3 = fVar3 + fVar2;
        if (pfVar5 == pfVar4) {
          return;
        }
      }
      fVar2 = _DAT_005814a4 / fVar2;
      *param_1 = (pfVar5[2] - *pfVar5) * fVar2 * (fVar1 - fVar3) + *pfVar5 + *param_1;
      *param_2 = *param_2 - ((pfVar5[3] - pfVar5[1]) * fVar2 * (fVar1 - fVar3) + pfVar5[1]);
    }
  }
  return;
}


