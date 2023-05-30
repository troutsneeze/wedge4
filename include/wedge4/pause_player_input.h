#ifndef WEDGE4_PAUSE_PLAYER_INPUT_H
#define WEDGE4_PAUSE_PLAYER_INPUT_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Pause_Player_Input_Step : public Step
{
public:
	Pause_Player_Input_Step(bool paused, Task *this_task);
	virtual ~Pause_Player_Input_Step();
	
	void start();
	bool run();

private:
	bool paused;
};

}

#endif // WEDGE4_PAUSE_PLAYER_INPUT_H
