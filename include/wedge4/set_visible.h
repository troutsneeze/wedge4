#ifndef WEDGE4_SET_VISIBLE_H
#define WEDGE4_SET_VISIBLE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Set_Visible_Step : public Step
{
public:
	Set_Visible_Step(Map_Entity *entity, bool visible, Task *task);
	virtual ~Set_Visible_Step();

	void start();
	bool run();

private:
	Map_Entity *entity;
	bool visible;
};

}

#endif // WEDGE4_SET_VISIBLE_H
