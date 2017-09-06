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
	playerLabel->enableShadow(Color4B::WHITE);
	addChild(playerLabel);

	tex = RenderTexture::create(designResolutionSize.width, designResolutionSize.height);
	addChild(tex);

	speedUpButton = InputButton::create(ACTION::DEBUG, "speed_up_UI.png", "speed_up_UI.png");
	speedUpButton->setPosition(designResolutionSize.width*0.97f, designResolutionSize.height*0.9f);
	addChild(speedUpButton);

	speedDownButton = InputButton::create(ACTION::DEBUG, "speed_down_UI.png", "speed_down_UI.png");
	speedDownButton->setPosition(designResolutionSize.width*0.9f, designResolutionSize.height*0.9f);
	addChild(speedDownButton);

	debugButton = InputButton::create(ACTION::DEBUG, "skill_on_UI.png", "skill_UI.png");
	debugButton->setPosition(Vec2(designResolutionSize.width*0.6f, designResolutionSize.height*0.9f));
	addChild(debugButton);

	logButton = SwitchButton::create(ACTION::DEBUG, "log_on_UI.png", "log_off_UI.png");
	logButton->setPosition(Vec2(designResolutionSize.width*0.8f, designResolutionSize.height*0.9f));
	addChild(logButton);

	scheduleUpdate();

	return true;
};

void DebugLogOutPut::update(float delta)
{
	if (speedDownButton->isPut)debugCharacter->addSpeed(-0.1f);
	if (speedUpButton->isPut)debugCharacter->addSpeed(0.1f);
	if (debugButton->isPut)debugCharacter->myPosition = Vec2(100, 100);

	if (logButton->isPut){

		//String* log_pos = String::createWithFormat("position,x:%0.1f,y:%0.1f", debugCharacter->myPosition.x, debugCharacter->myPosition.y);
		//String* log_move = String::createWithFormat("move,x:%0.1f,y:%0.1f", debugCharacter->moveDirection.x, debugCharacter->moveDirection.y);
		String* log_speed = String::createWithFormat("speed:%0.2f", debugCharacter->getSpeed());
		String* log_isattack = String::createWithFormat("isAttack[%s]", debugCharacter->isAttack ? "true" : "false");
		String* log_actionSize = String::createWithFormat("action_size[%d]", debugCharacter->attackAction.size());
		String* log_geometrySize = String::createWithFormat("geometry_size[%d]", debugCharacter->attackGeometry.size());
		String* log_state = String::createWithFormat("state[%s]", getStateName(debugCharacter->myState));
		String* log_action = String::createWithFormat("action[%s]", getActionName(debugCharacter->myAction));


		//logs.pushBack(log_pos);
		//logs.pushBack(log_move);
		logs.pushBack(log_speed);
		logs.pushBack(log_isattack);
		logs.pushBack(log_actionSize);
		logs.pushBack(log_geometrySize);
		logs.pushBack(log_state);
		logs.pushBack(log_action);

	}

	String* log_all = String::createWithFormat("%s\n",logButton->isPut ? "log_show" : "log_hide");

	for (int i = 0; i<logs.size(); i++)
	{
		log_all->appendWithFormat("%s\n", logs.at(i)->getCString());
	}

	playerLabel->setString(log_all->getCString());
	logs.clear();
}

void DebugLogOutPut::setStringPlayer(Character*& character)
{
	this->debugCharacter = character;
};
