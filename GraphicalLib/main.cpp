#include "AppCircles.h"

int main(int argc, char** args) 
{
	AppCircles app(RAYLIB);
	app.Init(1200, 800, "Circle App", 10);
	app.Run();
	return 0;
}
