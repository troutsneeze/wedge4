#ifndef ENEMIES_H
#define ENEMIES_H

#include <wedge4/battle_enemy.h>
#include <wedge4/battle_player.h>

class Enemy_Slime : public wedge::Battle_Enemy
{
public:
	Enemy_Slime();
	virtual ~Enemy_Slime();

	bool start();
	
	wedge::Battle_Game::Turn *get_turn();
	bool take_turn(wedge::Battle_Game::Turn *turn);

	void set_attack_done(bool done);

protected:
	void start_attack(wedge::Battle_Game::Turn *turn);
	bool turn_attack(wedge::Battle_Game::Turn *turn);

	bool turn_started;
	bool attack_done;

	audio::MML *attack_sfx;
};

#endif // ENEMIES_H
