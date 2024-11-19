#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

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

enum DisplayMode {
	RAYLIB,
	SDL,
};

enum Colors {
	T_GRAY,
	T_YELLOW,
	T_ORANGE,
	T_PINK,
	T_RED,
	T_GREEN,
	T_BLUE,
	T_PURPLE,
	T_BEIGE,
	T_BROWN,
	T_BLACK,
	T_MAGENTA,
	T_WHITE,
};