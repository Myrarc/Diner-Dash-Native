/* Native address 00411300; read-only Ghidra audit recovery. */

void __thiscall FUN_00411300(void *this,float param_1)

{
  int iVar1;
  void *_Memory;
  void **ppvVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005744d8;
  local_c = ExceptionList;
  piVar3 = *(int **)((int)this + 0x60);
  ExceptionList = &local_c;
  ppvVar2 = &local_c;
  if (piVar3 != *(int **)((int)this + 100)) {
    do {
      ExceptionList = ppvVar2;
      if ((piVar3[1] != 0) &&
         (piVar3[5] = (int)(param_1 + (float)piVar3[5]),
         *(float *)((int)this + 0x50) < (float)piVar3[5])) {
        piVar3[5] = 0;
        iVar1 = piVar3[1];
        piVar3[1] = iVar1 + -1;
        if (iVar1 + -1 < 1) {
          piVar3[1] = 0;
          if ((*piVar3 == *(int *)((int)this + 0x10)) || (*piVar3 == *(int *)((int)this + 8))) {
            *piVar3 = 0;
          }
          else {
            *piVar3 = *(int *)this;
            uVar4 = FUN_00560568();
            piVar3[2] = (int)uVar4;
            uVar4 = FUN_00560568();
            piVar3[3] = (int)uVar4;
          }
        }
      }
      piVar3 = piVar3 + 6;
      ppvVar2 = ExceptionList;
    } while (piVar3 != *(int **)((int)this + 100));
  }
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  piVar3 = *(int **)((int)this + 0x60);
  local_4 = 0;
  if (piVar3 != *(int **)((int)this + 100)) {
    do {
      if (*piVar3 != 0) {
        FUN_0040ed70(local_1c,piVar3);
      }
      piVar3 = piVar3 + 6;
    } while (piVar3 != *(int **)((int)this + 100));
  }
  _Memory = local_18;
  if (*(void **)((int)this + 0x60) != (void *)0x0) {
    _free(*(void **)((int)this + 0x60));
  }
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 100) = 0;
  *(undefined4 *)((int)this + 0x68) = 0;
  FUN_0040e0e0((void *)((int)this + 0x5c),local_1c);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
  }
  ExceptionList = local_c;
  return;
}

