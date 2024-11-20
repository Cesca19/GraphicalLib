#include "SpriteRaylib.h"

SpriteRaylib::SpriteRaylib() : _texture(new Texture2D())
{
}

SpriteRaylib::~SpriteRaylib()
{
	UnloadTexture(*_texture);
}

void SpriteRaylib::LoadImage(char* filePath)
{
	mFilePath = filePath;
	*_texture = LoadTexture(mFilePath);
	mWidth = _texture->width;
	mHeight = _texture->height;
}

void SpriteRaylib::Draw()
{
	DrawTextureEx(*_texture, { mPosition.x, mPosition.y }, 0.0f, mScale, WHITE);
}

void* SpriteRaylib::GetData()
{
	return nullptr;
}

void SpriteRaylib::SetFilePath(char* filePath)
{
	mFilePath = filePath;
	UnloadTexture(*_texture);
	*_texture = LoadTexture(mFilePath);
}

int SpriteRaylib::GetWidth() const
{
	return _texture->width;
}

int SpriteRaylib::GetHeight() const
{
	return _texture->height;
}
