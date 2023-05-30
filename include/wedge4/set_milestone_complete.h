#ifndef WEDGE4_SET_MILESTONE_COMPLETE_H
#define WEDGE4_SET_MILESTONE_COMPLETE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Set_Milestone_Complete_Step : public Step
{
public:
	Set_Milestone_Complete_Step(int milestone, bool complete, Task *task);
	virtual ~Set_Milestone_Complete_Step();

	void start();
	bool run();

private:
	int milestone;
	bool complete;
};

}

#endif // WEDGE4_SET_MILESTONE_COMPLETE_H
