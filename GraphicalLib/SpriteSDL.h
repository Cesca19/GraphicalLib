#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite {

public:
	void LoadImage(std::string filePath);
	void Render();

};

