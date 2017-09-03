#ifndef __USER_INPUT_H__
#define __USER_INPUT_H__

#include "cocos2d.h"
#include "Character.h"
#include "StaticGameDefinition.h"
#include "InputButton.h"

using namespace cocos2d;

class UserInput :public Node 
{
public:
	Character* playerCharacter;
	struct USER_INPUT 
	{
		Vec2 dir;//ˆÚ“®
		bool attack;//UŒ‚ƒ{ƒ^ƒ“
		bool skill;//•KŽE‹Zƒ{ƒ^ƒ“
		USER_INPUT()
		{
			this->dir = Vec2(0, 0);
			this->attack = false;
			this->skill = false;
		}
	}userInput;
	//mode:0=user,!=com
	static UserInput* createPlayer(int mode=0);
	bool init(int mode);

	void changeMode(int mode);

	void menuCloseCallback(Ref* pSender);


};

#endif // !__USER_INPUT_H__
