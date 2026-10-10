/* Native address 0046fa80; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0046fa80(int param_1)

{
  uint *puVar1;
  int iVar2;
  void *_Memory;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  undefined1 local_68 [4];
  uint *local_64;
  uint *local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  undefined1 local_34 [4];
  void *local_30;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0057b618;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &local_c;
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x420);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x424);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x428);
  piVar4 = *(int **)(param_1 + 0xb8);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x42c);
  if (piVar4 != *(int **)(param_1 + 0xbc)) {
    do {
      *(bool *)(*piVar4 + 0xd4) = *(int *)(*piVar4 + 0xd8) == 0;
      piVar4 = piVar4 + 1;
    } while (piVar4 != *(int **)(param_1 + 0xbc));
  }
  local_64 = (uint *)0x0;
  local_60 = (uint *)0x0;
  local_5c = 0;
  local_4 = 0;
  if (*(int *)(param_1 + 0x17c) != 0) {
    piVar4 = *(int **)(param_1 + 0xb8);
    if (piVar4 != *(int **)(param_1 + 0xbc)) {
      do {
        local_40 = 0xf;
        local_44 = 0;
        local_54 = (void *)((uint)local_54 & 0xffffff00);
        local_4 = CONCAT31(local_4._1_3_,1);
        FUN_00401e70(local_58,(void *)(*piVar4 + 0xdc),0,0xffffffff);
        local_3c = *(int *)(*piVar4 + 0xd8) + 1;
        FUN_00447c00(local_68,local_58);
        if (0xf < local_40) {
          _free(local_54);
        }
        piVar4 = piVar4 + 1;
        local_40 = 0xf;
        local_44 = 0;
        local_54 = (void *)((uint)local_54 & 0xffffff00);
      } while (piVar4 != *(int **)(param_1 + 0xbc));
    }
    local_1c = 0xf;
    local_20 = 0;
    local_30 = (void *)((uint)local_30 & 0xffffff00);
    local_4 = CONCAT31(local_4._1_3_,2);
    FUN_00401e70(local_34,(void *)(*(int *)(param_1 + 0x174) + 0x9d1c),0,0xffffffff);
    local_18 = *(int *)(*(int *)(param_1 + 0x174) + 4) + 1;
    FUN_00447c00(local_68,local_34);
    *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x178);
    FUN_00444a00((void *)(param_1 + 0x124),(int)local_68,'\0');
    puVar3 = local_60;
    if (local_64 != (uint *)0x0) {
      if (local_64 != local_60) {
        puVar5 = local_64 + 6;
        do {
          if (0xf < *puVar5) {
            _free((void *)puVar5[-5]);
          }
          *puVar5 = 0xf;
          puVar5[-1] = 0;
          *(undefined1 *)(puVar5 + -5) = 0;
          puVar1 = puVar5 + 3;
          puVar5 = puVar5 + 9;
        } while (puVar1 != puVar3);
      }
      _free(local_64);
    }
    iVar2 = *(int *)(param_1 + 0x178);
    local_64 = (uint *)0x0;
    local_60 = (uint *)0x0;
    local_5c = 0;
    if (((iVar2 != 0) && (*(int *)(param_1 + 0x174) != 0)) &&
       (*(int *)(*(int *)(param_1 + 0x174) + 4) == *(int *)(iVar2 + 4))) {
      *(undefined4 *)(param_1 + 0x2c8) = 0;
      *(undefined4 *)(param_1 + 0x2cc) = 0;
      *(undefined4 *)(param_1 + 0x2c4) = 0;
      FUN_00402260(iVar2);
      _Memory = *(void **)(param_1 + 0x178);
      if (_Memory != (void *)0x0) {
        FUN_0044cf50((int)_Memory);
        _free(_Memory);
      }
      *(undefined4 *)(param_1 + 0x178) = 0;
    }
    if (0xf < local_1c) {
      _free(local_30);
    }
    puVar3 = local_60;
    if (local_64 != (uint *)0x0) {
      if (local_64 != local_60) {
        puVar5 = local_64 + 6;
        do {
          if (0xf < *puVar5) {
            _free((void *)puVar5[-5]);
          }
          *puVar5 = 0xf;
          puVar5[-1] = 0;
          *(undefined1 *)(puVar5 + -5) = 0;
          puVar1 = puVar5 + 3;
          puVar5 = puVar5 + 9;
        } while (puVar1 != puVar3);
      }
      _free(local_64);
    }
  }
  ExceptionList = local_c;
  return;
}

