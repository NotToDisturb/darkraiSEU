CanalaveCity_RupertHouse_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 0, CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	map_script_2 VAR_CANALAVE_STATE, 6, CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY_RUPERT_HOUSE
	setvar VAR_CANALAVE_STATE, 1
	return

CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY_RUPERT_HOUSE
	setvar VAR_CANALAVE_STATE, 7
	return

CanalaveCity_RupertHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 1, CanalaveCity_RupertSonIntro
	map_script_2 VAR_CANALAVE_STATE, 7, CanalaveCity_RupertSonToVoid
	.2byte 0


CanalaveCity_RupertSonIntro::
	msgbox CanalaveCity_RupertSonIntro_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox CanalaveCity_RupertSonIntro_Text_1, MSGBOX_DEFAULT
	closemessage
	delay 16
	msgbox CanalaveCity_RupertSonIntro_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 2, Common_Movement_WalkLeft4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft4
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 8
	turnobject 2, DIR_EAST
	delay 16
	msgbox CanalaveCity_RupertSonIntro_Text_3, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft4
	applymovement 2, Common_Movement_WalkLeft4
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown4
	applymovement 2, Common_Movement_WalkDown4
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	removeobject 2, MAP_CANALAVE_CITY_RUPERT_HOUSE
	delay 16
	setvar VAR_CANALAVE_STATE, 2
	warp MAP_CANALAVE_CITY, -1, 15, 11
	return


CanalaveCity_RupertSonToVoid::
	setvar VAR_CANALAVE_STATE, 8
	warp MAP_THE_VOID, -1, 15, 12
	return


CanalaveCity_RupertSonIntro_Text_0:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}He's been sleeping for two\n"
	.string "entire days{PAUSE 4}.{PAUSE 8}.{PAUSE 8}.{PAUSE 8}\p"
	.string "My boy, what is happening to you.$"

CanalaveCity_RupertSonIntro_Text_1:
	.string "{COLOR BLUE}Child: {COLOR DARK_GREY}{PAUSE 8}.{PAUSE 32}.{PAUSE 32}.{PAUSE 32}$"

CanalaveCity_RupertSonIntro_Text_2:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}I have to go get help,{PAUSE 8} surely\n"
	.string "Nurse Joy will know what to do.$"

CanalaveCity_RupertSonIntro_Text_3:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}You hold on now, okay?$"
