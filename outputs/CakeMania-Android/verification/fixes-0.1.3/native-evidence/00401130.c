/* Native address 00401130; read-only Ghidra audit recovery. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00401130(float param_1,float param_2)

{
  float10 fVar1;
  
  if (param_1 != _DAT_0059d334) {
    fVar1 = (float10)fpatan((float10)param_2 / (float10)param_1,(float10)1);
    fVar1 = fVar1 * (float10)_DAT_00581408;
    if (param_1 <= _DAT_0059d334) {
      fVar1 = fVar1 + (float10)_DAT_00581400;
    }
    else if (param_2 < _DAT_0059d334) {
      return fVar1 + (float10)_DAT_00581404;
    }
    return fVar1;
  }
  if (param_2 == _DAT_0059d334) {
    return (float10)_DAT_00581414;
  }
  if (_DAT_0059d334 < param_2) {
    return (float10)_DAT_00581410;
  }
  return (float10)_DAT_0058140c;
}

