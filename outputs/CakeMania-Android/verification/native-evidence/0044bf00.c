/* Address: 0044bf00; name: FUN_0044bf00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044bf00(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  int *piVar6;
  float *pfVar7;
  int iVar8;
  uint uVar9;
  
  fVar3 = (float)param_2;
  fVar4 = (float)param_1;
  piVar6 = (int *)FUN_00436110((void *)((int)this + 0x1ac),fVar4,fVar3);
  if (piVar6 == (int *)0x0) goto LAB_0044c405;
  cVar5 = (**(code **)(*piVar6 + 0x10))(fVar4,fVar3);
  iVar8 = *(int *)((int)this + 0x1a8);
  *(float *)(iVar8 + 0x9d04) = fVar4;
  *(float *)(iVar8 + 0x9d08) = fVar3;
  if (cVar5 == '\0') {
    *(undefined1 *)(piVar6 + 0x1c) = 1;
  }
  if (((piVar6[0x18] == 6) && (cVar5 != '\0')) && ((float)piVar6[0x1a] == _DAT_0059d334)) {
    iVar8 = *(int *)((int)this + 0x1a8);
    *(float *)(iVar8 + 0x9d04) = fVar4;
    *(float *)(iVar8 + 0x9d08) = fVar3;
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 9;
    pfVar7 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar6[0x17]);
    FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar7,pfVar7[1]);
  }
  iVar8 = *(int *)((int)this + 0x1a8);
  iVar1 = *(int *)(iVar8 + 0x9cf0);
  if (iVar1 != 0) {
    iVar2 = piVar6[0x18];
    if (cVar5 == '\0') {
      if (((((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 0)) &&
          ((*(int *)(iVar1 + 0x18) != 1 && (piVar6[0xd] != 0)))) && (*(int *)(iVar8 + 0x9d10) == 0))
      {
        *(float *)(iVar8 + 0x9d04) = fVar4;
        *(float *)(iVar8 + 0x9d08) = fVar3;
        *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
        *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xb;
        goto LAB_0044c0d3;
      }
    }
    else if ((((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 0)) && (*(int *)(iVar1 + 0x18) != 1)) {
      *(float *)(iVar8 + 0x9d04) = fVar4;
      *(float *)(iVar8 + 0x9d08) = fVar3;
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 4;
LAB_0044c0d3:
      pfVar7 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar6[0x17]);
      FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar7,pfVar7[1]);
    }
    if (((piVar6[0x18] == 7) &&
        (*(int *)(*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0) + 0x18) != 1)) &&
       (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d10) == 0)) {
      iVar8 = FUN_004361f0((void *)((int)this + 0x1ac),fVar4,fVar3);
      if ((iVar8 != 0) && (*(int *)(iVar8 + 0xac) != 0)) {
        iVar8 = *(int *)((int)this + 0x1a8);
        *(float *)(iVar8 + 0x9d04) = fVar4;
        *(float *)(iVar8 + 0x9d08) = fVar3;
        *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
        *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xb;
        pfVar7 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar6[0x17]);
        FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar7,pfVar7[1]);
      }
    }
    if ((((piVar6[0x18] != 5) && (piVar6[0xd] == 0)) &&
        (iVar8 = *(int *)((int)this + 0x1a8), *(int *)(iVar8 + 0x9d10) == 0)) &&
       ((piVar6[0x18] != 6 || ((float)piVar6[0x1a] <= _DAT_0059d334)))) {
      *(float *)(iVar8 + 0x9d04) = fVar4;
      *(float *)(iVar8 + 0x9d08) = fVar3;
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 5;
      pfVar7 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar6[0x17]);
      FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar7,pfVar7[1]);
    }
  }
  if ((*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0) == 0) && (cVar5 == '\0')) {
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 7;
    iVar8 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
    uVar9 = piVar6[0x17];
    if ((iVar8 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar8 >> 3) <= uVar9)
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar8 + uVar9 * 8),
                 *(float *)(iVar8 + 4 + uVar9 * 8));
  }
  if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0) == 0) {
    if (cVar5 == '\0') goto LAB_0044c405;
    if ((piVar6[0x18] == 5) || (piVar6[0x18] == 7)) {
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
      iVar8 = *(int *)((int)this + 0x1a8);
      *(float *)(iVar8 + 0x9d04) = fVar4;
      *(float *)(iVar8 + 0x9d08) = fVar3;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 7;
      uVar9 = piVar6[0x17];
      iVar8 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
      if ((iVar8 == 0) ||
         ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar8 >> 3) <= uVar9)) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar8 + uVar9 * 8),
                   *(float *)(iVar8 + 4 + uVar9 * 8));
    }
  }
  if ((((cVar5 != '\0') && (iVar8 = *(int *)((int)this + 0x1a8), *(int *)(iVar8 + 0x9cf0) == 0)) &&
      (piVar6[0xd] != 0)) && (((iVar1 = piVar6[0x18], iVar1 == 1 || (iVar1 == 2)) || (iVar1 == 0))))
  {
    *(float *)(iVar8 + 0x9d04) = fVar4;
    *(float *)(iVar8 + 0x9d08) = fVar3;
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar6;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xc;
    pfVar7 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar6[0x17]);
    FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar7,pfVar7[1]);
  }
LAB_0044c405:
  iVar8 = FUN_0040daf0((void *)((int)this + 0x1fc),*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0),
                       fVar4,fVar3);
  *(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) = iVar8;
  iVar8 = *(int *)((int)this + 0x1a8);
  if (*(int *)(iVar8 + 0x9d00) != 0) {
    iVar1 = *(int *)(iVar8 + 0x9cf0);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) != 1)) {
      if (*(char *)(*(int *)(iVar8 + 0x9d00) + 0x26c) == '\0') {
        *(undefined4 *)(iVar8 + 0x9d10) = 8;
      }
      else if (iVar1 != 0) {
        *(undefined4 *)(iVar8 + 0x9d10) = 6;
      }
    }
    else {
      *(undefined4 *)(iVar8 + 0x9d10) = 10;
    }
    uVar9 = FUN_0044bdd0(this,*(float **)(*(int *)((int)this + 0x1a8) + 0x9d00));
    iVar8 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
    if ((iVar8 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar8 >> 3) <= uVar9)
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar8 + uVar9 * 8),
                 *(float *)(iVar8 + 4 + uVar9 * 8));
  }
  if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) == 0) {
    iVar8 = FUN_0040b540((void *)((int)this + 0x1fc),fVar4,fVar3);
    *(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) = iVar8;
    if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) != 0) {
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xd;
      uVar9 = FUN_0044bdd0(this,*(float **)(*(int *)((int)this + 0x1a8) + 0x9d00));
      iVar8 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
      if ((iVar8 == 0) ||
         ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar8 >> 3) <= uVar9)) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar8 + uVar9 * 8),
                   *(float *)(iVar8 + 4 + uVar9 * 8));
    }
  }
  iVar8 = FUN_00436760((void *)((int)this + 0x1ac),fVar4,fVar3);
  if (iVar8 != 0) {
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xe;
    iVar1 = *(int *)((int)this + 0x1a8);
    *(float *)(iVar1 + 0x9d04) = fVar4;
    *(float *)(iVar1 + 0x9d08) = fVar3;
    *(int *)(*(int *)((int)this + 0x1a8) + 0x9cfc) = iVar8;
    uVar9 = *(uint *)(iVar8 + 0x5c);
    iVar8 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
    if ((iVar8 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar8 >> 3) <= uVar9)
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar8 + uVar9 * 8),
                 *(float *)(iVar8 + 4 + uVar9 * 8));
  }
  return;
}


