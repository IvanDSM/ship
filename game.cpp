#include <algorithm>
#include "game.h"
#include <iostream>
#include "object.h"
#include <SDL2/SDL.h>
#include <thread>
#include <unistd.h>
#include <vector>

using namespace std;

void Game::AddObject(Object *obj)
{
	this->objects.push_back(obj);
}

Game::Game()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_TIMER) < 0)
	{
		cout << "ship: SDL2 failed to initialize! SDL2 Error:" << SDL_GetError() << endl;
		exit(1);
	}

	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
		cout << "ship: SDL2_image failed to initialize! SDL2_image Error:" << IMG_GetError() << endl;
		exit(1);
	}

	this->window = SDL_CreateWindow("Ivan's Ship Game!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 480, 0);

	if (window == NULL)
	{
		cout << "ship: SDL2 failed to create a window! SDL2 Error:" << SDL_GetError() << endl;
		exit(1);
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "ship: SDL2 failed to create a renderer! SDL2 Error:" << SDL_GetError() << endl;
		exit(1);
	}

	SDL_RenderSetLogicalSize(renderer, 256, 240);

	this->running = true;

	tickThread = thread(&Game::Tick, this);

}

Game::~Game()
{
	if (tickThread.joinable())
		tickThread.join();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

Object *Game::GetPlayer(int p_num)
{
	if (p_num > 0 && p_num < 3 && objects.size() != 0)
	{
		for (Object *o : this->objects)
		{
			if ((p_num == 1 && o->type == ObjectType::OBJ_PLAYER1) || (p_num == 2 && o->type == ObjectType::OBJ_PLAYER2))
				return o;
		}
	}

	return NULL;
}

void Game::RemObject(Object *obj)
{
	vector<Object *>::iterator iter = find(objects.begin(), objects.end(), obj);

	if (iter != objects.end())
		objects.erase(iter);

	obj->Kill();
}

void Game::Render()
{
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255); // Define a cor de renderização como zero, para limpar a tela
	SDL_RenderClear(this->renderer);

	if (this->objects.size() != 0)
	{
		for (Object *o : this->objects)
			o->Draw();
	}

	SDL_RenderPresent(this->renderer);

	this->frame++;
}

void Game::Tick()
{
	if (running)
	{;
		SDL_PollEvent(&this->events);
		this->keystates = (Uint8 *) SDL_GetKeyboardState(NULL);

		if (this->events.type == SDL_QUIT || this->events.type == SDLK_q)
		{
			cout << "ship: Received quit signal, closing game." << endl;
			running = false;
		}

		if (this->objects.size() != 0)
		{
			for (Object *o : this->objects)
				o->Tick();
		}

		this->Render();

		usleep(1000000/60.000);

		this->Tick();
	}
}
