#ifndef __INPUT_VIRTUAL_PAD_H__
#define __INPUT_VIRTUAL_PAD_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;

class InputVirtualPad :public Node
{
public:
	Vec2 beganPosition;//�n�_�ƂȂ�ʒu
	Vec2 movePosition;//�ړ���
	Vec2 boundingSection;//���͈�
	Sprite *baseSp, *arrowSp;//�p�b�h�̉��n�A���[�U�[���G���Ă���ʒu�̉摜
	bool isMove;
	
	static InputVirtualPad* create();
	bool init();


	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);


};


#endif // !__INPUT_VIRTUAL_PAD_H__
