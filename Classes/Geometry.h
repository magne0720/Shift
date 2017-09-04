#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "cocos2d.h"

using namespace cocos2d;

//�U���͈͂ƂȂ�}�`
class Geometry:public Node
{
public:
		Vec2 pos;//�n�_
		Vec2 move;//���̐}�`�̈ړ��I�_

		static Geometry* create(Vec2 p,Vec2 m);
		bool virtual init(Vec2 p, Vec2 m);
		void virtual update(float delta);
		void virtual setGeometry();
		void virtual setGeometry(float r);
		void virtual setGeometry(Vec2 p,Vec2 m);
		void virtual drawGeometry();
		//�f�o�b�O------------------
		DrawNode* dn;

		//-------------------------------
};

class GeometryCircle :public Geometry
{
public:
	float r;//���a

	static GeometryCircle* create(Vec2 p, Vec2 m);
	bool init(Vec2 p, Vec2 m);
	void update(float delta);
	void drawGeometry();
};

class GeometryLine :public Geometry
{
public:
	Vec2 dir;//�I�_

	static GeometryLine* create(Vec2 p, Vec2 m);
	bool init(Vec2 p, Vec2 m);
	void update(float delta);
	void drawGeometry();
};



#endif // !__GEOMETRY_H__
