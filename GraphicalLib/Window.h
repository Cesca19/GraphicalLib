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

class Window {

public:
	virtual void Init() = 0;
	virtual void CreateWindow(int width, int height, std::string title) = 0;
	virtual bool IsWindowOpen() = 0;
	virtual void Close() = 0;
	virtual void StartDrawing() = 0;
	virtual void StopDrawing() = 0;
	virtual void Clear(Colors color) = 0;
	//SetTargetFPS(60);
};

