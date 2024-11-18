#include "WindowSDL.h"

#include <iostream>
#include <ostream>


WindowSDL::WindowSDL(const char* title, int width, int height) {
	mTitle = title;
	mWidth = width;
	mHeight = height;
}

void WindowSDL::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
	}
}

void WindowSDL::CreateWindow() {
	mWindow = SDL_CreateWindow(mTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		mWidth, mHeight, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
}

bool WindowSDL::IsWindowOpen() {
	if (!mWindow) {
		return false;
	}
	return true;
}

void WindowSDL::RenderSprite(Sprite* sprite) {
	SpriteSDL* sdlSprite = static_cast<SpriteSDL*>(sprite);
	sdlSprite->Render(mRenderer);
}

void WindowSDL::Clear() {
	SDL_RenderClear(mRenderer);
}

void WindowSDL::Present() {
	SDL_RenderPresent(mRenderer);
}