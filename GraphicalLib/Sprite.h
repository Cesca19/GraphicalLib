#pragma once
#include "headers.h"

class Sprite {
public:
    virtual ~Sprite() = default;
    virtual void LoadImage(const char* filePath) = 0;
    virtual void* GetData() = 0;

    void SetPosition(const Vector2& newPos) { mPosition = newPos; }
    void SetVelocity(const Vector2& newVel) { mVelocity = newVel; }

    float GetX() const { return mPosition.x; }
    float GetY() const { return mPosition.y; }
    const Vector2& GetPosition() const { return mPosition; }
    const Vector2& GetVelocity() const { return mVelocity; }
    const char* GetFilePath() const { return mFilePath; }

protected:
    Vector2 mPosition;
    Vector2 mVelocity;
    const char* mFilePath;
};
