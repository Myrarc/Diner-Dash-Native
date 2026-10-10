/* Native address 0040ec70; read-only Ghidra audit recovery. */

undefined4 * __fastcall FUN_0040ec70(undefined4 *param_1)

{
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x16] = 0;
  param_1[0x13] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[0x11] = 0x41a00000;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x14] = 0x3db851ec;
  param_1[0x12] = 0;
  if ((void *)param_1[0x18] != (void *)0x0) {
    _free((void *)param_1[0x18]);
  }
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  return param_1;
}

