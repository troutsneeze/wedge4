#ifndef WEDGE4_PAUSE_SPRITE_H
#define WEDGE4_PAUSE_SPRITE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Pause_Sprite_Step : public Step
{
public:
	Pause_Sprite_Step(gfx::Sprite *sprite, bool paused, Task *task);
	virtual ~Pause_Sprite_Step();

	void start();
	bool run();

private:
	gfx::Sprite *sprite;
	bool paused;
};

}

#endif // WEDGE4_PAUSE_SPRITE_H
