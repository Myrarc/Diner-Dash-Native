/* Address: 0044fd60; name: FUN_0044fd60 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044fd60(int *param_1)

{
  uint *puVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  undefined4 *puVar6;
  uint *puVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  uint uVar12;
  uint *puVar13;
  float10 fVar14;
  ulonglong uVar15;
  undefined4 in_stack_ffffff7c;
  uint in_stack_ffffff80;
  void *pvVar16;
  undefined4 *apuStack_58 [2];
  undefined1 *puStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  undefined1 uStack_38;
  int iStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_0057960e;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  FUN_004d2fb0((int)param_1);
  (**(code **)(*param_1 + 0x10))();
  if (*(char *)((int)DAT_005ba088 + 0x47a) != '\0') {
    if (((char)param_1[0xb9] != '\0') && (*(int *)(param_1[0x6a] + 0x9d0c) == 0)) {
      uVar12 = 0;
      while( true ) {
        iVar9 = param_1[0x6a];
        iVar3 = *(int *)(iVar9 + 0x30);
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar9 + 0x34) - iVar3 >> 3) <= uVar12)) break;
        puStack_50 = (undefined1 *)(float)param_1[0xb8];
        apuStack_58[0] = (undefined4 *)(float)param_1[0xb7];
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar9 + 0x34) - iVar3 >> 3) <= uVar12))
        goto LAB_0045029a;
        fVar8 = *(float *)(iVar3 + 4 + uVar12 * 8) - (float)puStack_50;
        fVar2 = *(float *)(iVar3 + uVar12 * 8) - (float)apuStack_58[0];
        if (SQRT(fVar2 * fVar2 + fVar8 * fVar8) < _DAT_00581488) {
          if ((iVar3 == 0) || ((uint)(*(int *)(iVar9 + 0x34) - iVar3 >> 3) <= uVar12))
          goto LAB_0045029a;
          apuStack_58[0] = (undefined4 *)&stack0xffffff8c;
          FUN_00403e10((void *)param_1[0x6a],*(float *)(iVar3 + uVar12 * 8),
                       *(float *)(iVar3 + 4 + uVar12 * 8));
        }
        uVar12 = uVar12 + 1;
      }
      *(undefined1 *)(param_1 + 0xb9) = 0;
    }
    FUN_00404800((void *)param_1[0x6a]);
    pfVar5 = (float *)(param_1 + 0x5a);
    fVar14 = FUN_00409b10(pfVar5);
    param_1[0xbb] = (int)(float)fVar14;
    puVar10 = (undefined4 *)param_1[0x110];
    if (puVar10 != (undefined4 *)param_1[0x111]) {
      do {
        pfVar4 = (float *)*puVar10;
        if (pfVar4 != (float *)0x0) {
          if (pfVar4[0x11] == 0.0) {
            fVar2 = (float)param_1[0xbb] + pfVar4[1];
            pfVar4[1] = fVar2;
            if (*pfVar4 < fVar2) {
              pfVar4[1] = *pfVar4;
              pfVar4[0x11] = 1.4013e-45;
            }
          }
          else if ((pfVar4[0x11] == 2.8026e-45) &&
                  (fVar2 = pfVar4[1] - (float)param_1[0xbb], pfVar4[1] = fVar2,
                  fVar2 < _DAT_0059d334)) {
            pfVar4[1] = 0.0;
            pfVar4[0x11] = 4.2039e-45;
          }
        }
        puVar10 = puVar10 + 1;
      } while (puVar10 != (undefined4 *)param_1[0x111]);
    }
    piVar11 = (int *)param_1[0x110];
    if (piVar11 != (int *)param_1[0x111]) {
      do {
        if ((*piVar11 != 0) && (*(int *)(*piVar11 + 0x44) == 3)) {
          pvVar16 = (void *)*piVar11;
          if (pvVar16 != (void *)0x0) {
            if (0xf < *(uint *)((int)pvVar16 + 0x38)) {
              _free(*(void **)((int)pvVar16 + 0x24));
            }
            *(undefined4 *)((int)pvVar16 + 0x38) = 0xf;
            *(undefined4 *)((int)pvVar16 + 0x34) = 0;
            *(undefined1 *)((int)pvVar16 + 0x24) = 0;
            _free(pvVar16);
          }
          _memmove(piVar11,piVar11 + 1,(param_1[0x111] - (int)(piVar11 + 1) >> 2) * 4);
          param_1[0x111] = param_1[0x111] + -4;
          break;
        }
        piVar11 = piVar11 + 1;
      } while (piVar11 != (int *)param_1[0x111]);
    }
    iVar9 = FUN_00418c60((int)(param_1 + 0xda));
    if (iVar9 != 0) {
      *pfVar5 = 0.0;
      if ((char)param_1[0xb5] != '\0') {
        *(undefined1 *)(param_1 + 0x113) = 1;
      }
      *(undefined1 *)(param_1 + 0xb5) = 0;
    }
    if (_DAT_0059d334 < (float)param_1[0x114]) {
      param_1[0x114] = (int)((float)param_1[0x114] - (float)param_1[0xbb]);
    }
    if ((float)param_1[0x114] < _DAT_0059d334) {
      *(undefined1 *)(param_1 + 0x113) = 1;
      param_1[0x114] = 0;
    }
    FUN_004040e0((void *)param_1[0x6a],(float)param_1[0xbb]);
    if ((*pfVar5 < (float)param_1[0xbe] != (*pfVar5 == (float)param_1[0xbe])) ||
       ((((float)param_1[0xbe] < *pfVar5 && (param_1[0x84] != 0)) &&
        (param_1[0x85] - param_1[0x84] >> 2 != 0)))) {
      FUN_004163a0(param_1 + 0x7f,(float *)apuStack_58,(float)param_1[0xbb],
                   (void *)(param_1[0x21] + 0x664),(void *)0x0);
    }
    apuStack_58[0] = (undefined4 *)param_1[0xbb];
    pvVar16 = (void *)param_1[0x69];
    *(undefined4 **)((int)pvVar16 + 0x1c) = apuStack_58[0];
    FUN_00419540(pvVar16,(float)apuStack_58[0]);
    FUN_004392a0(param_1 + 0x6b,(float)param_1[0xbb]);
    fVar2 = (float)param_1[0x11d];
    param_1[0x11d] = (int)(fVar2 + (float)param_1[0xbb]);
    if ((float)param_1[0x11e] < fVar2 + (float)param_1[0xbb]) {
      param_1[0x11d] = 0;
      if ((char)param_1[0x11f] == '\0') {
        iVar9 = param_1[0x11c] + -0x19;
      }
      else {
        iVar9 = param_1[0x11c] + 0x19;
      }
      param_1[0x11c] = iVar9;
      if (0xff < param_1[0x11c]) {
        *(undefined1 *)(param_1 + 0x11f) = 0;
        param_1[0x11c] = 0xff;
      }
      if (param_1[0x11c] < 0) {
        *(undefined1 *)(param_1 + 0x11f) = 1;
        param_1[0x11c] = 0;
      }
    }
    if (((param_1[0x57] != 0) && (param_1[0x58] - param_1[0x57] >> 3 != 0)) &&
       (*(int *)(param_1[0x6a] + 0x9d0c) == 0)) {
      if ((param_1[0x57] == 0) || (param_1[0x58] - param_1[0x57] >> 3 == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      if ((param_1[0x57] == 0) || (param_1[0x58] - param_1[0x57] >> 3 == 0)) {
LAB_004501ab:
                    /* WARNING: Subroutine does not return */
        FUN_00406800();
      }
      uVar15 = FUN_00560568();
      iVar9 = (int)uVar15;
      uVar15 = FUN_00560568();
      FUN_0044f2b0(param_1,(int)uVar15,iVar9);
      if (*(int *)(param_1[0x6a] + 0x9d0c) == 0) {
        uVar12 = 0;
        while( true ) {
          iVar9 = param_1[0x6a];
          if ((*(int *)(iVar9 + 0x30) == 0) ||
             ((uint)(*(int *)(iVar9 + 0x34) - *(int *)(iVar9 + 0x30) >> 3) <= uVar12)) break;
          pfVar5 = (float *)param_1[0x57];
          if ((pfVar5 == (float *)0x0) || (param_1[0x58] - (int)pfVar5 >> 3 == 0))
          goto LAB_004501ab;
          iVar3 = *(int *)(iVar9 + 0x30);
          if ((iVar3 == 0) || ((uint)(*(int *)(iVar9 + 0x34) - iVar3 >> 3) <= uVar12))
          goto LAB_0045029a;
          puStack_50 = (undefined1 *)(*(float *)(iVar3 + uVar12 * 8) - *pfVar5);
          fVar2 = *(float *)(iVar3 + 4 + uVar12 * 8) - pfVar5[1];
          if (SQRT((float)puStack_50 * (float)puStack_50 + fVar2 * fVar2) < _DAT_00581488) {
            if ((iVar3 == 0) || ((uint)(*(int *)(iVar9 + 0x34) - iVar3 >> 3) <= uVar12)) {
LAB_0045029a:
                    /* WARNING: Subroutine does not return */
              FUN_00406800();
            }
            apuStack_58[0] = (undefined4 *)&stack0xffffff8c;
            FUN_00403e10((void *)param_1[0x6a],*(float *)(iVar3 + uVar12 * 8),
                         *(float *)(iVar3 + 4 + uVar12 * 8));
          }
          uVar12 = uVar12 + 1;
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
        puVar6 = (undefined4 *)param_1[0x58];
        puVar10 = (undefined4 *)(param_1[0x57] + 8);
        if (puVar10 != puVar6) {
          iVar9 = param_1[0x57] - (int)puVar10;
          do {
            *(undefined4 *)(iVar9 + (int)puVar10) = *puVar10;
            *(undefined4 *)(iVar9 + 4 + (int)puVar10) = puVar10[1];
            puVar10 = puVar10 + 2;
          } while (puVar10 != puVar6);
        }
        param_1[0x58] = param_1[0x58] + -8;
      }
    }
    if ((*(int *)(param_1[0x6a] + 0x9d0c) == 0) &&
       ((param_1[0x57] == 0 || (param_1[0x58] - param_1[0x57] >> 3 == 0)))) {
      FUN_00436660((int)(param_1 + 0x6b));
    }
    iVar9 = FUN_00418c60((int)(param_1 + 0xc0));
    if (iVar9 != 0) {
      FUN_0041f740(param_1[0x21]);
    }
    if ((((char)param_1[0x113] != '\0') && (param_1[0x10c] != 0)) &&
       (apuStack_58[0] = (undefined4 *)((param_1[0x10d] - param_1[0x10c]) / 0x3c),
       apuStack_58[0] != (undefined4 *)0x0)) {
      iVar9 = param_1[0x10d];
      iStack_4c = *(int *)(iVar9 + -0x3c);
      iStack_48 = *(int *)(iVar9 + -0x38);
      iStack_44 = *(int *)(iVar9 + -0x34);
      iStack_40 = *(int *)(iVar9 + -0x30);
      iStack_3c = *(int *)(iVar9 + -0x2c);
      uStack_38 = *(undefined1 *)(iVar9 + -0x28);
      iStack_34 = *(int *)(iVar9 + -0x24);
      uStack_18 = 0xf;
      uStack_1c = 0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
      FUN_00401e70(auStack_30,(void *)(iVar9 + -0x20),0,0xffffffff);
      uStack_14 = *(undefined4 *)(iVar9 + -4);
      iStack_4 = 0;
      if (param_1[0x10c] != 0) {
        puVar7 = (uint *)param_1[0x10d];
        apuStack_58[0] = (undefined4 *)(((int)puVar7 - param_1[0x10c]) / 0x3c);
        if (apuStack_58[0] != (undefined4 *)0x0) {
          if (puVar7 + -0xf != puVar7) {
            puVar13 = puVar7 + -2;
            do {
              if (0xf < *puVar13) {
                _free((void *)puVar13[-5]);
              }
              *puVar13 = 0xf;
              puVar13[-1] = 0;
              *(undefined1 *)(puVar13 + -5) = 0;
              puVar1 = puVar13 + 2;
              puVar13 = puVar13 + 0xf;
            } while (puVar1 != puVar7);
          }
          param_1[0x10d] = param_1[0x10d] + -0x3c;
        }
      }
      switch(uStack_14) {
      case 0:
        puVar10 = FUN_00412740((void *)param_1[0x87],iStack_34);
        puStack_50 = &stack0xffffff7c;
        pvVar16 = (void *)(in_stack_ffffff80 & 0xffffff00);
        apuStack_58[0] = puVar10;
        FUN_00401e70(&stack0xffffff7c,auStack_30,0,0xffffffff);
        FUN_0040e810(puVar10,in_stack_ffffff7c,pvVar16);
        FUN_0040ee80(param_1 + 0x83,apuStack_58);
        (**(code **)(*DAT_005ba088 + 0xc4))();
        break;
      case 1:
        param_1[0x114] = iStack_3c;
        *(undefined1 *)(param_1 + 0x113) = 0;
        break;
      case 2:
        apuStack_58[0] = operator_new(0x48);
        iStack_4._0_1_ = 1;
        if (apuStack_58[0] == (undefined4 *)0x0) {
          puVar10 = (undefined4 *)0x0;
        }
        else {
          puVar10 = FUN_0044ee00(apuStack_58[0]);
        }
        puVar10[2] = param_1[0x11a];
        puVar10[3] = iStack_4c;
        puVar10[4] = iStack_48;
        puVar10[5] = iStack_44;
        puVar10[6] = iStack_40;
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        apuStack_58[0] = puVar10;
        FUN_00401e70(puVar10 + 8,auStack_30,0,0xffffffff);
        puVar10[0xf] = iStack_34;
        puVar10[0x10] = 0;
        FUN_0044f9f0(param_1 + 0x10f,apuStack_58);
        break;
      case 3:
        apuStack_58[0] = operator_new(0x48);
        iStack_4._0_1_ = 2;
        if (apuStack_58[0] == (undefined4 *)0x0) {
          apuStack_58[0] = (undefined4 *)0x0;
        }
        else {
          apuStack_58[0] = FUN_0044ee00(apuStack_58[0]);
        }
        apuStack_58[0][2] = param_1[0x11b];
        apuStack_58[0][3] = iStack_4c;
        apuStack_58[0][4] = iStack_48;
        apuStack_58[0][5] = iStack_44;
        apuStack_58[0][6] = iStack_40;
        apuStack_58[0][7] = iStack_3c;
        apuStack_58[0][0xf] = iStack_34;
        iStack_4 = (uint)iStack_4._1_3_ << 8;
        apuStack_58[0][0x10] = 1;
        FUN_0044f9f0(param_1 + 0x10f,apuStack_58);
        break;
      case 4:
        param_1[0x115] = iStack_4c;
        param_1[0x116] = iStack_48;
        param_1[0x117] = iStack_44;
        param_1[0x118] = iStack_40;
        *(undefined1 *)(param_1 + 0x113) = 0;
        break;
      case 5:
        piVar11 = (int *)param_1[0x110];
        if (piVar11 != (int *)param_1[0x111]) {
          do {
            iVar9 = *piVar11;
            if (((iVar9 != 0) && (*(int *)(iVar9 + 0x3c) == iStack_34)) &&
               (*(int *)(iVar9 + 0x40) == 0)) {
              *(undefined4 *)(*piVar11 + 0x44) = 2;
              break;
            }
            piVar11 = piVar11 + 1;
          } while (piVar11 != (int *)param_1[0x111]);
        }
        break;
      case 6:
        piVar11 = (int *)param_1[0x110];
        if (piVar11 != (int *)param_1[0x111]) {
          do {
            iVar9 = *piVar11;
            if (((iVar9 != 0) && (*(int *)(iVar9 + 0x3c) == iStack_34)) &&
               (*(int *)(iVar9 + 0x40) == 1)) {
              *(undefined4 *)(*piVar11 + 0x44) = 2;
              break;
            }
            piVar11 = piVar11 + 1;
          } while (piVar11 != (int *)param_1[0x111]);
        }
        break;
      case 7:
        param_1[0x119] = iStack_34;
        *(undefined1 *)(param_1 + 0x113) = 0;
      }
      iStack_4 = 0xffffffff;
      if (0xf < uStack_18) {
        _free(pvStack_2c);
      }
      uStack_18 = 0xf;
      uStack_1c = 0;
      pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
    }
    FUN_0043a020();
    (**(code **)(*param_1 + 0x98))();
  }
  ExceptionList = pvStack_c;
  return;
}


