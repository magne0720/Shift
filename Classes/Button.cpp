#include "Button.h"

InputButton* InputButton::create(ACTION type, char* on_path, char* off_path)
{
	InputButton *pRet = new InputButton();
	if (pRet && pRet->init(type,on_path,off_path))
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

bool InputButton::init(ACTION type, char* on_path, char* off_path)
{
	if (!Sprite::init())return false;

	//タッチ判定
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(InputButton::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(InputButton::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(InputButton::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	actionType = type;
	onTexPath = on_path;
	offTexPath = off_path;
	initWithFile(offTexPath);
	isPut = false;

	buttonRange = getBoundingBox().getMaxX();

	return true;
};

bool InputButton::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);
	if (col <= buttonRange*buttonRange)
	{
		putbutton(true);
		return true;
	}
	return false;
};

void InputButton::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	
};

void InputButton::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);
	if (col <= buttonRange*buttonRange)
	{
	}
	putbutton(false);
};

void InputButton::putbutton(bool is)
{
	isPut = is;
	if (is)
	{
		setTexture(onTexPath);
		setColor(Color3B(200, 200, 200));
	}
	else
	{
		setTexture(offTexPath);
		setColor(Color3B::WHITE);
	}
};

SwitchButton* SwitchButton::create(ACTION type, char* on_path, char* off_path)
{
	SwitchButton *pRet = new SwitchButton();
	if (pRet && pRet->init(type, on_path, off_path))
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

bool SwitchButton::init(ACTION type, char* on_path, char* off_path)
{
	if (!Sprite::init())return false;

	//タッチ判定
	EventListenerTouchOneByOne *listener = EventListenerTouchOneByOne::create();
	// 対象のイベントが実行された後、下位のイベントは発動されなくする
	//listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(SwitchButton::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SwitchButton::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SwitchButton::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	actionType = type;
	onTexPath = on_path;
	offTexPath = off_path;
	initWithFile(offTexPath);
	isPut = false;

	buttonRange = getBoundingBox().getMaxX();

	return true;
};

bool SwitchButton::onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{
	Vec2 p = pTouch->getLocation();
	Vec2 t = getPosition();
	float col = pow(p.x - t.x, 2) + pow(p.y - t.y, 2);
	if (col <= buttonRange*buttonRange)
	{
		if (!isPut)
			putbutton(true);
		else
			putbutton(false);
		return true;
	}
	return false;
};

void SwitchButton::onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};

void SwitchButton::onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent)
{

};

void SwitchButton::putbutton(bool is)
{
	isPut = is;
	if (is)
	{
		setTexture(onTexPath);
		setColor(Color3B(200, 200, 200));
	}
	else
	{
		setTexture(offTexPath);
		setColor(Color3B::WHITE);
	}
};

