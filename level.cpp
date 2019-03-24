#include "level.h"

void Level::Tick()
{
	y = -720 + (line % 720);
	line += 2;
}
