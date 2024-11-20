#pragma once
#include "Circle.h"
#include "headers.h"

class CircleSdl :  public Circle
{
public:
	CircleSdl(Vector2f position, float radius, Colors color, SDL_Renderer* renderer);
	void Draw() override;

	void InitColorsMap();

private:
	std::unordered_map<Colors, SDL_Color> _colorsMap;
	SDL_Renderer* _renderer;
};

