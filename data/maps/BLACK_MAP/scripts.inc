BLACK_MAP_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	fadescreen FADE_TO_BLACK
	startblackcentermsg
	msgbox BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0
	release
	warp MAP_YSLQ_R5_CHUN_3_04, 255, 17, 14
	waitstate
	endblackcentermsg
	fadescreen FADE_FROM_BLACK
	warp MAP_YSLQ_R5_CHUN_3_04, 255, 17, 14
	SETVAR VAR_TEMP_0, 1
	return


BLACK_MAP_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "{COLOR WHITE}{SHADOW TRANSPARENT}小时候，我的爷爷经常跟我讲一个故事。\p那个故事，是他的父亲讲给他听的。\p1910年$"
