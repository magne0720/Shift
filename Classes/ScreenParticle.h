#ifndef __SCREEN_PARTICLE_H__
#define __SCREEN_PARTICLE_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;


class ParticleNormal :public Node
{
public:
	Vec2 position;
	Vec2 direction;//移動方向
	float speed;//スピード
	float decayTime;//寿命
	float timer;//時間経過
	Sprite*drawSprite;
	bool isDeleted;
	Vec2* parentPosition;

	static ParticleNormal* create(char* name = "circle.png");
	bool init(char* name);
	void update(float delta);
	void reset();
};


//何個のパーティクルを作るか
//生成時の方向
//寿命
//色
class ParticleLauncher :public Node
{
public:
	ParticleNormal* particle;
	Vector<ParticleNormal*>particleBox;
	int instanceCount;
	Vec2* originPosition;
	float directionRadius;
	float instanceRange;
	float timer;

	static ParticleLauncher* create(Vec2*origin,int count = 30, float range = 30.0f);
	bool init(Vec2*origin,int count, float range);
	void update(float delta);


};


#endif // !__SCREEN_PARTICLE_H__
