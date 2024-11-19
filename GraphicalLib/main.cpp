#include "headers.h"
#include "WindowSDL.h"
#include "WindowRaylib.h"

int main(int argc, char** args) {
	std::shared_ptr<Window> window(new WindowRaylib());
	window->Init();
	window->CreateWindow(1280, 720, "Graphic Lib");
	window->SetTargetFps(60);
   
	std::vector<Circle*> circles;
	const int NUM_CIRCLES = 10;
	srand(time(0));
	for (int i = 0; i < NUM_CIRCLES; i++) {
		float randX = rand() % (window->GetWidth());
		float randY = rand() % (window->GetHeight());
		float radius = rand() % 100;
		int color = rand() % 12;
		Circle *circle = window->CreateCircle(Vector2f(randX, randY), radius, (Colors)color);
		circles.push_back(circle);
	}
	Sprite* sprite = window->CreateSprite("../Ressources/apple.png", (500, 300));

	while (!window->ShouldClose()) {
		window->StartDrawing();
	
		window->PollEvents();
		window->Clear(T_BEIGE);
		window->DrawFps();

		for (auto circle : circles)
			circle->Draw();
		sprite->Draw();

		
		window->ShowDrawing();
		window->WaitFrame();
	}

	for (auto circle : circles)
		delete circle;
	window->Close();
	return 0;
}
