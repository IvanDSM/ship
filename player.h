#ifndef PLAYER_H
#define PLAYER_H

#include <beam.h>
#include <game.h>
#include <object.h>

class Player : public Object
{
	private:
		int				beam_timer = 0;

	public:
						Player(Game *Pgame, int pos_x, int pos_y) : Object(Pgame, (char *) "p_ship.png", true, pos_x, pos_y)
						{
							type = ObjectType::OBJ_PLAYER;
						}

		void			Tick();
};

#endif // PLAYER_H
