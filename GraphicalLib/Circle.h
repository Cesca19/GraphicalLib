#pragma once
#include "Sprite.h"
#include "Window.h"

class Circle {
public:
    Circle(Window* window, float startX, float startY);
    void Update(int windowWidth, int windowHeight);
    
public:
    float x, y;           // Position
    float dx, dy;         // Direction
    float speed = 5.0f;   // Movement speed
    Sprite* sprite;
};

