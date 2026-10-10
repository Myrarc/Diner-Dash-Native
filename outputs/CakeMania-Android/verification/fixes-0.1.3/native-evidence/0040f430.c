/* Native address 0040f430; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0040f430(undefined4 param_1,float *param_2,float *param_3,undefined4 param_4,int param_5,
                int param_6,int param_7)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  float *pfVar10;
  uint uVar11;
  ulonglong uVar12;
  float *pfVar13;
  uint local_5c;
  uint local_58;
  uint local_54;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined1 local_2c [4];
  float *local_28;
  undefined4 *local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00574428;
  local_c = ExceptionList;
  puVar9 = (undefined4 *)0x0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0040e020(local_1c,(int)&param_1);
  pfVar6 = (float *)0x0;
  local_28 = (float *)0x0;
  local_24 = (undefined4 *)0x0;
  local_20 = 0;
  iVar8 = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  pfVar5 = param_2;
  if (param_2 != param_3) {
    do {
      uVar12 = FUN_00560568();
      iVar8 = iVar8 + (int)uVar12;
      pfVar5 = pfVar5 + 2;
    } while (pfVar5 != param_3);
  }
  iVar3 = 0;
  local_58 = 0;
  if (param_2 != (float *)0x0) {
    iVar3 = (int)param_3 - (int)param_2 >> 3;
  }
  if ((param_5 != iVar3) && (iVar8 < 100)) {
    if (param_2 == (float *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)param_3 - (int)param_2 >> 3;
    }
    local_58 = (100U - iVar8) / (uint)(param_5 - iVar3);
  }
  local_54 = 0;
  if (0 < param_5) {
    do {
      pfVar5 = param_3;
      local_5c = local_54;
      if ((param_7 != 0) && (param_6 != -1)) {
        if (param_6 == 0) {
          iVar8 = *(int *)(param_7 + 0x18);
          if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= local_54))
          goto LAB_0040fdc8;
          local_5c = *(uint *)(iVar8 + local_54 * 4);
        }
        else if (param_6 == 2) {
          iVar8 = *(int *)(param_7 + 0x28);
          if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= local_54))
          goto LAB_0040fdc8;
          local_5c = *(uint *)(iVar8 + local_54 * 4);
        }
        else if (param_6 == 3) {
          iVar8 = *(int *)(param_7 + 0x38);
          if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= local_54))
          goto LAB_0040fdc8;
          local_5c = *(uint *)(iVar8 + local_54 * 4);
        }
      }
      bVar2 = false;
      if (param_2 == param_3) {
LAB_0040f687:
        if ((pfVar6 == (float *)0x0) || (uVar4 = (int)puVar9 - (int)pfVar6 >> 3, uVar4 == 0)) {
          local_34 = (float)(int)local_5c;
          local_30 = (float)(int)local_58;
          if ((pfVar6 == (float *)0x0) ||
             ((uint)(local_20 - (int)pfVar6 >> 3) <= (uint)((int)puVar9 - (int)pfVar6 >> 3))) {
            pfVar6 = &local_34;
            goto LAB_0040f724;
          }
          pfVar5 = &local_34;
        }
        else {
          local_3c = (float)(int)local_5c;
          local_38 = (float)(int)local_58 + (float)puVar9[-1];
          if ((uint)(local_20 - (int)pfVar6 >> 3) <= uVar4) {
            pfVar6 = &local_3c;
LAB_0040f724:
            FUN_0040c290(local_2c,puVar9,1,pfVar6);
            pfVar6 = local_28;
            puVar9 = local_24;
            goto LAB_0040f738;
          }
          pfVar5 = &local_3c;
        }
        FUN_0040b0a0(puVar9,1,pfVar5);
        local_24 = puVar9 + 2;
        puVar9 = local_24;
      }
      else {
        fVar1 = (float)(int)local_5c;
        iVar8 = local_20;
        pfVar10 = param_2;
        do {
          if (*pfVar10 == fVar1) {
            if ((pfVar6 == (float *)0x0) || (uVar4 = (int)puVar9 - (int)pfVar6 >> 3, uVar4 == 0)) {
              local_40 = pfVar10[1];
              local_44 = fVar1;
              if ((pfVar6 != (float *)0x0) &&
                 ((uint)((int)puVar9 - (int)pfVar6 >> 3) < (uint)(iVar8 - (int)pfVar6 >> 3))) {
                pfVar13 = &local_44;
                goto LAB_0040f5ff;
              }
              pfVar6 = &local_44;
LAB_0040f654:
              FUN_0040c290(local_2c,puVar9,1,pfVar6);
              pfVar6 = local_28;
            }
            else {
              local_48 = (float)puVar9[-1] + pfVar10[1];
              local_4c = fVar1;
              if ((uint)(iVar8 - (int)pfVar6 >> 3) <= uVar4) {
                pfVar6 = &local_4c;
                goto LAB_0040f654;
              }
              pfVar13 = &local_4c;
LAB_0040f5ff:
              FUN_0040b0a0(puVar9,1,pfVar13);
              local_24 = puVar9 + 2;
            }
            bVar2 = true;
            iVar8 = local_20;
            puVar9 = local_24;
          }
          pfVar10 = pfVar10 + 2;
        } while (pfVar10 != pfVar5);
        if (!bVar2) goto LAB_0040f687;
      }
LAB_0040f738:
      local_54 = local_54 + 1;
    } while ((int)local_54 < param_5);
  }
  iVar8 = _rand();
  pfVar6 = local_28;
  iVar8 = iVar8 % 100;
  bVar2 = true;
  pfVar5 = local_28 + 1;
  for (uVar4 = 0; (local_28 != (float *)0x0 && (uVar4 < (uint)((int)puVar9 - (int)local_28 >> 3)));
      uVar4 = uVar4 + 1) {
    if (*pfVar5 != _DAT_0059d334) {
      bVar2 = false;
    }
    pfVar5 = pfVar5 + 2;
  }
  if (bVar2) {
    iVar8 = _rand();
    iVar8 = iVar8 % param_5;
    if (pfVar6 == (float *)0x0) goto LAB_0040fe26;
LAB_0040fe1e:
    _free(pfVar6);
LAB_0040fe26:
    if (local_18 != (void *)0x0) {
      _free(local_18);
    }
    if (param_2 != (float *)0x0) {
      _free(param_2);
    }
    ExceptionList = local_c;
    return iVar8;
  }
  if (local_28 == (float *)0x0) goto LAB_0040fe68;
  uVar4 = (int)puVar9 - (int)local_28 >> 3;
  if (uVar4 != 0) {
    if (-1 < iVar8) {
      if (uVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      fVar1 = local_28[1];
      if ((float)iVar8 < fVar1 != ((float)iVar8 == fVar1)) {
        if ((param_7 != 0) && (param_6 != -1)) {
          if (param_6 == 0) {
            for (uVar11 = 0;
                (iVar8 = *(int *)(param_7 + 0x18), iVar8 != 0 &&
                (uVar11 < (uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
              if ((iVar8 == 0) ||
                 ((((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)) ||
                  ((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11)))) goto LAB_0040fdc8;
              if (uVar4 == 0) goto LAB_0040fdcd;
              if (*local_28 == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
            }
          }
          else if (param_6 == 2) {
            for (uVar11 = 0;
                (iVar8 = *(int *)(param_7 + 0x28), iVar8 != 0 &&
                (uVar11 < (uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
              if (((iVar8 == 0) ||
                  (((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)))) ||
                 ((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fdc8;
              if (uVar4 == 0) goto LAB_0040fdcd;
              if (*local_28 == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
            }
          }
          else if (param_6 == 3) {
            for (uVar11 = 0;
                (iVar8 = *(int *)(param_7 + 0x38), iVar8 != 0 &&
                (uVar11 < (uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
              if ((iVar8 == 0) ||
                 ((((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)) ||
                  ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11)))) {
LAB_0040fdc8:
                    /* WARNING: Subroutine does not return */
                FUN_00406800();
              }
              if (uVar4 == 0) {
LAB_0040fdcd:
                    /* WARNING: Subroutine does not return */
                FUN_00406800();
              }
              if (*local_28 == (float)*(int *)(iVar8 + uVar11 * 4)) {
LAB_0040fdd6:
                _free(local_28);
                if (local_18 != (void *)0x0) {
                  _free(local_18);
                }
                if (param_2 != (float *)0x0) {
                  _free(param_2);
                }
                ExceptionList = local_c;
                return uVar11;
              }
            }
          }
        }
        goto LAB_0040fe60;
      }
    }
    pfVar5 = local_28 + 3;
    for (uVar7 = 1; uVar7 < uVar4; uVar7 = uVar7 + 1) {
      if (uVar4 <= uVar7 - 1) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      fVar1 = (float)iVar8;
      if (pfVar5[-2] <= fVar1) {
        if (uVar4 <= uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_00406800();
        }
        if (fVar1 < *pfVar5 != (fVar1 == *pfVar5)) {
          if ((param_7 == 0) || (param_6 == -1)) goto LAB_0040fbc5;
          if (param_6 == 0) {
            uVar11 = 0;
            goto LAB_0040fb60;
          }
          if (param_6 == 2) {
            uVar11 = 0;
            goto LAB_0040fae0;
          }
          if (param_6 != 3) goto LAB_0040fbc5;
          uVar11 = 0;
          goto LAB_0040fa40;
        }
      }
      pfVar5 = pfVar5 + 2;
    }
    if (uVar4 <= uVar4 - 1) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    if (local_28[(uVar4 - 1) * 2 + 1] <= (float)iVar8) {
      if ((param_7 != 0) && (param_6 != -1)) {
        if (param_6 == 0) {
          for (uVar11 = 0;
              (iVar8 = *(int *)(param_7 + 0x18), iVar8 != 0 &&
              (uVar11 < (uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
            if ((iVar8 == 0) ||
               ((((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)) ||
                ((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11)))) goto LAB_0040fdc8;
            if (uVar4 <= uVar4 - 1) goto LAB_0040fdcd;
            if (local_28[(uVar4 - 1) * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
          }
        }
        else if (param_6 == 2) {
          for (uVar11 = 0;
              (iVar8 = *(int *)(param_7 + 0x28), iVar8 != 0 &&
              (uVar11 < (uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
            if (((iVar8 == 0) ||
                (((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)))) ||
               ((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fdc8;
            if (uVar4 <= uVar4 - 1) goto LAB_0040fdcd;
            if (local_28[(uVar4 - 1) * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
          }
        }
        else if (param_6 == 3) {
          for (uVar11 = 0;
              (iVar8 = *(int *)(param_7 + 0x38), iVar8 != 0 &&
              (uVar11 < (uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2))); uVar11 = uVar11 + 1) {
            if ((iVar8 == 0) ||
               ((((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)) ||
                ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11)))) goto LAB_0040fdc8;
            if (uVar4 <= uVar4 - 1) goto LAB_0040fdcd;
            if (local_28[(uVar4 - 1) * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
          }
        }
      }
      iVar8 = uVar4 - 1;
      goto LAB_0040fe1e;
    }
  }
LAB_0040fe60:
  _free(local_28);
LAB_0040fe68:
  if (local_18 != (void *)0x0) {
    _free(local_18);
  }
  if (param_2 != (float *)0x0) {
    _free(param_2);
  }
  ExceptionList = local_c;
  return 0;
LAB_0040fb60:
  iVar8 = *(int *)(param_7 + 0x18);
  if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fbc5;
  if ((iVar8 == 0) ||
     ((((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0)) ||
      ((uint)(*(int *)(param_7 + 0x1c) - iVar8 >> 2) <= uVar11)))) goto LAB_0040fdc8;
  if (uVar4 <= uVar7) goto LAB_0040fdcd;
  if (local_28[uVar7 * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
  uVar11 = uVar11 + 1;
  goto LAB_0040fb60;
LAB_0040fae0:
  iVar8 = *(int *)(param_7 + 0x28);
  if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fbc5;
  if (((iVar8 == 0) || (((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11 || (iVar8 == 0))))
     || ((uint)(*(int *)(param_7 + 0x2c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fdc8;
  if (uVar4 <= uVar7) goto LAB_0040fdcd;
  if (local_28[uVar7 * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
  uVar11 = uVar11 + 1;
  goto LAB_0040fae0;
LAB_0040fa40:
  iVar8 = *(int *)(param_7 + 0x38);
  if ((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11)) {
LAB_0040fbc5:
    _free(local_28);
    if (local_18 != (void *)0x0) {
      _free(local_18);
    }
    if (param_2 != (float *)0x0) {
      _free(param_2);
    }
    ExceptionList = local_c;
    return uVar7;
  }
  if ((((iVar8 == 0) || ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11)) || (iVar8 == 0))
     || ((uint)(*(int *)(param_7 + 0x3c) - iVar8 >> 2) <= uVar11)) goto LAB_0040fdc8;
  if (uVar4 <= uVar7) goto LAB_0040fdcd;
  if (local_28[uVar7 * 2] == (float)*(int *)(iVar8 + uVar11 * 4)) goto LAB_0040fdd6;
  uVar11 = uVar11 + 1;
  goto LAB_0040fa40;
}

