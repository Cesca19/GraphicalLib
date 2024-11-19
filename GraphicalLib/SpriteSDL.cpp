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

