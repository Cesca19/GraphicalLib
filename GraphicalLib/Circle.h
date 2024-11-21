#pragma once
#include "Struct.h"

class Circle {
public:
    Circle(Vector2f position, float radius, Colors color);
    ~Circle();
    void SetPosition(Vector2f position);
    void SetRadius(float radius);
    void SetColor(Colors color);
    float GetRadius();
    Vector2f GetPosition();
    virtual void Draw() = 0;

protected:
    Vector2f _position;
    float _radius;
    Colors _color;
};
