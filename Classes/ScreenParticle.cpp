
#include "ScreenParticle.h"


//------------------------------------------------------------------------------------------------------
//ParticleNormal
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
	decayTime = decayTime + random(-3, 3);
	position = (Vec2(0, 0));
	scheduleUpdate();
};
//----------------------------------------------------------------------------------------------------------------
//ParticleGeometry
ParticleGeometry* ParticleGeometry::create(int count)
{
	ParticleGeometry *pRet = new ParticleGeometry();
	if (pRet && pRet->init(count))
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

bool ParticleGeometry::init(int count)
{
	if (!Node::init())return false;

	drawNode = DrawNode::create();
	addChild(drawNode);

	isDeleted = false;
	decayTime = random(2.0f, 4.0f);
	timer = 0.0f;

	speed = random(1.0f, 4.0f);

	direction.x = random(-100, 100);
	direction.y = random(-100, 100);
	direction.normalize();

	maxDistance = 10.0f;
	for (int i = 0; i < count; i++)
	{
		float seta = (float)i / (float)count * M_PI *2.0f;
		Vec2 pos = Vec2((cos(seta) - sin(seta))*maxDistance, (sin(seta) + cos(seta))*maxDistance);
		vertexBox.push_back(pos);
		vertexAngleBox.push_back(pos);
		vertexTimerBox.push_back(2.0f);
	}

	scheduleUpdate();

	return true;
};

void ParticleGeometry::update(float delta)
{

	if (timer >= decayTime)
	{
		isDeleted = true;
		unscheduleUpdate();
		return;
	}

	for (int i = 0; i < vertexBox.size(); i++)
	{
		Vec2 pos = vertexAngleBox.at(i)*cos(M_PI / 360)* vertexTimerBox.at(i)*timer *speed;
		vertexBox.at(i).set(pos);
	}
	
	drawNode->clear();
	drawNode->drawPolygon(&vertexBox.at(0), vertexBox.size(),
	Color4F(1-(timer/decayTime),timer/decayTime,sin(M_PI*timer/decayTime),sin(M_PI*timer/decayTime)),decayTime, Color4F(0, 0, 0, 0));
	
	timer +=speed/100.0f;

	position += direction*speed;
	setPosition(position);
};

void ParticleGeometry::reset()
{
	isDeleted = false;
	timer = 0;
	decayTime = random(2.0f, 9.0f);
	direction.x = random(-100, 100);
	direction.y = random(-100, 100);
	direction.normalize();
	position = (Vec2(0, 0));
	setZOrder(1);
	scheduleUpdate();
};

//---------------------------------------------------------------------------------------------------------------------



ParticleLauncher* ParticleLauncher::create(Vec2* origin, int count, float range)
{
	ParticleLauncher *pRet = new ParticleLauncher();
	if (pRet && pRet->init(origin, count, range))
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

bool ParticleLauncher::init(Vec2* origin, int count, float range)
{
	if (!Node::init())return false;

	particle = ParticleNormal::create();

	instanceCount = count;
	instanceRange = range;
	originPosition = origin;

	for (int i = 0; i < count; i++)
	{
		ParticleOrigin* pa = ParticleGeometry::create(120);
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

	originPosition->x = sin(2.0f*M_PI*timer) * 400;
	originPosition->y = cos(2.0f*M_PI*timer) * 100;
	for (int i = 0; i < particleBox.size(); i++)
	{
		if (particleBox.at(i)->isDeleted)
		{
			particleBox.at(i)->reset();
			particleBox.at(i)->position = *originPosition;
		}
	}
};
