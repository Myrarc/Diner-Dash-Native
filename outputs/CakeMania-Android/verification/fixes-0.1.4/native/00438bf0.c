/* Address: 00438bf0; name: FUN_00438bf0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00438bf0(void *this,void *param_1)

{
  float fVar1;
  float *pfVar2;
  void *this_00;
  float fVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  ulonglong uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  float local_24;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,1);
    puVar4 = (undefined4 *)FUN_0048c7e0(&local_10,0,0,0,0x7a);
    FUN_00493640(param_1,puVar4);
  }
  if (((*(char *)((int)this + 0xd1) == '\0') && (*(char *)((int)this + 0xd0) != '\0')) ||
     (*(char *)((int)this + 0xd0) == '\0')) {
    uVar9 = FUN_00560568();
    uVar5 = (undefined4)uVar9;
    uVar9 = FUN_00560568();
    uVar10 = (undefined4)uVar9;
    FUN_00560568();
    uVar9 = FUN_00560568();
    uVar11 = (undefined4)uVar9;
    FUN_00560568();
    uVar9 = FUN_00560568();
    FUN_0049bbe0(param_1,*(int *)((int)this + 4),(int)uVar9,uVar11,uVar10,uVar5);
  }
  pfVar2 = *(float **)((int)this + 0x34);
  if (pfVar2 != (float *)0x0) {
    fVar3 = (float)*(int *)((int)this + 0x20) * _DAT_00581420;
    iVar7 = *(int *)((int)this + 0x50);
    fVar1 = *(float *)((int)this + 0x40);
    *pfVar2 = (float)*(int *)((int)this + 0x1c) * _DAT_00581420 + (float)*(int *)((int)this + 0x4c)
              + *(float *)((int)this + 0x3c);
    pfVar2[1] = fVar3 + (float)iVar7 + fVar1;
    FUN_00406570(*(void **)((int)this + 0x34),param_1);
  }
  if ((((*(char *)((int)this + 0xd1) == '\0') && (*(char *)((int)this + 0xd0) != '\0')) ||
      (*(char *)((int)this + 0xd0) == '\0')) &&
     (piVar8 = *(int **)((int)this + 0x28), piVar8 != *(int **)((int)this + 0x2c))) {
    do {
      this_00 = (void *)*piVar8;
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      if (*(int *)((int)this_00 + 0x2c) != 0) {
        iVar7 = *(int *)(*(int *)((int)this_00 + 0x2c) + 0x10);
        local_24 = (float)(iVar7 + -1);
        if ((*(float *)((int)this + 0x68) != _DAT_0059d334) &&
           (*(int *)((int)this + 0x6c) == *(int *)((int)this_00 + 0x48))) {
          uVar9 = FUN_00438540(this_00,*(float *)((int)this + 100) - *(float *)((int)this + 0x68),
                               *(float *)((int)this + 100),iVar7,1,1,'\0',1.8);
          local_24 = (float)(int)uVar9;
        }
        if (*(int *)((int)this + 0x6c) == *(int *)(*piVar8 + 0x48)) {
          if (local_24 == _DAT_005814a8) {
            if (*(char *)((int)this + 0x101) == '\0') {
              (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9ee0);
              *(undefined1 *)((int)this + 0x101) = 1;
            }
          }
          else {
            *(undefined1 *)((int)this + 0x101) = 0;
          }
          if (local_24 == _DAT_0058148c) {
            if (*(char *)((int)this + 0x100) == '\0') {
              (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9860);
              *(undefined1 *)((int)this + 0x100) = 1;
            }
          }
          else {
            *(undefined1 *)((int)this + 0x100) = 0;
          }
        }
        iVar7 = *piVar8;
        uVar9 = FUN_00560568();
        local_10 = (undefined4)uVar9;
        uVar9 = FUN_00560568();
        local_c = (undefined4)uVar9;
        FUN_00493700(*(int *)(iVar7 + 0x2c));
        uVar9 = FUN_00560568();
        local_8 = (undefined4)uVar9;
        iVar7 = *piVar8;
        FUN_00493710(*(int *)(iVar7 + 0x2c));
        uVar9 = FUN_00560568();
        local_4 = (undefined4)uVar9;
        if ((*(float *)((int)this + 0x68) == _DAT_0059d334) ||
           (*(int *)((int)this + 0x6c) != *(int *)(iVar7 + 0x48))) {
          uVar9 = FUN_00560568();
          uVar5 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          uVar10 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          uVar11 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          FUN_0049bbe0(param_1,*(int *)(iVar7 + 0x20),(int)uVar9,uVar11,uVar10,uVar5);
        }
        else {
          uVar9 = FUN_00560568();
          FUN_0049eff0(param_1,*(int *)(iVar7 + 0x2c),(int)&local_10,(int)uVar9);
        }
        iVar7 = *piVar8;
        if (*(char *)(iVar7 + 0x68) == '\0') {
          if ((*(int *)(iVar7 + 0x2c) == 0) &&
             (((*(char *)((int)this + 0xd1) == '\0' && (*(char *)(iVar7 + 0x74) != '\0')) ||
              (*(char *)(iVar7 + 0x74) == '\0')))) {
            uVar9 = FUN_00560568();
            uVar5 = (undefined4)uVar9;
            uVar9 = FUN_00560568();
            uVar10 = (undefined4)uVar9;
            uVar9 = FUN_00560568();
            uVar11 = (undefined4)uVar9;
            uVar9 = FUN_00560568();
            uVar6 = (undefined4)uVar9;
            iVar7 = *(int *)(iVar7 + 0x20);
LAB_004390c3:
            FUN_0049bbe0(param_1,iVar7,uVar6,uVar11,uVar10,uVar5);
          }
        }
        else if (*(float *)((int)this + 0x68) == _DAT_0059d334) {
          uVar9 = FUN_00560568();
          uVar5 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          uVar10 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          uVar11 = (undefined4)uVar9;
          uVar9 = FUN_00560568();
          uVar6 = (undefined4)uVar9;
          iVar7 = *(int *)(iVar7 + 0x24);
          goto LAB_004390c3;
        }
      }
      iVar7 = *piVar8;
      if (*(char *)(iVar7 + 0x69) != '\0') {
        FUN_0049bbe0(param_1,DAT_005b9618,
                     *(int *)(iVar7 + 0x40) / 2 + *(int *)(iVar7 + 0x38) + -0xf +
                     *(int *)((int)this + 0x4c),
                     *(int *)(iVar7 + 0x44) / 2 + *(int *)(iVar7 + 0x3c) + -0xf +
                     *(int *)((int)this + 0x50),0x1e,0x1e);
      }
      piVar8 = piVar8 + 1;
    } while (piVar8 != *(int **)((int)this + 0x2c));
  }
  if (*(char *)((int)this + 0x70) != '\0') {
    uVar11 = 0x1e;
    uVar10 = 0x1e;
    uVar9 = FUN_00560568();
    uVar5 = (undefined4)uVar9;
    uVar9 = FUN_00560568();
    FUN_0049bbe0(param_1,DAT_005b9618,(int)uVar9,uVar5,uVar10,uVar11);
  }
  iVar7 = DAT_005b9f40;
  if (((*(int *)((int)this + 0x34) != 0) && (_DAT_0059d334 < *(float *)((int)this + 0x68))) &&
     ((*(float *)((int)this + 0x68) < *(float *)((int)this + 100) &&
      (*(float *)((int)this + 100) != _DAT_0059d334)))) {
    uVar9 = FUN_00560568();
    local_10 = (undefined4)uVar9;
    uVar9 = FUN_00560568();
    local_c = (undefined4)uVar9;
    local_4 = 0x1e;
    local_8 = 0x1e;
    uVar9 = FUN_00560568();
    FUN_0049eff0(param_1,iVar7,(int)&local_10,(int)uVar9);
  }
  if (*(void **)((int)this + 0xfc) != (void *)0x0) {
    FUN_00425870(*(void **)((int)this + 0xfc),param_1);
  }
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,0);
    puVar4 = (undefined4 *)FUN_0048c7e0(&local_10,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar4);
  }
  return;
}


