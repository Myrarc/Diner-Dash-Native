/* Native address 0040b2e0; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_0040b2e0(void *this,float param_1,float param_2)

{
  float fVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined2 unaff_DI;
  float10 fVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  float local_18;
  float local_14 [3];
  int local_8;
  
  local_14[0] = *(float *)((int)this + 0x154);
  local_18 = *(float *)((int)this + 0x150);
  FUN_0040b140(this,&local_18,local_14);
  uVar6 = FUN_00560568();
  uVar7 = FUN_00560568();
  fVar5 = FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                                 (*(float *)((int)this + 0x268) - *(float *)((int)this + 0x264)) *
                                 _DAT_005813fc + *(float *)((int)this + 0x264)) *
                                (float)_DAT_005813f0 + (float)_DAT_005813e8),unaff_DI);
  local_18 = (float)(fVar5 * (float10)_DAT_005813e0);
  local_14[0] = (float)FUN_00493700(*(int *)((int)this + 0x58));
  uVar8 = FUN_00560568();
  local_8 = (int)uVar8;
  fVar5 = FUN_0055ff20((double)(((*(float *)((int)this + 4) - _DAT_005813f8) *
                                 (*(float *)((int)this + 0x268) - *(float *)((int)this + 0x264)) *
                                 _DAT_005813fc + *(float *)((int)this + 0x264)) *
                                (float)_DAT_005813f0 + (float)_DAT_005813e8),unaff_DI);
  local_18 = (float)(fVar5 * (float10)_DAT_005813e0);
  local_14[0] = (float)FUN_00493710(*(int *)((int)this + 0x58));
  uVar8 = FUN_00560568();
  uVar3 = FUN_00401010((int)uVar6,(int)uVar7,local_8,(int)uVar8,param_1,param_2);
  cVar2 = (char)uVar3;
  if (cVar2 == '\0') {
    fVar1 = *(float *)((int)this + 0x50);
    uVar3 = CONCAT22((short)(uVar3 >> 0x10),
                     (ushort)(fVar1 < _DAT_0059d334) << 8 |
                     (ushort)(NAN(fVar1) || NAN(_DAT_0059d334)) << 10 |
                     (ushort)(fVar1 == _DAT_0059d334) << 0xe);
    if ((fVar1 < _DAT_0059d334 != (fVar1 == _DAT_0059d334)) &&
       (uVar3 = CONCAT31((int3)(uVar3 >> 8),*(char *)((int)this + 0x26d)),
       *(char *)((int)this + 0x26d) == '\0')) {
      uVar3 = FUN_0040a210((void *)((int)this + 0x150),param_1,param_2);
      cVar2 = (char)uVar3;
    }
  }
  uVar4 = CONCAT31((int3)(uVar3 >> 8),*(char *)((int)this + 0x196));
  if (*(char *)((int)this + 0x196) == '\0') {
    fVar1 = *(float *)((int)this + 0x54);
    uVar4 = CONCAT22((short)(uVar3 >> 0x10),
                     (ushort)(fVar1 < _DAT_0059d334) << 8 |
                     (ushort)(NAN(fVar1) || NAN(_DAT_0059d334)) << 10 |
                     (ushort)(fVar1 == _DAT_0059d334) << 0xe);
    if (fVar1 >= _DAT_0059d334) {
      return CONCAT31((int3)(uVar4 >> 8),cVar2);
    }
  }
  return uVar4 & 0xffffff00;
}

