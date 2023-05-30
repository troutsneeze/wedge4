#ifndef WEDGE4_PLAY_ANIMATION_H
#define WEDGE4_PLAY_ANIMATION_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Play_Animation_Step : public Step
{
public:
	Play_Animation_Step(gfx::Sprite *sprite, std::string anim_name, Task *task);
	virtual ~Play_Animation_Step();
	
	void start();
	bool run();

	void set_done(bool done);

private:
	gfx::Sprite *sprite;
	std::string anim_name;
	bool done;
};

}

#endif // WEDGE4_PLAY_ANIMATION_H
