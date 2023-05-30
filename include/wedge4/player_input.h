#ifndef WEDGE4_PLAYER_INPUT_H
#define WEDGE4_PLAYER_INPUT_H

#include "wedge4/main.h"
#include "wedge4/input.h"
#include "wedge4/systems.h"

namespace wedge {

class Map_Entity;

class WEDGE4_EXPORT Player_Input_Step : public Map_Entity_Input_Step
{
public:
	Player_Input_Step(Map_Entity *entity, Task *task);
	virtual ~Player_Input_Step();

	void handle_event(TGUI_Event *event);

	void set_input_paused(bool paused);

private:
	bool input_paused;
};

}

#endif // WEDGE4_PLAYER_INPUT_H
