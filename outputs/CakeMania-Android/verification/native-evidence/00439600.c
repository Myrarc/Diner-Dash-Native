/* Address: 00439600; name: FUN_00439600 */

void * __thiscall FUN_00439600(void *this,void *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void **ppvVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  void *_Memory;
  undefined1 local_1c [4];
  void *local_18;
  int *local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00577c78;
  local_c = ExceptionList;
  piVar5 = (int *)0x0;
  _Memory = (void *)0x0;
  local_18 = (void *)0x0;
  local_14 = (int *)0x0;
  local_10 = 0;
  piVar7 = *(int **)((int)this + 0x34);
  local_4 = 0;
  ExceptionList = &local_c;
  ppvVar4 = &local_c;
  if (piVar7 != *(int **)((int)this + 0x38)) {
    do {
      iVar2 = *piVar7;
      if ((*(int *)(iVar2 + 0x60) == 7) &&
         (piVar6 = *(int **)(iVar2 + 0x28), piVar6 != *(int **)(iVar2 + 0x2c))) {
        do {
          piVar1 = (int *)(*piVar6 + 0xac);
          if (*piVar1 != 0) {
            if ((_Memory == (void *)0x0) ||
               ((uint)(local_10 - (int)_Memory >> 2) <= (uint)((int)piVar5 - (int)_Memory >> 2))) {
              FUN_00406b60(local_1c,piVar5,1,piVar1);
              piVar5 = local_14;
              _Memory = local_18;
            }
            else {
              *piVar5 = *piVar1;
              local_14 = piVar5 + 1;
              piVar5 = local_14;
            }
          }
          piVar6 = piVar6 + 1;
        } while (piVar6 != *(int **)(*piVar7 + 0x2c));
      }
      iVar2 = *piVar7;
      iVar3 = *(int *)(iVar2 + 0x60);
      if (((((iVar3 == 4) || (iVar3 == 0)) || (iVar3 == 1)) || ((iVar3 == 2 || (iVar3 == 6)))) &&
         (*(int *)(iVar2 + 0x34) != 0)) {
        if ((_Memory == (void *)0x0) ||
           ((uint)(local_10 - (int)_Memory >> 2) <= (uint)((int)piVar5 - (int)_Memory >> 2))) {
          FUN_00406b60(local_1c,piVar5,1,(int *)(iVar2 + 0x34));
          piVar5 = local_14;
          _Memory = local_18;
        }
        else {
          *piVar5 = *(int *)(iVar2 + 0x34);
          local_14 = piVar5 + 1;
          piVar5 = local_14;
        }
      }
      piVar7 = piVar7 + 1;
      ppvVar4 = ExceptionList;
    } while (piVar7 != *(int **)((int)this + 0x38));
  }
  ExceptionList = ppvVar4;
  FUN_00437f90(param_1,(int)local_1c);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
  }
  ExceptionList = local_c;
  return param_1;
}


