#include <wedge4/globals.h>

#include "battle_game.h"
#include "battle_transition_in2.h"
#include "transition.h"

Battle_Transition_In2_Step::Battle_Transition_In2_Step(wedge::Task *task) :
	Transition_Step(false, task)
{
}

Battle_Transition_In2_Step::~Battle_Transition_In2_Step()
{
}

bool Battle_Transition_In2_Step::run()
{
	bool ret = Transition_Step::run();
	if (ret == false) {
		static_cast<Battle_Game *>(BATTLE)->show_enemy_stats(true);
		static_cast<Battle_Game *>(BATTLE)->show_player_stats(true);
	}
	return ret;
}
