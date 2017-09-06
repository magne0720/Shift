#include "TestFieldScene.h"
#include "Character.h"
#include "UserInput.h"
#include "ScreenParticle.h"

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

	Layer* la = LayerColor::create(Color4B::WHITE);
	addChild(la);

	Sprite* background = Sprite::create("testbackground.png");
	background->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	background->setPosition(0, 0);
	la->addChild(background);


	UserInput* controller=UserInput::createPlayer();
	addChild(controller);

	Character* character=Character::create(PARAMETER());
	addChild(character);

	controller->playerCharacter = character;

	ParticleLauncher* PL = ParticleLauncher::create(&character->myPosition);
	PL->setPosition(designResolutionSize.width*0.5f,designResolutionSize.height*0.5f);
	addChild(PL);

	DebugLogOutPut* debug = DebugLogOutPut::create();
	addChild(debug);
	debug->setStringPlayer(character);

	return true;
};
