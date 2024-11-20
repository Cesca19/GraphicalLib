#pragma once
#include <raylib.h>
#include "Sprite.h"

class SpriteRaylib : public Sprite {
public:
	SpriteRaylib();
	~SpriteRaylib() override;
	void LoadImage(char* filePath) override;
	void Draw() override;
	void* GetData() override;
	void SetFilePath(char* filePath) override;
	int GetWidth() const override;
	int GetHeight() const override;

private:
	std::shared_ptr<Texture2D> _texture;
};

