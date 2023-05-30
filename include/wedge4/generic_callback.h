#ifndef WEDGE4_GENERIC_CALLBACK_H
#define WEDGE4_GENERIC_CALLBACK_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Generic_Callback_Step : public Step
{
public:
	Generic_Callback_Step(util::Callback callback, void *callback_data, Task *task);
	virtual ~Generic_Callback_Step();
	
	bool run();
	void done_signal(Step *step);

private:
	util::Callback callback;
	void *callback_data;
	bool done;
};

}

#endif // WEDGE4_GENERIC_CALLBACK_H
