#ifndef WEDGE4_BATTLE_PLAYER_H
#define WEDGE4_BATTLE_PLAYER_H

#include "wedge4/main.h"
#include "wedge4/battle_entity.h"
#include "wedge4/stats.h"

namespace wedge {

class WEDGE4_EXPORT Battle_Player : public Battle_Entity
{
public:
	Battle_Player(std::string name, int index);
	virtual ~Battle_Player();

	virtual void handle_event(TGUI_Event *event) = 0;
	virtual void draw() = 0;
	virtual void run() = 0;
	virtual bool start();
	virtual void draw_fore();
	virtual util::Point<float> get_draw_pos();

	bool is_dead();
	Player_Stats *get_player_stats();
	int get_index(); // what their index into Globals::Instance::stats is
	
	bool is_running();

	bool take_hit(Battle_Entity *actor, int damage);

	util::Point<float> get_run_offset();
	void set_run_offset(util::Point<float> run_offset);
	
protected:
	wedge::Player_Stats *player_stats;
	int index;
	bool run_success;
	util::Point<float> run_offset;
};

}

#endif // WEDGE4_BATTLE_PLAYER_H
