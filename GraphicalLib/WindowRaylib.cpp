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
	mTitle = title.c_str();
	mWidth = width;
	mHeight = height;
	InitWindow(width, height, title.c_str());
}

Sprite* WindowRaylib::CreateSprite(const char* filePath, const Vector2f& position)
{
	return nullptr;
}

Circle* WindowRaylib::CreateCircle(Vector2f position, float radius, Colors color)
{
	return new CircleRaylib(position, radius, color);
}

void WindowRaylib::RenderSprite(Sprite* sprite)
{
}

bool WindowRaylib::ShouldClose()
{
	return WindowShouldClose();
}

void WindowRaylib::PollEvents()
{
}

void WindowRaylib::WaitFrame()
{
}

void WindowRaylib::SetTargetFps(int fps)
{
	SetTargetFPS(fps);
}

void WindowRaylib::Close()
{
	CloseWindow();
}

void WindowRaylib::StartDrawing()
{
	BeginDrawing();
}

void WindowRaylib::ShowDrawing()
{
	EndDrawing();
}

void WindowRaylib::Clear(Colors color)
{
	ClearBackground(_colorsMap[color]);
}
