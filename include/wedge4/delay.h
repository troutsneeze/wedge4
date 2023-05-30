#ifndef WEDGE4_DELAY_H
#define WEDGE4_DELAY_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Delay_Step : public Step
{
public:
	Delay_Step(int millis, Task *task);
	virtual ~Delay_Step();
	
	void start();
	bool run();

private:
	int millis;
	int start_time;
};

}

#endif // WEDGE4_DELAY_H
