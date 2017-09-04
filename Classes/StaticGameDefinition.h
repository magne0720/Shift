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
	NONE = -1, STAND = 0, WALK, RUN, SIT, JUMP
};

//キャラの行動
enum class ACTION {
	NONE = -1, ATTACK, SHIFT, SKILL,DEBUG
};

//パラメーター
struct PARAMETER
{
	char* name;//名前
	float speed;//移動スピード
	float shift;//瞬間移動の距離
};


#endif // !__STATIC_GAME_DEFINITION_H__

