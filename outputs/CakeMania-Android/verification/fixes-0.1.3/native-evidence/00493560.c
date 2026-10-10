/* Native address 00493560; read-only Ghidra audit recovery. */

int __fastcall Recovered_00493560(int param_1)

{
  return *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
}

