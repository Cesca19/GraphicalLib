// Example Program

#include <iostream>

#include "Window.h"
#include "WindowSDL.h"

using namespace std;

int main(int argc, char** args) {
	Window* window = new WindowSDL("Test", 1280, 720);
	window->Init();
	window->CreateWindow();


	return 0;

}