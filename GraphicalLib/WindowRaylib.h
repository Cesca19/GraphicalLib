#pragma once
#include "Window.h"
#include "SpriteRaylib.h"
#include "CircleRaylib.h"
#include <raylib.h>

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
	Event_t GetEvent(Key_t& key) override;

	Sprite* CreateSprite(const char* filePath, const Vector2f& position) override;
	Circle* CreateCircle(Vector2f position, float radius, Colors color) override;
	void RenderSprite(Sprite* sprite) override;
	bool ShouldClose() override;
	void PollEvents() override;
	void WaitFrame() override;
	void SetTargetFps(int fps) override;
	void DrawFps() override;
	float GetFps() override;
private:
	std::unordered_map<Colors, Color>  _colorsMap;
	std::unordered_map<KeyboardKey, Key_t>  _keyMap;
};

