yslq_r5_chun_3_04_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 0, yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
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
	fadescreen FADE_TO_BLACK
	startblackcentermsg
	msgbox yslq_r5_chun_3_04_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6
	release
	warpsilent MAP_TIOTH_MAP_INDOOR0, 255, 3, 3
	waitstate
	endblackcentermsg
	fadescreen FADE_FROM_BLACK
	setvar VAR_TEMP_1, 1
	end


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
	.string "{COLOR WHITE}每当故事进行到此时\p爷爷总会回避我的追问。$"
