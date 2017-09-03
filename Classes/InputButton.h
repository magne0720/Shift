#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__



#include "cocos2d.h"

using namespace cocos2d;

class InputButton :public Sprite
{
public:

	Sprite *onSp, *offSp;//‰Ÿ‚³‚ê‚½ó‘ÔA‰Ÿ‚³‚ê‚Ä‚¢‚È‚¢ó‘Ô‚Ì‰æ‘œ
	bool isPut;//‰Ÿ‚³‚ê‚Ä‚¢‚é‚©‚Ç‚¤‚©

	static InputButton* create(char* off_path = "default.png", char* on_path = "default.png");
	bool init(char* off_path = "default.png", char* on_path = "default.png");


};


#endif
