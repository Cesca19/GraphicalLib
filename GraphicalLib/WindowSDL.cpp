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

Sprite* WindowSDL::CreateSprite(const char* filePath, const Vector2& position) {
	SpriteSDL* sprite = new SpriteSDL(mRenderer);
	sprite->LoadImage(filePath);
	sprite->SetPosition(position);
	return sprite;
}


void WindowSDL::Clear() {
	SDL_RenderClear(mRenderer);
}

void WindowSDL::Present() {
	SDL_RenderPresent(mRenderer);
}

void WindowSDL::RenderSprite(Sprite* sprite) {
	//auto sdlSprite = static_cast<SpriteSDL*>(sprite);
	SDL_Texture* texture = static_cast<SDL_Texture*>(sprite->GetData());

	if (texture) {
		SDL_Rect destRect = {
			static_cast<int>(sprite->GetX()),
			static_cast<int>(sprite->GetY()),
			sprite->GetSpriteSize(),
			sprite->GetSpriteSize()
		};

		SDL_RenderCopy(mRenderer, texture, NULL, &destRect);
	}
}

bool WindowSDL::ShouldClose() {
	return mShouldClose;
}

void WindowSDL::PollEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			mShouldClose = true;
	}
}

void WindowSDL::WaitFrame() {
	SDL_Delay(mTargetFrameTime);
}

void WindowSDL::SetTargetFps(int fps) {
	mTargetFrameTime = 1000 / fps;
}