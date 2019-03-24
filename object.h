#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Game;

enum class ObjectType
{
	OBJ_GENERIC,
	OBJ_PLAYER,
	OBJ_ENEMY_SLIDER,
	OBJ_PLAYER_BEAM,
	OBJ_ENEMY_BEAM,
	OBJ_UNKNOWN = 0xFF
};

class Object
{
	protected:

		bool			alive;
		bool			fx_blink;
		bool			fx_fliph;
		bool			fx_flipv;
		bool			visible;
		Game			*game;
		int				h;
		int				w;
		int				x;
		int				y;
		SDL_Texture		*sprite;


	public:
		ObjectType		type;
		void			Draw();
						Object(Game *Pgame, char texture_path[], bool is_visible, int pos_x, int pos_y);
						~Object();
		virtual void	Tick() = 0;
};

#endif // OBJECT_H
