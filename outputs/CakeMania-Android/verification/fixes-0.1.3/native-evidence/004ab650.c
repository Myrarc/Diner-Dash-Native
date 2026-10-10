/* Native address 004ab650; read-only Ghidra audit recovery. */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004ab650(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  ulonglong uVar8;
  undefined **local_10c0 [2];
  undefined4 local_10b8;
  undefined1 local_10b4;
  undefined4 local_10b0 [1024];
  undefined **local_b0;
  int *local_ac;
  undefined1 local_a0 [16];
  int local_90 [5];
  undefined4 local_7c;
  char local_78;
  undefined4 local_77;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  void *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  double local_44;
  int local_3c;
  double local_38;
  int *local_30;
  int local_2c;
  void *local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  uint *local_18;
  undefined4 uStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0057d691;
  local_10 = ExceptionList;
  uStack_14 = 0x4ab672;
  if (*(char *)(*(int *)(param_1 + 0x14) + 0x50) != '\0') {
    ExceptionList = &local_10;
    local_3c = param_1;
    FUN_004a04e0(param_1 + 0x30);
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    local_30 = (int *)**(int **)(*(int *)(param_1 + 0x14) + 0x170);
    uStack_14 = CONCAT13(1,(uint3)uStack_14);
    if (local_30 != *(int **)(*(int *)(param_1 + 0x14) + 0x170)) {
      do {
        piVar3 = local_30;
        piVar6 = local_30 + 2;
        if ((local_30[0x4818] <= *(int *)(param_1 + 0x18)) &&
           ((*(int *)(param_1 + 0x18) <= local_30[0x4819] || (local_30[0x4819] == -1)))) {
          uStack_14._0_3_ = CONCAT12(1,(ushort)uStack_14);
          local_18 = (uint *)0x0;
          for (local_1c = 0; (piVar3[4] != 0 && (local_1c < (uint)((piVar3[5] - piVar3[4]) / 0x1c)))
              ; local_1c = local_1c + 1) {
            pvVar1 = *(void **)(param_1 + 0x24);
            puVar4 = (undefined4 *)
                     FUN_0049f850(&local_58,*(void **)(param_1 + 0x20),pvVar1,
                                  piVar3[4] + (int)local_18);
            if ((void *)*puVar4 == pvVar1) {
              uStack_14._0_3_ = (uint3)(ushort)uStack_14;
            }
            local_18 = (uint *)((int)local_18 + 0x1c);
          }
          local_18 = (uint *)0x0;
          for (local_1c = 0;
              (*(int *)(param_1 + 0x20) != 0 &&
              (local_1c < (uint)((*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20)) / 0x1c)));
              local_1c = local_1c + 1) {
            pvVar1 = (void *)piVar3[9];
            puVar4 = (undefined4 *)
                     FUN_0049f850(&local_5c,(void *)piVar3[8],pvVar1,
                                  *(int *)(param_1 + 0x20) + (int)local_18);
            if ((void *)*puVar4 != pvVar1) {
              uStack_14._0_3_ = (uint3)(ushort)uStack_14;
            }
            local_18 = (uint *)((int)local_18 + 0x1c);
          }
          if (uStack_14._2_1_ != '\0') {
            local_10c0[0] = &PTR_FUN_00589470;
            puVar4 = local_10b0 + 2;
            iVar7 = 0x100;
            do {
              puVar4[-2] = 0;
              puVar4[-1] = 0;
              *puVar4 = 0;
              puVar4[1] = 0;
              puVar4 = puVar4 + 4;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
            local_10b8 = 0;
            local_10b4 = 0;
            local_8 = 0;
            iVar7 = *(int *)(param_1 + 0x34);
            local_24 = FUN_0049f660(iVar7,*(undefined4 *)(iVar7 + 4),(int)local_10c0);
            FUN_004a3d40((void *)(param_1 + 0x30),1);
            local_44 = _DAT_005874d8;
            *(int **)(iVar7 + 4) = local_24;
            *(int **)local_24[1] = local_24;
            iVar7 = *(int *)(*(int *)(param_1 + 0x34) + 4);
            *(int **)(iVar7 + 0xc) = piVar6;
            local_38 = *(double *)(param_1 + 0x40);
            local_8 = 0xffffffff;
            local_10c0[0] = &PTR_FUN_00589470;
            if (((*(int *)(param_1 + 0x40) == 0) && (*(int *)(param_1 + 0x44) == 0x3ff00000)) &&
               ((piVar3[0x481a] == 0 || (*(int *)(param_1 + 0x18) == piVar3[0x481a])))) {
              *(int *)(iVar7 + 0x10) = piVar3[0x4813];
              *(undefined1 *)(iVar7 + 0x14) = 0;
              local_20 = (int *)(iVar7 + 0x18);
              piVar6 = piVar3 + 0xb;
              local_18 = (uint *)0x100;
              do {
                *local_20 = *piVar6;
                local_20[1] = piVar6[1];
                local_20[2] = piVar6[2];
                local_20[3] = piVar6[3];
                local_20 = local_20 + 4;
                piVar6 = piVar6 + 0x48;
                local_18 = (uint *)((int)local_18 + -1);
              } while (local_18 != (uint *)0x0);
              local_18 = (uint *)0x0;
            }
            else {
              local_24 = (int *)piVar3[0x481a];
              if (local_24 != (int *)0x0) {
                local_44 = (double)(int)local_24;
                local_38 = (double)*(int *)(param_1 + 0x18) * *(double *)(param_1 + 0x40);
              }
              local_28 = operator_new(0x4c);
              local_8 = 1;
              if (local_28 == (void *)0x0) {
                local_24 = (int *)0x0;
              }
              else {
                local_24 = FUN_004a7a90(local_28,*(int *)(*(int *)(param_1 + 0x14) + 0x58));
              }
              local_18 = (uint *)(iVar7 + 0x18);
              local_8 = 0xffffffff;
              local_1c = 0;
              local_20 = (void *)0x0;
              local_2c = 0x100;
              do {
                uVar8 = FUN_00560568();
                local_28 = (void *)uVar8;
                uVar8 = FUN_00560568();
                piVar6 = local_24;
                *local_18 = local_1c;
                local_18[1] = 0;
                local_18[2] = (uint)uVar8;
                local_18[3] = (uint)local_28;
                if ((int)local_20 < (int)local_28) {
                  local_20 = local_28;
                }
                local_1c = local_1c + (uint)uVar8;
                local_18 = local_18 + 4;
                local_2c = local_2c + -1;
              } while (local_2c != 0);
              *(int **)(iVar7 + 0x10) = local_24;
              *(undefined1 *)(iVar7 + 0x14) = 1;
              (**(code **)(*local_24 + 0x70))(local_1c,local_20);
              FUN_004a05d0(&local_b0,(int)piVar6);
              local_20 = piVar3 + 0xb;
              local_8 = 2;
              puVar4 = (undefined4 *)(iVar7 + 0x20);
              local_2c = 0x100;
              do {
                if (piVar3[0x4813] != 0) {
                  uVar8 = FUN_00560568();
                  local_28 = (void *)uVar8;
                  uVar8 = FUN_00560568();
                  local_54 = (undefined4)uVar8;
                  local_50 = local_28;
                  local_4c = *puVar4;
                  local_48 = puVar4[1];
                  if (local_78 == '\0') {
                    local_24 = &DAT_005b5504;
                  }
                  else {
                    local_24 = local_90;
                  }
                  (**(code **)(*local_ac + 0x28))
                            (piVar3[0x4813],&local_54,local_20,local_a0,local_24,local_7c,local_77);
                }
                local_20 = local_20 + 0x48;
                puVar4 = puVar4 + 4;
                local_2c = local_2c + -1;
              } while (local_2c != 0);
              if (*(char *)(local_3c + 0x48) != '\0') {
                iVar7 = piVar6[2] * piVar6[1];
                puVar5 = (uint *)(**(code **)(*piVar6 + 0x74))();
                if (0 < iVar7) {
                  do {
                    *puVar5 = *puVar5 | 0xffffff;
                    puVar5 = puVar5 + 1;
                    iVar7 = iVar7 + -1;
                  } while (iVar7 != 0);
                }
              }
              (**(code **)(*piVar6 + 0x80))();
              local_b0 = &PTR_FUN_00589560;
              piVar6 = (int *)*local_64;
              *local_64 = (int)local_64;
              local_64[1] = (int)local_64;
              local_8 = 0xffffffff;
              local_60 = 0;
              if (piVar6 != local_64) {
                do {
                  piVar2 = (int *)*piVar6;
                  _free(piVar6);
                  piVar6 = piVar2;
                } while (piVar2 != local_64);
              }
              _free(local_64);
              local_64 = (int *)0x0;
              param_1 = local_3c;
            }
            uVar8 = FUN_00560568();
            if (*(int *)(param_1 + 4) < (int)uVar8) {
              *(int *)(param_1 + 4) = (int)uVar8;
            }
            local_28 = (void *)piVar3[0x481d];
            uVar8 = FUN_00560568();
            if (*(int *)(param_1 + 0xc) < (int)uVar8) {
              *(int *)(param_1 + 0xc) = (int)uVar8;
            }
            uVar8 = FUN_00560568();
            if ((uStack_14._3_1_ != '\0') || ((int)uVar8 < *(int *)(param_1 + 8))) {
              *(int *)(param_1 + 8) = (int)uVar8;
            }
            uVar8 = FUN_00560568();
            if ((uStack_14._3_1_ != '\0') || (*(int *)(param_1 + 0x10) < (int)uVar8)) {
              *(int *)(param_1 + 0x10) = (int)uVar8;
            }
            uStack_14 = uStack_14 & 0xffffff;
          }
        }
        local_30 = (int *)*local_30;
      } while (local_30 != (int *)*(int *)(*(int *)(param_1 + 0x14) + 0x170));
    }
  }
  ExceptionList = local_10;
  return;
}

