#include "game.h"
#include <iostream>
#include "level.h"
#include "player.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1) // Interpret arguments
	{

	}

	Game ship;

	Level level(&ship, (char *) "testlevel");

	while (ship.running)
	{

	}
}
