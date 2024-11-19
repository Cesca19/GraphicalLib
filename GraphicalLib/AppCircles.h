#pragma once

#include "Struct.h"
#include "CircleAnimated.h"
#include "WindowSDL.h"
#include "WindowRaylib.h"

class AppCircles
{
public:
	AppCircles(DisplayMode displayMode);
	~AppCircles();
	void Init(int witdh, int heigth, std::string title, int circlesNb);
	void Run();
private:
	DisplayMode _displayMode;
	std::shared_ptr<Window> _window;
	int _width;
	int _height;
	std::string _title;
	int _circlesNb;
	std::vector<Circle*> _circles;
	std::vector<CircleAnimated*> _movingCircles;
};

