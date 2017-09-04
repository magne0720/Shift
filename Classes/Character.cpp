#include "Character.h"

Character* Character::create(PARAMETER p)
{
	Character *pRet = new Character();
	if (pRet && pRet->init(p))
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

bool Character::init(PARAMETER p) 
{
	if (!Node::init())return false;

	mySprite = Sprite::create();
	addChild(mySprite);

	myPosition = Vec2(100, 100);
	setPosition(myPosition);

	setSprite("Character/default.png");

	myAction = ACTION::NONE;
	myState = STATE::WALK;

	myParameter.speed = 3.35f;

	scheduleUpdate();

	debugLabel = Label::create();
	debugLabel->setTextColor(Color4B::RED);
	debugLabel->setSystemFontSize(120);
	debugLabel->setPosition(Vec2(200,200));
	addChild(debugLabel);

	AttackAction* atk = AttackAction::create(5);
	addChild(atk);
	attackAction.pushBack(atk);


	resetTimer();

	return true;
};

void Character::update(float delta) 
{

	//ジオメトリの中があるなら表示する
	for (int i = 0; i < attackGeometry.size();i++)
	{
		attackGeometry.at(i)->drawGeometry();
	};

	move(moveDirection.x*myParameter.speed);
	switch (myState)
	{
	case STATE::NONE:
		break;
	case STATE::STAND:
		break;
	case STATE::WALK:
		break;
	case STATE::RUN:
		break;
	case STATE::SIT:
		break;
	case STATE::JUMP:
		break;
	default:
		break;
	};
	switch (myAction)
	{
	case ACTION::NONE:
		break;
	case ACTION::ATTACK:
		attack(attackAction.at(0));
		actionClock += delta;
		break;
	case ACTION::SHIFT:
		break;
	case ACTION::SKILL:
		break;
	case ACTION::DEBUG:
		myPosition = Vec2(100, 100);
		myAction = ACTION::NONE;
		break;
	default:
		break;
	};
};

//移動
void Character::move(float speed) 
{
	myPosition.x += speed;
	setPosition(myPosition);
};

//通常攻撃(円判定)
void Character::attack(AttackAction* action)
{

	//開始時間を計測
	if (delayTimer >= 0)
	{
		delayTimer = action->delay - actionClock;
		debugLabel->setString("delay");
	}
	//開始時間が0を下回り次第、持続時間の計測開始
	//アクションの実行
	if (delayTimer < 0) 
	{
		keepTimer = action->delay+action->keep-actionClock;
		action->obj->pos = ((action->keep-keepTimer)*action->obj->move+keepTimer*action->obj->pos);
		//action->obj->pos.x += 1.0f;
		debugLabel->setString("keep");
	}
	//持続時間が0を下回り次第、受付時間の計測開始
	if (keepTimer < 0) 
	{
		standbyTimer = action->standby-actionClock;
		debugLabel->setString("standby");
	}
	//受付時間中にコマンドが押されていたら次のアクションの設定
	if (standbyTimer > 0 && isCommand) 
	{
		resetTimer();
		comboCount++;
	}
	//受付時間が0を下回り次第、終了する
	if (standbyTimer < 0) 
	{
		resetTimer();
		myAction = ACTION::NONE;
		debugLabel->setString("end");
		comboCount = 0;
	}
	//移動(線形補間)。後にイージングとか
	


	//押した判定をなくす
	isCommand = false;
};

//瞬間移動
void Character::shift(float degree)
{

};
//必殺技
void Character::skill(void* skill) 
{

};

void Character::setSprite(char* spname) 
{
	mySprite->setTexture(spname);
};

//時間を初期化
void Character::resetTimer() 
{
	delayTimer = 0;
	keepTimer = 0;
	standbyTimer = 0;
	actionClock = 0;
};

void Character::pushAction(ACTION action) 
{
	isCommand = true;
	myAction = action;
}
