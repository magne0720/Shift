#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;

class InputButton :public Sprite
{
public:
	float buttonRange;
	char *onTexPath, *offTexPath;//押された状態、話した状態の画像パス
	bool isPut;//押されているかどうか
	ACTION actionType;

	static InputButton* create(ACTION type,char* off_path = "default.png", char* on_path = "default.png");
	bool init(ACTION type, char* off_path = "default.png", char* on_path = "default.png");

	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	void putbutton(bool is);

};


#endif
