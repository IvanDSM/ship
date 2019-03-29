#include "game.h"
#include "object.h"
#include <iostream>
#include <string>

Object::Object(Game *Pgame, char texture_path[], bool is_visible, int pos_x, int pos_y)
{
	alive = true;
	fx_blink = false;
	fx_fliph = false;
	fx_flipv = false;
	game = Pgame;
	type = ObjectType::OBJ_GENERIC;
	visible = is_visible;
	x = pos_x;
	y = pos_y;
	if (texture_path != NULL)
	{
		sprite = SDL_CreateTextureFromSurface(game->renderer, IMG_Load(texture_path));
		SDL_QueryTexture(sprite, NULL, NULL, &this->w, &this->h);
		Pgame->AddObject(this);
	}
}

void Object::Draw()
{
	if (!alive || !visible)
		return;
	if (fx_blink && game->frame % 2 != 0)
		return;

	SDL_Rect destination_rectangle;

	destination_rectangle.h = h;
	destination_rectangle.w = w;
	destination_rectangle.x = x;
	destination_rectangle.y = y;

	SDL_RendererFlip flip_value = SDL_FLIP_NONE;

	SDL_RenderCopyEx(game->renderer, sprite, NULL, &destination_rectangle, 0, NULL, flip_value);

}

void Object::Kill()
{
	alive = false;
	visible = false;
	SDL_DestroyTexture(sprite);
}
