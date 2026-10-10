/* Native address 00463550; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00463550(void *this,int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined4 *extraout_EDX;
  int iVar9;
  int *piVar10;
  uint uVar11;
  double dStack_d0;
  int *piStack_c8;
  double dStack_c4;
  int iStack_bc;
  uint *puStack_b8;
  int aiStack_b4 [4];
  undefined1 auStack_a4 [20];
  int local_90;
  void *pvStack_8c;
  int iStack_88;
  uint uStack_78;
  int local_74;
  uint *puStack_70;
  uint *puStack_6c;
  undefined4 uStack_68;
  uint *puStack_60;
  uint *puStack_5c;
  undefined4 uStack_58;
  uint *puStack_50;
  uint *puStack_4c;
  int iStack_48;
  uint *puStack_40;
  uint *puStack_3c;
  int iStack_38;
  void *pvStack_30;
  undefined4 *puStack_2c;
  int iStack_28;
  int iStack_20;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0057aa03;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  FUN_00462250((int)&local_90);
  uVar11 = 0;
  local_4._0_1_ = 0;
  local_4._1_3_ = 0;
  local_74 = -1;
  iVar9 = 0;
  while( true ) {
    iVar5 = *(int *)((int)this + 0xe8);
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0xec) - iVar5 >> 7) <= uVar11))
    goto LAB_00463606;
    if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0xec) - iVar5 >> 7) <= uVar11)) break;
    if (param_1 == *(int *)(iVar9 + 0x1c + iVar5)) {
      if ((iVar5 == 0) || ((uint)(*(int *)((int)this + 0xec) - iVar5 >> 7) <= uVar11)) break;
      FUN_004632c0(&local_90,(undefined4 *)(iVar9 + iVar5));
    }
    uVar11 = uVar11 + 1;
    iVar9 = iVar9 + 0x80;
  }
  FUN_0045fb00();
LAB_00463606:
  if (-1 < local_74) {
    *(int *)((int)this + 0xdc) = local_74;
    FUN_004632c0((void *)((int)this + 0x25c),&local_90);
    dStack_c4 = (double)((ulonglong)dStack_c4 & 0xffffffff00000000);
    if (*(int *)((int)this + 0x268) != 0) {
      uVar2 = FUN_00493710(*(int *)((int)this + 0x268));
      dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,uVar2);
    }
    iStack_bc = *(int *)((int)this + 0xd4);
    if (*(int *)((int)this + 0x268) != 0) {
      iVar9 = FUN_00493700(*(int *)((int)this + 0x268));
      iStack_bc = iStack_bc + iVar9 / 2;
    }
    aiStack_b4[0] = 0;
    if (*(int *)((int)this + 0x26c) != 0) {
      aiStack_b4[0] = FUN_00493710(*(int *)((int)this + 0x26c));
      aiStack_b4[0] = aiStack_b4[0] / 2;
    }
    FUN_0045f850((int)this);
    puStack_b8 = (uint *)0x0;
    if (puStack_70 != (uint *)0x0) {
      do {
        piVar10 = (int *)0xffffffff;
        uVar11 = 0;
        puVar7 = puStack_3c;
        while( true ) {
          uVar6 = 0xffffffff;
          if ((puStack_3c == (uint *)0x0) || ((uint)(iStack_38 - (int)puStack_3c >> 5) <= uVar11))
          goto LAB_004636da;
          if ((uint *)*puVar7 == puStack_b8) break;
          uVar11 = uVar11 + 1;
          puVar7 = puVar7 + 8;
        }
        piVar10 = (int *)0x1;
        uVar6 = uVar11;
LAB_004636da:
        uVar11 = 0;
        puVar7 = puStack_4c;
        while( true ) {
          if ((puStack_4c == (uint *)0x0) ||
             ((uint)((iStack_48 - (int)puStack_4c) / 0x5c) <= uVar11)) goto LAB_00463722;
          if ((uint *)*puVar7 == puStack_b8) break;
          uVar11 = uVar11 + 1;
          puVar7 = puVar7 + 0x17;
        }
        piVar10 = (int *)0x0;
        uVar6 = uVar11;
LAB_00463722:
        uVar11 = 0;
        puVar8 = puStack_2c;
        while( true ) {
          if ((puStack_2c == (undefined4 *)0x0) ||
             ((uint)(iStack_28 - (int)puStack_2c >> 5) <= uVar11)) goto LAB_00463765;
          if ((uint *)*puVar8 == puStack_b8) break;
          uVar11 = uVar11 + 1;
          puVar8 = puVar8 + 8;
        }
        piVar10 = (int *)0x2;
        uVar6 = uVar11;
LAB_00463765:
        if (piVar10 == (int *)0x0) {
          if ((puStack_4c == (uint *)0x0) || ((uint)((iStack_48 - (int)puStack_4c) / 0x5c) <= uVar6)
             ) goto LAB_00463f63;
          piVar10 = (int *)(uVar6 * 0x5c);
          if ((char)(puStack_4c + 0x16)[uVar6 * 0x17] == '\0') {
            piStack_c8 = operator_new(0x130);
            local_4._0_1_ = 1;
            if (piStack_c8 == (int *)0x0) {
              piVar4 = (int *)0x0;
            }
            else {
              dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,(int)this + 0x80);
              if ((puStack_4c == (uint *)0x0) ||
                 ((uint)((iStack_48 - (int)puStack_4c) / 0x5c) <= uVar6)) goto LAB_00463f6f;
              piVar4 = FUN_004d8b60(piStack_c8,puStack_4c[uVar6 * 0x17],(int)this + 0x80);
            }
            local_4._0_1_ = 0;
            dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,piVar4);
            (**(code **)(*piVar4 + 0xe4))();
            iVar9 = *piVar4;
            FUN_0048c7b0(auStack_a4,0xf9,0xef,0x66);
            (**(code **)(iVar9 + 0x4c))();
            iVar9 = *piVar4;
            FUN_0048c7b0(&iStack_bc,0xff,0xfc,0xff);
            (**(code **)(iVar9 + 0x4c))(1);
            if ((puStack_4c == (uint *)0x0) ||
               ((uint)((iStack_48 - (int)puStack_4c) / 0x5c) <= uVar6)) goto LAB_00463f7b;
            FUN_00401e70(piVar4 + 0x21,puStack_4c + 1 + uVar6 * 0x17,0,0xffffffff);
            piVar4[0x2b] = (int)pvStack_8c;
            if (iStack_88 != 0) {
              piVar4[0x2d] = iStack_88;
            }
            piVar4[0x2c] = (int)pvStack_8c;
            piVar4[0x2a] = local_90;
            *(undefined1 *)(piVar4 + 0x1d) = 1;
            iVar9 = *piVar4;
            FUN_00493710(piVar4[0x2a]);
            FUN_00493700(piVar4[0x2a]);
            FUN_00493710(piVar4[0x2a]);
            FUN_00493700(piVar4[0x2a]);
            (**(code **)(iVar9 + 100))();
            FUN_004d8dc0(*(void **)(*(int *)((int)this + 0xe0) + 0x2e4),piVar4);
            iVar9 = *(int *)((int)this + 0x94);
            if ((iVar9 == 0) ||
               ((uint)(*(int *)((int)this + 0x9c) - iVar9 >> 2) <=
                (uint)(*(int *)((int)this + 0x98) - iVar9 >> 2))) {
              FUN_0041b000((void *)((int)this + 0x90),*(undefined4 **)((int)this + 0x98),1,
                           (undefined4 *)&dStack_d0);
            }
            else {
              puVar8 = *(undefined4 **)((int)this + 0x98);
              *puVar8 = piVar4;
              *(undefined4 **)((int)this + 0x98) = puVar8 + 1;
            }
            iVar9 = *(int *)((int)this + 0x2f4);
            dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,piVar4);
            if ((iVar9 == 0) ||
               ((uint)(*(int *)((int)this + 0x2fc) - iVar9 >> 2) <=
                (uint)(*(int *)((int)this + 0x2f8) - iVar9 >> 2))) {
              FUN_00460420((void *)((int)this + 0x2f0),*(undefined4 **)((int)this + 0x2f8),1,
                           (undefined4 *)&dStack_d0);
            }
            else {
              puVar8 = *(undefined4 **)((int)this + 0x2f8);
              *puVar8 = piVar4;
              *(undefined4 **)((int)this + 0x2f8) = puVar8 + 1;
            }
            iVar9 = *(int *)((int)this + 0x26c);
            if (iVar9 == 0) {
              iVar9 = piVar4[0x2a];
            }
            iVar9 = FUN_00493710(iVar9);
            dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,dStack_c4._0_4_ + iVar9);
          }
        }
        else if (piVar10 == (int *)0x1) {
          pvVar3 = operator_new(0xa8);
          dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,pvVar3);
          local_4._0_1_ = 2;
          if (pvVar3 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            if ((puStack_3c == (uint *)0x0) || ((uint)(iStack_38 - (int)puStack_3c >> 5) <= uVar6))
            goto LAB_00463f3f;
            piVar4 = FUN_004d8860(pvVar3,DAT_005b9b64,DAT_005b9abc,puStack_3c[uVar6 * 8],
                                  (int)this + 0x88);
          }
          local_4._0_1_ = 0;
          dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,piVar4);
          if ((puStack_3c == (uint *)0x0) || ((uint)(iStack_38 - (int)puStack_3c >> 5) <= uVar6))
          goto LAB_00463f4b;
          if (puStack_3c[uVar6 * 8] == 0) {
            iVar9 = *piVar4;
            (**(code **)(*DAT_005ba088 + 0xcc))();
            (**(code **)(iVar9 + 0xe0))();
          }
          if ((puStack_3c == (uint *)0x0) || ((uint)(iStack_38 - (int)puStack_3c >> 5) <= uVar6))
          goto LAB_00463f57;
          if (puStack_3c[uVar6 * 8] == 1) {
            iVar9 = *piVar4;
            (**(code **)(*DAT_005ba088 + 0xd0))();
            (**(code **)(iVar9 + 0xe0))();
          }
          iVar9 = *piVar4;
          FUN_00493710(DAT_005b9abc);
          piStack_c8 = (int *)FUN_00493700(local_90);
          FUN_00560568();
          FUN_00493710(local_90);
          iVar5 = dStack_c4._0_4_;
          dStack_c4 = (double)iStack_bc;
          piStack_c8 = (int *)FUN_00493700(local_90);
          FUN_00560568();
          (**(code **)(iVar9 + 100))();
          FUN_004d8dc0(*(void **)(*(int *)((int)this + 0xe0) + 0x2e4),piVar4);
          iVar9 = *(int *)((int)this + 0xb4);
          if ((iVar9 == 0) ||
             ((uint)(*(int *)((int)this + 0xbc) - iVar9 >> 2) <=
              (uint)(*(int *)((int)this + 0xb8) - iVar9 >> 2))) {
            FUN_00460420((void *)((int)this + 0xb0),*(undefined4 **)((int)this + 0xb8),1,
                         (undefined4 *)&dStack_d0);
          }
          else {
            puVar8 = *(undefined4 **)((int)this + 0xb8);
            *puVar8 = piVar4;
            *(undefined4 **)((int)this + 0xb8) = puVar8 + 1;
          }
          iVar9 = *(int *)((int)this + 0x2f4);
          dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,piVar4);
          if ((iVar9 == 0) ||
             ((uint)(*(int *)((int)this + 0x2fc) - iVar9 >> 2) <=
              (uint)(*(int *)((int)this + 0x2f8) - iVar9 >> 2))) {
            FUN_00460420((void *)((int)this + 0x2f0),*(undefined4 **)((int)this + 0x2f8),1,
                         (undefined4 *)&dStack_d0);
          }
          else {
            puVar8 = *(undefined4 **)((int)this + 0x2f8);
            *puVar8 = piVar4;
            *(undefined4 **)((int)this + 0x2f8) = puVar8 + 1;
          }
          if (*(int *)((int)this + 0x26c) == 0) {
            iVar9 = FUN_00493710(DAT_005b9abc);
            dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,iVar5 + 0x28 + iVar9);
          }
          else {
            iVar9 = FUN_00493710(*(int *)((int)this + 0x26c));
            dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,iVar5 + iVar9);
          }
        }
        else if (piVar10 == (int *)0x2) {
          pvVar3 = operator_new(0xb4);
          dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,pvVar3);
          local_4._0_1_ = 3;
          if (pvVar3 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            if ((puStack_2c == (undefined4 *)0x0) ||
               ((uint)(iStack_28 - (int)puStack_2c >> 5) <= uVar6)) goto LAB_00463f27;
            piVar4 = FUN_004d8ab0(pvVar3,DAT_005b9a50,DAT_005b9a50,puStack_2c[uVar6 * 8],
                                  (int)this + 0x8c);
          }
          local_4._0_1_ = 0;
          piStack_c8 = piVar4;
          iVar9 = FUN_00493700(DAT_005b9a50);
          iVar9 = iVar9 / 2;
          iVar5 = FUN_00493710(DAT_005b9a50);
          piVar10 = piVar4 + 0x29;
          *piVar10 = 0;
          piVar4[0x2a] = 0;
          piVar4[0x2b] = iVar9;
          piVar4[0x2c] = iVar5;
          iVar5 = FUN_00493710(DAT_005b9a50);
          piVar4[0x25] = iVar9;
          piVar4[0x26] = 0;
          piVar4[0x27] = iVar9;
          piVar4[0x28] = iVar5;
          if ((puStack_2c == (undefined4 *)0x0) ||
             ((uint)(iStack_28 - (int)puStack_2c >> 5) <= uVar6)) goto LAB_00463f33;
          if (puStack_2c[uVar6 * 8] == 2) {
            *(bool *)(piVar4 + 0x22) = *(char *)((int)DAT_005ba088 + 0x307) == '\0';
          }
          iVar9 = *piVar4;
          FUN_00493710(local_90);
          dStack_d0 = (double)iStack_bc;
          iVar5 = dStack_c4._0_4_;
          uVar2 = FUN_00493700(local_90);
          dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,uVar2);
          FUN_00560568();
          (**(code **)(iVar9 + 100))();
          FUN_004d8dc0(*(void **)(*(int *)((int)this + 0xe0) + 0x2e4),piVar4);
          iVar9 = *(int *)((int)this + 0xc4);
          if ((iVar9 == 0) ||
             ((uint)(*(int *)((int)this + 0xcc) - iVar9 >> 2) <=
              (uint)(*(int *)((int)this + 200) - iVar9 >> 2))) {
            FUN_00460420((void *)((int)this + 0xc0),*(undefined4 **)((int)this + 200),1,&piStack_c8)
            ;
          }
          else {
            puVar8 = *(undefined4 **)((int)this + 200);
            *puVar8 = piVar4;
            *(undefined4 **)((int)this + 200) = puVar8 + 1;
          }
          iVar9 = *(int *)((int)this + 0x2f4);
          if ((iVar9 == 0) ||
             ((uint)(*(int *)((int)this + 0x2fc) - iVar9 >> 2) <=
              (uint)(*(int *)((int)this + 0x2f8) - iVar9 >> 2))) {
            piStack_c8 = piVar4;
            FUN_00460420((void *)((int)this + 0x2f0),*(undefined4 **)((int)this + 0x2f8),1,
                         &piStack_c8);
          }
          else {
            puVar8 = *(undefined4 **)((int)this + 0x2f8);
            *puVar8 = piVar4;
            *(undefined4 **)((int)this + 0x2f8) = puVar8 + 1;
            piStack_c8 = piVar4;
          }
          if (*(int *)((int)this + 0x26c) == 0) {
            dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,*(int *)(DAT_005b9a50 + 8) + 10 + iVar5);
          }
          else {
            iVar9 = FUN_00493710(*(int *)((int)this + 0x26c));
            dStack_c4 = (double)CONCAT44(dStack_c4._4_4_,iVar5 + iVar9);
          }
        }
        puStack_b8 = (uint *)((int)puStack_b8 + 1);
      } while (puStack_b8 < puStack_70);
    }
  }
  puVar8 = *(undefined4 **)((int)this + 0xe8);
  piVar10 = this;
  if ((puVar8 == (undefined4 *)0x0) || (*(int *)((int)this + 0xec) - (int)puVar8 >> 7 == 0)) {
    FUN_0045fb00();
LAB_00463f27:
    FUN_0045fb00();
LAB_00463f33:
    FUN_0045fb00();
LAB_00463f3f:
    FUN_0045fb00();
LAB_00463f4b:
    this = piVar10;
    FUN_0045fb00();
LAB_00463f57:
    FUN_0045fb00();
    piVar10 = this;
LAB_00463f63:
    FUN_0045fb00();
LAB_00463f6f:
    FUN_0045fb00();
LAB_00463f7b:
    FUN_0045fb00();
    puVar8 = extraout_EDX;
  }
  FUN_004632c0(&local_90,puVar8);
  pvVar3 = operator_new(0x130);
  local_4._0_1_ = 4;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    if (piVar10 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = piVar10 + 0x20;
    }
    dStack_d0._0_4_ = pvVar3;
    piVar4 = FUN_004d8b60(pvVar3,*(undefined4 *)(iStack_48 + -0x5c),piVar4);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  dStack_d0 = (double)CONCAT44(dStack_d0._4_4_,piVar4);
  (**(code **)(*piVar4 + 0xe4))();
  FUN_00401e70(piVar4 + 0x21,puStack_4c + -0x16,0,0xffffffff);
  piVar4[0x2a] = DAT_005b9900;
  piVar4[0x2b] = DAT_005b9d10;
  iVar9 = *piVar4;
  FUN_0048c7e0(aiStack_b4,0xff,0xff,0xff,200);
  (**(code **)(iVar9 + 0x4c))();
  iVar9 = *piVar4;
  FUN_0048c7e0(&iStack_bc,0xfa,0x1b,0x1b,0xff);
  (**(code **)(iVar9 + 0x4c))(1);
  piVar4[0x28] = 0;
  *(undefined1 *)(piVar4 + 0x1d) = 1;
  iVar9 = *piVar4;
  uVar2 = FUN_00493710(DAT_005b9900);
  (**(code **)(iVar9 + 100))(0x253,500,200,uVar2);
  FUN_004d8dc0(*(void **)(piVar10[0x38] + 0x2e4),piVar4);
  iVar9 = piVar10[0x25];
  if ((iVar9 == 0) || ((uint)(piVar10[0x27] - iVar9 >> 2) <= (uint)(piVar10[0x26] - iVar9 >> 2))) {
    FUN_0041b000(piVar10 + 0x24,(undefined4 *)piVar10[0x26],1,(undefined4 *)&stack0xffffff0c);
  }
  else {
    puVar8 = (undefined4 *)piVar10[0x26];
    *puVar8 = piVar4;
    piVar10[0x26] = (int)(puVar8 + 1);
  }
  iVar9 = piVar10[0xbd];
  if ((iVar9 == 0) || ((uint)(piVar10[0xbf] - iVar9 >> 2) <= (uint)(piVar10[0xbe] - iVar9 >> 2))) {
    FUN_00460420(piVar10 + 0xbc,(undefined4 *)piVar10[0xbe],1,(undefined4 *)&stack0xffffff0c);
  }
  else {
    puVar8 = (undefined4 *)piVar10[0xbe];
    *puVar8 = piVar4;
    piVar10[0xbe] = (int)(puVar8 + 1);
  }
  if (iStack_20 == 4) {
    uVar11 = 1;
    do {
      uVar6 = FUN_00421a00((void *)(piVar10[0x38] + 0x638),uVar11);
      if (uVar6 == 0xffffffff) {
        iVar9 = piVar10[0x25];
        if ((iVar9 == 0) || ((uint)(piVar10[0x26] - iVar9 >> 2) <= uVar11)) {
                    /* WARNING: Subroutine does not return */
          FUN_00418c80();
        }
        (**(code **)(**(int **)(iVar9 + uVar11 * 4) + 0x58))(1);
      }
      uVar11 = uVar11 + 1;
    } while ((int)uVar11 < 4);
  }
  if (puStack_40 != (uint *)0x0) {
    if (puStack_40 != puStack_3c) {
      puVar7 = puStack_40 + 0xd;
      do {
        if (0xf < *puVar7) {
          _free((void *)puVar7[-5]);
        }
        *puVar7 = 0xf;
        puVar7[-1] = 0;
        *(undefined1 *)(puVar7 + -5) = 0;
        puVar1 = puVar7 + 1;
        puVar7 = puVar7 + 0xe;
      } while (puVar1 != puStack_3c);
    }
    _free(puStack_40);
  }
  puStack_40 = (uint *)0x0;
  puStack_3c = (uint *)0x0;
  iStack_38 = 0;
  if (puStack_50 != (uint *)0x0) {
    if (puStack_50 != puStack_4c) {
      puVar7 = puStack_50 + 7;
      do {
        if (0xf < *puVar7) {
          _free((void *)puVar7[-5]);
        }
        *puVar7 = 0xf;
        puVar7[-1] = 0;
        *(undefined1 *)(puVar7 + -5) = 0;
        puVar1 = puVar7 + 1;
        puVar7 = puVar7 + 8;
      } while (puVar1 != puStack_4c);
    }
    _free(puStack_50);
  }
  puStack_50 = (uint *)0x0;
  puStack_4c = (uint *)0x0;
  iStack_48 = 0;
  if (puStack_60 != (uint *)0x0) {
    if (puStack_60 != puStack_5c) {
      puVar7 = puStack_60 + 7;
      do {
        if (0xf < *puVar7) {
          _free((void *)puVar7[-5]);
        }
        *puVar7 = 0xf;
        puVar7[-1] = 0;
        *(undefined1 *)(puVar7 + -5) = 0;
        puVar1 = puVar7 + 1;
        puVar7 = puVar7 + 8;
      } while (puVar1 != puStack_5c);
    }
    _free(puStack_60);
  }
  puStack_60 = (uint *)0x0;
  puStack_5c = (uint *)0x0;
  uStack_58 = 0;
  if (puStack_70 != (uint *)0x0) {
    if (puStack_70 != puStack_6c) {
      puVar7 = puStack_70 + 0x15;
      do {
        if (0xf < *puVar7) {
          _free((void *)puVar7[-5]);
        }
        *puVar7 = 0xf;
        puVar7[-1] = 0;
        *(undefined1 *)(puVar7 + -5) = 0;
        if (0xf < puVar7[-7]) {
          _free((void *)puVar7[-0xc]);
        }
        puVar7[-7] = 0xf;
        puVar7[-8] = 0;
        *(undefined1 *)(puVar7 + -0xc) = 0;
        if (0xf < puVar7[-0xe]) {
          _free((void *)puVar7[-0x13]);
        }
        puVar7[-0xe] = 0xf;
        puVar7[-0xf] = 0;
        *(undefined1 *)(puVar7 + -0x13) = 0;
        puVar1 = puVar7 + 2;
        puVar7 = puVar7 + 0x17;
      } while (puVar1 != puStack_6c);
    }
    _free(puStack_70);
  }
  puStack_70 = (uint *)0x0;
  puStack_6c = (uint *)0x0;
  uStack_68 = 0;
  if (0xf < uStack_78) {
    _free(pvStack_8c);
  }
  ExceptionList = pvStack_30;
  return;
}

