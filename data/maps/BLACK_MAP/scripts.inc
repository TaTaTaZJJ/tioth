BLACK_MAP_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BLACK_MAP_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_LOAD:
	setvar VAR_TEMP_0, 1
	return

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 1, BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	fadescreen FADE_TO_BLACK
	startblackcentermsg
	msgbox BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	release
	msgbox BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1
	release
	msgbox BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2
	release
	warp MAP_YSLQ_R5_CHUN_3_04, 0, 17, 14
	endblackcentermsg
	fadescreen FADE_FROM_BLACK
	SETVAR VAR_TEMP_0, 0
	return


BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "{COLOR WHITE}{SHADOW LIGHT_GRAY}小时候，我的爷爷经常跟我讲一个故事。$"

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "{COLOR WHITE}{SHADOW LIGHT_GRAY}那个故事，是他的父亲讲给他听的。$"

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "{COLOR WHITE}{SHADOW LIGHT_GRAY}        1910年......$"
