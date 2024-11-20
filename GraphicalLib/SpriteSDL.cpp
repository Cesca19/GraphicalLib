#include "SpriteSDL.h"

SpriteSDL::SpriteSDL(SDL_Renderer* renderer) : mRenderer(renderer){
}

SpriteSDL::~SpriteSDL() {
    if (mTexture) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
    if (mSurface) {
        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }
}

void SpriteSDL::LoadImage(const char* filePath) {
    mFilePath = filePath;
    mSurface = IMG_Load(mFilePath);
    if (mSurface) {
        mTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);
        //SDL_FreeSurface(mSurface);
        //sprite->SetTexture(mTexture);
    }
}

void SpriteSDL::Draw() {
    if (mTexture) {
        SDL_Rect destRect = {
            static_cast<int>(mPosition.x),
            static_cast<int>(mPosition.y),
            GetSpriteSize(),
            GetSpriteSize()
        };
        SDL_RenderCopy(mRenderer, mTexture, NULL, &destRect);
    }
}

void* SpriteSDL::GetData() {
    return mTexture;
}

