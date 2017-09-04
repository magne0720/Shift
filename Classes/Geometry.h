#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "cocos2d.h"

using namespace cocos2d;

//攻撃範囲となる図形
class Geometry:public Node
{
public:
		Vec2 pos;//始点
		Vec2 move;//この図形の移動終点

		static Geometry* create(Vec2 p,Vec2 m);
		bool virtual init(Vec2 p, Vec2 m);
		void virtual update(float delta);
		void virtual setGeometry();
		void virtual setGeometry(float r);
		void virtual setGeometry(Vec2 p,Vec2 m);
		void virtual drawGeometry();
		//デバッグ------------------
		DrawNode* dn;

		//-------------------------------
};

class GeometryCircle :public Geometry
{
public:
	float r;//半径

	static GeometryCircle* create(Vec2 p, Vec2 m);
	bool init(Vec2 p, Vec2 m);
	void update(float delta);
	void drawGeometry();
};

class GeometryLine :public Geometry
{
public:
	Vec2 dir;//終点

	static GeometryLine* create(Vec2 p, Vec2 m);
	bool init(Vec2 p, Vec2 m);
	void update(float delta);
	void drawGeometry();
};



#endif // !__GEOMETRY_H__
