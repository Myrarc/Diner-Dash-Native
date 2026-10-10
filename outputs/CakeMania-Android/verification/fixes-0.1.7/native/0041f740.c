/* Address: 0041f740; name: FUN_0041f740 */

void __fastcall FUN_0041f740(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  local_4 = param_1;
  FUN_004d3c60(*(void **)(param_1 + 0x2e4),*(int **)(param_1 + 0x604));
  if (*(int *)(param_1 + 0x710) == 1) {
    uVar1 = *(uint *)(param_1 + 0x70c);
    iVar4 = FUN_00421870((void *)(param_1 + 0x638));
    iVar2 = *(int *)(iVar4 + 0x30);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x34) - iVar2 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    **(undefined4 **)(iVar2 + uVar1 * 4) = 0;
  }
  iVar5 = *(int *)(param_1 + 0x710) + -1;
  local_4 = iVar5;
  iVar4 = FUN_00421870((void *)(param_1 + 0x638));
  iVar2 = *(int *)(iVar4 + 0x20);
  if ((iVar2 != 0) &&
     ((uint)(*(int *)(iVar4 + 0x24) - iVar2 >> 2) < (uint)(*(int *)(iVar4 + 0x28) - iVar2 >> 2))) {
    piVar3 = *(int **)(iVar4 + 0x24);
    *piVar3 = iVar5;
    *(int **)(iVar4 + 0x24) = piVar3 + 1;
    FUN_0041f290(param_1);
    return;
  }
  FUN_0040ccc0((void *)(iVar4 + 0x1c),*(undefined4 **)(iVar4 + 0x24),1,&local_4);
  FUN_0041f290(param_1);
  return;
}


