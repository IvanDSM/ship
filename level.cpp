#include <fstream>
#include <iostream>
#include "level.h"

using namespace std;

void Level::InterpretEvent()
{
	switch (events.front().event_type) // Check the type of the first event in line
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
	events.erase(events.begin()); // Erase the first event in line
}

void Level::LoadLevelFile(char level_path[])
{
	ifstream LevelFileReader;
	LevelFileReader.open(level_path, ios::in | ios::ate);
	if (LevelFileReader.is_open())
	{
		// Implement actual reading
	}
	else
	{
		cout << "ship: Failed to load level file! Error: " << strerror(errno) << endl;
		exit(1);
	}

	LevelFileReader.close();
}

void Level::Tick()
{
	y = -720 + (line % 720);
	line += scroll_speed;
}
