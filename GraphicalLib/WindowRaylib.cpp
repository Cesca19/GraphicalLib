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

	_keyMap[KEY_NULL] = Key_NONE;
	_keyMap[KEY_A] = Key_A;
	_keyMap[KEY_B] = Key_B;
	_keyMap[KEY_C] = Key_C;
	_keyMap[KEY_D] = Key_D;
	_keyMap[KEY_E] = Key_E;
	_keyMap[KEY_F] = Key_F;
	_keyMap[KEY_G] = Key_G;
	_keyMap[KEY_H] = Key_H;
	_keyMap[KEY_I] = Key_I;
	_keyMap[KEY_J] = Key_J;
	_keyMap[KEY_K] = Key_K;
	_keyMap[KEY_L] = Key_L;
	_keyMap[KEY_M] = Key_M;
	_keyMap[KEY_N] = Key_N;
	_keyMap[KEY_O] = Key_O;
	_keyMap[KEY_P] = Key_P;
	_keyMap[KEY_Q] = Key_Q;
	_keyMap[KEY_R] = Key_R;
	_keyMap[KEY_S] = Key_S;
	_keyMap[KEY_T] = Key_T;
	_keyMap[KEY_U] = Key_U;
	_keyMap[KEY_V] = Key_V;
	_keyMap[KEY_W] = Key_W;
	_keyMap[KEY_X] = Key_X;
	_keyMap[KEY_Y] = Key_Y;
	_keyMap[KEY_Z] = Key_Z;
	_keyMap[KEY_LEFT] = Key_LEFT;
	_keyMap[KEY_RIGHT] = Key_RIGHT;
	_keyMap[KEY_BACK] = Key_BACK;
	_keyMap[KEY_ENTER] = Key_ENTER;
	_keyMap[KEY_SPACE] = Key_SPACE;
	//_keyMap[KEY_ESCAPE] = Key_ESC;
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
	Sprite* sprite = new SpriteRaylib();
	sprite->LoadImage(filePath);
	sprite->SetPosition(position);
	return sprite;
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

void WindowRaylib::DrawFps()
{
	DrawFPS(10, 10);
}

float WindowRaylib::GetFps()
{
	return GetFps();
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

Event_t WindowRaylib::GetEvent(Key_t& key)
{
	key = Key_NONE;
	for (const auto& keys : _keyMap) {
		if (IsKeyDown(keys.first)) {
			key = keys.second;
			return Key_DOWN;
		} else if (IsKeyReleased(keys.first)) {
			key = keys.second;
			return Key_DOWN;
		}
	}
	if (IsKeyDown(KEY_ESCAPE)) {
		key = Key_ESC;
		return CLOSE;
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
		return MOUSE_LEFT_CLICK;
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		return MOUSE_RIGHT_CLIK;
	return NONE;
}
