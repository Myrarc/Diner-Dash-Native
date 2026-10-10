/* Address: 0041f290; name: FUN_0041f290 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __fastcall FUN_0041f290(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 *this;
  int iVar3;
  LPCSTR *****ppppppCVar4;
  int iVar5;
  uint uVar6;
  undefined4 in_stack_fffffef8;
  uint in_stack_fffffefc;
  void *pvVar7;
  char cVar8;
  undefined1 auStack_d8 [92];
  LPCSTR ****apppppCStack_7c [5];
  uint uStack_68;
  LPCSTR ****apppppCStack_60 [5];
  uint uStack_4c;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00575439;
  local_c = ExceptionList;
  local_10 = DAT_005b83e8;
  uVar6 = 0;
  if (*(int *)(param_1 + 0x70c) == 0) {
    if (*(int *)(param_1 + 0x710) == 1) {
      ExceptionList = &local_c;
      FUN_0041ba80(param_1);
      ExceptionList = local_c;
      return;
    }
    if (*(int *)(param_1 + 0x710) == 2) {
      ExceptionList = &local_c;
      FUN_0041f170(param_1);
      ExceptionList = local_c;
      return;
    }
  }
  ExceptionList = &local_c;
  if (*(undefined4 **)(param_1 + 0x614) != (undefined4 *)0x0) {
    ExceptionList = &local_c;
    (**(code **)**(undefined4 **)(param_1 + 0x614))();
  }
  *(undefined4 *)(param_1 + 0x614) = 0;
  pvVar2 = operator_new(0x464);
  uStack_4 = 0;
  if (pvVar2 == (void *)0x0) {
    this = (undefined4 *)0x0;
  }
  else {
    this = FUN_00471750(pvVar2,param_1);
  }
  uStack_4 = 0xffffffff;
  *(undefined4 **)(param_1 + 0x614) = this;
  FUN_0046fd50(this,"ShopCareerScreen/shop_env.xml");
  pvVar2 = (void *)(param_1 + 0x638);
  FUN_00421870(pvVar2);
  FUN_00421870(pvVar2);
  while( true ) {
    uVar1 = *(uint *)(param_1 + 0x70c);
    iVar3 = FUN_00421870(pvVar2);
    iVar5 = *(int *)(iVar3 + 0x30);
    if ((iVar5 == 0) || ((uint)(*(int *)(iVar3 + 0x34) - iVar5 >> 2) <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      FUN_0041a290();
    }
    iVar3 = uVar6 * 4;
    uVar6 = uVar6 + 1;
    if (*(int *)(*(int *)(iVar5 + uVar1 * 4) + iVar3) == 0) break;
    if (0xb < uVar6) {
LAB_0041f3b2:
      FUN_00421d30(pvVar2,auStack_d8);
      uStack_4 = 1;
      pvVar7 = (void *)(in_stack_fffffefc & 0xffffff00);
      FUN_00401f60(&stack0xfffffef8,(undefined4 *)&DAT_0058161c,0);
      ppppppCVar4 = (LPCSTR *****)apppppCStack_60[0];
      if (uStack_4c < 0x10) {
        ppppppCVar4 = apppppCStack_60;
      }
      FUN_00405c80(*(void **)(*(int *)(param_1 + 0x614) + 0x174),(LPCSTR)ppppppCVar4,
                   in_stack_fffffef8,pvVar7);
      pvVar7 = (void *)((uint)pvVar7 & 0xffffff00);
      FUN_00401f60(&stack0xfffffef8,(undefined4 *)&DAT_0058161c,0);
      if (uStack_4c < 0x10) {
        apppppCStack_60[0] = (LPCSTR ****)apppppCStack_60;
      }
      FUN_00405c80(*(void **)(*(int *)(param_1 + 0x614) + 0x178),(LPCSTR)apppppCStack_60[0],
                   in_stack_fffffef8,pvVar7);
      *(undefined4 *)(*(int *)(param_1 + 0x614) + 0xb0) =
           *(undefined4 *)(*(int *)(param_1 + 0x614) + 0x174);
      *(int *)(*(int *)(param_1 + 0x614) + 0x88) = param_1 + 0x664;
      ppppppCVar4 = (LPCSTR *****)apppppCStack_7c[0];
      if (uStack_68 < 0x10) {
        ppppppCVar4 = apppppCStack_7c;
      }
      FUN_004440a0((void *)(*(int *)(param_1 + 0x614) + 0x84),(LPCSTR)ppppppCVar4,'\x01');
      cVar8 = '\x01';
      iVar5 = FUN_00421870(pvVar2);
      FUN_00444a00((void *)(*(int *)(param_1 + 0x614) + 0x84),iVar5 + 0x4c,cVar8);
      if (uStack_68 < 0x10) {
        apppppCStack_7c[0] = (LPCSTR ****)apppppCStack_7c;
      }
      FUN_004440a0((void *)(*(int *)(param_1 + 0x614) + 0x124),(LPCSTR)apppppCStack_7c[0],'\0');
      FUN_0046fa80(*(int *)(param_1 + 0x614));
      (**(code **)(**(int **)(param_1 + 0x614) + 100))();
      FUN_004d8dc0(*(void **)(param_1 + 0x2e4),*(int **)(param_1 + 0x614));
      FUN_004d1b90(*(void **)(param_1 + 0x2e4),*(int **)(param_1 + 0x614));
      FUN_0041b5a0((int)auStack_d8);
      ExceptionList = local_c;
      return;
    }
  }
  *(uint *)(param_1 + 0x710) = uVar6;
  goto LAB_0041f3b2;
}


