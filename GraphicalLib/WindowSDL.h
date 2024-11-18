#pragma once
#include "Window.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

class WindowSDL : public Window {
public:
	WindowSDL(const char* title, int width, int height);
	void Init() override;
	void CreateWindow() override;
	bool IsWindowOpen() override;

private:
	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;


};

