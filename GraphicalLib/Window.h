#pragma once
#include "Circle.h"
#include "Sprite.h"
#include "Struct.h"

class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow(int width, int height, std::string title) = 0;
	virtual void Close() = 0;
	virtual void StartDrawing() = 0;
	virtual void ShowDrawing() = 0;
	virtual void Clear(Colors color) = 0;

	virtual bool ShouldClose() = 0;
	virtual Event_t PollEvents(Key_t& key) = 0;
	virtual void WaitFrame() = 0;
	virtual void SetTargetFps(int fps) = 0;
	virtual void DrawFps() = 0;
	virtual float GetFps() = 0;

	virtual Sprite* CreateSprite(const char* filePath, const Vector2f& position) = 0;
	virtual Circle* CreateCircle(Vector2f position, float radius, Colors color) = 0;

	int GetWidth() const { return mWidth; }
	int GetHeight() const { return mHeight; }

protected:
	const char* mTitle;
	int mWidth;
	int mHeight;
	float mCurrentFPS = 0;
};

