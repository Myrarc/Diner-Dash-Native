/* Native address 00411420; read-only Ghidra audit recovery. */

void __thiscall FUN_00411420(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_1 < *(int *)((int)this + 0x48)) {
    uVar5 = 0;
    if (*(int *)((int)this + 0x48) != param_1) {
      local_4 = 0;
      do {
        if (*(int *)((int)this + 8) != 0) {
          local_14 = *(undefined4 *)(*(int *)((int)this + 8) + 0xc);
        }
        uVar6 = FUN_00560568();
        local_10 = (undefined4)uVar6;
        uVar6 = FUN_00560568();
        local_c = (undefined4)uVar6;
        iVar3 = 0;
        if (*(int *)((int)this + 0x60) != 0) {
          iVar3 = (*(int *)((int)this + 100) - *(int *)((int)this + 0x60)) / 0x18;
        }
        iVar2 = *(int *)((int)this + 0x60);
        uVar4 = (iVar3 - uVar5) - 1;
        if ((iVar2 == 0) || ((uint)((*(int *)((int)this + 100) - iVar2) / 0x18) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0040bb80();
        }
        puVar1 = (undefined4 *)(iVar2 + uVar4 * 0x18);
        *puVar1 = *(undefined4 *)((int)this + 8);
        puVar1[1] = local_14;
        puVar1[2] = local_10;
        puVar1[3] = local_c;
        puVar1[4] = local_8;
        puVar1[5] = local_4;
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)(*(int *)((int)this + 0x48) - param_1));
    }
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b9bcc);
  }
  if ((*(int *)((int)this + 0x48) < param_1) && (uVar5 = 0, param_1 != *(int *)((int)this + 0x48)))
  {
    local_4 = 0;
    do {
      local_18 = *(int *)((int)this + 4);
      if (local_18 != 0) {
        local_14 = *(undefined4 *)(local_18 + 0xc);
      }
      uVar6 = FUN_00560568();
      local_10 = (undefined4)uVar6;
      uVar6 = FUN_00560568();
      local_c = (undefined4)uVar6;
      FUN_0040ed70((void *)((int)this + 0x5c),&local_18);
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(param_1 - *(int *)((int)this + 0x48)));
  }
  *(int *)((int)this + 0x48) = param_1;
  return;
}

