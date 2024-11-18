#pragma once
#include "Window.h"
#include "SpriteSDL.h"

class WindowSDL : public Window {
public:
	WindowSDL(const char* title, int width, int height);
	void Init() override;
	void CreateWindow() override;
	bool IsWindowOpen() override;

	void RenderSprite(Sprite* sprite) override;

	void Clear() override;
	void Present() override;


private:
	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Texture* mTexture = nullptr;


	
};

