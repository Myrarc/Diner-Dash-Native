/* Address: 00477f80; name: FUN_00477f80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00477f80(int param_1)

{
  double dVar1;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  
  DVar2 = timeGetTime();
  if (*(int *)(param_1 + 0x418) == 0) {
    *(DWORD *)(param_1 + 0x418) = DVar2;
  }
  else {
    iVar4 = DVar2 - *(int *)(param_1 + 0x418);
    dVar1 = (double)iVar4 + *(double *)(param_1 + 0x410);
    if (_DAT_00588308 <= dVar1) {
      dVar1 = _DAT_00588308;
    }
    *(double *)(param_1 + 0x410) = dVar1;
    *(DWORD *)(param_1 + 0x418) = DVar2;
    if (0 < *(int *)(param_1 + 0x7c)) {
      uVar3 = *(int *)(param_1 + 0x7c) - iVar4;
      *(uint *)(param_1 + 0x7c) = uVar3 & ((int)uVar3 < 1) - 1;
      return;
    }
  }
  return;
}


