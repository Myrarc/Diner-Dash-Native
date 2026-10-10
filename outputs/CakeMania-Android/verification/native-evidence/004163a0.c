/* Address: 004163a0; name: FUN_004163a0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004163a0(void *this,float *param_1,float param_2,void *param_3,void *param_4)

{
  char cVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  void **ppvVar7;
  void *pvVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float *pfVar12;
  uint uVar13;
  undefined4 *puVar14;
  int *piVar15;
  undefined4 *puVar16;
  int *piVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  undefined4 in_stack_fffffeec;
  undefined4 in_stack_fffffef0;
  int *local_c0;
  float local_b8;
  float local_b4;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 auStack_70 [15];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  uint uStack_1c;
  uint uStack_18;
  int iStack_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00574ac6;
  pvStack_c = ExceptionList;
  piVar17 = *(int **)((int)this + 0x14);
  local_10 = DAT_005b83e8;
  local_b8 = 0.0;
  local_b4 = 0.0;
  ExceptionList = &pvStack_c;
  ppvVar7 = &pvStack_c;
  local_c0 = piVar17;
  if (piVar17 != *(int **)((int)this + 0x18)) {
    do {
      ExceptionList = ppvVar7;
      local_c0 = local_c0 + 1;
      FUN_00412970((void *)*piVar17,param_2);
      *(float *)(*piVar17 + 0x2e0) = param_2 + *(float *)(*piVar17 + 0x2e0);
      iVar9 = *piVar17;
      if ((*(float *)(iVar9 + 0x2e0) <= *(float *)(iVar9 + 0x2e4) * _DAT_00581420) ||
         (*(float *)(iVar9 + 0x2e0) < *(float *)(iVar9 + 0x2e4) !=
          (*(float *)(iVar9 + 0x2e0) == *(float *)(iVar9 + 0x2e4)))) {
        uVar18 = FUN_00560568();
        *(int *)(iVar9 + 0x2dc) = (int)uVar18;
      }
      else {
        *(undefined4 *)(iVar9 + 0x2e0) = 0;
      }
      if ((*(char *)(*piVar17 + 0x26c) != '\0') && (*(int *)(*piVar17 + 0x14) == 0)) {
        iVar9 = *(int *)(*(int *)((int)this + 0x50) + 0x600);
        if (iVar9 != 0) {
          pvVar8 = FUN_00439510((void *)(iVar9 + 0x1ac),local_80);
          local_4 = 0;
          FUN_0040ded0((void *)(*piVar17 + 0x29c),pvVar8);
          local_4 = 0xffffffff;
          if (local_7c != (void *)0x0) {
            _free(local_7c);
          }
          local_7c = (void *)0x0;
          local_78 = 0;
          local_74 = 0;
        }
        FUN_0040feb0((void *)*piVar17,param_3);
        iVar9 = *piVar17;
        if (*(void **)(iVar9 + 0x2a0) != (void *)0x0) {
          _free(*(void **)(iVar9 + 0x2a0));
        }
        *(undefined4 *)(iVar9 + 0x2a0) = 0;
        *(undefined4 *)(iVar9 + 0x2a4) = 0;
        *(undefined4 *)(iVar9 + 0x2a8) = 0;
      }
      iVar9 = *piVar17;
      cVar1 = *(char *)(iVar9 + 0x26d);
      bVar4 = false;
      bVar5 = false;
      if ((*(float *)(iVar9 + 0x328) < (float)*(int *)(iVar9 + 0x3c)) && (cVar1 == '\0')) {
        bVar4 = true;
        bVar5 = true;
      }
      if ((*(float *)(iVar9 + 0x54) < _DAT_0059d334 != (*(float *)(iVar9 + 0x54) == _DAT_0059d334))
         && (*(char *)(iVar9 + 0x300) == '\0')) {
        *(undefined4 *)(DAT_005b97e4 + 0xc) = 5;
        iVar6 = DAT_005b97e4;
        iVar9 = *(int *)(DAT_005b97e4 + 0xc);
        FUN_00493700(DAT_005b97e4);
        uVar18 = FUN_00560568();
        FUN_00493710(DAT_005b97e4);
        uVar19 = FUN_00560568();
        iVar2 = *piVar17;
        *(int *)(iVar2 + 0x2e8) = iVar6;
        *(int *)(iVar2 + 0x2ec) = iVar9 + -1;
        *(int *)(iVar2 + 0x2f0) = (int)uVar18;
        *(int *)(iVar2 + 0x2f4) = (int)uVar19;
        *(undefined4 *)(iVar2 + 0x2f8) = 0x3dcccccd;
        *(undefined4 *)(iVar2 + 0x2fc) = 0;
        *(undefined1 *)(*piVar17 + 0x300) = 1;
        (**(code **)(*DAT_005ba088 + 0xc4))();
        bVar4 = bVar5;
      }
      iVar9 = *piVar17;
      if ((*(float *)(iVar9 + 0x54) < _DAT_0059d334 != (*(float *)(iVar9 + 0x54) == _DAT_0059d334))
         && (*(char *)(iVar9 + 0x26f) != '\0')) {
        bVar4 = true;
      }
      if (((cVar1 == '\0') && (bVar4)) && (*(char *)(iVar9 + 0x300) == '\0')) {
        (**(code **)(*DAT_005ba088 + 0xc4))();
        local_b8 = local_b8 + _DAT_005814a4;
        iVar9 = *(int *)(*piVar17 + 0x14);
        fVar3 = _DAT_00581880;
        if (iVar9 != 0) {
          if (*(int *)(iVar9 + 0x30) == 0) {
            iVar9 = 0;
          }
          else {
            iVar9 = *(int *)(iVar9 + 0x34) - *(int *)(iVar9 + 0x30) >> 2;
          }
          fVar3 = (float)iVar9;
          if (iVar9 < 0) {
            fVar3 = fVar3 + _DAT_00581608;
          }
          fVar3 = fVar3 * _DAT_0058187c;
        }
        local_b4 = local_b4 + fVar3;
        if (param_4 != (void *)0x0) {
          uVar18 = FUN_00560568();
          uVar10 = (undefined4)uVar18;
          uVar18 = FUN_00560568();
          uVar11 = (undefined4)uVar18;
          uVar18 = FUN_00560568();
          thunk_FUN_00419ab0(param_4,(int)uVar18,uVar11,uVar10);
        }
        *(undefined4 *)(DAT_005b9a2c + 0xc) = 5;
        iVar6 = DAT_005b9a2c;
        iVar9 = *(int *)(DAT_005b9a2c + 0xc);
        FUN_00493700(DAT_005b9a2c);
        uVar18 = FUN_00560568();
        FUN_00493710(DAT_005b9a2c);
        uVar19 = FUN_00560568();
        iVar2 = *piVar17;
        *(int *)(iVar2 + 0x2e8) = iVar6;
        *(int *)(iVar2 + 0x2ec) = iVar9 + -1;
        *(int *)(iVar2 + 0x2f0) = (int)uVar18;
        *(int *)(iVar2 + 0x2f4) = (int)uVar19;
        *(undefined4 *)(iVar2 + 0x2f8) = 0x3dcccccd;
        *(undefined4 *)(iVar2 + 0x2fc) = 0;
        *(undefined1 *)(*piVar17 + 0x300) = 1;
      }
      pvVar8 = (void *)*piVar17;
      if (((*(char *)((int)pvVar8 + 0x300) != '\0') && (*(int *)((int)pvVar8 + 0x2ec) < 0)) &&
         ((*(char *)((int)pvVar8 + 0x26f) != '\0' || (*(int *)((int)pvVar8 + 0x2e8) == DAT_005b9a2c)
          ))) {
        if (pvVar8 != (void *)0x0) {
          FUN_0040f270((int)pvVar8);
          _free(pvVar8);
        }
        if (piVar17 == (int *)(*(int *)((int)this + 0x18) + -4)) {
          if ((*(int *)((int)this + 0x14) != 0) &&
             (*(int *)((int)this + 0x18) - *(int *)((int)this + 0x14) >> 2 != 0)) {
            *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + -4;
          }
          break;
        }
        _memmove(piVar17,local_c0,(*(int *)((int)this + 0x18) - (int)local_c0 >> 2) * 4);
        *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + -4;
      }
      piVar17 = piVar17 + 1;
      ppvVar7 = ExceptionList;
    } while (piVar17 != *(int **)((int)this + 0x18));
  }
  if (*(char *)((int)this + 0x3c) != '\0') {
    pvVar8 = (void *)((int)this + 0x24);
    fVar3 = param_2 + *(float *)((int)this + 0x34);
    *(float *)((int)this + 0x34) = fVar3;
    if (((*(int *)((int)this + 0x28) != 0) &&
        ((*(int *)((int)this + 0x2c) - *(int *)((int)this + 0x28)) / 0x54 != 0)) &&
       (*(float *)((int)this + 0x38) < fVar3)) {
      if (*(int *)((int)this + 0x14) == 0) {
        local_c0 = (int *)0x0;
      }
      else {
        local_c0 = (int *)(*(int *)((int)this + 0x18) - *(int *)((int)this + 0x14) >> 2);
      }
      iVar9 = *(int *)((int)this + 0x28);
      uVar13 = *(uint *)((int)this + 0x48);
      if ((iVar9 == 0) || ((uint)((*(int *)((int)this + 0x2c) - iVar9) / 0x54) <= uVar13)) {
                    /* WARNING: Subroutine does not return */
        FUN_0040bb80();
      }
      if ((int)local_c0 < *(int *)(uVar13 * 0x54 + 8 + iVar9)) {
        iVar9 = *(int *)((int)this + 0x28);
        if ((iVar9 == 0) || ((uint)((*(int *)((int)this + 0x2c) - iVar9) / 0x54) <= uVar13)) {
                    /* WARNING: Subroutine does not return */
          FUN_0040bb80();
        }
        iVar2 = *(int *)((int)this + 0x28);
        if ((iVar2 == 0) || ((uint)((*(int *)((int)this + 0x2c) - iVar2) / 0x54) <= uVar13)) {
                    /* WARNING: Subroutine does not return */
          FUN_0040bb80();
        }
        if (*(float *)(uVar13 * 0x54 + iVar9 + 4) <= *(float *)(uVar13 * 0x54 + iVar2)) {
          iVar9 = FUN_0040c020(pvVar8,uVar13);
          *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(iVar9 + 4);
        }
        else {
          FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          pfVar12 = (float *)FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          FUN_0040c020(pvVar8,uVar13);
          uVar18 = FUN_00560568();
          iVar9 = FUN_004bb1e0();
          *(float *)((int)this + 0x38) = (float)(iVar9 % (int)uVar18) + *pfVar12;
        }
        iVar9 = *(int *)((int)this + 0x28);
        uVar13 = *(uint *)((int)this + 0x48);
        if ((iVar9 == 0) || ((uint)((*(int *)((int)this + 0x2c) - iVar9) / 0x54) <= uVar13)) {
                    /* WARNING: Subroutine does not return */
          FUN_0040bb80();
        }
        iVar2 = *(int *)(uVar13 * 0x54 + 0x20 + iVar9);
        if ((iVar2 == 0) || (*(int *)(uVar13 * 0x54 + iVar9 + 0x24) - iVar2 >> 3 == 0)) {
          FUN_00413b50(this,param_3,(undefined4 *)0xffffffff);
          if ((*(int *)((int)this + 0x50) != 0) &&
             (piVar17 = *(int **)(*(int *)((int)this + 0x50) + 0x600), piVar17 != (int *)0x0)) {
            (**(code **)(*piVar17 + 0x98))();
          }
          *(undefined4 *)((int)this + 0x34) = 0;
        }
        else {
          iVar9 = FUN_0040c020(pvVar8,uVar13);
          puVar14 = *(undefined4 **)(*(int *)(iVar9 + 0x24) + -8);
          iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          FUN_0040e900(auStack_70,(undefined4 *)(*(int *)(iVar9 + 0x4c) + -0x3c));
          local_4 = 1;
          iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          if ((*(int *)(iVar9 + 0x20) != 0) &&
             (*(int *)(iVar9 + 0x24) - *(int *)(iVar9 + 0x20) >> 3 != 0)) {
            *(int *)(iVar9 + 0x24) = *(int *)(iVar9 + 0x24) + -8;
          }
          iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          FUN_00412820(iVar9 + 0x44);
          FUN_0040e900(&stack0xfffffeec,auStack_70);
          FUN_00413c90(this,param_3,puVar14,in_stack_fffffeec,in_stack_fffffef0);
          if ((*(int *)((int)this + 0x50) != 0) &&
             (piVar17 = *(int **)(*(int *)((int)this + 0x50) + 0x600), piVar17 != (int *)0x0)) {
            (**(code **)(*piVar17 + 0x98))();
          }
          iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          if ((*(int *)(iVar9 + 0x20) != 0) &&
             (*(int *)(iVar9 + 0x24) - *(int *)(iVar9 + 0x20) >> 3 != 0)) {
            iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
            *(float *)((int)this + 0x38) = (float)*(int *)(*(int *)(iVar9 + 0x24) + -4);
          }
          local_4 = 0xffffffff;
          FUN_0040baa0((int)auStack_70);
          *(undefined4 *)((int)this + 0x34) = 0;
        }
      }
    }
  }
  if ((*(int *)((int)this + 0x50) != 0) && (*(char *)((int)this + 0x54) != '\0')) {
    pvVar8 = (void *)((int)this + 0x24);
    fVar3 = param_2 + *(float *)((int)this + 0xa8);
    *(float *)((int)this + 0xa8) = fVar3;
    if ((*(int *)((int)this + 0x28) != 0) &&
       (((*(int *)((int)this + 0x2c) - *(int *)((int)this + 0x28)) / 0x54 != 0 &&
        (*(float *)((int)this + 0xac) < fVar3)))) {
      iVar9 = *(int *)((int)this + 0x28);
      uVar13 = *(uint *)((int)this + 0x48);
      if ((iVar9 == 0) || ((uint)((*(int *)((int)this + 0x2c) - iVar9) / 0x54) <= uVar13)) {
                    /* WARNING: Subroutine does not return */
        FUN_0040bb80();
      }
      iVar2 = *(int *)(uVar13 * 0x54 + 0x30 + iVar9);
      if ((iVar2 != 0) && ((*(int *)(uVar13 * 0x54 + iVar9 + 0x34) - iVar2) / 0x24 != 0)) {
        iVar9 = FUN_0040c020(pvVar8,uVar13);
        FUN_0040bb20(auStack_34,(undefined4 *)(*(int *)(iVar9 + 0x34) + -0x24));
        local_4 = 2;
        uVar13 = FUN_004013c0(auStack_30,0,uStack_1c,(byte *)"froster",7);
        if (uVar13 == 0) {
          *(int *)((int)this + 0x5c) = *(int *)((int)this + 0x5c) + iStack_14;
        }
        uVar13 = FUN_004013c0(auStack_30,0,uStack_1c,(byte *)"decorator",9);
        if (uVar13 == 0) {
          *(int *)((int)this + 0x60) = *(int *)((int)this + 0x60) + iStack_14;
        }
        uVar13 = FUN_004013c0(auStack_30,0,uStack_1c,(byte *)"cakeoven",8);
        if (uVar13 == 0) {
          *(int *)((int)this + 0x70) = *(int *)((int)this + 0x70) + iStack_14;
        }
        iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
        FUN_0040ef50(iVar9 + 0x2c);
        iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
        if ((*(int *)(iVar9 + 0x30) != 0) &&
           ((*(int *)(iVar9 + 0x34) - *(int *)(iVar9 + 0x30)) / 0x24 != 0)) {
          iVar9 = FUN_0040c020(pvVar8,*(uint *)((int)this + 0x48));
          *(float *)((int)this + 0xac) = (float)*(int *)(*(int *)(iVar9 + 0x34) + -0x24);
        }
        local_4 = 0xffffffff;
        if (0xf < uStack_18) {
          _free(pvStack_2c);
        }
        uStack_18 = 0xf;
        uStack_1c = 0;
        pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      }
      *(undefined4 *)((int)this + 0xa8) = 0;
    }
    iVar9 = *(int *)(*(int *)((int)this + 0x50) + 0x600);
    piVar17 = *(int **)(iVar9 + 0x1e0);
    if (piVar17 != *(int **)(iVar9 + 0x1e4)) {
      do {
        iVar9 = *piVar17;
        if (((0 < *(int *)((int)this + *(int *)(iVar9 + 0x60) * 4 + 0x58)) &&
            (*(int *)(iVar9 + 0xfc) == 0)) && (*(int *)(iVar9 + 0x34) != 0)) {
          puVar14 = operator_new(0xe0);
          local_4 = 3;
          if (puVar14 == (undefined4 *)0x0) {
            puVar14 = (undefined4 *)0x0;
          }
          else {
            puVar14 = FUN_00425930(puVar14);
          }
          piVar15 = *(int **)(*(int *)((int)this + 0x20) + 0x2c);
          local_4 = 0xffffffff;
          for (; piVar15 != *(int **)(*(int *)((int)this + 0x20) + 0x30); piVar15 = piVar15 + 1) {
            if (*(int *)(*piVar15 + 0x9c) == *(int *)(*piVar17 + 0x60)) {
              puVar16 = (undefined4 *)*piVar15;
              goto LAB_00416e57;
            }
          }
          puVar16 = (undefined4 *)0x0;
LAB_00416e57:
          FUN_0040e980(puVar14,puVar16);
          FUN_00425730(puVar14,*piVar17);
          *(int *)((int)this + *(int *)(*piVar17 + 0x60) * 4 + 0x58) =
               *(int *)((int)this + *(int *)(*piVar17 + 0x60) * 4 + 0x58) + -1;
          if ((*(int *)((int)this + 0x50) != 0) &&
             (piVar15 = *(int **)(*(int *)((int)this + 0x50) + 0x600), piVar15 != (int *)0x0)) {
            (**(code **)(*piVar15 + 0x98))();
          }
        }
        piVar17 = piVar17 + 1;
      } while (piVar17 != *(int **)(*(int *)(*(int *)((int)this + 0x50) + 0x600) + 0x1e4));
    }
  }
  *param_1 = local_b8;
  param_1[1] = local_b4;
  ExceptionList = pvStack_c;
  return;
}


