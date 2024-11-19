#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <iostream>
#include <vector>

struct Vector2f {
    float x;
    float y;

    Vector2f(float x_ = 0, float y_ = 0) : x(x_), y(y_) {}

    Vector2f operator+=(const Vector2f& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f operator*(float scalar) const {
        return Vector2f(x * scalar, y * scalar);
    }
};