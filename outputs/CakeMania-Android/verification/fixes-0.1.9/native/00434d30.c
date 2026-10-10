/* Address: 00434d30; name: FUN_00434d30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00434d30(void *this,void *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float fVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  ulonglong uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,1);
    puVar5 = (undefined4 *)FUN_0048c7e0(&local_20,0,0,0,0x7a);
    FUN_00493640(param_1,puVar5);
  }
  iVar13 = *(int *)((int)this + 4);
  local_20 = (double)param_2;
  uVar12 = FUN_00560568();
  local_10 = (undefined4)uVar12;
  uVar12 = FUN_00560568();
  local_c = (undefined4)uVar12;
  uVar12 = FUN_00560568();
  local_8 = (undefined4)uVar12;
  uVar12 = FUN_00560568();
  local_4 = (undefined4)uVar12;
  if (((*(char *)((int)this + 0xd1) == '\0') && (*(char *)((int)this + 0xd0) != '\0')) ||
     (*(char *)((int)this + 0xd0) == '\0')) {
    uVar12 = FUN_00560568();
    uVar6 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    uVar14 = (undefined4)uVar12;
    FUN_00560568();
    uVar12 = FUN_00560568();
    uVar15 = (undefined4)uVar12;
    FUN_00560568();
    uVar12 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar13,(int)uVar12,uVar15,uVar14,uVar6);
  }
  if (*(float *)((int)this + 0x68) <= _DAT_0059d334) {
    if ((((*(char *)((int)this + 0xd1) != '\0') || (*(char *)((int)this + 0xd0) == '\0')) &&
        (*(char *)((int)this + 0xd0) != '\0')) || (*(int *)((int)this + 0x104) == 0))
    goto LAB_004353e7;
    FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,0);
    iVar13 = *(int *)((int)this + 0x104);
    uVar12 = FUN_00560568();
    uVar6 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    uVar14 = (undefined4)uVar12;
    FUN_00560568();
LAB_004353b7:
    uVar12 = FUN_00560568();
    uVar15 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar13,(int)uVar12,uVar15,uVar14,uVar6);
    goto LAB_004353e7;
  }
  fVar2 = *(float *)((int)this + 100) - *(float *)((int)this + 0x68);
  if (fVar2 < *(float *)((int)this + 0x118)) {
    iVar13 = *(int *)((int)this + 8);
    uVar12 = FUN_00560568();
    uVar6 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    uVar14 = (undefined4)uVar12;
    FUN_00560568();
    uVar12 = FUN_00560568();
    uVar15 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar13,(int)uVar12,uVar15,uVar14,uVar6);
  }
  pfVar3 = *(float **)((int)this + 0x34);
  if (pfVar3 != (float *)0x0) {
    fVar4 = (float)*(int *)((int)this + 0x20) * _DAT_00581420;
    fVar1 = *(float *)((int)this + 0x40);
    iVar13 = *(int *)((int)this + 0x50);
    *pfVar3 = (float)*(int *)((int)this + 0x1c) * _DAT_00581420 + *(float *)((int)this + 0x3c) +
              (float)*(int *)((int)this + 0x4c);
    pfVar3[1] = fVar4 + fVar1 + (float)iVar13;
  }
  if (fVar2 < *(float *)((int)this + 0x108)) {
    FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,0);
    if (*(void **)((int)this + 0x34) != (void *)0x0) {
      FUN_00406570(*(void **)((int)this + 0x34),param_1);
    }
    goto LAB_004353e7;
  }
  if ((fVar2 < *(float *)((int)this + 0x108)) || (*(float *)((int)this + 0x10c) <= fVar2)) {
    if ((fVar2 < *(float *)((int)this + 0x10c)) || (*(float *)((int)this + 0x110) <= fVar2)) {
      if ((fVar2 < *(float *)((int)this + 0x110)) || (*(float *)((int)this + 0x114) <= fVar2)) {
        if ((fVar2 < *(float *)((int)this + 0x114)) || (*(float *)((int)this + 0x118) <= fVar2)) {
          if (fVar2 < *(float *)((int)this + 0x118)) goto LAB_004353e7;
          *(undefined1 *)((int)this + 0x11c) = 0;
          FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,0);
          pfVar3 = *(float **)((int)this + 0x34);
          if (pfVar3 != (float *)0x0) {
            fVar2 = fVar2 - *(float *)((int)this + 0x118);
            fVar4 = *(float *)((int)this + 100) - *(float *)((int)this + 0x118);
            fVar1 = (fVar2 * _DAT_0058187c) / fVar4 - _DAT_0058187c;
            *pfVar3 = ((fVar2 * _DAT_00585fd0) / fVar4 - _DAT_00585fd0) + *pfVar3;
            pfVar3[1] = fVar1 + pfVar3[1];
            FUN_00406570(*(void **)((int)this + 0x34),param_1);
          }
          iVar13 = *(int *)((int)this + 0xc);
          uVar12 = FUN_00560568();
          uVar6 = (undefined4)uVar12;
          uVar12 = FUN_00560568();
          uVar14 = (undefined4)uVar12;
          FUN_00560568();
          goto LAB_004353b7;
        }
        if ((*(int *)((int)this + 0x34) == 0) && (*(char *)((int)this + 0x11c) == '\0')) {
          FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,0);
          goto LAB_004353e7;
        }
        uVar12 = FUN_00560568();
        iVar13 = (int)uVar12;
        goto LAB_00435040;
      }
      if ((*(int *)((int)this + 0x34) != 0) && (*(char *)((int)this + 0x11c) != '\0')) {
        FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,4);
        uVar12 = FUN_00560568();
        local_20 = (double)CONCAT44(local_20._4_4_,(int)uVar12);
        uVar12 = FUN_00560568();
        local_20 = (double)CONCAT44((int)uVar12,(undefined4)local_20);
        uVar12 = FUN_00560568();
        local_18 = (undefined4)uVar12;
        uVar12 = FUN_00560568();
        local_14 = (undefined4)uVar12;
        uVar12 = FUN_00560568();
        FUN_0049eff0(param_1,DAT_005b97b4,(int)&local_20,(int)uVar12);
        goto LAB_004353e7;
      }
    }
    else if ((*(int *)((int)this + 0x34) != 0) && (*(char *)((int)this + 0x11c) != '\0')) {
      FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,4);
      puVar5 = *(undefined4 **)((int)this + 0x34);
      fVar4 = (fVar2 - *(float *)((int)this + 0x10c)) * _DAT_00581914;
      fVar2 = *(float *)((int)this + 0x114);
      fVar1 = *(float *)((int)this + 0x10c);
      *puVar5 = *puVar5;
      puVar5[1] = fVar4 / (fVar2 - fVar1) + (float)puVar5[1];
      FUN_00406570(*(void **)((int)this + 0x34),param_1);
      goto LAB_004353e7;
    }
    FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,0);
  }
  else {
    if (*(int *)((int)this + 0x34) != 0) {
      uVar12 = FUN_00560568();
      FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,(int)uVar12);
      FUN_00406570(*(void **)((int)this + 0x34),param_1);
      *(undefined1 *)((int)this + 0x11c) = 1;
      goto LAB_004353e7;
    }
    iVar13 = 0;
LAB_00435040:
    FUN_0049eff0(param_1,DAT_005b9c08,(int)&local_10,iVar13);
  }
LAB_004353e7:
  iVar13 = *(int *)((int)this + 0x100);
  if ((iVar13 != 0) &&
     (((*(char *)((int)this + 0xd1) == '\0' && (*(char *)((int)this + 0xd0) != '\0')) ||
      (*(char *)((int)this + 0xd0) == '\0')))) {
    uVar12 = FUN_00560568();
    uVar6 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    uVar14 = (undefined4)uVar12;
    FUN_00560568();
    uVar12 = FUN_00560568();
    uVar15 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    FUN_0049bbe0(param_1,iVar13,(int)uVar12,uVar15,uVar14,uVar6);
  }
  pfVar3 = *(float **)((int)this + 0x34);
  if ((pfVar3 != (float *)0x0) && (*(float *)((int)this + 0x68) == _DAT_0059d334)) {
    fVar2 = (float)*(int *)((int)this + 0x1c) * _DAT_00581420 + *(float *)((int)this + 0x3c) +
            (float)*(int *)((int)this + 0x4c);
    fVar1 = (float)*(int *)((int)this + 0x20) * _DAT_00581420 + *(float *)((int)this + 0x40) +
            (float)*(int *)((int)this + 0x50);
    *pfVar3 = fVar2;
    local_20 = (double)CONCAT44(fVar1,fVar2);
    pfVar3[1] = fVar1;
    FUN_00406570(*(void **)((int)this + 0x34),param_1);
  }
  iVar13 = DAT_005b9f40;
  if (((_DAT_0059d334 < *(float *)((int)this + 0x68)) &&
      (*(float *)((int)this + 0x68) < *(float *)((int)this + 100))) &&
     (*(float *)((int)this + 100) != _DAT_0059d334)) {
    uVar12 = FUN_00560568();
    local_20 = (double)CONCAT44(local_20._4_4_,(int)uVar12);
    uVar12 = FUN_00560568();
    local_20 = (double)CONCAT44((int)uVar12,(undefined4)local_20);
    local_14 = 0x1e;
    local_18 = 0x1e;
    uVar12 = FUN_00560568();
    FUN_0049eff0(param_1,iVar13,(int)&local_20,(int)uVar12);
  }
  if ((*(int *)((int)this + 0x104) != 0) &&
     (piVar11 = *(int **)((int)this + 0x28), piVar11 != *(int **)((int)this + 0x2c))) {
    do {
      iVar13 = *piVar11;
      if (*(char *)(iVar13 + 0x68) == '\0') {
        if (((*(char *)((int)this + 0xd1) == '\0') && (*(char *)(iVar13 + 0x74) != '\0')) ||
           (*(char *)(iVar13 + 0x74) == '\0')) {
          uVar12 = FUN_00560568();
          uVar6 = (undefined4)uVar12;
          uVar12 = FUN_00560568();
          uVar14 = (undefined4)uVar12;
          uVar12 = FUN_00560568();
          uVar15 = (undefined4)uVar12;
          uVar12 = FUN_00560568();
          FUN_0049bbe0(param_1,*(int *)(iVar13 + 0x20),(int)uVar12,uVar15,uVar14,uVar6);
        }
        if ((*(float *)((int)this + 0x68) != _DAT_0059d334) &&
           (iVar13 = *piVar11, *(int *)((int)this + 0x6c) == *(int *)(iVar13 + 0x48))) {
          iVar10 = *(int *)(iVar13 + 0x44) + 8;
          iVar9 = *(int *)(iVar13 + 0x40) + 8;
          iVar7 = *(int *)(iVar13 + 0x3c) + -4 + *(int *)((int)this + 0x50);
          iVar8 = *(int *)(iVar13 + 0x38) + -4 + *(int *)((int)this + 0x4c);
          iVar13 = *(int *)(iVar13 + 0x24);
          goto LAB_0043571a;
        }
      }
      else {
        if ((*(float *)((int)this + 0x68) == _DAT_0059d334) ||
           (*(int *)((int)this + 0x6c) == *(int *)(iVar13 + 0x48))) {
          iVar10 = *(int *)(iVar13 + 0x44) + 8;
          iVar9 = *(int *)(iVar13 + 0x40) + 8;
          iVar7 = *(int *)(iVar13 + 0x3c) + -4 + *(int *)((int)this + 0x50);
          iVar8 = *(int *)(iVar13 + 0x38) + -4 + *(int *)((int)this + 0x4c);
          iVar13 = *(int *)(iVar13 + 0x24);
        }
        else {
          uVar12 = FUN_00560568();
          iVar10 = (int)uVar12;
          uVar12 = FUN_00560568();
          iVar9 = (int)uVar12;
          uVar12 = FUN_00560568();
          iVar7 = (int)uVar12;
          uVar12 = FUN_00560568();
          iVar8 = (int)uVar12;
          iVar13 = *(int *)(iVar13 + 0x20);
        }
LAB_0043571a:
        FUN_0049bbe0(param_1,iVar13,iVar8,iVar7,iVar9,iVar10);
      }
      iVar13 = *piVar11;
      if (*(char *)(iVar13 + 0x69) != '\0') {
        FUN_0049bbe0(param_1,DAT_005b9618,
                     *(int *)(iVar13 + 0x40) / 2 + *(int *)(iVar13 + 0x38) + -0xf +
                     *(int *)((int)this + 0x4c),
                     *(int *)(iVar13 + 0x44) / 2 + *(int *)(iVar13 + 0x3c) + -0xf +
                     *(int *)((int)this + 0x50),0x1e,0x1e);
      }
      piVar11 = piVar11 + 1;
    } while (piVar11 != *(int **)((int)this + 0x2c));
  }
  if (*(void **)((int)this + 0xfc) != (void *)0x0) {
    FUN_00425870(*(void **)((int)this + 0xfc),param_1);
  }
  if (*(char *)((int)this + 0x70) != '\0') {
    uVar15 = 0x1e;
    uVar14 = 0x1e;
    uVar12 = FUN_00560568();
    uVar6 = (undefined4)uVar12;
    uVar12 = FUN_00560568();
    FUN_0049bbe0(param_1,DAT_005b9618,(int)uVar12,uVar6,uVar14,uVar15);
  }
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,0);
    puVar5 = (undefined4 *)FUN_0048c7e0(&local_20,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar5);
  }
  return;
}


