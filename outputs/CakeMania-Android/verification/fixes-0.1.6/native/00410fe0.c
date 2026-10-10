/* Native address 00410fe0; read-only Ghidra audit recovery. */

void * FUN_00410fe0(void *param_1,void *param_2)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  void *this;
  long *plVar4;
  void *_Memory;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  bool bVar8;
  long local_30;
  undefined1 local_2c [4];
  void *local_28;
  long *local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 *local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00574500;
  local_c = ExceptionList;
  local_30 = 0;
  _Memory = (void *)0x0;
  plVar4 = (long *)0x0;
  local_4 = 0;
  local_28 = (void *)0x0;
  local_24 = (long *)0x0;
  local_20 = 0;
  ExceptionList = &local_c;
  pvVar1 = (void *)FUN_004734f0(param_2,0);
  do {
    if (pvVar1 == (void *)0x0) {
      local_18 = (void *)0x0;
      local_14 = (undefined4 *)0x0;
      local_10 = 0;
      uVar5 = (uint)local_4 >> 8;
      local_4 = CONCAT31((int3)uVar5,1);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (int)plVar4 - (int)_Memory >> 2;
      }
      uVar5 = iVar3 - 1;
      if (-1 < (int)uVar5) {
        puVar7 = (undefined4 *)((int)_Memory + uVar5 * 4);
        do {
          if ((_Memory == (void *)0x0) || ((uint)((int)plVar4 - (int)_Memory >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_00406800();
          }
          if ((local_18 == (void *)0x0) ||
             ((uint)(local_10 - (int)local_18 >> 2) <= (uint)((int)local_14 - (int)local_18 >> 2)))
          {
            FUN_0040ccc0(local_1c,local_14,1,puVar7);
          }
          else {
            *local_14 = *puVar7;
            local_14 = local_14 + 1;
          }
          uVar5 = uVar5 - 1;
          puVar7 = puVar7 + -1;
        } while (-1 < (int)uVar5);
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
      }
      local_28 = (void *)0x0;
      local_24 = (long *)0x0;
      local_20 = 0;
      FUN_0040dcc0(param_1,(int)local_1c);
      if (local_18 != (void *)0x0) {
        _free(local_18);
      }
      ExceptionList = local_c;
      return param_1;
    }
    if (*(int *)((int)pvVar1 + 0x24) == 0) {
      pcVar2 = "";
    }
    else {
      pcVar2 = *(char **)((int)pvVar1 + 0x20);
    }
    iVar3 = 9;
    bVar8 = true;
    pcVar6 = "Sequence";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar8 = *pcVar2 == *pcVar6;
      pcVar2 = pcVar2 + 1;
      pcVar6 = pcVar6 + 1;
    } while (bVar8);
    if (bVar8) {
      if ((pvVar1 == (void *)0x0) || (this = pvVar1, *(int *)((int)pvVar1 + 0x14) != 1)) {
        this = (void *)0x0;
      }
      pcVar2 = FUN_00474a10(this,"frames");
      pcVar2 = _strtok(pcVar2,",");
      while (pcVar2 != (char *)0x0) {
        local_30 = _atol(pcVar2);
        if ((_Memory == (void *)0x0) ||
           ((uint)(local_20 - (int)_Memory >> 2) <= (uint)((int)plVar4 - (int)_Memory >> 2))) {
          FUN_0040ccc0(local_2c,plVar4,1,&local_30);
          _Memory = local_28;
        }
        else {
          *plVar4 = local_30;
          local_24 = plVar4 + 1;
        }
        plVar4 = local_24;
        pcVar2 = _strtok((char *)0x0,",");
      }
    }
    pvVar1 = (void *)FUN_004734f0(param_2,(int)pvVar1);
  } while( true );
}

