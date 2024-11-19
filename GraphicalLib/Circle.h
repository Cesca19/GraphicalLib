#pragma once
#include "Sprite.h"
#include "Window.h"

class Circle {
public:
    Circle(Sprite* sprite, float speed = 5.0f);
    void Update(int windowWidth, int windowHeight);
    Sprite* GetSprite() const { return sprite; }

private:
    Sprite* sprite;
    Vector2f velocity;
    float speed;
};