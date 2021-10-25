SCENE_A_0_2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MAINLINE_0x404E, 0, SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	msgbox SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, 3
	delay 20
	warpsilent MAP_SCENE_B_0_3, 255, 1, 1
	waitstate
	end


SCENE_A_0_2_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "小时候，我的爷爷经常跟我讲一个故事。\p那个故事，是他的父亲讲给他听的。\p1910年$"
