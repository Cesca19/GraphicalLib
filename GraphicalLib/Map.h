#pragma once
#include "Window.h"

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

};