/* Address: 0044d570; name: FUN_0044d570 */

void __fastcall FUN_0044d570(void *param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  LPCSTR pCVar4;
  undefined4 uVar5;
  void *pvStack_20;
  undefined1 local_1c [4];
  int *local_18;
  int *local_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00579473;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00439600((void *)((int)param_1 + 0x1ac),local_1c);
  local_4 = 0;
  if (local_18 != local_14) {
    do {
      iVar2 = FUN_00419510(*local_18);
      *(int *)((int)param_1 + 0x31c) = *(int *)((int)param_1 + 0x31c) + iVar2 * 2;
      FUN_00419460(*(void **)((int)param_1 + 0x1a4),iVar2 * 2);
      local_18 = local_18 + 1;
    } while (local_18 != local_14);
  }
  (**(code **)(**(int **)((int)param_1 + 0x444) + 0x40))(0);
  iVar2 = *(int *)(*(int *)((int)param_1 + 0x1a4) + 0x10);
  *(int *)((int)param_1 + 0x324) = *(int *)((int)param_1 + 0x324) + iVar2;
  *(int *)((int)param_1 + 0x328) = iVar2;
  iVar2 = FUN_00421870((void *)(*(int *)((int)param_1 + 0x84) + 0x638));
  *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + *(int *)((int)param_1 + 0x328);
  iVar2 = FUN_00421870((void *)(*(int *)((int)param_1 + 0x84) + 0x638));
  *(int *)(iVar2 + 0x48) = *(int *)(iVar2 + 0x48) + *(int *)((int)param_1 + 0x328);
  if ((((*(int *)((int)param_1 + 0x84) == 0) ||
       (*(int *)(*(int *)((int)param_1 + 0x1a4) + 0x18) <=
        *(int *)(*(int *)((int)param_1 + 0x1a4) + 0x10))) ||
      (iVar2 = FUN_00421870((void *)(*(int *)((int)param_1 + 0x84) + 0x638)), uVar5 = DAT_005b9f3c,
      *(int *)(iVar2 + 0x3c) != 1)) &&
     (((iVar2 = *(int *)((int)param_1 + 0x84), iVar2 == 0 ||
       (*(int *)(*(int *)((int)param_1 + 0x1a4) + 0x10) <
        *(int *)(*(int *)((int)param_1 + 0x1a4) + 0x18))) ||
      ((*(int *)(iVar2 + 0x70c) != 3 || (uVar5 = DAT_005b9954, *(int *)(iVar2 + 0x710) != 0xc))))))
  {
    pvVar3 = operator_new(0x194);
    puStack_8._0_1_ = 1;
    if (pvVar3 == (void *)0x0) {
      pvVar3 = (void *)0x0;
    }
    else {
      pvVar3 = FUN_0044cca0(pvVar3);
    }
    *(void **)((int)param_1 + 0x2d8) = pvVar3;
    *(undefined4 *)((int)pvVar3 + 0x148) = *(undefined4 *)(*(int *)((int)param_1 + 0x84) + 0x70c);
    *(int *)(*(int *)((int)param_1 + 0x2d8) + 0x14c) =
         *(int *)(*(int *)((int)param_1 + 0x84) + 0x710) + -1;
    *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 0x130) = *(undefined4 *)((int)param_1 + 0x84);
    iVar1 = *(int *)((int)param_1 + 0x84);
    iVar2 = *(int *)(iVar1 + 0x6e8);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if ((iVar2 == 0) ||
       ((uint)((*(int *)(iVar1 + 0x6ec) - iVar2) / 0xbc) <= *(uint *)(iVar1 + 0x70c))) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    iVar2 = *(uint *)(iVar1 + 0x70c) * 0xbc + 0x58 + iVar2;
    if (*(uint *)(iVar2 + 0x18) < 0x10) {
      pCVar4 = (LPCSTR)(iVar2 + 4);
    }
    else {
      pCVar4 = *(LPCSTR *)(iVar2 + 4);
    }
    FUN_00454c50(*(void **)((int)param_1 + 0x2d8),pCVar4);
    *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 0x60) = *(undefined4 *)((int)param_1 + 0x84);
    *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 200) = *(undefined4 *)((int)param_1 + 0x84);
    *(undefined1 *)(*(int *)((int)param_1 + 0x2d8) + 0xac) = 0;
    *(undefined1 *)((int)param_1 + 0x18d) = 1;
    *(undefined4 *)((int)param_1 + 0x174) = 0;
    *(undefined1 *)((int)param_1 + 0x2e4) = 1;
    if (*(int **)((int)param_1 + 0x444) != (int *)0x0) {
      (**(code **)(**(int **)((int)param_1 + 0x444) + 0x40))(0);
    }
    if (*(int **)((int)param_1 + 0x43c) != (int *)0x0) {
      (**(code **)(**(int **)((int)param_1 + 0x43c) + 0xe4))(DAT_005b9f04);
    }
    if (*(int **)((int)param_1 + 0x440) != (int *)0x0) {
      (**(code **)(**(int **)((int)param_1 + 0x440) + 0xe4))(DAT_005b9f04);
    }
    if (*(int *)(*(int *)((int)param_1 + 0x1a4) + 0x10) <
        *(int *)(*(int *)((int)param_1 + 0x1a4) + 0x18)) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 400) = 1;
      *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 0x58) = 0;
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9f3c);
    }
    else {
      *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 400) = 0;
      *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 0x58) = *(undefined4 *)((int)param_1 + 0x440)
      ;
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9954);
    }
    *(undefined4 *)(*(int *)((int)param_1 + 0x2d8) + 0x54) = *(undefined4 *)((int)param_1 + 0x43c);
    *(int *)(*(int *)((int)param_1 + 0x2d8) + 0x5c) = (int)param_1 + 0x310;
  }
  else {
    (**(code **)(*DAT_005ba088 + 0xc4))(uVar5);
    FUN_0044d0d0(param_1,0);
  }
  if (pvStack_20 != (void *)0x0) {
    _free(pvStack_20);
  }
  ExceptionList = local_14;
  return;
}


