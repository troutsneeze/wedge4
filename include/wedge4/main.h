#ifndef WEDGE4_MAIN_H
#define WEDGE4_MAIN_H

#include <shim4/shim4.h>

#ifdef _WIN32
#ifdef WEDGE4_STATIC
#define WEDGE4_EXPORT
#else
#ifdef WEDGE4_BUILD
#define WEDGE4_EXPORT __declspec(dllexport)
#else
#define WEDGE4_EXPORT __declspec(dllimport)
#endif
#endif
#else
#define WEDGE4_EXPORT
#endif

namespace wedge {

bool WEDGE4_EXPORT start(util::Size<int> base_screen_size, util::Size<int> window_size);
bool WEDGE4_EXPORT go();
void WEDGE4_EXPORT end();
void WEDGE4_EXPORT handle_event(TGUI_Event *event);

}

#endif // NOOSKEWL_EDGE_MAIN_H
