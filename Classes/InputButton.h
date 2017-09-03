#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__



#include "cocos2d.h"

using namespace cocos2d;

class InputButton :public Sprite
{
public:

	Sprite *onSp, *offSp;//�����ꂽ��ԁA������Ă��Ȃ���Ԃ̉摜
	bool isPut;//������Ă��邩�ǂ���

	static InputButton* create(char* off_path = "default.png", char* on_path = "default.png");
	bool init(char* off_path = "default.png", char* on_path = "default.png");


};


#endif
