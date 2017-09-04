#include "Geometry.h"

Geometry* Geometry::create(Vec2 p, Vec2 m) 
{
	Geometry *pRet = new Geometry();
	if (pRet && pRet->init(p,m))
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

bool Geometry::init(Vec2 p, Vec2 m) 
{
	if (!Node::init()) return false;

	dn = DrawNode::create();
	addChild(dn);

	log("Geometry");

	//scheduleUpdate();

	return true;
};

void Geometry::update(float delta) 
{
	log("update_base");
	drawGeometry();
};

//dummy
void Geometry::setGeometry() {};
void Geometry::setGeometry(float r) {};
void Geometry::setGeometry(Vec2 p, Vec2 m) {};

void Geometry::drawGeometry() 
{
	dn->clear();
	dn->drawDot(pos, 5, Color4F::GREEN);
};

GeometryCircle* GeometryCircle::create(Vec2 p, Vec2 m) 
{
	GeometryCircle *pRet = new GeometryCircle();
	if (pRet && pRet->init(p, m))
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

bool GeometryCircle::init(Vec2 p, Vec2 m) 
{
	if (!Node::init())return false;

	dn = DrawNode::create();
	addChild(dn);

	r = 100.0f;
	pos = p;
	move = m;

	log("GeometryCircle");

	scheduleUpdate();

	return true;
};

void GeometryCircle::update(float delta)
{
	drawGeometry();
};

void GeometryCircle::drawGeometry() 
{
	dn->clear();
	dn->drawCircle(pos, r, 0, 360, true, Color4F::BLUE);
};

GeometryLine* GeometryLine::create(Vec2 p, Vec2 m) 
{
	GeometryLine *pRet = new GeometryLine();
	if (pRet && pRet->init(p, m))
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

bool GeometryLine::init(Vec2 p, Vec2 m) 
{
	if (!Node::init())return false;

	dn = DrawNode::create();
	addChild(dn);

	dir = Vec2(200, 200);

	log("GeometryLine");

	scheduleUpdate();

	return true;
};

void GeometryLine::update(float delta)
{
	drawGeometry();
};

void GeometryLine::drawGeometry() 
{
	dn->clear();
	dn->drawLine(pos, move, Color4F::GREEN);
};
