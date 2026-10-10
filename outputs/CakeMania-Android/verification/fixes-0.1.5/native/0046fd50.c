/* Native address 0046fd50; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall FUN_0046fd50(void *this,LPCSTR param_1)

{
  bool bVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  void *pvVar5;
  LPCSTR pCVar6;
  uint uVar7;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint3 uVar11;
  uint3 extraout_var;
  undefined4 uVar8;
  int *piVar9;
  long lVar10;
  int *extraout_ECX;
  int *extraout_ECX_00;
  double dVar12;
  undefined4 in_stack_fffffc30;
  void *in_stack_fffffc34;
  char *pcVar13;
  byte *pbVar14;
  undefined4 *local_39c;
  char *local_398;
  undefined4 *local_394;
  undefined1 local_390 [4];
  void *local_38c;
  undefined4 local_37c;
  uint local_378;
  undefined1 local_374 [4];
  void *local_370;
  undefined4 local_360;
  uint local_35c;
  undefined1 local_358 [4];
  void *local_354;
  undefined4 local_344;
  uint local_340;
  undefined1 local_33c [4];
  void *local_338;
  undefined4 local_328;
  uint local_324;
  undefined1 local_320 [4];
  void *local_31c;
  undefined4 local_30c;
  uint local_308;
  undefined1 local_304 [4];
  void *local_300;
  undefined4 local_2f0;
  uint local_2ec;
  undefined1 local_2e8 [4];
  void *local_2e4;
  undefined4 local_2d4;
  uint local_2d0;
  undefined1 local_2cc [4];
  void *local_2c8;
  undefined4 local_2b8;
  uint local_2b4;
  undefined1 local_2b0 [4];
  void *local_2ac;
  undefined4 local_29c;
  uint local_298;
  undefined1 local_294 [4];
  void *local_290;
  undefined4 local_280;
  uint local_27c;
  undefined1 local_278 [4];
  void *local_274;
  undefined4 local_264;
  uint local_260;
  undefined1 local_25c [4];
  void *local_258;
  undefined4 local_248;
  uint local_244;
  undefined1 local_240 [4];
  void *local_23c;
  undefined4 local_22c;
  uint local_228;
  undefined1 local_224 [4];
  void *local_220;
  undefined4 local_210;
  uint local_20c;
  undefined1 local_208 [4];
  void *local_204;
  undefined4 local_1f4;
  uint local_1f0;
  undefined1 local_1ec [4];
  void *local_1e8;
  undefined4 local_1d8;
  uint local_1d4;
  undefined1 local_1d0 [4];
  void *local_1cc;
  undefined4 local_1bc;
  uint local_1b8;
  undefined1 local_1b4 [28];
  undefined1 local_198 [28];
  undefined1 local_17c [28];
  undefined1 local_160 [28];
  undefined1 local_144 [28];
  undefined1 local_128 [28];
  undefined1 local_10c [28];
  undefined1 local_f0 [28];
  undefined1 local_d4 [28];
  undefined1 local_b8 [28];
  undefined1 local_9c [28];
  int local_80;
  undefined1 local_7c [20];
  uint local_68;
  undefined1 local_60 [20];
  uint local_4c;
  undefined1 local_28 [24];
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0057b7c9;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  local_398 = (char *)0x0;
  ExceptionList = &pvStack_c;
  local_394 = operator_new(0x78);
  local_4 = 0;
  if (local_394 == (undefined4 *)0x0) {
    local_39c = (undefined4 *)0x0;
    piVar9 = extraout_ECX;
  }
  else {
    local_39c = (undefined4 *)FUN_004c5210(local_394);
    piVar9 = extraout_ECX_00;
  }
  local_4 = 0xffffffff;
  if ((*(int *)((int)this + 0x17c) != 0) && (*(int *)(*(int *)((int)this + 0x17c) + 0x718) != 0)) {
    local_394 = (undefined4 *)&stack0xfffffc48;
    local_398 = "error";
    FUN_00401490(&stack0xfffffc48,param_1);
    FUN_004d0fb0(*(void **)(*(int *)((int)this + 0x17c) + 0x718),(int *)&local_398,&local_394,piVar9
                );
    iVar4 = __stricmp(local_398,"error");
    if (iVar4 != 0) {
      FUN_004022f0(local_374,param_1);
      local_4 = 1;
      FUN_004beaa0(local_39c,(int)local_398,local_394,(int)local_374);
      local_4 = 0xffffffff;
      if (0xf < local_35c) {
        _free(local_370);
      }
    }
  }
  pvVar5 = FUN_004bd700(local_39c,local_374);
  uVar7 = *(uint *)((int)pvVar5 + 0x14);
  bVar3 = false;
  local_4 = 2;
  local_398 = (char *)0x1;
  if (uVar7 == 0) {
    local_378 = 0xf;
    local_37c = 0;
    local_38c = (void *)((uint)local_38c & 0xffffff00);
    pCVar6 = param_1;
    do {
      cVar2 = *pCVar6;
      pCVar6 = pCVar6 + 1;
    } while (cVar2 != '\0');
    FUN_00401f60(local_390,(undefined4 *)param_1,(int)pCVar6 - (int)(param_1 + 1));
    bVar3 = true;
    local_4 = 3;
    local_398 = (char *)0x3;
    uVar7 = FUN_004be9a0(local_39c,(int)local_390);
    bVar1 = true;
    if ((char)uVar7 == '\0') goto LAB_0046fef2;
  }
  bVar1 = false;
LAB_0046fef2:
  if (bVar3) {
    uVar7 = local_378;
    if (0xf < local_378) {
      _free(local_38c);
      uVar7 = extraout_EAX;
    }
    local_378 = 0xf;
    local_37c = 0;
    local_38c = (void *)((uint)local_38c & 0xffffff00);
  }
  local_4 = 0xffffffff;
  if (0xf < local_35c) {
    _free(local_370);
    uVar7 = extraout_EAX_00;
  }
  uVar11 = (uint3)(uVar7 >> 8);
  if (bVar1) {
    if (local_39c != (undefined4 *)0x0) {
      (**(code **)*local_39c)();
      uVar11 = extraout_var;
    }
    iVar4 = (uint)uVar11 << 8;
  }
  else {
    FUN_00405700((int)&local_80);
    local_4._0_1_ = 4;
    local_4._1_3_ = 0;
    uVar8 = FUN_004c7ea0(local_39c,&local_80);
    cVar2 = (char)uVar8;
    while (cVar2 != '\0') {
      if (local_80 == 1) {
        uVar7 = FUN_004013c0(local_60,0,local_4c,(byte *)"RenderBackground",0x10);
        if (uVar7 == 0) {
          local_378 = 0xf;
          local_37c = 0;
          local_38c = (void *)((uint)local_38c & 0xffffff00);
          FUN_00401f60(local_390,(undefined4 *)&DAT_00581660,1);
          local_4._0_1_ = 5;
          piVar9 = FUN_00404ab0(local_28,local_390);
          if ((uint)piVar9[6] < 0x10) {
            piVar9 = piVar9 + 1;
          }
          else {
            piVar9 = (int *)piVar9[1];
          }
          lVar10 = _atol((char *)piVar9);
          *(long *)((int)this + 0x420) = lVar10;
          local_4._0_1_ = 4;
          if (0xf < local_378) {
            _free(local_38c);
          }
          local_378 = 0xf;
          local_37c = 0;
          local_38c = (void *)((uint)local_38c & 0xffffff00);
          local_340 = 0xf;
          local_344 = 0;
          local_354 = (void *)((uint)local_354 & 0xffffff00);
          FUN_00401f60(local_358,(undefined4 *)&DAT_0058165c,1);
          local_4._0_1_ = 6;
          piVar9 = FUN_00404ab0(local_28,local_358);
          if ((uint)piVar9[6] < 0x10) {
            piVar9 = piVar9 + 1;
          }
          else {
            piVar9 = (int *)piVar9[1];
          }
          lVar10 = _atol((char *)piVar9);
          *(long *)((int)this + 0x424) = lVar10;
          local_4._0_1_ = 4;
          if (0xf < local_340) {
            _free(local_354);
          }
          local_340 = 0xf;
          local_344 = 0;
          local_354 = (void *)((uint)local_354 & 0xffffff00);
          local_298 = 0xf;
          local_29c = 0;
          local_2ac = (void *)((uint)local_2ac & 0xffffff00);
          FUN_00401f60(local_2b0,(undefined4 *)"scale_x",7);
          local_4._0_1_ = 7;
          piVar9 = FUN_00404ab0(local_28,local_2b0);
          if ((uint)piVar9[6] < 0x10) {
            piVar9 = piVar9 + 1;
          }
          else {
            piVar9 = (int *)piVar9[1];
          }
          dVar12 = _atof((char *)piVar9);
          *(float *)((int)this + 0x428) = (float)dVar12;
          local_4._0_1_ = 4;
          if (0xf < local_298) {
            _free(local_2ac);
          }
          local_298 = 0xf;
          local_29c = 0;
          local_2ac = (void *)((uint)local_2ac & 0xffffff00);
          local_2b4 = 0xf;
          local_2b8 = 0;
          local_2c8 = (void *)((uint)local_2c8 & 0xffffff00);
          FUN_00401f60(local_2cc,(undefined4 *)"scale_y",7);
          local_4._0_1_ = 8;
          piVar9 = FUN_00404ab0(local_28,local_2cc);
          if ((uint)piVar9[6] < 0x10) {
            piVar9 = piVar9 + 1;
          }
          else {
            piVar9 = (int *)piVar9[1];
          }
          dVar12 = _atof((char *)piVar9);
          *(float *)((int)this + 0x42c) = (float)dVar12;
          local_4._0_1_ = 4;
          if (0xf < local_2b4) {
            _free(local_2c8);
          }
          local_2b4 = 0xf;
          local_2b8 = 0;
          local_2c8 = (void *)((uint)local_2c8 & 0xffffff00);
          local_2ec = 0xf;
          local_2f0 = 0;
          local_300 = (void *)((uint)local_300 & 0xffffff00);
          FUN_00401f60(local_304,(undefined4 *)"music",5);
          local_4._0_1_ = 9;
          piVar9 = FUN_00404ab0(local_28,local_304);
          local_394 = (undefined4 *)&stack0xfffffc30;
          in_stack_fffffc34 = (void *)((uint)in_stack_fffffc34 & 0xffffff00);
          FUN_00401e70(&stack0xfffffc30,piVar9,0,0xffffffff);
          FUN_0041a4d0((void *)((int)this + 0x220),*(undefined4 *)((int)this + 0x17c),
                       in_stack_fffffc30,in_stack_fffffc34);
          local_4._0_1_ = 4;
          if (0xf < local_2ec) {
            _free(local_300);
          }
          local_2ec = 0xf;
          local_2f0 = 0;
          local_300 = (void *)((uint)local_300 & 0xffffff00);
          *(undefined4 *)((int)this + 0x1b8) = *(undefined4 *)((int)this + 0x17c);
        }
        else {
          uVar7 = FUN_004013c0(local_7c,0,local_68,(byte *)"RenderBackground",0x10);
          if (uVar7 == 0) {
            uVar7 = FUN_004013c0(local_60,0,local_4c,(byte *)"Image",5);
            if (uVar7 == 0) {
              local_324 = 0xf;
              local_328 = 0;
              local_338 = (void *)((uint)local_338 & 0xffffff00);
              FUN_00401f60(local_33c,(undefined4 *)&DAT_005816e4,4);
              local_4._0_1_ = 10;
              piVar9 = FUN_00404ab0(local_28,local_33c);
              uVar7 = FUN_004013c0(piVar9,0,piVar9[5],(byte *)"background",10);
              local_4._0_1_ = 4;
              if (0xf < local_324) {
                _free(local_338);
              }
              local_324 = 0xf;
              local_328 = 0;
              local_338 = (void *)((uint)local_338 & 0xffffff00);
              if (uVar7 == 0) {
                FUN_004022f0(local_1ec,"img");
                local_4._0_1_ = 0xb;
                piVar9 = FUN_00404ab0(local_28,local_1ec);
                iVar4 = piVar9[5];
                local_4._0_1_ = 4;
                if (0xf < local_1d4) {
                  _free(local_1e8);
                }
                local_1d4 = 0xf;
                local_1d8 = 0;
                local_1e8 = (void *)((uint)local_1e8 & 0xffffff00);
                if (iVar4 != 0) {
                  FUN_004022f0(local_9c,"img");
                  local_4._0_1_ = 0xc;
                  piVar9 = FUN_00404ab0(local_28,local_9c);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  iVar4 = FUN_00433e00((char *)piVar9);
                  uVar8 = FUN_00427410(iVar4);
                  *(undefined4 *)((int)this + 0x2d4) = uVar8;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_9c);
                  FUN_004022f0(local_17c,"x");
                  local_4._0_1_ = 0xd;
                  piVar9 = FUN_00404ab0(local_28,local_17c);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)((int)this + 0x2dc) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_17c);
                  FUN_004022f0(local_1b4,"y");
                  local_4._0_1_ = 0xe;
                  piVar9 = FUN_00404ab0(local_28,local_1b4);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)((int)this + 0x2e0) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_1b4);
                }
              }
              local_308 = 0xf;
              local_30c = 0;
              local_31c = (void *)((uint)local_31c & 0xffffff00);
              FUN_00401f60(local_320,(undefined4 *)&DAT_005816e4,4);
              local_4._0_1_ = 0xf;
              piVar9 = FUN_00404ab0(local_28,local_320);
              uVar7 = FUN_004013c0(piVar9,0,piVar9[5],&DAT_0058791c,4);
              local_4._0_1_ = 4;
              if (0xf < local_308) {
                _free(local_31c);
              }
              local_308 = 0xf;
              local_30c = 0;
              local_31c = (void *)((uint)local_31c & 0xffffff00);
              if (uVar7 == 0) {
                FUN_004022f0(local_1d0,"img");
                local_4._0_1_ = 0x10;
                piVar9 = FUN_00404ab0(local_28,local_1d0);
                iVar4 = piVar9[5];
                local_4._0_1_ = 4;
                if (0xf < local_1b8) {
                  _free(local_1cc);
                }
                local_1b8 = 0xf;
                local_1bc = 0;
                local_1cc = (void *)((uint)local_1cc & 0xffffff00);
                if (iVar4 != 0) {
                  FUN_004022f0(local_144,"img");
                  local_4._0_1_ = 0x11;
                  piVar9 = FUN_00404ab0(local_28,local_144);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  iVar4 = FUN_00433e00((char *)piVar9);
                  uVar8 = FUN_00427410(iVar4);
                  *(undefined4 *)((int)this + 0x2fc) = uVar8;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_144);
                  FUN_004022f0(local_d4,"wc");
                  local_4._0_1_ = 0x12;
                  piVar9 = FUN_00404ab0(local_28,local_d4);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)(*(int *)((int)this + 0x2fc) + 0x10) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_d4);
                  FUN_004022f0(local_10c,"hc");
                  local_4._0_1_ = 0x13;
                  piVar9 = FUN_00404ab0(local_28,local_10c);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)(*(int *)((int)this + 0x2fc) + 0xc) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_10c);
                }
              }
              local_2d0 = 0xf;
              local_2d4 = 0;
              local_2e4 = (void *)((uint)local_2e4 & 0xffffff00);
              FUN_00401f60(local_2e8,(undefined4 *)&DAT_005816e4,4);
              local_4._0_1_ = 0x14;
              piVar9 = FUN_00404ab0(local_28,local_2e8);
              uVar7 = FUN_004013c0(piVar9,0,piVar9[5],(byte *)"background_upgr",0xf);
              local_4._0_1_ = 4;
              if (0xf < local_2d0) {
                _free(local_2e4);
              }
              local_2d0 = 0xf;
              local_2d4 = 0;
              local_2e4 = (void *)((uint)local_2e4 & 0xffffff00);
              if (uVar7 == 0) {
                FUN_004022f0(local_25c,"img");
                local_4._0_1_ = 0x15;
                piVar9 = FUN_00404ab0(local_28,local_25c);
                iVar4 = piVar9[5];
                local_4._0_1_ = 4;
                if (0xf < local_244) {
                  _free(local_258);
                }
                local_244 = 0xf;
                local_248 = 0;
                local_258 = (void *)((uint)local_258 & 0xffffff00);
                if (iVar4 != 0) {
                  FUN_004022f0(local_198,"img");
                  local_4._0_1_ = 0x16;
                  piVar9 = FUN_00404ab0(local_28,local_198);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  iVar4 = FUN_00433e00((char *)piVar9);
                  uVar8 = FUN_00427410(iVar4);
                  *(undefined4 *)((int)this + 0x2d8) = uVar8;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_198);
                  FUN_004022f0(local_160,"x");
                  local_4._0_1_ = 0x17;
                  piVar9 = FUN_00404ab0(local_28,local_160);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)((int)this + 0x2e4) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_160);
                  FUN_004022f0(local_128,"y");
                  local_4._0_1_ = 0x18;
                  piVar9 = FUN_00404ab0(local_28,local_128);
                  if ((uint)piVar9[6] < 0x10) {
                    piVar9 = piVar9 + 1;
                  }
                  else {
                    piVar9 = (int *)piVar9[1];
                  }
                  lVar10 = _atol((char *)piVar9);
                  *(long *)((int)this + 0x2e8) = lVar10;
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_128);
                }
              }
            }
            else {
              uVar7 = FUN_004013c0(local_60,0,local_4c,(byte *)"Window",6);
              if (uVar7 == 0) {
                FUN_004022f0(local_294,"guid");
                pcVar13 = "description";
                local_4._0_1_ = 0x19;
                piVar9 = FUN_00404ab0(local_28,local_294);
                bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                local_4 = CONCAT31(local_4._1_3_,4);
                if (0xf < local_27c) {
                  _free(local_290);
                }
                local_27c = 0xf;
                local_280 = 0;
                local_290 = (void *)((uint)local_290 & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,0,(int)&local_80);
                }
                FUN_004022f0(local_224,"guid");
                pbVar14 = &DAT_005815ec;
                local_4._0_1_ = 0x1a;
                piVar9 = FUN_00404ab0(local_28,local_224);
                bVar3 = FUN_00401b90(piVar9,pbVar14);
                local_4 = CONCAT31(local_4._1_3_,4);
                if (0xf < local_20c) {
                  _free(local_220);
                }
                local_20c = 0xf;
                local_210 = 0;
                local_220 = (void *)((uint)local_220 & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,1,(int)&local_80);
                }
                FUN_004022f0(local_278,"guid");
                pcVar13 = "price";
                local_4._0_1_ = 0x1b;
                piVar9 = FUN_00404ab0(local_28,local_278);
                bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                local_4 = CONCAT31(local_4._1_3_,4);
                if (0xf < local_260) {
                  _free(local_274);
                }
                local_260 = 0xf;
                local_264 = 0;
                local_274 = (void *)((uint)local_274 & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,2,(int)&local_80);
                }
                FUN_004022f0(local_240,"guid");
                pcVar13 = "lives";
                local_4._0_1_ = 0x1c;
                piVar9 = FUN_00404ab0(local_28,local_240);
                bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                local_4 = CONCAT31(local_4._1_3_,4);
                if (0xf < local_228) {
                  _free(local_23c);
                }
                local_228 = 0xf;
                local_22c = 0;
                local_23c = (void *)((uint)local_23c & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,3,(int)&local_80);
                }
                FUN_004022f0(local_208,"guid");
                pcVar13 = "count";
                local_4._0_1_ = 0x1d;
                piVar9 = FUN_00404ab0(local_28,local_208);
                bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                local_4 = CONCAT31(local_4._1_3_,4);
                if (0xf < local_1f0) {
                  _free(local_204);
                }
                local_1f0 = 0xf;
                local_1f4 = 0;
                local_204 = (void *)((uint)local_204 & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,4,(int)&local_80);
                }
                FUN_004022f0(local_374,"guid");
                pcVar13 = "money";
                local_4._0_1_ = 0x1e;
                piVar9 = FUN_00404ab0(local_28,local_374);
                bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                local_4._0_1_ = 4;
                if (0xf < local_35c) {
                  _free(local_370);
                }
                local_35c = 0xf;
                local_360 = 0;
                local_370 = (void *)((uint)local_370 & 0xffffff00);
                if (bVar3) {
                  FUN_0046f090(this,5,(int)&local_80);
                }
              }
              else {
                uVar7 = FUN_004013c0(local_60,0,local_4c,(byte *)"Button",6);
                if (uVar7 == 0) {
                  FUN_004022f0(local_f0,"guid");
                  pcVar13 = "finish";
                  local_4._0_1_ = 0x1f;
                  piVar9 = FUN_00404ab0(local_28,local_f0);
                  bVar3 = FUN_00401b90(piVar9,(byte *)pcVar13);
                  local_4 = CONCAT31(local_4._1_3_,4);
                  FUN_0049fbf0((int)local_f0);
                  if (bVar3) {
                    FUN_0046f370(this,0);
                  }
                  FUN_004022f0(local_b8,"guid");
                  pbVar14 = &DAT_005878f0;
                  local_4._0_1_ = 0x20;
                  piVar9 = FUN_00404ab0(local_28,local_b8);
                  bVar3 = FUN_00401b90(piVar9,pbVar14);
                  local_4._0_1_ = 4;
                  FUN_0049fbf0((int)local_b8);
                  if (bVar3) {
                    FUN_0046f370(this,1);
                  }
                }
              }
            }
          }
        }
      }
      uVar8 = FUN_004c7ea0(local_39c,&local_80);
      cVar2 = (char)uVar8;
    }
    local_4 = 0xffffffff;
    uVar8 = FUN_004057a0((int)&local_80);
    iVar4 = CONCAT31((int3)((uint)uVar8 >> 8),1);
  }
  ExceptionList = pvStack_c;
  return iVar4;
}

