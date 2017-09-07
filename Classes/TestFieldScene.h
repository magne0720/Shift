#ifndef __TEST_FIELD_SCENE_H__
#define __TEST_FIELD_SCENE_H__

#include "cocos2d.h"
#include "DebugLogOutPut.h"

using namespace cocos2d;

#define LAYER_UI 5
#define LAYER_CHARACTER 4
#define LAYER_PARTICLE 3
#define LAYER_BACKGROUND 2
#define LAYER_HIDEITEM 1

class TestFieldScene :public Scene {
public:
	static TestFieldScene* createScene();
	bool init();

};


#endif // !__TEST_FIELD_H__
