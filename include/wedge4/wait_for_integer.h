#ifndef WEDGE4_WAIT_FOR_INTEGER_H
#define WEDGE4_WAIT_FOR_INTEGER_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Wait_For_Integer_Step : public Step
{
public:
	Wait_For_Integer_Step(int *i, int desired_value, Task *task);
	virtual ~Wait_For_Integer_Step();
	
	bool run();

private:
	int *i;
	int desired_value;
};

}

#endif // WEDGE4_WAIT_FOR_INTEGER_H
