/* Native address 0044ab40. Recovered in read-only Ghidra session. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Recovered_0044ab40(void *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                       void *param_5,float param_6,float param_7,int param_8,undefined4 param_9)

{
  void *pvVar1;
  void *this;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  int in_stack_ffffffa4;
  undefined4 in_stack_ffffffa8;
  undefined4 in_stack_ffffffac;
  int in_stack_ffffffb0;
  undefined4 auStack_20 [5];
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  this = param_5;
  iVar6 = param_4;
  pvVar1 = param_1;
  if (param_8 == 1) goto switchD_0044ab68_caseD_2;
  switch(param_9) {
  case 1:
    *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = param_2;
    break;
  case 4:
    if (*(float *)(param_4 + 0x68) != _DAT_0059d334) break;
    if ((*(int *)(param_4 + 0x34) != 0) &&
       (uVar3 = FUN_004011f0(*(int *)(param_4 + 0x34) + 0x2c), iVar7 = DAT_005ba070, uVar3 < 4)) {
      iVar4 = FUN_004011f0(*(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) + 0x2c);
      if ((iVar4 == 1) && (*(int *)(iVar6 + 0x60) == 1)) {
        FUN_00406d40(*(void **)(iVar7 + 0x19c),auStack_20,
                     *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 0x1a8) + 0x9cf0) + 0x34) +
                                      -4) + 0x28),0,0);
        puVar2 = operator_new(0x30);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = (undefined4 *)FUN_004061e0(puVar2);
        }
        (**(code **)*puVar2)();
        puVar2[4] = uStack_c;
        puVar2[5] = uStack_8;
        FUN_00406190((int)puVar2);
        puVar2[10] = *(undefined4 *)
                      (*(int *)(*(int *)(*(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) + 0x34) +
                               -4) + 0x28);
        puVar2[9] = *(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) + 0x34) +
                              -4) + 0x24);
        puVar2[8] = (float)iStack_4;
        uVar5 = FUN_00407870(*(void **)(iVar6 + 0x34),(int)puVar2);
        if ((char)uVar5 != '\0') {
          FUN_004367f0((void *)(DAT_005ba070 + 0x2c0),
                       *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0));
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
          *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 100);
          FUN_00436000((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
          (**(code **)(*DAT_005ba088 + 0xc4))();
        }
      }
      break;
    }
    FUN_00401520(&stack0xffffffa4,&param_1);
    uVar3 = FUN_0044aae0(in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,in_stack_ffffffb0);
    iVar6 = param_4;
    if ((char)uVar3 == '\0') {
      (**(code **)(*DAT_005ba088 + 0xc4))();
      break;
    }
    if ((*(int *)(param_4 + 0x34) != 0) &&
       (uVar3 = FUN_004011f0(*(int *)(param_4 + 0x34) + 0x2c), 3 < uVar3)) break;
    *(void **)(iVar6 + 0x34) = param_1;
    *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
    *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 100);
    FUN_00436000((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
    goto LAB_0044b3c7;
  case 5:
    if (((*(int *)(param_4 + 0x34) == 0) &&
        (iVar7 = *(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0), iVar7 != 0)) &&
       ((iVar4 = *(int *)(param_4 + 0x60), iVar4 != 7 && (iVar4 != 8)))) {
      if ((*(int *)((int)param_1 + 0x18) == 1) || (iVar4 == 6)) {
        if (iVar4 == 3) {
          *(int *)(param_4 + 0x34) = iVar7;
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
        }
        else if ((iVar4 == 6) && (iVar4 = FUN_004011f0(iVar7 + 0x2c), iVar4 == 1)) {
          *(int *)(iVar6 + 0x34) = iVar7;
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
          (**(code **)(*DAT_005ba088 + 0xc4))();
        }
      }
      else {
        FUN_00401520(&stack0xffffffa4,&param_1);
        uVar3 = FUN_0044aae0(in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,in_stack_ffffffb0
                            );
        iVar6 = param_4;
        if ((char)uVar3 == '\0') {
          (**(code **)(*DAT_005ba088 + 0xc4))();
          iVar6 = param_4;
        }
        else {
          *(undefined4 *)(param_4 + 0x34) = *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0)
          ;
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
          (**(code **)(*DAT_005ba088 + 0xc4))();
        }
      }
      if (*(int *)(iVar6 + 0x60) == 3) {
        (**(code **)(*DAT_005ba088 + 0xc4))();
        pvVar1 = param_1;
        *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(iVar6 + 100);
        if (*(int *)((int)param_1 + 0x18) != 1) {
          iVar7 = FUN_00419510((int)param_1);
          *(int *)(DAT_005ba070 + 0x31c) = *(int *)(DAT_005ba070 + 0x31c) + iVar7;
          uVar5 = *(undefined4 *)(iVar6 + 0x50);
          uVar8 = FUN_00560568();
          FUN_00419b40(*(void **)(DAT_005ba070 + 0x1a4),(int)pvVar1,(int)uVar8,uVar5);
        }
      }
    }
    if (*(int *)(iVar6 + 0x60) == 7) {
      iVar6 = FUN_004361f0((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
      if (((iVar6 == 0) || (*(int *)(iVar6 + 0xac) != 0)) || (*(int *)((int)param_1 + 0x18) == 1)) {
        (**(code **)(*DAT_005ba088 + 0xc4))();
      }
      else {
        *(undefined4 *)(iVar6 + 0xac) = *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0);
        *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
        (**(code **)(*DAT_005ba088 + 0xc4))();
      }
    }
    break;
  case 6:
    if (*(char *)((int)param_5 + 0x300) != '\0') break;
    if (*(int *)((int)param_1 + 0x18) == 1) {
      FUN_0040a190((int)param_5);
    }
    else {
      iVar6 = FUN_00419510((int)param_1);
      *(int *)((int)this + 0x1c4) = iVar6;
      *(undefined1 *)((int)this + 0x26d) = 1;
      FUN_0040a170(this,2);
      (**(code **)(*DAT_005ba088 + 0xc4))();
    }
    *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
    FUN_004367f0((void *)(DAT_005ba070 + 0x2c0),pvVar1);
LAB_0044b3c7:
    (**(code **)(*DAT_005ba088 + 0xc4))();
    break;
  case 7:
    if ((*(int *)(param_4 + 0x34) != 0) &&
       (((*(int *)(param_4 + 0x60) == 6 &&
         (*(float *)(param_4 + 100) - *(float *)(param_4 + 0x68) < *(float *)(param_4 + 0x108))) ||
        ((*(int *)(param_4 + 0x34) != 0 && (*(float *)(param_4 + 0x68) == _DAT_0059d334)))))) {
      *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = *(undefined4 *)(param_4 + 0x34);
      *(undefined4 *)(param_4 + 0x34) = 0;
      (**(code **)(*DAT_005ba088 + 0xc4))();
      if (*(int *)(iVar6 + 0x60) == 5) {
        (**(code **)(*DAT_005ba088 + 0xc4))();
        *(undefined4 *)(iVar6 + 0x100) = 0x3f800000;
      }
    }
    if ((((*(int *)(iVar6 + 0x60) == 5) || (*(int *)(iVar6 + 0x60) == 7)) &&
        (iVar6 = FUN_004361f0((void *)(DAT_005ba070 + 0x1ac),param_6,param_7), iVar6 != 0)) &&
       (*(int *)(iVar6 + 0xac) != 0)) {
      *(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = *(int *)(iVar6 + 0xac);
      *(undefined4 *)(iVar6 + 0xac) = 0;
      (**(code **)(*DAT_005ba088 + 0xc4))();
    }
    break;
  case 8:
    *(undefined1 *)(*(int *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9d00) + 0x26c) = 1;
    pvVar1 = *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9d00);
    FUN_0040a120(pvVar1,*(int *)((int)pvVar1 + 0x48));
    (**(code **)(*DAT_005ba088 + 0xc4))();
    break;
  case 9:
    *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
    break;
  case 10:
    if (*(int *)((int)param_1 + 0x18) == 1) {
      FUN_0040a190((int)param_5);
    }
    *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
    FUN_004367f0((void *)(DAT_005ba070 + 0x2c0),pvVar1);
    break;
  case 0xb:
    if (*(int *)(param_4 + 0x60) != 7) {
      puVar2 = *(undefined4 **)(param_4 + 0x34);
      if (((puVar2 != (undefined4 *)0x0) && (*(float *)(param_4 + 0x68) == _DAT_0059d334)) &&
         (uVar3 = FUN_004011f0((int)(puVar2 + 0xb)), uVar3 < 4)) {
        pvVar1 = *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0);
        iVar7 = (int)pvVar1 + 0x2c;
        iVar4 = FUN_004011f0(iVar7);
        if (((iVar4 != 0) && (uVar3 = FUN_004011f0(iVar7), uVar3 < 4)) &&
           (uVar5 = FUN_00407930(pvVar1,puVar2,*(void **)(DAT_005ba070 + 0x19c)),
           (char)uVar5 != '\0')) {
          FUN_004367f0((void *)(DAT_005ba070 + 0x2c0),
                       *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0));
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
          *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
          (**(code **)(*DAT_005ba088 + 0xc4))();
        }
      }
      if (*(int *)(iVar6 + 0x60) != 7) break;
    }
    iVar6 = FUN_004361f0((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
    if (((iVar6 != 0) && (puVar2 = *(undefined4 **)(iVar6 + 0xac), puVar2 != (undefined4 *)0x0)) &&
       (uVar3 = FUN_004011f0((int)(puVar2 + 0xb)), uVar3 < 4)) {
      pvVar1 = *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0);
      iVar6 = (int)pvVar1 + 0x2c;
      iVar7 = FUN_004011f0(iVar6);
      if (((iVar7 != 0) && (uVar3 = FUN_004011f0(iVar6), uVar3 < 4)) &&
         (uVar5 = FUN_00407930(pvVar1,puVar2,*(void **)(DAT_005ba070 + 0x19c)), (char)uVar5 != '\0')
         ) {
        FUN_004367f0((void *)(DAT_005ba070 + 0x2c0),
                     *(void **)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0));
        *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
        *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9cf0) = 0;
        (**(code **)(*DAT_005ba088 + 0xc4))();
      }
    }
    break;
  case 0xc:
    if ((*(int *)(param_4 + 0x34) != 0) && (*(float *)(param_4 + 0x68) == _DAT_0059d334)) {
      *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
      FUN_00436000((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
    }
    break;
  case 0xd:
    if (((*(char *)((int)param_5 + 0x26d) != '\0') &&
        (*(float *)((int)param_5 + 0x54) < _DAT_0059d334)) &&
       (*(char *)((int)param_5 + 0x26f) == '\0')) {
      iVar6 = *(int *)((int)param_5 + 0x38);
      if (*(int *)((int)param_5 + 0x3c) != 0) {
        uVar8 = FUN_00560568();
        iVar6 = (int)uVar8;
      }
      if (*(int *)((int)this + 0x34) < iVar6) {
        iVar6 = *(int *)((int)this + 0x34);
      }
      uVar8 = FUN_00560568();
      uVar5 = (undefined4)uVar8;
      uVar8 = FUN_00560568();
      FUN_00419b10(*(void **)(DAT_005ba070 + 0x1a4),
                   *(int *)((int)this + 0x40) * iVar6 + *(int *)((int)this + 0x1c4),(int)uVar8,uVar5
                  );
      *(undefined1 *)((int)this + 0x26f) = 1;
      *(int *)(DAT_005ba070 + 800) =
           *(int *)(DAT_005ba070 + 800) + *(int *)((int)this + 0x40) * iVar6;
      *(int *)(DAT_005ba070 + 0x318) = *(int *)(DAT_005ba070 + 0x318) + *(int *)((int)this + 0x1c4);
    }
  }
switchD_0044ab68_caseD_2:
  FUN_00436520((void *)(DAT_005ba070 + 0x1ac),param_6,param_7);
  *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9d10) = 0;
  *(undefined4 *)(*(int *)(DAT_005ba070 + 0x1a8) + 0x9d0c) = 0;
  return;
}

