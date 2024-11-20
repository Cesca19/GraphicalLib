#include "CircleRaylib.h"

CircleRaylib::CircleRaylib(Vector2f position, float radius, Colors color) : Circle(position, radius, color)
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
	_colorsMap[T_MAGENTA] = MAGENTA;
}

void CircleRaylib::Draw()
{
	DrawCircle(_position.x, _position.y, _radius, _colorsMap[_color]);
}
