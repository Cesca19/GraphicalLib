#include "Circle.h"

#include "SpriteSDL.h"

Circle::Circle(Window* window, float startX, float startY) {
    sprite = new SpriteSDL();
    sprite->LoadImage("test-sprite.png");
    x = startX;
    y = startY;
        
    // Random direction
    float angle = (rand() % 360) * 3.14159f / 180.0f;
    dx = cos(angle) * speed;
    dy = sin(angle) * speed;
}

void Circle::Update(int windowWidth, int windowHeight) {
    x += dx;
    y += dy;

    // Bounce off walls
    if (x < 0 || x > windowWidth - sprite->GetX()) {
        dx = -dx;
        x = std::max(0.0f, std::min(float(windowWidth - sprite->GetX()), x));
    }
    if (y < 0 || y > windowHeight - sprite->GetY()) {
        dy = -dy;
        y = std::max(0.0f, std::min(float(windowHeight - sprite->GetY()), y));
    }

    sprite->SetPosition(x, y);
}
