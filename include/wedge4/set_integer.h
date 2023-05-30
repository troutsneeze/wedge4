#ifndef WEDGE4_SET_INTEGER_H
#define WEDGE4_SET_INTEGER_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Set_Integer_Step : public Step
{
public:
	Set_Integer_Step(int *i, int value, Task *task);
	virtual ~Set_Integer_Step();

	bool run();

private:
	int *i;
	int value;
};

}

#endif // WEDGE4_SET_INTEGER_H
