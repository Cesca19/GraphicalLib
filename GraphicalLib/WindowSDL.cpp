#include "WindowSDL.h"

#include <iostream>
#include <ostream>


WindowSDL::WindowSDL() 
{
}
WindowSDL::~WindowSDL() {
	if (mFont) {
		TTF_CloseFont(mFont);
	}
	TTF_Quit();
}

void WindowSDL::Init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
		system("pause");
	}

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	mFont = TTF_OpenFont("font/GeistMono-Bold.ttf", 24); 
	if (!mFont) {
		std::cout << "Error loading font: " << TTF_GetError() << std::endl;
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

void WindowSDL::UpdateFPS() {
	mFrameCount++;
	Uint32 currentTime = SDL_GetTicks();

	if (currentTime - mLastTime >= 1000) {
		mCurrentFPS = mFrameCount / ((currentTime - mLastTime) / 1000.0f);
		mFrameCount = 0;
		mLastTime = currentTime;
	}
}

void WindowSDL::DrawFPS() {
	UpdateFPS();

	SDL_Color textColor = { 0, 0, 0, 255 }; // Black color
	char fpsText[16];
	sprintf_s(fpsText, sizeof(fpsText), "FPS: %.1f", mCurrentFPS);

	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, fpsText, textColor);
	if (textSurface) {
		SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if (texture) {
			SDL_Rect destRect = { 10, 10, textSurface->w, textSurface->h };
			SDL_RenderCopy(mRenderer, texture, NULL, &destRect);
			SDL_DestroyTexture(texture);
		}
		SDL_FreeSurface(textSurface);
	}
}