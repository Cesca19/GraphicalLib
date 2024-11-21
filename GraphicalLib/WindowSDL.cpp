#include "WindowSDL.h"

WindowSDL::WindowSDL() {
	_colorsMap[T_GRAY] = { 128, 128, 128, 255 };
	_colorsMap[T_YELLOW] = { 255, 255, 0, 255 };
	_colorsMap[T_ORANGE] = { 255, 165, 0, 255 };
	_colorsMap[T_PINK] = { 255, 192, 203, 255 };
	_colorsMap[T_RED] = { 255, 0, 0, 255 };
	_colorsMap[T_GREEN] = { 0, 255, 0, 255 };
	_colorsMap[T_BLUE] = { 0, 0, 255, 255 };
	_colorsMap[T_PURPLE] = { 128, 0, 128, 255 };
	_colorsMap[T_BEIGE] = { 204, 170, 136, 255 };
	_colorsMap[T_BROWN] = { 165, 42, 42, 255 };
	_colorsMap[T_WHITE] = { 255, 255, 255, 255 };
	_colorsMap[T_BLACK] = { 0, 0, 0, 255 };

	_keyMap[SDLK_UNKNOWN] = Key_NONE;
	_keyMap[SDLK_a] = Key_A;
	_keyMap[SDLK_b] = Key_B;
	_keyMap[SDLK_c] = Key_C;
	_keyMap[SDLK_d] = Key_D;
	_keyMap[SDLK_e] = Key_E;
	_keyMap[SDLK_f] = Key_F;
	_keyMap[SDLK_g] = Key_G;
	_keyMap[SDLK_h] = Key_H;
	_keyMap[SDLK_i] = Key_I;
	_keyMap[SDLK_j] = Key_J;
	_keyMap[SDLK_k] = Key_K;
	_keyMap[SDLK_l] = Key_L;
	_keyMap[SDLK_m] = Key_M;
	_keyMap[SDLK_n] = Key_N;
	_keyMap[SDLK_o] = Key_O;
	_keyMap[SDLK_p] = Key_P;
	_keyMap[SDLK_q] = Key_Q;
	_keyMap[SDLK_r] = Key_R;
	_keyMap[SDLK_s] = Key_S;
	_keyMap[SDLK_t] = Key_T;
	_keyMap[SDLK_u] = Key_U;
	_keyMap[SDLK_v] = Key_V;
	_keyMap[SDLK_w] = Key_W;
	_keyMap[SDLK_x] = Key_X;
	_keyMap[SDLK_y] = Key_Y;
	_keyMap[SDLK_z] = Key_Z;
	_keyMap[SDLK_LEFT] = Key_LEFT;
	_keyMap[SDLK_RIGHT] = Key_RIGHT;
	_keyMap[SDLK_BACKSPACE] = Key_BACK;
	_keyMap[SDLK_KP_ENTER] = Key_ENTER;
	_keyMap[SDLK_SPACE] = Key_SPACE;
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

	mFont = TTF_OpenFont("../Ressources/font/GeistMono-Bold.ttf", 24); 
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
	sprite->LoadImage(_strdup(filePath));
	sprite->SetPosition(position);
	return sprite;
}

Circle* WindowSDL::CreateCircle(Vector2f position, float radius, Colors color) {
	return new CircleSdl(position, radius, color, mRenderer);
}


void WindowSDL::Clear(Colors color) {
	SDL_Color sdlColor = _colorsMap[color];
	SDL_SetRenderDrawColor(mRenderer, sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
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

bool WindowSDL::ShouldClose() {
	return mShouldClose;
}

Event_t WindowSDL::PollEvents(Key_t& key)
{
	SDL_Event event;
	key = Key_NONE;
	SDL_PumpEvents();
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_LEFT]) {
		key = _keyMap[SDLK_LEFT];
	}
	if (keys[SDL_SCANCODE_RIGHT]) {
		key = _keyMap[SDLK_RIGHT];
	}

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			mShouldClose = true;
			key = Key_ESC;
			return CLOSE;
		// should not return NONE in default
		// will cause a untreatement poll event
		// and will make the app slow
		//default:
		//	return NONE;
		}
	}

	return NONE;
}

void WindowSDL::WaitFrame() {
	UpdateFPS();
	SDL_Delay(mTargetFrameTime - mDeltaTime);
}

void WindowSDL::SetTargetFps(int fps) {
	mTargetFrameTime = 1000 / fps;
}

void WindowSDL::UpdateFPS() {
	Uint64 currentTime = SDL_GetTicks64();

	mDeltaTime = ((float)(currentTime - mLastTime) / 1000.f);
	mCurrentFPS = 1.f / mDeltaTime;
	mLastTime = currentTime;
}

void WindowSDL::DrawFps() {

	SDL_Color textColor = { 0, 0, 0, 255 };
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