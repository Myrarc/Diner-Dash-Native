/* Address: 0047ab30; name: FUN_0047ab30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0047ab30(void *this,char param_1)

{
  double dVar1;
  bool bVar2;
  char cVar3;
  DWORD DVar4;
  undefined4 uVar5;
  DWORD DVar6;
  DWORD dwMilliseconds;
  uint uVar7;
  int iVar8;
  undefined4 unaff_EDI;
  ulonglong uVar9;
  undefined2 uVar10;
  undefined8 local_20;
  undefined8 local_18;
  undefined4 local_c;
  
  if (*(char *)((int)this + 0x4a9) != '\0') {
    (**(code **)(*(int *)this + 0xa0))();
  }
  uVar10 = (undefined2)unaff_EDI;
  if (((((*(char *)((int)this + 0x4b9) == '\0') && (*(char *)((int)this + 0x55c) != '\0')) &&
       (*(char *)((int)this + 0x401) == '\0')) && (*(char *)((int)this + 0x55d) == '\0')) &&
     ((*(char *)((int)this + 0x308) == '\0' ||
      ((*(char *)((int)this + 0x56c) != '\0' && (*(char *)((int)this + 0x56d) == '\0')))))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (*(char *)((int)this + 0x55c) == '\0') {
    local_20 = (double)*(int *)((int)this + 0x3fc) / *(double *)((int)this + 0x438);
    local_18 = _DAT_005874d8;
  }
  else {
    local_20 = (_DAT_00588458 / (double)*(int *)((int)this + 0x558)) /
               *(double *)((int)this + 0x438);
    local_18 = _DAT_00588458 / (double)(*(int *)((int)this + 0x3fc) * *(int *)((int)this + 0x558));
  }
  if (*(char *)((int)this + 0x4b9) != '\0') {
    if ((*(int *)((int)this + 0x42c) < *(int *)((int)this + 0x444)) ||
       (*(char *)((int)this + 0x448) != '\0')) {
      if ((*(char *)((int)this + 1000) == '\0') && (*(char *)((int)this + 0x449) == '\0')) {
        *(undefined1 *)((int)this + 1000) = 1;
        (**(code **)(*(int *)this + 0xe4))();
      }
      if ((_DAT_005ba104 & 1) == 0) {
        _DAT_005ba104 = _DAT_005ba104 | 1;
        _DAT_005ba100 = GetTickCount();
      }
      while ((uVar10 = (undefined2)unaff_EDI,
             *(int *)((int)this + 0x42c) < *(int *)((int)this + 0x444) ||
             (*(char *)((int)this + 0x448) != '\0'))) {
        DVar4 = timeGetTime();
        *(double *)((int)this + 0x410) = _DAT_00587c80;
        iVar8 = *(int *)((int)this + 0x42c);
        *(DWORD *)((int)this + 0x418) = DVar4;
        uVar5 = (**(code **)(*(int *)this + 0x24))();
        if ((char)uVar5 != '\0') {
          *(double *)((int)this + 0x408) =
               (local_18 + *(double *)((int)this + 0x408)) - _DAT_005874d8;
          FUN_0047aa70((int)this);
          if (_DAT_005874d8 <= *(double *)((int)this + 0x408)) {
            do {
              FUN_00477800(this);
              cVar3 = (**(code **)(*(int *)this + 0x24))();
              if (cVar3 == '\0') break;
              FUN_0047aa70((int)this);
              *(double *)((int)this + 0x408) = *(double *)((int)this + 0x408) - _DAT_005874d8;
            } while (_DAT_005874d8 <= *(double *)((int)this + 0x408));
          }
          (**(code **)(*(int *)this + 0x28))();
          uVar5 = FUN_0047aa70((int)this);
        }
        if (iVar8 == *(int *)((int)this + 0x42c)) goto LAB_0047b0b5;
        DVar4 = GetTickCount();
        if ((999 < DVar4 - _DAT_005ba100) || (*(char *)((int)this + 0x449) != '\0')) {
          *(undefined1 *)((int)this + 0x449) = 0;
          _DAT_005ba100 = GetTickCount();
          uVar5 = (**(code **)(*(int *)this + 0x14c))();
          return CONCAT31((int3)((uint)uVar5 >> 8),1);
        }
      }
    }
    if (*(char *)((int)this + 1000) != '\0') {
      *(undefined1 *)((int)this + 1000) = 0;
      (**(code **)(**(int **)((int)this + 0x460) + 0x40))();
      (**(code **)(*(int *)this + 0xe8))();
    }
  }
  if ((*(char *)((int)this + 0x440) != '\0') || (*(double *)((int)this + 0x438) <= _DAT_00587c80))
  goto LAB_0047b0ae;
  DVar4 = timeGetTime();
  local_c = 0;
  if (!bVar2) {
    FUN_00477f80((int)this);
  }
  if (*(int *)((int)this + 0x430) == 1) {
    dVar1 = *(double *)((int)this + 0x438) * _DAT_00588450;
    *(int *)((int)this + 0x3f8) = *(int *)((int)this + 0x3f8) + 1;
    FUN_005626d0(dVar1,uVar10);
    uVar9 = FUN_00560568();
    if ((*(int *)((int)this + 0x3f8) < (int)uVar9) || (*(char *)((int)this + 0x4a7) == '\0')) {
      if (bVar2) {
        if (*(char *)((int)this + 0x402) != '\0') {
          uVar9 = FUN_00560568();
          if ((double)(int)uVar9 < *(double *)((int)this + 0x410) ==
              ((double)(int)uVar9 == *(double *)((int)this + 0x410))) goto LAB_0047ae5c;
        }
      }
      else if (*(double *)((int)this + 0x410) < local_20) goto LAB_0047ae5c;
      if ((((*(char *)((int)this + 0x4b9) == '\0') && (*(int *)((int)this + 0x438) == 0)) &&
          (*(int *)((int)this + 0x43c) == 0x3ff00000)) &&
         (uVar7 = *(int *)((int)this + 0x568) + 1, *(uint *)((int)this + 0x568) = uVar7,
         (uint)((*(int *)((int)this + 0x3fc) + 999) / *(int *)((int)this + 0x3fc)) <= uVar7)) {
        if (DVar4 - *(int *)((int)this + 0x564) < 0x321) {
          iVar8 = *(int *)((int)this + 0x560) + 1;
          *(int *)((int)this + 0x560) = iVar8;
          if (2 < iVar8) {
            *(undefined1 *)((int)this + 0x55d) = 1;
          }
        }
        else {
          *(undefined4 *)((int)this + 0x560) = 0;
        }
        *(DWORD *)((int)this + 0x564) = DVar4;
        *(undefined4 *)((int)this + 0x568) = 0;
      }
      cVar3 = (**(code **)(*(int *)this + 0x24))();
      if (cVar3 != '\0') {
        *(undefined4 *)((int)this + 0x430) = 2;
      }
      *(undefined1 *)((int)this + 0x402) = 1;
    }
    else {
LAB_0047ae5c:
      *(undefined4 *)((int)this + 0x430) = 3;
      *(undefined4 *)((int)this + 0x3f8) = 0;
      if (*(char *)((int)this + 0x402) == '\0') {
        uVar9 = FUN_00560568();
        DVar6 = (DWORD)uVar9;
        if (0 < (int)DVar6) {
          dwMilliseconds = CONCAT31((int3)(uVar9 >> 8),param_1);
          if (param_1 == '\0') goto LAB_0047b09c;
          *(int *)((int)this + 0x424) = *(int *)((int)this + 0x424) + 1;
          Sleep(DVar6);
          local_c = DVar6;
        }
      }
      else {
        (**(code **)(*(int *)this + 0x14c))();
      }
    }
  }
  else {
    if (*(int *)((int)this + 0x430) != 2) goto LAB_0047ae5c;
    *(undefined4 *)((int)this + 0x430) = 3;
    *(double *)((int)this + 0x408) = (local_18 + *(double *)((int)this + 0x408)) - _DAT_005874d8;
    FUN_0047aa70((int)this);
    if (_DAT_005874d8 <= *(double *)((int)this + 0x408)) {
      do {
        FUN_00477800(this);
        *(int *)((int)this + 0x3f8) = *(int *)((int)this + 0x3f8) + 1;
        cVar3 = (**(code **)(*(int *)this + 0x24))();
        if (cVar3 == '\0') break;
        FUN_0047aa70((int)this);
        *(double *)((int)this + 0x408) = *(double *)((int)this + 0x408) - _DAT_005874d8;
      } while (_DAT_005874d8 <= *(double *)((int)this + 0x408));
    }
    (**(code **)(*(int *)this + 0x28))();
    FUN_0047aa70((int)this);
    local_20 = *(double *)((int)this + 0x410) - local_20;
    if ((bVar2) && (local_20 = local_20 - _DAT_00588440, local_20 <= _DAT_00587c80)) {
      local_20 = _DAT_00587c80;
    }
    *(double *)((int)this + 0x410) = local_20;
    if (0 < *(int *)((int)this + 0x7c)) {
      *(double *)((int)this + 0x410) = _DAT_00587c80;
    }
  }
  if (*(char *)((int)this + 0x4a8) != '\0') {
    DVar6 = timeGetTime();
    dwMilliseconds = DVar6 * 2 + local_c * -3 + DVar4 * -2;
    if ((int)dwMilliseconds < 0xfb) {
      if ((int)dwMilliseconds < 0) goto LAB_0047b0ae;
    }
    else {
      dwMilliseconds = 0xfa;
    }
    if (param_1 == '\0') {
LAB_0047b09c:
      return dwMilliseconds & 0xffffff00;
    }
    Sleep(dwMilliseconds);
  }
LAB_0047b0ae:
  uVar5 = FUN_0047aa70((int)this);
LAB_0047b0b5:
  return CONCAT31((int3)((uint)uVar5 >> 8),1);
}


