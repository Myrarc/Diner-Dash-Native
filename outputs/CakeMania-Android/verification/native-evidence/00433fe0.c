/* Native address 00433fe0. Recovered in read-only Ghidra session. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Recovered_00433fe0(int param_1,undefined4 param_2,float param_3)

{
  if (((*(int *)(param_1 + 0x34) != 0) && (_DAT_0059d334 < *(float *)(param_1 + 0x68))) &&
     (param_3 = *(float *)(param_1 + 0x68) - param_3, *(float *)(param_1 + 0x68) = param_3,
     param_3 < _DAT_0059d334)) {
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}

