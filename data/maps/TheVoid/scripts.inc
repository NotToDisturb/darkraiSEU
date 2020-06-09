TheVoid_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TheVoid_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TheVoid_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TheVoid_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_THE_VOID_STATE, 0, TheVoid_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0
	.2byte 0

TheVoid_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE_0:
	setvar VAR_THE_VOID_STATE, 1
	return

TheVoid_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_THE_VOID_STATE, 1, TheVoid_FirstAppear
	.2byte 0


TheVoid_FirstAppear::
	delay 8
	msgbox TheVoid_FirstAppear_Text_0, MSGBOX_DEFAULT
	closemessage
	delay 16
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight4
	delay 16
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 16
	applymovement 1, Common_Movement_WalkLeft2
	waitmovement 1
	setobjectnewmovementtype 1, MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT
	msgbox TheVoid_FirstAppear_Text_1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 16
	applymovement 1, DarkraiApproach
	applymovement OBJ_EVENT_ID_CAMERA, CameraCenter
	delay 32
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	setobjectnewmovementtype OBJ_EVENT_ID_PLAYER, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	waitmovement 1
	applymovement 1, DarkraiInPlace
	waitmovement 1
	applymovement 1, DarkraiJump
	delay 10
	special RemoveCameraObject
	setvar VAR_THE_VOID_STATE, 2
	warp MAP_CANALAVE_CITY, -1, 10, 5
	end


CameraCenter:
	walk_slow_left
	walk_slow_left
	walk_slow_left
	step_end

DarkraiApproach:
	walk_left
	walk_left
	walk_left
	walk_slow_left
	step_end

DarkraiInPlace:
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_left
	step_end

DarkraiJump:
	walk_left
	jump_left
	step_end

TheVoid_FirstAppear_Text_0:
	.string "{COLOR BLUE}Child: {COLOR DARK_GREY}{PAUSE 8}.{PAUSE 32}.{PAUSE 32}.{PAUSE 32}$"

TheVoid_FirstAppear_Text_1:
	.string "{COLOR RED}Darkrai: {COLOR DARK_GREY}{PAUSE 8}You.{PAUSE 32} Sleep.{PAUSE 32} Now.{PAUSE 32}$"
