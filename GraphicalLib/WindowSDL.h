#pragma once
#include "Window.h"
#include "SpriteSDL.h"

class WindowSDL : public Window {
public:
	WindowSDL(const char* title, int width, int height);
	void Init() override;
	void CreateWindow() override;
	bool IsWindowOpen() override;
	Sprite* CreateSprite(const char* filePath, const Vector2& position) override;
	void Clear() override;
	void Present() override;
	void RenderSprite(Sprite* sprite) override;
	bool ShouldClose() override;
	void PollEvents() override;

private:
	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	SDL_Texture* mTexture = nullptr;
	bool mShouldClose = false;

	SDL_Texture* GetOrCreateTexture(SpriteSDL* sprite);
	
};

