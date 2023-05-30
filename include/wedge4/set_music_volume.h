#ifndef WEDGE4_SET_MUSIC_VOLUME_H
#define WEDGE4_SET_MUSIC_VOLUME_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Set_Music_Volume_Step : public Step
{
public:
	Set_Music_Volume_Step(float volume, Task *task);
	virtual ~Set_Music_Volume_Step();

	void start();
	bool run();

private:
	float volume;
};

}

#endif // WEDGE4_SET_MUSIC_VOLUME_H
