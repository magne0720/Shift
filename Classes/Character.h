#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
#include "AttackManager.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;
using namespace std;




//�L�����N�^
//�o�ꂷ��L�����̊��N���X
//���ʂłł��邱��
//�ړ��E�u�Ԉړ�
class Character :public Node
{
public:
	PARAMETER* myParameter;

	STATE myState;
	ACTION myAction;
	AttackManager* attackManager;
	int frontSide;//�ǂ���������Ă��邩
	int refCount;
	int comboCount;//�R���{�̉�(���݂̃R���{��)
	//�U�����̃^�C�}�[----
	float actionClock;
	float delayTimer;
	float keepTimer;
	float standbyTimer;
	//-----------------------------
	bool isCommand;//�R�}���h�����������ǂ���
	Sprite* mySprite;//�摜
	Vec2 moveDirection;//���������Ƃ��Ă������
	Vec2 myPosition;//���g�̈ʒu
	Vector<Geometry*> attackGeometry;//���߂��R���{�����炩���ߐݒ肵�Ă���
	//�f�o�b�O�R�}���h�̈�-----------
	
	Label* debugLabel;
	
	//-------------------------------------------

	static Character* create(PARAMETER p);
	bool init(PARAMETER p);
	void update(float delta);

	//�ړ�
	void move(float speed);
	//�ʏ�U��
	void attack(ATTACK_ACTION action);
	//�u�Ԉړ�
	void shift(float degree);
	//�K�E�Z
	void skill(void* skill);

	//�Z�b�^�[
	void setSprite(char* spname);

	//���Ԃ�������
	void resetTimer();

	//�U���{�^��
	void pushAction(ACTION action);
	//�R���{�p��
	void addCombo();
};

#endif // !__CHARACTER_H__
