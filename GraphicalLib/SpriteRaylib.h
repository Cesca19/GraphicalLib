#pragma once
#include <raylib.h>
#include "Sprite.h"

class SpriteRaylib : public Sprite {
public:
	SpriteRaylib();
	~SpriteRaylib() override;
	void LoadImage(const char* filePath) override;
	void Draw() override;
	void* GetData() override;

private:
	std::shared_ptr<Texture2D> _texture;
};

