#include "WindowRaylib.h"

WindowRaylib::WindowRaylib()
{
	_colorsMap[T_GRAY] = GRAY;
	_colorsMap[T_YELLOW] = YELLOW;
	_colorsMap[T_ORANGE] = ORANGE;
	_colorsMap[T_PINK] = PINK;
	_colorsMap[T_RED] = RED;
	_colorsMap[T_GREEN] = GREEN;
	_colorsMap[T_BLUE] = BLUE;
	_colorsMap[T_PURPLE] = PURPLE;
	_colorsMap[T_BEIGE] = BEIGE;
	_colorsMap[T_BROWN] = BROWN;
	_colorsMap[T_WHITE] = WHITE;
	_colorsMap[T_BLACK] = BLACK;
}

void WindowRaylib::Init()
{
}

void WindowRaylib::CreateWindow(int width, int height, std::string title)
{
	InitWindow(width, height, title.c_str());
}

bool WindowRaylib::IsWindowOpen()
{
	return WindowShouldClose();
}

void WindowRaylib::Close()
{
	CloseWindow();
}

void WindowRaylib::StartDrawing()
{
	BeginDrawing();
}

void WindowRaylib::StopDrawing()
{
	EndDrawing();
}

void WindowRaylib::Clear(Colors color)
{
	ClearBackground(_colorsMap[color]);
}
