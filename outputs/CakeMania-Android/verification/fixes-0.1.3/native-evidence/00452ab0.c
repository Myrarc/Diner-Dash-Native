/* Address: 00452ab0; name: FUN_00452ab0 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall FUN_00452ab0(void *this,void *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 ****ppppuVar5;
  void *pvVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [16];
  undefined1 local_80 [4];
  undefined4 ***local_7c [4];
  undefined4 *local_6c;
  uint local_68;
  undefined1 local_64 [4];
  undefined4 ***local_60 [4];
  uint local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 local_2c [4];
  void *pvStack_28;
  uint uStack_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00579970;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  iVar2 = *(int *)((int)this + 0x13c);
  if (iVar2 == 0) {
    ExceptionList = &local_c;
    FUN_00418d20((void *)((int)this + 0x40),param_1,0);
    iVar2 = FUN_00418c60((int)this + 0x40);
    if (iVar2 != 0) {
      FUN_004527b0(this);
      *(undefined4 *)((int)this + 0x13c) = 1;
    }
  }
  else if (iVar2 == 1) {
    ExceptionList = &local_c;
    FUN_00418d20((void *)((int)this + 0x40),param_1,0);
    puVar3 = *(undefined4 **)((int)this + 0x164);
    if (puVar3 != *(undefined4 **)((int)this + 0x168)) {
      do {
        FUN_0049bbe0(param_1,puVar3[4],*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        puVar3 = puVar3 + 5;
      } while (puVar3 != *(undefined4 **)((int)this + 0x168));
    }
    FUN_004c1200(local_2c,"%d");
    local_4 = 0;
    FUN_004c1200(local_48,"%d");
    pvVar6 = *(void **)((int)this + 0x174);
    local_4._0_1_ = 1;
    if (pvVar6 != *(void **)((int)this + 0x178)) {
      do {
        local_4c = 0xf;
        local_50 = 0;
        local_60[0] = (undefined4 ***)((uint)local_60[0] & 0xffffff00);
        FUN_00401e70(local_64,pvVar6,0,0xffffffff);
        local_68 = 0xf;
        local_6c = (undefined4 *)0x0;
        local_7c[0] = (undefined4 ***)((uint)local_7c[0] & 0xffffff00);
        local_4 = CONCAT31(local_4._1_3_,3);
        puVar3 = FUN_00452500(local_64,"[%BAKER_GOAL]",(undefined4 *)0x0,0xd);
        if (-1 < (int)puVar3) {
          FUN_00401940(local_64,(uint)puVar3,0xd);
        }
        uVar7 = 0;
        if (local_50 != 0) {
          if (local_50 == 0) {
            FUN_0055e994();
          }
          do {
            FUN_0040b8b0(local_80,1);
            if (uVar7 == (int)puVar3 - 1U) {
              FUN_00419ec0(local_80,(int)local_2c,0,0xffffffff);
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < local_50);
        }
        uVar7 = 0xffffffff;
        if ((local_50 == 0xffffffff) || (uVar7 = local_50, local_50 != 0)) {
          ppppuVar5 = (undefined4 ****)local_60[0];
          if (local_4c < 0x10) {
            ppppuVar5 = local_60;
          }
          _memmove(ppppuVar5,(void *)((int)ppppuVar5 + uVar7),local_50 - uVar7);
          local_50 = local_50 - uVar7;
          ppppuVar5 = (undefined4 ****)local_60[0];
          if (local_4c < 0x10) {
            ppppuVar5 = local_60;
          }
          *(undefined1 *)((int)ppppuVar5 + local_50) = 0;
        }
        puVar3 = FUN_00452500(local_80,"[%MASTER_BAKER_GOAL]",(undefined4 *)0x0,0x14);
        if (-1 < (int)puVar3) {
          if (local_6c < puVar3) {
            FUN_0055e994();
          }
          uVar4 = (int)local_6c - (int)puVar3;
          uVar7 = 0x14;
          if ((0x13 < uVar4) || (uVar7 = uVar4, uVar4 != 0)) {
            ppppuVar5 = (undefined4 ****)local_7c[0];
            if (local_68 < 0x10) {
              ppppuVar5 = local_7c;
            }
            _memmove((void *)((int)ppppuVar5 + (int)puVar3),
                     (void *)((int)ppppuVar5 + uVar7 + (int)puVar3),
                     (int)local_6c + (-(int)puVar3 - uVar7));
            local_6c = (undefined4 *)((int)local_6c - uVar7);
            ppppuVar5 = (undefined4 ****)local_7c[0];
            if (local_68 < 0x10) {
              ppppuVar5 = local_7c;
            }
            *(undefined1 *)((int)ppppuVar5 + (int)local_6c) = 0;
          }
        }
        puVar8 = (undefined4 *)0x0;
        if (local_6c != (undefined4 *)0x0) {
          if (local_6c == (undefined4 *)0x0) {
            FUN_0055e994();
          }
          do {
            FUN_0040b8b0(local_64,1);
            if (puVar8 == (undefined4 *)((int)puVar3 + -1)) {
              FUN_00419ec0(local_64,(int)local_48,0,0xffffffff);
            }
            puVar8 = (undefined4 *)((int)puVar8 + 1);
          } while (puVar8 < local_6c);
        }
        puVar3 = (undefined4 *)FUN_0048c7b0(auStack_90,0,0,0);
        FUN_00493640(param_1,puVar3);
        uVar1 = *(undefined4 *)(DAT_005b9f04 + 0x10);
        *(undefined4 *)(DAT_005b9f04 + 0x10) = *(undefined4 *)((int)pvVar6 + 0x30);
        uStack_a0 = *(undefined4 *)((int)pvVar6 + 0x20);
        uStack_94 = *(undefined4 *)((int)pvVar6 + 0x2c);
        uStack_98 = *(undefined4 *)((int)pvVar6 + 0x28);
        uStack_9c = *(undefined4 *)((int)pvVar6 + 0x24);
        (**(code **)(*param_2 + 200))(param_1,&uStack_a0,local_64,0xffffffff,0);
        *(undefined4 *)(DAT_005b9f04 + 0x10) = uVar1;
        if (0xf < local_68) {
          _free(local_7c[0]);
        }
        local_68 = 0xf;
        local_6c = (undefined4 *)0x0;
        local_7c[0] = (undefined4 ***)((uint)local_7c[0] & 0xffffff00);
        local_4._0_1_ = 1;
        if (0xf < local_4c) {
          _free(local_60[0]);
        }
        pvVar6 = (void *)((int)pvVar6 + 0x34);
        local_4c = 0xf;
        local_50 = 0;
        local_60[0] = (undefined4 ***)((uint)local_60[0] & 0xffffff00);
      } while (pvVar6 != *(void **)((int)this + 0x178));
    }
    (**(code **)(**(int **)((int)this + 0x38) + 0x40))(1);
    if (0xf < uStack_30) {
      _free(pvStack_44);
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    if (0xf < uStack_14) {
      _free(pvStack_28);
    }
  }
  else if (iVar2 == 2) {
    ExceptionList = &local_c;
    if (*(int **)((int)this + 0x38) != (int *)0x0) {
      ExceptionList = &local_c;
      (**(code **)(**(int **)((int)this + 0x38) + 0x40))(0);
    }
    FUN_00419090((void *)((int)this + 0xa8),param_1,0);
    iVar2 = FUN_00418c60((int)this + 0xa8);
    if ((iVar2 != 0) && (*(int *)((int)this + 0x40) != 0)) {
      FUN_0044aa10(*(int *)(*(int *)((int)this + 0x40) + 0x600));
    }
  }
  ExceptionList = local_c;
  return;
}


