#pragma once
#include "Circle.h"

class CircleSdl :  public Circle
{
public:
	CircleSdl(Vector2f position, float radius, Colors color);
	void Draw() override;
};

