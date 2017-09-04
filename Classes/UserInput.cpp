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


	attackButton = InputButton::create(ACTION::ATTACK,"attack_on_UI.png", "attack_UI.png");
	attackButton->setPosition(Vec2(designResolutionSize.width - attackButton->getBoundingBox().getMaxX(), designResolutionSize.height*0.0f + attackButton->getBoundingBox().getMaxY()));
	addChild(attackButton);

	skillButton = InputButton::create(ACTION::SKILL, "skill_on_UI.png", "skill_UI.png");
	skillButton->setPosition(Vec2(designResolutionSize.width - skillButton->getBoundingBox().getMaxX(), designResolutionSize.height*0.0f + skillButton->getBoundingBox().getMaxY() + 200));
	addChild(skillButton);

	debugButton = InputButton::create(ACTION::DEBUG, "skill_on_UI.png", "skill_UI.png");
	debugButton->setPosition(Vec2(designResolutionSize.width*0.5f, designResolutionSize.height*0.9f));
	addChild(debugButton);

	pad = InputVirtualPad::create();
	addChild(pad);

	scheduleUpdate();

	return true;
};

void UserInput::update(float delta)
{
	if (pad->isMove)
	{
		playerCharacter->moveDirection = pad->movePosition;
	}
	else{
		playerCharacter->moveDirection = Vec2(0, 0);
	}

	if (attackButton->isPut){
		userAction(attackButton);
	}
	else if (skillButton->isPut){
		userAction(skillButton);
	}
	else if (debugButton->isPut){
		userAction(debugButton);
	}
	else{}
}

void UserInput::setPlayer(Character* c)
{
	playerCharacter = c;
};

void UserInput::changeMode(int mode) 
{

};


void UserInput::menuCloseCallback(Ref* pSender)
{
	playerCharacter->pushAction(ACTION::ATTACK);
};

void UserInput::userAction(InputButton* b)
{
	playerCharacter->pushAction(b->actionType);
	b->isPut = false;
}
