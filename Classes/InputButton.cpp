#include "InputButton.h"

InputButton* InputButton::create(char* on_path, char* off_path)
{
	InputButton *pRet = new InputButton();
	if (pRet && pRet->init(on_path,off_path))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
};

bool InputButton::init(char* on_path, char* off_path)
{
	if (!Sprite::init())return false;

	onSp = Sprite::create(on_path);
	offSp = Sprite::create(off_path);

	initWithTexture(onSp->getTexture());

	return true;
};

