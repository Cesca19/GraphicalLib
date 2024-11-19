#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite {
public:
    virtual ~SpriteSDL();
    void LoadImage(const char* filePath) override;
    void* GetData() override;

    int GetWidth() const { return mSurface ? mSurface->w : 0; }
    int GetHeight() const { return mSurface ? mSurface->h : 0; }

    SDL_Texture* GetTexture() const { return mTexture; }
    void SetTexture(SDL_Texture* texture) { mTexture = texture; }

private:
    SDL_Surface* mSurface = nullptr;
    SDL_Texture* mTexture = nullptr;
};