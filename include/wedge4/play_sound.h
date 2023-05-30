#ifndef WEDGE4_PLAY_SOUND_H
#define WEDGE4_PLAY_SOUND_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Play_Sound_Step : public Step
{
public:
	Play_Sound_Step(std::string name, Task *task, float volume = 1.0f);
	Play_Sound_Step(audio::Sound *sound, bool wait, bool loop, Task *task, float volume = 1.0f);
	virtual ~Play_Sound_Step();

	void start();
	bool run();
	
private:
	std::string name;
	bool destroy;
	bool wait;
	bool loop;
	audio::Sound *sound;
	float volume;
};

}

#endif // WEDGE4_PLAY_SOUND_H
