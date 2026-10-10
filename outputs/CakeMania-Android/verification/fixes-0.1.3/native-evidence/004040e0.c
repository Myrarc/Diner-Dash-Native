/* Native address 004040e0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004040e0(void *this,float param_1)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  void *_Memory;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int iVar5;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int iVar6;
  int *piVar7;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int extraout_EDX_05;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00573c18;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(float *)((int)this + 0x10) != _DAT_0059d334) {
    ExceptionList = &pvStack_c;
    *(float *)((int)this + 0x10) = *(float *)((int)this + 0x10) - param_1;
  }
  if (*(float *)((int)this + 0x10) < _DAT_0059d334) {
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  iVar5 = *(int *)((int)this + 0x9dc0);
  uVar1 = *(uint *)((int)this + 0x9d14);
  if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
    FUN_004023a0();
    iVar5 = extraout_ECX;
  }
  iVar4 = *(int *)((int)this + 0x9dc0);
  iVar5 = **(int **)(iVar5 + uVar1 * 4);
  if ((iVar4 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar4 >> 2) <= uVar1)) {
    FUN_004023a0();
    iVar4 = extraout_ECX_00;
    iVar5 = extraout_EDX;
  }
  iVar8 = *(int *)((int)this + 0x9dc0);
  if (*(int *)(**(int **)(iVar4 + uVar1 * 4) + 0xc) < *(int *)(iVar5 + 0x10)) {
    if ((iVar8 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar8 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar8 = extraout_EDX_00;
    }
    iVar5 = *(int *)((int)this + 0x9dc0);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar5 = extraout_ECX_01;
      iVar8 = extraout_EDX_01;
    }
    *(float *)((int)this + 0xa90c) =
         *(float *)((int)this + 0xa90c) -
         (float)*(int *)(**(int **)(iVar5 + uVar1 * 4) + 0x10) *
         *(float *)(*(int *)(iVar8 + uVar1 * 4) + 0x10) * param_1;
    uVar9 = FUN_00560568();
    if (-1 < (int)uVar9) {
      iVar5 = *(int *)((int)this + 0x9dc0);
      uVar10 = CONCAT44(iVar5,(int)uVar9);
      if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        uVar10 = FUN_004023a0();
      }
      if ((int)uVar10 <=
          *(int *)(**(int **)((int)((ulonglong)uVar10 >> 0x20) + uVar1 * 4) + 0x10) + -1)
      goto LAB_004042ee;
    }
    iVar5 = *(int *)((int)this + 0x9dc0);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar5 = extraout_ECX_02;
    }
    iVar5 = *(int *)(**(int **)(iVar5 + uVar1 * 4) + 0x10);
  }
  else {
    if ((iVar8 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar8 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar8 = extraout_EDX_02;
    }
    iVar5 = *(int *)((int)this + 0x9dc0);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar5 = extraout_ECX_03;
      iVar8 = extraout_EDX_03;
    }
    *(float *)((int)this + 0xa90c) =
         *(float *)((int)this + 0xa90c) -
         (float)*(int *)(**(int **)(iVar5 + uVar1 * 4) + 0xc) *
         *(float *)(*(int *)(iVar8 + uVar1 * 4) + 0x10) * param_1;
    uVar9 = FUN_00560568();
    if (-1 < (int)uVar9) {
      iVar5 = *(int *)((int)this + 0x9dc0);
      uVar10 = CONCAT44(iVar5,(int)uVar9);
      if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        uVar10 = FUN_004023a0();
      }
      if ((int)uVar10 <=
          *(int *)(**(int **)((int)((ulonglong)uVar10 >> 0x20) + uVar1 * 4) + 0xc) + -1)
      goto LAB_004042ee;
    }
    iVar5 = *(int *)((int)this + 0x9dc0);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar5 = extraout_ECX_04;
    }
    iVar5 = *(int *)(**(int **)(iVar5 + uVar1 * 4) + 0xc);
  }
  *(float *)((int)this + 0xa90c) = (float)(iVar5 + -1);
LAB_004042ee:
  if (*(int *)((int)this + 0x9d0c) == 1) {
    *(undefined4 *)((int)this + 0xa910) = 0;
  }
  else {
    fVar3 = param_1 + *(float *)((int)this + 0xa910);
    *(float *)((int)this + 0xa910) = fVar3;
    if (fVar3 < _DAT_005814a8) {
      iVar5 = *(int *)((int)this + 0x9dc0);
      if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
        FUN_004023a0();
        iVar5 = extraout_ECX_05;
      }
      *(float *)((int)this + 0xa90c) = (float)(*(int *)(**(int **)(iVar5 + uVar1 * 4) + 0xc) + -1);
    }
  }
  if (*(float *)((int)this + 0x10) != _DAT_0059d334) {
    iVar5 = *(int *)((int)this + 0x9dc0);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar5 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar5 = extraout_ECX_06;
    }
    iVar4 = *(int *)((int)this + 0x9dc0);
    iVar5 = **(int **)(iVar5 + uVar1 * 4);
    if ((iVar4 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar4 >> 2) <= uVar1)) {
      iVar4 = FUN_004023a0();
    }
    iVar8 = *(int *)((int)this + 0x9dc0);
    iVar4 = **(int **)(iVar4 + uVar1 * 4);
    if ((iVar8 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar8 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar8 = extraout_EDX_04;
    }
    iVar6 = *(int *)((int)this + 0x9dc0);
    if ((iVar6 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar6 >> 2) <= uVar1)) {
      FUN_004023a0();
      iVar6 = extraout_ECX_07;
      iVar8 = extraout_EDX_05;
    }
    iVar6 = **(int **)(iVar6 + uVar1 * 4);
    iVar2 = *(int *)((int)this + 0x9dc0);
    uVar10 = CONCAT44(iVar8,iVar2);
    if ((iVar2 == 0) || ((uint)(*(int *)((int)this + 0x9dc4) - iVar2 >> 2) <= uVar1)) {
      uVar10 = FUN_004023a0();
    }
    *(float *)((int)this + 0xa90c) =
         (_DAT_005814a4 -
         ((float)*(int *)(iVar4 + 0xc) *
          *(float *)(*(int *)((int)((ulonglong)uVar10 >> 0x20) + uVar1 * 4) + 0x10) -
         *(float *)((int)this + 0x10)) /
         ((float)*(int *)(iVar6 + 0xc) * *(float *)(*(int *)((int)uVar10 + uVar1 * 4) + 0x10))) *
         (float)(*(int *)(iVar5 + 0xc) + -1);
  }
  piVar7 = *(int **)((int)this + 0xa918);
  if (piVar7 != *(int **)((int)this + 0xa91c)) {
    do {
      if ((*piVar7 != 0) &&
         (piVar7[4] = (int)(param_1 + (float)piVar7[4]), (float)piVar7[3] < (float)piVar7[4])) {
        iVar5 = piVar7[5];
        piVar7[5] = iVar5 + -1;
        if (iVar5 + -1 < 0) {
          *piVar7 = 0;
        }
        piVar7[4] = 0;
      }
      piVar7 = piVar7 + 6;
    } while (piVar7 != *(int **)((int)this + 0xa91c));
  }
  pvStack_18 = (void *)0x0;
  uStack_14 = 0;
  uStack_10 = 0;
  piVar7 = *(int **)((int)this + 0xa918);
  uStack_4 = 0;
  if (piVar7 != *(int **)((int)this + 0xa91c)) {
    do {
      if (*piVar7 != 0) {
        FUN_00403ed0(auStack_1c,piVar7);
      }
      piVar7 = piVar7 + 6;
    } while (piVar7 != *(int **)((int)this + 0xa91c));
  }
  _Memory = pvStack_18;
  if (*(void **)((int)this + 0xa918) != (void *)0x0) {
    _free(*(void **)((int)this + 0xa918));
  }
  *(undefined4 *)((int)this + 0xa918) = 0;
  *(undefined4 *)((int)this + 0xa91c) = 0;
  *(undefined4 *)((int)this + 0xa920) = 0;
  FUN_004039b0((void *)((int)this + 0xa914),auStack_1c);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
  }
  ExceptionList = pvStack_c;
  return;
}

