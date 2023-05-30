#ifndef WEDGE4_CHECK_POSITIONS_H
#define WEDGE4_CHECK_POSITIONS_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Check_Positions_Step : public Step
{
public:
	Check_Positions_Step(std::vector<Map_Entity *> entities, std::vector< util::Point<int> > positions, bool check_for_zero_offset, Task *task);
	virtual ~Check_Positions_Step();

	bool run();

private:
	std::vector<Map_Entity *> entities;
	std::vector< util::Point<int> > positions;
	bool check_for_zero_offset;
};

}

#endif // WEDGE4_CHECK_POSITIONS_H
