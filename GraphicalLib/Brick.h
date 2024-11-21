#pragma once
#include "Sprite.h"
#include "Circle.h"
#include "CircleAnimated.h"

enum Brick_State {
	DESTROY_STATE,
	PINK_STATE,
	BLUE_STATE,
	ORANGE_STATE,
	GREEN_STATE,
};

class Brick
{
public:
	Brick(Sprite* sprite, Brick_State currentState, std::unordered_map<Brick_State, std::string> &stateSprite);
	void Draw();
	// à chaque fois que la brick est hit on décrémente son state actuel,
	// et on met à jour le sprite
	//quand le state atteint destroy la brique est détruite et supprimée de la map
	void OnHit();
	void OnStateChange();
	void Update(Circle* ball, CircleAnimated* ballAnimation);
	bool IsDestroyed() const { return _isDestroyed; }
	Sprite* GetSprite() const { return _sprite; }

private:
	Sprite* _sprite;
	Brick_State _currentState;
	std::unordered_map<Brick_State, std::string> _stateSprite;
	bool _isDestroyed = false;

};

