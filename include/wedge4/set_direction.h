#ifndef WEDGE4_SET_DIRECTION_H
#define WEDGE4_SET_DIRECTION_H

#include "wedge4/main.h"
#include "wedge4/globals.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Set_Direction_Step : public Step
{
public:
	Set_Direction_Step(Map_Entity *entity, Direction direction, bool set_animation, bool moving, Task *task);
	virtual ~Set_Direction_Step();

	void start();
	bool run();

private:
	Map_Entity *entity;
	Direction direction;
	bool set_animation;
	bool moving;
};

}

#endif // WEDGE4_SET_DIRECTION_H
