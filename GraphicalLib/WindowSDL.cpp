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
	mWindow = SDL_CreateWindow(mTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mWidth, mHeight, SDL_WINDOW_SHOWN);
	if (!mWindow) {
		std::cout << "Error creating window: " << SDL_GetError() << std::endl;
		system("pause");
	}

	mWinSurface = SDL_GetWindowSurface(mWindow);
	if (!mWinSurface) {
		std::cout << "Error getting surface: " << SDL_GetError() << std::endl;
		system("pause");
	}

	SDL_FillRect(mWinSurface, NULL, SDL_MapRGB(mWinSurface->format, 0, 255, 255));
	// SDL_UpdateWindowSurface(mWindow);	
	// system("pause");
	// SDL_DestroyWindow(mWindow);
	// SDL_Quit();
}

bool WindowSDL::IsWindowOpen() {
	if (!mWindow) {
		return false;
	}
	return true;
}

void WindowSDL::LoadSprite() {
	SDL_Surface* imageTest = nullptr;
	SDL_Surface* imageSurface = nullptr;

	imageSurface = IMG_Load("test3.png");
	imageTest = SDL_ConvertSurface(imageSurface, mWinSurface->format, 0);
	if (!imageTest) {
		std::cout << "Error loading image: " << SDL_GetError() << std::endl;
	} else {
		SDL_FreeSurface(imageSurface);
		imageSurface = nullptr;
	}

	SDL_BlitScaled(imageTest, NULL, mWinSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);	
	system("pause");
}
