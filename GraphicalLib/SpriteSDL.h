#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite {
public:
    virtual ~SpriteSDL();
    void LoadImage(const char* filePath) override;
    void* GetData() override;
    void Render(SDL_Renderer* renderer) override;
    void CreateTexture(SDL_Renderer* renderer);

    int GetWidth() const { return mSurface ? mSurface->w : 0; }
    int GetHeight() const { return mSurface ? mSurface->h : 0; }

private:
    SDL_Surface* mSurface = nullptr;
    SDL_Texture* mTexture = nullptr;
    const char* mFilePath;
};