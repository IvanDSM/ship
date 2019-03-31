#include "beam.h"
#include "game.h"
#include "object.h"
#include "slider.h"

void Slider::Tick()
{
	if (y < desired_y)
	{
		if (game->frame % 4)
			y++;
	}

	else
	{
		if (beam_timer > 0 && game->frame % 2)
			beam_timer--;

		if (x + 16 >= 240 - spacing)
			direction = false;
		else if (x <= spacing)
		{
			direction = true;
			n_slides++;
		}

		if (n_slides > slides_before_aggresive)
			y += 2;

		if (direction)
			x++;
		else
			x--;

		// TODO: Slider should only fire if player is within shot radius

		if (beam_timer == 0)
		{
			game->AddObject(new Beam(game, BeamType::BEAM_SLIDER, x + 4, y + 13));
			beam_timer = 14;
		}
	}
}
