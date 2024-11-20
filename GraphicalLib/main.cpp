#include "headers.h"
#include "Circle.h"
#include "Window.h"
#include "WindowSDL.h"
#include "WindowRaylib.h"

int main(int argc, char** args) {
	std::shared_ptr<Window> window(new WindowSDL());
	window->Init();
	window->CreateWindow(1280, 720, "Window");
	window->SetTargetFps(60);
   
	std::vector<Circle*> circles;
	const int NUM_CIRCLES = 5;

	for (int i = 0; i < NUM_CIRCLES; i++) {
		float randX = rand() % (window->GetWidth());
		float randY = rand() % (window->GetHeight());
		auto sprite = window->CreateSprite("test-sprite.png", Vector2f(randX, randY));
		circles.push_back(new Circle(sprite, 6.0f));
	}

	while (!window->ShouldClose()) {
		window->StartDrawing();
		
		window->PollEvents();
		window->Clear(T_BEIGE);
		for (auto circle : circles) {
			circle->Update(window->GetWidth(), window->GetHeight());
			window->RenderSprite(circle->GetSprite());
		}

		window->DrawFPS();
		//window->Present();
		window->ShowDrawing();
		window->WaitFrame();
	}

	for (auto circle : circles) {
		delete circle->GetSprite();
		delete circle;
	}
	window->Close();
	return 0;
}
