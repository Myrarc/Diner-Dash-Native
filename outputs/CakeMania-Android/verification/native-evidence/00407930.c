/* Address: 00407930; name: FUN_00407930 */

int * __thiscall FUN_00407930(void *this,undefined4 *param_1,void *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint3 uVar7;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar8;
  int *piVar9;
  int **ppiVar10;
  int *piVar11;
  int *local_f0;
  int local_e4;
  int local_ac [4];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c [4];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int *local_4c [8];
  int *local_2c [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00573f4e;
  local_c = ExceptionList;
  puVar3 = ExceptionList;
  ExceptionList = &local_c;
  if (param_1 == (undefined4 *)0x0) {
    ExceptionList = &local_c;
    puVar3 = operator_new(0x3c);
    local_4 = param_1;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      param_1 = puVar3;
    }
    else {
      puVar3 = FUN_00407740(puVar3);
      param_1 = puVar3;
    }
  }
  local_4 = (undefined4 *)0xffffffff;
  uVar7 = (uint3)((uint)puVar3 >> 8);
  piVar4 = (int *)CONCAT31(uVar7,1);
  if ((((param_1[0xc] == 0) || ((int)(param_1[0xd] - param_1[0xc]) >> 2 == 0)) ||
      (*(int *)(*(int *)(param_1[0xd] + -4) + 0x2c) != 2)) &&
     ((param_1[0xc] != 0 && ((int)(param_1[0xd] - param_1[0xc]) >> 2 != 0)))) {
    piVar4 = (int *)((uint)uVar7 << 8);
  }
  else {
    local_e4 = -1;
    if ((param_1[0xc] != 0) && ((int)(param_1[0xd] - param_1[0xc]) >> 2 != 0)) {
      local_e4 = *(int *)(**(int **)((int)this + 0x30) + 0x28);
    }
    piVar9 = *(int **)((int)this + 0x30);
    if (piVar9 != *(int **)((int)this + 0x34)) {
LAB_00407a10:
      iVar8 = *(int *)(*piVar9 + 0x2c);
      if (iVar8 != 0) {
        if (iVar8 != 2) {
          if (iVar8 == 3) {
            local_f0 = (int *)0x0;
LAB_00407a37:
            iVar8 = local_ac[1];
            piVar11 = (int *)0x0;
            do {
              iVar6 = *(int *)((int)param_2 + 0x18);
              if ((iVar6 == 0) ||
                 (piVar4 = (int *)(*(int *)((int)param_2 + 0x1c) - iVar6 >> 2), piVar4 <= piVar11))
              goto LAB_00407b0c;
              if ((iVar6 == 0) || ((int *)(*(int *)((int)param_2 + 0x1c) - iVar6 >> 2) <= piVar11))
              {
LAB_00407f76:
                    /* WARNING: Subroutine does not return */
                FUN_00406800();
              }
              uVar1 = *(uint *)(iVar6 + (int)piVar11 * 4);
              iVar6 = *(int *)((int)param_2 + 8);
              if ((iVar6 == 0) || ((uint)(*(int *)((int)param_2 + 0xc) - iVar6 >> 2) <= uVar1)) {
LAB_00407f7d:
                    /* WARNING: Subroutine does not return */
                FUN_00406800();
              }
              piVar4 = *(int **)(iVar6 + uVar1 * 4);
              if (*piVar4 == local_e4) goto LAB_00407aa4;
              piVar11 = (int *)((int)piVar11 + 1);
            } while( true );
          }
          goto LAB_00407f5e;
        }
        local_f0 = (int *)0x0;
        while( true ) {
          iVar8 = local_6c[1];
          piVar11 = (int *)0x0;
          while( true ) {
            iVar6 = *(int *)((int)param_2 + 0x18);
            if ((iVar6 == 0) ||
               (piVar4 = (int *)(*(int *)((int)param_2 + 0x1c) - iVar6 >> 2), piVar4 <= piVar11))
            goto LAB_00407cf2;
            if ((iVar6 == 0) || ((int *)(*(int *)((int)param_2 + 0x1c) - iVar6 >> 2) <= piVar11))
            goto LAB_00407f76;
            uVar1 = *(uint *)(iVar6 + (int)piVar11 * 4);
            piVar4 = *(int **)((int)param_2 + 8);
            if ((piVar4 == (int *)0x0) ||
               ((uint)(*(int *)((int)param_2 + 0xc) - (int)piVar4 >> 2) <= uVar1))
            goto LAB_00407f7d;
            if (*(int *)piVar4[uVar1] == local_e4) break;
            piVar11 = (int *)((int)piVar11 + 1);
          }
          if ((*(int *)((int)param_2 + 0x28) == 0) ||
             (piVar4 = (int *)(*(int *)((int)param_2 + 0x2c) - *(int *)((int)param_2 + 0x28) >> 2),
             piVar4 <= local_f0)) break;
          FUN_00406d40(param_2,local_2c,local_e4,2,(uint)local_f0);
          piVar4 = *(int **)(*piVar9 + 4);
          if ((piVar4 == local_2c[0]) || (piVar4 == local_2c[1])) {
            ppiVar10 = local_2c;
            piVar11 = local_6c;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *piVar11 = (int)*ppiVar10;
              ppiVar10 = ppiVar10 + 1;
              piVar11 = piVar11 + 1;
            }
          }
          local_f0 = (int *)((int)local_f0 + 1);
        }
LAB_00407cf2:
        if (local_6c[1] == 0) goto LAB_00407e2b;
        puVar5 = operator_new(0x30);
        puVar3 = (undefined4 *)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar5[6] = 0;
          puVar5[7] = 0;
          puVar5[9] = 0;
          puVar5[8] = 0;
          *puVar5 = &PTR_FUN_00581544;
          puVar5[6] = 0;
          puVar5[7] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar5[0xb] = 2;
          puVar3 = puVar5;
        }
        if ((param_1[0xc] == 0) || ((int)(param_1[0xd] - param_1[0xc]) >> 2 != 1)) {
          (**(code **)*puVar3)(iVar8);
          puVar3[4] = local_58;
          puVar3[5] = local_54;
        }
        else {
          (**(code **)*puVar3)(local_6c[0]);
          puVar3[4] = local_6c[3];
          puVar3[5] = local_5c;
        }
        iVar8 = FUN_00493710(puVar3[1]);
        iVar6 = FUN_00493700(puVar3[1]);
        puVar3[6] = (float)iVar6;
        puVar3[7] = (float)iVar8;
        puVar3[9] = *(undefined4 *)(*piVar9 + 0x24);
        puVar3[10] = *(undefined4 *)(*(int *)(*(int *)((int)this + 0x34) + -4) + 0x28);
        iVar8 = local_50;
        goto LAB_00407e10;
      }
      FUN_00406d40(param_2,&local_8c,*(int *)(*piVar9 + 0x28),0,0);
      local_e4 = *(int *)(*piVar9 + 0x28);
      puVar5 = operator_new(0x30);
      puVar3 = (undefined4 *)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        puVar5[2] = 0;
        puVar5[3] = 0;
        puVar5[6] = 0;
        puVar5[7] = 0;
        puVar5[9] = 0;
        puVar5[8] = 0;
        puVar5[0xb] = 0;
        *puVar5 = &PTR_FUN_00581544;
        puVar5[6] = 0;
        puVar5[7] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        puVar3 = puVar5;
      }
      if ((param_1[0xc] == 0) || ((int)(param_1[0xd] - param_1[0xc]) >> 2 == 0)) {
        (**(code **)*puVar3)(local_8c);
        puVar3[4] = local_80;
        puVar3[5] = local_7c;
      }
      else {
        (**(code **)*puVar3)(local_88);
        puVar3[4] = local_78;
        puVar3[5] = local_74;
      }
      iVar8 = FUN_00493710(puVar3[1]);
      iVar6 = FUN_00493700(puVar3[1]);
      puVar3[7] = (float)iVar8;
      puVar3[6] = (float)iVar6;
      puVar3[10] = *(undefined4 *)(*piVar9 + 0x28);
      uVar2 = *(undefined4 *)(*piVar9 + 0x24);
      puVar3[8] = (float)local_70;
      puVar3[9] = uVar2;
      piVar4 = (int *)FUN_00407870(param_1,(int)puVar3);
      goto LAB_00407f5e;
    }
  }
  ExceptionList = local_c;
  return piVar4;
LAB_00407aa4:
  if ((*(int *)((int)param_2 + 0x38) == 0) ||
     (piVar4 = (int *)(*(int *)((int)param_2 + 0x3c) - *(int *)((int)param_2 + 0x38) >> 2),
     piVar4 <= local_f0)) goto LAB_00407b0c;
  FUN_00406d40(param_2,local_4c,local_e4,3,(uint)local_f0);
  piVar4 = *(int **)(*piVar9 + 4);
  if ((piVar4 == local_4c[0]) || (piVar4 == local_4c[1])) {
    ppiVar10 = local_4c;
    piVar11 = local_ac;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *piVar11 = (int)*ppiVar10;
      ppiVar10 = ppiVar10 + 1;
      piVar11 = piVar11 + 1;
    }
  }
  local_f0 = (int *)((int)local_f0 + 1);
  goto LAB_00407a37;
LAB_00407b0c:
  if (local_ac[1] == 0) {
LAB_00407e2b:
    piVar4 = (int *)((uint)piVar4 & 0xffffff00);
  }
  else {
    puVar5 = operator_new(0x30);
    puVar3 = (undefined4 *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[9] = 0;
      puVar5[8] = 0;
      *puVar5 = &PTR_FUN_00581544;
      puVar5[6] = 0;
      puVar5[7] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[0xb] = 3;
      puVar3 = puVar5;
    }
    if ((param_1[0xc] == 0) || ((int)(param_1[0xd] - param_1[0xc]) >> 2 != 2)) {
      (**(code **)*puVar3)(iVar8);
      puVar3[4] = local_98;
      puVar3[5] = local_94;
    }
    else {
      (**(code **)*puVar3)(local_ac[0]);
      puVar3[4] = local_ac[3];
      puVar3[5] = local_9c;
    }
    iVar8 = FUN_00493710(puVar3[1]);
    iVar6 = FUN_00493700(puVar3[1]);
    puVar3[7] = (float)iVar8;
    puVar3[6] = (float)iVar6;
    puVar3[9] = *(undefined4 *)(*piVar9 + 0x24);
    puVar3[10] = *(undefined4 *)(*(int *)(*(int *)((int)this + 0x34) + -4) + 0x28);
    iVar8 = local_90;
LAB_00407e10:
    puVar3[8] = (float)iVar8;
    piVar4 = (int *)FUN_00407870(param_1,(int)puVar3);
  }
LAB_00407f5e:
  piVar9 = piVar9 + 1;
  if (piVar9 == *(int **)((int)this + 0x34)) {
    ExceptionList = local_c;
    return piVar4;
  }
  goto LAB_00407a10;
}


