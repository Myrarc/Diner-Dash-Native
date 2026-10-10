/* Address: 00453970; name: FUN_00453970 */

void __cdecl FUN_00453970(void *param_1,int param_2,void *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00579a11;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (void *)0x0) {
      *(undefined4 *)((int)param_1 + 0x18) = 0xf;
      *(undefined4 *)((int)param_1 + 0x14) = 0;
      *(undefined1 *)((int)param_1 + 4) = 0;
      FUN_00401e70(param_1,param_3,0,0xffffffff);
      *(undefined4 *)((int)param_1 + 0x1c) = *(undefined4 *)((int)param_3 + 0x1c);
      *(undefined4 *)((int)param_1 + 0x20) = *(undefined4 *)((int)param_3 + 0x20);
      *(undefined4 *)((int)param_1 + 0x24) = *(undefined4 *)((int)param_3 + 0x24);
      *(undefined4 *)((int)param_1 + 0x28) = *(undefined4 *)((int)param_3 + 0x28);
      *(undefined4 *)((int)param_1 + 0x2c) = *(undefined4 *)((int)param_3 + 0x2c);
      *(undefined4 *)((int)param_1 + 0x30) = *(undefined4 *)((int)param_3 + 0x30);
    }
    param_1 = (void *)((int)param_1 + 0x34);
  }
  ExceptionList = local_10;
  return;
}


