#include "level.h"

void Level::InterpretEvent(LevelEvent event)
{
	//stub
}

void Level::Tick()
{
	y = -720 + (line % 720);
	line += 2;
}
