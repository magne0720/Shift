#include "InputVirtualPad.h"

InputVirtualPad* InputVirtualPad::create()
{
	InputVirtualPad *pRet = new InputVirtualPad();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
};

bool InputVirtualPad::init()
{
	if (!Node::init())return false;


	//タッチ判定
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(InputVirtualPad::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(InputVirtualPad::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(InputVirtualPad::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	baseSp = Sprite::create("pad_base_UI.png");
	baseSp->setVisible(false);
	addChild(baseSp);

	arrowSp = Sprite::create("pad_arrow_UI.png");
	arrowSp->setVisible(false);
	addChild(arrowSp);

	isMove = false;


	return true;
};

bool InputVirtualPad::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);
	if (p.x >= designResolutionSize.width*0.5f)return false;

	baseSp->setVisible(true);
	baseSp->setPosition(p);
	arrowSp->setVisible(true);
	arrowSp->setPosition(p);

	beganPosition = p;

	return true;
};

void InputVirtualPad::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);

	arrowSp->setPosition(p);
	isMove = true;

	movePosition = p - beganPosition;
	movePosition.normalize();

};

void InputVirtualPad::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);

	movePosition = Vec2(0, 0);
	isMove = false;

	baseSp->setVisible(false);
	arrowSp->setVisible(false);
};

