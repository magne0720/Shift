#include "DebugLogOutPut.h"

DebugLogOutPut* DebugLogOutPut::create()
{
	DebugLogOutPut *pRet = new DebugLogOutPut();
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

bool DebugLogOutPut::init()
{
	if (!Node::init())return false;

	playerLabel = Label::create();
	playerLabel->setTextColor(Color4B::BLACK);
	playerLabel->setSystemFontSize(48);
	playerLabel->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	playerLabel->setPosition(designResolutionSize.width*0.0f, designResolutionSize.height*1.0f);
	addChild(playerLabel);

	scheduleUpdate();

	return true;
};

void DebugLogOutPut::update(float delta)
{
	String* log_pos = String::createWithFormat("position,x:%0.1f,y:%0.1f", debugCharacter->myPosition.x, debugCharacter->myPosition.y);
	String* log_move = String::createWithFormat("move,x:%0.1f,y:%0.1f", debugCharacter->moveDirection.x, debugCharacter->moveDirection.y);
	String* log_action = String::createWithFormat("action[%s]", action);
	String* log_all = String::createWithFormat("%s\n%s\n%s", log_pos->getCString(), log_move->getCString(),log_action->getCString());
	playerLabel->setString(log_all->getCString());
}

void DebugLogOutPut::setStringPlayer(Character* character, char* action)
{
	this->debugCharacter = character;
	this->action = action;
};
