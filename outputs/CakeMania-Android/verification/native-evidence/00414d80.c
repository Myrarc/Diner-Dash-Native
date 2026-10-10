/* Address: 00414d80; name: FUN_00414d80 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00414d80(void *this,LPCSTR param_1)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  void *pvVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  long lVar13;
  float *pfVar14;
  int *extraout_ECX;
  void *pvVar15;
  char *pcVar16;
  uint uVar17;
  undefined4 *puVar18;
  int iVar19;
  byte ****ppppbVar20;
  undefined4 *this_00;
  byte *pbVar21;
  void *this_01;
  bool bVar22;
  bool bVar23;
  double dVar24;
  undefined4 in_stack_fffffc7c;
  char *in_stack_fffffc80;
  undefined4 *puStack_358;
  undefined4 *local_354;
  undefined4 *puStack_350;
  int *local_34c;
  undefined4 *puStack_348;
  void *local_344;
  byte *local_340;
  undefined ***local_33c;
  float fStack_338;
  undefined1 *puStack_334;
  float fStack_330;
  undefined1 *puStack_32c;
  undefined1 auStack_328 [4];
  void *pvStack_324;
  undefined4 uStack_320;
  undefined4 uStack_31c;
  undefined1 auStack_318 [4];
  void *pvStack_314;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined1 auStack_308 [4];
  void *pvStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined1 auStack_2f8 [4];
  void *pvStack_2f4;
  undefined4 uStack_2f0;
  undefined4 uStack_2ec;
  undefined1 auStack_2e8 [4];
  void *pvStack_2e4;
  undefined4 uStack_2e0;
  undefined4 uStack_2dc;
  float fStack_2d4;
  int local_2d0;
  undefined4 local_2cc;
  undefined1 local_2c8 [4];
  void *local_2c4;
  undefined4 local_2b4;
  uint local_2b0;
  undefined1 auStack_2ac [4];
  void *pvStack_2a8;
  undefined4 uStack_298;
  uint uStack_294;
  undefined1 auStack_290 [4];
  void *pvStack_28c;
  undefined4 uStack_27c;
  uint uStack_278;
  undefined **local_274 [15];
  void *local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_220 [24];
  void *local_1c0;
  undefined1 auStack_1b4 [4];
  byte ***apppbStack_1b0 [4];
  uint uStack_1a0;
  uint uStack_19c;
  undefined1 auStack_198 [4];
  byte ***apppbStack_194 [4];
  uint uStack_184;
  uint uStack_180;
  undefined1 auStack_17c [4];
  void *pvStack_178;
  uint uStack_168;
  uint uStack_164;
  int local_160 [28];
  int aiStack_f0 [28];
  int aiStack_80 [28];
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00574a33;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &local_c;
  local_344 = this;
  FUN_00473f40(local_274);
  local_4 = 0;
  local_340 = (byte *)0x58153c;
  if ((*(int *)((int)this + 4) != 0) && (*(int *)(*(int *)((int)this + 4) + 0x718) != 0)) {
    local_354 = (undefined4 *)&stack0xfffffc94;
    piVar7 = extraout_ECX;
    FUN_00401490(&stack0xfffffc94,param_1);
    FUN_004d0fb0(*(void **)(*(int *)((int)this + 4) + 0x718),(int *)&local_340,&local_2cc,piVar7);
  }
  iVar5 = __stricmp((char *)local_340,"error");
  if (iVar5 == 0) {
    FUN_00473fe0(local_274,param_1);
  }
  else {
    FUN_00475f40(local_274,local_340,(undefined4 *)0x0);
  }
  local_33c = local_274;
  FUN_0040ec70(local_220);
  local_4._0_1_ = 1;
  piVar7 = (int *)0x0;
  do {
    do {
      puVar9 = (undefined4 *)0x0;
      puVar6 = (uint *)FUN_004744f0(&local_33c,&local_2d0,"Customers");
      uVar17 = *puVar6;
      if ((uVar17 == 0) || (*(int *)(uVar17 + 0x14) != 1)) {
        pvVar15 = (void *)0x0;
      }
      else {
        pvVar15 = (void *)((*(int *)(uVar17 + 0x14) != 1) - 1 & uVar17);
      }
      piVar7 = (int *)FUN_004734f0(pvVar15,(int)piVar7);
      local_34c = piVar7;
      if (piVar7 == (int *)0x0) {
        if (local_1c0 != (void *)0x0) {
          _free(local_1c0);
        }
        local_4 = 0xffffffff;
        local_274[0] = &PTR_FUN_0058c764;
        if (local_238 != (void *)0x0) {
          _free(local_238);
        }
        local_238 = (void *)0x0;
        local_234 = 0;
        local_230 = 0;
        uVar12 = FUN_00473ba0(local_274);
        ExceptionList = local_c;
        return CONCAT31((int3)((uint)uVar12 >> 8),1);
      }
      if (piVar7[9] == 0) {
        pcVar16 = "";
      }
      else {
        pcVar16 = (char *)piVar7[8];
      }
      iVar5 = 0xf;
      bVar22 = true;
      pcVar11 = "HeartAnimation";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar22 = *pcVar16 == *pcVar11;
        pcVar16 = pcVar16 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
      if (bVar22) {
        local_354 = operator_new(0x78);
        local_4._0_1_ = 2;
        if (local_354 == (undefined4 *)0x0) {
          pvVar15 = (void *)0x0;
        }
        else {
          pvVar15 = (void *)FUN_004c5210(local_354);
        }
        local_4._0_1_ = 1;
        pvVar8 = FUN_004d0c80(local_2c8,piVar7);
        local_4._0_1_ = 3;
        FUN_004c5a90(pvVar15,(int)pvVar8);
        local_4._0_1_ = 1;
        if (0xf < local_2b0) {
          _free(local_2c4);
        }
        local_2b0 = 0xf;
        local_2b4 = 0;
        local_2c4 = (void *)((uint)local_2c4 & 0xffffff00);
        FUN_00405700((int)local_160);
        local_4._0_1_ = 4;
        FUN_004c7ea0(pvVar15,local_160);
        FUN_004132a0((int)local_160,(int)local_220);
        local_4._0_1_ = 1;
        FUN_004057a0((int)local_160);
      }
      if (piVar7[9] == 0) {
        pcVar16 = "";
      }
      else {
        pcVar16 = (char *)piVar7[8];
      }
      iVar5 = 9;
      bVar22 = true;
      pcVar11 = "Customer";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar22 = *pcVar16 == *pcVar11;
        pcVar16 = pcVar16 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
      if (bVar22) {
        local_354 = operator_new(0x32c);
        local_4._0_1_ = 5;
        if (local_354 != (undefined4 *)0x0) {
          puVar9 = FUN_00411c20(local_354);
        }
        local_4 = CONCAT31(local_4._1_3_,1);
        local_354 = puVar9;
        puStack_348 = puVar9;
        for (puVar10 = (undefined4 *)FUN_004734f0(local_34c,0); puStack_358 = puVar10,
            puVar10 != (undefined4 *)0x0;
            puVar10 = (undefined4 *)FUN_004734f0(local_34c,(int)puVar10)) {
          if (puVar10[9] == 0) {
            pcVar16 = "";
          }
          else {
            pcVar16 = (char *)puVar10[8];
          }
          iVar5 = 6;
          bVar22 = true;
          pcVar11 = "Image";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar22 = *pcVar16 == *pcVar11;
            pcVar16 = pcVar16 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar22);
          if (bVar22) {
            if ((puVar10 == (undefined4 *)0x0) || (puVar9 = puVar10, puVar10[5] != 1)) {
              puVar9 = (undefined4 *)0x0;
            }
            pcVar11 = FUN_00474a10(puVar9,"id");
            uStack_19c = 0xf;
            uStack_1a0 = 0;
            apppbStack_1b0[0] = (byte ***)((uint)apppbStack_1b0[0] & 0xffffff00);
            pcVar16 = pcVar11;
            do {
              cVar4 = *pcVar16;
              pcVar16 = pcVar16 + 1;
            } while (cVar4 != '\0');
            FUN_00401f60(auStack_1b4,(undefined4 *)pcVar11,(int)pcVar16 - (int)(pcVar11 + 1));
            iVar5 = -1;
            local_4._0_1_ = 6;
            if (uStack_1a0 != 0) {
              uVar17 = uStack_1a0;
              if (8 < uStack_1a0) {
                uVar17 = 9;
              }
              ppppbVar20 = (byte ****)apppbStack_1b0[0];
              if (uStack_19c < 0x10) {
                ppppbVar20 = apppbStack_1b0;
              }
              bVar22 = false;
              iVar19 = 0;
              bVar23 = true;
              pbVar21 = (byte *)"ID_NORMAL";
              do {
                if (uVar17 == 0) break;
                uVar17 = uVar17 - 1;
                bVar22 = *(byte *)ppppbVar20 < *pbVar21;
                bVar23 = *(byte *)ppppbVar20 == *pbVar21;
                ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
                pbVar21 = pbVar21 + 1;
              } while (bVar23);
              if (!bVar23) {
                iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
              }
              if (((iVar19 == 0) && (8 < uStack_1a0)) && (uStack_1a0 == 9)) {
                iVar5 = 0;
              }
              puVar10 = puStack_358;
              if (uStack_1a0 != 0) {
                uVar17 = uStack_1a0;
                if (6 < uStack_1a0) {
                  uVar17 = 7;
                }
                ppppbVar20 = (byte ****)apppbStack_1b0[0];
                if (uStack_19c < 0x10) {
                  ppppbVar20 = apppbStack_1b0;
                }
                bVar22 = false;
                iVar19 = 0;
                bVar23 = true;
                pbVar21 = (byte *)"ID_MENU";
                do {
                  if (uVar17 == 0) break;
                  uVar17 = uVar17 - 1;
                  bVar22 = *(byte *)ppppbVar20 < *pbVar21;
                  bVar23 = *(byte *)ppppbVar20 == *pbVar21;
                  ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
                  pbVar21 = pbVar21 + 1;
                } while (bVar23);
                if (!bVar23) {
                  iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
                }
                if (((iVar19 == 0) && (6 < uStack_1a0)) && (uStack_1a0 == 7)) {
                  iVar5 = 1;
                }
                if (uStack_1a0 != 0) {
                  uVar17 = uStack_1a0;
                  if (7 < uStack_1a0) {
                    uVar17 = 8;
                  }
                  ppppbVar20 = (byte ****)apppbStack_1b0[0];
                  if (uStack_19c < 0x10) {
                    ppppbVar20 = apppbStack_1b0;
                  }
                  bVar22 = false;
                  iVar19 = 0;
                  bVar23 = true;
                  pbVar21 = (byte *)"ID_HAPPY";
                  do {
                    if (uVar17 == 0) break;
                    uVar17 = uVar17 - 1;
                    bVar22 = *(byte *)ppppbVar20 < *pbVar21;
                    bVar23 = *(byte *)ppppbVar20 == *pbVar21;
                    ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
                    pbVar21 = pbVar21 + 1;
                  } while (bVar23);
                  if (!bVar23) {
                    iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
                  }
                  if (((iVar19 == 0) && (7 < uStack_1a0)) && (uStack_1a0 == 8)) {
                    iVar5 = 2;
                  }
                  if (uStack_1a0 != 0) {
                    uVar17 = uStack_1a0;
                    if (8 < uStack_1a0) {
                      uVar17 = 9;
                    }
                    ppppbVar20 = (byte ****)apppbStack_1b0[0];
                    if (uStack_19c < 0x10) {
                      ppppbVar20 = apppbStack_1b0;
                    }
                    bVar22 = false;
                    iVar19 = 0;
                    bVar23 = true;
                    pbVar21 = (byte *)"ID_EATING";
                    do {
                      if (uVar17 == 0) break;
                      uVar17 = uVar17 - 1;
                      bVar22 = *(byte *)ppppbVar20 < *pbVar21;
                      bVar23 = *(byte *)ppppbVar20 == *pbVar21;
                      ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
                      pbVar21 = pbVar21 + 1;
                    } while (bVar23);
                    if (!bVar23) {
                      iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
                    }
                    if (((iVar19 == 0) && (8 < uStack_1a0)) && (uStack_1a0 == 9)) {
                      iVar5 = 4;
                    }
                  }
                }
              }
            }
            if (uStack_1a0 == 0) {
LAB_0041526c:
              if (iVar5 != -1) goto LAB_00415275;
            }
            else {
              uVar17 = uStack_1a0;
              if (7 < uStack_1a0) {
                uVar17 = 8;
              }
              ppppbVar20 = (byte ****)apppbStack_1b0[0];
              if (uStack_19c < 0x10) {
                ppppbVar20 = apppbStack_1b0;
              }
              bVar22 = false;
              iVar19 = 0;
              bVar23 = true;
              pbVar21 = (byte *)"ID_BORED";
              do {
                if (uVar17 == 0) break;
                uVar17 = uVar17 - 1;
                bVar22 = *(byte *)ppppbVar20 < *pbVar21;
                bVar23 = *(byte *)ppppbVar20 == *pbVar21;
                ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
                pbVar21 = pbVar21 + 1;
              } while (bVar23);
              if (!bVar23) {
                iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
              }
              if (((iVar19 != 0) || (uStack_1a0 < 8)) || (uStack_1a0 != 8)) goto LAB_0041526c;
              iVar5 = 3;
LAB_00415275:
              if ((puVar10 == (undefined4 *)0x0) || (puVar9 = puVar10, puVar10[5] != 1)) {
                puVar9 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar9,"img");
              iVar19 = FUN_00433e00(pcVar16);
              uVar12 = FUN_00427410(iVar19);
              puVar9 = puStack_348;
              puStack_348[iVar5 + 0x16] = uVar12;
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar18,"cols");
              lVar13 = _atol(pcVar16);
              *(long *)(puVar9[iVar5 + 0x16] + 0x10) = lVar13;
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar18,"rows");
              lVar13 = _atol(pcVar16);
              *(long *)(puVar9[iVar5 + 0x16] + 0xc) = lVar13;
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              if ((puVar10 == (undefined4 *)0x0) || (this_00 = puVar10, puVar10[5] != 1)) {
                this_00 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar18,"ydec");
              puStack_358 = (undefined4 *)_atol(pcVar16);
              puStack_350 = (undefined4 *)(float)(int)puStack_358;
              pcVar16 = FUN_00474a10(this_00,"xdec");
              puStack_358 = (undefined4 *)_atol(pcVar16);
              fStack_338 = (float)(int)puStack_358;
              puVar9[iVar5 * 2 + 0x1b] = fStack_338;
              puStack_334 = (undefined1 *)puStack_350;
              puVar9[iVar5 * 2 + 0x1c] = puStack_350;
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar18,"scale");
              dVar24 = _atof(pcVar16);
              puVar9[iVar5 + 0x25] = (float)dVar24;
              pvVar15 = FUN_00410e80(auStack_2f8,puVar10);
              local_4._0_1_ = 7;
              FUN_0040e330(puVar9 + iVar5 * 4 + 0x2a,pvVar15);
              local_4._0_1_ = 6;
              if (pvStack_2f4 != (void *)0x0) {
                _free(pvStack_2f4);
              }
              pvStack_2f4 = (void *)0x0;
              uStack_2f0 = 0;
              uStack_2ec = 0;
              pvVar15 = FUN_00410fe0(auStack_328,puVar10);
              local_4._0_1_ = 8;
              FUN_0040dd80(puVar9 + iVar5 * 4 + 0x3e,pvVar15);
              if (pvStack_324 != (void *)0x0) {
                _free(pvStack_324);
              }
              pvStack_324 = (void *)0x0;
              uStack_320 = 0;
              uStack_31c = 0;
            }
            local_4 = CONCAT31(local_4._1_3_,1);
            if (0xf < uStack_19c) {
              _free(apppbStack_1b0[0]);
            }
            uStack_19c = 0xf;
            uStack_1a0 = 0;
            apppbStack_1b0[0] = (byte ***)((uint)apppbStack_1b0[0] & 0xffffff00);
            puVar9 = puStack_348;
          }
          else {
            if (puVar10[9] == 0) {
              pcVar16 = "";
            }
            else {
              pcVar16 = (char *)puVar10[8];
            }
            iVar5 = 10;
            bVar22 = true;
            pcVar11 = "Animation";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar22 = *pcVar16 == *pcVar11;
              pcVar16 = pcVar16 + 1;
              pcVar11 = pcVar11 + 1;
            } while (bVar22);
            if (bVar22) {
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              pcVar11 = FUN_00474a10(puVar18,"curve");
              puStack_350 = (undefined4 *)&stack0xfffffc7c;
              in_stack_fffffc80 = (char *)((uint)in_stack_fffffc80 & 0xffffff00);
              pcVar16 = pcVar11;
              do {
                cVar4 = *pcVar16;
                pcVar16 = pcVar16 + 1;
              } while (cVar4 != '\0');
              FUN_00401f60(&stack0xfffffc7c,(undefined4 *)pcVar11,(int)pcVar16 - (int)(pcVar11 + 1))
              ;
              pvVar15 = FUN_00410ca0(auStack_2e8,in_stack_fffffc7c,in_stack_fffffc80);
              local_4._0_1_ = 9;
              FUN_00403860(puVar9 + 0xb0,pvVar15);
              local_4 = CONCAT31(local_4._1_3_,1);
              if (pvStack_2e4 != (void *)0x0) {
                _free(pvStack_2e4);
              }
              pvStack_2e4 = (void *)0x0;
              uStack_2e0 = 0;
              uStack_2dc = 0;
              if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                puVar18 = (undefined4 *)0x0;
              }
              pcVar16 = FUN_00474a10(puVar18,"time");
              dVar24 = _atof(pcVar16);
              puVar9[0xb4] = (float)dVar24;
              puVar9[0xb6] = 0;
              pfVar14 = (float *)puVar9[0xb1];
              if (pfVar14 != (float *)(puVar9[0xb2] + -8)) {
                do {
                  pfVar1 = pfVar14 + 2;
                  fStack_2d4 = pfVar14[1];
                  pfVar2 = pfVar14 + 3;
                  fVar3 = *pfVar14;
                  pfVar14 = pfVar14 + 2;
                  puStack_358 = (undefined4 *)(fVar3 - *pfVar1);
                  puVar9[0xb6] = SQRT((float)puStack_358 * (float)puStack_358 +
                                      (fStack_2d4 - *pfVar2) * (fStack_2d4 - *pfVar2)) +
                                 (float)puVar9[0xb6];
                } while (pfVar14 != (float *)(puVar9[0xb2] + -8));
              }
            }
            else {
              if (puVar10[9] == 0) {
                pcVar16 = "";
              }
              else {
                pcVar16 = (char *)puVar10[8];
              }
              iVar5 = 8;
              bVar22 = true;
              pcVar11 = "Message";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar22 = *pcVar16 == *pcVar11;
                pcVar16 = pcVar16 + 1;
                pcVar11 = pcVar11 + 1;
              } while (bVar22);
              if (bVar22) {
                if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                  puVar18 = (undefined4 *)0x0;
                }
                pcVar11 = FUN_00474a10(puVar18,"xtime");
                uStack_164 = 0xf;
                uStack_168 = 0;
                pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
                pcVar16 = pcVar11;
                do {
                  cVar4 = *pcVar16;
                  pcVar16 = pcVar16 + 1;
                } while (cVar4 != '\0');
                FUN_00401f60(auStack_17c,(undefined4 *)pcVar11,(int)pcVar16 - (int)(pcVar11 + 1));
                local_4 = CONCAT31(local_4._1_3_,10);
                uVar17 = FUN_004013c0(auStack_17c,0,uStack_168,(byte *)"atstart",7);
                if (uVar17 == 0) {
                  puVar9[0x9d] = 0xffffffff;
                }
                else {
                  uVar17 = FUN_004013c0(auStack_17c,0,uStack_168,(byte *)"atserved",8);
                  if (uVar17 == 0) {
                    puVar9[0x9d] = 0;
                  }
                  else {
                    if ((puVar10 == (undefined4 *)0x0) || (puVar18 = puVar10, puVar10[5] != 1)) {
                      puVar18 = (undefined4 *)0x0;
                    }
                    pcVar16 = FUN_00474a10(puVar18,"xtime");
                    lVar13 = _atol(pcVar16);
                    puVar9[0x9d] = lVar13;
                  }
                }
                local_4 = CONCAT31(local_4._1_3_,1);
                if (0xf < uStack_164) {
                  _free(pvStack_178);
                }
                uStack_164 = 0xf;
                uStack_168 = 0;
                pvStack_178 = (void *)((uint)pvStack_178 & 0xffffff00);
              }
            }
          }
        }
        puStack_350 = operator_new(0x78);
        local_4._0_1_ = 0xb;
        if (puStack_350 == (undefined4 *)0x0) {
          pvVar15 = (void *)0x0;
        }
        else {
          pvVar15 = (void *)FUN_004c5210(puStack_350);
        }
        local_4._0_1_ = 1;
        pvVar8 = FUN_004d0c80(auStack_2ac,local_34c);
        local_4._0_1_ = 0xc;
        FUN_004c5a90(pvVar15,(int)pvVar8);
        local_4._0_1_ = 1;
        if (0xf < uStack_294) {
          _free(pvStack_2a8);
        }
        uStack_294 = 0xf;
        uStack_298 = 0;
        pvStack_2a8 = (void *)((uint)pvStack_2a8 & 0xffffff00);
        FUN_00405700((int)aiStack_f0);
        local_4 = CONCAT31(local_4._1_3_,0xd);
        FUN_004c7ea0(pvVar15,aiStack_f0);
        pvVar15 = local_344;
        FUN_00414200((int)aiStack_f0,(int)puVar9);
        FUN_0040ebc0(puVar9 + 0x7b,local_220);
        if (puVar9[0xf] == 0) {
          puStack_350 = (undefined4 *)((puVar9[0xe] + 1) * 100);
        }
        else {
          puStack_350 = (undefined4 *)((puVar9[0xe] + 1) * puVar9[0xf]);
        }
        puVar9[0xca] = (float)(int)puStack_350 - (float)_DAT_005813e0;
        iVar5 = *(int *)((int)pvVar15 + 0xc);
        if ((iVar5 == 0) ||
           ((uint)(*(int *)((int)pvVar15 + 0x14) - iVar5 >> 2) <=
            (uint)(*(int *)((int)pvVar15 + 0x10) - iVar5 >> 2))) {
          FUN_0040ccc0((void *)((int)pvVar15 + 8),*(undefined4 **)((int)pvVar15 + 0x10),1,&local_354
                      );
        }
        else {
          pfVar14 = *(float **)((int)pvVar15 + 0x10);
          *pfVar14 = (float)puVar9;
          *(float **)((int)pvVar15 + 0x10) = pfVar14 + 1;
        }
        local_4._0_1_ = 1;
        FUN_004057a0((int)aiStack_f0);
        piVar7 = local_34c;
      }
      if (piVar7[9] == 0) {
        pcVar16 = "";
      }
      else {
        pcVar16 = (char *)piVar7[8];
      }
      iVar5 = 6;
      bVar22 = true;
      pcVar11 = "Gnome";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar22 = *pcVar16 == *pcVar11;
        pcVar16 = pcVar16 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
    } while (!bVar22);
    local_354 = operator_new(0xe0);
    local_4._0_1_ = 0xe;
    if (local_354 == (undefined4 *)0x0) {
      puVar9 = (undefined4 *)0x0;
    }
    else {
      puVar9 = FUN_00425930(local_354);
    }
    piVar7 = local_34c;
    local_4 = CONCAT31(local_4._1_3_,1);
    puStack_358 = puVar9;
    puStack_348 = puVar9;
    pcVar16 = FUN_00474a10((void *)((local_34c[5] != 1) - 1 & (uint)local_34c),"steal_frame");
    lVar13 = _atol(pcVar16);
    puVar9[0x2e] = lVar13;
    pcVar16 = FUN_00474a10((void *)((piVar7[5] != 1) - 1 & (uint)piVar7),"avatar_smack");
    dVar24 = _atof(pcVar16);
    puVar9[0x32] = (float)dVar24;
    for (pvVar15 = (void *)FUN_004734f0(piVar7,0); pvVar15 != (void *)0x0;
        pvVar15 = (void *)FUN_004734f0(local_34c,(int)pvVar15)) {
      if (*(int *)((int)pvVar15 + 0x24) == 0) {
        pcVar16 = "";
      }
      else {
        pcVar16 = *(char **)((int)pvVar15 + 0x20);
      }
      iVar5 = 6;
      bVar22 = true;
      pcVar11 = "Image";
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar22 = *pcVar16 == *pcVar11;
        pcVar16 = pcVar16 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
      if (bVar22) {
        if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
          pvVar8 = (void *)0x0;
        }
        pcVar11 = FUN_00474a10(pvVar8,"id");
        uStack_180 = 0xf;
        uStack_184 = 0;
        apppbStack_194[0] = (byte ***)((uint)apppbStack_194[0] & 0xffffff00);
        pcVar16 = pcVar11;
        do {
          cVar4 = *pcVar16;
          pcVar16 = pcVar16 + 1;
        } while (cVar4 != '\0');
        FUN_00401f60(auStack_198,(undefined4 *)pcVar11,(int)pcVar16 - (int)(pcVar11 + 1));
        iVar5 = -1;
        local_4._0_1_ = 0xf;
        if (uStack_184 != 0) {
          uVar17 = uStack_184;
          if (6 < uStack_184) {
            uVar17 = 7;
          }
          ppppbVar20 = (byte ****)apppbStack_194[0];
          if (uStack_180 < 0x10) {
            ppppbVar20 = apppbStack_194;
          }
          bVar22 = false;
          iVar19 = 0;
          bVar23 = true;
          pbVar21 = (byte *)"ID_LINE";
          do {
            if (uVar17 == 0) break;
            uVar17 = uVar17 - 1;
            bVar22 = *(byte *)ppppbVar20 < *pbVar21;
            bVar23 = *(byte *)ppppbVar20 == *pbVar21;
            ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
            pbVar21 = pbVar21 + 1;
          } while (bVar23);
          if (!bVar23) {
            iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (((iVar19 == 0) && (6 < uStack_184)) && (uStack_184 == 7)) {
            iVar5 = 0;
          }
        }
        if (uStack_184 == 0) {
LAB_00415a9e:
          if (iVar5 != -1) goto LAB_00415aa7;
        }
        else {
          uVar17 = uStack_184;
          if (7 < uStack_184) {
            uVar17 = 8;
          }
          ppppbVar20 = (byte ****)apppbStack_194[0];
          if (uStack_180 < 0x10) {
            ppppbVar20 = apppbStack_194;
          }
          bVar22 = false;
          iVar19 = 0;
          bVar23 = true;
          pbVar21 = (byte *)"ID_SMACK";
          do {
            if (uVar17 == 0) break;
            uVar17 = uVar17 - 1;
            bVar22 = *(byte *)ppppbVar20 < *pbVar21;
            bVar23 = *(byte *)ppppbVar20 == *pbVar21;
            ppppbVar20 = (byte ****)((int)ppppbVar20 + 1);
            pbVar21 = pbVar21 + 1;
          } while (bVar23);
          if (!bVar23) {
            iVar19 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
          }
          if (((iVar19 != 0) || (uStack_184 < 8)) || (uStack_184 != 8)) goto LAB_00415a9e;
          iVar5 = 1;
LAB_00415aa7:
          if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            pvVar8 = (void *)0x0;
          }
          pcVar16 = FUN_00474a10(pvVar8,"img");
          iVar19 = FUN_00433e00(pcVar16);
          uVar12 = FUN_00427410(iVar19);
          puVar9 = puStack_348;
          puStack_348[iVar5] = uVar12;
          if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            pvVar8 = (void *)0x0;
          }
          pcVar16 = FUN_00474a10(pvVar8,"cols");
          lVar13 = _atol(pcVar16);
          *(long *)(puVar9[iVar5] + 0x10) = lVar13;
          if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            pvVar8 = (void *)0x0;
          }
          pcVar16 = FUN_00474a10(pvVar8,"rows");
          lVar13 = _atol(pcVar16);
          *(long *)(puVar9[iVar5] + 0xc) = lVar13;
          if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            pvVar8 = (void *)0x0;
          }
          if ((pvVar15 == (void *)0x0) || (this_01 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            this_01 = (void *)0x0;
          }
          pcVar16 = FUN_00474a10(pvVar8,"ydec");
          local_354 = (undefined4 *)_atol(pcVar16);
          puStack_350 = (undefined4 *)(float)(int)local_354;
          pcVar16 = FUN_00474a10(this_01,"xdec");
          local_354 = (undefined4 *)_atol(pcVar16);
          fStack_330 = (float)(int)local_354;
          puVar9[iVar5 * 2 + 2] = fStack_330;
          puStack_32c = (undefined1 *)puStack_350;
          puVar9[iVar5 * 2 + 3] = puStack_350;
          if ((pvVar15 == (void *)0x0) || (pvVar8 = pvVar15, *(int *)((int)pvVar15 + 0x14) != 1)) {
            pvVar8 = (void *)0x0;
          }
          pcVar16 = FUN_00474a10(pvVar8,"scale");
          dVar24 = _atof(pcVar16);
          puVar9[iVar5 + 6] = (float)dVar24;
          pvVar8 = FUN_00410e80(auStack_308,pvVar15);
          local_4._0_1_ = 0x10;
          FUN_0040e330(puVar9 + (iVar5 + 2) * 4,pvVar8);
          local_4._0_1_ = 0xf;
          if (pvStack_304 != (void *)0x0) {
            _free(pvStack_304);
          }
          pvStack_304 = (void *)0x0;
          uStack_300 = 0;
          uStack_2fc = 0;
          pvVar8 = FUN_00410fe0(auStack_318,pvVar15);
          local_4._0_1_ = 0x11;
          FUN_0040dd80(puVar9 + (iVar5 + 4) * 4,pvVar8);
          if (pvStack_314 != (void *)0x0) {
            _free(pvStack_314);
          }
          pvStack_314 = (void *)0x0;
          uStack_310 = 0;
          uStack_30c = 0;
        }
        local_4 = CONCAT31(local_4._1_3_,1);
        if (0xf < uStack_180) {
          _free(apppbStack_194[0]);
        }
        uStack_180 = 0xf;
        uStack_184 = 0;
        apppbStack_194[0] = (byte ***)((uint)apppbStack_194[0] & 0xffffff00);
        puVar9 = puStack_348;
      }
    }
    local_354 = operator_new(0x78);
    local_4._0_1_ = 0x12;
    if (local_354 == (undefined4 *)0x0) {
      pvVar15 = (void *)0x0;
    }
    else {
      pvVar15 = (void *)FUN_004c5210(local_354);
    }
    local_4._0_1_ = 1;
    pvVar8 = FUN_004d0c80(auStack_290,local_34c);
    local_4._0_1_ = 0x13;
    FUN_004c5a90(pvVar15,(int)pvVar8);
    local_4._0_1_ = 1;
    if (0xf < uStack_278) {
      _free(pvStack_28c);
    }
    uStack_278 = 0xf;
    uStack_27c = 0;
    pvStack_28c = (void *)((uint)pvStack_28c & 0xffffff00);
    FUN_00405700((int)aiStack_80);
    local_4 = CONCAT31(local_4._1_3_,0x14);
    FUN_004c7ea0(pvVar15,aiStack_80);
    pvVar15 = local_344;
    FUN_00412fb0((int)aiStack_80,(int)puVar9);
    iVar5 = *(int *)((int)pvVar15 + 0x2c);
    if ((iVar5 == 0) ||
       ((uint)(*(int *)((int)pvVar15 + 0x34) - iVar5 >> 2) <=
        (uint)(*(int *)((int)pvVar15 + 0x30) - iVar5 >> 2))) {
      FUN_0040ccc0((void *)((int)pvVar15 + 0x28),*(undefined4 **)((int)pvVar15 + 0x30),1,
                   &puStack_358);
    }
    else {
      pfVar14 = *(float **)((int)pvVar15 + 0x30);
      *pfVar14 = (float)puVar9;
      *(float **)((int)pvVar15 + 0x30) = pfVar14 + 1;
    }
    local_4._0_1_ = 1;
    FUN_004057a0((int)aiStack_80);
    piVar7 = local_34c;
  } while( true );
}


