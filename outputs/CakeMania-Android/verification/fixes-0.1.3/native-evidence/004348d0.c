/* Native address 004348d0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Recovered_004348d0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  bool bVar2;
  undefined4 *puVar3;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00577b6b;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0xd2) != '\0') {
    bVar2 = false;
    for (piVar4 = *(int **)(param_1 + 0x28); piVar4 != *(int **)(param_1 + 0x2c);
        piVar4 = piVar4 + 1) {
      if (*(int *)(*piVar4 + 0xac) != 0) {
        bVar2 = true;
      }
    }
    ExceptionList = &pvStack_c;
    if (_DAT_0059d334 < *(float *)(param_1 + 0x68)) {
      fVar1 = *(float *)(param_1 + 0x68) - param_3;
      ExceptionList = &pvStack_c;
      *(float *)(param_1 + 0x68) = fVar1;
      if (fVar1 < _DAT_0059d334 != (fVar1 == _DAT_0059d334)) {
        (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9c48);
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x100) = 0x3f800000;
      }
    }
    if ((_DAT_0059d334 < *(float *)(param_1 + 0x100)) &&
       (param_3 = *(float *)(param_1 + 0x100) - param_3, *(float *)(param_1 + 0x100) = param_3,
       param_3 < _DAT_0059d334)) {
      piVar4 = *(int **)(param_1 + 0x28);
      if (piVar4 != *(int **)(param_1 + 0x2c)) {
        do {
          puVar3 = operator_new(0x3c);
          uStack_4 = 0;
          if (puVar3 == (undefined4 *)0x0) {
            puVar3 = (undefined4 *)0x0;
          }
          else {
            puVar3 = FUN_00407740(puVar3);
          }
          *(undefined4 **)(*piVar4 + 0xac) = puVar3;
          *(undefined4 *)(*(int *)(*piVar4 + 0xac) + 0x18) = 1;
          piVar4 = piVar4 + 1;
          uStack_4 = 0xffffffff;
        } while (piVar4 != *(int **)(param_1 + 0x2c));
      }
      bVar2 = true;
      *(undefined4 *)(param_1 + 0x100) = 0;
    }
    if (((*(float *)(param_1 + 0x68) == _DAT_0059d334) && (!bVar2)) &&
       (*(float *)(param_1 + 0x100) == _DAT_0059d334)) {
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 100);
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9bfc);
    }
  }
  ExceptionList = pvStack_c;
  return;
}

