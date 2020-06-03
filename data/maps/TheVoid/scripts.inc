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
	msgbox TheVoid_FirstAppear_Text_0
	closemessage
	setvar VAR_THE_VOID_STATE, 2
	warp MAP_CANALAVE_CITY, 0, 10, 5
	end


TheVoid_FirstAppear_Text_0:
	.string "{COLOR BLUE}Prinplup: {COLOR DARK_GREY}{PAUSE 8}.{PAUSE 32}.{PAUSE 32}.{PAUSE 32}$"
