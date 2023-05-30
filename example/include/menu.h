#ifndef MENU_H
#define MENU_H

#include "gui.h"

class Menu_Game : public wedge::Game
{
public:
	Menu_Game();
	virtual ~Menu_Game();

	bool start();
	bool run();
	void draw();
	void draw_fore();
};

#endif // MENU_H
