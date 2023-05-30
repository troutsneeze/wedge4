#ifndef WEDGE4_FADE_H
#define WEDGE4_FADE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Fade_Step : public Step
{
public:
	Fade_Step(SDL_Colour colour, bool out, int length/*ms*/, Task *task); // in or out
	virtual ~Fade_Step();
	
	bool run();
	void start();

protected:
	SDL_Colour colour;
	bool out;
	int length;
	Uint32 start_time;
};

}

#endif // WEDGE4_FADE_H
