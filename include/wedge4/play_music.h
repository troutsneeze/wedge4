#ifndef WEDGE4_PLAY_MUSIC_H
#define WEDGE4_PLAY_MUSIC_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Play_Music_Step : public Step
{
public:
	Play_Music_Step(std::string name, Task *task);
	virtual ~Play_Music_Step();

	void start();
	bool run();

private:
	std::string name;
};

}

#endif // WEDGE4_PLAY_MUSIC_H
