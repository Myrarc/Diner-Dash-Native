/* Address: 00453a50; name: FUN_00453a50 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00453a50(void *this,void *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 in_stack_fffffeb4;
  undefined4 *in_stack_fffffeb8;
  undefined1 auStack_130 [4];
  undefined1 local_12c;
  undefined4 uStack_128;
  undefined1 local_e4 [4];
  void *local_e0;
  undefined4 local_d0;
  uint local_cc;
  undefined1 local_c8 [4];
  void *local_c4;
  undefined4 local_b4;
  uint local_b0;
  undefined1 local_ac [4];
  void *local_a8;
  undefined4 local_98;
  uint local_94;
  undefined1 local_90 [4];
  void *local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined1 local_74 [4];
  void *local_70;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_58 [4];
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_3c [16];
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00579aa6;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  iVar2 = *(int *)((int)this + 0x134);
  if (iVar2 == 0) {
    ExceptionList = &local_c;
    FUN_00418d20((void *)((int)this + 0x60),param_1,0);
    iVar2 = FUN_00418c60((int)this + 0x60);
    if (iVar2 != 0) {
      FUN_00453170((int)this);
      *(undefined4 *)((int)this + 0x134) = 1;
    }
  }
  else if (iVar2 == 1) {
    ExceptionList = &local_c;
    FUN_00418d20((int *)((int)this + 0x60),param_1,0);
    iVar2 = (*(int *)((int)this + 400) + 0x15) * 0x10;
    puVar4 = *(undefined4 **)(iVar2 + 4 + (int)this);
    if (puVar4 != *(undefined4 **)((int)this + iVar2 + 8)) {
      do {
        uStack_128 = 0x453b3c;
        FUN_0049bbe0(param_1,puVar4[4],*puVar4,puVar4[1],puVar4[2],puVar4[3]);
        puVar4 = puVar4 + 5;
      } while (puVar4 != *(undefined4 **)((*(int *)((int)this + 400) + 0x15) * 0x10 + 8 + (int)this)
              );
    }
    iVar2 = (*(int *)((int)this + 400) + 0x17) * 0x10;
    pvVar5 = *(void **)(iVar2 + 4 + (int)this);
    if (pvVar5 != *(void **)((int)this + iVar2 + 8)) {
      do {
        local_14 = 0xf;
        local_18 = 0;
        local_28 = (void *)((uint)local_28 & 0xffffff00);
        FUN_00401e70(local_2c,pvVar5,0,0xffffffff);
        local_4 = 0;
        if (*(int *)((int)this + 0x5c) != 0) {
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%CUSTOMERS_LOST_MONEY]",0x17);
          local_4._0_1_ = 1;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_90,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 2;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4._0_1_ = 0;
          if (0xf < local_78) {
            _free(local_8c);
          }
          local_78 = 0xf;
          local_7c = 0;
          local_8c = (void *)((uint)local_8c & 0xffffff00);
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%CAKES_SERVED]",0xf);
          local_4._0_1_ = 3;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_c8,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 4;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4._0_1_ = 0;
          if (0xf < local_b0) {
            _free(local_c4);
          }
          local_b0 = 0xf;
          local_b4 = 0;
          local_c4 = (void *)((uint)local_c4 & 0xffffff00);
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%CAKES_LOST]",0xd);
          local_4._0_1_ = 5;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_ac,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 6;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4._0_1_ = 0;
          if (0xf < local_94) {
            _free(local_a8);
          }
          local_94 = 0xf;
          local_98 = 0;
          local_a8 = (void *)((uint)local_a8 & 0xffffff00);
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%CUSTOMER_TIP]",0xf);
          local_4._0_1_ = 7;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_74,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 8;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4._0_1_ = 0;
          if (0xf < local_5c) {
            _free(local_70);
          }
          local_5c = 0xf;
          local_60 = 0;
          local_70 = (void *)((uint)local_70 & 0xffffff00);
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%TOTAL_LEVEL_MONEY]",0x14);
          local_4._0_1_ = 9;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_58,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 10;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4._0_1_ = 0;
          if (0xf < local_40) {
            _free(local_54);
          }
          local_40 = 0xf;
          local_44 = 0;
          local_54 = (void *)((uint)local_54 & 0xffffff00);
          local_12c = 0;
          FUN_00401f60(auStack_130,(undefined4 *)"[%TOTAL_MONEY]",0xe);
          local_4._0_1_ = 0xb;
          in_stack_fffffeb8 = (undefined4 *)((uint)in_stack_fffffeb8 & 0xffffff00);
          FUN_00401e70(&stack0xfffffeb4,local_2c,0,0xffffffff);
          local_4._0_1_ = 0;
          pvVar3 = FUN_00452f80(local_e4,in_stack_fffffeb4,in_stack_fffffeb8);
          local_4._0_1_ = 0xc;
          FUN_00401e70(local_2c,pvVar3,0,0xffffffff);
          local_4 = (uint)local_4._1_3_ << 8;
          if (0xf < local_cc) {
            _free(local_e0);
          }
          local_cc = 0xf;
          local_d0 = 0;
          local_e0 = (void *)((uint)local_e0 & 0xffffff00);
        }
        puVar4 = (undefined4 *)FUN_0048c7b0(local_3c,0,0,0);
        FUN_00493640(param_1,puVar4);
        FUN_00493630(param_1,DAT_005b9e30);
        uVar1 = *(undefined4 *)(DAT_005b9e30 + 0x10);
        *(undefined4 *)(DAT_005b9e30 + 0x10) = *(undefined4 *)((int)pvVar5 + 0x30);
        uStack_128 = 0x454038;
        (**(code **)(*param_2 + 200))();
        *(undefined4 *)(DAT_005b9e30 + 0x10) = uVar1;
        local_4 = 0xffffffff;
        if (0xf < local_14) {
          _free(local_28);
        }
        pvVar5 = (void *)((int)pvVar5 + 0x34);
        local_14 = 0xf;
        local_18 = 0;
        local_28 = (void *)((uint)local_28 & 0xffffff00);
      } while (pvVar5 != *(void **)(*(int *)((int)this + 400) * 0x10 + 0x178 + (int)this));
    }
    if (*(int **)((int)this + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)((int)this + 0x54) + 0x40))();
    }
    if (((*(int **)((int)this + 0x58) != (int *)0x0) &&
        (iVar2 = *(int *)((int)this + 0x60), iVar2 != 0)) &&
       (iVar2 = *(int *)(*(int *)(iVar2 + 0x600) + 0x1a4),
       *(int *)(iVar2 + 0x18) <= *(int *)(iVar2 + 0x10))) {
      (**(code **)(**(int **)((int)this + 0x58) + 0x40))();
    }
  }
  else if (iVar2 == 2) {
    ExceptionList = &local_c;
    if (*(int **)((int)this + 0x54) != (int *)0x0) {
      ExceptionList = &local_c;
      (**(code **)(**(int **)((int)this + 0x54) + 0x40))();
    }
    if (*(int **)((int)this + 0x58) != (int *)0x0) {
      (**(code **)(**(int **)((int)this + 0x58) + 0x40))();
    }
    FUN_00418d20((void *)((int)this + 200),param_1,0);
    iVar2 = FUN_00418c60((int)this + 200);
    if ((iVar2 != 0) && (*(int *)((int)this + 0x60) != 0)) {
      FUN_0044d0d0(*(void **)(*(int *)((int)this + 0x60) + 0x600),0x7d);
    }
  }
  ExceptionList = local_c;
  return;
}


