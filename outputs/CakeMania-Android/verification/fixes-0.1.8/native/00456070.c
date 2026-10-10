/* Native address 00456070; read-only Ghidra audit recovery. */

void __fastcall Recovered_00456070(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int unaff_retaddr;
  
  (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9e48);
  if (unaff_retaddr == 0) {
    iVar2 = *(int *)(param_1 + 0x144);
    if (0 < iVar2) {
      *(int *)(param_1 + 0x148) = iVar2;
      *(undefined4 *)(param_1 + 300) = 0x3f800000;
      *(int *)(param_1 + 0x144) = iVar2 + -1;
    }
    piVar3 = (int *)(*(int *)(param_1 + 0x134) + 4);
    if (*(int *)(param_1 + 0x144) == 0) {
      *(undefined1 *)(*piVar3 + 0x4e) = 0;
      return;
    }
    *(undefined1 *)(*piVar3 + 0x4e) = 0;
  }
  else if (unaff_retaddr == 1) {
    if (*(int *)(param_1 + 0x120) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x124) - *(int *)(param_1 + 0x120) >> 2;
    }
    uVar1 = *(uint *)(param_1 + 0x144);
    if (uVar1 < iVar2 - 1U) {
      *(uint *)(param_1 + 0x148) = uVar1;
      *(undefined4 *)(param_1 + 300) = 0x3f800000;
      *(uint *)(param_1 + 0x144) = uVar1 + 1;
    }
    if (*(int *)(param_1 + 0x120) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x124) - *(int *)(param_1 + 0x120) >> 2;
    }
    if (*(int *)(param_1 + 0x144) != iVar2 + -1) {
      *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x134) + 4) + 0x4e) = 0;
      return;
    }
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x134) + 4) + 0x4e) = 1;
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x134) + 4) + 0xf9) = 1;
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0x4e) = 0;
    *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x134) + 8) + 0xf9) = 0;
    if (*(int **)(param_1 + 0x140) != (int *)0x0) {
      FUN_004d3c60(*(void **)(*(int *)(param_1 + 0x150) + 0x2e4),*(int **)(param_1 + 0x140));
    }
    piVar3 = *(int **)(*(int *)(param_1 + 0x134) + 8);
    *(int **)(param_1 + 0x140) = piVar3;
    if (piVar3 != (int *)0x0) {
      FUN_004d8dc0(*(void **)(*(int *)(param_1 + 0x150) + 0x2e4),piVar3);
      return;
    }
  }
  else if (unaff_retaddr == 2) {
    *(undefined1 *)(param_1 + 0xfc) = 1;
    return;
  }
  return;
}

