#include "Circle.h"
#include "SpriteSDL.h"

Circle::Circle(Sprite* sprite, float speed)
    : sprite(sprite), speed(speed)
{
    float angle = (rand() % 360) * 3.14159f / 180.0f;
    velocity = Vector2(cos(angle) * speed, sin(angle) * speed);
}

void Circle::Update(int windowWidth, int windowHeight) {
    Vector2 position = sprite->GetPosition();
    position += velocity;

    if (position.x < 0 || position.x > windowWidth - sprite->GetX()) {
        velocity.x = -velocity.x;
        position.x = std::max(0.0f, std::min(float(windowWidth - sprite->GetX()), position.x));
    }
    if (position.y < 0 || position.y > windowHeight - sprite->GetY()) {
        velocity.y = -velocity.y;
        position.y = std::max(0.0f, std::min(float(windowHeight - sprite->GetY()), position.y));
    }

    sprite->SetPosition(position);
}