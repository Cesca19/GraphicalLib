#include "CircleSdl.h"

CircleSdl::CircleSdl(Vector2f position, float radius, Colors color, SDL_Renderer* renderer) : Circle(position, radius, color) {
    _renderer = renderer;
    InitColorsMap();
}

void CircleSdl::Draw() {
    if (!_renderer) return;

    SDL_Color color = _colorsMap[_color];
    filledCircleRGBA(_renderer,
        static_cast<Sint16>(_position.x),
        static_cast<Sint16>(_position.y),
        static_cast<Sint16>(_radius),
        color.r, color.g, color.b, color.a);
}

void CircleSdl::InitColorsMap() {
    _colorsMap[T_GRAY] = { 128, 128, 128, 255 };
    _colorsMap[T_YELLOW] = { 255, 255, 0, 255 };
    _colorsMap[T_ORANGE] = { 255, 165, 0, 255 };
    _colorsMap[T_PINK] = { 255, 192, 203, 255 };
    _colorsMap[T_RED] = { 255, 0, 0, 255 };
    _colorsMap[T_GREEN] = { 0, 255, 0, 255 };
    _colorsMap[T_BLUE] = { 0, 0, 255, 255 };
    _colorsMap[T_PURPLE] = { 128, 0, 128, 255 };
    _colorsMap[T_BEIGE] = { 245, 245, 220, 255 };
    _colorsMap[T_BROWN] = { 165, 42, 42, 255 };
    _colorsMap[T_WHITE] = { 255, 255, 255, 255 };
    _colorsMap[T_BLACK] = { 0, 0, 0, 255 };
}
