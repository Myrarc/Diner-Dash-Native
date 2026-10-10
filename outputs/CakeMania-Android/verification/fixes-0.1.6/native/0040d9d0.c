/* Native address 0040d9d0; read-only Ghidra audit recovery. */

/* WARNING: Removing unreachable block (ram,0x0040d9f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040d9d0(int param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  ulonglong uVar8;
  
  if (((*(int *)(param_1 + 4) != 0) &&
      (uVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 4, uVar4 != 0)) &&
     (uVar4 <= uVar4 - 1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0040bb80();
  }
  piVar7 = *(int **)(param_1 + 0x14);
  uVar4 = 0;
  if (piVar7 != *(int **)(param_1 + 0x18)) {
    iVar6 = 0;
    do {
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - iVar1 >> 4;
      }
      if ((int)uVar4 < iVar5) {
        if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar1 >> 4) <= uVar4)) {
LAB_0040dae9:
                    /* WARNING: Subroutine does not return */
          FUN_0040bb80();
        }
        iVar5 = *(int *)(iVar6 + 4 + iVar1);
        pfVar2 = (float *)*piVar7;
        *pfVar2 = (float)*(int *)(iVar6 + iVar1);
        pfVar2[1] = (float)iVar5;
        iVar1 = *(int *)(param_1 + 4);
        if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar1 >> 4) <= uVar4))
        goto LAB_0040dae9;
        uVar3 = *(undefined4 *)(iVar6 + 0xc + iVar1);
        iVar5 = *piVar7;
        *(undefined4 *)(iVar5 + 0x1dc) = *(undefined4 *)(iVar6 + 8 + iVar1);
        *(undefined4 *)(iVar5 + 0x1e0) = uVar3;
        uVar8 = FUN_00560568();
        *(int *)(*piVar7 + 0x10) = (int)uVar8;
      }
      uVar4 = uVar4 + 1;
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + 0x10;
    } while (piVar7 != *(int **)(param_1 + 0x18));
  }
  return;
}

