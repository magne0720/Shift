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
	la->addChild(background,LAYER_BACKGROUND);

	BlendFunc negativeBlend = { GL_ONE_MINUS_DST_COLOR, GL_ZERO };
	background->setBlendFunc(negativeBlend);

	UserInput* controller=UserInput::createPlayer();
	//controller->setVisible(false);
	la->addChild(controller,LAYER_UI);

	Character* character=Character::create(PARAMETER());
	//character->setVisible(false);
	la->addChild(character, LAYER_CHARACTER);

	controller->playerCharacter = character;

	ParticleLauncher* PLB = ParticleLauncher::create(&this->_position, 4);
	PLB->setPosition(designResolutionSize.width*0.5f, designResolutionSize.height*0.5f);
	la->addChild(PLB, LAYER_BACKPARTICLE);

	ParticleLauncher* PL = ParticleLauncher::create(&this->_position, 5);
	PL->setPosition(designResolutionSize.width*0.5f, designResolutionSize.height*0.5f);
	la->addChild(PL, LAYER_PARTICLE);

	DebugLogOutPut* debug = DebugLogOutPut::create();
	la->addChild(debug, LAYER_UI);
	//debug->setVisible(false);
	debug->setStringPlayer(character);

	return true;
};
