/* Address: 004121b0; name: FUN_004121b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004121b0(void *this,int param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  void **ppvVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  byte **ppbVar12;
  bool bVar13;
  bool bVar14;
  uint in_stack_0000001c;
  uint in_stack_00000020;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00574638;
  pvStack_c = ExceptionList;
  piVar10 = *(int **)((int)this + 0x14);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  ppvVar4 = &pvStack_c;
  if (piVar10 != *(int **)((int)this + 0x18)) {
    do {
      iVar9 = *piVar10;
      piVar5 = *(int **)(iVar9 + 0x2b0);
      if (piVar5 != *(int **)(iVar9 + 0x2b4)) {
        puVar8 = (uint *)(piVar5 + 6);
        do {
          if (*piVar5 == param_1) {
            ppbVar12 = (byte **)param_3;
            if (in_stack_00000020 < 0x10) {
              ppbVar12 = &param_3;
            }
            uVar1 = *puVar8;
            if (uVar1 != 0) {
              uVar7 = in_stack_0000001c;
              if (uVar1 < in_stack_0000001c) {
                uVar7 = uVar1;
              }
              if (puVar8[1] < 0x10) {
                puVar11 = puVar8 + -4;
              }
              else {
                puVar11 = (uint *)puVar8[-4];
              }
              bVar13 = false;
              iVar6 = 0;
              bVar14 = true;
              do {
                if (uVar7 == 0) break;
                uVar7 = uVar7 - 1;
                bVar13 = (byte)*puVar11 < *(byte *)ppbVar12;
                bVar14 = (byte)*puVar11 == *(byte *)ppbVar12;
                puVar11 = (uint *)((int)puVar11 + 1);
                ppbVar12 = (byte **)((int)ppbVar12 + 1);
              } while (bVar14);
              if (!bVar14) {
                iVar6 = (1 - (uint)bVar13) - (uint)(bVar13 != 0);
              }
              if (iVar6 != 0) goto LAB_00412325;
            }
            if ((in_stack_0000001c <= uVar1) && (uVar1 == in_stack_0000001c)) {
              fVar2 = (float)(int)(puVar8[2] * *(int *)(iVar9 + 0x3c)) + *(float *)(iVar9 + 0x328);
              *(float *)(iVar9 + 0x328) = fVar2;
              fVar3 = (float)((*(int *)(iVar9 + 0x34) + 1) * *(int *)(iVar9 + 0x3c)) - _DAT_00581620
              ;
              if (fVar3 < fVar2) {
                *(float *)(iVar9 + 0x328) = fVar3;
              }
              if (0 < (int)puVar8[2]) {
                iVar9 = *piVar10;
                *(undefined4 *)(iVar9 + 800) = 2;
                *(undefined4 *)(iVar9 + 0x308) = 0;
                *(undefined4 *)(iVar9 + 0x304) = 0;
                (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9740);
                *(undefined1 *)(*piVar10 + 0x260) = 1;
              }
              if (*piVar5 == 1) {
                FUN_00411590((void *)(*piVar10 + 0x1ec),puVar8[2]);
              }
            }
          }
LAB_00412325:
          iVar9 = *piVar10;
          piVar5 = piVar5 + 9;
          puVar8 = puVar8 + 9;
        } while (piVar5 != *(int **)(iVar9 + 0x2b4));
      }
      piVar10 = piVar10 + 1;
      ppvVar4 = ExceptionList;
    } while (piVar10 != *(int **)((int)this + 0x18));
  }
  ExceptionList = ppvVar4;
  if (0xf < in_stack_00000020) {
    _free(param_3);
  }
  ExceptionList = pvStack_c;
  return;
}


