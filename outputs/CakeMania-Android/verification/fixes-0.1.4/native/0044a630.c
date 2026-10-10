/* Native address 0044a630; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Recovered_0044a630(int param_1,void *param_2)

{
  void *this;
  
  if (((DAT_005ba070 != 0) && (*(float *)(DAT_005ba070 + 0x428) == _DAT_0059d334)) &&
     (*(int *)(DAT_005ba070 + 0x2d4) == 0)) {
    this = *(void **)(DAT_005ba070 + 0x1a8);
    if (*(float *)((int)this + 0x1c) <= _DAT_00586b90) {
      if (param_1 == 0) {
        FUN_00402df0(this,param_2,'\0');
      }
    }
    else if (param_1 == 1) {
      FUN_00402df0(this,param_2,'\0');
      return;
    }
  }
  return;
}

