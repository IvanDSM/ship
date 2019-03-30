#ifndef PLAYER_H
#define PLAYER_H

#include <beam.h>
#include <game.h>
#include <iostream>
#include <object.h>

class Player : public Object
{
	private:
		bool			is_spawning = true;
		bool			is_ending = false;
		int				beam_timer = 0;
		int				start_y;

	public:
						Player(Game *Pgame, int pos_x, int pos_y, int p_num) : Object(Pgame, (char *) "p_ship.png", true, pos_x, pos_y)
						{
							switch (p_num)
							{
								case 1:
									type = ObjectType::OBJ_PLAYER1;
									break;
								case 2:
									type = ObjectType::OBJ_PLAYER2;
									break;
								default:
									std::cout << "ship: Invalid player number when spawning player! Given p_num: " << p_num << std::endl;
									exit(1);
									break;
							}
							y = 240;
							start_y = pos_y;
							is_spawning = true;
						}

		void			Tick();
};

#endif // PLAYER_H
