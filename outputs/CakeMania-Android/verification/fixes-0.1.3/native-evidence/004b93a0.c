/* Address: 004b93a0; name: FUN_004b93a0 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

undefined4 __thiscall FUN_004b93a0(int param_1,undefined ***param_2,void *param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char cVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  undefined1 auStack_12170 [73852];
  undefined4 local_f4 [2];
  int local_ec [2];
  byte local_e4 [88];
  int local_8c;
  undefined **local_88 [13];
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  void *local_34;
  undefined4 local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0057db51;
  local_10 = ExceptionList;
  local_14 = 0x4b93c2;
  if (*(char *)(param_1 + 0x50) != '\0') {
    return 0;
  }
  ExceptionList = &local_10;
  local_18 = param_1;
  puVar6 = FUN_004ab490(auStack_12170,param_1);
  iVar2 = *(int *)(param_1 + 0x170);
  local_8 = 0;
  puVar6 = FUN_004b69e0(iVar2,*(undefined4 *)(iVar2 + 4),puVar6);
  FUN_004a3cb0((void *)(param_1 + 0x16c),1);
  *(undefined4 **)(iVar2 + 4) = puVar6;
  *(undefined4 **)puVar6[1] = puVar6;
  local_8 = 0xffffffff;
  FUN_004aa7f0((int)auStack_12170);
  iVar8 = local_18;
  iVar2 = *(int *)(*(int *)(local_18 + 0x170) + 4);
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401f60(local_54,(undefined4 *)&DAT_0058161c,0);
  local_8 = 1;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401e70(&local_38,local_54,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = iVar2 + 8;
  piVar7 = (int *)FUN_004ac380((void *)(iVar8 + 0x178),local_f4,&local_38);
  local_14 = *piVar7;
  if (0xf < local_20) {
    _free(local_34);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  local_8 = 0xffffffff;
  if (0xf < local_3c) {
    _free(local_50);
  }
  pvVar4 = param_3;
  if (local_14 != *(int *)(iVar8 + 0x17c)) {
    *(undefined ****)(iVar2 + 0x1204c) = param_2;
    *(undefined4 *)(iVar2 + 0x12078) = *(undefined4 *)((int)param_2 + 8);
    local_14 = 0;
    *(undefined4 *)(iVar2 + 0x1206c) = *(undefined4 *)((int)param_2 + 8);
    if (*(uint *)((int)param_3 + 0x18) < 0x10) {
      pcVar9 = (char *)((int)param_3 + 4);
    }
    else {
      pcVar9 = *(char **)((int)param_3 + 4);
    }
    FUN_004aa9a0(local_ec,pcVar9,1,0x1b6,1);
    local_8 = 3;
    if (local_8c != 0) {
      FUN_00401e70((void *)(local_18 + 0x184),pvVar4,0,0xffffffff);
      piVar7 = FUN_004a0330(local_ec);
      FUN_004a0330(piVar7);
      bVar1 = local_e4[*(int *)(local_ec[0] + 4)];
      while ((bVar1 & 1) == 0) {
        param_2 = (undefined ***)((uint)param_2 & 0xffffff);
        param_3 = (void *)0x0;
        piVar7 = FUN_0049ff90(local_ec,(undefined1 *)((int)&param_2 + 3));
        FUN_004a0330(piVar7);
        if (param_2._3_1_ == 0) break;
        uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0x1204c) + 8);
        iVar8 = (uint)param_2._3_1_ * 0x120 + iVar2 + 8;
        *(int *)(iVar8 + 0x24) = local_14;
        *(undefined4 *)(iVar8 + 0x28) = 0;
        *(void **)(iVar8 + 0x2c) = param_3;
        *(undefined4 *)(iVar8 + 0x30) = uVar3;
        *(void **)(iVar8 + 0x13c) = param_3;
        local_14 = local_14 + (int)param_3;
        bVar1 = local_e4[*(int *)(local_ec[0] + 4)];
      }
      cVar5 = 'A';
      pcVar9 = (char *)(local_18 + 0xa1);
      piVar7 = (int *)(iVar2 + 0x6e64);
      do {
        if ((piVar7[-0x900] == 0) && (*piVar7 != 0)) {
          *pcVar9 = cVar5 + ' ';
        }
        cVar5 = cVar5 + '\x01';
        piVar7 = piVar7 + 0x48;
        pcVar9 = pcVar9 + 1;
      } while (cVar5 < '[');
      cVar5 = 'a';
      pcVar9 = (char *)(local_18 + 0xc1);
      piVar7 = (int *)(iVar2 + 0x4a64);
      do {
        if ((piVar7[0x900] == 0) && (*piVar7 != 0)) {
          *pcVar9 = cVar5 + -0x20;
        }
        cVar5 = cVar5 + '\x01';
        piVar7 = piVar7 + 0x48;
        pcVar9 = pcVar9 + 1;
      } while (cVar5 < '{');
      *(undefined1 *)(local_18 + 0x50) = 1;
      param_2 = local_88;
      *(undefined ***)((int)local_ec + *(int *)(local_ec[0] + 4)) = &PTR_FUN_00589eb4;
      local_8 = 4;
      FUN_00484130((int *)local_e4);
      *(undefined ***)((int)local_ec + *(int *)(local_ec[0] + 4)) = &PTR_FUN_00588334;
      local_8 = 0xffffffff;
      local_88[0] = &PTR_FUN_0058832c;
      FUN_0055f1b1((ios_base *)local_88);
      ExceptionList = local_10;
      return 1;
    }
    local_8 = 0xffffffff;
    FUN_004aaae0((int)local_88);
    local_88[0] = &PTR_FUN_0058832c;
    FUN_0055f1b1((ios_base *)local_88);
  }
  ExceptionList = local_10;
  return 0;
}


