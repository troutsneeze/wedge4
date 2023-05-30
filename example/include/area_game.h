#ifndef AREA_GAME_H
#define AREA_GAME_H

#include <wedge4/area.h>
#include <wedge4/area_game.h>

class Area_Game : public wedge::Area_Game
{
public:
	virtual ~Area_Game();

	wedge::Area_Hooks *get_area_hooks(std::string area_name, wedge::Area *area);
	void draw();
	
	wedge::Game *create_menu();
};

#endif // AREA_GAME_H
