#ifndef __INPUT_BUTTON_H__
#define __INPUT_BUTTON_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;

class InputButton :public Sprite
{
public:
	float buttonRange;
	char *onTexPath, *offTexPath;//�����ꂽ��ԁA�b������Ԃ̉摜�p�X
	bool isPut;//������Ă��邩�ǂ���
	ACTION actionType;

	static InputButton* create(ACTION type,char* off_path = "default.png", char* on_path = "default.png");
	bool init(ACTION type, char* off_path = "default.png", char* on_path = "default.png");

	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);

	void putbutton(bool is);

};


#endif
