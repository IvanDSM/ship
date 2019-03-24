#ifndef BEAM_H
#define BEAM_H

#include <game.h>
#include <object.h>

enum class BeamType
{
	BEAM_PLAYER,
	BEAM_SLIDER
};

class Beam : public Object
{
	protected:
		BeamType		beamtype;

	public:
						Beam (Game *Pgame, BeamType btype, int pos_x, int pos_y) : Object(Pgame, NULL, true, pos_x, pos_y)
						{
							switch(btype)
							{
								case BeamType::BEAM_PLAYER:
									type = ObjectType::OBJ_PLAYER_BEAM;
									sprite = SDL_CreateTextureFromSurface(game->renderer, IMG_Load((char *) "p_beam.png"));
									break;
								case BeamType::BEAM_SLIDER:
									type = ObjectType::OBJ_ENEMY_BEAM;
									sprite = SDL_CreateTextureFromSurface(game->renderer, IMG_Load((char *) "e_beam.png"));
									break;
							}
							SDL_QueryTexture(sprite, NULL, NULL, &this->w, &this->h);
							Pgame->AddObject(this);
						}

		void			Tick();
};

#endif // BEAM_H
