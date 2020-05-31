CanalaveCity_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CanalaveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 0, CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY
	return

CanalaveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 0, CanalaveCity_BeginStartingCutscene
	.2byte 0


CanalaveCity_BeginStartingCutscene::
	setvar VAR_CANALAVE_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, WalkOutOfHouseCamera
	applymovement 1, WalkOutOfHouseRupert
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 4
	msgbox CanalaveCity_BeginStartingCutscene_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MoveToGrunts
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 4, Common_Movement_ExclamationMark
	msgbox CanalaveCity_BeginStartingCutscene_Text_1, MSGBOX_DEFAULT
	applymovement 5, GruntGetAttention
	waitmovement 5
	msgbox CanalaveCity_BeginStartingCutscene_Text_2, MSGBOX_DEFAULT
	applymovement 2, GruntGetAttention
	waitmovement 2
	msgbox CanalaveCity_BeginStartingCutscene_Text_3, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_4, MSGBOX_DEFAULT
	applymovement 3, GruntGetAttention
	waitmovement 3
	msgbox CanalaveCity_BeginStartingCutscene_Text_5, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_6, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_7, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_ExclamationMark
	msgbox CanalaveCity_BeginStartingCutscene_Text_8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_ExclamationMark
	applymovement 6, FeintAttack
	applymovement OBJ_EVENT_ID_PLAYER, MoveToRupert
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, WalkIntoHouse
	applymovement 1, WalkIntoHouse
	waitmovement OBJ_EVENT_ID_PLAYER
	end


WalkOutOfHouseRupert:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	emote_exclamation_mark
	delay_1
	walk_fast_up
	walk_fast_up
	step_end

WalkOutOfHouseCamera:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MoveToGrunts:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

GruntGetAttention:
	jump_in_place_down
	jump_in_place_down
	step_end

FeintAttack:
	jump_in_place_down
	jump_in_place_down
	jump_down
	jump_up_backwards
	step_end

MoveToRupert:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

WalkIntoHouse:
	walk_down_backwards
	walk_down_backwards
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

CanalaveCity_BeginStartingCutscene_Text_0:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}Ben! {PAUSE 4}What's going on!$"

CanalaveCity_BeginStartingCutscene_Text_1:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}Get back inside Rupert!\n"
	.string "They're trying to take the dock!$"

CanalaveCity_BeginStartingCutscene_Text_2:
	.string "{COLOR RED}Grunt 1: {COLOR DARK_GREY}Damn right we are! And you\n"
	.string "can't do anything to stop us.$"

CanalaveCity_BeginStartingCutscene_Text_3:
	.string "{COLOR RED}Grunt 2: {COLOR DARK_GREY}Give us the key to the boat\n"
	.string "now, old man.$"

CanalaveCity_BeginStartingCutscene_Text_4:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}In your dreams! Rupert, get inside\n"
	.string "and lock the door, now!$"

CanalaveCity_BeginStartingCutscene_Text_5:
	.string "{COLOR RED}Grunt 3: {COLOR DARK_GREY}Enough of this. {PAUSE 8}Just take him\n"
	.string "out.$"

CanalaveCity_BeginStartingCutscene_Text_6:
	.string "{COLOR RED}Grunt 1: {COLOR DARK_GREY}Right.{PAUSE 8}.{PAUSE 8}.\n"
	.string "Stunky! Use Feint attack!$"

CanalaveCity_BeginStartingCutscene_Text_7:
	.string "{COLOR LIGHT_RED}Stunky: {COLOR DARK_GREY}Stuunk!$"

CanalaveCity_BeginStartingCutscene_Text_8:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}Rupert, go!$"
