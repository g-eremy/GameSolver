#include "flood_it_evaluable_action_try3.h"
#include "lib/vector.h"
#include "game/flood_it/flood_it_action.h"

template<class Base>
FloodItEvaluableActionTry3<Base>::FloodItEvaluableActionTry3(const FloodItEvaluableActionTry3& o): Base(o)
{

}

template<class Base>
FloodItEvaluableActionTry3<Base>::FloodItEvaluableActionTry3(const IGame& o): Base(o)
{

}

template<class Base>
size_t FloodItEvaluableActionTry3<Base>::evaluate(IAction& action)
{
	FloodItAction& chosen = static_cast<FloodItAction&>(action);
	FloodItCell& current_cell = *(matrix[begin_y][begin_x]);
	FloodItZone& current_zone = current_cell.getZone();

	size_t r = 0;
	size_t temp = 0;
	size_t current_color;
	size_t count = current_zone.countNeighbors();

	for (size_t i = 0; i < count; ++i)
	{
		current_color = current_zone.getNeighbor(i).getColor();
		temp = current_zone.getNeighbor(i).countCells();

		if(chosen == current_color && r < temp)
			r = temp;
	}

	return r;
}
