#pragma once
#include "Window.h"
#include "raylib.h"


class WindowRaylib : public Window 
{
public:
	WindowRaylib();
	void Init() override;
	void CreateWindow(int width, int height, std::string title) override;
	bool IsWindowOpen() override;
	void Close() override;
	void StartDrawing() override;
	void StopDrawing() override;
	void Clear(Colors color)override;
private:
	std::unordered_map<Colors, Color>  _colorsMap;
};

