#ifndef WEDGE4_GENERIC_GUI_H
#define WEDGE4_GENERIC_GUI_H

#include "wedge4/main.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Generic_GUI_Step : public Step
{
public:
	Generic_GUI_Step(gui::GUI *gui, bool resize, Task *task);
	virtual ~Generic_GUI_Step();

	void start();
	bool run();

	void set_done(bool done);

private:
	bool done;
	gui::GUI *gui;
	bool resize;
};

}

#endif // WEDGE4_GENERIC_GUI_H
