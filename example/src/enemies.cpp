#include <wedge4/battle_enemy.h>
#include <wedge4/stats.h>

#include "enemies.h"
#include "general.h"
#include "globals.h"

static void attack_callback(void *data)
{
	if (BATTLE == nullptr) {
		return;
	}

	Enemy_Slime *e = static_cast<Enemy_Slime *>(data);
	e->get_sprite()->set_animation("idle");
	e->set_attack_done(true);
}

Enemy_Slime::Enemy_Slime() :
	wedge::Battle_Enemy(TRANSLATE("Slime")END),
	turn_started(false)
{
	attack_sfx = new audio::MML("sfx/enemy_attack.mml");
}

Enemy_Slime::~Enemy_Slime()
{
	delete attack_sfx;
}

bool Enemy_Slime::start()
{
	experience = 8;
	gold = 11;
	sprite = new gfx::Sprite("slime");

	stats = new wedge::Base_Stats();

	stats->fixed.max_hp = stats->hp = 50;
	stats->fixed.attack = 30;
	stats->fixed.defence = 10;

	return true;
}

void Enemy_Slime::set_attack_done(bool done)
{
	attack_done = done;
}

void Enemy_Slime::start_attack(wedge::Battle_Game::Turn *turn)
{
	attack_done = false;
	attack_sfx->play(false);
	sprite->set_animation("attack", attack_callback, this);
}

bool Enemy_Slime::turn_attack(wedge::Battle_Game::Turn *turn)
{
	if (attack_done) {
		EX_GLOBALS->hit->play(false);
		auto p = turn->targets[0];
		int damage = MAX(1, stats->fixed.attack-p->get_stats()->fixed.defence);
		damage += util::rand(0, stats->fixed.attack*0.25f);
		damage *= 0.25f;
		add_special_number(this, p, damage, true, true);
		turn_started = false;
		return false;
	}
	return true;
}

wedge::Battle_Game::Turn *Enemy_Slime::get_turn()
{
	auto t = new wedge::Battle_Game::Turn;

	t->actor = this;
	t->turn_type = wedge::Battle_Game::ATTACK;
	t->turn_name = "attack";
	t->targets.push_back(BATTLE->get_random_player());
	t->started = false;

	return t;
}

bool Enemy_Slime::take_turn(wedge::Battle_Game::Turn *turn)
{
	if (turn_started == false) {
		if (turn->targets.size() == 0) {
			return false; // do nothing, we were attacking dead player or something and there are no more living players
		}
		turn_started = true;
		if (turn->turn_type == wedge::Battle_Game::ATTACK) {
			start_attack(turn);
		}
	}
	else {
		if (turn->turn_type == wedge::Battle_Game::ATTACK) {
			return turn_attack(turn);
		}
	}
	return true;
}
