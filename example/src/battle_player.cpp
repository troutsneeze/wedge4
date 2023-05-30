#include <wedge4/battle_game.h>
#include <wedge4/globals.h>
#include <wedge4/stats.h>

#include "battle_player.h"
#include "general.h"
#include "globals.h"

static void attack_callback(void *data)
{
	if (BATTLE == nullptr) {
		return;
	}

	Battle_Player *p = static_cast<Battle_Player *>(data);
	p->get_sprite()->set_animation("stand_w");
	p->set_attack_done(true);
}

Battle_Player::Battle_Player() :
	wedge::Battle_Player("Hero", 0),
	turn_started(false)
{
	sprite = new gfx::Sprite("eny");
	sprite->set_animation("stand_w");
}

Battle_Player::~Battle_Player()
{
	delete sprite;
}

void Battle_Player::handle_event(TGUI_Event *event)
{
}

void Battle_Player::draw()
{
	gfx::Image *current_image = sprite->get_current_image();
	util::Size<int> offset = (util::Size<int>(shim::tile_size, shim::tile_size) - current_image->size) / 2;
	util::Point<float> pos = get_draw_pos() + util::Point<int>(offset.w, offset.h);
	current_image->draw(pos);
}

void Battle_Player::draw_fore()
{
}

void Battle_Player::set_attack_done(bool done)
{
	attack_done = done;
}

wedge::Battle_Game::Turn *Battle_Player::get_turn()
{
	auto t = new wedge::Battle_Game::Turn;

	t->actor = this;
	t->turn_type = wedge::Battle_Game::ATTACK;
	t->turn_name = "attack";
	wedge::Battle_Entity *e = (wedge::Battle_Entity *)BATTLE->get_random_enemy();
	t->targets.push_back(e);
	t->started = false;

	return t;
}

bool Battle_Player::take_turn(wedge::Battle_Game::Turn *turn)
{
	// this example just does a simple auto-attack

	if (turn_started == false) {
		std::vector<wedge::Battle_Entity *> enemies = BATTLE->get_enemies();
		bool all_dead = true;
		for (size_t i = 0; i < enemies.size(); i++) {
			if (enemies[i]->get_stats()->hp > 0) {
				all_dead = false;
				break;
			}
		}
		if (all_dead == false) {
			attack_done = false;
			sprite->set_animation("punch", attack_callback, this);
			EX_GLOBALS->melee->play(false);
			turn_started = true;
		}
	}
	else {
		if (attack_done) {
			EX_GLOBALS->hit->play(false);
			auto p = turn->targets[0];
			int damage = MAX(1, stats->fixed.attack-p->get_stats()->fixed.defence);
			damage += util::rand(0, stats->fixed.attack*0.25f);
			add_special_number(this, p, damage, true, true);
			turn_started = false;
			return true;
		}
	}

	return false;
}

void Battle_Player::run()
{
}

bool Battle_Player::take_hit(Battle_Entity *actor, int damage)
{
	bool result = wedge::Battle_Entity::take_hit(actor, damage);
	if (stats->hp <= 0 && sprite != nullptr) {
		sprite->set_animation("dead");
	}
	return result;
}
