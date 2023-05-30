#include <wedge4/map_entity.h>
#include <wedge4/onscreen_controller.h>
#include <wedge4/special_number.h>

#include "area_game.h"
#include "general.h"
#include "globals.h"
#include "menu.h"
#include "widgets.h"

Menu_Game::Menu_Game()
{
}

Menu_Game::~Menu_Game()
{
	for (std::vector<gui::GUI *>::iterator it = shim::guis.begin(); it != shim::guis.end(); it++) {
		gui::GUI *gui = *it;
		if (dynamic_cast<Menu_GUI *>(gui)) {
			gui->exit();
		}
	}
}

bool Menu_Game::start()
{
	if (Game::start() == false) {
		return false;
	}

	Menu_GUI *gui = new Menu_GUI(false);
	shim::guis.push_back(gui);

	return true;
}

bool Menu_Game::run()
{
	Game::run(); // don't return if false, there are no systems usually
	
	if (AREA->is_pausing() == false && AREA->is_paused() == false && (shim::guis.size() == 0 || dynamic_cast<Menu_GUI *>(shim::guis.back()) == NULL)) {
		return false;
	}

	return true;
}

void Menu_Game::draw()
{
	Game::draw();
}

void Menu_Game::draw_fore()
{
	Game::draw_fore();
}
