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

	//�W�I���g���̒�������Ȃ�\������
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

//�ړ�
void Character::move(float speed) 
{
	myPosition.x += speed;
	setPosition(myPosition);
};

//�ʏ�U��(�~����)
void Character::attack(AttackAction* action)
{

	//�J�n���Ԃ��v��
	if (delayTimer >= 0)
	{
		delayTimer = action->delay - actionClock;
		debugLabel->setString("delay");
	}
	//�J�n���Ԃ�0������莟��A�������Ԃ̌v���J�n
	//�A�N�V�����̎��s
	if (delayTimer < 0) 
	{
		keepTimer = action->delay+action->keep-actionClock;
		action->obj->pos = ((action->keep-keepTimer)*action->obj->move+keepTimer*action->obj->pos);
		//action->obj->pos.x += 1.0f;
		debugLabel->setString("keep");
	}
	//�������Ԃ�0������莟��A��t���Ԃ̌v���J�n
	if (keepTimer < 0) 
	{
		standbyTimer = action->standby-actionClock;
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
