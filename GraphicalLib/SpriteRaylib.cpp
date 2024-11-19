#include "SpriteRaylib.h"

SpriteRaylib::SpriteRaylib() : _texture(new Texture2D())
{
}

SpriteRaylib::~SpriteRaylib()
{
	UnloadTexture(*_texture);
}

void SpriteRaylib::LoadImage(const char* filePath)
{
	mFilePath = filePath;
	*_texture = LoadTexture(mFilePath);
}

void SpriteRaylib::Draw()
{
	DrawTexture(*_texture, mPosition.x, mPosition.y, WHITE);
}

void* SpriteRaylib::GetData()
{
	return nullptr;
}
