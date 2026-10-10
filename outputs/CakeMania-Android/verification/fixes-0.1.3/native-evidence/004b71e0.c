/* Address: 004b71e0; name: FUN_004b71e0 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint __thiscall FUN_004b71e0(void *this,uint param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  undefined1 *puVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  uint uVar15;
  void *pvVar16;
  char *******pppppppcVar17;
  char *pcVar18;
  byte *pbVar19;
  uint extraout_EAX;
  uint extraout_EAX_00;
  ulonglong uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  int in_stack_fffedd8c;
  char *in_stack_fffedd90;
  void *in_stack_fffedd94;
  char *pcVar23;
  undefined1 auStack_12248 [73852];
  uint local_1cc;
  undefined1 local_1c8 [12];
  undefined1 local_1bc [4];
  undefined4 *local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  undefined1 local_1ac [4];
  undefined1 local_1a8 [12];
  undefined1 local_19c [4];
  int *local_198;
  int local_194;
  undefined4 local_190;
  undefined4 *local_18c;
  int *local_188;
  undefined4 local_184;
  undefined4 *local_180;
  char local_179;
  int *local_178;
  int *local_174;
  char local_170 [256];
  undefined1 local_70 [4];
  undefined1 local_6c [12];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  void *local_48 [2];
  undefined1 local_40 [4];
  int local_3c;
  undefined4 local_38;
  uint local_34;
  undefined1 local_30 [4];
  char ******local_2c [4];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  uVar10 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0057db0a;
  local_10 = ExceptionList;
  local_14 = DAT_005b83e8;
  local_18 = 0xf;
  local_1c = 0;
  local_2c[0] = (char ******)((uint)local_2c[0] & 0xffffff00);
  ExceptionList = &local_10;
  local_18c = this;
  FUN_00401e70(local_30,(void *)(**(int **)(param_1 + 0xc) + 8),0,0xffffffff);
  local_8 = 0;
  param_1 = param_1 & 0xffffff;
  local_179 = '\0';
  pppppppcVar17 = (char *******)local_2c[0];
  if (local_18 < 0x10) {
    pppppppcVar17 = local_2c;
  }
  iVar5 = __stricmp((char *)pppppppcVar17,"Define");
  if (iVar5 == 0) {
    iVar5 = *(int *)(uVar10 + 0xc);
    if ((iVar5 == 0) || (*(int *)(uVar10 + 0x10) - iVar5 >> 2 != 3)) goto LAB_004b92e6;
    if (*(char *)(*(int *)(iVar5 + 4) + 4) != '\0') goto LAB_004b7ab4;
    FUN_004bd740(local_4c,*(int *)(iVar5 + 4) + 8);
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar6 = FUN_004bb9c0((int)local_4c);
    if ((char)uVar6 == '\0') {
      pvVar16 = (void *)((int)this + 0x44);
      FUN_004a0ee0(pvVar16,&local_188,local_4c);
      if (local_188 != *(int **)((int)this + 0x48)) {
        if ((undefined4 *)local_188[10] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)local_188[10])();
        }
        FUN_004a83b0(&local_180,local_188);
      }
      if (*(char *)(*(int *)(*(int *)(uVar10 + 0xc) + 8) + 4) == '\0') {
        piVar7 = *(int **)(*(int *)(uVar10 + 0xc) + 8);
        piVar9 = (int *)(**(code **)(*(int *)this + 4))();
        if (piVar9 == (int *)0x0) {
          local_178 = (int *)(**(code **)(*piVar7 + 4))();
          puVar8 = FUN_004a0f70(local_70,local_4c,&local_178);
          local_8 = CONCAT31(local_8._1_3_,5);
          FUN_004ac380(pvVar16,&local_184,puVar8);
          FUN_0049fbf0((int)local_70);
        }
        else {
          local_178 = (int *)(**(code **)(*piVar9 + 4))();
          puVar8 = FUN_004a0f70(local_70,local_4c,&local_178);
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_004ac380(pvVar16,&local_184,puVar8);
          FUN_0049fbf0((int)local_70);
        }
        goto LAB_004b7430;
      }
      local_180 = operator_new(0x18);
      local_8._0_1_ = 2;
      if (local_180 == (undefined4 *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = (int *)FUN_004ab450(local_180);
      }
      local_8._0_1_ = 1;
      uVar6 = FUN_004c6bb0(local_18c,*(int *)(*(int *)(uVar10 + 0xc) + 8),(int)piVar7);
      if ((char)uVar6 != '\0') {
        local_178 = piVar7;
        puVar8 = FUN_004a0f70(local_70,local_4c,&local_178);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004ac380(pvVar16,&local_184,puVar8);
        FUN_0049fbf0((int)local_70);
        goto LAB_004b7430;
      }
      if (piVar7 != (int *)0x0) {
        (**(code **)*piVar7)();
      }
    }
    else {
      param_1 = 0x1000000;
LAB_004b7430:
      local_8 = local_8 & 0xffffff00;
      if (0xf < local_34) {
        _free(local_48[0]);
      }
LAB_004b7aa3:
      this = local_18c;
      if (param_1._3_1_ == '\0') {
        if (local_179 == '\0') {
LAB_004b7920:
          uVar6 = FUN_0049fbf0((int)local_30);
          ExceptionList = local_10;
          return CONCAT31((int3)((uint)uVar6 >> 8),1);
        }
        FUN_004022f0(local_4c,"List Size Mismatch");
        puVar8 = (undefined4 *)*local_18c;
        local_8._0_1_ = 0x3a;
LAB_004b936a:
        (*(code *)*puVar8)();
      }
      else {
LAB_004b7ab4:
        FUN_004022f0(local_4c,"Invalid Paramater Type");
        local_8._0_1_ = 0x38;
        (*(code *)**(undefined4 **)this)();
      }
    }
LAB_004b9373:
    FUN_0049fbf0((int)local_4c);
LAB_004b9378:
    local_34 = FUN_0049fbf0((int)local_30);
  }
  else {
    pppppppcVar17 = (char *******)local_2c[0];
    if (local_18 < 0x10) {
      pppppppcVar17 = local_2c;
    }
    iVar5 = __stricmp((char *)pppppppcVar17,"CreateHorzSpanRectList");
    if (iVar5 == 0) {
      iVar5 = *(int *)(uVar10 + 0xc);
      if ((iVar5 != 0) && (*(int *)(uVar10 + 0x10) - iVar5 >> 2 == 4)) {
        local_198 = (int *)0x0;
        local_194 = 0;
        local_190 = 0;
        local_1b8 = (void *)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8._0_1_ = 7;
        if ((*(char *)(*(int *)(iVar5 + 4) + 4) == '\0') &&
           ((((uVar6 = FUN_004c9ee0(this,*(void **)(iVar5 + 8),local_19c), (char)uVar6 != '\0' &&
              (local_198 != (int *)0x0)) && (local_194 - (int)local_198 >> 2 == 4)) &&
            (uVar6 = FUN_004c9ee0(this,*(void **)(*(int *)(uVar10 + 0xc) + 0xc),local_1bc),
            (char)uVar6 != '\0')))) {
          FUN_004bd740(local_4c,*(int *)(*(int *)(uVar10 + 0xc) + 4) + 8);
          local_8._0_1_ = 8;
          local_180 = operator_new(0x18);
          local_8._0_1_ = 9;
          if (local_180 == (undefined4 *)0x0) {
            local_178 = (int *)0x0;
          }
          else {
            local_178 = (int *)FUN_004ab450(local_180);
          }
          local_8._0_1_ = 8;
          for (local_188 = (int *)0x0;
              (puVar8 = local_18c, local_1b8 != (void *)0x0 &&
              (local_188 < (int *)(local_1b4 - (int)local_1b8 >> 2)));
              local_188 = (int *)((int)local_188 + 1)) {
            local_180 = operator_new(0x18);
            local_8._0_1_ = 10;
            if (local_180 == (undefined4 *)0x0) {
              piVar7 = (int *)0x0;
            }
            else {
              piVar7 = (int *)FUN_004ab450(local_180);
            }
            local_8._0_1_ = 8;
            local_174 = piVar7;
            FUN_004ac330(local_178 + 2,&local_174);
            _sprintf(local_170,"%d");
            puVar8 = operator_new(0x24);
            local_8._0_1_ = 0xb;
            local_180 = puVar8;
            if (puVar8 == (undefined4 *)0x0) {
              local_174 = (int *)0x0;
            }
            else {
              local_174 = (int *)&stack0xfffedd90;
              FUN_004022f0(&stack0xfffedd90,local_170);
              local_174 = FUN_004a1ae0(puVar8,in_stack_fffedd90,in_stack_fffedd94);
            }
            piVar7 = piVar7 + 2;
            local_8._0_1_ = 8;
            FUN_004ac330(piVar7,&local_174);
            _sprintf(local_170,"%d");
            puVar8 = operator_new(0x24);
            local_8._0_1_ = 0xc;
            local_180 = puVar8;
            if (puVar8 == (undefined4 *)0x0) {
              local_174 = (int *)0x0;
            }
            else {
              local_174 = (int *)&stack0xfffedd90;
              FUN_004022f0(&stack0xfffedd90,local_170);
              local_174 = FUN_004a1ae0(puVar8,in_stack_fffedd90,in_stack_fffedd94);
            }
            local_8._0_1_ = 8;
            FUN_004ac330(piVar7,&local_174);
            _sprintf(local_170,"%d");
            puVar8 = operator_new(0x24);
            local_8._0_1_ = 0xd;
            local_180 = puVar8;
            if (puVar8 == (undefined4 *)0x0) {
              local_174 = (int *)0x0;
            }
            else {
              local_174 = (int *)&stack0xfffedd90;
              FUN_004022f0(&stack0xfffedd90,local_170);
              local_174 = FUN_004a1ae0(puVar8,in_stack_fffedd90,in_stack_fffedd94);
            }
            local_8._0_1_ = 8;
            FUN_004ac330(piVar7,&local_174);
            _sprintf(local_170,"%d");
            puVar8 = operator_new(0x24);
            local_8._0_1_ = 0xe;
            local_180 = puVar8;
            if (puVar8 == (undefined4 *)0x0) {
              local_174 = (int *)0x0;
            }
            else {
              local_174 = (int *)&stack0xfffedd90;
              FUN_004022f0(&stack0xfffedd90,local_170);
              local_174 = FUN_004a1ae0(puVar8,in_stack_fffedd90,in_stack_fffedd94);
            }
            local_8._0_1_ = 8;
            FUN_004ac330(piVar7,&local_174);
          }
          puVar14 = local_18c + 0x11;
          FUN_004a0ee0(puVar14,&local_174,local_4c);
          piVar7 = local_174;
          if (local_174 != (int *)puVar8[0x12]) {
            if ((undefined4 *)local_174[10] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)local_174[10])();
            }
            FUN_004a83b0(&local_180,piVar7);
          }
          local_174 = local_178;
          puVar8 = FUN_004a0f70(local_70,local_4c,&local_174);
          local_8._0_1_ = 0xf;
          FUN_004ac380(puVar14,&local_184,puVar8);
          FUN_0049fbf0((int)local_70);
          FUN_0049fbf0((int)local_4c);
        }
        else {
          param_1 = 0x1000000;
        }
        if (local_1b8 != (void *)0x0) {
          _free(local_1b8);
        }
        local_1b8 = (undefined4 *)0x0;
        local_1b4 = 0;
        local_1b0 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_198 != (int *)0x0) {
          _free(local_198);
        }
        goto LAB_004b7aa3;
      }
    }
    else {
      pppppppcVar17 = (char *******)local_2c[0];
      if (local_18 < 0x10) {
        pppppppcVar17 = local_2c;
      }
      iVar5 = __stricmp((char *)pppppppcVar17,"SetDefaultPointSize");
      if (iVar5 == 0) {
        iVar5 = *(int *)(uVar10 + 0xc);
        if ((iVar5 != 0) && (*(int *)(uVar10 + 0x10) - iVar5 >> 2 == 2)) {
          if (*(char *)(*(int *)(iVar5 + 4) + 4) == '\0') {
            local_180 = (undefined4 *)&stack0xfffedd8c;
            FUN_00402070(&stack0xfffedd8c,(void *)(*(int *)(iVar5 + 4) + 8));
            uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
            if ((char)uVar10 != '\0') {
              *(uint *)((int)this + 0x5c) = param_1;
              goto LAB_004b7920;
            }
          }
          goto LAB_004b7ab4;
        }
      }
      else {
        pppppppcVar17 = (char *******)local_2c[0];
        if (local_18 < 0x10) {
          pppppppcVar17 = local_2c;
        }
        iVar5 = __stricmp((char *)pppppppcVar17,"SetCharMap");
        if (iVar5 != 0) {
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"CreateLayer");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 != 2) goto LAB_004b92e6;
            iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 4);
            if (*(char *)(iVar5 + 4) == '\0') {
              FUN_004bd740(local_6c,iVar5 + 8);
              puVar8 = local_18c;
              local_8._0_1_ = 0x12;
              puVar14 = FUN_004ab490(auStack_12248,local_18c);
              local_8._0_1_ = 0x13;
              FUN_004b71a0(puVar8 + 0x5b,puVar14);
              local_8._0_1_ = 0x12;
              FUN_004aa7f0((int)auStack_12248);
              local_174 = (int *)(*(int *)(puVar8[0x5c] + 4) + 8);
              puVar14 = FUN_004a0f70(local_50,local_6c,&local_174);
              local_8._0_1_ = 0x14;
              iVar5 = FUN_004ac380(puVar8 + 0x5e,&local_184,puVar14);
              cVar1 = *(char *)(iVar5 + 4);
              local_8._0_1_ = 0x12;
              FUN_0049fbf0((int)local_50);
              if (cVar1 != '\0') goto LAB_004b7cf3;
              FUN_004022f0(local_4c,"Layer Already Exists");
              local_8._0_1_ = 0x15;
LAB_004b7cdd:
              (**(code **)*local_18c)();
              FUN_0049fbf0((int)local_4c);
LAB_004b7cf3:
              FUN_0049fbf0((int)local_6c);
              uVar6 = FUN_0049fbf0((int)local_30);
              ExceptionList = local_10;
              return CONCAT31((int3)((uint)uVar6 >> 8),1);
            }
            goto LAB_004b7ab4;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"CreateLayerFrom");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              if ((*(char *)(*(int *)(*(int *)(uVar10 + 0xc) + 4) + 4) == '\0') &&
                 (uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 8),&local_174),
                 (char)uVar15 != '\0')) {
                FUN_004bd740(local_6c,*(int *)(*(int *)(uVar10 + 0xc) + 4) + 8);
                local_8._0_1_ = 0x16;
                puVar14 = FUN_004ad880(auStack_12248,local_174);
                puVar8 = local_18c;
                local_8._0_1_ = 0x17;
                FUN_004b71a0(local_18c + 0x5b,puVar14);
                local_8._0_1_ = 0x16;
                FUN_004aa7f0((int)auStack_12248);
                local_174 = (int *)(*(int *)(puVar8[0x5c] + 4) + 8);
                puVar14 = FUN_004a0f70(local_50,local_6c,&local_174);
                local_8._0_1_ = 0x18;
                iVar5 = FUN_004ac380(puVar8 + 0x5e,&local_184,puVar14);
                cVar1 = *(char *)(iVar5 + 4);
                local_8._0_1_ = 0x16;
                FUN_0049fbf0((int)local_50);
                if (cVar1 != '\0') goto LAB_004b7cf3;
                FUN_004022f0(local_4c,"Layer Already Exists");
                local_8._0_1_ = 0x19;
                goto LAB_004b7cdd;
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerRequireTags");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_198 = (int *)0x0;
              local_194 = 0;
              local_190 = 0;
              local_8 = CONCAT31(local_8._1_3_,0x1a);
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 == '\0') ||
                 (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                 (char)uVar6 == '\0')) {
LAB_004b7ed7:
                param_1 = 0x1000000;
              }
              else {
                uVar10 = 0;
                iVar5 = FUN_0041f870((int)local_19c);
                if (iVar5 != 0) {
                  piVar7 = local_174 + 1;
                  iVar5 = 0;
                  do {
                    pvVar16 = FUN_004bd740(local_4c,iVar5 + (int)local_198);
                    local_8._0_1_ = 0x1b;
                    FUN_00421ac0(piVar7,pvVar16);
                    local_8 = CONCAT31(local_8._1_3_,0x1a);
                    FUN_0049fbf0((int)local_4c);
                    uVar10 = uVar10 + 1;
                    iVar5 = iVar5 + 0x1c;
                    uVar15 = FUN_0041f870((int)local_19c);
                  } while (uVar10 < uVar15);
                }
              }
              goto LAB_004b7a94;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerExcludeTags");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_198 = (int *)0x0;
              local_194 = 0;
              local_190 = 0;
              local_8 = CONCAT31(local_8._1_3_,0x1c);
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 == '\0') ||
                 (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                 (char)uVar6 == '\0')) goto LAB_004b7ed7;
              uVar10 = 0;
              iVar5 = FUN_0041f870((int)local_19c);
              if (iVar5 != 0) {
                piVar7 = local_174 + 5;
                iVar5 = 0;
                do {
                  pvVar16 = FUN_004bd740(local_4c,iVar5 + (int)local_198);
                  local_8._0_1_ = 0x1d;
                  FUN_00421ac0(piVar7,pvVar16);
                  local_8 = CONCAT31(local_8._1_3_,0x1c);
                  FUN_0049fbf0((int)local_4c);
                  uVar10 = uVar10 + 1;
                  iVar5 = iVar5 + 0x1c;
                  uVar15 = FUN_0041f870((int)local_19c);
                } while (uVar10 < uVar15);
              }
              goto LAB_004b7a94;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerPointRange");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 4) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if ((((char)uVar15 != '\0') &&
                  (iVar5 = *(int *)(uVar10 + 0xc), *(char *)(*(int *)(iVar5 + 8) + 4) == '\0')) &&
                 (*(char *)(*(int *)(iVar5 + 0xc) + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(*(int *)(iVar5 + 8) + 8));
                uVar15 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar15 != '\0') {
                  local_180 = (undefined4 *)&stack0xfffedd8c;
                  FUN_00402070(&stack0xfffedd8c,(void *)(*(int *)(*(int *)(uVar10 + 0xc) + 0xc) + 8)
                              );
                  uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                  if ((char)uVar10 != '\0') {
                    local_174[0x4816] = param_1;
                    local_174[0x4817] = (int)local_178;
                    uVar6 = FUN_0049fbf0((int)local_30);
                    ExceptionList = local_10;
                    return CONCAT31((int3)((uint)uVar6 >> 8),1);
                  }
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetPointSize");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar10 != '\0') {
                  local_174[0x4818] = param_1;
                  uVar6 = FUN_0049fbf0((int)local_30);
                  ExceptionList = local_10;
                  return CONCAT31((int3)((uint)uVar6 >> 8),1);
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetImage");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_34 = 0xf;
              local_38 = 0;
              local_48[0] = (void *)((uint)local_48[0] & 0xffffff00);
              local_8._0_1_ = 0x1e;
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_178);
              if (((char)uVar15 == '\0') ||
                 (uVar6 = FUN_004c23f0(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_4c),
                 puVar8 = local_18c, (char)uVar6 == '\0')) {
                param_1 = 0x1000000;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0049fbf0((int)local_4c);
              }
              else {
                pvVar16 = FUN_004c0ee0(local_1c8,local_18c + 0x61,'\0');
                local_8._0_1_ = 0x1f;
                FUN_004c0490(local_6c,local_4c,pvVar16);
                local_8._0_1_ = 0x21;
                FUN_0049fbf0((int)local_1c8);
                FUN_004a0ee0(puVar8 + 0x58,&local_174,local_6c);
                if (local_174 == (int *)puVar8[0x59]) {
                  piVar7 = (int *)(**(code **)(*(int *)puVar8[0x16] + 0xf0))();
                  if (piVar7 == (int *)0x0) {
                    FUN_004022f0(local_1a8,"Failed to Load Image");
                    local_8._0_1_ = 0x23;
                    (**(code **)*puVar8)();
                    FUN_0049fbf0((int)local_1a8);
                    FUN_0049fbf0((int)local_6c);
                    goto LAB_004b9373;
                  }
                  (**(code **)(*piVar7 + 0x80))();
                  local_178[0x4811] = (int)piVar7;
                  local_174 = piVar7;
                  puVar14 = FUN_004a0f70(local_1ac,local_6c,&local_174);
                  local_8._0_1_ = 0x22;
                  FUN_004ac380(puVar8 + 0x58,&local_184,puVar14);
                  FUN_0049fbf0((int)local_1ac);
                  FUN_0049fbf0((int)local_6c);
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0049fbf0((int)local_4c);
                }
                else {
                  local_178[0x4811] = local_174[10];
                  FUN_0049fbf0((int)local_6c);
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0049fbf0((int)local_4c);
                }
              }
              goto LAB_004b7aa3;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetDrawMode");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if (((char)uVar10 != '\0') && ((-1 < (int)param_1 && (param_1 < 2)))) {
                  local_174[0x4812] = param_1;
                  uVar6 = FUN_0049fbf0((int)local_30);
                  ExceptionList = local_10;
                  return CONCAT31((int3)((uint)uVar6 >> 8),1);
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetColorMult");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 != 3) goto LAB_004b92e6;
            local_198 = (int *)0x0;
            local_194 = 0;
            local_190 = 0;
            local_8._0_1_ = 0x24;
            uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
            if (((((char)uVar15 == '\0') ||
                 (uVar6 = FUN_004ca0a0(this,*(void **)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                 (char)uVar6 == '\0')) || (local_198 == (int *)0x0)) ||
               (local_194 - (int)local_198 >> 3 != 4)) {
LAB_004b853c:
              param_1 = 0x1000000;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fb40((int)local_19c);
            }
            else {
              uVar20 = FUN_00560568();
              uVar21 = FUN_00560568();
              uVar22 = FUN_00560568();
              local_178 = (int *)uVar22;
              uVar22 = FUN_00560568();
              local_174[0x4809] = (int)uVar22;
              local_174[0x480a] = (int)local_178;
              local_174[0x480b] = (int)uVar21;
              local_174[0x480c] = (int)uVar20;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fb40((int)local_19c);
            }
            goto LAB_004b7aa3;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetColorAdd");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_198 = (int *)0x0;
              local_194 = 0;
              local_190 = 0;
              local_8._0_1_ = 0x25;
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if ((((char)uVar15 == '\0') ||
                  (uVar6 = FUN_004ca0a0(this,*(void **)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                  (char)uVar6 == '\0')) ||
                 ((local_198 == (int *)0x0 || (local_194 - (int)local_198 >> 3 != 4))))
              goto LAB_004b853c;
              uVar20 = FUN_00560568();
              uVar21 = FUN_00560568();
              uVar22 = FUN_00560568();
              local_178 = (int *)uVar22;
              uVar22 = FUN_00560568();
              local_174[0x480d] = (int)uVar22;
              local_174[0x480e] = (int)local_178;
              local_174[0x480f] = (int)uVar21;
              local_174[0x4810] = (int)uVar20;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fb40((int)local_19c);
              goto LAB_004b7aa3;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetAscent");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar10 != '\0') {
                  local_174[0x4819] = param_1;
                  uVar6 = FUN_0049fbf0((int)local_30);
                  ExceptionList = local_10;
                  return CONCAT31((int3)((uint)uVar6 >> 8),1);
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetAscentPadding");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar10 != '\0') {
                  local_174[0x481a] = param_1;
                  uVar6 = FUN_0049fbf0((int)local_30);
                  ExceptionList = local_10;
                  return CONCAT31((int3)((uint)uVar6 >> 8),1);
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetLineSpacingOffset");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar10 != '\0') {
                  local_174[0x481d] = param_1;
                  uVar6 = FUN_0049fbf0((int)local_30);
                  ExceptionList = local_10;
                  return CONCAT31((int3)((uint)uVar6 >> 8),1);
                }
              }
              goto LAB_004b7ab4;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetOffset");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_198 = (int *)0x0;
              local_194 = 0;
              local_190 = 0;
              local_8._0_1_ = 0x26;
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((((char)uVar15 == '\0') ||
                   (uVar6 = FUN_004c9ee0(this,*(void **)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                   (char)uVar6 == '\0')) || (local_198 == (int *)0x0)) ||
                 (local_194 - (int)local_198 >> 2 != 2)) {
                param_1 = 0x1000000;
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0041fb40((int)local_19c);
              }
              else {
                local_174[0x4813] = *local_198;
                local_174[0x4814] = local_198[1];
                local_8 = (uint)local_8._1_3_ << 8;
                FUN_0041fb40((int)local_19c);
              }
              goto LAB_004b7aa3;
            }
            goto LAB_004b92e6;
          }
          pppppppcVar17 = (char *******)local_2c[0];
          if (local_18 < 0x10) {
            pppppppcVar17 = local_2c;
          }
          iVar5 = __stricmp((char *)pppppppcVar17,"LayerSetCharWidths");
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 4) {
              local_198 = (int *)0x0;
              local_194 = 0;
              local_190 = 0;
              local_1b8 = (undefined4 *)0x0;
              local_1b4 = 0;
              local_1b0 = 0;
              local_8 = CONCAT31(local_8._1_3_,0x28);
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if ((((char)uVar15 == '\0') ||
                  (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                  (char)uVar6 == '\0')) ||
                 (uVar6 = FUN_004c9ee0(this,*(void **)(*(int *)(uVar10 + 0xc) + 0xc),local_1bc),
                 (char)uVar6 == '\0')) goto LAB_004b92d2;
              iVar5 = FUN_004011f0((int)local_1bc);
              iVar11 = FUN_0041f870((int)local_19c);
              if (iVar11 != iVar5) goto LAB_004b8972;
              uVar10 = 0;
              iVar5 = FUN_0041f870((int)local_19c);
              if (iVar5 == 0) goto LAB_004b92d6;
              iVar5 = 0;
              do {
                if (*(int *)(iVar5 + 0x14 + (int)local_198) == 1) {
                  pbVar13 = (byte *)FUN_0049e760((void *)(iVar5 + (int)local_198),0);
                  local_174[(uint)*pbVar13 * 0x48 + 0x4f] = local_1b8[uVar10];
                }
                else {
                  param_1 = 0x1000000;
                }
                uVar10 = uVar10 + 1;
                iVar5 = iVar5 + 0x1c;
                uVar15 = FUN_0041f870((int)local_19c);
              } while (uVar10 < uVar15);
              FUN_0041fb40((int)local_1bc);
              goto LAB_004b7a94;
            }
            goto LAB_004b92e6;
          }
          pcVar23 = "LayerSetSpacing";
          pcVar18 = (char *)FUN_004016f0((int)local_30);
          iVar5 = __stricmp(pcVar18,pcVar23);
          if (iVar5 == 0) {
            iVar5 = FUN_004011f0(uVar10 + 8);
            if (iVar5 == 3) {
              local_5c = 0;
              local_58 = 0;
              local_54 = 0;
              local_8._0_1_ = 0x29;
              uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_174);
              if (((char)uVar15 != '\0') &&
                 (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                local_180 = (undefined4 *)&stack0xfffedd8c;
                FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                if ((char)uVar10 != '\0') {
                  local_174[0x4815] = (int)local_178;
                  local_8 = (uint)local_8._1_3_ << 8;
                  FUN_0041fb40((int)&local_60);
                  goto LAB_004b7aa3;
                }
              }
              param_1 = 0x1000000;
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0041fb40((int)&local_60);
              goto LAB_004b7aa3;
            }
            goto LAB_004b92e6;
          }
          pcVar23 = "LayerSetImageMap";
          pcVar18 = (char *)FUN_004016f0((int)local_30);
          iVar5 = __stricmp(pcVar18,pcVar23);
          if (iVar5 != 0) {
            pcVar23 = "LayerSetCharOffsets";
            pcVar18 = (char *)FUN_004016f0((int)local_30);
            iVar5 = __stricmp(pcVar18,pcVar23);
            if (iVar5 == 0) {
              iVar5 = FUN_004011f0(uVar10 + 8);
              if (iVar5 == 4) {
                local_198 = (int *)0x0;
                local_194 = 0;
                local_190 = 0;
                local_8._0_1_ = 0x2f;
                FUN_004ab450(local_48);
                local_8._0_1_ = 0x30;
                uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_180);
                if ((((char)uVar15 == '\0') ||
                    (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                    (char)uVar6 == '\0')) ||
                   (uVar6 = FUN_004c6f00(this,*(int *)(*(int *)(uVar10 + 0xc) + 0xc),local_48),
                   (char)uVar6 == '\0')) {
                  param_1 = 0x1000000;
LAB_004b8f75:
                  local_8 = CONCAT31(local_8._1_3_,0x2f);
                  FUN_004a0e40(local_48);
                }
                else {
                  iVar5 = FUN_0041f870((int)local_19c);
                  iVar11 = FUN_004011f0((int)local_40);
                  if (iVar5 == iVar11) {
                    local_178 = (int *)0x0;
                    iVar5 = FUN_0041f870((int)local_19c);
                    if (iVar5 == 0) goto LAB_004b8f75;
                    iVar5 = 0;
                    piVar7 = local_178;
                    do {
                      local_1b8 = (undefined4 *)0x0;
                      local_1b4 = 0;
                      local_1b0 = 0;
                      local_8._0_1_ = 0x31;
                      if (((*(int *)(iVar5 + 0x14 + (int)local_198) == 1) &&
                          (uVar6 = FUN_004c9ee0(local_18c,*(void **)(local_3c + (int)piVar7 * 4),
                                                local_1bc), (char)uVar6 != '\0')) &&
                         (iVar11 = FUN_004011f0((int)local_1bc), iVar11 == 2)) {
                        uVar6 = local_1b8[1];
                        uVar3 = *local_1b8;
                        pbVar13 = (byte *)FUN_0049e760((void *)(iVar5 + (int)local_198),0);
                        bVar2 = *pbVar13;
                        local_180[(uint)bVar2 * 0x48 + 0xd] = uVar3;
                        local_180[(uint)bVar2 * 0x48 + 0xe] = uVar6;
                        piVar7 = local_178;
                      }
                      else {
                        param_1 = 0x1000000;
                      }
                      FUN_0041fb40((int)local_1bc);
                      piVar7 = (int *)((int)piVar7 + 1);
                      iVar5 = iVar5 + 0x1c;
                      local_178 = piVar7;
                      piVar9 = (int *)FUN_0041f870((int)local_19c);
                    } while (piVar7 < piVar9);
                    local_8 = CONCAT31(local_8._1_3_,0x2f);
                    FUN_004a0e40(local_48);
                  }
                  else {
                    local_179 = '\x01';
                    local_8 = CONCAT31(local_8._1_3_,0x2f);
                    FUN_004a0e40(local_48);
                  }
                }
LAB_004b7a94:
                puVar12 = local_19c;
                goto LAB_004b7a9a;
              }
              goto LAB_004b92e6;
            }
            pcVar23 = "LayerSetKerningPairs";
            pcVar18 = (char *)FUN_004016f0((int)local_30);
            iVar5 = __stricmp(pcVar18,pcVar23);
            if (iVar5 == 0) {
              iVar5 = FUN_004011f0(uVar10 + 8);
              if (iVar5 == 4) {
                local_198 = (int *)0x0;
                local_194 = 0;
                local_190 = 0;
                local_1b8 = (undefined4 *)0x0;
                local_1b4 = 0;
                local_1b0 = 0;
                local_8 = CONCAT31(local_8._1_3_,0x33);
                uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_180);
                if ((((char)uVar15 == '\0') ||
                    (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                    (char)uVar6 == '\0')) ||
                   (uVar6 = FUN_004c9ee0(this,*(void **)(*(int *)(uVar10 + 0xc) + 0xc),local_1bc),
                   (char)uVar6 == '\0')) {
LAB_004b92d2:
                  param_1 = 0x1000000;
                }
                else {
                  iVar5 = FUN_004011f0((int)local_1bc);
                  iVar11 = FUN_0041f870((int)local_19c);
                  if (iVar11 != iVar5) {
LAB_004b8972:
                    local_179 = '\x01';
                    FUN_0041fb40((int)local_1bc);
                    goto LAB_004b7a94;
                  }
                  uVar10 = 0;
                  iVar5 = FUN_0041f870((int)local_19c);
                  if (iVar5 != 0) {
                    piVar7 = (int *)0x0;
                    local_178 = (int *)0x0;
                    do {
                      pvVar16 = (void *)((int)piVar7 + (int)local_198);
                      if (*(int *)((int)(piVar7 + 5) + (int)local_198) == 2) {
                        pbVar13 = (byte *)FUN_0049e760(pvVar16,0);
                        pbVar19 = (byte *)FUN_0049e760(pvVar16,1);
                        *(undefined1 *)((int)local_180 + *pbVar19 + 0x3c + (uint)*pbVar13 * 0x120) =
                             *(undefined1 *)(local_1b8 + uVar10);
                      }
                      else {
                        param_1 = 0x1000000;
                      }
                      piVar7 = local_178 + 7;
                      uVar10 = uVar10 + 1;
                      local_178 = piVar7;
                      uVar15 = FUN_0041f870((int)local_19c);
                    } while (uVar10 < uVar15);
                    FUN_0041fb40((int)local_1bc);
                    goto LAB_004b7a94;
                  }
                }
LAB_004b92d6:
                FUN_0041fb40((int)local_1bc);
                goto LAB_004b7a94;
              }
              goto LAB_004b92e6;
            }
            pcVar23 = "LayerSetBaseOrder";
            pcVar18 = (char *)FUN_004016f0((int)local_30);
            iVar5 = __stricmp(pcVar18,pcVar23);
            if (iVar5 == 0) {
              iVar5 = FUN_004011f0(uVar10 + 8);
              if (iVar5 == 3) {
                uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_180);
                if (((char)uVar15 != '\0') &&
                   (iVar5 = *(int *)(*(int *)(uVar10 + 0xc) + 8), *(char *)(iVar5 + 4) == '\0')) {
                  local_174 = (int *)&stack0xfffedd8c;
                  FUN_00402070(&stack0xfffedd8c,(void *)(iVar5 + 8));
                  uVar10 = FUN_004bc260(in_stack_fffedd8c,in_stack_fffedd90);
                  if ((char)uVar10 != '\0') {
                    local_180[0x481e] = param_1;
                    uVar6 = FUN_0049fbf0((int)local_30);
                    ExceptionList = local_10;
                    return CONCAT31((int3)((uint)uVar6 >> 8),1);
                  }
                }
                goto LAB_004b7ab4;
              }
              goto LAB_004b92e6;
            }
            pcVar23 = "LayerSetCharOrders";
            pcVar18 = (char *)FUN_004016f0((int)local_30);
            iVar5 = __stricmp(pcVar18,pcVar23);
            if (iVar5 == 0) {
              iVar5 = FUN_004011f0(uVar10 + 8);
              if (iVar5 == 4) {
                local_198 = (int *)0x0;
                local_194 = 0;
                local_190 = 0;
                local_1b8 = (undefined4 *)0x0;
                local_1b4 = 0;
                local_1b0 = 0;
                local_8 = CONCAT31(local_8._1_3_,0x35);
                uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_180);
                if ((((char)uVar15 != '\0') &&
                    (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_19c),
                    (char)uVar6 != '\0')) &&
                   (uVar6 = FUN_004c9ee0(this,*(void **)(*(int *)(uVar10 + 0xc) + 0xc),local_1bc),
                   (char)uVar6 != '\0')) {
                  iVar5 = FUN_004011f0((int)local_1bc);
                  iVar11 = FUN_0041f870((int)local_19c);
                  if (iVar11 == iVar5) {
                    uVar10 = 0;
                    iVar5 = FUN_0041f870((int)local_19c);
                    if (iVar5 == 0) goto LAB_004b92d6;
                    iVar5 = 0;
                    do {
                      if (*(int *)((int)local_198 + iVar5 + 0x14) == 1) {
                        pbVar13 = (byte *)FUN_0049e760((void *)((int)local_198 + iVar5),0);
                        local_180[(uint)*pbVar13 * 0x48 + 0x50] = local_1b8[uVar10];
                      }
                      else {
                        param_1 = 0x1000000;
                      }
                      uVar10 = uVar10 + 1;
                      iVar5 = iVar5 + 0x1c;
                      uVar15 = FUN_0041f870((int)local_19c);
                    } while (uVar10 < uVar15);
                    FUN_0041fb40((int)local_1bc);
                    goto LAB_004b7a94;
                  }
                  goto LAB_004b8972;
                }
                goto LAB_004b92d2;
              }
              goto LAB_004b92e6;
            }
            FUN_004022f0(local_4c,"Unknown Command");
            puVar8 = *(undefined4 **)this;
            local_8._0_1_ = 0x36;
            goto LAB_004b936a;
          }
          iVar5 = FUN_004011f0(uVar10 + 8);
          if (iVar5 != 4) goto LAB_004b92e6;
          local_1b8 = (undefined4 *)0x0;
          local_1b4 = 0;
          local_1b0 = 0;
          local_8._0_1_ = 0x2a;
          FUN_004ab450(local_48);
          local_8._0_1_ = 0x2b;
          uVar15 = FUN_004a7710(this,*(uint *)(*(int *)(uVar10 + 0xc) + 4),&local_178);
          if ((((char)uVar15 == '\0') ||
              (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_1bc),
              (char)uVar6 == '\0')) ||
             (uVar6 = FUN_004c6f00(this,*(int *)(*(int *)(uVar10 + 0xc) + 0xc),local_48),
             (char)uVar6 == '\0')) {
            param_1 = 0x1000000;
            local_8 = CONCAT31(local_8._1_3_,0x2a);
            FUN_004a0e40(local_48);
            puVar12 = local_1bc;
LAB_004b7a9a:
            local_8 = local_8 & 0xffffff00;
            FUN_0041b2d0((int)puVar12);
            goto LAB_004b7aa3;
          }
          iVar5 = FUN_0041f870((int)local_1bc);
          iVar11 = FUN_004011f0((int)local_40);
          if (iVar5 != iVar11) {
            local_179 = '\x01';
            local_8 = CONCAT31(local_8._1_3_,0x2a);
            FUN_004a0e40(local_48);
            puVar12 = local_1bc;
            goto LAB_004b7a9a;
          }
          iVar5 = local_178[0x4811];
          if (iVar5 != 0) {
            local_174 = *(int **)(iVar5 + 4);
            local_180 = *(undefined4 **)(iVar5 + 8);
            local_1cc = 0;
            iVar5 = FUN_0041f870((int)local_1bc);
            if (iVar5 != 0) {
              local_188 = (int *)0x0;
              do {
                local_198 = (int *)0x0;
                local_194 = 0;
                local_190 = 0;
                local_8._0_1_ = 0x2c;
                if (((*(int *)((int)(local_188 + 5) + (int)local_1b8) == 1) &&
                    (uVar6 = FUN_004c9ee0(this,*(void **)(local_3c + local_1cc * 4),local_19c),
                    (char)uVar6 != '\0')) && (iVar5 = FUN_004011f0((int)local_19c), iVar5 == 4)) {
                  CRect::CRect((CRect *)&local_60,*local_198,local_198[1],local_198[2],local_198[3])
                  ;
                  iVar4 = local_54;
                  iVar11 = local_5c;
                  iVar5 = local_60;
                  if ((((local_60 < 0) || (local_5c < 0)) || ((int)local_174 < local_58 + local_60))
                     || ((int)local_180 < local_54 + local_5c)) {
                    FUN_004022f0(local_6c,"Image rectangle out of bounds");
                    local_8._0_1_ = 0x2d;
                    (**(code **)*local_18c)();
                    FUN_0049fbf0((int)local_6c);
                    FUN_0041fb40((int)local_19c);
                    local_8._0_1_ = 0x2a;
                    FUN_004a0e40(local_48);
                    FUN_0041b2d0((int)local_1bc);
                    goto LAB_004b9378;
                  }
                  pbVar13 = (byte *)FUN_0049e760((void *)((int)local_188 + (int)local_1b8),0);
                  piVar7 = local_178 + (uint)*pbVar13 * 0x48 + 9;
                  *piVar7 = iVar5;
                  piVar7[1] = iVar11;
                  piVar7[2] = local_58;
                  piVar7[3] = iVar4;
                  this = local_18c;
                }
                else {
                  param_1 = 0x1000000;
                }
                FUN_0041fb40((int)local_19c);
                local_188 = local_188 + 7;
                local_1cc = local_1cc + 1;
                uVar10 = FUN_0041f870((int)local_1bc);
              } while (local_1cc < uVar10);
            }
            local_178[0x481c] = 0;
            piVar7 = local_178 + 0xc;
            iVar5 = 0x100;
            do {
              if (local_178[0x481c] < piVar7[2] + *piVar7) {
                local_178[0x481c] = piVar7[2] + *piVar7;
              }
              piVar7 = piVar7 + 0x48;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            local_8 = CONCAT31(local_8._1_3_,0x2a);
            FUN_004a0e40(local_48);
            puVar12 = local_1bc;
            goto LAB_004b7a9a;
          }
          FUN_004022f0(local_6c,"Layer image not set");
          local_8._0_1_ = 0x2e;
          (*(code *)**(undefined4 **)this)();
          FUN_0049fbf0((int)local_6c);
          local_8._0_1_ = 0x2a;
          FUN_004a0e40(local_48);
          FUN_0041b2d0((int)local_1bc);
          goto LAB_004b9378;
        }
        iVar5 = *(int *)(uVar10 + 0xc);
        if ((iVar5 != 0) && (*(int *)(uVar10 + 0x10) - iVar5 >> 2 == 3)) {
          local_198 = (int *)0x0;
          local_194 = 0;
          local_190 = 0;
          local_1b8 = (undefined4 *)0x0;
          local_1b4 = 0;
          local_1b0 = 0;
          local_8 = CONCAT31(local_8._1_3_,0x11);
          uVar6 = FUN_004c9c90(this,*(int *)(iVar5 + 4),local_19c);
          if (((char)uVar6 == '\0') ||
             (uVar6 = FUN_004c9c90(this,*(int *)(*(int *)(uVar10 + 0xc) + 8),local_1bc),
             (char)uVar6 == '\0')) {
            param_1 = 0x1000000;
          }
          else {
            iVar5 = FUN_0041f870((int)local_1bc);
            iVar11 = FUN_0041f870((int)local_19c);
            if (iVar11 == iVar5) {
              local_178 = (int *)0x0;
              iVar5 = FUN_0041f870((int)local_19c);
              if (iVar5 != 0) {
                iVar5 = 0;
                do {
                  pvVar16 = (void *)(iVar5 + (int)local_198);
                  if ((*(int *)(iVar5 + 0x14 + (int)local_198) == 1) &&
                     (*(int *)(iVar5 + (int)local_1b8 + 0x14) == 1)) {
                    puVar12 = (undefined1 *)FUN_0049e760((void *)(iVar5 + (int)local_1b8),0);
                    pbVar13 = (byte *)FUN_0049e760(pvVar16,0);
                    *(undefined1 *)(*pbVar13 + 0x60 + (int)local_18c) = *puVar12;
                  }
                  else {
                    param_1 = 0x1000000;
                  }
                  piVar9 = (int *)((int)local_178 + 1);
                  iVar5 = iVar5 + 0x1c;
                  local_178 = piVar9;
                  piVar7 = (int *)FUN_0041f870((int)local_19c);
                } while (piVar9 < piVar7);
              }
            }
            else {
              local_179 = '\x01';
            }
          }
          FUN_0041b2d0((int)local_1bc);
          goto LAB_004b7a94;
        }
      }
    }
LAB_004b92e6:
    FUN_004022f0(local_4c,"Invalid Number of Parameters");
    local_8 = CONCAT31(local_8._1_3_,0x37);
    (*(code *)**(undefined4 **)this)();
    if (0xf < local_34) {
      _free(local_48[0]);
      local_34 = extraout_EAX;
    }
    if (0xf < local_18) {
      _free(local_2c[0]);
      local_34 = extraout_EAX_00;
    }
  }
  ExceptionList = local_10;
  return local_34 & 0xffffff00;
}


