#ifndef WEDGE4_PAUSE_TASK_H
#define WEDGE4_PAUSE_TASK_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Pause_Task_Step : public Step
{
public:
	Pause_Task_Step(Task *task_to_pause, bool paused, Task *this_task);
	virtual ~Pause_Task_Step();
	
	void start();
	bool run();

private:
	Task *task_to_pause;
	bool paused;
};

}

#endif // WEDGE4_PAUSE_TASK_H
