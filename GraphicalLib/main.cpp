#include "headers.h"
#include "Circle.h"
#include "Window.h"
#include "WindowSDL.h"

int main(int argc, char** args) {
	Window* window = new WindowSDL("Window", 1280, 720);
	window->Init();
	window->CreateWindow();
   
	std::vector<Circle*> circles;
	const int NUM_CIRCLES = 5;

	for(int i = 0; i < NUM_CIRCLES; i++) {
		float randX = rand() % (1280 - 64);
		float randY = rand() % (720 - 64);
		circles.push_back(new Circle(window, randX, randY));
	}

	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				running = false;
		}

		window->Clear();
		for(auto circle : circles) {
			circle->Update(1280, 720);
			window->RenderSprite(circle->sprite);
		}
		window->Present();
		SDL_Delay(16);
	}

	for(auto circle : circles) {
		delete circle->sprite;
		delete circle;
	}
	delete window;
   
	return 0;
}