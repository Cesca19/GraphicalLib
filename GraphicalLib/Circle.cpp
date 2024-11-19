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

void Circle::SetRadius(float radius)
{
    _radius = radius;
}


/*
Circle::Circle(Sprite* sprite, float speed)
    : sprite(sprite), speed(speed)
{
    float angle = (rand() % 360) * 3.14159f / 180.0f;
    velocity = Vector2f(cos(angle) * speed, sin(angle) * speed);
}

void Circle::Update(int windowWidth, int windowHeight) {
    Vector2f position = sprite->GetPosition();
    position += velocity;

    if (position.x < 0 || position.x > windowWidth - sprite->GetSpriteSize()) {
        velocity.x = -velocity.x;
        position.x = std::max(0.0f, std::min(float(windowWidth - sprite->GetSpriteSize()), position.x));
    }
    if (position.y < 0 || position.y > windowHeight - sprite->GetSpriteSize()) {
        velocity.y = -velocity.y;
        position.y = std::max(0.0f, std::min(float(windowHeight - sprite->GetSpriteSize()), position.y));
    }

    sprite->SetPosition(position);
}

Circle::Circle(Vector2f position, float radius, Colors color)
{
}*/