#include "UserInput.h"

UserInput* UserInput::createPlayer(int mode) 
{
	UserInput *pRet = new UserInput();
	if (pRet && pRet->init(mode))
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

bool UserInput::init(int mode) 
{
	if (!Node::init())return false;

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(UserInput::menuCloseCallback, this));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2(100,100));
	this->addChild(menu, 1);

	return true;
};

void UserInput::changeMode(int mode) 
{

};


void UserInput::menuCloseCallback(Ref* pSender)
{
	playerCharacter->pushAction(ACTION::ATTACK);
};
