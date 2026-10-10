/* Native address 00469810; read-only Ghidra audit recovery. */

void __fastcall FUN_00469810(int *param_1)

{
  int iVar1;
  
  FUN_004d2fb0((int)param_1);
  (**(code **)(*param_1 + 0x10))();
  iVar1 = FUN_00418c60((int)(param_1 + 0x25));
  if (iVar1 != 0) {
    FUN_004d3c60(*(void **)(param_1[0x66] + 0x2e4),param_1);
    if (param_1[99] == 2) {
      FUN_0041f580((void *)param_1[0x66],'\0');
      return;
    }
    FUN_0041f580((void *)param_1[0x66],'\x01');
  }
  return;
}

