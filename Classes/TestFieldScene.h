#ifndef __TEST_FIELD_SCENE_H__
#define __TEST_FIELD_SCENE_H__

#include "cocos2d.h"
#include "DebugLogOutPut.h"

using namespace cocos2d;

class TestFieldScene :public Scene {
public:
	static TestFieldScene* createScene();
	bool init();

};


#endif // !__TEST_FIELD_H__
