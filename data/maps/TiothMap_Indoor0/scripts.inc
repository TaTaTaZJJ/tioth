TiothMap_Indoor0_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TIOTH_MAP, 1, TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0
	.2byte 0

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0:
	lockall
	mugshot MUGSHOT_WAIFU_NORMAL
	usedialog LEFT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0, 3
	mugshot MUGSHOT_WAIFU_NORMAL, RIGHT
	usedialog RIGHT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1, 3
	usedialog LEFT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2, 3
	usedialog RIGHT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3, 3
	usedialog LEFT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4, 3
	usedialog RIGHT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5, 3
	usedialog LEFT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6, 3
	usedialog RIGHT_ARROW
	msgbox TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7, 3
	clearmughot RIGHT
	clearmughot
	usedialog NORMAL
	setflag FLAG_UNUSED_0x020
	fadescreen 1
	playbgm MUS_B_PYRAMID, 0
	delay 20
	SETVAR VAR_TIOTH_MAP, 2
	releaseall
	warpsilent MAP_YSLQ_R5_CHUN_3_04, 255, 17, 14
	waitstate
	end


TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_0:
	.string "小悠：爷爷，这么多年了，\p这个故事的结局究竟是什么啊？$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_1:
	.string "爷爷：呵呵呵…… 咳咳。\p让我歇歇吧，以后会讲给你听的。$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_2:
	.string "小悠：爷—— 爷——$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_3:
	.string "爷爷：好啦好啦，明天你可得搬家了。\n那会是一个怎样新奇的大地呢？\l你也会遇到属于你的宝可梦同伴吧。\l难道你就不好奇吗？$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_4:
	.string "小悠：可是我走之前还是希望\n能知道那个故事的结局。$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_5:
	.string "爷爷：哈哈哈…… 结局吗？\n事实上，我也不知道。\l我的父亲也没有告诉我这个故事的结局。$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_6:
	.string "小悠：那…… 曾祖母呢？$"

TiothMap_Indoor0_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE_0_Text_7:
	.string "爷爷：她只告诉我，结局即在你眼前。$"
