#pragma once
#include "Window.h"
extern "C" {
#include <raylib.h>
}


class WindowRaylib : public Window 
{
public:
	WindowRaylib();
	void Init() override;
	void CreateWindow(int width, int height, std::string title) override;
	void Close() override;
	void StartDrawing() override;
	void ShowDrawing() override;
	void Clear(Colors color)override;

	Sprite* CreateSprite(const char* filePath, const Vector2f& position) override;
	void RenderSprite(Sprite* sprite) override;
	bool ShouldClose() override;
	void PollEvents() override;
	void WaitFrame() override;
	void SetTargetFps(int fps) override;
private:
	std::unordered_map<Colors, Color>  _colorsMap;
};

