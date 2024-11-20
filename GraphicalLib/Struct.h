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

enum Event_t {
    NONE,
    CLOSE,
    MOUSE_LEFT_CLICK,
    MOUSE_RIGHT_CLIK,
	Key_DOWN,
	Key_UP,
};

enum Key_t {
	Key_NONE,
    Key_A,
    Key_B,
    Key_C,
    Key_D,
    Key_E,
    Key_F,
    Key_G,
    Key_H,
    Key_I,
    Key_J,
    Key_K,
    Key_L,
    Key_M,
    Key_N,
    Key_O,
    Key_P,
    Key_Q,
    Key_R,
    Key_S,
    Key_T,
    Key_U,
    Key_V,
    Key_W,
    Key_X,
    Key_Y,
    Key_Z,
    Key_LEFT,
    Key_RIGHT,
    Key_BACK,
    Key_ENTER,
    Key_ESC,
    Key_SPACE,
};