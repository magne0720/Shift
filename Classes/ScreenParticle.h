#ifndef __SCREEN_PARTICLE_H__
#define __SCREEN_PARTICLE_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;

class ParticleOrigin :public Node
{
public:
	Vec2 position;
	Vec2 direction;//�ړ�����
	float speed;//�X�s�[�h
	float decayTime;//����
	float timer;//���Ԍo��
	bool isDeleted;
	Vec2* parentPosition;

	void virtual reset() = 0;
};

class ParticleNormal :public ParticleOrigin
{
public:
	
	Sprite*drawSprite;

	static ParticleNormal* create(char* name = "circle.png");
	bool init(char* name);
	void update(float delta);
	void reset();
};

class ParticleGeometry :public ParticleOrigin
{
public:
	float maxDistance;
	std::vector<Vec2> vertexBox;
	std::vector<Vec2> vertexAngleBox;
	std::vector<float> vertexTimerBox;
	DrawNode* drawNode;

	static ParticleGeometry* create(int count=12);
	bool init(int count);
	void update(float delta);
	void reset();
};

//���̃p�[�e�B�N������邩
//�������̕���
//����
//�F
class ParticleLauncher :public Node
{
public:
	ParticleOrigin* particle;
	Vector<ParticleOrigin*>particleBox;
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
