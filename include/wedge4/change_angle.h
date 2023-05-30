#ifndef WEDGE4_CHANGE_ANGLE_H
#define WEDGE4_CHANGE_ANGLE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Change_Angle_Step : public Step
{
public:
	Change_Angle_Step(Map_Entity *entity, float start_angle, float end_angle, Uint32 duration, Task *task);
	virtual ~Change_Angle_Step();

	void start();
	bool run();

private:
	Map_Entity *entity;
	float start_angle;
	float end_angle;
	Uint32 duration;
	Uint32 start_time;
};

}

#endif // WEDGE4_CHANGE_ANGLE_H
