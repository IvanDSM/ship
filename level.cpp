#include <fstream>
#include "game.h"
#include <iostream>
#include "level.h"
#include "player.h"

using namespace std;

LevelEvent::LevelEvent(int new_line, LevelEventType new_type, int new_value, bool new_has_child)
{
	this->event_line = new_line;
	this->event_type = new_type;
	this->value = new_value;
	this->has_child = new_has_child;
}

void Level::InterpretEvent()
{
	switch (events.front()->event_type) // Check the type of the first event in line
	{
		case LevelEventType::LEVENT_STARTLEVEL:
			game->AddObject(new Player(game, 122, 160));
			break;
		case LevelEventType::LEVENT_SPEEDCHANGE:
			scroll_speed = events.back()->value;
			break;
		case LevelEventType::LEVENT_SPAWNENEMY:
			cout << "LEVENT_SPAWNENEMY stubbed\n";
			break;
		case LevelEventType::LEVENT_SETBLINK:
			if (events.back()->value == 1)
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
	LevelFileReader.open(level_path, ios::in);
	if (LevelFileReader.is_open())
	{
		int n_events;
		int newevent_line, newevent_value;
		int newevent_type;
		bool newevent_has_child;

		LevelFileReader >> n_events;
		for (int i; i < n_events; i++)
		{
			LevelFileReader >> newevent_line;
			LevelFileReader >> newevent_type;
			LevelFileReader >> newevent_value;
			LevelFileReader >> newevent_has_child;

			events.push_back(new LevelEvent(newevent_line, (LevelEventType) newevent_type, newevent_value, newevent_has_child));
		}
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
	if (events.front()->event_line == line)
		InterpretEvent();
	y = -720 + (line % 720);
	line += scroll_speed;
}
