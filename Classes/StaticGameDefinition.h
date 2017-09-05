#ifndef __STATIC_GAME_DEFINITION_H__
#define __STATIC_GAME_DEFINITION_H__


#include "cocos2d.h"

using namespace cocos2d;

static cocos2d::Size designResolutionSize = cocos2d::Size(1920, 1080);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1920, 1080);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1920, 1920);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1920, 1920);

//キャラの姿勢
enum class STATE {
	NONE = 0, STAND, WALK, RUN, SIT, JUMP
};

//キャラの行動
enum class ACTION {
	NONE = 0,WAIT ,ATTACK, SHIFT, SKILL,DEBUG
};

//パラメーター
struct PARAMETER
{
	char* name;//名前
	float speed;//移動スピード
	float shift;//瞬間移動の距離
};

static char* getStateName(STATE s)
{
	char* name;
	switch (s)
	{
	case STATE::NONE:name = "NONE";
		break;
	case STATE::STAND:name = "STAND";
		break;
	case STATE::WALK:name = "WALK";
		break;
	case STATE::RUN:name = "RUN";
		break;
	case STATE::SIT:name = "SIT";
		break;
	case STATE::JUMP:name = "JUMP";
		break;
	default:
		break;
	}
	return name;
};


static char* getActionName(ACTION a)
{
	char* name;
	switch (a)
	{
	case ACTION::NONE:name = "NONE";
		break;
	case ACTION::WAIT:name = "WAIT";
		break;
	case ACTION::ATTACK:name = "ATTACK";
		break;
	case ACTION::SHIFT:name = "SHIFT";
		break;
	case ACTION::SKILL:name = "SKILL";
		break;
	case ACTION::DEBUG:name = "DEBUG";
		break;
	default:
		break;
	}
	return name;
};

#endif // !__STATIC_GAME_DEFINITION_H__

