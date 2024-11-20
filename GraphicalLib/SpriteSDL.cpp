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
        mWidth = mSurface->w;
        mHeight = mSurface->h;
    }
}

void SpriteSDL::Draw() {
    if (mTexture) {
        SDL_Rect destRect = {
            static_cast<int>(mPosition.x),
            static_cast<int>(mPosition.y),
            static_cast<int>(mWidth * mScale),
            static_cast<int>(mHeight * mScale)
        };
        SDL_RenderCopy(mRenderer, mTexture, NULL, &destRect);
    }
}

void* SpriteSDL::GetData() {
    return mTexture;
}

