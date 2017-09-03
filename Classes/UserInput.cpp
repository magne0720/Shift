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

	InputButton* button = InputButton::create("attack_on_UI.png", "attack_UI.png");
	button->setPosition(Vec2(designResolutionSize.width*0.5f, designResolutionSize.height*0.5f));
	addChild(button);

	return true;
};

void UserInput::changeMode(int mode) 
{

};


void UserInput::menuCloseCallback(Ref* pSender)
{
	playerCharacter->pushAction(ACTION::ATTACK);
};
