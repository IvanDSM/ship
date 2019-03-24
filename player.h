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
						using Object::Object;
		void			Tick();
};

#endif // PLAYER_H
