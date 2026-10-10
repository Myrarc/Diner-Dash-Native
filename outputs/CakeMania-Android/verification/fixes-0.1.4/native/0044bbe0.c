/* Address: 0044bbe0; name: FUN_0044bbe0 */

void __thiscall FUN_0044bbe0(void *this,void *param_1)

{
  float *this_00;
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_10 [16];
  
  FUN_004c5bd0("Start_Of_Draw");
  puVar1 = (undefined4 *)FUN_0048c7b0(local_10,0,0,0);
  FUN_00493640(param_1,puVar1);
  FUN_0049b8e0(param_1,0,0,*(undefined4 *)((int)this + 0x34),*(undefined4 *)((int)this + 0x38));
  FUN_004785c0(*(int *)((int)this + 0x84));
  FUN_00437d20((void *)((int)this + 0x1ac),param_1,&LAB_0044a630);
  FUN_0040e8c0((void *)((int)this + 0x1fc),param_1);
  FUN_004785c0(*(int *)((int)this + 0x84));
  FUN_004366b0((void *)((int)this + 0x1ac),param_1);
  FUN_0044b790(this,param_1);
  this_00 = (float *)((int)this + 0x168);
  FUN_00409c00(this_00,param_1);
  FUN_00419a30(*(void **)((int)this + 0x1a4),param_1);
  if ((*(float *)((int)this + 0x308) < *this_00) && (*(char *)((int)this + 0x198) == '\0')) {
    FUN_00409d00(this_00,0.5);
    (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b98bc);
  }
  if (*(void **)((int)this + 0x2d4) != (void *)0x0) {
    FUN_00452ab0(*(void **)((int)this + 0x2d4),param_1,this);
  }
  if (*(void **)((int)this + 0x2d8) != (void *)0x0) {
    FUN_00453a50(*(void **)((int)this + 0x2d8),param_1,this);
  }
  if (*(void **)((int)this + 0x2dc) != (void *)0x0) {
    FUN_0044a580(*(void **)((int)this + 0x2dc),param_1);
  }
  iVar2 = FUN_00418c60((int)this + 0x398);
  if (iVar2 == 0) {
    FUN_00419090((void *)((int)this + 0x398),param_1,(int)this + 0x88);
  }
  if (*(char *)((int)this + 0x434) != '\0') {
    FUN_00418d20((void *)((int)this + 0x330),param_1,(int)this + 0x88);
  }
  iVar2 = (**(code **)(**(int **)((int)this + 0x84) + 0x108))(9);
  if (iVar2 != 0) {
    FUN_00493670(param_1,1);
    puVar1 = (undefined4 *)FUN_0048c7e0(&stack0xffffffec,0,0,0,0x96);
    FUN_00493640(param_1,puVar1);
    FUN_0049b8e0(param_1,0,0,*(undefined4 *)((int)this + 0x34),*(undefined4 *)((int)this + 0x38));
    FUN_00493670(param_1,0);
    puVar1 = (undefined4 *)FUN_0048c7e0(&stack0xffffffec,0xff,0xff,0xff,0xff);
    FUN_00493640(param_1,puVar1);
  }
  FUN_004c5c10("Start_Of_Draw");
  return;
}


