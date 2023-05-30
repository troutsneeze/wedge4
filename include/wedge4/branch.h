#ifndef WEDGE4_BRANCH_H
#define WEDGE4_BRANCH_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Branch_Step : public Step
{
public:
	Branch_Step(int *i, Game *game, std::vector< std::vector< std::vector< Step *> > > steps, Task *task);
	virtual ~Branch_Step();

	bool run();

private:
	int *i;
	Game *game;
	std::vector< std::vector< std::vector< Step *> > > steps;
};

}

#endif // WEDGE4_BRANCH_H
