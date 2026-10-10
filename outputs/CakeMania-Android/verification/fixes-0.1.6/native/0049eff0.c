/* Native address 0049eff0; read-only Ghidra audit recovery. */

void __thiscall FUN_0049eff0(void *this,int param_1,int param_2,int param_3)

{
  FUN_0049be70(this,param_1,param_2,param_3 % *(int *)(param_1 + 0x10),
               param_3 / *(int *)(param_1 + 0x10));
  return;
}

