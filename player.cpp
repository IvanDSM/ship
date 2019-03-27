#include "player.h"

void Player::Tick()
{
	if (beam_timer > 0)
		beam_timer --;

	if (game->keystates[SDL_SCANCODE_UP] && y > 1)
		y-=2;
	else if (game->keystates[SDL_SCANCODE_DOWN] && y < 225)
		y+=2;
	if (game->keystates[SDL_SCANCODE_LEFT] && x > 0)
		x-=2;
	else if (game->keystates[SDL_SCANCODE_RIGHT] && x < 244)
		x+=2;

	if (game->keystates[SDL_SCANCODE_D] && beam_timer == 0)
	{
		game->AddObject(new Beam(game, BeamType::BEAM_PLAYER, x + 4, y - 8));
		beam_timer = 8;
	}
}
