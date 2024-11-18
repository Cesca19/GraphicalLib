#pragma once
#include "string"

class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow() = 0;
	virtual bool IsWindowOpen() = 0;
	virtual void LoadSprite() = 0;

protected:
	const char* mTitle;
	int mWidth;
	int mHeight;

};

