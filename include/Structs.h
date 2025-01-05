#pragma once

#define windowWidth 1280
#define windowHeight 740
#define menuHeight 120
#define matHeight 130

enum ObjectType{
	ROBOT = '/',
	GUARD = '!',
	DOOR  =	'D',
	WALL  = '#',
	ROCK  = '@',
	EMPTY = ' ',
	DELETE = 6,
	SAVE = 7,
	NEWPAGE  = 8
};

enum TextureType {
	TROBOT,
	TGUARD,
	TDOOR,
	TWALL,
	TROCK,
	TEMPTY,
	TDELETE,
	TSAVE,
	TNEWPAGE
};


