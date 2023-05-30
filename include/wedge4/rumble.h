#ifndef WEDGE4_RUMBLE_H
#define WEDGE4_RUMBLE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Rumble_Step : public Step
{
public:
	Rumble_Step(Uint32 length, Task *task);
	virtual ~Rumble_Step();

	bool run();

private:
	Uint32 length;
};

}

#endif // WEDGE4_RUMBLE_H
