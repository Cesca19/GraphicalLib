#include "SpriteSDL.h"

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
}

void* SpriteSDL::GetData() {
    return mSurface;
}

void SpriteSDL::Render(SDL_Renderer* renderer) {
    if (!mTexture) {
        SDL_Surface* tempSurface = IMG_Load(mFilePath);
        mTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
    }

    SDL_Rect destRect = {
        static_cast<int>(mX), 
        static_cast<int>(mY),
        64,  // Width you want
        64   // Height you want
    };
    
    SDL_RenderCopy(renderer, mTexture, NULL, &destRect);
    SDL_RenderPresent(renderer);
}

void SpriteSDL::CreateTexture(SDL_Renderer* renderer) {
    if (mSurface && !mTexture) {
        mTexture = SDL_CreateTextureFromSurface(renderer, mSurface);
        SDL_FreeSurface(mSurface);
        mSurface = nullptr;
    }
}