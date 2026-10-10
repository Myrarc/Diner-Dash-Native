/* Native address 0041eb90; read-only Ghidra audit recovery. */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_0041eb90(void *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  LPCSTR pCVar6;
  int iVar7;
  float10 fVar8;
  undefined4 in_stack_fffffef8;
  uint in_stack_fffffefc;
  void *pvVar9;
  undefined1 local_d8 [4];
  undefined1 local_d4 [44];
  int local_a8;
  LPCSTR *local_7c [5];
  uint local_68;
  LPCSTR *local_60 [5];
  uint local_4c;
  undefined1 auStack_2c [20];
  int iStack_18;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00575413;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  pvVar2 = (void *)((int)this + 0x638);
  ExceptionList = &local_c;
  FUN_00401e70(pvVar2,(void *)(*(int *)((int)this + 0x608) + 0x114),0,0xffffffff);
  *(undefined4 *)((int)this + 0x608) = 0;
  if (param_1 == 4) {
    iVar1 = FUN_00421870(pvVar2);
    if (*(void **)(iVar1 + 0x20) != (void *)0x0) {
      _free(*(void **)(iVar1 + 0x20));
    }
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(undefined4 *)((int)this + 0x710) = 1;
    *(undefined4 *)((int)this + 0x70c) = 0;
  }
  else {
    if (param_1 == 1) {
      if (*(undefined4 **)((int)this + 0x61c) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)((int)this + 0x61c))();
      }
      pvVar2 = operator_new(0x1a8);
      local_4 = 0;
      if (pvVar2 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_0041e7a0(pvVar2,this);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)((int)this + 0x61c) = puVar4;
      FUN_0045a0e0(puVar4,"HelpScreen/help_screen.xml");
      (**(code **)(**(int **)((int)this + 0x61c) + 100))();
      FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x61c));
      FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x61c));
      ExceptionList = local_c;
      return;
    }
    if (param_1 == 2) {
      if (*(undefined4 **)((int)this + 0x620) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)((int)this + 0x620))();
      }
      pvVar2 = operator_new(0x1a8);
      local_4 = 1;
      if (pvVar2 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_0041eab0(pvVar2,this);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)((int)this + 0x620) = puVar4;
      FUN_00457dd0(puVar4,"CreditsScreen/credits_screen.xml");
      (**(code **)(**(int **)((int)this + 0x620) + 100))();
      FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x620));
      FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x620));
      ExceptionList = local_c;
      return;
    }
    if (param_1 == 3) {
      if (*(undefined4 **)((int)this + 0x624) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)((int)this + 0x624))();
      }
      pvVar2 = operator_new(0x2b0);
      local_4 = 2;
      if (pvVar2 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_0045e680(pvVar2,this);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)((int)this + 0x624) = puVar4;
      FUN_0045eb00(puVar4,"HighScoresScreen/hscores_screen.xml");
      (**(code **)(**(int **)((int)this + 0x624) + 100))();
      FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x624));
      FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x624));
      ExceptionList = local_c;
      return;
    }
    if (param_1 != 0) {
      ExceptionList = local_c;
      return;
    }
  }
  if (*(int *)((int)this + 0x714) == 0) {
    iVar1 = *(int *)((int)this + 0x710);
    if (param_1 == 4) {
      iVar1 = iVar1 + -1;
    }
    if ((iVar1 == 0) && (*(int *)((int)this + 0x70c) == 0)) {
      FUN_0041c100(this,(undefined ***)0x0);
    }
    else {
      FUN_0041c460(this);
    }
  }
  else if (*(int *)((int)this + 0x714) == 1) {
    pvVar3 = operator_new(0x468);
    local_4 = 3;
    if (pvVar3 == (void *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_0044c650(pvVar3,this);
    }
    *(undefined4 **)((int)this + 0x600) = puVar4;
    local_4 = 0xffffffff;
    *(undefined4 *)((int)this + 0x710) = 1;
    FUN_00421d30(pvVar2,local_d8);
    *(float *)(*(int *)((int)this + 0x600) + 0x308) = (float)local_a8;
    local_4 = 4;
    FUN_00401e70((void *)(*(int *)((int)this + 0x600) + 0x448),local_d4,0,0xffffffff);
    *(int *)(*(int *)((int)this + 0x600) + 0x19c) = (int)this + 0x664;
    *(int *)(*(int *)((int)this + 0x600) + 0x1b0) = (int)this + 0x664;
    *(int *)(*(int *)((int)this + 0x600) + 0x21c) = (int)this + 0x6ac;
    if (local_68 < 0x10) {
      local_7c[0] = (LPCSTR *)local_7c;
    }
    FUN_004440a0((void *)(*(int *)((int)this + 0x600) + 0x1ac),(LPCSTR)local_7c[0],'\x01');
    pvVar3 = (void *)((int)this + 0x6f4);
    iVar1 = FUN_0041af50(pvVar3,*(uint *)((int)this + 0x70c));
    iVar7 = *(int *)(iVar1 + 100);
    iVar5 = FUN_0041af50(pvVar3,*(uint *)((int)this + 0x70c));
    iVar7 = iVar7 * 0x1c;
    iVar1 = iVar5 + 0x68 + iVar7;
    if (*(uint *)(iVar5 + 0x80 + iVar7) < 0x10) {
      pCVar6 = (LPCSTR)(iVar1 + 4);
    }
    else {
      pCVar6 = *(LPCSTR *)(iVar1 + 4);
    }
    FUN_004182d0((void *)(*(int *)((int)this + 0x600) + 0x1fc),pCVar6);
    iVar1 = FUN_00421870(pvVar2);
    fVar8 = FUN_00411f80(*(int *)((int)this + 0x600) + 0x1fc,*(float *)(iVar1 + 0x6c));
    *(float *)(*(int *)((int)this + 0x600) + 0x30c) = (float)fVar8;
    iVar1 = FUN_0041af50(pvVar3,*(uint *)((int)this + 0x70c));
    if (*(uint *)(iVar1 + 0x44) < 0x10) {
      pCVar6 = (LPCSTR)(iVar1 + 0x30);
    }
    else {
      pCVar6 = *(LPCSTR *)(iVar1 + 0x30);
    }
    FUN_00410a20((void *)(*(int *)((int)this + 0x600) + 0x1fc),pCVar6);
    pvVar9 = (void *)(in_stack_fffffefc & 0xffffff00);
    FUN_00401f60(&stack0xfffffef8,(undefined4 *)&DAT_0058161c,0);
    if (local_4c < 0x10) {
      local_60[0] = (LPCSTR *)local_60;
    }
    FUN_00405c80(*(void **)(*(int *)((int)this + 0x600) + 0x1a8),(LPCSTR)local_60[0],
                 in_stack_fffffef8,pvVar9);
    iVar1 = FUN_0041af50(pvVar3,*(uint *)((int)this + 0x70c));
    iVar1 = *(int *)(iVar1 + 100);
    iVar7 = FUN_00421870(pvVar2);
    *(undefined4 *)(*(int *)((int)this + 0x600) + 0x32c) = *(undefined4 *)(iVar7 + 0x88 + iVar1 * 4)
    ;
    (**(code **)(**(int **)((int)this + 0x600) + 100))();
    FUN_004367b0(*(int *)((int)this + 0x600) + 0x1ac);
    iVar1 = FUN_00421870(pvVar2);
    *(undefined4 *)(*(int *)((int)this + 0x600) + 0x168) = *(undefined4 *)(iVar1 + 0x6c);
    if (iStack_18 != 0) {
      pvVar9 = (void *)((uint)pvVar9 & 0xffffff00);
      FUN_00401e70(&stack0xfffffef8,auStack_2c,0,0xffffffff);
      FUN_0041a4d0((void *)(*(int *)((int)this + 0x600) + 0x398),this,in_stack_fffffef8,pvVar9);
      *(void **)(*(int *)((int)this + 0x600) + 0x330) = this;
    }
    FUN_004d8dc0(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x600));
    FUN_004d1b90(*(void **)((int)this + 0x2e4),*(int **)((int)this + 0x600));
    FUN_0041b5a0((int)local_d8);
  }
  ExceptionList = local_c;
  return;
}

