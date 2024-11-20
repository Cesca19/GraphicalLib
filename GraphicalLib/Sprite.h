#pragma once
#include "headers.h"

class Sprite {
public:
    virtual ~Sprite() = default;
    virtual void LoadImage(const char* filePath) = 0;
    virtual void* GetData() = 0;
    virtual void Draw() = 0;

    void SetPosition(const Vector2f& newPos) { mPosition = newPos; }
    void SetVelocity(const Vector2f& newVel) { mVelocity = newVel; }
    void SetScale(float scale) { mScale = scale; }

    float GetX() const { return mPosition.x; }
    float GetY() const { return mPosition.y; }
    const Vector2f& GetPosition() const { return mPosition; }
    const Vector2f& GetVelocity() const { return mVelocity; }
    const char* GetFilePath() const { return mFilePath; }
    int GetWidth() const { return mWidth; }
    int GetHeight() const { return mHeight; }
    float GetScale() const { return mScale; }

protected:
    Vector2f mPosition;
    Vector2f mVelocity;
    const char* mFilePath;
    int mSpriteSize = 64;
    int mWidth = 0;
    int mHeight = 0;
    float mScale = 1.0f;
};
