/* Address: 0041ba80; name: FUN_0041ba80 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0041ba80(int param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  LPCSTR pCVar3;
  int iVar4;
  int iVar5;
  undefined4 in_stack_fffffedc;
  uint in_stack_fffffee0;
  void *pvVar6;
  char cVar7;
  undefined1 auStack_f4 [4];
  void *pvStack_f0;
  undefined1 auStack_e8 [8];
  undefined4 uStack_e0;
  uint uStack_dc;
  int iStack_d8;
  undefined1 auStack_d4 [44];
  int iStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  LPCSTR *appCStack_7c [5];
  uint uStack_68;
  LPCSTR *appCStack_60 [5];
  uint uStack_4c;
  undefined1 auStack_2c [16];
  void *pvStack_1c;
  int iStack_18;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00575034;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  if (*(undefined4 **)(param_1 + 0x600) != (undefined4 *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)**(undefined4 **)(param_1 + 0x600))();
  }
  *(undefined4 *)(param_1 + 0x600) = 0;
  pvVar1 = operator_new(0x468);
  uStack_4 = 0;
  if (pvVar1 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_0044c650(pvVar1,param_1);
  }
  pvVar1 = (void *)(param_1 + 0x638);
  uStack_4 = 0xffffffff;
  *(undefined4 **)(param_1 + 0x600) = puVar2;
  FUN_00421d30(pvVar1,&iStack_d8);
  *(float *)(*(int *)(param_1 + 0x600) + 0x308) = (float)iStack_a8;
  uStack_4 = 1;
  FUN_00401e70((void *)(*(int *)(param_1 + 0x600) + 0x448),auStack_d4,0,0xffffffff);
  *(float *)(*(int *)(param_1 + 0x600) + 0x16c) = (float)iStack_a8;
  *(int *)(*(int *)(param_1 + 0x600) + 0x19c) = param_1 + 0x664;
  pvVar6 = (void *)(in_stack_fffffee0 & 0xffffff00);
  FUN_00401f60(&stack0xfffffedc,(undefined4 *)&DAT_0058161c,0);
  if (uStack_4c < 0x10) {
    appCStack_60[0] = (LPCSTR *)appCStack_60;
  }
  FUN_00405c80(*(void **)(*(int *)(param_1 + 0x600) + 0x1a8),(LPCSTR)appCStack_60[0],
               in_stack_fffffedc,pvVar6);
  *(undefined4 *)(*(int *)(param_1 + 0x600) + 0x1d8) =
       *(undefined4 *)(*(int *)(param_1 + 0x600) + 0x1a8);
  *(int *)(*(int *)(param_1 + 0x600) + 0x1b0) = param_1 + 0x664;
  *(int *)(*(int *)(param_1 + 0x600) + 0x21c) = param_1 + 0x6ac;
  if ((*(int *)(param_1 + 0x6e8) != 0) &&
     (*(uint *)(param_1 + 0x70c) <
      (uint)((*(int *)(param_1 + 0x6ec) - *(int *)(param_1 + 0x6e8)) / 0xbc))) {
    iVar4 = *(uint *)(param_1 + 0x70c) * 0xbc;
    iVar5 = iVar4 + *(int *)(param_1 + 0x6e8);
    if (*(uint *)(iVar4 + 0x8c + *(int *)(param_1 + 0x6e8)) < 0x10) {
      pCVar3 = (LPCSTR)(iVar5 + 0x78);
    }
    else {
      pCVar3 = *(LPCSTR *)(iVar5 + 0x78);
    }
    FUN_004182d0((void *)(*(int *)(param_1 + 0x600) + 0x1fc),pCVar3);
    FUN_00412030((void *)(*(int *)(param_1 + 0x600) + 0x1fc),iStack_d8);
    iVar4 = *(int *)(param_1 + 0x6e8);
    if ((iVar4 != 0) &&
       (*(uint *)(param_1 + 0x70c) < (uint)((*(int *)(param_1 + 0x6ec) - iVar4) / 0xbc))) {
      iVar4 = *(uint *)(param_1 + 0x70c) * 0xbc + iVar4;
      if (*(uint *)(iVar4 + 0x54) < 0x10) {
        pCVar3 = (LPCSTR)(iVar4 + 0x40);
      }
      else {
        pCVar3 = *(LPCSTR *)(iVar4 + 0x40);
      }
      FUN_00410a20((void *)(*(int *)(param_1 + 0x600) + 0x1fc),pCVar3);
      if (uStack_68 < 0x10) {
        appCStack_7c[0] = (LPCSTR *)appCStack_7c;
      }
      FUN_004440a0((void *)(*(int *)(param_1 + 0x600) + 0x1ac),(LPCSTR)appCStack_7c[0],'\x01');
      cVar7 = '\x01';
      iVar4 = FUN_00421870(pvVar1);
      FUN_00444a00((void *)(*(int *)(param_1 + 0x600) + 0x1ac),iVar4 + 0x4c,cVar7);
      FUN_0043a330(*(int *)(param_1 + 0x600) + 0x1ac);
      iVar4 = FUN_00421870(pvVar1);
      iVar4 = *(int *)(iVar4 + 0x50);
      iVar5 = FUN_00421870(pvVar1);
      if (iVar4 != *(int *)(iVar5 + 0x54)) {
        do {
          *(undefined1 *)(iVar4 + 0x20) = 0;
          iVar4 = iVar4 + 0x24;
          iVar5 = FUN_00421870(pvVar1);
        } while (iVar4 != *(int *)(iVar5 + 0x54));
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0x600) + 0x1a4);
      *(undefined4 *)(iVar4 + 0x14) = uStack_a0;
      *(undefined4 *)(iVar4 + 0x18) = uStack_a4;
      iVar4 = FUN_00421870(pvVar1);
      *(undefined4 *)(*(int *)(param_1 + 0x600) + 0x32c) = *(undefined4 *)(iVar4 + 0x3c);
      if (iStack_18 != 0) {
        uStack_dc = 0xf;
        uStack_e0 = 0;
        pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
        FUN_00401e70(auStack_f4,auStack_2c,0,0xffffffff);
        iVar4 = *(int *)(param_1 + 0x600);
        uStack_4._0_1_ = 2;
        FUN_00401e70((void *)(iVar4 + 0x3dc),auStack_f4,0,0xffffffff);
        *(int *)(iVar4 + 0x398) = param_1;
        uStack_4 = CONCAT31(uStack_4._1_3_,1);
        if (0xf < uStack_dc) {
          _free(pvStack_f0);
        }
        *(int *)(*(int *)(param_1 + 0x600) + 0x330) = param_1;
      }
      FUN_004367b0(*(int *)(param_1 + 0x600) + 0x1ac);
      (**(code **)(**(int **)(param_1 + 0x600) + 100))();
      FUN_004d8dc0(*(void **)(param_1 + 0x2e4),*(int **)(param_1 + 0x600));
      FUN_004d1b90(*(void **)(param_1 + 0x2e4),*(int **)(param_1 + 0x600));
      FUN_0041b5a0((int)auStack_e8);
      ExceptionList = pvStack_1c;
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0041a290();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0041a290();
}


