#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;


class Button :public Sprite
{
public:
	bool isPut;//押されているかどうか
	float buttonRange;
	ACTION actionType;
protected:
	char *onTexPath, *offTexPath;//押された状態、話した状態の画像パス

	bool virtual onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)=0;
	void virtual onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)=0;
	void virtual onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)=0;

	void virtual putbutton(bool is)=0;

};

class InputButton :public Button
{
public:
	static InputButton* create(ACTION type, char* off_path = "default.png", char* on_path = "default.png");
	bool init(ACTION type, char* off_path = "default.png", char* on_path = "default.png");

	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	void putbutton(bool is);
};


class SwitchButton :public Button
{
public:
	static SwitchButton* create(ACTION type, char* off_path = "default.png", char* on_path = "default.png");
	bool init(ACTION type, char* off_path = "default.png", char* on_path = "default.png");

	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	void putbutton(bool is);
};

#endif
