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


TestFollowMeTalk::
	msgbox TestFollowMeTalk_Text_0
	closemessage
	return


TestFollowMe::
	lock
	faceplayer
	loadword 0, TestFollowMeTalk
	setfollower 1, 0x100
	release
	return


TestSetScript::
	lock
	setvar VAR_T_SLOT, 0
	special ClearTimeEvent
	msgbox TestSetScript_Text_0
	closemessage
	release
	end


TestSetScript2::
	lock
	setvar VAR_T_SLOT, 1
	special ClearTimeEvent
	msgbox TestSetScript2_Text_0
	closemessage
	release
	end


TestTimeEvent::
	lock
	setvar VAR_T_SLOT, 0
	setvar VAR_T_DAYS, 0
	setvar VAR_T_HOURS, 0
	setvar VAR_T_MINUTES, 10
	loadword 0, TestSetScript
	special SetTimeEvent
	setvar VAR_T_SLOT, 1
	setvar VAR_T_DAYS, 0
	setvar VAR_T_HOURS, 0
	setvar VAR_T_MINUTES, 20
	loadword 0, TestSetScript2
	special SetTimeEvent
	end


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

TestFollowMeTalk_Text_0:
	.string "测试跟随对话。$"

TestSetScript_Text_0:
	.string "这是10分钟前设置的事件。\n(现实10秒)$"

TestSetScript2_Text_0:
	.string "这是20分钟前设置的事件。\n(现实20秒)$"
