/* Native address 0049bd40; read-only Ghidra audit recovery. */

void __thiscall
FUN_0049bd40(int param_1,int param_2,float param_3,float param_4,undefined8 param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  fVar1 = param_3 + *(float *)(param_1 + 8);
  fVar2 = param_4 + *(float *)(param_1 + 0xc);
  if (param_8 == 0) {
    local_c = *(undefined4 *)(param_2 + 4);
    local_8 = *(undefined4 *)(param_2 + 8);
    local_14 = 0;
    local_10 = 0;
    puVar3 = (undefined4 *)(param_1 + 0x20);
    if (*(char *)(param_1 + 0x38) == '\0') {
      puVar3 = &DAT_005b5504;
    }
    (**(code **)(**(int **)(param_1 + 4) + 0x24))
              (param_2,fVar1,fVar2,&local_14,param_1 + 0x10,puVar3,*(undefined4 *)(param_1 + 0x34),
               param_5,param_6,param_7);
    return;
  }
  puVar3 = (undefined4 *)(param_1 + 0x20);
  if (*(char *)(param_1 + 0x38) == '\0') {
    puVar3 = &DAT_005b5504;
  }
  (**(code **)(**(int **)(param_1 + 4) + 0x24))
            (param_2,fVar1,fVar2,param_8,param_1 + 0x10,puVar3,*(undefined4 *)(param_1 + 0x34),
             param_5,param_6,param_7);
  return;
}

