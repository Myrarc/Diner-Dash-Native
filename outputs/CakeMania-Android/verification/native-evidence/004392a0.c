/* Address: 004392a0; name: FUN_004392a0 */

void __thiscall FUN_004392a0(void *this,float param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined4 in_stack_ffffffcc;
  byte *in_stack_ffffffd0;
  
  if (*(void **)((int)this + 0x20) != (void *)0x0) {
    _free(*(void **)((int)this + 0x20));
  }
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  piVar6 = *(int **)((int)this + 0x34);
  if (piVar6 != *(int **)((int)this + 0x38)) {
    do {
      piVar1 = (int *)(*piVar6 + 0xfc);
      if (*piVar1 != 0) {
        iVar2 = *(int *)((int)this + 0x20);
        if ((iVar2 == 0) ||
           ((uint)(*(int *)((int)this + 0x28) - iVar2 >> 2) <=
            (uint)(*(int *)((int)this + 0x24) - iVar2 >> 2))) {
          FUN_0040ccc0((void *)((int)this + 0x1c),*(undefined4 **)((int)this + 0x24),1,piVar1);
        }
        else {
          piVar7 = *(int **)((int)this + 0x24);
          *piVar7 = *piVar1;
          *(int **)((int)this + 0x24) = piVar7 + 1;
        }
      }
      (**(code **)(*(int *)*piVar6 + 4))();
      piVar1 = (int *)*piVar6;
      if (piVar1[0x18] == 5) {
        piVar7 = (int *)piVar1[10];
        bVar4 = false;
        if (piVar7 != (int *)piVar1[0xb]) {
          do {
            iVar2 = *(int *)(*piVar7 + 0xac);
            if ((iVar2 != 0) &&
               ((*(int *)(iVar2 + 0x30) == 0 ||
                (*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x30) >> 2 == 0)))) {
              bVar4 = true;
            }
            piVar7 = piVar7 + 1;
          } while (piVar7 != (int *)piVar1[0xb]);
          if (bVar4) {
            (**(code **)(*piVar1 + 0xc))();
          }
        }
      }
      piVar1 = (int *)*piVar6;
      if ((((piVar1[0x18] == 6) && (iVar2 = piVar1[0xd], iVar2 != 0)) &&
          ((*(int *)(iVar2 + 0x30) == 0 ||
           (*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x30) >> 2 == 0)))) &&
         ((*(int *)(iVar2 + 0x30) == 0 ||
          (*(int *)(iVar2 + 0x34) - *(int *)(iVar2 + 0x30) >> 2 == 0)))) {
        (**(code **)(*piVar1 + 0xc))();
      }
      iVar2 = *piVar6;
      if ((*(int *)(iVar2 + 0x60) == 8) && (*(int *)(iVar2 + 0x114) != 0)) {
        if (*(int *)(*(int *)this + 0x600) != 0) {
          in_stack_ffffffd0 = (byte *)((uint)in_stack_ffffffd0 & 0xffffff00);
          FUN_00401e70(&stack0xffffffcc,(void *)(iVar2 + 0x100),0,0xffffffff);
          FUN_004121b0((void *)(*(int *)(*(int *)this + 0x600) + 0x1fc),0,in_stack_ffffffcc,
                       in_stack_ffffffd0);
        }
        FUN_00401f60((void *)(*piVar6 + 0x100),(undefined4 *)&DAT_0058161c,0);
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != *(int **)((int)this + 0x38));
  }
  uVar8 = 0;
  while( true ) {
    iVar2 = *(int *)((int)this + 0x44);
    if (iVar2 == 0) {
      return;
    }
    if ((uint)(*(int *)((int)this + 0x48) - iVar2 >> 2) <= uVar8) {
      return;
    }
    if ((iVar2 == 0) || ((uint)(*(int *)((int)this + 0x48) - iVar2 >> 2) <= uVar8)) break;
    piVar6 = *(int **)(*(int *)(iVar2 + uVar8 * 4) + 0x24);
    while( true ) {
      iVar2 = *(int *)((int)this + 0x44);
      if ((iVar2 == 0) || ((uint)(*(int *)((int)this + 0x48) - iVar2 >> 2) <= uVar8))
      goto LAB_004394ff;
      if (piVar6 == *(int **)(*(int *)(iVar2 + uVar8 * 4) + 0x28)) break;
      iVar2 = *piVar6;
      fVar3 = param_1 + *(float *)(iVar2 + 0x28);
      *(float *)(iVar2 + 0x28) = fVar3;
      if (*(float *)(iVar2 + 0x24) < fVar3) {
        *(undefined4 *)(iVar2 + 0x28) = 0;
      }
      fVar3 = param_1 + *(float *)(iVar2 + 0xc);
      *(float *)(iVar2 + 0xc) = fVar3;
      if (*(float *)(iVar2 + 0x10) < fVar3) {
        iVar5 = *(int *)(iVar2 + 8) + 1;
        *(undefined4 *)(iVar2 + 0xc) = 0;
        *(int *)(iVar2 + 8) = iVar5;
        if (*(int *)(iVar2 + 4) + -1 < iVar5) {
          *(undefined4 *)(iVar2 + 8) = 0;
        }
      }
      piVar6 = piVar6 + 1;
    }
    uVar8 = uVar8 + 1;
  }
LAB_004394ff:
  FUN_00436bc0();
  return;
}


