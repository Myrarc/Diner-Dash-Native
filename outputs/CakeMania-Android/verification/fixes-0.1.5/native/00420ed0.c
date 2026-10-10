/* Native address 00420ed0; read-only Ghidra audit recovery. */

undefined4 * __thiscall FUN_00420ed0(void *this,undefined4 *param_1)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00575635;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)this = *param_1;
  *(undefined4 *)((int)this + 0x1c) = 0xf;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined1 *)((int)this + 8) = 0;
  FUN_00401e70((void *)((int)this + 4),param_1 + 1,0,0xffffffff);
  local_4 = 0;
  FUN_00420740((void *)((int)this + 0x20),(int)(param_1 + 8));
  *(undefined4 *)((int)this + 0x30) = param_1[0xc];
  *(undefined4 *)((int)this + 0x34) = param_1[0xd];
  *(undefined4 *)((int)this + 0x38) = param_1[0xe];
  *(undefined4 *)((int)this + 0x54) = 0xf;
  *(undefined4 *)((int)this + 0x50) = 0;
  local_4._0_1_ = 1;
  *(undefined1 *)((int)this + 0x40) = 0;
  FUN_00401e70((void *)((int)this + 0x3c),param_1 + 0xf,0,0xffffffff);
  *(undefined4 *)((int)this + 0x70) = 0xf;
  *(undefined4 *)((int)this + 0x6c) = 0;
  local_4._0_1_ = 2;
  *(undefined1 *)((int)this + 0x5c) = 0;
  FUN_00401e70((void *)((int)this + 0x58),param_1 + 0x16,0,0xffffffff);
  *(undefined4 *)((int)this + 0x8c) = 0xf;
  *(undefined4 *)((int)this + 0x88) = 0;
  local_4._0_1_ = 3;
  *(undefined1 *)((int)this + 0x78) = 0;
  FUN_00401e70((void *)((int)this + 0x74),param_1 + 0x1d,0,0xffffffff);
  *(undefined4 *)((int)this + 0xa8) = 0xf;
  *(undefined4 *)((int)this + 0xa4) = 0;
  local_4._0_1_ = 4;
  *(undefined1 *)((int)this + 0x94) = 0;
  FUN_00401e70((void *)((int)this + 0x90),param_1 + 0x24,0,0xffffffff);
  local_4 = CONCAT31(local_4._1_3_,5);
  *(undefined4 *)((int)this + 0xc4) = 0xf;
  *(undefined4 *)((int)this + 0xc0) = 0;
  *(undefined1 *)((int)this + 0xb0) = 0;
  FUN_00401e70((void *)((int)this + 0xac),param_1 + 0x2b,0,0xffffffff);
  ExceptionList = local_c;
  return this;
}

