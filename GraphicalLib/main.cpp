#include "headers.h"
#include "Circle.h"
#include "Window.h"
#include "WindowSDL.h"

int main(int argc, char** args) {
	Window* window = new WindowSDL("Window", 1280, 720);
	window->Init();
	window->CreateWindow();
	window->SetTargetFps(60);
   
	std::vector<Circle*> circles;
	const int NUM_CIRCLES = 5;

	for (int i = 0; i < NUM_CIRCLES; i++) {
		float randX = rand() % (window->GetWidth());
		float randY = rand() % (window->GetHeight());
		auto sprite = window->CreateSprite("test-sprite.png", Vector2(randX, randY));
		circles.push_back(new Circle(sprite));
	}

	while (!window->ShouldClose()) {
		window->PollEvents();

		window->Clear();
		for (auto circle : circles) {
			circle->Update(window->GetWidth(), window->GetHeight());
			window->RenderSprite(circle->GetSprite());
		}

		window->Present();
		window->WaitFrame();
	}

	for (auto circle : circles) {
		delete circle->GetSprite();
		delete circle;
	}
	delete window;
   
	return 0;
}