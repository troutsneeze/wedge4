#ifndef WEDGE4_STOP_SOUND_H
#define WEDGE4_STOP_SOUND_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Stop_Sound_Step : public Step
{
public:
	Stop_Sound_Step(audio::Sound *sound, Task *task);
	virtual ~Stop_Sound_Step();

	bool run();

private:
	audio::Sound *sound;
};

}

#endif // WEDGE4_STOP_SOUND_H
