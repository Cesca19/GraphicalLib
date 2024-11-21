#pragma once
#include "Window.h"
#include "SpriteSDL.h"
#include "CircleSdl.h"
#include "Headers.h"

struct KeycodeHash {
	std::size_t operator()(SDL_Keycode key) const {
		return std::hash<int>()(static_cast<int>(key));
	}
};

struct KeycodeEqual {
	bool operator()(SDL_Keycode lhs, SDL_Keycode rhs) const {
		return static_cast<int>(lhs) == static_cast<int>(rhs);
	}
};

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
	bool ShouldClose() override;
	Event_t PollEvents(Key_t& key) override;
	void WaitFrame() override;
	void SetTargetFps(int fps) override;
	void DrawFps() override;
	float GetFps() override { return mCurrentFPS; }

private:
	bool mShouldClose = false;
	int mTargetFrameTime;
	Uint32 mLastTime = 0;
	float mDeltaTime = 0;
	//int mFrameCount = 0;

	SDL_Surface* mWinSurface = nullptr;
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;
	TTF_Font* mFont = nullptr;
	std::unordered_map<Colors, SDL_Color> _colorsMap;
	std::unordered_map<Sint32, Key_t, KeycodeHash, KeycodeEqual> _keyMap;
	void UpdateFPS();
	
};

