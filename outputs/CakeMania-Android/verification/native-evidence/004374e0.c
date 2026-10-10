/* Address: 004374e0; name: FUN_004374e0 */

void __thiscall FUN_004374e0(void *this,uint param_1,void *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  if (((*(int *)((int)this + 0x34) == 0) ||
      (iVar3 = *(int *)(*(int *)(*(int *)((int)this + 0x34) + 0x34) + -4),
      *(int *)(iVar3 + 0x2c) == 2)) || (*(int *)(iVar3 + 0x2c) == 3)) {
    *(undefined4 *)((int)this + 0x68) = 0;
    return;
  }
  puVar1 = operator_new(0x30);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_00406220(puVar1);
  }
  *(uint *)((int)this + 0x6c) = param_1;
  for (uVar5 = 0;
      (iVar3 = *(int *)((int)param_2 + 0x28), uVar6 = param_1, iVar3 != 0 &&
      (uVar5 < (uint)(*(int *)((int)param_2 + 0x2c) - iVar3 >> 2))); uVar5 = uVar5 + 1) {
    if ((iVar3 == 0) || ((uint)(*(int *)((int)param_2 + 0x2c) - iVar3 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
      FUN_00406800();
    }
    uVar6 = uVar5;
    if (param_1 == *(uint *)(iVar3 + uVar5 * 4)) break;
  }
  piVar2 = *(int **)((int)this + 0x28);
  if (piVar2 != *(int **)((int)this + 0x2c)) {
    do {
      if (uVar6 == *(uint *)(*piVar2 + 0x48)) {
        puVar1[9] = *(undefined4 *)(*piVar2 + 0x94);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)((int)this + 0x2c));
  }
  FUN_00406d40(param_2,&local_20,
               *(int *)(*(int *)(*(int *)(*(int *)((int)this + 0x34) + 0x34) + -4) + 0x28),2,uVar6);
  iVar3 = *(int *)(*(int *)((int)this + 0x34) + 0x30);
  if ((iVar3 == 0) || (*(int *)(*(int *)((int)this + 0x34) + 0x34) - iVar3 >> 2 != 1)) {
    (**(code **)*puVar1)(local_1c);
    puVar1[4] = uStack_10;
    puVar1[5] = uStack_c;
  }
  else {
    (**(code **)*puVar1)(local_20);
    puVar1[4] = uStack_18;
    puVar1[5] = uStack_14;
  }
  iVar3 = FUN_00493710(puVar1[1]);
  iVar4 = FUN_00493700(puVar1[1]);
  puVar1[7] = (float)iVar3;
  puVar1[6] = (float)iVar4;
  puVar1[10] = *(undefined4 *)(*(int *)(*(int *)(*(int *)((int)this + 0x34) + 0x34) + -4) + 0x28);
  puVar1[8] = (float)iStack_8;
  FUN_00407870(*(void **)((int)this + 0x34),(int)puVar1);
  return;
}


