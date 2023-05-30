#ifndef WEDGE4_STOP_MUSIC_H
#define WEDGE4_STOP_MUSIC_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Stop_Music_Step : public Step
{
public:
	Stop_Music_Step(Task *task);
	virtual ~Stop_Music_Step();

	void start();
	bool run();
};

}

#endif // WEDGE4_STOP_MUSIC_H
