#pragma once
#include "headers.h"

class Sprite {

public:
    virtual ~Sprite() = default;
    virtual void LoadImage(const char* filePath) = 0;
    virtual void* GetData() = 0;
    virtual void Update(int windowWidth, int windowHeight);
    virtual void Render(SDL_Renderer* renderer) = 0;

    void SetPosition(float newX, float newY);
    void SetVelocity(float newDx, float newDy);
    float GetX() const { return mX; }
    float GetY() const { return mY; }

protected:
    float mX, mY;
    float mDx, mDy;
};

