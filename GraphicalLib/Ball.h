#pragma once

#include "Sprite.h"
#include "Struct.h"
#include "Circle.h"

class Ball
{
public:
	Ball(Circle* circle, Sprite* player, int speed, int windowWidth, int windowHeight);
	void Update();
	void Draw();
	void CheckCollision(Sprite* target);
private:
	Vector2f _velocity;
	Circle* _circle;
	Sprite* _player;
	float _speed;
	int _windowWidth;
	int _windowHeight;
};

