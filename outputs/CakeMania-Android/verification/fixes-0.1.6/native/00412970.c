/* Native address 00412970; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00412970(void *this,float param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  undefined4 in_stack_ffffffd0;
  byte *in_stack_ffffffd4;
  uint3 uVar6;
  byte *pbVar5;
  
  iVar3 = *(int *)((int)this + 0x324);
  *(float *)((int)this + 0x304) = param_1 + *(float *)((int)this + 0x304);
  if ((*(int *)((int)this + 0x3c) != 0) && (*(char *)((int)this + 0x26d) == '\0')) {
    *(float *)((int)this + 0x328) = *(float *)((int)this + 0x328) - param_1;
  }
  if ((*(char *)((int)this + 0x26c) != '\0') && (*(float *)((int)this + 0x50) != _DAT_0059d334)) {
    *(float *)((int)this + 0x50) = *(float *)((int)this + 0x50) - param_1;
  }
  if ((*(float *)((int)this + 0x50) < _DAT_0059d334) && (*(char *)((int)this + 0x26c) != '\0')) {
    *(undefined4 *)((int)this + 0x50) = 0;
    iVar2 = *(int *)(*(int *)((int)this + 0x14) + 0x30);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)((int)this + 0x14) + 0x34) - iVar2 >> 2;
    }
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + _DAT_00581608;
    }
    *(float *)((int)this + 400) = fVar1;
    *(undefined4 *)((int)this + 800) = 0;
  }
  if (*(char *)((int)this + 0x26d) != '\0') {
    *(float *)((int)this + 0x54) = *(float *)((int)this + 0x54) - param_1;
  }
  if (_DAT_0059d334 < *(float *)((int)this + 0x18c)) {
    fVar1 = *(float *)((int)this + 0x18c) - param_1;
    *(float *)((int)this + 0x18c) = fVar1;
    if (fVar1 < _DAT_0059d334) {
      *(undefined4 *)((int)this + 0x18c) = 0;
    }
    iVar2 = *(int *)((int)this + 0x188) + 1;
    *(int *)((int)this + 0x188) = iVar2;
    if (0x3c < iVar2) {
      *(undefined4 *)((int)this + 0x188) = 0;
    }
  }
  if ((_DAT_0059d334 < *(float *)((int)this + 400)) &&
     (fVar1 = *(float *)((int)this + 400) - param_1, *(float *)((int)this + 400) = fVar1,
     fVar1 < _DAT_0059d334)) {
    *(undefined4 *)((int)this + 400) = 0;
  }
  fVar1 = param_1 + *(float *)((int)this + 0x1d8);
  *(float *)((int)this + 0x1d8) = fVar1;
  if (_DAT_00581474 < fVar1) {
    *(undefined4 *)((int)this + 0x1d8) = 0;
  }
  if ((-1 < *(int *)((int)this + 0x1d4)) &&
     (fVar1 = param_1 + *(float *)((int)this + 0x1e8), *(float *)((int)this + 0x1e8) = fVar1,
     *(float *)((int)this + 0x1e4) < fVar1)) {
    *(undefined4 *)((int)this + 0x1e8) = 0;
    *(int *)((int)this + 0x1d4) = *(int *)((int)this + 0x1d4) + -1;
  }
  if (*(int *)((int)this + 700) != 0) {
    iVar2 = *(int *)((int)this + 0x274);
    uVar6 = (uint3)((uint)in_stack_ffffffd4 >> 8);
    if (iVar2 < 1) {
      if (iVar2 == -1) {
        in_stack_ffffffd4 = (byte *)((uint)uVar6 << 8);
        FUN_00401e70(&stack0xffffffd0,(void *)((int)this + 0x27c),0,0xffffffff);
      }
      else {
        if ((iVar2 != 0) || (*(char *)((int)this + 0x26d) == '\0')) goto LAB_00412c07;
        FUN_00402070(&stack0xffffffd0,(void *)((int)this + 0x27c));
      }
      FUN_004121b0((void *)(*(int *)(*(int *)((int)this + 700) + 0x600) + 0x1fc),1,in_stack_ffffffd0
                   ,in_stack_ffffffd4);
      *(undefined4 *)((int)this + 0x274) = 0xfffffffe;
    }
    else {
      fVar1 = param_1 + *(float *)((int)this + 0x31c);
      *(float *)((int)this + 0x31c) = fVar1;
      if ((float)iVar2 < fVar1) {
        pbVar5 = (byte *)((uint)uVar6 << 8);
        FUN_00401e70(&stack0xffffffd0,(void *)((int)this + 0x27c),0,0xffffffff);
        FUN_004121b0((void *)(*(int *)(*(int *)((int)this + 700) + 0x600) + 0x1fc),1,
                     in_stack_ffffffd0,pbVar5);
        *(undefined4 *)((int)this + 0x31c) = 0;
      }
    }
  }
LAB_00412c07:
  *(undefined4 *)((int)this + 0x324) = *(undefined4 *)((int)this + 0x38);
  if (*(int *)((int)this + 0x3c) != 0) {
    uVar4 = FUN_00560568();
    *(int *)((int)this + 0x324) = (int)uVar4;
  }
  if (*(int *)((int)this + 0x34) < *(int *)((int)this + 0x324)) {
    *(int *)((int)this + 0x324) = *(int *)((int)this + 0x34);
  }
  if (*(int *)((int)this + 800) != 1) {
    if (*(int *)((int)this + 0x324) == 1) {
      *(undefined4 *)((int)this + 800) = 3;
    }
    if ((_DAT_0059d334 < *(float *)((int)this + 0x50)) && (*(char *)((int)this + 0x26c) != '\0')) {
      *(undefined4 *)((int)this + 800) = 1;
    }
  }
  if (*(char *)((int)this + 0x26d) != '\0') {
    *(undefined4 *)((int)this + 800) = 2;
  }
  if (((*(int *)((int)this + 0x324) < iVar3) && (*(int *)((int)this + 0x324) == 1)) &&
     (-1 < *(int *)((int)this + 600))) {
    (**(code **)(*DAT_005ba088 + 0xc4))();
  }
  if (((iVar3 < *(int *)((int)this + 0x324)) || (*(char *)((int)this + 0x260) != '\0')) &&
     (-1 < *(int *)((int)this + 0x25c))) {
    (**(code **)(*DAT_005ba088 + 0xc4))();
    *(undefined1 *)((int)this + 0x260) = 0;
  }
  FUN_00411420((void *)((int)this + 0x1ec),*(int *)((int)this + 0x324));
  FUN_00411300((void *)((int)this + 0x1ec),param_1);
  if ((*(float *)((int)this + 0x2d0) != _DAT_0059d334) &&
     (fVar1 = param_1 + *(float *)((int)this + 0x2d4), *(float *)((int)this + 0x2d4) = fVar1,
     *(float *)((int)this + 0x2d0) < fVar1)) {
    *(undefined4 *)((int)this + 0x2d4) = 0;
  }
  if ((*(char *)((int)this + 0x300) != '\0') &&
     (fVar1 = param_1 + *(float *)((int)this + 0x2fc), *(float *)((int)this + 0x2fc) = fVar1,
     *(float *)((int)this + 0x2f8) < fVar1)) {
    *(undefined4 *)((int)this + 0x2fc) = 0;
    *(int *)((int)this + 0x2ec) = *(int *)((int)this + 0x2ec) + -1;
  }
  if ((*(char *)((int)this + 0x196) != '\0') &&
     (fVar1 = param_1 + *(float *)((int)this + 0x1bc), *(float *)((int)this + 0x1bc) = fVar1,
     *(float *)((int)this + 0x1b8) < fVar1)) {
    iVar3 = *(int *)((int)this + 0x1c0) + 1;
    *(undefined4 *)((int)this + 0x1bc) = 0;
    *(int *)((int)this + 0x1c0) = iVar3;
    if (*(int *)(*(int *)((int)this + 0x19c) + 0x10) + -1 < iVar3) {
      *(undefined4 *)((int)this + 0x1c0) = 0;
    }
  }
  return;
}

