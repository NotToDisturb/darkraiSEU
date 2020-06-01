CanalaveCity_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CanalaveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 0, CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	map_script_2 VAR_CANALAVE_STATE, 2, CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1
	.2byte 0

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY
	hideobjectat 8, MAP_CANALAVE_CITY
	setvar VAR_CANALAVE_STATE, 1
	return

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY
	hideobjectat 1, MAP_CANALAVE_CITY
	hideobjectat 4, MAP_CANALAVE_CITY
	hideobjectat 6, MAP_CANALAVE_CITY
	hideobjectat 7, MAP_CANALAVE_CITY
	setobjectxy OBJ_EVENT_ID_PLAYER, 10, 7
	removeobject 5, MAP_CANALAVE_CITY
	setobjectxyperm 5, 20, 13
	addobject 5, MAP_CANALAVE_CITY
	setobjectnewmovementtype 5, MOVEMENT_TYPE_WANDER_AROUND
	removeobject 2, MAP_CANALAVE_CITY
	setobjectxyperm 2, 18, 12
	addobject 2, MAP_CANALAVE_CITY
	setobjectnewmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	removeobject 3, MAP_CANALAVE_CITY
	setobjectxyperm 3, 17, 15
	addobject 3, MAP_CANALAVE_CITY
	setobjectnewmovementtype 3, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_CANALAVE_STATE, 3
	return

CanalaveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_CANALAVE_STATE, 1, CanalaveCity_BeginStartingCutscene
	map_script_2 VAR_CANALAVE_STATE, 3, CanalaveCity_BarrySavesTheDay
	.2byte 0


CanalaveCity_BeginStartingCutscene::
	msgbox CanalaveCity_BeginStartingCutscene_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkOutOfHouseCamera
	applymovement 1, WalkOutOfHouseRupert
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 4
	msgbox CanalaveCity_BeginStartingCutscene_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MoveToGrunts
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 4, Common_Movement_ExclamationMark
	msgbox CanalaveCity_BeginStartingCutscene_Text_2, MSGBOX_DEFAULT
	applymovement 5, GruntGetAttention
	waitmovement 5
	msgbox CanalaveCity_BeginStartingCutscene_Text_3, MSGBOX_DEFAULT
	applymovement 2, GruntGetAttention
	waitmovement 2
	msgbox CanalaveCity_BeginStartingCutscene_Text_4, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_5, MSGBOX_DEFAULT
	applymovement 3, GruntGetAttention
	waitmovement 3
	msgbox CanalaveCity_BeginStartingCutscene_Text_6, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_7, MSGBOX_DEFAULT
	msgbox CanalaveCity_BeginStartingCutscene_Text_8, MSGBOX_DEFAULT
	applymovement 6, FeintAttackStart
	message CanalaveCity_BeginStartingCutscene_Text_9
	waitmovement 6
	applymovement 7, WingullSurprised
	applymovement 6, FeintAttackEnd
	waitmovement 6
	setobjectnewmovementtype 7, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	setobjectnewmovementtype 6, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	waitmessage
	waitbuttonpress
	closemessage
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, MoveToRupert
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, WalkIntoHouse
	applymovement 1, WalkIntoHouse
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_CANALAVE_STATE, 2
	warp MAP_CANALAVE_CITY, 0, 10, 7
	end


WalkOutOfHouseRupert:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_8
	emote_exclamation_mark
	delay_8
	walk_fast_up
	walk_fast_up
	step_end

WalkOutOfHouseCamera:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
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
	delay_16
	step_end

FeintAttackStart:
	jump_in_place_down
	jump_in_place_down
	jump_down
	step_end

WingullSurprised:
	jump_in_place_up
	step_end

FeintAttackEnd:
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
	step_end

CanalaveCity_BarrySavesTheDay::
	setvar VAR_CANALAVE_STATE, 4
	end


CanalaveCity_BeginStartingCutscene_Text_0:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}My poor son{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.{PAUSE 8}\n"
	.string "You'll get better, {PAUSE 4}I swear.$"

CanalaveCity_BeginStartingCutscene_Text_1:
	.string "{COLOR BLUE}Rupert: {COLOR DARK_GREY}Ben! {PAUSE 4}What's going on!$"

CanalaveCity_BeginStartingCutscene_Text_2:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}Get back inside Rupert!\n"
	.string "They're trying to take the dock!$"

CanalaveCity_BeginStartingCutscene_Text_3:
	.string "{COLOR RED}Grunt 1: {COLOR DARK_GREY}Damn right we are! And you\n"
	.string "can't do anything to stop us.$"

CanalaveCity_BeginStartingCutscene_Text_4:
	.string "{COLOR RED}Grunt 2: {COLOR DARK_GREY}Give us the key to the boat\n"
	.string "already, {PAUSE 8}old man.$"

CanalaveCity_BeginStartingCutscene_Text_5:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}In your dreams! {PAUSE 8}Rupert, get inside\n"
	.string "and lock the door, now!$"

CanalaveCity_BeginStartingCutscene_Text_6:
	.string "{COLOR RED}Grunt 3: {COLOR DARK_GREY}Enough of this.\n"
	.string "{PAUSE 8}Take him out and let's get the job done.$"

CanalaveCity_BeginStartingCutscene_Text_7:
	.string "{COLOR RED}Grunt 1: {COLOR DARK_GREY}Right{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.\p"
	.string "Stunky! {PAUSE 4}Use Feint attack!$"

CanalaveCity_BeginStartingCutscene_Text_8:
	.string "{COLOR RED}Stunky: {COLOR DARK_GREY}Stuunk!$"

CanalaveCity_BeginStartingCutscene_Text_9:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}Rupert, go!$"
