#ifndef WEDGE4_PAUSE_PRESSES_H
#define WEDGE4_PAUSE_PRESSES_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Pause_Presses_Step : public Step
{
public:
	Pause_Presses_Step(bool paused, bool repeat_pressed, Task *this_task);
	virtual ~Pause_Presses_Step();
	
	void start();
	bool run();

private:
	bool paused;
	bool repeat_pressed;
};

}

#endif // WEDGE4_PAUSE_PRESSES_H
