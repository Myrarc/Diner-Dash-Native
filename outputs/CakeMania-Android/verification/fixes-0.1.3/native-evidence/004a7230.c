/* Address: 004a7230; name: FUN_004a7230 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __thiscall
FUN_004a7230(void *this,int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_48;
  int local_44;
  int local_3c;
  uint local_38;
  int local_34;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar7 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0057d8b8;
  local_10 = ExceptionList;
  uVar2 = *(undefined4 *)((int)this + 0x20);
  uVar3 = *(undefined4 *)((int)this + 0x24);
  uVar4 = *(undefined4 *)((int)this + 0x28);
  uVar5 = *(undefined4 *)((int)this + 0x2c);
  piVar6 = *(int **)((int)this + 0x30);
  ExceptionList = &local_10;
  iVar9 = (**(code **)(*piVar6 + 8))();
  local_34 = (**(code **)(*piVar6 + 4))();
  local_34 = local_34 - iVar9;
  if (param_3 == -1) {
    param_3 = (**(code **)(*piVar6 + 0x18))();
  }
  uVar10 = *(uint *)(param_2 + 0x14);
  uVar14 = 0;
  local_38 = 0xffffffff;
  local_8 = 0;
  local_44 = 0;
  local_48 = local_48 & 0xffffff00;
  local_3c = 0;
  uVar12 = 0;
  if (uVar10 != 0) {
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar9 = param_2 + 4;
      }
      else {
        iVar9 = *(int *)(param_2 + 4);
      }
      bVar1 = *(byte *)(iVar9 + uVar12);
      param_1 = (int *)(uint)bVar1;
      uVar13 = uVar12;
      uVar8 = local_38;
      if (bVar1 == 0x5e) {
        if ((*(char *)((int)this + 0x3a) == '\0') || (uVar10 <= uVar12 + 1)) goto LAB_004a733c;
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          iVar9 = param_2 + 4;
        }
        else {
          iVar9 = *(int *)(param_2 + 4);
        }
        uVar13 = uVar12 + 1;
        if (*(char *)(iVar9 + 1 + uVar12) == '^') goto LAB_004a733c;
        uVar13 = uVar12 + 8;
      }
      else {
        uVar8 = uVar12;
        if ((bVar1 != 0x20) && (uVar8 = local_38, bVar1 == 10)) {
          local_44 = piVar7[2] + 1;
          uVar13 = uVar12 + 1;
          uVar8 = uVar12;
        }
LAB_004a733c:
        local_38 = uVar8;
        iVar9 = (**(code **)(*piVar6 + 0x24))(param_1,local_48);
        local_44 = local_44 + iVar9;
        iVar9 = piVar7[2];
        if (iVar9 < local_44) {
          if (local_38 == 0xffffffff) {
            if ((int)uVar13 < (int)(uVar14 + 1)) {
              uVar13 = uVar13 + 1;
            }
            iVar9 = FUN_004a6f70(this,param_2,*piVar7,piVar7[1] + local_34,iVar9,param_4,'\x01',
                                 uVar14,uVar13 - uVar14);
            if ((param_5 != (int *)0x0) && (*param_5 < iVar9)) {
              *param_5 = iVar9;
            }
          }
          else {
            iVar9 = FUN_004a6f70(this,param_2,*piVar7,piVar7[1] + local_34,iVar9,param_4,'\x01',
                                 uVar14,local_38 - uVar14);
            uVar13 = local_38 + 1;
            if (bVar1 != 10) {
              for (; uVar13 < *(uint *)(param_2 + 0x14); uVar13 = uVar13 + 1) {
                if (*(uint *)(param_2 + 0x18) < 0x10) {
                  iVar11 = param_2 + 4;
                }
                else {
                  iVar11 = *(int *)(param_2 + 4);
                }
                if (*(char *)(iVar11 + uVar13) != ' ') break;
              }
            }
          }
          if (local_3c < iVar9) {
            local_3c = iVar9;
          }
          local_34 = local_34 + param_3;
          local_38 = 0xffffffff;
          local_44 = 0;
          local_48._0_1_ = 0;
          uVar14 = uVar13;
          bVar1 = (byte)local_48;
        }
        else {
          uVar13 = uVar13 + 1;
        }
        local_48 = CONCAT31(local_48._1_3_,bVar1);
      }
      uVar10 = *(uint *)(param_2 + 0x14);
      uVar12 = uVar13;
    } while (uVar13 < uVar10);
  }
  if ((int)uVar14 < *(int *)(param_2 + 0x14)) {
    iVar9 = FUN_004a6f70(this,param_2,*piVar7,piVar7[1] + local_34,piVar7[2],param_4,'\x01',uVar14,
                         *(int *)(param_2 + 0x14) - uVar14);
    if (local_3c < iVar9) {
      local_3c = iVar9;
    }
    if ((param_5 != (int *)0x0) && (*param_5 < iVar9)) {
      *param_5 = iVar9;
    }
    local_34 = local_34 + param_3;
  }
  *(undefined4 *)((int)this + 0x20) = uVar2;
  *(undefined4 *)((int)this + 0x24) = uVar3;
  *(undefined4 *)((int)this + 0x28) = uVar4;
  *(undefined4 *)((int)this + 0x2c) = uVar5;
  if (param_5 != (int *)0x0) {
    *param_5 = local_3c;
  }
  iVar9 = (**(code **)(*piVar6 + 0xc))();
  ExceptionList = local_10;
  return iVar9 + (local_34 - param_3);
}


