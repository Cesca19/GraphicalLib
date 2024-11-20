#include "AppCircles.h"

AppCircles::AppCircles(DisplayMode displayMode)
{
	if (displayMode == RAYLIB)
		_window = std::make_shared<WindowRaylib>();
	else
		_window = std::make_shared<WindowSDL>();
}

AppCircles::~AppCircles()
{
	for (auto circle : _circles)
		delete circle;
}

void AppCircles::Init(int witdh, int heigth, std::string title, int circlesNb)
{
	_width = witdh;
	_height = heigth;
	_title = title;
	_circlesNb = circlesNb;
	_window->Init();
	_window->CreateWindow(witdh, heigth, "Graphic Lib");
	_window->SetTargetFps(60);

	srand(time(0));
	float randX = 0, randY = 0, radius = 0, speed = 2;
	for (int i = 0, color = 0; i < circlesNb; i++) {
		randX = rand() % (_window->GetWidth());
		randY = rand() % (_window->GetHeight());
		radius = rand() % 100;
		color = rand() % 11;
		speed = 1.0f + (rand() % 5);
		Circle* tmp = _window->CreateCircle(Vector2f(randX, randY), radius, (Colors)color);
		_circles.push_back(tmp);
		_movingCircles.push_back(new CircleAnimated(tmp, speed, _width, _height));
	}
}

void AppCircles::Run()
{
	Key_t key = Key_NONE;

	while (!_window->ShouldClose()) {
		_window->StartDrawing();

		_window->PollEvents(key);
		_window->Clear(T_WHITE);
		_window->DrawFps();

		for (int i = 0; i < _circles.size(); i++) {
			if (key == Key_SPACE) {
				_movingCircles[i]->ChangeDirection();
				_circles[i]->SetColor((Colors)(rand() % 11));
			}
			_movingCircles[i]->Update();
			_circles[i]->Draw();
		}
		_window->ShowDrawing();
		_window->WaitFrame();
	}
	_window->Close();
}


