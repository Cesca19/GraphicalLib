#include "WindowSDL.h"

#include <iostream>
#include <ostream>


WindowSDL::WindowSDL() 
{
}

void WindowSDL::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
	}
}

void WindowSDL::CreateWindow(int width, int height, std::string title) {
	mTitle = title.c_str();
	mWidth = width;
	mHeight = height;
	mWindow = SDL_CreateWindow(mTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		mWidth, mHeight, SDL_WINDOW_SHOWN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
}

Sprite* WindowSDL::CreateSprite(const char* filePath, const Vector2f& position) {
	SpriteSDL* sprite = new SpriteSDL(mRenderer);
	sprite->LoadImage(filePath);
	sprite->SetPosition(position);
	return sprite;
}

Circle* WindowSDL::CreateCircle(Vector2f position, float radius, Colors color)
{
	return nullptr;
}


void WindowSDL::Clear(Colors color) {
	SDL_RenderClear(mRenderer);
}

void WindowSDL::Close()
{
}

void WindowSDL::ShowDrawing() {
	SDL_RenderPresent(mRenderer);
}

void WindowSDL::StartDrawing()
{
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