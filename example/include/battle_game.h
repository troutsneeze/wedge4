#ifndef BATTLE_GAME_H
#define BATTLE_GAME_H

#include <wedge4/battle_game.h>

class Battle_Game : public wedge::Battle_Game
{
public:
	Battle_Game(std::string bg, int bg_delay);
	virtual ~Battle_Game();

	void start_transition_in();
	void start_transition_out();
	wedge::Battle_Player *create_player(int index);
	void draw();
	void start_turn(wedge::Battle_Entity *entity);

	void show_enemy_stats(bool show);
	void show_player_stats(bool show);

protected:
	bool enemy_stats_shown;
	bool player_stats_shown;
};

#endif // BATTLE_GAME_H
