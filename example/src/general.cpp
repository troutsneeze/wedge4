#include <wedge4/battle_enemy.h>
#include <wedge4/battle_player.h>
#include <wedge4/special_number.h>

#include "general.h"
#include "hit.h"

bool add_special_number(wedge::Battle_Entity *actor, wedge::Battle_Entity *target, int damage, bool lucky_misses, bool play_sounds)
{
	bool ret = false;

	SDL_Colour colour;
	SDL_Colour shadow_colour;
		
	audio::Sound *hit_sfx;
	audio::Sound *hit_sfx2 = nullptr;
		
	//hit_sfx = TTH_GLOBALS->hit;

	wedge::Base_Stats *actor_stats = actor->get_stats();
	wedge::Base_Stats *target_stats = target->get_stats();

	// TTH specific
	lucky_misses = false;

	if (lucky_misses) {
#if 0
		int actor_luck = actor_stats->fixed.get_extra(LUCK);
		int target_luck = target_stats->fixed.get_extra(LUCK);
		int diff = actor_luck - target_luck;

		int r = util::rand(0, 99);
		int r2 = util::rand(0, 99);

		int l_max;
		int m_max;

		if (diff >= 0) {
			l_max = MAX(MIN(50, diff), 1);
			m_max = 1;
		}
		else {
			l_max = 1;
			m_max = MAX(MIN(50, -diff), 1);
		}

		bool do_dodge = false;

		/*
		if (dynamic_cast<Enemy_Red_Wasp *>(target)) {
			do_dodge = true;
			// if it's 0, it's a dodge
			r2 = util::rand(0, 3);
			m_max = 1;
		}
		*/

		float r3 = util::rand(0, 10);
		r3 -= 5.0f;
		damage *= (1.0f + r3/100.0f);
		damage = MAX(1, damage);

		if (r < l_max) {
			damage *= 1.25f;
			if (play_sounds) {
				//hit_sfx->play(false);
				//if (hit_sfx2 != nullptr) {
					//hit_sfx2->play(false);
				//}
			}
			colour = GLOBALS->strong_attack_colour;
			shadow_colour = GLOBALS->strong_attack_shadow;
		}
		else if (r2 < m_max) {
			ret = true;
			damage = 0;
			if (play_sounds) {
				//TTH_GLOBALS->shock->play(false);
			}
			colour = shim::palette[5];
			colour = GLOBALS->helpful_attack_colour;
			shadow_colour = GLOBALS->helpful_attack_shadow;
			if (do_dodge) {
				gfx::add_notification(GLOBALS->game_t->translate(366)/* Originally: Dodged! */);
				//TTH_GLOBALS->dodge->play(false);
				target->get_sprite()->set_animation("dodge", dodge_callback, target);
			}
		}
		else {
			if (play_sounds) {
				//hit_sfx->play(false);
				//if (hit_sfx2 != nullptr) {
					//hit_sfx2->play(false);
				//}
			}
			colour = GLOBALS->regular_attack_colour;
			shadow_colour = GLOBALS->regular_attack_shadow;
		}
#endif
	}
	else {
		colour = GLOBALS->regular_attack_colour;
		shadow_colour = GLOBALS->regular_attack_shadow;
		if (damage > 0 && play_sounds) {
			//hit_sfx->play(false);
			//if (hit_sfx2 != nullptr) {
				//hit_sfx2->play(false);
			//}
		}
	}

	/*
	if (target->get_sprite()->get_animation() == "attack_defend") {
		damage = 1;
	}
	*/

	std::string text = damage == 0 ? GLOBALS->game_t->translate(185)/* Originally: MISS! */ : util::itos(damage);

	util::Point<int> number_pos;

	if (dynamic_cast<wedge::Battle_Player *>(target)) {
		target->take_hit(actor, damage);
		auto player = dynamic_cast<wedge::Battle_Player *>(target);
		number_pos = player->get_draw_pos();
		number_pos.x -= (shim::font->get_text_width(text)+5);
		number_pos.y -= shim::tile_size/4;
	}
	else {
		target->take_hit(actor, damage);
		auto enemy = dynamic_cast<wedge::Battle_Enemy *>(target);
		number_pos = enemy->get_position();
		gfx::Sprite *sprite = enemy->get_sprite();
		util::Point<int> topleft, bottomright;
		sprite->get_bounds(topleft, bottomright);
		number_pos += topleft;
		number_pos.x += (bottomright.x-topleft.x) + 5;
		number_pos.y -= shim::tile_size/4;
	}
	/*
	if (BATTLE && static_cast<Battle_Game *>(BATTLE)->is_sneak_attack()) {
		number_pos.x = shim::screen_size.w - number_pos.x - shim::font->get_text_width(text);
	}
	*/
	
	NEW_SYSTEM_AND_TASK(BATTLE)
	wedge::Special_Number_Step *step = new wedge::Special_Number_Step(colour, shadow_colour, text, number_pos, damage == 0 ? wedge::Special_Number_Step::RISE : wedge::Special_Number_Step::SHAKE, new_task, false);
	ADD_STEP(step)
	ADD_TASK(new_task)
	if (damage != 0) {
		ANOTHER_TASK
		ADD_STEP(new Hit_Step(target, 0, new_task))
		ADD_TASK(new_task)
	}
	FINISH_SYSTEM(BATTLE)

	return ret;
}
	

