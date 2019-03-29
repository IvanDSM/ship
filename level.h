#ifndef LEVEL_H
#define LEVEL_H

#include "object.h"
#include <vector>

using std::string;
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
		int				scroll_speed = 4;
		vector <struct LevelEvent> events;

	public:
		void			InterpretEvent();
		void			LoadLevelFile(char level_path[]);
						Level (Game *Pgame, char level_path[]) : Object(Pgame, (char *) "level.png", true, 0, -720)
						{
							type = ObjectType::OBJ_LEVEL;
							this->LoadLevelFile(level_path);
						}

		void			Tick();
};

#endif // LEVEL_H
