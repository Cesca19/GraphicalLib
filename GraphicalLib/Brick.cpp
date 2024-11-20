#include "Brick.h"

Brick::Brick(Sprite* sprite, Brick_State currentState, std::unordered_map<Brick_State, std::string>& stateSprite) 
			: _sprite(sprite), _currentState(currentState), _stateSprite(stateSprite)
{
}

void Brick::Draw()
{
	_sprite->Draw();
}

void Brick::OnHit()
{
	if (_currentState != DESTROY_STATE)
		_currentState = (Brick_State)(_currentState - 1);
	if (_currentState == DESTROY_STATE) {
		//delete the object and notify the map
	}
	else
		OnStateChange();
	
}

void Brick::OnStateChange()
{
	_sprite->SetFilePath(_strdup(_stateSprite[_currentState].c_str()));
}

void Brick::Update()
{
	// check collision then call on hit
}
