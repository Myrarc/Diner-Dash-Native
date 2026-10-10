/* Native address 0044c950; read-only Ghidra audit recovery. */

void __thiscall Recovered_0044c950(void *param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  void *this;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_2c [8];
  undefined1 auStack_24 [24];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0057925b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_004d3f40(param_1,(int)param_2);
  piVar1 = (int *)((int)param_1 + 0x444);
  if (*(int *)((int)param_1 + 0x444) == 0) {
    this = operator_new(0x130);
    uStack_4 = 0;
    if (this == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_004d8b60(this,0,(int)param_1 + 0x80);
    }
    *piVar1 = (int)puVar4;
    *(undefined1 *)((int)puVar4 + 0xfb) = 1;
    uStack_4 = 0xffffffff;
    FUN_00401f60((void *)(*piVar1 + 0x84),(undefined4 *)&DAT_0058161c,0);
    *(undefined4 *)(*piVar1 + 0xac) = DAT_005b99ac;
    *(undefined4 *)(*piVar1 + 0xb0) = DAT_005b99ac;
    *(int *)(*piVar1 + 0xa8) = DAT_005b9dac;
    iVar2 = *(int *)*piVar1;
    uVar5 = FUN_0048c7b0(auStack_2c,0x19,0x5f,0xff);
    (**(code **)(iVar2 + 0x4c))(0,uVar5);
    iVar2 = *(int *)*piVar1;
    uVar5 = FUN_0048c7b0(auStack_24,0x85,0xaa,0xff);
    (**(code **)(iVar2 + 0x4c))(1,uVar5);
    *(undefined1 *)(*piVar1 + 0x74) = 1;
    iVar2 = *(int *)*piVar1;
    uVar5 = FUN_00493710(DAT_005b9dac);
    uVar6 = FUN_00493700(DAT_005b9dac);
    iVar7 = FUN_00493710(DAT_005b9dac);
    iVar8 = 0x23d - iVar7 / 2;
    iVar7 = FUN_00493700(DAT_005b9dac);
    (**(code **)(iVar2 + 100))(0x43 - iVar7 / 2,iVar8,uVar6,uVar5);
    (**(code **)(*(int *)*piVar1 + 0x40))(0);
  }
  FUN_004d8dc0(param_2,(int *)*piVar1);
  iVar2 = *(int *)((int)param_1 + 0x8c);
  if ((iVar2 != 0) &&
     ((uint)(*(int *)((int)param_1 + 0x90) - iVar2 >> 2) <
      (uint)(*(int *)((int)param_1 + 0x94) - iVar2 >> 2))) {
    piVar3 = *(int **)((int)param_1 + 0x90);
    *piVar3 = *piVar1;
    *(int **)((int)param_1 + 0x90) = piVar3 + 1;
    ExceptionList = pvStack_c;
    return;
  }
  FUN_0041b000((void *)((int)param_1 + 0x88),*(undefined4 **)((int)param_1 + 0x90),1,piVar1);
  ExceptionList = pvStack_c;
  return;
}

