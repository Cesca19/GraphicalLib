#include "AppBrickBreaker.h"

AppBrickBreaker::AppBrickBreaker(DisplayMode displayMode) : _displayMode(displayMode), _playerSpeed(5)
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

	float randX = 0, randY = 0, radius = 0, speed = 2;
	InitMap();

	Vector2f ballPos(_width / 2, _height - 150);
	_ball = _window->CreateCircle(ballPos, 15.0f, T_RED);
	_movingBall = new CircleAnimated(_ball, 15, _width, _height);

	_player = _window->CreateSprite("../Ressources/bar.png", barPosition);
	_player->SetScale(4.0f);
	_ballCircle = _window->CreateCircle({ (float)witdh / 2, (float)heigth / 2 }, 30.0f, T_BEIGE);
	_ball = new Ball(_ballCircle, _player, 3, _width, _height);
}

void AppBrickBreaker::UpdatePlayer(Key_t keyPressed)
{
	Vector2f pos = _player->GetPosition();
	pos.x += (keyPressed == Key_RIGHT) ? _playerSpeed : (keyPressed == Key_LEFT) ? (-_playerSpeed) : 0;
	pos.x = (pos.x < 0) ? 0 : 
		(_player->GetWidth() * _player->GetScale() + pos.x) >= _width ? _width - (_player->GetWidth() * _player->GetScale()) :
		pos.x;
	_player->SetPosition(pos);
}

void AppBrickBreaker::Run()
{
	Key_t key = Key_NONE;

	while (!_window->ShouldClose()) {
		_window->StartDrawing();

		_window->PollEvents(key);
		_window->Clear(T_WHITE);
		_window->DrawFps();

		UpdatePlayer(key);
		_map->Draw();
		_player->Draw();
		_ball->Update();
		_ball->Draw();

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