/* Native address 0044e130; read-only Ghidra audit recovery. */

void __thiscall FUN_0044e130(void *this,void *param_1,int *param_2,char param_3)

{
  int iVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined1 local_10 [16];
  
  uVar3 = FUN_00560568();
  if (param_3 != '\0') {
    FUN_00493670(param_1,1);
    puVar2 = (undefined4 *)FUN_0048c7e0(&local_20,0xff,0xff,0xff,(int)uVar3);
    FUN_00493640(param_1,puVar2);
  }
  iVar1 = *(int *)((int)this + 8);
  if (iVar1 != 0) {
    if (*(int *)((int)this + 0x40) == 1) {
      FUN_0049fb60((int)param_1,iVar1,*(int *)((int)this + 0xc),*(int *)((int)this + 0x10),
                   (double)*(float *)((int)this + 0x1c),0);
    }
    else {
      FUN_0049bbe0(param_1,iVar1,*(undefined4 *)((int)this + 0xc),*(undefined4 *)((int)this + 0x10),
                   *(undefined4 *)((int)this + 0x14),*(undefined4 *)((int)this + 0x18));
    }
  }
  if (*(int *)((int)this + 0x34) != 0) {
    FUN_00493630(param_1,DAT_005b9e30);
    puVar2 = (undefined4 *)FUN_0048c7e0(local_10,0,0,0,(int)uVar3);
    FUN_00493640(param_1,puVar2);
    local_20 = *(int *)((int)this + 0xc) + 7;
    local_1c = *(int *)((int)this + 0x10) + 10;
    local_18 = *(int *)((int)this + 0x14) + -0xe;
    local_14 = *(int *)((int)this + 0x18) + -0xe;
    (**(code **)(*param_2 + 200))(param_1,&local_20,(int)this + 0x20,0xffffffff,0);
  }
  if (param_3 != '\0') {
    FUN_00493670(param_1,0);
    puVar2 = (undefined4 *)FUN_0048c7e0(local_10,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar2);
  }
  return;
}

