#ifndef SLIDER_H
#define SLIDER_H

#include <cstdlib>
#include <ctime>
#include "object.h"

using namespace std;

class Slider : public Object
{
	private:
		bool		direction; // True is right
		int			beam_timer = 0;
		int			desired_y;
		int			n_slides = 0;
		int			shots_radius;
		int			slides_before_aggresive;
		int			spacing;

	public:
					Slider(Game *Pgame, int pos_x) : Object (Pgame, (char *) "e_ship.png", true, pos_x, -13)
					{
						spacing = pos_x;
						srand(time(NULL));
						desired_y = rand() % 68;
						shots_radius = rand() % 49;
						slides_before_aggresive = rand() % 8;
					}
		void		Tick();
};

#endif // SLIDER_H
