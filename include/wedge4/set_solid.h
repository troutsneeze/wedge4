#ifndef WEDGE4_SET_SOLID_H
#define WEDGE4_SET_SOLID_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Set_Solid_Step : public Step
{
public:
	Set_Solid_Step(Map_Entity *entity, bool solid, Task *task);
	virtual ~Set_Solid_Step();

	void start();
	bool run();

private:
	Map_Entity *entity;
	bool solid;
};

}

#endif // WEDGE4_SET_SOLID_H
