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
class AttackAction:public Node {
public:
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
	static AttackAction* create(
		int count, 
		char *name = "action",
		float radius = 1.0f,
		float delay = 1.0f,
		float keep = 0.5f,
		float standby = 2.0f,
		Vec2 move = Vec2(500, 0),
		Vec2 distance = Vec2(0, 0));
	bool init(
		int count,
		char *name,
		float radius,
		float delay,
		float keep,
		float standby,
		Vec2 move,
		Vec2 distance);
};

#endif // !__ACTION_MANAGER_H__
