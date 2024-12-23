#include "CircleAnimated.h"

CircleAnimated::CircleAnimated(Circle* circle, int speed, int windowWidth, int windowHeight) 
    : _circle(circle), _windowHeight(windowHeight), _windowWidth(windowWidth), _speed(speed)
{
    float angle = (float)(rand() % 360);
    _velocity = { speed * cos(angle), speed * sin(angle) };
}

void CircleAnimated::Update()
{
    Vector2f pos = _circle->GetPosition();
    float radius = _circle->GetRadius();
    
    pos.x += _velocity.x;
    pos.y += _velocity.y;

    if (pos.x - radius < 0) {
        pos.x = 0 + radius;
        _velocity.x = -_velocity.x;
    }
    else if (pos.x + radius > 0 + _windowWidth) {
        pos.x = 0 + _windowWidth - radius; 
        _velocity.x = -_velocity.x;
    }

    if (pos.y - radius < 0) {
        pos.y = 0 + radius;
        _velocity.y = -_velocity.y;
    }
    else if (pos.y + radius > 0 + _windowHeight) {
        pos.y = 0 + _windowHeight - radius;
        _velocity.y = -_velocity.y;
    }
    _circle->SetPosition(pos);
}

void CircleAnimated::ChangeDirection()
{
    float angle = (float)(rand() % 360);
    _velocity = { _speed * cos(angle), _speed * sin(angle) };
}
