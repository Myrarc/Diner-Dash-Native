/* Address: 0041f580; name: FUN_0041f580 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_0041f580(void *this,char param_1)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_2c [4];
  void *local_28;
  int local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00575463;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  if (param_1 == '\0') {
    iVar6 = *(int *)((int)this + 0x710) + -1 + *(int *)((int)this + 0x70c) * 0xc;
    bVar1 = true;
    ExceptionList = &local_c;
    FUN_004517e0(local_2c,(int)this,"TutorialScreen/levels.xml",iVar6);
    pvVar3 = (void *)((int)this + 0x638);
    local_4 = 0;
    iVar2 = FUN_00421870(pvVar3);
    piVar4 = *(int **)(iVar2 + 0x20);
    iVar2 = FUN_00421870(pvVar3);
    if (piVar4 != *(int **)(iVar2 + 0x24)) {
      do {
        if (*piVar4 == iVar6) {
          bVar1 = false;
        }
        piVar4 = piVar4 + 1;
        iVar2 = FUN_00421870(pvVar3);
      } while (piVar4 != *(int **)(iVar2 + 0x24));
    }
    if ((local_18 == 0) || (!bVar1)) {
      FUN_0041f290((int)this);
    }
    else {
      FUN_0041c210(this,iVar6);
    }
    if (0xf < local_14) {
      _free(local_28);
    }
  }
  else {
    ExceptionList = &local_c;
    pvVar3 = operator_new(900);
    local_4 = 1;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_00467a40(pvVar3,this);
    }
    iVar6 = *(int *)((int)this + 0x88);
    pvVar3 = (void *)0x0;
    *(int **)((int)this + 0x608) = piVar4;
    uVar5 = 0;
    local_4 = 0xffffffff;
    (**(code **)(*piVar4 + 100))();
    FUN_00421c80((void *)((int)this + 0x638),&stack0xffffffb0);
    FUN_004696a0(*(void **)((int)this + 0x608),uVar5,pvVar3,iVar6);
    FUN_00401e70((void *)(*(int *)((int)this + 0x608) + 0x114),(void *)((int)this + 0x638),0,
                 0xffffffff);
    FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x608));
    FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x608));
  }
  ExceptionList = local_c;
  return;
}


