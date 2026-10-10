/* Address: 00407740; name: FUN_00407740 */

undefined4 * __fastcall FUN_00407740(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  param_1[10] = 0;
  if ((void *)param_1[0xc] != (void *)0x0) {
    _free((void *)param_1[0xc]);
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 0x3f19999a;
  param_1[3] = 0x3ecccccd;
  return param_1;
}


