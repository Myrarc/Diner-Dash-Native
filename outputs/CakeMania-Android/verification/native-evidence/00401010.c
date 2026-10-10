/* Address: 00401010; name: FUN_00401010 */

uint __cdecl
FUN_00401010(int param_1,int param_2,int param_3,int param_4,float param_5,float param_6)

{
  float fVar1;
  uint uVar2;
  undefined2 uVar3;
  
  uVar2 = DAT_005ba088;
  if (*(char *)(DAT_005ba088 + 0x47a) != '\0') {
    fVar1 = (float)(param_3 + param_1);
    uVar3 = (undefined2)(DAT_005ba088 >> 0x10);
    uVar2 = CONCAT22(uVar3,(ushort)(fVar1 < param_5) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_5)) << 10 |
                           (ushort)(fVar1 == param_5) << 0xe);
    if (fVar1 >= param_5) {
      fVar1 = (float)param_1;
      uVar2 = CONCAT22(uVar3,(ushort)(fVar1 < param_5) << 8 |
                             (ushort)(NAN(fVar1) || NAN(param_5)) << 10 |
                             (ushort)(fVar1 == param_5) << 0xe);
      if (fVar1 < param_5 != (fVar1 == param_5)) {
        fVar1 = (float)(param_4 + param_2);
        uVar3 = (undefined2)((uint)param_2 >> 0x10);
        uVar2 = CONCAT22(uVar3,(ushort)(fVar1 < param_6) << 8 |
                               (ushort)(NAN(fVar1) || NAN(param_6)) << 10 |
                               (ushort)(fVar1 == param_6) << 0xe);
        if (fVar1 >= param_6) {
          fVar1 = (float)param_2;
          uVar2 = CONCAT22(uVar3,(ushort)(fVar1 < param_6) << 8 |
                                 (ushort)(NAN(fVar1) || NAN(param_6)) << 10 |
                                 (ushort)(fVar1 == param_6) << 0xe);
          if (fVar1 < param_6 != (fVar1 == param_6)) {
            return CONCAT31((int3)(uVar2 >> 8),1);
          }
        }
      }
    }
  }
  return uVar2 & 0xffffff00;
}


