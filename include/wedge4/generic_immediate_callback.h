#ifndef WEDGE4_GENERIC_IMMEDIATE_CALLBACK_H
#define WEDGE4_GENERIC_IMMEDIATE_CALLBACK_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Generic_Immediate_Callback_Step : public Step
{
public:
	Generic_Immediate_Callback_Step(util::Callback callback, void *callback_data, Task *task);
	virtual ~Generic_Immediate_Callback_Step();

	void start();
	bool run();

private:
	util::Callback callback;
	void *callback_data;
};

}

#endif // WEDGE4_GENERIC_IMMEDIATE_CALLBACK_H
