#include "level.h"

void Level::Tick()
{
	y = -720 + (line % 721);
	line += 2;
}
