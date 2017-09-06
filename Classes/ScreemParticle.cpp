#include "ScreenParticle.h"



ParticleNormal* ParticleNormal::create(char* name)
{
	ParticleNormal *pRet = new ParticleNormal();
	if (pRet && pRet->init(name))
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

bool ParticleNormal::init(char* name)
{
	if (!Node::init())return false;

	drawSprite = Sprite::create(name);
	drawSprite->setColor(Color3B::BLUE);
	addChild(drawSprite);

	isDeleted = false;
	decayTime = 2.0f;
	timer = 0.0f;

	speed = random(-10.0f, 10.0f) / 10.0f;

	direction.x = random(-100, 100);
	direction.y = random(-100, 100);
	direction.normalize();


	scheduleUpdate();

	return true;
};

void ParticleNormal::update(float delta)
{
	timer += delta;

	position += direction*speed;
	setPosition(position);
	drawSprite->setScale(sin(2.0f*M_PI*timer / decayTime*3.0f));
	if (timer >= decayTime)
	{
		isDeleted = true;
		unscheduleUpdate();
	}
};

void ParticleNormal::reset()
{
	isDeleted = false;
	timer = 0;
	decayTime = decayTime+random(-3,3);
	position=(Vec2(0, 0));
	scheduleUpdate();
};

ParticleLauncher* ParticleLauncher::create(Vec2* origin,int count, float range)
{
	ParticleLauncher *pRet = new ParticleLauncher();
	if (pRet && pRet->init(origin,count,range))
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

bool ParticleLauncher::init(Vec2* origin,int count, float range)
{
	if (!Node::init())return false;

	particle = ParticleNormal::create();

	instanceCount=count;
	instanceRange = range;
	originPosition = origin;

	for (int i = 0; i < count; i++)
	{
		ParticleNormal* pa = ParticleNormal::create();
		pa->parentPosition = originPosition;
		addChild(pa);
		particleBox.pushBack(pa);
	}

	timer = 0;

	scheduleUpdate();

	return true;
};

void ParticleLauncher::update(float delta)
{
	timer += delta;

	//originPosition->x = sin(2.0f*M_PI*timer)*400+designResolutionSize.width*0.5f;
	for (int i = 0; i < particleBox.size(); i++)
	{
		if (particleBox.at(i)->isDeleted)
		{
			particleBox.at(i)->reset();
		}
	}
};
