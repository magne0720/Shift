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

	setPosition(Vec2(100,100));

	setSprite("Character/default.png");

	myAction = ACTION::NONE;

	attackManager = AttackManager::create();
	addChild(attackManager);

	scheduleUpdate();

	debugLabel = Label::create();
	debugLabel->setPosition(Vec2(100, 100));
	addChild(debugLabel);

	resetTimer();

	return true;
};

void Character::update(float delta) 
{
	//�W�I���g���̒�������Ȃ�\������
	for each (Geometry* geo in attackGeometry)
	{
		geo->drawGeometry();
	}

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
	}
	switch (myAction)
	{
	case ACTION::NONE:
		break;
	case ACTION::ATTACK:
		attack(attackManager->getNextAttack());
		actionClock += delta;
		break;
	case ACTION::SHIFT:
		break;
	case ACTION::SKILL:
		break;
	default:
		break;
	}
};

//�ړ�
void Character::move(float speed) 
{
	setPositionX(getPositionX() + speed);
};

//�ʏ�U��(�~����)
void Character::attack(ATTACK_ACTION action)
{
	//log("%s", action.name);
	//log("d=%0.2f", delayTimer);
	//log("k=%0.2f", keepTimer);
	//log("s=%0.2f", standbyTimer);

	//�J�n���Ԃ��v��
	if (delayTimer >= 0)
	{
		delayTimer = action.delay - actionClock;
		debugLabel->setString("delay");
	}
	//�J�n���Ԃ�0������莟��A�������Ԃ̌v���J�n
	//�A�N�V�����̎��s
	if (delayTimer < 0) 
	{
		keepTimer = action.delay+action.keep-actionClock;
		action.obj->pos = myPosition+frontSide*((1-keepTimer/action.keep)*action.obj->pos+keepTimer/action.keep*action.obj->move);
		debugLabel->setString("keep");
	}
	//�������Ԃ�0������莟��A��t���Ԃ̌v���J�n
	if (keepTimer < 0) 
	{
		standbyTimer = action.standby-actionClock;
		debugLabel->setString("standby");
	}
	//��t���Ԓ��ɃR�}���h��������Ă����玟�̃A�N�V�����̐ݒ�
	if (standbyTimer > 0 && isCommand) 
	{
		resetTimer();
		comboCount++;
	}
	//��t���Ԃ�0������莟��A�I������
	if (standbyTimer < 0) 
	{
		resetTimer();
		myAction = ACTION::NONE;
		debugLabel->setString("end");
		comboCount = 0;
	}
	//�ړ�(���`���)�B��ɃC�[�W���O�Ƃ�
	


	//������������Ȃ���
	isCommand = false;
};

//�u�Ԉړ�
void Character::shift(float degree)
{

};
//�K�E�Z
void Character::skill(void* skill) 
{

};

void Character::setSprite(char* spname) 
{
	mySprite->setTexture(spname);
};

//���Ԃ�������
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
