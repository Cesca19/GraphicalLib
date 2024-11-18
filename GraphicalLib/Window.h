#pragma once
#include "Sprite.h"
#include "string"

class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow() = 0;
	virtual bool IsWindowOpen() = 0;
	virtual Sprite CreateSprite() = 0;

protected:
	const char* mTitle;
	int mWidth;
	int mHeight;

};

