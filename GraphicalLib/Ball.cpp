#include "Ball.h"

Ball::Ball(Circle* circle, Sprite* player, int speed, int windowWidth, int windowHeight) : _circle(circle), _player(player),
_speed(speed), _windowWidth(windowWidth), _windowHeight(windowHeight)
{
    _velocity = { speed * cos(45.0f), speed * sin(45.0f) };
}

void Ball::Update()
{
    Vector2f pos = _circle->GetPosition();
    float radius = _circle->GetRadius();

    pos.x += _velocity.x;
    pos.y += _velocity.y;

    if (pos.x - radius <= 0) {
        pos.x = 0 + radius;
        _velocity.x = -_velocity.x;
    }
    else if (pos.x + radius > 0 + _windowWidth) {
        pos.x = 0 + _windowWidth - radius;
        _velocity.x = -_velocity.x;
    }

    if (pos.y - radius <= 0) {
        pos.y = 0 + radius;
        _velocity.y = -_velocity.y;
    }
    else if (pos.y + radius > _windowHeight) {
        pos.y = 0 + _windowHeight - radius;
        _velocity.y = -_velocity.y;
    }
    _circle->SetPosition(pos);

}

void Ball::Draw()
{
    _circle->Draw();
}

void Ball::CheckCollision(Sprite* target)
{

}
