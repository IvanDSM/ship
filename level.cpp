#include <iostream>
#include "level.h"

using namespace std;

void Level::InterpretEvent()
{
	switch (events.back().event_type)
	{
		case LevelEventType::LEVENT_STARTLEVEL:
			cout << "LEVENT_STARTLEVEL stubbed\n";
			break;
		case LevelEventType::LEVENT_SPEEDCHANGE:
			scroll_speed = events.back().value;
			break;
		case LevelEventType::LEVENT_SPAWNENEMY:
			cout << "LEVENT_SPAWNENEMY stubbed\n";
			break;
		case LevelEventType::LEVENT_SETBLINK:
			if (events.back().value == 1)
				fx_blink = true;
			else
				fx_blink = false;
			break;
		case LevelEventType::LEVENT_ENDLEVEL:
			cout << "LEVENT_ENDLEVEL stubbed\n";
			break;
	}
	events.pop_back();
}

void Level::LoadLevelFile(char level_path[])
{

}

void Level::Tick()
{
	y = -720 + (line % 720);
	line += scroll_speed;
}
