/* Address: 00436d50; name: FUN_00436d50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00436d50(void *this,void *param_1,float param_2)

{
  void *this_00;
  float fVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  ulonglong uVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00577c1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((*(float *)((int)this + 0x68) == *(float *)((int)this + 100)) &&
     (ExceptionList = &pvStack_c, *(int *)((int)this + 0xf8) == 0)) {
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*(int *)DAT_005ba088[0x118] + 0x24))(DAT_005b9918);
    *(int **)((int)this + 0xf8) = piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))(1,0);
    }
  }
  if ((_DAT_0059d334 < *(float *)((int)this + 0x68)) &&
     (fVar1 = *(float *)((int)this + 0x68) - param_2, *(float *)((int)this + 0x68) = fVar1,
     fVar1 < _DAT_0059d334)) {
    *(undefined4 *)((int)this + 0x68) = 0;
  }
  if (((*(float *)((int)this + 0x68) != _DAT_0059d334) &&
      (*(float *)((int)this + 0x118) < *(float *)((int)this + 100) - *(float *)((int)this + 0x68)))
     && (*(int *)((int)this + 0x34) == 0)) {
    if (*(int **)((int)this + 0xf8) != (int *)0x0) {
      (**(code **)(**(int **)((int)this + 0xf8) + 0x20))();
      (**(code **)(**(int **)((int)this + 0xf8) + 4))();
      *(undefined4 *)((int)this + 0xf8) = 0;
    }
    puVar3 = operator_new(0x3c);
    uStack_4 = 0;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_00407740(puVar3);
    }
    *(undefined4 **)((int)this + 0x34) = puVar3;
    puVar3[6] = 0;
    uStack_4 = 0xffffffff;
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9ec0);
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b99e0);
  }
  fVar1 = *(float *)((int)this + 100) - *(float *)((int)this + 0x68);
  if (((*(float *)((int)this + 0x114) <= fVar1) && (fVar1 < *(float *)((int)this + 0x118))) &&
     (iVar4 = *(int *)((int)this + 0x34), iVar4 != 0)) {
    uVar5 = FUN_00560568();
    FUN_00419b40(*(void **)(DAT_005ba088[0x180] + 0x1a4),iVar4,
                 *(int *)((int)this + 0x1c) / 2 + *(int *)((int)this + 0x4c),(int)uVar5);
    piVar2 = DAT_005ba088 + 0x180;
    iVar4 = FUN_00419510(*(int *)((int)this + 0x34));
    *(int *)(*piVar2 + 0x31c) = iVar4 + *(int *)(*piVar2 + 0x31c);
    FUN_004367f0(param_1,*(void **)((int)this + 0x34));
    *(undefined4 *)((int)this + 0x34) = 0;
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9d88);
  }
  this_00 = *(void **)((int)this + 0xfc);
  if (this_00 != (void *)0x0) {
    if (*(char *)((int)this_00 + 0xa0) != '\0') {
      FUN_00436ca0((int)this_00);
      _free(this_00);
      *(undefined4 *)((int)this + 0xfc) = 0;
      ExceptionList = pvStack_c;
      return;
    }
    FUN_004255f0(this_00,param_2);
  }
  ExceptionList = pvStack_c;
  return;
}


