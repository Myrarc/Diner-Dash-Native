/* Native address 00411c20; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __fastcall FUN_00411c20(undefined4 *param_1)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0057461d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  local_4 = 0;
  puVar2 = param_1 + 0x1b;
  iVar3 = 5;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _eh_vector_constructor_iterator_(param_1 + 0x2a,0x10,5,FUN_0044be70,FUN_0041fb40);
  local_4._0_1_ = 1;
  _eh_vector_constructor_iterator_(param_1 + 0x3e,0x10,5,FUN_0044be70,FUN_0041fb40);
  local_4._0_1_ = 2;
  FUN_004107f0(param_1 + 0x54);
  param_1[0x72] = DAT_005b9e8c;
  param_1[0x73] = DAT_005b9660;
  param_1[0x76] = 0;
  param_1[0x71] = 0;
  iVar3 = DAT_005b9c00;
  param_1[0x74] = DAT_005b9c00;
  param_1[0x75] = 0xffffffff;
  param_1[0x7a] = 0;
  param_1[0x79] = 0x3d8f5c29;
  local_4._0_1_ = 3;
  *(undefined4 *)(iVar3 + 0xc) = 8;
  FUN_0040ec70(param_1 + 0x7b);
  param_1[0xa5] = 0xf;
  param_1[0xa4] = 0;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0xac] = 0;
  param_1[0xad] = 0;
  param_1[0xae] = 0;
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0xc4] = 0;
  param_1[0xc5] = 0;
  param_1[0xc6] = 0;
  param_1[1] = 0;
  local_4 = CONCAT31(local_4._1_3_,9);
  *param_1 = 0;
  param_1[5] = 0;
  FUN_00401f60(param_1 + 6,(undefined4 *)&DAT_005816bc,4);
  param_1[0xd] = 1;
  param_1[0x12] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x13] = 2;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x19] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x1a] = 0;
  param_1[0x99] = 0x3f800000;
  param_1[0x9a] = 0x3f800000;
  param_1[0x52] = DAT_005b962c;
  param_1[0x53] = DAT_005b9e8c;
  param_1[0xca] = 0;
  param_1[0x14] = 0x40400000;
  param_1[0x15] = 0x40000000;
  param_1[0x5a] = DAT_005b9ec8;
  param_1[0x5b] = DAT_005b9db8;
  iVar3 = *(int *)(param_1[0x67] + 0x10);
  *(undefined1 *)(param_1 + 0x9b) = 0;
  *(undefined1 *)((int)param_1 + 0x26d) = 0;
  fVar1 = _DAT_005814a8 / (float)iVar3;
  *(undefined1 *)((int)param_1 + 0x26f) = 0;
  *(undefined1 *)((int)param_1 + 0x26e) = 0;
  *(undefined1 *)(param_1 + 0x9c) = 0;
  param_1[0xa6] = 0;
  param_1[0x6e] = fVar1;
  if ((void *)param_1[0xa8] != (void *)0x0) {
    _free((void *)param_1[0xa8]);
  }
  param_1[0xa8] = 0;
  param_1[0xa9] = 0;
  param_1[0xaa] = 0;
  param_1[0x9e] = 0xffffffff;
  param_1[0xc1] = 0;
  param_1[0xc2] = 0;
  param_1[0xaf] = 0;
  if ((void *)param_1[0xc4] != (void *)0x0) {
    _free((void *)param_1[0xc4]);
  }
  param_1[0xc4] = 0;
  param_1[0xc5] = 0;
  param_1[0xc6] = 0;
  FUN_0040e650((int)(param_1 + 0xab));
  param_1[200] = 0;
  param_1[0xc9] = 0;
  param_1[0x9d] = 0xfffffffe;
  param_1[199] = 0;
  param_1[0xb5] = 0;
  param_1[0xb4] = 0;
  param_1[0xb6] = 0;
  if ((void *)param_1[0xb1] != (void *)0x0) {
    _free((void *)param_1[0xb1]);
  }
  param_1[0xb1] = 0;
  param_1[0xb2] = 0;
  param_1[0xb3] = 0;
  param_1[0x96] = 0xffffffff;
  param_1[0x97] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x98) = 0;
  param_1[0xb8] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 0xc0) = 0;
  param_1[0x8c] = 0x41a00000;
  param_1[0xb9] = 0x3f000000;
  param_1[0xb7] = 0xff;
  ExceptionList = local_c;
  return param_1;
}

