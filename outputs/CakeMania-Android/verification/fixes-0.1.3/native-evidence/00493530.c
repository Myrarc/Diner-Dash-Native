/* Native address 00493530; read-only Ghidra audit recovery. */

int __fastcall Recovered_00493530(int param_1)

{
  return *(int *)(param_1 + 0xc) - *(int *)(param_1 + 4);
}

