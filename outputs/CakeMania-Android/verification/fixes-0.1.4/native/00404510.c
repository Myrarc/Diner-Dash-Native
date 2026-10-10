/* Native address 00404510; read-only Ghidra audit recovery. */

void __fastcall FUN_00404510(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  if ((0 < *(int *)(param_1 + 4)) && (iVar3 = *(int *)(param_1 + 0x9d90), iVar3 != 0)) {
    if ((*(int *)(param_1 + 0x9dc0) == 0) ||
       ((uint)(*(int *)(param_1 + 0x9dc4) - *(int *)(param_1 + 0x9dc0) >> 2) <=
        *(uint *)(param_1 + 0x9d14))) {
      FUN_004023a0();
      return;
    }
    uVar4 = FUN_00560568();
    uVar5 = FUN_00560568();
    *(undefined4 *)(iVar3 + 0xc) = 4;
    *(undefined4 *)(iVar3 + 0x10) = 1;
    local_18 = iVar3;
    iVar1 = FUN_004bb1e0();
    iVar2 = FUN_00493700(iVar3);
    iVar1 = (int)((ulonglong)((longlong)(iVar2 * (iVar1 % 100 + -0x32)) * -0x51eb851f) >> 0x20);
    local_14 = (int)uVar4 + ((iVar1 >> 5) - (iVar1 >> 0x1f));
    iVar2 = FUN_004bb1e0();
    iVar1 = *(int *)(iVar3 + 0xc);
    iVar3 = FUN_00493710(iVar3);
    local_c = *(undefined4 *)(param_1 + 0x9d94);
    local_8 = 0;
    local_10 = (int)uVar5 + (iVar3 * (iVar2 % 100 + -0x32)) / (iVar1 * -100);
    local_4 = iVar1;
    FUN_00403ed0((void *)(param_1 + 0xa914),&local_18);
  }
  return;
}

