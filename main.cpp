#include "game.h"
#include <iostream>
#include "player.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	Game ship;

	Player *play = new Player(&ship, (char *) "/home/ivan/Qt Creator/ship/p_ship.png", true, 116, 105);
}
