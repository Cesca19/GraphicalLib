#pragma once
#include "Sprite.h"

class SpriteSDL : public Sprite {
public:
    SpriteSDL(SDL_Renderer* renderer);
    virtual ~SpriteSDL();
    void LoadImage(const char* filePath) override;
    void Draw() override;
    void* GetData() override;

private:
    SDL_Surface* mSurface = nullptr;
    SDL_Texture* mTexture = nullptr;
    SDL_Renderer* mRenderer = nullptr;
};