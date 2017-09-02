#ifndef __ACTION_MANAGER_H__
#define __ACTION_NAMAGER_H__

#include "cocos2d.h"
#include "Geometry.h"

using namespace cocos2d;
using namespace std;

//ACTION_STACK�ɂ���
//�U���P���̎d�l
//	�P�D�U�������n�߂Ă���U������̂���}�`���o���܂ł̎���
//	�Q�D���̐}�`���ő�̏�Ԃ��ێ����鎞��
//	�R�D���̐}�`���o�Ă���ԂɈړ����鋗��
//	�S�D���̐}�`�������鎞��(�����U�����ԂƓ��`)
//	�T�D�R���{���e����(�Q�I��������v��)
//	�U�D���̃R���{���
struct ATTACK_ACTION {
	Geometry* obj;
	char* name;//���̍U���̖��O
	float radius;//�U���͈͂̔��a
	float delay;//�U�����肪�o��܂ł̑҂�����
	float keep;//�U�����肪�o�Ă��鎝������
	float standby;//�R���{���e����(��{�Idelay�I����)
	float powerrate;//�U���{��
	Vec2 move;//���̍U�����ɂ���ړ���
	Vec2 distance;//�U���͈͂��ړ������(�o�Ă��鎝�����ԂŐ��`���)
	///<summary>
	///ACTION_STACK�̐ݒ�
	///type=�U���͈͂̌`(0:circle,1:line,def:none)
	///</summary>
	ATTACK_ACTION(int type,char *name="action",float radius = 1.0f, float delay = 1.0f, float keep = 0.5f, float standby = 2.0f, float powerrate = 1, Vec2 move = Vec2(0, 0), Vec2 distance = Vec2(0, 0)) {
		obj = GeometryCircle::create(Vec2(0,0),Vec2(0,0));
		this->name = name;
		this->radius = radius;
		this->delay = delay;
		this->keep = keep;
		this->standby = standby;
		this->powerrate = powerrate;
		this->move = move;
		this->distance = distance;
	}
};

class AttackManager :public Node 
{
public:
	vector<ATTACK_ACTION> attackStack;

	static AttackManager* create();
	bool init();
	ATTACK_ACTION getNextAttack();
	//	static Vector<ACTION_ATTACK_CIRCLE> actions;
	//static ACTION_ATTACK_CIRCLE* load(char* path);
	//vector<ACTION_ATTACK_CIRCLE> AttackActions;
};

#endif // !__ACTION_MANAGER_H__
