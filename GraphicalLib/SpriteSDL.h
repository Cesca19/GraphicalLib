#pragma once
#include "Headers.h"
#include "Sprite.h"

class SpriteSDL : public Sprite {
public:
    SpriteSDL(SDL_Renderer* renderer);
    virtual ~SpriteSDL();
    void LoadImage(char* filePath) override;
    void Draw() override;
    void* GetData() override;
    void SetFilePath(char* filePath) override;

private:
    SDL_Surface* mSurface = nullptr;
    SDL_Texture* mTexture = nullptr;
    SDL_Renderer* mRenderer = nullptr;
};