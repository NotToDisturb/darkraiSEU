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
	hideobjectat 9, MAP_CANALAVE_CITY
	setvar VAR_CANALAVE_STATE, 1
	return

CanalaveCity_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_1:
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CANALAVE_CITY
	hideobjectat 1, MAP_CANALAVE_CITY
	hideobjectat 4, MAP_CANALAVE_CITY
	hideobjectat 6, MAP_CANALAVE_CITY
	hideobjectat 7, MAP_CANALAVE_CITY
	removeobject 5, MAP_CANALAVE_CITY
	setobjectxyperm 5, 19, 13
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	addobject 5, MAP_CANALAVE_CITY
	removeobject 2, MAP_CANALAVE_CITY
	setobjectxyperm 2, 18, 11
	setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
	addobject 2, MAP_CANALAVE_CITY
	removeobject 3, MAP_CANALAVE_CITY
	setobjectxyperm 3, 16, 15
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	addobject 3, MAP_CANALAVE_CITY
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
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, WalkOutOfHouseCameraEnd
	applymovement 1, WalkOutOfHouseRupertEnd
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	msgbox CanalaveCity_BeginStartingCutscene_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MoveToGrunts
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 4, Common_Movement_ExclamationMark
	delay 16
	msgbox CanalaveCity_BeginStartingCutscene_Text_2, MSGBOX_DEFAULT
	closemessage
	applymovement 5, ObjectGetAttentionDown
	waitmovement 5
	delay 4
	msgbox CanalaveCity_BeginStartingCutscene_Text_3, MSGBOX_DEFAULT
	closemessage
	applymovement 2, ObjectGetAttentionDown
	waitmovement 2
	delay 4
	msgbox CanalaveCity_BeginStartingCutscene_Text_4, MSGBOX_DEFAULT
	delay 16
	msgbox CanalaveCity_BeginStartingCutscene_Text_5, MSGBOX_DEFAULT
	closemessage
	applymovement 3, ObjectGetAttentionDown
	waitmovement 3
	delay 4
	msgbox CanalaveCity_BeginStartingCutscene_Text_6, MSGBOX_DEFAULT
	delay 16
	msgbox CanalaveCity_BeginStartingCutscene_Text_7, MSGBOX_DEFAULT
	delay 16
	msgbox CanalaveCity_BeginStartingCutscene_Text_8, MSGBOX_DEFAULT
	applymovement 6, FeintAttackStart
	delay 16
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
	warp MAP_THE_VOID, 0, 10, 5
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
	step_end

WalkOutOfHouseRupertEnd:
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
	step_end

WalkOutOfHouseCameraEnd:
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

ObjectGetAttentionDown:
	jump_in_place_down
	jump_in_place_down
	delay_16
	step_end

ObjectGetAttentionLeft:
	jump_in_place_left
	jump_in_place_left
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
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BarryWalkFromGym
	applymovement 8, BarryWalkFromGym
	applymovement 9, BarryWalkFromGym
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_0
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 9, PrinplupFaceBarry
	waitmessage
	waitbuttonpress
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BarryShortLeft
	applymovement 8, BarryShortLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	msgbox CanalaveCity_BarrySavesTheDay_Text_1, MSGBOX_DEFAULT
	applymovement 8, ObjectRealizationDown
	delay 16
	msgbox CanalaveCity_BarrySavesTheDay_Text_2, MSGBOX_DEFAULT
	closemessage
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_3
	applymovement 9, ObjectGetAttentionLeft
	waitmovement 9
	waitmessage
	waitbuttonpress
	closemessage
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_4
	applymovement OBJ_EVENT_ID_PLAYER, BarryShortRight
	applymovement 8, BarryShortRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, BarryShortRight
	applymovement 8, BarryShortRight
	turnobject 9, DIR_NORTH
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject 8, DIR_SOUTH
	waitmessage
	waitbuttonpress
	closemessage
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_5
	waitmessage
	waitbuttonpress
	closemessage
	delay 32
	msgbox CanalaveCity_BarrySavesTheDay_Text_6, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, BarryShortLeft
	applymovement 8, BarryShortLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject 9, DIR_WEST
	delay 24
	msgbox CanalaveCity_BarrySavesTheDay_Text_7, MSGBOX_DEFAULT
	closemessage
	applymovement 8, ObjectRealizationDownExclamation
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_8
	delay 4
	applymovement 9, ObjectRealizationLeftExclamation
	waitmovement 9
	waitmessage
	waitbuttonpress
	closemessage
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown2
	applymovement 8, Common_Movement_WalkDown2
	waitmovement OBJ_EVENT_ID_PLAYER
	turnobject 9, DIR_SOUTH
	delay 8
	applymovement 9, Common_Movement_QuestionMark
	delay 32
	turnobject 8, DIR_NORTH
	msgbox CanalaveCity_BarrySavesTheDay_Text_9, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement 9, ObjectRealizationDown
	waitmovement 9
	delay 16
	msgbox CanalaveCity_BarrySavesTheDay_Text_10, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement 9, ObjectGetAttentionDown
	waitmovement 9
	delay 16
	msgbox CanalaveCity_BarrySavesTheDay_Text_11, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement 9, PrinplupStartDock
	waitmovement 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown4
	applymovement 8, Common_Movement_WalkDown4
	applymovement 9, PrinplupTurnDock
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 8, Common_Movement_WalkRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight2
	applymovement 8, Common_Movement_WalkRight2
	applymovement 9, Common_Movement_WalkRight2
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, BarryShortRight
	applymovement 8, BarryShortRight
	applymovement 9, BarryShortRight
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	message CanalaveCity_BarrySavesTheDay_Text_12
	delay 16
	waitmovement 8
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 8
	delay 16
	waitmessage
	waitbuttonpress
	closemessage
	setvar VAR_CANALAVE_STATE, 4
	releaseall
	end


BarryWalkFromGym:
	walk_slow_down
	walk_slow_down
	step_end

PrinplupFaceBarry:
	walk_down
	face_left
	step_end

BarryShortLeft:
	walk_slow_left
	step_end

BarryShortRight:
	walk_slow_right
	step_end

ObjectRealizationDown:
	jump_in_place_down
	step_end

ObjectRealizationDownExclamation:
	jump_in_place_down
	emote_exclamation_mark
	step_end

ObjectRealizationLeftExclamation:
	jump_in_place_left
	emote_exclamation_mark
	step_end

PrinplupStartDock:
	jump_in_place_down
	jump_in_place_down
	delay_16
	walk_down
	step_end

PrinplupTurnDock:
	walk_down
	walk_down
	walk_slow_down
	face_right
	step_end

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
	.string "{COLOR RED}Grunt 3: {COLOR DARK_GREY}Enough of this!\n"
	.string "{PAUSE 8}Take him out and let's get the job done.$"

CanalaveCity_BeginStartingCutscene_Text_7:
	.string "{COLOR RED}Grunt 1: {COLOR DARK_GREY}Right{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.\p"
	.string "Stunky! {PAUSE 4}Use Feint attack!$"

CanalaveCity_BeginStartingCutscene_Text_8:
	.string "{COLOR RED}Stunky: {COLOR DARK_GREY}Stuunk!$"

CanalaveCity_BeginStartingCutscene_Text_9:
	.string "{COLOR BLUE}Ben: {COLOR DARK_GREY}Rupert, go!$"

CanalaveCity_BarrySavesTheDay_Text_0:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Oh man, Byron is so strong{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.{PAUSE 4}\n"
	.string "He beat us without breaking a sweat!$"

CanalaveCity_BarrySavesTheDay_Text_1:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}We sure can't can beat him yet, {PAUSE 8}\n"
	.string "I'm still a long way from his level.$"

CanalaveCity_BarrySavesTheDay_Text_2:
	.string "But I'm not giving up! {PAUSE 4}No sir!\n"
	.string "{PAUSE 8}We're gonna train together!\p"
	.string "That's right! Even harder than before!\n"
	.string "{PAUSE 8}Hear that Prinplup?$"

CanalaveCity_BarrySavesTheDay_Text_3:
	.string "{COLOR BLUE}Prinplup: {COLOR DARK_GREY}Prinp! Prinp!$"

CanalaveCity_BarrySavesTheDay_Text_4:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}We still need to find where to\n"
	.string "train though. {PAUSE 8}What do you think?$"

CanalaveCity_BarrySavesTheDay_Text_5:
	.string "{COLOR BLUE}Prinplup: {COLOR DARK_GREY}{PAUSE 8}.{PAUSE 32}.{PAUSE 32}.{PAUSE 32}$"

CanalaveCity_BarrySavesTheDay_Text_6:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Right. {PAUSE 32}\n"
	.string "I keep forgetting you can't speak.$"

CanalaveCity_BarrySavesTheDay_Text_7:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Hm{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.{PAUSE 4}$"

CanalaveCity_BarrySavesTheDay_Text_8:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Oh, {PAUSE 2}I know just the place!\p"
	.string "Come on Prinplup, we're going to Iron\n"
	.string "Island!$"

CanalaveCity_BarrySavesTheDay_Text_9:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Why that face buddy?$"

CanalaveCity_BarrySavesTheDay_Text_10:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}You still can't talk you know{PAUSE 4}.{PAUSE 4}.{PAUSE 4}.{PAUSE 4}$"

CanalaveCity_BarrySavesTheDay_Text_11:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}Gotta go to the docks to get to\n"
	.string "Iron Island! Come on!$"

CanalaveCity_BarrySavesTheDay_Text_12:
	.string "{COLOR BLUE}Barry: {COLOR DARK_GREY}What is Team Galactic doing\n"
	.string "around here?\p"
	.string "Well, hopefully they aren't up to\n"
	.string "anything bad.$"
