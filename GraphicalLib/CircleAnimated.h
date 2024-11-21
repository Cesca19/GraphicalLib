#pragma once
#include "Struct.h"
#include "Circle.h"

class CircleAnimated
{
public:
	CircleAnimated(Circle* circle, int speed, int windowWidth, int windowHeight);
	void Update();
	void ChangeDirection();

private:
	Vector2f _velocity;
	Circle* _circle;
	float _speed;
	int _windowWidth;
	int _windowHeight;
};

