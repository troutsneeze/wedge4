#ifndef BATTLE_PLAYER_H
#define BATTLE_PLAYER_H

#include <wedge4/main.h>
#include <wedge4/battle_player.h>
#include <wedge4/stats.h>

class Battle_Player : public wedge::Battle_Player
{
public:
	Battle_Player();
	~Battle_Player();

	void handle_event(TGUI_Event *event);
	void draw();
	void draw_fore();
	void run();
	
	wedge::Battle_Game::Turn *get_turn();
	bool take_turn(wedge::Battle_Game::Turn *turn);

	bool take_hit(Battle_Entity *actor, int damage);
	
	void set_attack_done(bool done);

private:
	bool turn_started;
	bool attack_done;
};

#endif // BATTLE_PLAYER_H
