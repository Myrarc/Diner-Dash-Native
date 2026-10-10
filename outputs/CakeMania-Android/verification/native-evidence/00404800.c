/* Address: 00404800; name: FUN_00404800 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00404800(void *param_1)

{
  float *pfVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  float *pfVar5;
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  float local_8 [2];
  
  if (*(float *)((int)param_1 + 0x10) == _DAT_0059d334) {
    if (*(int *)((int)param_1 + 0x9d0c) == 1) {
      FUN_00404510((int)param_1);
    }
    else {
      iVar2 = 0;
      if (*(int *)((int)param_1 + 0x9cf0) != 0) {
        iVar2 = *(int *)((int)param_1 + 0x9d18);
      }
      uVar4 = iVar2 + 8;
      *(uint *)((int)param_1 + 0x9d14) = uVar4;
      iVar2 = *(int *)((int)param_1 + 0x9dc0);
      if ((iVar2 == 0) || ((uint)(*(int *)((int)param_1 + 0x9dc4) - iVar2 >> 2) <= uVar4)) {
        FUN_004023a0();
        return;
      }
      *(undefined4 *)((int)param_1 + 0x9cec) = *(undefined4 *)(*(int *)(iVar2 + uVar4 * 4) + 8);
    }
    if (*(int *)((int)param_1 + 0x9d0c) == 1) {
      iVar2 = *(int *)((int)param_1 + 0x9da4);
      if (((iVar2 != 0) && (*(int *)((int)param_1 + 0x9da8) - iVar2 >> 3 != 0)) &&
         (*(int *)((int)param_1 + 0x9da8) + -8 != iVar2)) {
        pfVar5 = (float *)(*(int *)((int)param_1 + 0x9da8) + -4);
        do {
          if ((pfVar5[-1] == *(float *)((int)param_1 + 0x18)) &&
             (*pfVar5 == *(float *)((int)param_1 + 0x1c))) {
            uStack_2c = 0x404907;
            FUN_00403460(param_1,pfVar5[-3],pfVar5[-2],pfVar5[-1],*pfVar5);
          }
          uStack_2c = 0x40492d;
          iVar2 = FUN_00401560(param_1,pfVar5[-1],*pfVar5,pfVar5[-3],pfVar5[-2]);
          if (iVar2 == 2) {
            if (pfVar5 + -1 == (float *)(*(int *)((int)param_1 + 0x9da4) + 8)) {
              uStack_2c = 0x40496b;
              FUN_00403460(param_1,pfVar5[-1],*pfVar5,pfVar5[-1],*pfVar5);
              *(uint *)((int)param_1 + 0x9d0c) = (*(int *)((int)param_1 + 0x9d10) != 4) - 1 & 2;
              FUN_00401520(auStack_3c,(undefined4 *)((int)param_1 + 0x9cf0));
              (**(code **)((int)param_1 + 0x9db8))();
              *(undefined1 *)((int)param_1 + 0x14) = 0;
            }
          }
          else if ((iVar2 == 0) || (iVar2 == 1)) {
            puVar3 = (undefined4 *)FUN_00401680(param_1,local_8,pfVar5[-3],pfVar5[-2]);
            *(undefined4 *)((int)param_1 + 0x18) = *puVar3;
            *(undefined4 *)((int)param_1 + 0x1c) = puVar3[1];
          }
          pfVar1 = pfVar5 + -3;
          pfVar5 = pfVar5 + -2;
        } while (pfVar1 != *(float **)((int)param_1 + 0x9da4));
      }
      if (*(int *)((int)param_1 + 0x9d0c) == 1) {
        if ((*(int *)((int)param_1 + 0x9da4) == 0) ||
           (*(int *)((int)param_1 + 0x9da8) - *(int *)((int)param_1 + 0x9da4) >> 3 == 0)) {
          uVar4 = (*(int *)((int)param_1 + 0x9d10) != 4) - 1 & 2;
          *(uint *)((int)param_1 + 0x9d0c) = uVar4;
          if (uVar4 == 1) {
            return;
          }
          FUN_00401520(auStack_3c,(undefined4 *)((int)param_1 + 0x9cf0));
          (**(code **)((int)param_1 + 0x9db8))();
        }
        if (*(int *)((int)param_1 + 0x9d0c) == 1) {
          return;
        }
      }
      if (*(void **)((int)param_1 + 0x9da4) != (void *)0x0) {
        _free(*(void **)((int)param_1 + 0x9da4));
      }
      *(undefined4 *)((int)param_1 + 0x9da4) = 0;
      *(undefined4 *)((int)param_1 + 0x9da8) = 0;
      *(undefined4 *)((int)param_1 + 0x9dac) = 0;
    }
  }
  return;
}


