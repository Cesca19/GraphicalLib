#pragma once
#include "Window.h"
#include "Brick.h"

class Map {
public:
    Map(Window* window, int rows, int cols);
    void Draw();
    void InitializeMap();

private:
    Window* mWindow;
    int mRows;
    int mCols;
    std::vector<Sprite*> mSprites;
    std::vector<Brick*> mBrick;
    std::unordered_map<Brick_State, std::string> mStateSprite;
};
