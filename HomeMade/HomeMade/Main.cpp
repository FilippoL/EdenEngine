#include "GameManager.h"
#include <iostream>

#define WIDTH 960
#define HEIGHT 540



int main(int argc, char* argv[])
{

	Game::Instance()->Initialise("HOME ENGINE", WIDTH, HEIGHT);

	Game::Instance()->Run();

	Game::Instance()->ShutDown();

	return 0;
}