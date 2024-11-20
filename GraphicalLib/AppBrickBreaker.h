#pragma once

#include "Struct.h"
#include "CircleAnimated.h"
#include "WindowSDL.h"
#include "WindowRaylib.h"
#include "Map.h"
#include "Ball.h"

class AppBrickBreaker
{
public:
	AppBrickBreaker(DisplayMode displayMode);
	~AppBrickBreaker();
	void Init(int witdh, int heigth, std::string title);
	void UpdatePlayer(Key_t keyPressed);
	void Run();
	void InitMap();
	void CheckCollisions();

private:
	DisplayMode _displayMode;
	std::shared_ptr<Window> _window;
	int _playerSpeed;
	int _width;
	int _height;
	std::string _title;
	std::unique_ptr<Map> _map;

	Circle* _ball = nullptr;
	CircleAnimated* _movingBall = nullptr;
  
	Sprite* _player = nullptr;
};

