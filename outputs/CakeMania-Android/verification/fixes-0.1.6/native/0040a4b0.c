/* Native address 0040a4b0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_0040a4b0(int param_1)

{
  float10 fVar1;
  undefined2 unaff_retaddr;
  
  fVar1 = FUN_0055ff20((double)(((*(float *)(param_1 + 4) - _DAT_005813f8) *
                                 (*(float *)(param_1 + 0x268) - *(float *)(param_1 + 0x264)) *
                                 _DAT_005813fc + *(float *)(param_1 + 0x264)) * (float)_DAT_005813f0
                               + (float)_DAT_005813e8),unaff_retaddr);
  return fVar1 * (float10)_DAT_005813e0;
}

