/* Address: 00454c50; name: FUN_00454c50 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __thiscall FUN_00454c50(void *this,LPCSTR param_1)

{
  undefined1 uVar1;
  char cVar2;
  bool bVar3;
  undefined4 *this_00;
  int iVar4;
  char ****ppppcVar5;
  void *pvVar6;
  char ****ppppcVar7;
  uint uVar8;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  undefined4 extraout_EAX_02;
  int *extraout_ECX;
  int *extraout_ECX_00;
  undefined1 *puVar12;
  char *pcVar13;
  char local_4c5;
  char *local_4c4;
  undefined4 *local_4c0;
  undefined4 *local_4bc;
  float local_4b8;
  long local_4b4;
  void *local_4b0;
  long local_4ac;
  undefined1 local_4a8 [4];
  void *local_4a4;
  undefined4 local_494;
  uint local_490;
  float local_48c;
  float local_488;
  float local_484;
  float local_480;
  undefined1 local_47c [4];
  void *local_478;
  undefined4 local_468;
  uint local_464;
  undefined1 local_460 [4];
  void *local_45c;
  undefined4 local_44c;
  uint local_448;
  undefined1 local_444 [4];
  void *local_440;
  undefined4 local_430;
  uint local_42c;
  undefined1 local_428 [4];
  void *local_424;
  undefined4 local_414;
  uint local_410;
  long local_40c;
  long local_408;
  long local_404;
  long local_400;
  undefined4 local_3fc;
  undefined1 local_3f8 [28];
  undefined1 local_3dc [28];
  undefined1 local_3c0 [28];
  undefined1 local_3a4 [28];
  undefined1 local_388 [28];
  undefined1 local_36c [28];
  undefined1 local_350 [28];
  undefined1 local_334 [28];
  undefined1 local_318 [28];
  undefined1 local_2fc [28];
  undefined1 local_2e0 [28];
  undefined1 local_2c4 [28];
  undefined1 local_2a8 [28];
  undefined1 local_28c [28];
  undefined1 local_270 [28];
  undefined1 local_254 [28];
  undefined1 local_238 [28];
  undefined1 local_21c [28];
  undefined1 local_200 [28];
  undefined1 local_1e4 [28];
  undefined1 local_1c8 [28];
  undefined1 local_1ac [28];
  undefined1 local_190 [28];
  undefined1 local_174 [28];
  undefined1 local_158 [28];
  long local_13c;
  void *local_138;
  long local_134;
  long local_130;
  undefined4 local_12c;
  undefined4 local_128;
  uint local_124;
  int local_120;
  undefined1 local_11c [20];
  uint local_108;
  undefined1 local_100 [20];
  uint local_ec;
  undefined1 local_c8 [24];
  undefined1 local_b0 [4];
  char ***local_ac [5];
  uint local_98;
  undefined1 local_94 [4];
  undefined1 local_90;
  undefined4 local_80;
  undefined4 local_7c;
  long local_74;
  long local_70;
  long local_6c;
  long local_68;
  long local_64;
  undefined1 local_60 [4];
  undefined1 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  long local_40;
  long local_3c;
  long local_38;
  long local_34;
  long local_30;
  undefined1 local_2c [28];
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00579d88;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  local_4c4 = (char *)0x0;
  ExceptionList = &pvStack_c;
  local_4b0 = this;
  FUN_004547c0(this,local_b0,param_1);
  local_4 = 0;
  local_4c0 = operator_new(0x78);
  local_4._0_1_ = 1;
  if (local_4c0 == (undefined4 *)0x0) {
    this_00 = (undefined4 *)0x0;
    piVar10 = extraout_ECX;
  }
  else {
    this_00 = (undefined4 *)FUN_004c5210(local_4c0);
    piVar10 = extraout_ECX_00;
  }
  local_4._0_1_ = 0;
  uVar1 = (undefined1)local_4;
  local_4._0_1_ = 0;
  local_4bc = this_00;
  if ((*(int *)((int)this + 0x130) != 0) &&
     (uVar1 = (undefined1)local_4, *(int *)(*(int *)((int)this + 0x130) + 0x718) != 0)) {
    local_4c4 = "error";
    ppppcVar5 = (char ****)local_ac[0];
    if (local_98 < 0x10) {
      ppppcVar5 = local_ac;
    }
    local_4c0 = (undefined4 *)&stack0xfffffb24;
    FUN_00401490(&stack0xfffffb24,(LPCSTR)ppppcVar5);
    FUN_004d0fb0(*(void **)(*(int *)((int)this + 0x130) + 0x718),(int *)&local_4c4,&local_4b4,
                 piVar10);
    iVar4 = __stricmp(local_4c4,"error");
    uVar1 = (undefined1)local_4;
    if (iVar4 != 0) {
      ppppcVar5 = (char ****)local_ac[0];
      if (local_98 < 0x10) {
        ppppcVar5 = local_ac;
      }
      FUN_004022f0(local_4a8,(char *)ppppcVar5);
      local_4._0_1_ = 2;
      FUN_004beaa0(this_00,(int)local_4c4,local_4b4,(int)local_4a8);
      local_4._0_1_ = 0;
      uVar1 = (undefined1)local_4;
      if (0xf < local_490) {
        _free(local_4a4);
        uVar1 = (undefined1)local_4;
      }
    }
  }
  local_4._0_1_ = uVar1;
  pvVar6 = FUN_004bd700(this_00,local_4a8);
  uVar8 = *(uint *)((int)pvVar6 + 0x14);
  bVar3 = false;
  local_4 = CONCAT31(local_4._1_3_,3);
  local_4c4 = (char *)0x1;
  if (uVar8 == 0) {
    ppppcVar5 = (char ****)local_ac[0];
    if (local_98 < 0x10) {
      ppppcVar5 = local_ac;
    }
    local_124 = 0xf;
    local_128 = 0;
    local_138 = (void *)((uint)local_138 & 0xffffff00);
    ppppcVar7 = ppppcVar5;
    do {
      cVar2 = *(char *)ppppcVar7;
      ppppcVar7 = (char ****)((int)ppppcVar7 + 1);
    } while (cVar2 != '\0');
    FUN_00401f60(&local_13c,ppppcVar5,(int)ppppcVar7 - (int)((int)ppppcVar5 + 1));
    bVar3 = true;
    local_4 = 4;
    local_4c4 = (char *)0x3;
    uVar8 = FUN_004be9a0(local_4bc,(int)&local_13c);
    local_4c5 = '\x01';
    if ((char)uVar8 == '\0') goto LAB_00454e5a;
  }
  local_4c5 = '\0';
LAB_00454e5a:
  if (bVar3) {
    uVar8 = local_124;
    if (0xf < local_124) {
      _free(local_138);
      uVar8 = extraout_EAX;
    }
    local_124 = 0xf;
    local_128 = 0;
    local_138 = (void *)((uint)local_138 & 0xffffff00);
  }
  local_4 = 0;
  if (0xf < local_490) {
    _free(local_4a4);
    uVar8 = extraout_EAX_00;
  }
  uVar8 = CONCAT31((int3)(uVar8 >> 8),local_4c5);
  if (local_4c5 == '\0') {
    FUN_00405700((int)&local_120);
    pcVar13 = (char *)0xffffffff;
    local_4 = CONCAT31(local_4._1_3_,5);
    local_4c4 = (char *)0xffffffff;
    local_4ac = 0;
    local_4b4 = 0;
    uVar9 = FUN_004c7ea0(local_4bc,&local_120);
    cVar2 = (char)uVar9;
    while (cVar2 != '\0') {
      if (local_120 == 1) {
        uVar8 = FUN_004013c0(local_11c,0,local_108,(byte *)"Levels",6);
        if (uVar8 == 0) {
          uVar8 = FUN_004013c0(local_100,0,local_ec,(byte *)"Level",5);
          if (uVar8 == 0) {
            local_464 = 0xf;
            local_468 = 0;
            local_478 = (void *)((uint)local_478 & 0xffffff00);
            FUN_00401f60(local_47c,(undefined4 *)"y_save",6);
            local_4._0_1_ = 6;
            local_410 = 0xf;
            local_414 = 0;
            local_424 = (void *)((uint)local_424 & 0xffffff00);
            FUN_00401f60(local_428,(undefined4 *)"x_save",6);
            local_4 = CONCAT31(local_4._1_3_,7);
            piVar10 = FUN_00404ab0(local_c8,local_47c);
            if ((uint)piVar10[6] < 0x10) {
              piVar10 = piVar10 + 1;
            }
            else {
              piVar10 = (int *)piVar10[1];
            }
            piVar11 = FUN_00404ab0(local_c8,local_428);
            if ((uint)piVar11[6] < 0x10) {
              piVar11 = piVar11 + 1;
            }
            else {
              piVar11 = (int *)piVar11[1];
            }
            local_4b8 = (float)_atol((char *)piVar10);
            local_4c0 = (undefined4 *)(float)(int)local_4b8;
            local_4b8 = (float)_atol((char *)piVar11);
            local_484 = (float)(int)local_4b8;
            local_480 = (float)local_4c0;
            *(float *)((int)local_4b0 + 0x138) = local_484;
            *(undefined4 **)((int)local_4b0 + 0x13c) = local_4c0;
            if (0xf < local_410) {
              _free(local_424);
            }
            local_410 = 0xf;
            local_414 = 0;
            local_424 = (void *)((uint)local_424 & 0xffffff00);
            local_4._0_1_ = 5;
            if (0xf < local_464) {
              _free(local_478);
            }
            local_464 = 0xf;
            local_468 = 0;
            local_478 = (void *)((uint)local_478 & 0xffffff00);
            local_42c = 0xf;
            local_430 = 0;
            local_440 = (void *)((uint)local_440 & 0xffffff00);
            FUN_00401f60(local_444,(undefined4 *)"y_continue",10);
            local_4._0_1_ = 8;
            local_448 = 0xf;
            local_44c = 0;
            local_45c = (void *)((uint)local_45c & 0xffffff00);
            FUN_00401f60(local_460,(undefined4 *)"x_continue",10);
            local_4 = CONCAT31(local_4._1_3_,9);
            piVar10 = FUN_00404ab0(local_c8,local_444);
            if ((uint)piVar10[6] < 0x10) {
              piVar10 = piVar10 + 1;
            }
            else {
              piVar10 = (int *)piVar10[1];
            }
            piVar11 = FUN_00404ab0(local_c8,local_460);
            if ((uint)piVar11[6] < 0x10) {
              piVar11 = piVar11 + 1;
            }
            else {
              piVar11 = (int *)piVar11[1];
            }
            local_4c0 = (undefined4 *)_atol((char *)piVar10);
            local_4b8 = (float)(int)local_4c0;
            local_4c0 = (undefined4 *)_atol((char *)piVar11);
            local_48c = (float)(int)local_4c0;
            *(float *)((int)local_4b0 + 0x144) = local_4b8;
            *(float *)((int)local_4b0 + 0x140) = local_48c;
            local_488 = local_4b8;
            if (0xf < local_448) {
              _free(local_45c);
            }
            local_448 = 0xf;
            local_44c = 0;
            local_45c = (void *)((uint)local_45c & 0xffffff00);
            local_4 = CONCAT31(local_4._1_3_,5);
            if (0xf < local_42c) {
              _free(local_440);
            }
            local_42c = 0xf;
            local_430 = 0;
            local_440 = (void *)((uint)local_440 & 0xffffff00);
            pcVar13 = local_4c4;
            this = local_4b0;
          }
        }
        else {
          uVar8 = FUN_004013c0(local_11c,0,local_108,(byte *)"Levels/Level",0xc);
          if (uVar8 == 0) {
            uVar8 = FUN_004013c0(local_100,0,local_ec,(byte *)"SubLevel",8);
            if (uVar8 == 0) {
              local_490 = 0xf;
              local_494 = 0;
              local_4a4 = (void *)((uint)local_4a4 & 0xffffff00);
              FUN_00401f60(local_4a8,(undefined4 *)&DAT_005814e8,2);
              local_4._0_1_ = 10;
              piVar10 = FUN_00404ab0(local_c8,local_4a8);
              if ((uint)piVar10[6] < 0x10) {
                piVar10 = piVar10 + 1;
              }
              else {
                piVar10 = (int *)piVar10[1];
              }
              pcVar13 = (char *)_atol((char *)piVar10);
              local_4 = CONCAT31(local_4._1_3_,5);
              local_4c4 = pcVar13;
              if (0xf < local_490) {
                _free(local_4a4);
              }
              local_490 = 0xf;
              local_494 = 0;
              local_4a4 = (void *)((uint)local_4a4 & 0xffffff00);
            }
          }
          else {
            uVar8 = FUN_004013c0(local_11c,0,local_108,(byte *)"Levels/Level/SubLevel",0x15);
            if ((uVar8 == 0) && (pcVar13 == *(char **)((int)this + 0x14c))) {
              uVar8 = FUN_004013c0(local_100,0,local_ec,(byte *)"EndScreenSuccess",0x10);
              if (uVar8 == 0) {
                FUN_004022f0(local_3a4,"spacing");
                local_4 = CONCAT31(local_4._1_3_,0xb);
                piVar10 = FUN_00404ab0(local_c8,local_3a4);
                if ((uint)piVar10[6] < 0x10) {
                  local_4ac = _atol((char *)(piVar10 + 1));
                  puVar12 = local_3a4;
                }
                else {
                  local_4ac = _atol((char *)piVar10[1]);
                  puVar12 = local_3a4;
                }
              }
              else {
                bVar3 = FUN_00401b90(local_100,(byte *)"EndScreenFailed");
                if (!bVar3) goto LAB_00455ee7;
                FUN_004022f0(local_21c,"spacing");
                local_4 = CONCAT31(local_4._1_3_,0xc);
                piVar10 = FUN_00404ab0(local_c8,local_21c);
                if ((uint)piVar10[6] < 0x10) {
                  local_4b4 = _atol((char *)(piVar10 + 1));
                  puVar12 = local_21c;
                }
                else {
                  local_4b4 = _atol((char *)piVar10[1]);
                  puVar12 = local_21c;
                }
              }
LAB_00455eda:
              local_4 = CONCAT31(local_4._1_3_,5);
              FUN_0049fbf0((int)puVar12);
            }
            else {
              uVar8 = FUN_004013c0(local_11c,0,local_108,
                                   (byte *)"Levels/Level/SubLevel/EndScreenSuccess",0x26);
              if ((uVar8 == 0) && (pcVar13 == *(char **)((int)this + 0x14c))) {
                bVar3 = FUN_00401b90(local_100,&DAT_00586f7c);
                if (bVar3) {
                  local_48 = 0xf;
                  local_4c = 0;
                  local_5c = 0;
                  local_4._0_1_ = 0xd;
                  local_30 = local_4ac;
                  FUN_004022f0(local_36c,"text");
                  local_4._0_1_ = 0xe;
                  piVar10 = FUN_00404ab0(local_c8,local_36c);
                  if ((uint)piVar10[6] < 0x10) {
                    piVar10 = piVar10 + 1;
                  }
                  else {
                    piVar10 = (int *)piVar10[1];
                  }
                  FUN_004020a0(local_60,(char *)piVar10);
                  local_4._0_1_ = 0xd;
                  FUN_0049fbf0((int)local_36c);
                  FUN_004022f0(local_1c8,"x");
                  local_4._0_1_ = 0xf;
                  piVar10 = FUN_00404ab0(local_c8,local_1c8);
                  if ((uint)piVar10[6] < 0x10) {
                    piVar10 = piVar10 + 1;
                  }
                  else {
                    piVar10 = (int *)piVar10[1];
                  }
                  local_40 = _atol((char *)piVar10);
                  local_4._0_1_ = 0xd;
                  FUN_0049fbf0((int)local_1c8);
                  FUN_004022f0(local_334,"y");
                  local_4._0_1_ = 0x10;
                  piVar10 = FUN_00404ab0(local_c8,local_334);
                  if ((uint)piVar10[6] < 0x10) {
                    piVar10 = piVar10 + 1;
                  }
                  else {
                    piVar10 = (int *)piVar10[1];
                  }
                  local_3c = _atol((char *)piVar10);
                  local_4._0_1_ = 0xd;
                  FUN_0049fbf0((int)local_334);
                  FUN_004022f0(local_3f8,"w");
                  local_4._0_1_ = 0x11;
                  piVar10 = FUN_00404ab0(local_c8,local_3f8);
                  if ((uint)piVar10[6] < 0x10) {
                    piVar10 = piVar10 + 1;
                  }
                  else {
                    piVar10 = (int *)piVar10[1];
                  }
                  local_38 = _atol((char *)piVar10);
                  local_4._0_1_ = 0xd;
                  FUN_0049fbf0((int)local_3f8);
                  FUN_004022f0(local_2fc,"h");
                  local_4._0_1_ = 0x12;
                  piVar10 = FUN_00404ab0(local_c8,local_2fc);
                  if ((uint)piVar10[6] < 0x10) {
                    piVar10 = piVar10 + 1;
                  }
                  else {
                    piVar10 = (int *)piVar10[1];
                  }
                  local_34 = _atol((char *)piVar10);
                  local_4._0_1_ = 0xd;
                  FUN_0049fbf0((int)local_2fc);
                  FUN_00454730((void *)((int)this + 0x170),local_60);
                  local_4 = CONCAT31(local_4._1_3_,5);
                  FUN_0049fbf0((int)local_60);
                }
                else {
                  bVar3 = FUN_00401b90(local_100,(byte *)"Image");
                  if (bVar3) {
                    FUN_004022f0(local_190,"img");
                    local_4._0_1_ = 0x13;
                    piVar10 = FUN_00404ab0(local_c8,local_190);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    iVar4 = FUN_00433e00((char *)piVar10);
                    local_3fc = FUN_00427410(iVar4);
                    local_4._0_1_ = 5;
                    FUN_0049fbf0((int)local_190);
                    FUN_004022f0(local_2c4,"x");
                    local_4._0_1_ = 0x14;
                    piVar10 = FUN_00404ab0(local_c8,local_2c4);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_40c = _atol((char *)piVar10);
                    local_4._0_1_ = 5;
                    FUN_0049fbf0((int)local_2c4);
                    FUN_004022f0(local_1ac,"y");
                    local_4._0_1_ = 0x15;
                    piVar10 = FUN_00404ab0(local_c8,local_1ac);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_408 = _atol((char *)piVar10);
                    local_4._0_1_ = 5;
                    FUN_0049fbf0((int)local_1ac);
                    FUN_004022f0(local_28c,"w");
                    local_4._0_1_ = 0x16;
                    piVar10 = FUN_00404ab0(local_c8,local_28c);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_404 = _atol((char *)piVar10);
                    local_4._0_1_ = 5;
                    FUN_0049fbf0((int)local_28c);
                    FUN_004022f0(local_1e4,"h");
                    local_4._0_1_ = 0x17;
                    piVar10 = FUN_00404ab0(local_c8,local_1e4);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_400 = _atol((char *)piVar10);
                    local_4 = CONCAT31(local_4._1_3_,5);
                    FUN_0049fbf0((int)local_1e4);
                    FUN_004541c0((void *)((int)this + 0x150),&local_40c);
                  }
                  else {
                    bVar3 = FUN_00401b90(local_100,(byte *)"Button");
                    if (bVar3) {
                      FUN_004022f0(local_254,"text");
                      local_4._0_1_ = 0x18;
                      piVar10 = FUN_00404ab0(local_c8,local_254);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      FUN_004020a0(this,(char *)piVar10);
                      local_4._0_1_ = 5;
                      FUN_0049fbf0((int)local_254);
                      FUN_004022f0(local_3dc,"text_save");
                      local_4 = CONCAT31(local_4._1_3_,0x19);
                      piVar10 = FUN_00404ab0(local_c8,local_3dc);
                      if ((uint)piVar10[6] < 0x10) {
                        FUN_004020a0((void *)((int)this + 0x38),(char *)(piVar10 + 1));
                        puVar12 = local_3dc;
                      }
                      else {
                        FUN_004020a0((void *)((int)this + 0x38),(char *)piVar10[1]);
                        puVar12 = local_3dc;
                      }
                      goto LAB_00455eda;
                    }
                  }
                }
              }
              else {
                uVar8 = FUN_004013c0(local_11c,0,local_108,
                                     (byte *)"Levels/Level/SubLevel/EndScreenFailed",0x25);
                if ((uVar8 == 0) && (pcVar13 == *(char **)((int)this + 0x14c))) {
                  bVar3 = FUN_00401b90(local_100,&DAT_00586f7c);
                  if (bVar3) {
                    local_7c = 0xf;
                    local_80 = 0;
                    local_90 = 0;
                    local_64 = local_4b4;
                    local_4._0_1_ = 0x1a;
                    FUN_004022f0(local_3c0,"text");
                    local_4._0_1_ = 0x1b;
                    piVar10 = FUN_00404ab0(local_c8,local_3c0);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    FUN_004020a0(local_94,(char *)piVar10);
                    local_4._0_1_ = 0x1a;
                    FUN_0049fbf0((int)local_3c0);
                    FUN_004022f0(local_388,"x");
                    local_4._0_1_ = 0x1c;
                    piVar10 = FUN_00404ab0(local_c8,local_388);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_74 = _atol((char *)piVar10);
                    local_4._0_1_ = 0x1a;
                    FUN_0049fbf0((int)local_388);
                    FUN_004022f0(local_350,"y");
                    local_4._0_1_ = 0x1d;
                    piVar10 = FUN_00404ab0(local_c8,local_350);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_70 = _atol((char *)piVar10);
                    local_4._0_1_ = 0x1a;
                    FUN_0049fbf0((int)local_350);
                    FUN_004022f0(local_318,"w");
                    local_4._0_1_ = 0x1e;
                    piVar10 = FUN_00404ab0(local_c8,local_318);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_6c = _atol((char *)piVar10);
                    local_4._0_1_ = 0x1a;
                    FUN_0049fbf0((int)local_318);
                    FUN_004022f0(local_2e0,"h");
                    local_4._0_1_ = 0x1f;
                    piVar10 = FUN_00404ab0(local_c8,local_2e0);
                    if ((uint)piVar10[6] < 0x10) {
                      piVar10 = piVar10 + 1;
                    }
                    else {
                      piVar10 = (int *)piVar10[1];
                    }
                    local_68 = _atol((char *)piVar10);
                    local_4._0_1_ = 0x1a;
                    FUN_0049fbf0((int)local_2e0);
                    FUN_00454730((void *)((int)this + 0x180),local_94);
                    local_4 = CONCAT31(local_4._1_3_,5);
                    FUN_0049fbf0((int)local_94);
                  }
                  else {
                    bVar3 = FUN_00401b90(local_100,(byte *)"Image");
                    if (bVar3) {
                      FUN_004022f0(local_2a8,"img");
                      local_4._0_1_ = 0x20;
                      piVar10 = FUN_00404ab0(local_c8,local_2a8);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      iVar4 = FUN_00433e00((char *)piVar10);
                      local_12c = FUN_00427410(iVar4);
                      local_4._0_1_ = 5;
                      FUN_0049fbf0((int)local_2a8);
                      FUN_004022f0(local_270,"x");
                      local_4._0_1_ = 0x21;
                      piVar10 = FUN_00404ab0(local_c8,local_270);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      local_13c = _atol((char *)piVar10);
                      local_4._0_1_ = 5;
                      FUN_0049fbf0((int)local_270);
                      FUN_004022f0(local_238,"y");
                      local_4._0_1_ = 0x22;
                      piVar10 = FUN_00404ab0(local_c8,local_238);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      local_138 = (void *)_atol((char *)piVar10);
                      local_4._0_1_ = 5;
                      FUN_0049fbf0((int)local_238);
                      FUN_004022f0(local_200,"w");
                      local_4._0_1_ = 0x23;
                      piVar10 = FUN_00404ab0(local_c8,local_200);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      local_134 = _atol((char *)piVar10);
                      local_4._0_1_ = 5;
                      FUN_0049fbf0((int)local_200);
                      FUN_004022f0(local_158,"h");
                      local_4._0_1_ = 0x24;
                      piVar10 = FUN_00404ab0(local_c8,local_158);
                      if ((uint)piVar10[6] < 0x10) {
                        piVar10 = piVar10 + 1;
                      }
                      else {
                        piVar10 = (int *)piVar10[1];
                      }
                      local_130 = _atol((char *)piVar10);
                      local_4 = CONCAT31(local_4._1_3_,5);
                      FUN_0049fbf0((int)local_158);
                      FUN_004541c0((void *)((int)this + 0x160),&local_13c);
                    }
                    else {
                      bVar3 = FUN_00401b90(local_100,(byte *)"Button");
                      if (bVar3) {
                        FUN_004022f0(local_174,"text");
                        local_4._0_1_ = 0x25;
                        piVar10 = FUN_00404ab0(local_c8,local_174);
                        if ((uint)piVar10[6] < 0x10) {
                          piVar10 = piVar10 + 1;
                        }
                        else {
                          piVar10 = (int *)piVar10[1];
                        }
                        FUN_004020a0((void *)((int)this + 0x1c),(char *)piVar10);
                        local_4._0_1_ = 5;
                        FUN_0049fbf0((int)local_174);
                        FUN_004022f0(local_2c,"text_save");
                        local_4 = CONCAT31(local_4._1_3_,0x26);
                        piVar10 = FUN_00404ab0(local_c8,local_2c);
                        if ((uint)piVar10[6] < 0x10) {
                          piVar10 = piVar10 + 1;
                        }
                        else {
                          piVar10 = (int *)piVar10[1];
                        }
                        FUN_004020a0((void *)((int)this + 0x38),(char *)piVar10);
                        puVar12 = local_2c;
                        goto LAB_00455eda;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_00455ee7:
      uVar9 = FUN_004c7ea0(local_4bc,&local_120);
      cVar2 = (char)uVar9;
    }
    if (local_4bc != (undefined4 *)0x0) {
      (**(code **)*local_4bc)();
    }
    *(undefined4 *)((int)this + 0xa8) = 0x7d;
    *(undefined4 *)((int)this + 0x10c) = 0x7d;
    local_4 = local_4 & 0xffffff00;
    uVar9 = FUN_004057a0((int)&local_120);
    if (0xf < local_98) {
      _free(local_ac[0]);
      uVar9 = extraout_EAX_02;
    }
    uVar8 = CONCAT31((int3)((uint)uVar9 >> 8),1);
  }
  else {
    if (local_4bc != (undefined4 *)0x0) {
      uVar8 = (**(code **)*local_4bc)();
    }
    if (0xf < local_98) {
      _free(local_ac[0]);
      uVar8 = extraout_EAX_01;
    }
    uVar8 = uVar8 & 0xffffff00;
  }
  ExceptionList = pvStack_c;
  return uVar8;
}


