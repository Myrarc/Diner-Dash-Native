/* Address: 0043a680; name: FUN_0043a680 */

void __cdecl FUN_0043a680(int param_1)

{
  bool bVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  float *pfVar6;
  void *this;
  undefined4 in_stack_ffffff60;
  uint in_stack_ffffff64;
  char *pcVar7;
  undefined4 *local_74;
  undefined4 *local_70;
  long local_6c;
  long local_64;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00577e75;
  local_c = ExceptionList;
  local_70 = (undefined4 *)0x0;
  ExceptionList = &local_c;
  local_70 = operator_new(0xac);
  local_4 = 0;
  if (local_70 == (undefined4 *)0x0) {
    local_74 = (undefined4 *)0x0;
  }
  else {
    local_74 = FUN_00438120(local_70);
  }
  local_4 = 0xffffffff;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)&DAT_005815ec,4);
  this = (void *)(param_1 + 0x58);
  local_4 = 1;
  piVar2 = FUN_00404ab0(this,local_60);
  FUN_00401e70(local_74 + 1,piVar2,0,0xffffffff);
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)&DAT_005814e8,2);
  local_4 = 2;
  piVar2 = FUN_00404ab0(this,local_60);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  lVar3 = _atol((char *)piVar2);
  local_74[0x12] = lVar3;
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)&DAT_005816e4,4);
  local_4 = 3;
  piVar2 = FUN_00404ab0(this,local_60);
  iVar4 = piVar2[5];
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  if (iVar4 != 0) {
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    FUN_00401f60(local_60,(undefined4 *)&DAT_005816e4,4);
    local_4 = 4;
    piVar2 = FUN_00404ab0(this,local_60);
    FUN_00401e70(local_74 + 0x13,piVar2,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_48) {
      _free(local_5c);
    }
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)"image",5);
  local_4 = 5;
  piVar2 = FUN_00404ab0(this,local_60);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  iVar4 = FUN_00433e00((char *)piVar2);
  uVar5 = FUN_00427410(iVar4);
  local_74[8] = uVar5;
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)"image_hl",8);
  local_4 = 6;
  piVar2 = FUN_00404ab0(this,local_60);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  iVar4 = FUN_00433e00((char *)piVar2);
  uVar5 = FUN_00427410(iVar4);
  local_74[9] = uVar5;
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  local_74[10] = local_74[9];
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)"flash",5);
  local_4 = 7;
  piVar2 = FUN_00404ab0(this,local_60);
  iVar4 = piVar2[5];
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  if (iVar4 != 0) {
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    FUN_00401f60(local_60,(undefined4 *)"flash",5);
    local_4 = 8;
    piVar2 = FUN_00404ab0(this,local_60);
    if ((uint)piVar2[6] < 0x10) {
      piVar2 = piVar2 + 1;
    }
    else {
      piVar2 = (int *)piVar2[1];
    }
    lVar3 = _atol((char *)piVar2);
    *(bool *)(local_74 + 0x1d) = lVar3 != 0;
    local_4 = 0xffffffff;
    if (0xf < local_48) {
      _free(local_5c);
    }
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401f60(local_60,(undefined4 *)"price",5);
  local_4 = 9;
  piVar2 = FUN_00404ab0(this,local_60);
  iVar4 = piVar2[5];
  local_4 = 0xffffffff;
  if (0xf < local_48) {
    _free(local_5c);
  }
  if (iVar4 != 0) {
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    FUN_00401f60(local_60,(undefined4 *)"price",5);
    local_4 = 10;
    piVar2 = FUN_00404ab0(this,local_60);
    if ((uint)piVar2[6] < 0x10) {
      piVar2 = piVar2 + 1;
    }
    else {
      piVar2 = (int *)piVar2[1];
    }
    lVar3 = _atol((char *)piVar2);
    local_74[0x25] = lVar3;
    local_4 = 0xffffffff;
    if (0xf < local_48) {
      _free(local_5c);
    }
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)"image_anim",10);
  local_4 = 0xb;
  local_70 = (undefined4 *)0x1;
  piVar2 = FUN_00404ab0(this,local_44);
  if (piVar2[5] == 0) {
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    FUN_00401f60(local_60,(undefined4 *)"image_anim",10);
    local_4 = 0xc;
    local_70 = (undefined4 *)0x3;
    piVar2 = FUN_00404ab0(this,local_60);
    bVar1 = false;
    if (piVar2[5] == 0) goto LAB_0043abb3;
  }
  bVar1 = true;
LAB_0043abb3:
  if (((uint)local_70 & 2) != 0) {
    local_70 = (undefined4 *)((uint)local_70 & 0xfffffffd);
    if (0xf < local_48) {
      _free(local_5c);
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
  }
  local_4 = 0xffffffff;
  if ((((uint)local_70 & 1) != 0) && (0xf < local_2c)) {
    _free(local_40);
  }
  if (bVar1) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)"image_anim",10);
    local_4 = 0xd;
    piVar2 = FUN_00404ab0(this,local_44);
    if ((uint)piVar2[6] < 0x10) {
      piVar2 = piVar2 + 1;
    }
    else {
      piVar2 = (int *)piVar2[1];
    }
    iVar4 = FUN_00433e00((char *)piVar2);
    uVar5 = FUN_00427410(iVar4);
    local_74[0xb] = uVar5;
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)"pt_anim",7);
    local_4 = 0xe;
    piVar2 = FUN_00404ab0(this,local_44);
    pcVar7 = (char *)(in_stack_ffffff64 & 0xffffff00);
    FUN_00401e70(&stack0xffffff60,piVar2,0,0xffffffff);
    pfVar6 = FUN_00439c20((float *)&local_70,in_stack_ffffff60,pcVar7);
    local_74[0xc] = *pfVar6;
    local_74[0xd] = pfVar6[1];
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)"count_anim",10);
    local_4 = 0xf;
    piVar2 = FUN_00404ab0(this,local_44);
    iVar4 = piVar2[5];
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
    }
    if (iVar4 == 0) {
      *(undefined4 *)(local_74[0xb] + 0xc) = 1;
    }
    else {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401f60(local_44,(undefined4 *)"count_anim",10);
      local_4 = 0x10;
      piVar2 = FUN_00404ab0(this,local_44);
      if ((uint)piVar2[6] < 0x10) {
        piVar2 = piVar2 + 1;
      }
      else {
        piVar2 = (int *)piVar2[1];
      }
      lVar3 = _atol((char *)piVar2);
      *(long *)(local_74[0xb] + 0xc) = lVar3;
      local_4 = 0xffffffff;
      if (0xf < local_2c) {
        _free(local_40);
      }
    }
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)"count_anim_vert",0xf);
    local_4 = 0x11;
    piVar2 = FUN_00404ab0(this,local_44);
    iVar4 = piVar2[5];
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
    }
    if (iVar4 == 0) {
      *(undefined4 *)(local_74[0xb] + 0x10) = 1;
    }
    else {
      local_2c = 0xf;
      local_30 = 0;
      local_40 = (void *)((uint)local_40 & 0xffffff00);
      FUN_00401f60(local_44,(undefined4 *)"count_anim_vert",0xf);
      local_4 = 0x12;
      piVar2 = FUN_00404ab0(this,local_44);
      if ((uint)piVar2[6] < 0x10) {
        piVar2 = piVar2 + 1;
      }
      else {
        piVar2 = (int *)piVar2[1];
      }
      lVar3 = _atol((char *)piVar2);
      *(long *)(local_74[0xb] + 0x10) = lVar3;
      local_4 = 0xffffffff;
      if (0xf < local_2c) {
        _free(local_40);
      }
    }
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)&DAT_00586130,3);
  local_4 = 0x13;
  piVar2 = FUN_00404ab0(this,local_44);
  iVar4 = piVar2[5];
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
  }
  if (iVar4 != 0) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401f60(local_44,(undefined4 *)&DAT_00586130,3);
    local_4 = 0x14;
    piVar2 = FUN_00404ab0(this,local_44);
    FUN_00401e70(local_74 + 0x1e,piVar2,0,0xffffffff);
    local_4 = 0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
    }
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)"purchase_points",0xf);
  local_4 = 0x15;
  piVar2 = FUN_00404ab0(this,local_44);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  lVar3 = _atol((char *)piVar2);
  local_74[0x1c] = lVar3;
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)&DAT_00581660,1);
  local_4 = 0x16;
  piVar2 = FUN_00404ab0(this,local_44);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  local_70 = (undefined4 *)_atol((char *)piVar2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)&DAT_0058165c,1);
  local_4 = 0x17;
  piVar2 = FUN_00404ab0(this,local_44);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  local_6c = _atol((char *)piVar2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401f60(local_44,(undefined4 *)"height",6);
  local_4 = 0x18;
  piVar2 = FUN_00404ab0(this,local_44);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  local_64 = _atol((char *)piVar2);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401f60(local_28,(undefined4 *)"width",5);
  local_4 = 0x19;
  piVar2 = FUN_00404ab0(this,local_28);
  if ((uint)piVar2[6] < 0x10) {
    piVar2 = piVar2 + 1;
  }
  else {
    piVar2 = (int *)piVar2[1];
  }
  lVar3 = _atol((char *)piVar2);
  if (0xf < local_10) {
    _free(local_24);
  }
  local_74[0xe] = local_70;
  local_74[0xf] = local_6c;
  local_74[0x10] = lVar3;
  local_74[0x11] = local_64;
  ExceptionList = local_c;
  return;
}


