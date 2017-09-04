#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
#include "AttackManager.h"
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
	PARAMETER* myParameter;

	STATE myState;
	ACTION myAction;
	AttackManager* attackManager;
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
	void attack(ATTACK_ACTION action);
	//瞬間移動
	void shift(float degree);
	//必殺技
	void skill(void* skill);

	//セッター
	void setSprite(char* spname);

	//時間を初期化
	void resetTimer();

	//攻撃ボタン
	void pushAction(ACTION action);
	//コンボ継続
	void addCombo();
};

#endif // !__CHARACTER_H__
