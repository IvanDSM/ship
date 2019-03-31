#include "beam.h"

void Beam::Tick()
{
	if (y < 0 || y > 240)
	{
		game->RemObject(this);
	}

	switch (beamtype)
	{
		case BeamType::BEAM_PLAYER:
			y -= 3;
			break;
		case BeamType::BEAM_SLIDER:
			y += 3;
			break;
	}
}
