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
		_isDestroyed = true;
	}
	else
		OnStateChange();
	
}

void Brick::OnStateChange()
{
	_sprite->SetFilePath(_strdup(_stateSprite[_currentState].c_str()));
}

void Brick::Update(Circle* ball, CircleAnimated* ballAnimation)
{
    if (_isDestroyed) return;

    Vector2f ballPos = ball->GetPosition();
    float ballRadius = ball->GetRadius();
    Vector2f brickPos = _sprite->GetPosition();
    float brickWidth = _sprite->GetWidth() * _sprite->GetScale();
    float brickHeight = _sprite->GetHeight() * _sprite->GetScale();

    if (ballPos.x + ballRadius >= brickPos.x &&
        ballPos.x - ballRadius <= brickPos.x + brickWidth &&
        ballPos.y + ballRadius >= brickPos.y &&
        ballPos.y - ballRadius <= brickPos.y + brickHeight) {

        if (ballPos.x < brickPos.x) {
            ball->SetPosition({ brickPos.x - ballRadius, ballPos.y });
        }
        else if (ballPos.x > brickPos.x + brickWidth) {
            ball->SetPosition({ brickPos.x + brickWidth + ballRadius, ballPos.y });
        }
        if (ballPos.y < brickPos.y) {
            ball->SetPosition({ ballPos.x, brickPos.y - ballRadius });
        }
        else if (ballPos.y > brickPos.y + brickHeight) {
            ball->SetPosition({ ballPos.x, brickPos.y + brickHeight + ballRadius });
        }

        OnHit();
        ballAnimation->ChangeDirection();
    }
}
