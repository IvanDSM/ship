#ifndef LEVEL_H
#define LEVEL_H

#include "object.h"
#include <vector>

using std::vector;

enum class LevelEventType
{
	LEVENT_STARTLEVEL,
	LEVENT_SPEEDCHANGE,
	LEVENT_SPAWNENEMY,
	LEVENT_SETBLINK,
	LEVENT_ENDLEVEL
};

struct LevelEvent
{
		int				event_line;
		LevelEventType	event_type;
		int				value;
		LevelEvent		*child;
};

class Level : public Object
{
	protected:
		int				line = 0;
		int				scroll_speed = 2;
		vector <struct LevelEvent> events;

	public:
		void			InterpretEvent();
						Level (Game *Pgame) : Object(Pgame, (char *) "level.png", true, 0, -720)
						{
							type = ObjectType::OBJ_LEVEL;
						}

		void			Tick();
};

#endif // LEVEL_H
