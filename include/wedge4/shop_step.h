#ifndef WEDGE4_SHOP_STEP_H
#define WEDGE4_SHOP_STEP_H

#include "wedge4/main.h"
#include "wedge4/inventory.h"
#include "wedge4/systems.h"

namespace wedge {

class WEDGE4_EXPORT Shop_Step : public Step
{
public:
	Shop_Step(std::vector<Object> items, Task *task);
	virtual ~Shop_Step();

	void start();
	bool run();

private:
	std::vector<Object> items;
};

}

#endif // WEDGE4_SHOP_STEP_H
