#pragma once
#include "Struct.h"

class Circle {
public:
    Circle(Vector2f position, float radius, Colors color);
    ~Circle();
    void SetPosition(Vector2f position);
    void SetRadius(float radius);
    void SetColor(Colors color);
    virtual void Draw() = 0;
protected:
    Vector2f _position;
    float _radius;
    Colors _color;
};

/*
class Circle {
public:
    Circle(Sprite* sprite, float speed = 5.0f);
    void Update(int windowWidth, int windowHeight);
    Sprite* GetSprite() const { return sprite; }

private:
    Sprite* sprite;
    Vector2f velocity;
    float speed;
};*/