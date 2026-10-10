/* Native address 0044e5d0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Recovered_0044e5d0(void *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                       void *param_5,float param_6,float param_7,int param_8,undefined4 param_9)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  iVar5 = DAT_005ba074;
  if (param_8 == 1) goto switchD_0044e5f8_default;
  switch(param_9) {
  case 1:
    *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = param_2;
    break;
  case 2:
  case 3:
    break;
  case 4:
    if (*(int *)(param_4 + 0x34) == 0) {
      *(void **)(param_4 + 0x34) = param_1;
      *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
LAB_0044e741:
      *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
      FUN_00436000((void *)(DAT_005ba074 + 0x1ac),param_6,param_7);
LAB_0044ea55:
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9958);
    }
    else {
      iVar2 = FUN_004011f0(*(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) + 0x2c);
      if ((iVar2 == 1) && (*(int *)(param_4 + 0x60) == 1)) {
        FUN_00406d40(*(void **)(iVar5 + 0x19c),&uStack_20,
                     *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar5 + 0x1a8) + 0x9cf0) + 0x34) +
                                      -4) + 0x28),0,0);
        puVar1 = operator_new(0x30);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = (undefined4 *)FUN_004061e0(puVar1);
        }
        (**(code **)*puVar1)(uStack_1c);
        puVar1[4] = uStack_c;
        puVar1[5] = uStack_8;
        FUN_00406190((int)puVar1);
        puVar1[10] = *(undefined4 *)
                      (*(int *)(*(int *)(*(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) + 0x34) +
                               -4) + 0x28);
        puVar1[8] = (float)iStack_4;
        uVar4 = FUN_00407870(*(void **)(param_4 + 0x34),(int)puVar1);
        if ((char)uVar4 != '\0') {
          FUN_004367f0((void *)(DAT_005ba074 + 0x2c0),
                       *(void **)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0));
          *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
          (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9958);
          goto LAB_0044e741;
        }
      }
    }
    break;
  case 5:
    if (((*(int *)(param_4 + 0x34) == 0) &&
        (iVar5 = *(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0), iVar5 != 0)) &&
       (*(int *)(param_4 + 0x60) != 7)) {
      *(int *)(param_4 + 0x34) = iVar5;
      *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
      if (*(int *)(param_4 + 0x60) == 3) {
        (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9d88);
        *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
        if (*(int *)((int)param_1 + 0x18) != 1) {
          uVar4 = *(undefined4 *)(param_4 + 0x50);
          uVar6 = FUN_00560568();
          FUN_00419b40(*(void **)(DAT_005ba074 + 0x1a4),(int)param_1,(int)uVar6,uVar4);
        }
      }
      else {
        (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9958);
      }
    }
    if (((*(int *)(param_4 + 0x60) == 7) &&
        (iVar5 = FUN_004361f0((void *)(DAT_005ba074 + 0x1ac),param_6,param_7), iVar5 != 0)) &&
       (*(int *)(iVar5 + 0xac) == 0)) {
      *(undefined4 *)(iVar5 + 0xac) = *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0);
LAB_0044ea43:
      *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
      goto LAB_0044ea55;
    }
    break;
  case 6:
    if (*(int *)((int)param_1 + 0x18) == 1) {
      FUN_0040a190((int)param_5);
    }
    else {
      iVar5 = FUN_00419510((int)param_1);
      *(int *)((int)param_5 + 0x1c4) = iVar5;
      *(undefined1 *)((int)param_5 + 0x26d) = 1;
      FUN_0040a170(param_5,2);
    }
    *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
    FUN_004367f0((void *)(DAT_005ba074 + 0x2c0),param_1);
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9958);
    break;
  case 7:
    if ((*(int *)(param_4 + 0x34) != 0) && (*(float *)(param_4 + 0x68) == _DAT_0059d334)) {
      *(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = *(int *)(param_4 + 0x34);
      *(undefined4 *)(param_4 + 0x34) = 0;
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9e4c);
      if (*(int *)(param_4 + 0x60) == 5) {
        (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9e9c);
        *(undefined4 *)(param_4 + 0x100) = 0x3f800000;
      }
    }
    if (((*(int *)(param_4 + 0x60) == 5) || (*(int *)(param_4 + 0x60) == 7)) &&
       ((iVar5 = FUN_004361f0((void *)(DAT_005ba074 + 0x1ac),param_6,param_7), iVar5 != 0 &&
        (*(int *)(iVar5 + 0xac) != 0)))) {
      *(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = *(int *)(iVar5 + 0xac);
      *(undefined4 *)(iVar5 + 0xac) = 0;
      (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9e4c);
    }
    break;
  case 8:
    *(undefined1 *)(*(int *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9d00) + 0x26c) = 1;
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9ab8);
    break;
  case 9:
    *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
    break;
  case 10:
    if (*(int *)((int)param_1 + 0x18) == 1) {
      FUN_0040a190((int)param_5);
    }
    *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
    FUN_004367f0((void *)(DAT_005ba074 + 0x2c0),param_1);
    break;
  case 0xb:
    puVar1 = *(undefined4 **)(param_4 + 0x34);
    if (puVar1 != (undefined4 *)0x0) {
      this = *(void **)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0);
      iVar5 = (int)this + 0x2c;
      iVar2 = FUN_004011f0(iVar5);
      if (((iVar2 != 0) && (uVar3 = FUN_004011f0(iVar5), uVar3 < 4)) &&
         (uVar4 = FUN_00407930(this,puVar1,*(void **)(DAT_005ba074 + 0x19c)), (char)uVar4 != '\0'))
      {
        FUN_004367f0((void *)(DAT_005ba074 + 0x2c0),
                     *(void **)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0));
        *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9cf0) = 0;
        goto LAB_0044ea43;
      }
    }
    break;
  case 0xc:
    if (*(int *)(param_4 + 0x34) != 0) {
      *(undefined4 *)(param_4 + 0x68) = *(undefined4 *)(param_4 + 100);
      FUN_00436000((void *)(DAT_005ba074 + 0x1ac),param_6,param_7);
    }
    break;
  case 0xd:
    uVar6 = FUN_00560568();
    uVar4 = (undefined4)uVar6;
    uVar6 = FUN_00560568();
    FUN_00419b10(*(void **)(DAT_005ba074 + 0x1a4),*(int *)((int)param_5 + 0x1c4),(int)uVar6,uVar4);
    *(undefined1 *)((int)param_5 + 0x26f) = 1;
    *(undefined1 *)(DAT_005ba074 + 0x2d5) = 1;
    break;
  default:
    goto switchD_0044e5f8_default;
  }
switchD_0044e5f8_default:
  FUN_00436520((void *)(DAT_005ba074 + 0x1ac),param_6,param_7);
  *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9d10) = 0;
  *(undefined4 *)(*(int *)(DAT_005ba074 + 0x1a8) + 0x9d0c) = 0;
  return;
}

