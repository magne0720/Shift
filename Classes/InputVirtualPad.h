#ifndef __INPUT_VIRTUAL_PAD_H__
#define __INPUT_VIRTUAL_PAD_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;

class InputVirtualPad :public Node
{
public:
	Vec2 beganPosition;//始点となる位置
	Vec2 movePosition;//移動量
	Vec2 boundingSection;//可動範囲
	Sprite *baseSp, *arrowSp;//パッドの下地、ユーザーが触っている位置の画像
	bool isMove;
	
	static InputVirtualPad* create();
	bool init();


	bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);
	void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent);


};


#endif // !__INPUT_VIRTUAL_PAD_H__
