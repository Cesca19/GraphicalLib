// Example Program

#include <iostream>

#include "Window.h"
#include "WindowSDL.h"

int main(int argc, char** args) {
	Window* window = new WindowSDL("Window", 1280, 720);
	window->Init();
	window->CreateWindow();
	window->LoadSprite();
	return 0;
}