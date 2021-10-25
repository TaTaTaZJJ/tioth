yslq_r5_chun_3_04_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAINLINE_0x404E, 1, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	mugshot MUGSHOT_WAIFU_NORMAL
	usedialog LEFT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, 3
	clearmughot
	playse 15
	applymovement 255, MOVE0304T1_5
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, 3
	clearmughot
	playse 15
	applymovement 3, MOVE0304T1_5
	waitmovement 0
	delay 60
	playse 15
	applymovement 255, MOVE0304T1_5
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, 3
	clearmughot
	playse 15
	applymovement 3, MOVE0304M1_1
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3, 3
	clearmughot
	applymovement 3, MOVE0304M1_2
	waitmovement 0
	usedialog NORMAL
	giveitem ITEM_MIRROR_OF_MIND, 1
	mugshot MUGSHOT_WAIFU_NORMAL
	usedialog LEFT_ARROW
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4, 3
	clearmughot
	playse 15
	applymovement 3, MOVE0304M1_3
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5, 3
	clearmughot
	applymovement 3, MOVE0304M1_4
	applymovement 255, MOVE0304M1_5
	waitmovement 0
	call W0304_11
	opendoor 3, 5
	waitdooranim
	applymovement 3, MOVE0304M1_11
	applymovement 255, MOVE0304M1_12
	waitmovement 0
	setdoorclosed 3, 5
	waitdooranim
	applymovement 3, MOVE0304M1_6
	applymovement 255, MOVE0304M1_6
	waitmovement 0
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6, 3
	clearmughot
	applymovement 255, MOVE0304M1_8
	applymovement 3, MOVE0304M1_7
	waitmovement 0
	playse 15
	applymovement 3, MOVE0304M1_9
	waitmovement 0
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7, 3
	clearmughot
	usedialog NORMAL
	applymovement 3, MOVE0304M1_10
	waitmovement 0
	setobjectxy 3, 3, 3
	setobjectxyperm 3, 3, 3
	setvar VAR_MAINLINE_0x404E, 2
	end

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_MAINLINE_0x404E, 1, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	turnobject 3, 4
	turnobject 255, 3
	return


MOVE0304M1_1:
	emote_speechless
	step_end

MOVE0304M1_2:
	walk_right
	step_end

MOVE0304M1_3:
	emote_evil
	step_end

MOVE0304M1_4:
	walk_left
	walk_down
	walk_down
	set_invisible
	step_end

MOVE0304M1_5:
	walk_left
	walk_left
	walk_down
	set_invisible
	step_end

MOVE0304M1_6:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

MOVE0304M1_7:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MOVE0304M1_8:
	walk_right
	face_left
	step_end

MOVE0304M1_9:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MOVE0304M1_10:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MOVE0304M1_11:
	set_visible
	walk_down
	walk_right
	step_end

MOVE0304M1_12:
	walk_down
	set_visible
	walk_down
	step_end

T0304T1::
	call T0304T1_3
	applymovement 255, MOVE0304T1_2
	goto T0304T1_4
	end


T0304T1_2::
	call T0304T1_3
	goto T0304T1_4
	end


T0304T1_3::
	addobject 1
	applymovement 1, MOVE0304T1
	waitmovement 0
	return


T0304T1_4::
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
	msgbox T0304T1_4_Text_0, 3
	clearmughot
	applymovement 255, MOVE0304T1_5
	waitmovement 0
	delay 60
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox T0304T1_4_Text_1, 3
	clearmughot
	mugshot MUGSHOT_WAIFU_NORMAL
	msgbox T0304T1_4_Text_2, 3
	clearmughot
	special SpawnCameraObject
	applymovement 2, MOVE0304T1_6
	applymovement 255, MOVE0304T1_7
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_MAINLINE_0x404E, 1
	warpsilent MAP_YSLQ_R5_CHUN_3_04, 255, 5, 3
	waitstate
	end


MOVE0304T1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MOVE0304T1_2:
	face_left
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

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

W0304_10::
	setmetatile 1, 1, 109, 0
	setmetatile 2, 1, 109, 0
	setmetatile 3, 1, 109, 0
	setmetatile 4, 1, 109, 0
	setmetatile 5, 1, 109, 0
	setmetatile 1, 2, 109, 0
	setmetatile 2, 2, 109, 0
	setmetatile 3, 2, 109, 0
	setmetatile 4, 2, 109, 0
	setmetatile 5, 2, 109, 0
	setmetatile 1, 3, 109, 0
	setmetatile 2, 3, 109, 0
	setmetatile 3, 3, 109, 0
	setmetatile 4, 3, 109, 0
	setmetatile 5, 3, 109, 0
	setmetatile 1, 4, 109, 0
	setmetatile 2, 4, 109, 0
	setmetatile 3, 4, 109, 0
	setmetatile 4, 4, 109, 0
	setmetatile 5, 4, 109, 0
	setmetatile 1, 5, 109, 0
	setmetatile 2, 5, 109, 0
	setmetatile 3, 5, 109, 0
	setmetatile 4, 5, 109, 0
	setmetatile 5, 5, 109, 0
	special DrawWholeMapView
	return


W0304_11::
	setmetatile 1, 1, 109, 1
	setmetatile 2, 1, 109, 1
	setmetatile 3, 1, 109, 1
	setmetatile 4, 1, 109, 1
	setmetatile 5, 1, 109, 1
	setmetatile 1, 2, 109, 1
	setmetatile 2, 2, 109, 1
	setmetatile 3, 2, 109, 1
	setmetatile 4, 2, 109, 1
	setmetatile 5, 2, 109, 1
	setmetatile 1, 3, 109, 1
	setmetatile 2, 3, 109, 1
	setmetatile 3, 3, 109, 1
	setmetatile 4, 3, 109, 1
	setmetatile 5, 3, 109, 1
	setmetatile 1, 4, 109, 1
	setmetatile 2, 4, 109, 1
	setmetatile 3, 4, 25, 1
	setmetatile 4, 4, 109, 1
	setmetatile 5, 4, 109, 1
	setmetatile 1, 5, 109, 1
	setmetatile 2, 5, 109, 1
	setmetatile 3, 5, 33, 1
	setmetatile 4, 5, 109, 1
	setmetatile 5, 5, 109, 1
	special DrawWholeMapView
	return


yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "警员：啧，\n没想到是个冒牌的训练家，\l这年头这么多人出来逞英雄吗？$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "警员：这下好了，这个月绩效完不成了。\n上头叫我每个月抓五个训练家，\l到目前为止我只抓到俩。\l真希望月底之前有个什么大事发生，\l让我一次性把今年的绩效全部抓完……\l那不知道得立多大个功，\l可能还会被调到总部去呢。\l咳咳，那么你。$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "警员：你居然能把自己名字都忘了，\n而且身无分文一个人在原野里游荡。\l不过也好，我看你也是这个镇的生面孔，\l不如帮我一个忙，自然有你的好处。\l说实话，我在这里抓非法的训练家，\l但也顶多把他们拘留几天，\l到头来还是把他们放了——$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "警员：结果他们都能认得我了，\n自然是避着我行动。\l我需要一个人，\l能够秘密潜入我指定的场所，\l帮我打探一下里面的情况，\l没准儿还能逮个正着儿。$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "警员：穿上它让你看着像个体面人，\n这也是你第一次任务的报酬。\l什么，不合身？你不能拒绝它！\l没有人能在不穿着制服的\l情况下在城内活动，\l这被认为是违法的！$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
	.string "警员：没有规矩，不成方圆。\n还是说你想被以无家可归罪继续关禁闭？\l现在闭上嘴跟我来！$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
	.string "警员：就是这里。\n这里的户主是个女巫。\l你没听错，就是那些中世纪遗留的\l陈腐的幻象主义唯心者！\l但我还没有证据证明她是一个训练家，\l而你的任务就是去弄明白这一点。\l交给你了，我在警局等你汇报。$"

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
	.string "警员：记得先敲门，\n确认主人是否在家，不要贸然行动。$"

T0304T1_4_Text_0:
	.string "警员：呼，呼——\n你，有看到，一个训练家吗？$"

T0304T1_4_Text_1:
	.string "警员：什么训练家？\n你是在跟我装傻吗？\l等等，\l你说刚有人塞给你一个东西？\l拿出来我看看！$"

T0304T1_4_Text_2:
	.string "警员：你手上居然有训练家的小玩意儿！\n那你可得跟我走一趟了。\l你可以在路上好好想想怎么\l解释这些违法小玩意儿的获取渠道！$"
