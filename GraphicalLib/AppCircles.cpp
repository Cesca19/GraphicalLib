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
	float randX = 0, randY = 0, radius = 0;
	for (int i = 0, color = 0; i < circlesNb; i++) {
		randX = rand() % (_window->GetWidth());
		randY = rand() % (_window->GetHeight());
		radius = rand() % 100;
		color = rand() % 12;
		_circles.push_back(_window->CreateCircle(Vector2f(randX, randY), radius, (Colors)color));
	}
}

void AppCircles::Run()
{
	Sprite* sprite = _window->CreateSprite("../Ressources/apple.png", (500, 300));

	while (!_window->ShouldClose()) {
		_window->StartDrawing();

		_window->PollEvents();
		_window->Clear(T_BEIGE);
		_window->DrawFps();

		for (auto circle : _circles)
			circle->Draw();
		sprite->Draw();


		_window->ShowDrawing();
		_window->WaitFrame();
	}
	_window->Close();
}


