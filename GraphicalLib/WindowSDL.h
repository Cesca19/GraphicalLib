#pragma once
#include "Window.h"
#include "SpriteSDL.h"

class WindowSDL : public Window {
public:
	WindowSDL();
	~WindowSDL();
	void Init() override;
	void CreateWindow(int width, int height, std::string title) override;
	Sprite* CreateSprite(const char* filePath, const Vector2f& position) override;
	void Clear(Colors color) override;
	void Close() override;
	void ShowDrawing() override;
	void StartDrawing()override;
	void RenderSprite(Sprite* sprite) override;
	bool ShouldClose() override;
	void PollEvents() override;
	void WaitFrame() override;
	void SetTargetFps(int fps) override;
	void DrawFPS() override;
	float GetFPS() const override { return mCurrentFPS; }

private:
	bool mShouldClose = false;
	int mTargetFrameTime;

	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	TTF_Font* mFont = nullptr;

	void UpdateFPS();
	
};

