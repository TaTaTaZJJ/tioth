SpawnPlace_MapScripts::
	.byte 0


TestAddMoneywithVar::
	lock
	setvar VAR_0x8000, 999
	addmoneywithvar VAR_0x8000, 0
	msgbox TestAddMoneywithVar_Text_0, MSGBOX_SIGN_IRON
	release
	return


TestSubMoneywithVar::
	lock
	setvar VAR_0x8000, 999
	removemoneywithvar VAR_0x8000, 0
	msgbox TestSubMoneywithVar_Text_0, MSGBOX_SIGN_IRON
	release
	return


TestMultMoneywithVar::
	lock
	setvar VAR_0x8000, 3
	multiplymoneywithvar VAR_0x8000, 0
	msgbox TestMultMoneywithVar_Text_0, MSGBOX_SIGN_IRON
	release
	return


TestCheckMoneywithVar::
	lock
	setvar VAR_0x8000, 2999
	checkmoneywithvar VAR_0x8000, 0
	msgbox TestCheckMoneywithVar_Text_0, MSGBOX_SIGN_IRON
	compare VAR_RESULT, TRUE
	goto_if_eq TestCheckMoneywithVar_2
	msgbox TestCheckMoneywithVar_Text_2, MSGBOX_SIGN_IRON
TestCheckMoneywithVar_1:
	release
	return

TestCheckMoneywithVar_2:
	msgbox TestCheckMoneywithVar_Text_1, MSGBOX_SIGN_IRON
	goto TestCheckMoneywithVar_1


Test2v2TrainerBattle::
	msgbox Test2v2TrainerBattle_Text_0, MSGBOX_SIGN_IRON
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
	cleartimeevent 0
	msgbox TestSetScript_Text_0
	closemessage
	release
	end


TestSetScript2::
	lock
	cleartimeevent 1
	msgbox TestSetScript2_Text_0
	closemessage
	release
	end


TestTimeEvent::
	lock
	settimeevent 0, 0, 0, 10, TestSetScript
	settimeevent 1, 0, 0, 20, TestSetScript2
	end


TestEmotion::
	lock
	msgbox TestEmotion_Text_0
	playse SE_PIN
	applymovement 2, TestEmotionMovement1
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement2
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement3
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement4
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement5
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement6
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement7
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement8
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement9
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement10
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement11
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement12
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement13
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement14
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement15
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement16
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement17
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement18
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement19
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement20
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement21
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement22
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement23
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement24
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement25
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement26
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement 2, TestEmotionMovement27
	waitmovement 0
	delay 60
	closemessage
	release
	end


TestEmotionMovement1:
	emote_exclamation_mark
	step_end

TestEmotionMovement2:
	emote_question_mark
	step_end

TestEmotionMovement3:
	emote_heart
	step_end

TestEmotionMovement4:
	emote_dot_dot_dot
	step_end

TestEmotionMovement5:
	emote_angry
	step_end

TestEmotionMovement6:
	emote_sweat
	step_end

TestEmotionMovement7:
	emote_exclamation_mark_2
	step_end

TestEmotionMovement8:
	emote_bulb
	step_end

TestEmotionMovement9:
	emote_speechless
	step_end

TestEmotionMovement10:
	emote_music
	step_end

TestEmotionMovement11:
	emote_circle
	step_end

TestEmotionMovement12:
	emote_sleepy
	step_end

TestEmotionMovement13:
	emote_cross
	step_end

TestEmotionMovement14:
	emote_star
	step_end

TestEmotionMovement15:
	emote_funny
	step_end

TestEmotionMovement16:
	emote_vommit
	step_end

TestEmotionMovement17:
	emote_smile
	step_end

TestEmotionMovement18:
	emote_face_palm
	step_end

TestEmotionMovement19:
	emote_bombed
	step_end

TestEmotionMovement20:
	emote_doge
	step_end

TestEmotionMovement21:
	emote_evil
	step_end

TestEmotionMovement22:
	emote_sweat_2
	step_end

TestEmotionMovement23:
	emote_skull
	step_end

TestEmotionMovement24:
	emote_sword
	step_end

TestEmotionMovement25:
	emote_creeper
	step_end

TestEmotionMovement26:
	emote_spit_blood
	step_end

TestEmotionMovement27:
	emote_interesting
	step_end

TestMugshot::
	mugshot MUGSHOT_TEST
	usedialog LEFT_ARROW
	msgbox TestMugshot_Text_0
	usedialog LEFT_BUBBLE
	msgbox TestMugshot_Text_1
	mugshot MUGSHOT_TEST2, RIGHT
	usedialog RIGHT_ARROW
	msgbox TestMugshot_Text_2
	usedialog RIGHT_BUBBLE
	msgbox TestMugshot_Text_3
	clearmughot RIGHT
	usedialog NORMAL
	msgbox TestMugshot_Text_4, MSGBOX_YESNO
	closemessage
	end


TestWoodenPlate::
	msgbox TestWoodenPlate_Text_0, MSGBOX_SIGN_WOODEN
	return


TestIronPlate::
	msgbox TestIronPlate_Text_0, MSGBOX_SIGN_IRON
	return


TestRadioTextbox::
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_RADIO
	msgbox TestRadioTextbox_Text_0, MSGBOX_NPC
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_DEFAULT
	return


TestNewMugshot::
	giveitem ITEM_MIRROR_OF_MIND, 1
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

TestFollowMeTalk_Text_0:
	.string "测试跟随对话。$"

TestSetScript_Text_0:
	.string "这是10分钟前设置的事件。\n(现实10秒)$"

TestSetScript2_Text_0:
	.string "这是20分钟前设置的事件。\n(现实20秒)$"

TestEmotion_Text_0:
	.string "测试表情。$"

TestMugshot_Text_0:
	.string "测试头像对话左$"

TestMugshot_Text_1:
	.string "测试头像思考左$"

TestMugshot_Text_2:
	.string "测试头像对话右$"

TestMugshot_Text_3:
	.string "测试头像思考右$"

TestMugshot_Text_4:
	.string "测试选项框$"

TestWoodenPlate_Text_0:
	.string "木制路标$"

TestIronPlate_Text_0:
	.string "铁制路标$"

TestRadioTextbox_Text_0:
	.string "收音机对话框$"
