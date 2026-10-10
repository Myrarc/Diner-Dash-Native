/* Native address 00401560; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00401560(void *this,float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if ((param_1 == *(float *)((int)this + 0x18)) && (param_2 == *(float *)((int)this + 0x1c))) {
    return 1;
  }
  if ((param_3 == *(float *)((int)this + 0x18)) && (param_4 == *(float *)((int)this + 0x1c))) {
    return 2;
  }
  fVar1 = param_3 - param_1;
  fVar2 = param_4 - param_2;
  fVar3 = *(float *)((int)this + 0x18) - param_1;
  fVar4 = *(float *)((int)this + 0x1c) - param_2;
  fVar5 = fVar4 * fVar1 - fVar2 * fVar3;
  if ((((fVar5 <= _DAT_0058141c) && (_DAT_00581418 <= fVar5)) &&
      (SQRT(fVar4 * fVar4 + fVar3 * fVar3) <= SQRT(fVar1 * fVar1 + fVar2 * fVar2))) &&
     ((_DAT_0059d334 <= fVar3 * fVar1 && (_DAT_0059d334 <= fVar2 * fVar4)))) {
    return 0;
  }
  return 3;
}

