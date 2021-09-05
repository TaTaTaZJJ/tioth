SpawnPlace_MapScripts::
	.byte 0


TestAddMoneywithVar::
	lock
	setvar VAR_0x8000, 999
	addmoneywithvar VAR_0x8000, 0
	msgbox TestAddMoneywithVar_Text_0
	release
	return


TestSubMoneywithVar::
	lock
	setvar VAR_0x8000, 999
	removemoneywithvar VAR_0x8000, 0
	msgbox TestSubMoneywithVar_Text_0
	release
	return


TestMultMoneywithVar::
	lock
	setvar VAR_0x8000, 3
	multiplymoneywithvar VAR_0x8000, 0
	msgbox TestMultMoneywithVar_Text_0
	release
	return


TestCheckMoneywithVar::
	lock
	setvar VAR_0x8000, 2999
	checkmoneywithvar VAR_0x8000, 0
	msgbox TestCheckMoneywithVar_Text_0
	compare VAR_RESULT, TRUE
	goto_if_eq TestCheckMoneywithVar_2
	msgbox TestCheckMoneywithVar_Text_2
TestCheckMoneywithVar_1:
	release
	return

TestCheckMoneywithVar_2:
	msgbox TestCheckMoneywithVar_Text_1
	goto TestCheckMoneywithVar_1


Test2v2TrainerBattle::
	msgbox Test2v2TrainerBattle_Text_0
	closemessage
	givemon SPECIES_CYNDAQUIL, 100, 0
	givemon SPECIES_CYNDAQUIL, 100, 0
	givemon SPECIES_CYNDAQUIL, 100, 0
	multi_fixed_2_vs_2 TRAINER_WALLACE, Test2v2TrainerBattle_Text_1, TRAINER_SIDNEY, Test2v2TrainerBattle_Text_2, TRAINER_RICK, TRAINER_BACK_PIC_RED
	return


TestAddMoneywithVar_Text_0:
	.string "设置变数8000值为999\n测试钱包值增加变数8000值。$"

TestSubMoneywithVar_Text_0:
	.string "设置变数8000值为999\n测试钱包值减少变数8000值。$"

TestMultMoneywithVar_Text_0:
	.string "设置变数8000值为3\n测试钱包值乘以变数8000值。$"

TestCheckMoneywithVar_Text_0:
	.string "设置变数8000值为2999\n测试钱包高于变数8000值。$"

TestCheckMoneywithVar_Text_1:
	.string "钱包值高于变数8000值$"

TestCheckMoneywithVar_Text_2:
	.string "钱包值低于变数8000值$"

Test2v2TrainerBattle_Text_0:
	.string "测试双打。$"

Test2v2TrainerBattle_Text_1:
	.string "冠军$"

Test2v2TrainerBattle_Text_2:
	.string "天王$"
