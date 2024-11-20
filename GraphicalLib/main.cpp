#include "AppCircles.h"
#include "AppBrickBreaker.h"

int main(int argc, char** args) 
{
	//AppCircles app(SDL);
	//app.Init(1200, 800, "Circle App", 10);
	//app.Run();

	AppBrickBreaker appBrick(SDL);
	appBrick.Init(1200, 800, "Brick Breaker");
	appBrick.Run();
	return 0;
}
