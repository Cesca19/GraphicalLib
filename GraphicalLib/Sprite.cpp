#include "Sprite.h"

void Sprite::SetPosition(float newX, float newY) {
    mX = newX;
    mY = newY;
}

void Sprite::SetVelocity(float newDx, float newDy) {
    mDx = newDx;
    mDy = newDy;
}

void Sprite::Update(int windowWidth, int windowHeight) {
    mX += mDx;
    mY += mDy;

    if (mX < 0 || mX > windowWidth) mDx *= -1;
    if (mY < 0 || mY > windowHeight) mDy *= -1;
}