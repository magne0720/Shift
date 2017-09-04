#ifndef __ACTION_MANAGER_H__
#define __ACTION_NAMAGER_H__

#include "cocos2d.h"
#include "Geometry.h"

using namespace cocos2d;
using namespace std;

//ACTION_STACKについて
//攻撃単発の仕様
//	１．攻撃をし始めてから攻撃判定のある図形を出すまでの時間
//	２．その図形が最大の状態を維持する時間
//	３．その図形が出ている間に移動する距離
//	４．その図形が消える時間(実質攻撃時間と同義)
//	５．コンボ許容時間(２終了時から計測)
//	６．次のコンボ先へ
class AttackAction:public Node {
public:
	Geometry* obj;
	char* name;//この攻撃の名前
	float radius;//攻撃範囲の半径
	float delay;//攻撃判定が出るまでの待ち時間
	float keep;//攻撃判定が出ている持続時間
	float standby;//コンボ許容時間(基本的delay終了時)
	float powerrate;//攻撃倍率
	Vec2 move;//この攻撃中にする移動量
	Vec2 distance;//攻撃範囲が移動する量(出ている持続時間で線形補間)
	///<summary>
	///ACTION_STACKの設定
	///type=攻撃範囲の形(0:circle,1:line,def:none)
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
