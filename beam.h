#ifndef BEAM_H
#define BEAM_H

#include <game.h>
#include <object.h>

class Beam : public Object
{
	public:
						using Object::Object;
		void			Tick();
};

#endif // BEAM_H
