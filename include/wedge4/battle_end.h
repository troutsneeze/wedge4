#ifndef WEDGE4_BATTLE_END_H
#define WEDGE4_BATTLE_END_H

#include "wedge4/main.h"
#include "wedge4/general.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Battle_End_Step : public Step
{
public:
	Battle_End_Step(Task *task);
	virtual ~Battle_End_Step();
	
	bool run();
	void done_signal(Step *step);

private:
	int count;
};

}

#endif // WEDGE4_BATTLE_END_H
