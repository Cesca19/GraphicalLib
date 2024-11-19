#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

enum Colors {
	T_GRAY,
	T_YELLOW,
	T_ORANGE,
	T_PINK,
	T_RED,
	T_GREEN,
	T_BLUE,
	T_PURPLE,
	T_BEIGE,
	T_BROWN,
	T_WHITE,
	T_BLACK,
	T_MAGENTA,
};
#include "Sprite.h"
#include "headers.h"


class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow(int width, int height, std::string title) = 0;
	virtual void Close() = 0;
	virtual void StartDrawing() = 0;
	virtual void ShowDrawing() = 0;
	virtual void Clear(Colors color) = 0;
	virtual Sprite* CreateSprite(const char* filePath, const Vector2f& position) = 0;
	virtual void RenderSprite(Sprite* sprite) = 0;

	virtual bool ShouldClose() = 0;
	virtual void PollEvents() = 0;
	virtual void WaitFrame() = 0;
	virtual void SetTargetFps(int fps) = 0;
	virtual void DrawFPS() = 0;
	virtual float GetFPS() const = 0;

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

protected:
	const char* mTitle;
	int mWidth;
	int mHeight;
	float mCurrentFPS = 0;
	Uint32 mLastTime = 0;
	int mFrameCount = 0;

};

