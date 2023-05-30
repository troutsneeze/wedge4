#ifndef WEDGE4_ONSCREEN_CONTROLLER
#define WEDGE4_ONSCREEN_CONTROLLER

#include "wedge4/main.h"

namespace wedge {

enum Onscreen_Button {
	ONSCREEN_IGNORE = 0,
	ONSCREEN_NONE,
	ONSCREEN_UP,
	ONSCREEN_RIGHT,
	ONSCREEN_DOWN,
	ONSCREEN_LEFT,
	ONSCREEN_B1,
	ONSCREEN_B2
};

void WEDGE4_EXPORT enable_onscreen_controller(bool enabled);
bool WEDGE4_EXPORT is_onscreen_controller_enabled();
void WEDGE4_EXPORT set_onscreen_controller_b2_enabled(bool enabled);

bool handle_onscreen_controller(SDL_Event *event);
void update_onscreen_controller();
void draw_onscreen_controller();

void start_onscreen_controller(bool generate_repeats);

// Generate key_b1/b2 (default is action/back)
void set_onscreen_controller_generates_b1_b2(bool onoff);

}

#endif // WEDGE4_ONSCREEN_CONTROLLER
