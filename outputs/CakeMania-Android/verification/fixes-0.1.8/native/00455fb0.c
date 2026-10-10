/* Address: 00455fb0; name: FUN_00455fb0 */

void __fastcall FUN_00455fb0(int *param_1)

{
  int iVar1;
  
  FUN_004d2fb0((int)param_1);
  (**(code **)(*param_1 + 0x10))();
  iVar1 = FUN_00418c60((int)(param_1 + 0x21));
  if (iVar1 != 0) {
    FUN_004d3c60(*(void **)(param_1[0x74] + 0x2e4),param_1);
    thunk_FUN_0041c460((void *)param_1[0x74]);
  }
  if ((char)param_1[0x5f] == '\0') {
    iVar1 = FUN_004781b0((int)DAT_005ba088);
    if (iVar1 != 6) {
      FUN_00478190(DAT_005ba088,1);
    }
  }
  return;
}


