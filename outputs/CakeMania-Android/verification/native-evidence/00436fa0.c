/* Native address 00436fa0. Recovered in read-only Ghidra session. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Recovered_00436fa0(int param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (*(float *)(param_1 + 0x68) != _DAT_0059d334) {
    *(float *)(param_1 + 0x68) = *(float *)(param_1 + 0x68) - param_3;
  }
  if (*(float *)(param_1 + 0x68) < _DAT_0059d334) {
    *(undefined4 *)(param_1 + 0x68) = 0;
    if (*(char *)(param_1 + 0xd3) == '\0') {
      *(undefined4 *)(param_1 + 0x120) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 100);
      *(undefined1 *)(param_1 + 0xd3) = 0;
      FUN_00401e70((void *)(param_1 + 0x100),(void *)(*(int *)(param_1 + 0x120) + 0x4c),0,0xffffffff
                  );
      iVar1 = *(int *)(param_1 + 0x120);
      if (*(int *)(iVar1 + 0x8c) != 0) {
        if (*(uint *)(iVar1 + 0x90) < 0x10) {
          pcVar4 = (char *)(iVar1 + 0x7c);
        }
        else {
          pcVar4 = *(char **)(iVar1 + 0x7c);
        }
        FUN_00433e00(pcVar4);
        iVar1 = *(int *)(param_1 + 0x120);
        if (*(uint *)(iVar1 + 0x90) < 0x10) {
          pcVar4 = (char *)(iVar1 + 0x7c);
        }
        else {
          pcVar4 = *(char **)(iVar1 + 0x7c);
        }
        iVar1 = *DAT_005ba088;
        iVar2 = FUN_00433e00(pcVar4);
        uVar3 = FUN_00427410(iVar2);
        (**(code **)(iVar1 + 0xc4))(uVar3);
        return;
      }
    }
  }
  return;
}

