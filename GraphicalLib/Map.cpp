#include "Map.h"

Map::Map(Window* window, int rows, int cols) : mWindow(window), mRows(rows), mCols(cols)
{
    InitializeMap();
}

void Map::InitializeMap() {
    const int brickWidth = 128;  
    const int brickHeight = 64; 
    const int totalWidth = mCols * brickWidth;
    const int startX = (mWindow->GetWidth() - totalWidth) / 2;  
    const int startY = 50;  

    const int gapX = -4; 
    const int gapY = -4;

    const char* brickSprites[] = {
        "../Ressources/brick-1.png",
        "../Ressources/brick-2.png",
        "../Ressources/brick-3.png",
        "../Ressources/brick-4.png"
    };

    mStateSprite[PINK_STATE] = brickSprites[0];
    mStateSprite[GREEN_STATE] = brickSprites[1];
    mStateSprite[ORANGE_STATE] = brickSprites[2];
    mStateSprite[BLUE_STATE] = brickSprites[3];

    for (int row = 0; row < mRows; row++) {
        for (int col = 0; col < mCols; col++) {
            Vector2f position(
                startX + (col * (brickWidth + gapX)),  
                startY + (row * (brickHeight + gapY)) 
            );

            const char* spritePath = brickSprites[row % 4];

            Sprite* sprite = mWindow->CreateSprite(spritePath, position);
            sprite->SetScale(4);
            Brick* brick = new Brick(sprite, (Brick_State)((row % 4) + 1), mStateSprite);
            mSprites.push_back(sprite);
            mBrick.push_back(brick);
        }
    }
}

void Map::Draw() {
    auto it = mBrick.begin();
    while (it != mBrick.end()) {
        if ((*it)->IsDestroyed()) {
            delete* it;
            auto spriteIt = std::find(mSprites.begin(), mSprites.end(), (*it)->GetSprite());
            if (spriteIt != mSprites.end()) {
                delete* spriteIt;
                mSprites.erase(spriteIt);
            }
            it = mBrick.erase(it);
        }
        else {
            (*it)->Draw();
            ++it;
        }
    }
}