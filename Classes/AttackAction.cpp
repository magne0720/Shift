#include "AttackAction.h"

AttackAction* AttackAction::create(int type,char *name,float radius,float delayf,float keep,float standby,Vec2 move,Vec2 distance)
{
	AttackAction *pRet = new AttackAction();
	if (pRet && pRet->init( type, name, radius, delayf,  keep,standby,move,distance))
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

bool AttackAction::init(int type, char *name, float radius, float delay, float keep, float standby, Vec2 move, Vec2 distance)
{
	if (!Node::init()) return false;

	obj = GeometryCircle::create(Vec2(0, 0), move);
	addChild(obj);

	//count = type;
	this->name = name;
	this->radius = radius;
	this->delay = delay;
	this->keep = keep;
	this->standby = standby;
	this->move = move;
	this->distance = distance;

	return true;
};
