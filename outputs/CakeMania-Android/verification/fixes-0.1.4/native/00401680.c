/* Native address 00401680; read-only Ghidra audit recovery. */

void __thiscall FUN_00401680(void *this,float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = *(float *)((int)this + 0x1c) - param_3;
  fVar1 = *(float *)((int)this + 0x18) - param_2;
  fVar3 = SQRT(fVar3 * fVar3 + fVar1 * fVar1);
  if (fVar3 < *(float *)this) {
    *param_1 = param_2;
    param_1[1] = param_3;
    return;
  }
  fVar1 = *(float *)((int)this + 0x1c);
  fVar3 = *(float *)this / fVar3;
  fVar2 = *(float *)((int)this + 0x1c);
  *param_1 = fVar3 * (param_2 - *(float *)((int)this + 0x18)) + *(float *)((int)this + 0x18);
  param_1[1] = fVar3 * (param_3 - fVar1) + fVar2;
  return;
}

