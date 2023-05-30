#ifndef WEDGE4_DELETE_MAP_ENTITY_H
#define WEDGE4_DELETE_MAP_ENTITY_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Delete_Map_Entity_Step : public Step
{
public:
	Delete_Map_Entity_Step(Map_Entity *entity, Task *task);
	virtual ~Delete_Map_Entity_Step();
	
	bool run();
	void start();

private:
	Map_Entity *entity;
};

}

#endif // WEDGE4_DELETE_MAP_ENTITY_H
