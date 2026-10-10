/* Address: 0041c460; name: FUN_0041c460 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0041c460(void *param_1)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_stack_fffffee8;
  uint in_stack_fffffeec;
  undefined1 auStack_d8 [52];
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  LPCSTR *appCStack_70 [5];
  uint uStack_5c;
  void *pvStack_1c;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00575439;
  pvStack_c = ExceptionList;
  local_10 = DAT_005b83e8;
  ExceptionList = &pvStack_c;
  FUN_0041ab10(param_1,*(undefined4 *)((int)param_1 + 0x70c));
  uVar6 = 0;
  if (*(undefined4 **)((int)param_1 + 0x60c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)param_1 + 0x60c))();
  }
  *(undefined4 *)((int)param_1 + 0x60c) = 0;
  pvVar3 = operator_new(0x220);
  uStack_4 = 0;
  if (pvVar3 == (void *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = FUN_0046b420(pvVar3,param_1);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 **)((int)param_1 + 0x60c) = puVar4;
  while( true ) {
    uVar1 = *(uint *)((int)param_1 + 0x70c);
    iVar5 = FUN_00421870((void *)((int)param_1 + 0x638));
    iVar2 = *(int *)(iVar5 + 0x30);
    if ((iVar2 == 0) || ((uint)(*(int *)(iVar5 + 0x34) - iVar2 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    iVar5 = uVar6 * 4;
    uVar6 = uVar6 + 1;
    if (*(int *)(*(int *)(iVar2 + uVar1 * 4) + iVar5) == 0) break;
    if (0xb < uVar6) {
LAB_0041c532:
      *(int *)(*(int *)((int)param_1 + 0x60c) + 0x210) = *(int *)((int)param_1 + 0x710) + -1;
      FUN_00421d30((void *)((int)param_1 + 0x638),auStack_d8);
      iVar2 = *(int *)((int)param_1 + 0x60c);
      *(undefined4 *)(iVar2 + 0x218) = uStack_a4;
      *(undefined4 *)(iVar2 + 0x214) = uStack_a0;
      uStack_4 = 1;
      (**(code **)(**(int **)((int)param_1 + 0x60c) + 100))();
      pvVar3 = (void *)(in_stack_fffffeec & 0xffffff00);
      FUN_00401f60(&stack0xfffffee8,(undefined4 *)"MapScreen/pathes.xml",0x14);
      if (uStack_5c < 0x10) {
        appCStack_70[0] = (LPCSTR *)appCStack_70;
      }
      FUN_00405c80(*(void **)(*(int *)((int)param_1 + 0x60c) + 400),(LPCSTR)appCStack_70[0],
                   in_stack_fffffee8,pvVar3);
      *(undefined4 *)(*(int *)((int)param_1 + 0x60c) + 0x1ac) =
           *(undefined4 *)((int)param_1 + 0x70c);
      FUN_0046c6b0(*(void **)((int)param_1 + 0x60c),"MapScreen/map_env.xml");
      FUN_004d8dc0(*(void **)((int)param_1 + 0x2e4),*(int **)((int)param_1 + 0x60c));
      FUN_004d1b90(*(void **)((int)param_1 + 0x2e4),*(int **)((int)param_1 + 0x60c));
      FUN_0041b5a0((int)&stack0xffffff18);
      ExceptionList = pvStack_1c;
      return;
    }
  }
  *(uint *)((int)param_1 + 0x710) = uVar6;
  goto LAB_0041c532;
}


