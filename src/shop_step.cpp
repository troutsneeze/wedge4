#include "wedge4/area_game.h"
#include "wedge4/globals.h"
#include "wedge4/shop_step.h"

using namespace wedge;

namespace wedge {

Shop_Step::Shop_Step(std::vector<Object> items, Task *task) :
	Step(task),
	items(items)
{
}

Shop_Step::~Shop_Step()
{
}

void Shop_Step::start()
{
	AREA->start_shop(items);
}

bool Shop_Step::run()
{
	send_done_signal();
	return false;
}

}
