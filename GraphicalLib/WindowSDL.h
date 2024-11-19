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
	Circle* CreateCircle(Vector2f position, float radius, Colors color) override;
	void Clear(Colors color) override;
	void Close() override;
	void ShowDrawing() override;
	void StartDrawing()override;
	void RenderSprite(Sprite* sprite) override;
	bool ShouldClose() override;
	void PollEvents() override;
	void WaitFrame() override;
	void SetTargetFps(int fps) override;
	void DrawFps() override;
	float GetFps() override { return mCurrentFPS; }

private:
	bool mShouldClose = false;
	int mTargetFrameTime;

	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	TTF_Font* mFont = nullptr;

	void UpdateFPS();
	
};

