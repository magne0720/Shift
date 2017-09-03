#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__



#include "cocos2d.h"

using namespace cocos2d;

class InputButton :public Sprite
{
public:

	Sprite *onSp, *offSp;//押された状態、押されていない状態の画像
	bool isPut;//押されているかどうか

	static InputButton* create(char* off_path = "default.png", char* on_path = "default.png");
	bool init(char* off_path = "default.png", char* on_path = "default.png");


};


#endif
