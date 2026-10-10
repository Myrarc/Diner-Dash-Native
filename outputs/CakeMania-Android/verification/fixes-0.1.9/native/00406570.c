/* Address: 00406570; name: FUN_00406570 */

void __thiscall FUN_00406570(void *this,void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  ulonglong uVar7;
  int local_14;
  undefined4 local_10 [4];
  
  if (*(char *)((int)this + 0x11) == '\0') {
    FUN_004017c0(this,local_10);
    FUN_00401080(600.0,0.0,*(float *)((int)this + 8),*(float *)((int)this + 0xc),
                 *(float *)((int)this + 4));
    piVar6 = *(int **)((int)this + 0x30);
    local_14 = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
    if (piVar6 != (int *)(*(int *)((int)this + 0x34) + -4)) {
      do {
        FUN_00401080(600.0,0.0,*(float *)((int)this + 8),*(float *)((int)this + 0xc),
                     *(float *)((int)this + 4));
        iVar1 = *piVar6;
        uVar7 = FUN_00560568();
        uVar2 = (undefined4)uVar7;
        uVar7 = FUN_00560568();
        uVar3 = (undefined4)uVar7;
        uVar7 = FUN_00560568();
        uVar4 = (undefined4)uVar7;
        uVar7 = FUN_00560568();
        FUN_0049bbe0(param_1,*(int *)(iVar1 + 4),(int)uVar7,uVar4,uVar3,uVar2);
        iVar1 = *(int *)(*piVar6 + 0x14);
        local_14 = local_14 - *(int *)(*piVar6 + 0x10);
        if (iVar1 < 0) {
          local_14 = local_14 + iVar1;
        }
        piVar6 = piVar6 + 1;
        *(float *)((int)this + 0x14) = (float)local_14;
      } while (piVar6 != (int *)(*(int *)((int)this + 0x34) + -4));
    }
    iVar1 = *(int *)(*(int *)((int)this + 0x34) + -4);
    FUN_00493670(param_1,1);
    uVar7 = FUN_00560568();
    puVar5 = (undefined4 *)FUN_0048c7e0(local_10,0xff,0xff,0xff,(int)uVar7);
    FUN_00493640(param_1,puVar5);
    FUN_00401080(600.0,0.0,*(float *)((int)this + 8),*(float *)((int)this + 0xc),
                 *(float *)((int)this + 4));
    uVar7 = FUN_00560568();
    uVar2 = (undefined4)uVar7;
    uVar7 = FUN_00560568();
    uVar3 = (undefined4)uVar7;
    uVar7 = FUN_00560568();
    uVar4 = (undefined4)uVar7;
    uVar7 = FUN_00560568();
    FUN_0049bbe0(param_1,*(int *)(iVar1 + 4),(int)uVar7,uVar4,uVar3,uVar2);
    puVar5 = (undefined4 *)FUN_0048c7e0(local_10,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar5);
    FUN_00493670(param_1,0);
  }
  return;
}


