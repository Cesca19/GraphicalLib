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
	mWidth = _texture->width;
	mHeight = _texture->height;
}

void SpriteRaylib::Draw()
{
	Rectangle source = { 0.0f, 0.0f, (float)_texture->width, (float)_texture->height };
	Rectangle dest = { mPosition.x, mPosition.y, _texture->width * mScale, _texture->height * mScale };
	DrawTexturePro(*_texture, source, dest, Vector2{ 0, 0 }, 0.0f, WHITE);
}

void* SpriteRaylib::GetData()
{
	return nullptr;
}
