/* Native address 0049fc20; read-only Ghidra audit recovery. */

undefined8 __thiscall FUN_0049fc20(void *this,uint param_1,byte param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  ulonglong uVar5;
  int local_8;
  
  (**(code **)(*(int *)this + 0x58))();
  uVar2 = (uint)*(byte *)((param_1 & 0xff) + 0x60 + *(int *)((int)this + 0x14));
  local_8 = 0;
  cVar3 = '\0';
  if (param_2 != 0) {
    cVar3 = *(char *)(param_2 + 0x60 + *(int *)((int)this + 0x14));
  }
  piVar4 = (int *)**(int **)((int)this + 0x34);
  iVar1 = 0;
  if (piVar4 != *(int **)((int)this + 0x34)) {
    do {
      if (*(int *)(piVar4[3] + 0x12060) == 0) {
        uVar5 = FUN_00560568();
        _param_2 = (int)uVar5;
        if (cVar3 == '\0') {
LAB_0049fd12:
          uVar5 = uVar5 & 0xffffffff00000000;
        }
        else {
          uVar5 = FUN_00560568();
        }
      }
      else {
        uVar5 = FUN_00560568();
        _param_2 = (int)uVar5;
        if (cVar3 == '\0') goto LAB_0049fd12;
        uVar5 = FUN_00560568();
      }
      uVar2 = (uint)(uVar5 >> 0x20);
      _param_2 = (int)uVar5 + _param_2;
      if (local_8 < _param_2) {
        local_8 = _param_2;
      }
      piVar4 = (int *)*piVar4;
      iVar1 = local_8;
    } while (piVar4 != (int *)*(int *)((int)this + 0x34));
  }
  return CONCAT44(uVar2,iVar1);
}

