#include "AppCircles.h"
#include "AppBrickBreaker.h"

int main(int argc, char** argv) 
{
	//AppCircles app(SDL);
	//app.Init(1200, 800, "Circle App", 10);
	//app.Run();

	DisplayMode dm = RAYLIB;
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-sdl") == 0) {
			dm = SDL;
		}
		if (strcmp(argv[i], "-raylib") == 0) {
			dm = RAYLIB;
		}
	}

	AppBrickBreaker appBrick(dm);
	appBrick.Init(1200, 800, "Brick Breaker");
	appBrick.Run();
	return 0;
}

