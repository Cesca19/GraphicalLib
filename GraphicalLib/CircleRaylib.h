#pragma once
#include "Circle.h"
#include <raylib.h>

class CircleRaylib :  public Circle
{
public:
	CircleRaylib(Vector2f position, float radius, Colors color);
	void Draw() override;
private:
	std::unordered_map<Colors, Color>  _colorsMap;
};

