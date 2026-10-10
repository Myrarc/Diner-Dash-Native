/* Address: 0044d8f0; name: FUN_0044d8f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044d8f0(int *param_1)

{
  void *pvVar1;
  char *pcVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  ulonglong uVar10;
  float afStack_8 [2];
  
  FUN_004c5bd0("Start_Of_Update");
  FUN_004d2fb0((int)param_1);
  (**(code **)(*param_1 + 0x10))();
  if (*(char *)((int)param_1 + 0x435) != '\0') {
    return;
  }
  FUN_004c5c10("Start_Of_Update");
  if (((char)param_1[0xbd] != '\0') && (*(int *)(param_1[0x6a] + 0x9d0c) == 0)) {
    uVar8 = 0;
    while( true ) {
      iVar5 = param_1[0x6a];
      iVar7 = *(int *)(iVar5 + 0x30);
      if ((iVar7 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar7 >> 3) <= uVar8)) break;
      afStack_8[0] = (float)param_1[0xbb];
      if ((iVar7 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar7 >> 3) <= uVar8)) goto LAB_0044dda6;
      afStack_8[0] = *(float *)(iVar7 + uVar8 * 8) - afStack_8[0];
      fVar4 = *(float *)(iVar7 + 4 + uVar8 * 8) - (float)param_1[0xbc];
      if (SQRT(afStack_8[0] * afStack_8[0] + fVar4 * fVar4) < _DAT_00581488) {
        if ((iVar7 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar7 >> 3) <= uVar8))
        goto LAB_0044dda6;
        FUN_00403e10((void *)param_1[0x6a],*(float *)(iVar7 + uVar8 * 8),
                     *(float *)(iVar7 + 4 + uVar8 * 8));
      }
      uVar8 = uVar8 + 1;
    }
    *(undefined1 *)(param_1 + 0xbd) = 0;
  }
  FUN_00404800((void *)param_1[0x6a]);
  if (((float)param_1[0x10a] == _DAT_0059d334) && (param_1[0xb5] == 0)) {
    fVar9 = FUN_00409b10((float *)(param_1 + 0x5a));
    param_1[0xbf] = (int)(float)fVar9;
  }
  else {
    fVar9 = FUN_00409b10((float *)(param_1 + 0x5a));
    param_1[0xc0] = (int)(float)fVar9;
  }
  iVar5 = FUN_00418c60((int)(param_1 + 0xe6));
  if (iVar5 == 0) goto LAB_0044dae8;
  if (param_1[0x10a] == 0x40000000) {
    *(undefined1 *)(param_1 + 99) = 1;
LAB_0044da95:
    param_1[0x10a] = (int)((float)param_1[0x10a] - (float)param_1[0xc0]);
  }
  else if ((float)param_1[0x10a] != _DAT_0059d334) goto LAB_0044da95;
  if (((float)param_1[0x10a] == _DAT_0059d334) && ((char)param_1[0x10b] != '\0')) {
    *(undefined1 *)(param_1 + 0x10b) = 0;
    *(undefined1 *)(param_1 + 0xb9) = 1;
    if ((int *)param_1[0x111] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x111] + 0x40))(0);
    }
    FUN_0044aa10((int)param_1);
  }
LAB_0044dae8:
  FUN_004040e0((void *)param_1[0x6a],(float)param_1[0xbf]);
  if (((float)param_1[0x5a] < (float)param_1[0xc2] != ((float)param_1[0x5a] == (float)param_1[0xc2])
      ) || ((((float)param_1[0xc2] < (float)param_1[0x5a] && (param_1[0x84] != 0)) &&
            (param_1[0x85] - param_1[0x84] >> 2 != 0)))) {
    FUN_004163a0(param_1 + 0x7f,afStack_8,(float)param_1[0xbf],(void *)(param_1[0x21] + 0x664),
                 (void *)param_1[0x69]);
    uVar10 = FUN_00560568();
    param_1[0xc5] = (int)uVar10;
    uVar10 = FUN_00560568();
    param_1[0xc4] = (int)uVar10;
    uVar10 = FUN_00560568();
    FUN_00419460((void *)param_1[0x69],(int)uVar10);
  }
  afStack_8[0] = (float)param_1[0xbf];
  pvVar1 = (void *)param_1[0x69];
  *(float *)((int)pvVar1 + 0x1c) = afStack_8[0];
  FUN_00419540(pvVar1,afStack_8[0]);
  FUN_004392a0(param_1 + 0x6b,(float)param_1[0xbf]);
  if ((((char)param_1[0x119] != '\0') && (pcVar2 = (char *)param_1[0xb8], pcVar2 != (char *)0x0)) &&
     (*(float *)(pcVar2 + 8) = (float)param_1[0xbf] + *(float *)(pcVar2 + 8), *pcVar2 == '\0')) {
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b97f0);
    *pcVar2 = '\x01';
  }
  pvVar1 = (void *)param_1[0xb8];
  if ((pvVar1 != (void *)0x0) && (*(float *)((int)pvVar1 + 4) < *(float *)((int)pvVar1 + 8))) {
    _free(pvVar1);
    param_1[0xb8] = 0;
  }
  if (((param_1[0x57] != 0) && (param_1[0x58] - param_1[0x57] >> 3 != 0)) &&
     (*(int *)(param_1[0x6a] + 0x9d0c) == 0)) {
    if (*(float *)(param_1[0x6a] + 0x10) == _DAT_0059d334) {
      if ((param_1[0x57] == 0) || (param_1[0x58] - param_1[0x57] >> 3 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      if ((param_1[0x57] == 0) || (param_1[0x58] - param_1[0x57] >> 3 == 0)) {
LAB_0044dcb6:
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      uVar10 = FUN_00560568();
      iVar5 = (int)uVar10;
      uVar10 = FUN_00560568();
      FUN_0044bf00(param_1,(int)uVar10,iVar5);
    }
    if (*(int *)(param_1[0x6a] + 0x9d0c) == 0) {
      uVar8 = 0;
      while( true ) {
        iVar5 = param_1[0x6a];
        if ((*(int *)(iVar5 + 0x30) == 0) ||
           ((uint)(*(int *)(iVar5 + 0x34) - *(int *)(iVar5 + 0x30) >> 3) <= uVar8)) break;
        pfVar3 = (float *)param_1[0x57];
        if ((pfVar3 == (float *)0x0) || (param_1[0x58] - (int)pfVar3 >> 3 == 0)) goto LAB_0044dcb6;
        iVar7 = *(int *)(iVar5 + 0x30);
        if ((iVar7 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar7 >> 3) <= uVar8))
        goto LAB_0044dda6;
        afStack_8[0] = *(float *)(iVar7 + uVar8 * 8) - *pfVar3;
        fVar4 = *(float *)(iVar7 + 4 + uVar8 * 8) - pfVar3[1];
        if (SQRT(afStack_8[0] * afStack_8[0] + fVar4 * fVar4) < _DAT_00581488) {
          if ((iVar7 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar7 >> 3) <= uVar8)) {
LAB_0044dda6:
                    /* WARNING: Subroutine does not return */
            FUN_00406800();
          }
          FUN_00403e10((void *)param_1[0x6a],*(float *)(iVar7 + uVar8 * 8),
                       *(float *)(iVar7 + 4 + uVar8 * 8));
        }
        uVar8 = uVar8 + 1;
      }
    }
    if (*(int *)(param_1[0x6a] + 0x9d0c) == 0) {
      if ((void *)param_1[0x57] != (void *)0x0) {
        _free((void *)param_1[0x57]);
      }
      param_1[0x57] = 0;
      param_1[0x58] = 0;
      param_1[0x59] = 0;
    }
    else {
      FUN_0044b5d0(param_1 + 0x56,afStack_8,(undefined4 *)param_1[0x57]);
    }
  }
  if ((*(int *)(param_1[0x6a] + 0x9d0c) == 0) &&
     ((param_1[0x57] == 0 || (param_1[0x58] - param_1[0x57] >> 3 == 0)))) {
    FUN_00436660((int)(param_1 + 0x6b));
  }
  if ((((float)param_1[0xc2] < (float)param_1[0x5a]) && (*(int *)(param_1[0x21] + 0x714) == 0)) &&
     (param_1[0xb5] == 0)) {
    iVar5 = param_1[0x69];
    if ((*(int *)(iVar5 + 4) == 0) || (*(int *)(iVar5 + 8) - *(int *)(iVar5 + 4) >> 5 == 0)) {
      iVar7 = 0;
      if ((param_1[0xb8] == 0) ||
         ((uVar8 = FUN_0044a6a0(param_1[0xb8]), iVar7 = extraout_ECX, (char)uVar8 != '\0' ||
          (extraout_ECX == 0)))) {
        if ((*(int *)(iVar5 + 0x10) < *(int *)(iVar5 + 0x18)) ||
           ((iVar7 == 0 || (*(char *)(iVar7 + 1) != '\0')))) {
          if ((param_1[0x84] == 0) || (param_1[0x85] - param_1[0x84] >> 2 == 0)) {
            if ((param_1[0xb6] == 0) && ((char)param_1[0x10d] == '\0')) {
              FUN_0044d570(param_1);
              *(undefined1 *)(param_1 + 0x94) = 0;
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x8e) = 0;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x119) = 1;
        }
      }
    }
  }
  if ((((float)param_1[0x5a] <= (float)param_1[0xc2]) && (*(int *)(param_1[0x21] + 0x714) == 0)) &&
     (param_1[0xb5] == 0)) {
    iVar5 = FUN_0040c020(param_1 + 0x88,param_1[0x91]);
    if (((*(int *)(iVar5 + 0x20) == 0) ||
        (*(int *)(iVar5 + 0x24) - *(int *)(iVar5 + 0x20) >> 3 == 0)) &&
       ((param_1[0x84] == 0 || (param_1[0x85] - param_1[0x84] >> 2 == 0)))) {
      iVar5 = param_1[0x69];
      uVar6 = FUN_0044a8e0(iVar5);
      if ((char)uVar6 != '\0') {
        iVar7 = 0;
        if (((param_1[0xb8] == 0) ||
            (uVar8 = FUN_0044a6a0(param_1[0xb8]), iVar7 = extraout_ECX_00, (char)uVar8 != '\0')) ||
           (extraout_ECX_00 == 0)) {
          if (((*(int *)(iVar5 + 0x10) < *(int *)(iVar5 + 0x18)) || (iVar7 == 0)) ||
             (*(char *)(iVar7 + 1) != '\0')) {
            if ((param_1[0xb6] == 0) && ((char)param_1[0x10d] == '\0')) {
              FUN_0044d570(param_1);
              *(undefined1 *)(param_1 + 0x94) = 0;
            }
          }
          else {
            *(undefined1 *)(param_1 + 0x119) = 1;
          }
        }
      }
    }
  }
  if (param_1[0xcb] < 1) {
    *(undefined1 *)(param_1 + 0x10d) = 1;
  }
  iVar5 = FUN_00418c60((int)(param_1 + 0xcc));
  if (iVar5 != 0) {
    pvVar1 = (void *)param_1[0x21];
    if ((*(char *)((int)param_1 + 0x2e5) == '\0') && (*(int *)((int)pvVar1 + 0x714) == 0)) {
      FUN_0041d890(pvVar1);
      return;
    }
    FUN_0041cd30(pvVar1);
  }
  return;
}


