#ifndef GUI_H
#define GUI_H

#include <wedge4/main.h>

#include "widgets.h"

class Menu_GUI : public gui::GUI {
public:
	Menu_GUI(bool transition);
	virtual ~Menu_GUI();

	virtual void draw_fore();
	virtual void update();
	virtual void resize(util::Size<int> new_size);
	void handle_event(TGUI_Event *event);

private:
	Widget_Text_Button *potion_button;
	Widget_Text_Button *return_button;
};

#endif // GUI_H
