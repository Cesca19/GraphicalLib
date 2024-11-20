#include "AppBrickBreaker.h"

AppBrickBreaker::AppBrickBreaker(DisplayMode displayMode) : _displayMode(displayMode)
{
	if (displayMode == RAYLIB)
		_window = std::make_shared<WindowRaylib>();
	else
		_window = std::make_shared<WindowSDL>();
}

AppBrickBreaker::~AppBrickBreaker()
{
}

void AppBrickBreaker::Init(int witdh, int heigth, std::string title)
{
	_width = witdh;
	_height = heigth;
	_title = title;
	_window->Init();
	_window->CreateWindow(witdh, heigth, "Graphic Lib");
	_window->SetTargetFps(60);

	srand(time(0));
	float randX = 0, randY = 0, radius = 0, speed = 2;
	InitMap();

	Vector2f barPosition((_width - 64 * 4) / 2, _height - 100);
	_bar = _window->CreateSprite("../Ressources/bar.png", barPosition);
	_bar->SetScale(4.0f);

	Vector2f ballPos(_width / 2, _height - 150);
	_ball = _window->CreateCircle(ballPos, 15.0f, T_RED);
	_movingBall = new CircleAnimated(_ball, 15, _width, _height);
}

void AppBrickBreaker::Run()
{
	Key_t key = Key_NONE;

	while (!_window->ShouldClose()) {
		_window->StartDrawing();

		_window->PollEvents(key);
		_window->Clear(T_WHITE);
		_window->DrawFps();

		_map->Draw();
		_bar->Draw();

		CheckCollisions();
		_movingBall->Update();
		_ball->Draw();

		_window->ShowDrawing();
		_window->WaitFrame();
	}
	_window->Close();
}

void AppBrickBreaker::InitMap()
{
	_map = std::make_unique<Map>(_window.get(), 5, 8);
}

void AppBrickBreaker::CheckCollisions() {
	for (auto brick : _map->GetBricks()) {
		brick->Update(_ball, _movingBall);
	}
}