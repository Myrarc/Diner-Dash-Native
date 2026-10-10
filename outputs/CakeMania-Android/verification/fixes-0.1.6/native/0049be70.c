/* Native address 0049be70; read-only Ghidra audit recovery. */

void __thiscall FUN_0049be70(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  if ((((-1 < param_4) && (-1 < param_3)) && (param_4 < *(int *)(param_1 + 0xc))) &&
     (param_3 < *(int *)(param_1 + 0x10))) {
    local_10 = *(int *)(param_1 + 4) / *(int *)(param_1 + 0x10);
    local_c = *(int *)(param_1 + 8) / *(int *)(param_1 + 0xc);
    local_18 = local_10 * param_3;
    local_14 = local_c * param_4;
    local_8 = this;
    FUN_0049bc60(this,param_1,param_2,&local_18);
  }
  return;
}

