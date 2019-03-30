#ifndef GAME_H
#define GAME_H
#include <cstdint>
#include "object.h"
#include <SDL2/SDL.h>
#include <thread>
#include <vector>

using namespace std;

class Game
{

	public:

		bool			is_2p_game;
		bool			running;
		int				frame;
		SDL_Event		events;
		SDL_Renderer	*renderer;
		SDL_Window		*window;
		thread			tickThread;
		Uint8			*keystates;
		vector<Object *> objects;

		void			AddObject(Object *obj);
		Object *		GetPlayer(int p_num);
						Game();
						~Game();
		void			RemObject(Object *obj);
		void			Render();
		void			Tick();
};

#endif // GAME_H
