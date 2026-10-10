/* Address: 0043a330; name: FUN_0043a330 */

void __fastcall FUN_0043a330(int param_1)

{
  int iVar1;
  uint uVar2;
  void **ppvVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  int iStack_20;
  undefined1 auStack_1c [4];
  void *local_18;
  int *local_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00577d68;
  pvStack_c = ExceptionList;
  pvVar6 = (void *)0x0;
  local_18 = (void *)0x0;
  local_14 = (int *)0x0;
  local_10 = 0;
  piVar8 = *(int **)(param_1 + 0x34);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  ppvVar3 = &pvStack_c;
  if (piVar8 != *(int **)(param_1 + 0x38)) {
    do {
      ExceptionList = ppvVar3;
      iVar1 = *piVar8;
      if ((*(int *)(iVar1 + 0xd8) < 1) && (iVar1 != 0)) {
        if (*(int *)(param_1 + 0x44) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x48) - *(int *)(param_1 + 0x44) >> 2;
        }
        uVar2 = *(uint *)(iVar1 + 0x78);
        if ((int)uVar2 < iVar4) {
          iVar4 = *(int *)(param_1 + 0x44);
          if ((iVar4 == 0) || ((uint)(*(int *)(param_1 + 0x48) - iVar4 >> 2) <= uVar2)) {
LAB_0043a4ad:
            FUN_00436bc0();
            return;
          }
          piVar7 = *(int **)(*(int *)(iVar4 + uVar2 * 4) + 0x14);
          while( true ) {
            if ((iVar4 == 0) || ((uint)(*(int *)(param_1 + 0x48) - iVar4 >> 2) <= uVar2))
            goto LAB_0043a4ad;
            if (piVar7 == *(int **)(*(int *)(iVar4 + uVar2 * 4) + 0x18)) goto LAB_0043a450;
            if (*piVar7 == iVar1) break;
            piVar7 = piVar7 + 1;
          }
          iVar1 = *(int *)(param_1 + 0x44);
          if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x48) - iVar1 >> 2) <= uVar2))
          goto LAB_0043a4ad;
          iVar1 = *(int *)(iVar1 + uVar2 * 4);
          _memmove(piVar7,piVar7 + 1,(*(int *)(iVar1 + 0x18) - (int)(piVar7 + 1) >> 2) << 2);
          *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -4;
        }
LAB_0043a450:
        if ((undefined4 *)*piVar8 != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)*piVar8)(1);
        }
        *piVar8 = 0;
        pvVar6 = local_18;
      }
      else if ((pvVar6 == (void *)0x0) ||
              ((uint)(local_10 - (int)pvVar6 >> 2) <= (uint)((int)local_14 - (int)pvVar6 >> 2))) {
        FUN_004201e0(auStack_1c,local_14,1,piVar8);
        pvVar6 = local_18;
      }
      else {
        *local_14 = iVar1;
        local_14 = local_14 + 1;
      }
      piVar8 = piVar8 + 1;
      ppvVar3 = ExceptionList;
    } while (piVar8 != *(int **)(param_1 + 0x38));
  }
  if (*(void **)(param_1 + 0x34) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x34));
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  FUN_004203c0((void *)(param_1 + 0x30),auStack_1c);
  if (local_18 != (void *)0x0) {
    _free(local_18);
  }
  iVar1 = *(int *)(param_1 + 4);
  local_18 = (void *)0x0;
  local_14 = (int *)0x0;
  local_10 = 0;
  if (*(void **)(iVar1 + 0x18) != (void *)0x0) {
    _free(*(void **)(iVar1 + 0x18));
  }
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  piVar8 = *(int **)(param_1 + 0x34);
  if (piVar8 != *(int **)(param_1 + 0x38)) {
    do {
      iVar1 = *piVar8;
      if (((*(int *)(iVar1 + 0x60) == 6) && (iVar1 != 0)) &&
         (piVar7 = *(int **)(iVar1 + 0x28), piVar7 != *(int **)(iVar1 + 0x2c))) {
        do {
          iVar1 = *(int *)(param_1 + 4);
          iStack_20 = *(int *)(*piVar7 + 0x48);
          for (piVar5 = *(int **)(iVar1 + 0x18); piVar5 != *(int **)(iVar1 + 0x1c);
              piVar5 = piVar5 + 1) {
            if (*piVar5 == iStack_20) goto LAB_0043a5bf;
          }
          iVar4 = *(int *)(iVar1 + 0x18);
          if ((iVar4 == 0) ||
             ((uint)(*(int *)(iVar1 + 0x20) - iVar4 >> 2) <=
              (uint)(*(int *)(iVar1 + 0x1c) - iVar4 >> 2))) {
            FUN_0040ccc0((void *)(iVar1 + 0x14),*(undefined4 **)(iVar1 + 0x1c),1,&iStack_20);
          }
          else {
            piVar5 = *(int **)(iVar1 + 0x1c);
            *piVar5 = iStack_20;
            *(int **)(iVar1 + 0x1c) = piVar5 + 1;
          }
LAB_0043a5bf:
          piVar7 = piVar7 + 1;
        } while (piVar7 != *(int **)(*piVar8 + 0x2c));
      }
      piVar8 = piVar8 + 1;
    } while (piVar8 != *(int **)(param_1 + 0x38));
  }
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(iVar1 + 8) == 0) {
    iStack_20 = 0;
  }
  else {
    iStack_20 = *(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8) >> 2;
  }
  iStack_20 = iStack_20 + -1;
  for (piVar8 = *(int **)(iVar1 + 0x18); piVar8 != *(int **)(iVar1 + 0x1c); piVar8 = piVar8 + 1) {
    if (*piVar8 == iStack_20) {
      ExceptionList = pvStack_c;
      return;
    }
  }
  iVar4 = *(int *)(iVar1 + 0x18);
  if ((iVar4 != 0) &&
     ((uint)(*(int *)(iVar1 + 0x1c) - iVar4 >> 2) < (uint)(*(int *)(iVar1 + 0x20) - iVar4 >> 2))) {
    piVar8 = *(int **)(iVar1 + 0x1c);
    *piVar8 = iStack_20;
    *(int **)(iVar1 + 0x1c) = piVar8 + 1;
    ExceptionList = pvStack_c;
    return;
  }
  FUN_0040ccc0((void *)(iVar1 + 0x14),*(undefined4 **)(iVar1 + 0x1c),1,&iStack_20);
  ExceptionList = pvStack_c;
  return;
}


