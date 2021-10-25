SCENE_B_0_3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAINLINE_0x404E, 0, SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	mugshot MUGSHOT_WAIFU_NORMAL
	usedialog LEFT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, 3
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, 3
	usedialog LEFT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, 3
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3, 3
	usedialog LEFT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4, 3
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5, 3
	clearmughot RIGHT
	clearmughot
	usedialog NORMAL
	fadescreen 1
	playbgm MUS_B_PYRAMID, 0
	delay 20
	msgbox SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6, 3
	delay 20
	warpsilent MAP_SCENE_C_0_4, 255, 1, 1
	waitstate
	end


SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "夜：让大家变成那样的……就是你吗？！$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "代：咕……$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "夜：可恶，他已经失去理智了。$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "洛托姆：目标：迟来的勇者-代。\n根据分析，他是白夜梦游症的零号病人，\l根据发病阶段判断，\l在疫情扩散之初就已经失去理智。$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "夜：明明…… 明明是这一切的罪魁祸首，\n他却比我们更加轻松……$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
	.string "玲：是时候了结这一切了！\n朋友们，我们上吧！$"

SCENE_B_0_3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
	.string "每当故事进行到此时\p爷爷总会回避我的追问。$"
