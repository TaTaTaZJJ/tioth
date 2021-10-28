yslq_r5_chun_3_04_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TIOTH_MAP, 0, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	mugshot MUGSHOT_WAIFU_NORMAL
	usedialog LEFT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, 3
	clearmughot
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, 3
	usedialog LEFT_ARROW
	clearmughot RIGHT
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, 3
	clearmughot
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3, 3
	usedialog LEFT_ARROW
	clearmughot RIGHT
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4, 3
	clearmughot
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5, 3
	clearmughot RIGHT
	usedialog NORMAL
	fadescreen 1
	playbgm MUS_B_PYRAMID, 0
	startblackcentermsg
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
	release
	setvar VAR_TIOTH_MAP, 1
	endblackcentermsg
	releaseall
	warpsilent MAP_TIOTH_MAP_INDOOR0, 255, 3, 3
	waitstate
	end


H_H_0::
	turnobject 255, 3
	applymovement 1, MOVE0304T1_3
	waitmovement 0
	giveitem ITEM_MIRROR_OF_MIND, 1
	closemessage
	applymovement 1, MOVE0304T1_4
	waitmovement 0
	removeobject 1
	addobject 2
	applymovement 2, MOVE0304T1_4
	waitmovement 0
	turnobject 2, 4
	usedialog LEFT_ARROW
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox H_H_0_Text_0, 3
	clearmughot
	applymovement 255, MOVE0304T1_5
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox H_H_0_Text_1, 3
	clearmughot
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox H_H_0_Text_2, 3
	clearmughot
	special SpawnCameraObject
	applymovement 2, MOVE0304T1_6
	applymovement 255, MOVE0304T1_7
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TIOTH_MAP, 3
	warpsilent MAP_POLISH_OFFICE, 255, 10, 10
	waitstate
	end


MOVE0304T1_3:
	walk_fast_up
	face_right
	delay_16
	lock_facing_direction
	walk_fast_right
	walk_fast_left
	unlock_facing_direction
	step_end

MOVE0304T1_4:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MOVE0304T1_5:
	emote_dot_dot_dot
	step_end

MOVE0304T1_6:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MOVE0304T1_7:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "夜：让大家变成那样的……就是你吗？！$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "代：咕……$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "夜：可恶，他已经失去理智了。$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "洛托姆：目标：迟来的勇者-代。\n根据分析，他是白夜梦游症的零号病人，\l根据发病阶段判断，\l在疫情扩散之初就已经失去理智。$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "夜：明明…… 明明是这一切的罪魁祸首，\n他却比我们更加轻松……$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
	.string "玲：是时候了结这一切了！\n朋友们，我们上吧！$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
	.string "{COLOR WHITE}{SHADOW TRANSPARENT}每当故事进行到此时\p爷爷总会回避我的追问。$"

H_H_0_Text_0:
	.string "警员：呼，呼——\n你，有看到，一个训练家吗？$"

H_H_0_Text_1:
	.string "警员：什么训练家？\n你是在跟我装傻吗？\l等等，\l你说刚有人塞给你一个东西？\l拿出来我看看！$"

H_H_0_Text_2:
	.string "警员：你手上居然有训练家的小玩意儿！\n那你可得跟我走一趟了。\l你可以在路上好好想想怎么\l解释这些违法小玩意儿的获取渠道！$"
