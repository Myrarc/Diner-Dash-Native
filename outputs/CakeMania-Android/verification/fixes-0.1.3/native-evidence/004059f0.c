/* Native address 004059f0; read-only Ghidra audit recovery. */

undefined4 * __fastcall FUN_004059f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00573e1d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  param_1[6] = 0;
  param_1[7] = 0;
  FUN_00405890((int)(param_1 + 9));
  param_1[0x2741] = 0;
  param_1[0x2742] = 0;
  param_1[0x274d] = 0xf;
  param_1[0x274c] = 0;
  *(undefined1 *)(param_1 + 0x2748) = 0;
  param_1[0x2754] = 0xf;
  param_1[0x2753] = 0;
  *(undefined1 *)(param_1 + 0x274f) = 0;
  param_1[0x275b] = 0xf;
  param_1[0x275a] = 0;
  *(undefined1 *)(param_1 + 0x2756) = 0;
  param_1[0x2762] = 0xf;
  param_1[0x2761] = 0;
  *(undefined1 *)(param_1 + 0x275d) = 0;
  param_1[0x2766] = 0;
  param_1[0x2767] = 0;
  param_1[0x2769] = 0;
  param_1[0x276a] = 0;
  param_1[0x276b] = 0;
  param_1[0x2770] = 0;
  param_1[0x2771] = 0;
  param_1[0x2772] = 0;
  puVar1 = param_1 + 0x277b;
  iVar2 = 0x48;
  do {
    puVar1[-3] = 0;
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0x2a46] = 0;
  param_1[0x2a47] = 0;
  param_1[0x2a48] = 0;
  param_1[3] = 0x3f800000;
  *param_1 = 0x40866666;
  param_1[0x2745] = 8;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  local_4 = 7;
  if ((void *)param_1[0x2769] != (void *)0x0) {
    _free((void *)param_1[0x2769]);
  }
  param_1[0x2769] = 0;
  param_1[0x276a] = 0;
  param_1[0x276b] = 0;
  param_1[0x273b] = 0x3f800000;
  param_1[0x2a43] = 0;
  param_1[0x276c] = 0x3f800000;
  param_1[0x276d] = 0x3f333333;
  if ((void *)param_1[0x2770] != (void *)0x0) {
    _free((void *)param_1[0x2770]);
  }
  param_1[0x2770] = 0;
  param_1[0x2771] = 0;
  param_1[0x2772] = 0;
  param_1[0x273c] = 0;
  param_1[0x273d] = 0;
  param_1[0x273f] = 0;
  param_1[0x2740] = 0;
  param_1[0x2741] = 0xbf800000;
  param_1[0x2742] = 0xbf800000;
  param_1[0x273e] = 0;
  param_1[0x2743] = 0;
  param_1[0x2744] = 0;
  param_1[8] = 0;
  param_1[0x2a44] = 0;
  param_1[4] = 0;
  param_1[0x2746] = 0;
  param_1[1] = 0;
  FUN_00401f60(param_1 + 0x2747,(undefined4 *)&DAT_0058150c,4);
  puVar1 = param_1 + 0x277d;
  iVar2 = 0x12;
  do {
    puVar1[-10] = 0;
    *puVar1 = 0;
    puVar1[10] = 0;
    puVar1[0x14] = 0;
    puVar1 = puVar1 + 0x28;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[2] = 0;
  param_1[0x2764] = 0;
  if ((void *)param_1[0x2a46] != (void *)0x0) {
    _free((void *)param_1[0x2a46]);
  }
  param_1[0x2a46] = 0;
  param_1[0x2a47] = 0;
  param_1[0x2a48] = 0;
  param_1[0x2765] = 0;
  param_1[0x2766] = 0;
  param_1[0x2767] = 0;
  ExceptionList = local_c;
  return param_1;
}

