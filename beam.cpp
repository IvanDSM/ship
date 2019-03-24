#include "beam.h"

void Beam::Tick()
{
	if (y < 0)
	{
		game->RemObject(this);
	}
	y -= 3;
}
