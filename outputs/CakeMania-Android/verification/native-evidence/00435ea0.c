/* Address: 00435ea0; name: FUN_00435ea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00435ea0(void *this,float param_1,float param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  int *piVar6;
  
  iVar2 = **(int **)((int)this + 0x28);
  uVar3 = FUN_00401010(*(int *)(iVar2 + 0x38) + *(int *)((int)this + 0x4c),
                       *(int *)(iVar2 + 0x3c) + *(int *)((int)this + 0x50),*(int *)(iVar2 + 0x40),
                       *(int *)(iVar2 + 0x44),param_1,param_2);
  if ((char)uVar3 == '\0') {
    return uVar3 & 0xffffff00;
  }
  if (*(char *)((int)this + 0xd3) == '\0') {
    fVar1 = *(float *)((int)this + 0x68);
    uVar5 = CONCAT22((short)(uVar3 >> 0x10),
                     (ushort)(fVar1 < _DAT_0059d334) << 8 |
                     (ushort)(NAN(fVar1) || NAN(_DAT_0059d334)) << 10 |
                     (ushort)(fVar1 == _DAT_0059d334) << 0xe);
    if (fVar1 == _DAT_0059d334) {
      *(undefined4 *)((int)this + 0x120) = **(undefined4 **)((int)this + 0x28);
      *(undefined1 *)((int)this + 0xd3) = 1;
      *(undefined4 *)((int)this + 0x68) = 0x3f800000;
      uVar5 = (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b98dc);
    }
    return CONCAT31((int3)((uint)uVar5 >> 8),1);
  }
  if ((*(int *)((int)this + 0x120) != 0) &&
     (piVar6 = *(int **)((int)this + 0x28), piVar6 != *(int **)((int)this + 0x2c))) {
    do {
      iVar2 = *(int *)((int)this + 0x120);
      if (*(uint *)(iVar2 + 100) < 0x10) {
        pbVar4 = (byte *)(iVar2 + 0x50);
      }
      else {
        pbVar4 = *(byte **)(iVar2 + 0x50);
      }
      uVar3 = FUN_004013c0((void *)(*piVar6 + 0x4c),0,*(uint *)(*piVar6 + 0x60),pbVar4,
                           *(uint *)(iVar2 + 0x60));
      if (uVar3 == 0) {
        if (piVar6 == (int *)(*(int *)((int)this + 0x2c) + -4)) {
          *(undefined4 *)((int)this + 0x120) = **(undefined4 **)((int)this + 0x28);
        }
        else {
          *(int *)((int)this + 0x120) = piVar6[1];
        }
        break;
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != *(int **)((int)this + 0x2c));
  }
  *(undefined4 *)((int)this + 0x68) = 0x3f800000;
  uVar5 = (**(code **)(*DAT_005ba088 + 0xc4))(DAT_005b98dc);
  return CONCAT31((int3)((uint)uVar5 >> 8),1);
}


