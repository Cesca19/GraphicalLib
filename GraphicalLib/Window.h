#pragma once
#include "Sprite.h"
#include "headers.h"


class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow() = 0;
	virtual bool IsWindowOpen() = 0;
	virtual Sprite* CreateSprite(const char* filePath, const Vector2& position) = 0;
	virtual void RenderSprite(Sprite* sprite) = 0;
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual bool ShouldClose() = 0;
	virtual void PollEvents() = 0;

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

protected:
	const char* mTitle;
	int mWidth;
	int mHeight;

};

