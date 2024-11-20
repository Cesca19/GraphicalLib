#include "Map.h"

Map::Map(Window* window, int rows, int cols) : mWindow(window), mRows(rows), mCols(cols)  {
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

    for (int row = 0; row < mRows; row++) {
        for (int col = 0; col < mCols; col++) {
            Vector2f position(
                startX + (col * (brickWidth + gapX)),  
                startY + (row * (brickHeight + gapY)) 
            );

            const char* spritePath = brickSprites[row % 4];

            Sprite* sprite = mWindow->CreateSprite(spritePath, position);
            sprite->SetScale(4);
            mSprites.push_back(sprite);
        }
    }
}

void Map::Draw() {
    for (auto sprite : mSprites) {
        sprite->Draw();
    }
}