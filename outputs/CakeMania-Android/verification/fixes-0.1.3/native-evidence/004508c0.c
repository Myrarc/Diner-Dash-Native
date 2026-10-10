/* Address: 004508c0; name: FUN_004508c0 */

void __thiscall FUN_004508c0(void *this,int param_1,float param_2,int param_3)

{
  void *pvVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  float local_8;
  float local_4;
  
  iVar5 = param_3;
  fVar3 = param_2;
  if (param_3 == 3) {
    *(undefined1 *)((int)this + 0x2e6) = 1;
  }
  else if (param_3 < 1) {
    if (param_3 < 0) {
      *(undefined1 *)((int)this + 0x2e5) = 1;
    }
  }
  else {
    fVar2 = (float)param_1;
    *(int *)((int)this + 0x2dc) = param_1;
    *(float *)((int)this + 0x2e0) = param_2;
    *(undefined1 *)((int)this + 0x2e4) = 1;
    param_2 = (float)(int)param_2;
    uVar4 = FUN_00401010(*(int *)((int)this + 0x454),*(int *)((int)this + 0x458),
                         *(int *)((int)this + 0x45c),*(int *)((int)this + 0x460),fVar2,param_2);
    if ((char)uVar4 != '\0') {
      *(undefined4 *)((int)this + 0x454) = 0xffffffff;
      *(undefined4 *)((int)this + 0x458) = 0xffffffff;
      *(undefined4 *)((int)this + 0x45c) = 1;
      *(undefined4 *)((int)this + 0x460) = 1;
      *(undefined1 *)((int)this + 0x44c) = 1;
      if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d0c) == 0) {
        pvVar1 = (void *)((int)this + 0x158);
        if ((*(int *)((int)this + 0x15c) == 0) ||
           (*(int *)((int)this + 0x160) - *(int *)((int)this + 0x15c) >> 3 == 0)) {
          FUN_0044f2b0(this,param_1,(int)fVar3);
        }
        else {
          FUN_004068e0(pvVar1,0);
          FUN_004068e0(pvVar1,0);
          uVar8 = FUN_00560568();
          iVar5 = (int)uVar8;
          uVar8 = FUN_00560568();
          FUN_0044f2b0(this,(int)uVar8,iVar5);
          FUN_0044b5d0(pvVar1,&local_8,*(undefined4 **)((int)this + 0x15c));
          iVar5 = param_3;
        }
      }
      else {
        uVar7 = FUN_0044e0b0(this,param_1,(int)fVar3);
        if ((char)uVar7 != '\0') {
          local_4 = param_2;
          local_8 = fVar2;
          FUN_0040ed00((void *)((int)this + 0x158),&local_8);
        }
      }
    }
    iVar6 = FUN_0040b4e0((void *)((int)this + 0x1fc),fVar2,param_2);
    if (((*(int *)((int)this + 0x464) != -1) && (iVar6 != 0)) &&
       (*(int *)(iVar6 + 0x278) == *(int *)((int)this + 0x464))) {
      *(undefined1 *)((int)this + 0x44c) = 1;
      *(undefined4 *)((int)this + 0x464) = 0xffffffff;
      if (*(int *)(*(int *)((int)this + 0x1a8) + 0x9d0c) == 0) {
        pvVar1 = (void *)((int)this + 0x158);
        iVar6 = FUN_004011d0((int)pvVar1);
        if (iVar6 == 0) {
          FUN_0044f2b0(this,param_1,(int)fVar3);
        }
        else {
          FUN_004068e0(pvVar1,0);
          FUN_004068e0(pvVar1,0);
          uVar8 = FUN_00560568();
          iVar5 = (int)uVar8;
          uVar8 = FUN_00560568();
          FUN_0044f2b0(this,(int)uVar8,iVar5);
          FUN_0044b5d0(pvVar1,&param_2,*(undefined4 **)((int)this + 0x15c));
          iVar5 = param_3;
        }
      }
      else {
        uVar7 = FUN_0044e0b0(this,param_1,(int)fVar3);
        if ((char)uVar7 != '\0') {
          local_4 = param_2;
          local_8 = fVar2;
          FUN_0040ed00((void *)((int)this + 0x158),&local_8);
        }
      }
    }
  }
  FUN_004d1fd0(this,param_1,fVar3,iVar5);
  return;
}


