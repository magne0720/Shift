#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
#include "AttackAction.h"
#include "StaticGameDefinition.h"

using namespace cocos2d;
using namespace std;




//キャラクタ
//登場するキャラの基底クラス
//共通でできること
//移動・瞬間移動
class Character :public Node
{
public:
	PARAMETER myParameter;

	STATE myState;
	ACTION myAction;
	Vector<AttackAction*> attackAction;
	int frontSide;//どちらを向いているか
	int refCount;
	int comboCount;//コンボの回数(現在のコンボ数)
	//攻撃時のタイマー----
	float actionClock;
	float delayTimer;
	float keepTimer;
	float standbyTimer;
	//-----------------------------
	bool isCommand;//コマンドを押したかどうか
	bool isAttack;//攻撃中か
	Sprite* mySprite;//画像
	Vec2 moveDirection;//向かおうとしている方向
	Vec2 myPosition;//自身の位置
	Vector<Geometry*> attackGeometry;//決めたコンボをあらかじめ設定しておく
	//デバッグコマンド領域-----------
	
	Label* debugLabel;
	
	//-------------------------------------------

	static Character* create(PARAMETER p);
	bool init(PARAMETER p);
	void update(float delta);

	//移動
	void move(float speed);
	//通常攻撃
	void attack(AttackAction* action);
	//瞬間移動
	void shift(float degree);
	//必殺技
	void skill(void* skill);

	//セッター
	void setSprite(char* spname);
	//状態変化
	void setState(STATE state);
	//行動変化
	void setAction(ACTION action);
	//スピード変化
	void addSpeed(float speed);

	//時間を初期化
	void resetTimer();

	//次の攻撃方法を探す
	AttackAction* nextAction();
	//攻撃ボタン
	void pushAction(ACTION action);
	//コンボ継続
	void addCombo();

	float getSpeed();
};

#endif // !__CHARACTER_H__
