#ifndef LEVEL_H
#define LEVEL_H

#include <object.h>

class Level : public Object
{
	protected:
		int				line = 0;

	public:
						Level (Game *Pgame) : Object(Pgame, (char *) "level.png", true, 0, -720)
						{
							type = ObjectType::OBJ_LEVEL;
						}

		void			Tick();
};

#endif // LEVEL_H
