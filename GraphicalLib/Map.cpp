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

    const int gapX = -2; 
    const int gapY = -2;

    const char* brickSprites[] = {
        "../Ressources/brick-1.png",
        "../Ressources/brick-2.png",
        "../Ressources/brick-3.png",
        "../Ressources/brick-4.png"
    };

    mStateSprite[PINK_STATE] = "../Ressources/brick-1.png";
    mStateSprite[GREEN_STATE] = "../Ressources/brick-2.png";
    mStateSprite[ORANGE_STATE] = "../Ressources/brick-3.png";
    mStateSprite[BLUE_STATE] = "../Ressources/brick-4.png";

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
    for (auto brick : mBrick) {
        brick->Update();
        brick->Draw();
    }
}