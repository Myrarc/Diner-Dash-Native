/* Address: 0044f2b0; name: FUN_0044f2b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0044f2b0(void *this,int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int *piVar7;
  float *pfVar8;
  int iVar9;
  
  fVar4 = (float)param_2;
  fVar5 = (float)param_1;
  piVar7 = (int *)FUN_00436110((void *)((int)this + 0x1ac),fVar5,fVar4);
  if (piVar7 == (int *)0x0) goto LAB_0044f6e4;
  cVar6 = (**(code **)(*piVar7 + 0x10))(fVar5,fVar4);
  iVar9 = *(int *)((int)this + 0x1a8);
  *(float *)(iVar9 + 0x9d04) = fVar5;
  *(float *)(iVar9 + 0x9d08) = fVar4;
  if (cVar6 == '\0') {
    *(undefined1 *)(piVar7 + 0x1c) = 1;
  }
  if (((piVar7[0x18] == 6) && (cVar6 != '\0')) && ((float)piVar7[0x1a] == _DAT_0059d334)) {
    iVar9 = *(int *)((int)this + 0x1a8);
    *(float *)(iVar9 + 0x9d04) = fVar5;
    *(float *)(iVar9 + 0x9d08) = fVar4;
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 9;
    pfVar8 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar7[0x17]);
    FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar8,pfVar8[1]);
  }
  iVar9 = *(int *)((int)this + 0x1a8);
  iVar1 = *(int *)(iVar9 + 0x9cf0);
  if (iVar1 != 0) {
    iVar2 = piVar7[0x18];
    if (cVar6 == '\0') {
      if (((((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 0)) &&
          ((*(int *)(iVar1 + 0x18) != 1 && (piVar7[0xd] != 0)))) && (*(int *)(iVar9 + 0x9d10) == 0))
      {
        *(float *)(iVar9 + 0x9d04) = fVar5;
        *(float *)(iVar9 + 0x9d08) = fVar4;
        *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
        *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xb;
        goto LAB_0044f479;
      }
    }
    else if ((((iVar2 == 1) || (iVar2 == 2)) || (iVar2 == 0)) && (*(int *)(iVar1 + 0x18) != 1)) {
      *(float *)(iVar9 + 0x9d04) = fVar5;
      *(float *)(iVar9 + 0x9d08) = fVar4;
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 4;
LAB_0044f479:
      pfVar8 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar7[0x17]);
      FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar8,pfVar8[1]);
    }
    if (((piVar7[0x18] != 6) && (piVar7[0x18] != 5)) &&
       ((piVar7[0xd] == 0 && (iVar9 = *(int *)((int)this + 0x1a8), *(int *)(iVar9 + 0x9d10) == 0))))
    {
      *(float *)(iVar9 + 0x9d04) = fVar5;
      *(float *)(iVar9 + 0x9d08) = fVar4;
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 5;
      pfVar8 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar7[0x17]);
      FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar8,pfVar8[1]);
    }
  }
  if ((*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0) == 0) && (cVar6 == '\0')) {
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 7;
    iVar9 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
    uVar3 = piVar7[0x17];
    if ((iVar9 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar9 >> 3) <= uVar3)
       ) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar9 + uVar3 * 8),
                 *(float *)(iVar9 + 4 + uVar3 * 8));
  }
  if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0) == 0) {
    if (cVar6 == '\0') goto LAB_0044f6e4;
    if ((piVar7[0x18] == 5) || (piVar7[0x18] == 7)) {
      *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
      iVar9 = *(int *)((int)this + 0x1a8);
      *(float *)(iVar9 + 0x9d04) = fVar5;
      *(float *)(iVar9 + 0x9d08) = fVar4;
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 7;
      uVar3 = piVar7[0x17];
      iVar9 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
      if ((iVar9 == 0) ||
         ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar9 >> 3) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar9 + uVar3 * 8),
                   *(float *)(iVar9 + 4 + uVar3 * 8));
    }
  }
  if ((((cVar6 != '\0') && (iVar9 = *(int *)((int)this + 0x1a8), *(int *)(iVar9 + 0x9cf0) == 0)) &&
      (piVar7[0xd] != 0)) && (((iVar1 = piVar7[0x18], iVar1 == 1 || (iVar1 == 2)) || (iVar1 == 0))))
  {
    *(float *)(iVar9 + 0x9d04) = fVar5;
    *(float *)(iVar9 + 0x9d08) = fVar4;
    *(int **)(*(int *)((int)this + 0x1a8) + 0x9cfc) = piVar7;
    *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xc;
    pfVar8 = (float *)FUN_004068e0((void *)(*(int *)((int)this + 0x1a8) + 0x2c),piVar7[0x17]);
    FUN_00403e10(*(void **)((int)this + 0x1a8),*pfVar8,pfVar8[1]);
  }
LAB_0044f6e4:
  iVar9 = FUN_0040daf0((void *)((int)this + 0x1fc),*(int *)(*(int *)((int)this + 0x1a8) + 0x9cf0),
                       fVar5,fVar4);
  *(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) = iVar9;
  iVar9 = *(int *)((int)this + 0x1a8);
  if (*(int *)(iVar9 + 0x9d00) != 0) {
    iVar1 = *(int *)(iVar9 + 0x9cf0);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x18) != 1)) {
      if (*(char *)(*(int *)(iVar9 + 0x9d00) + 0x26c) == '\0') {
        *(undefined4 *)(iVar9 + 0x9d10) = 8;
      }
      else if (iVar1 != 0) {
        *(undefined4 *)(iVar9 + 0x9d10) = 6;
      }
    }
    else {
      *(undefined4 *)(iVar9 + 0x9d10) = 10;
    }
    iVar9 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
    if ((iVar9 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar9 >> 3) < 0xc)) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar9 + 0x58),*(float *)(iVar9 + 0x5c));
  }
  if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) == 0) {
    iVar9 = FUN_0040b540((void *)((int)this + 0x1fc),fVar5,fVar4);
    *(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) = iVar9;
    if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d00) != 0) {
      *(undefined4 *)(*(int *)((int)this + 0x1a8) + 0x9d10) = 0xd;
      iVar9 = *(int *)(*(int *)((int)this + 0x1a8) + 0x30);
      if ((iVar9 == 0) || ((uint)(*(int *)(*(int *)((int)this + 0x1a8) + 0x34) - iVar9 >> 3) < 0xc))
      {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      FUN_00403e10(*(void **)((int)this + 0x1a8),*(float *)(iVar9 + 0x58),*(float *)(iVar9 + 0x5c));
    }
  }
  return;
}


