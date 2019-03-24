#include "game.h"
#include <iostream>
#include "level.h"
#include "player.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	Game ship;

	Level *level = new Level(&ship);

	Player *play = new Player(&ship, 116, 105);
}
