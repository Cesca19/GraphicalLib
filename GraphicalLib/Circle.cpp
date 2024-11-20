#include "Circle.h"

Circle::Circle(Vector2f position, float radius, Colors color) : _position(position), _radius(radius), _color(color)
{
}

Circle::~Circle()
{
}

void Circle::SetPosition(Vector2f position)
{
    _position = position;
}

void Circle::SetColor(Colors color)
{
    _color = color;
}

float Circle::GetRadius()
{
    return _radius;
}

Vector2f Circle::GetPosition()
{
    return _position;
}

void Circle::SetRadius(float radius)
{
    _radius = radius;
}
