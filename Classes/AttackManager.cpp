#include "AttackManager.h"

AttackManager* AttackManager::create() 
{
	AttackManager *pRet = new AttackManager();
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

bool AttackManager::init()
{
	if (!Node::init()) return false;
	
	attackStack.push_back(ATTACK_ACTION(0));


	return true;
};

ATTACK_ACTION AttackManager::getNextAttack()
{
	if (attackStack.size() > 0) 
	{
		return attackStack.at(0);
	}
	return ATTACK_ACTION(0);
};
