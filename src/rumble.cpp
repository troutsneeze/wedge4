#include "wedge4/general.h"
#include "wedge4/rumble.h"

using namespace wedge;

namespace wedge {

Rumble_Step::Rumble_Step(Uint32 length, Task *task) :
	Step(task),
	length(length)
{
}

Rumble_Step::~Rumble_Step()
{
}

bool Rumble_Step::run()
{
	rumble(length);
	send_done_signal();
	return false;
}

} // End namespace wedge
