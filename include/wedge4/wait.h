#ifndef WEDGE4_WAIT_H
#define WEDGE4_WAIT_H

// Wait for signal, call add_monitor on the Step to wait for

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Wait_Step : public Step
{
public:
	Wait_Step(Task *task);
	virtual ~Wait_Step();
	
	bool run();
	
	void done_signal(Step *step);

private:
	bool done;
};

}

#endif // WEDGE4_WAIT_H
