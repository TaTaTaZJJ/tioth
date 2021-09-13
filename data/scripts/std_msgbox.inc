Std_MsgboxNPC:
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSignWooden:
	lockall
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_WOODEN
	message 0x0
	waitmessage
	waitbuttonpress
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_DEFAULT
	releaseall
	return

Std_MsgboxSignIron:
	lockall
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_IRON
	message 0x0
	waitmessage
	waitbuttonpress
	setvar VAR_DIALOG_STYLE, MSGBOX_STYLE_DEFAULT
	releaseall
	return

Std_MsgboxDefault:
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxGetPoints:
	message 0x0
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

Std_10:
	pokenavcall 0x0
	waitmessage
	return

EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	waitstate
	return
