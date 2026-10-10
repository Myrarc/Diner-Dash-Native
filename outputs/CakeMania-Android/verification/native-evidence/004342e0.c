/* Address: 004342e0; name: FUN_004342e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004342e0(void *this,void *param_1)

{
  float *pfVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float local_10;
  float local_c;
  
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,1);
    puVar2 = (undefined4 *)FUN_0048c7e0(&local_10,0,0,0,0x7a);
    FUN_00493640(param_1,puVar2);
  }
  if (((*(char *)((int)this + 0xd1) == '\0') && (*(char *)((int)this + 0xd0) != '\0')) ||
     (*(char *)((int)this + 0xd0) == '\0')) {
    uVar4 = FUN_00560568();
    uVar3 = (undefined4)uVar4;
    uVar4 = FUN_00560568();
    uVar5 = (undefined4)uVar4;
    FUN_00560568();
    uVar4 = FUN_00560568();
    uVar6 = (undefined4)uVar4;
    FUN_00560568();
    uVar4 = FUN_00560568();
    FUN_0049bbe0(param_1,*(int *)((int)this + 4),(int)uVar4,uVar6,uVar5,uVar3);
  }
  pfVar1 = *(float **)((int)this + 0x34);
  if (pfVar1 != (float *)0x0) {
    local_10 = (float)*(int *)((int)this + 0x54) * _DAT_00581420 + (float)*(int *)((int)this + 0x4c)
               + *(float *)((int)this + 0x3c);
    local_c = (float)*(int *)((int)this + 0x58) * _DAT_00581420 + (float)*(int *)((int)this + 0x50)
              + *(float *)((int)this + 0x40);
    *pfVar1 = local_10;
    pfVar1[1] = local_c;
    FUN_00406570(*(void **)((int)this + 0x34),param_1);
  }
  if (*(char *)((int)this + 0x70) != '\0') {
    uVar6 = 0x1e;
    uVar5 = 0x1e;
    uVar4 = FUN_00560568();
    uVar3 = (undefined4)uVar4;
    uVar4 = FUN_00560568();
    FUN_0049bbe0(param_1,DAT_005b9618,(int)uVar4,uVar3,uVar5,uVar6);
  }
  if (*(char *)((int)this + 0xd4) != '\0') {
    FUN_00493670(param_1,0);
    puVar2 = (undefined4 *)FUN_0048c7e0(&local_10,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar2);
  }
  return;
}


