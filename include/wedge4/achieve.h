#ifndef WEDGE4_ACHIEVE_H
#define WEDGE4_ACHIEVE_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Achieve_Step : public Step
{
public:
	Achieve_Step(void *id, Task *task);
	virtual ~Achieve_Step();

	void start();
	bool run();

private:
	void *id;
};

}

#endif // WEDGE4_ACHIEVE_H
