#include "TestFieldScene.h"
#include "Character.h"
#include "UserInput.h"

TestFieldScene* TestFieldScene::createScene() 
{
	TestFieldScene *pRet = new TestFieldScene();
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

bool TestFieldScene::init() 
{
	if (!Scene::init())return false;

	UserInput* controller=UserInput::createPlayer();
	addChild(controller);

	Character* character=Character::create(PARAMETER());
	addChild(character);

	controller->playerCharacter = character;

	return true;
};
