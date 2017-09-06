#ifndef __DEBUG_LOG_OUT_PUT_H__
#define __DEBUG_LOG_OUT_PUT_H__

#include "cocos2d.h"
#include "StaticGameDefinition.h"
#include "Character.h"
#include "Button.h"

using namespace cocos2d;

class DebugLogOutPut :public Node
{
public:
	Character* debugCharacter;
	Label* playerLabel;
	RenderTexture* tex;

	Vector<String*> logs;

	InputButton *speedUpButton, *speedDownButton, *debugButton;
	SwitchButton*logButton;

	static DebugLogOutPut* create();
	bool init();
	void update(float delta);

	void setStringPlayer(Character*& character);//ƒvƒŒƒCƒ„[‚Ìî•ñ‚ğ‰Â‹‰»‚µ‚½êŠ‚Éİ’è‚·‚é
	//void setStringAther();

};
#endif
