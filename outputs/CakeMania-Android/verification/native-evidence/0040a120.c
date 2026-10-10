/* Address: 0040a120; name: FUN_0040a120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0040a120(void *this,int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)(*(int *)((int)this + 0x3c) * param_1) + *(float *)((int)this + 0x328);
  *(float *)((int)this + 0x328) = fVar1;
  fVar2 = (float)((*(int *)((int)this + 0x34) + 1) * *(int *)((int)this + 0x3c)) - _DAT_00581620;
  if (fVar2 < fVar1) {
    *(float *)((int)this + 0x328) = fVar2;
  }
  return;
}


