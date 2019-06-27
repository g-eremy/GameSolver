#include "flood_it_evaluable_action_try1.h"
#include "game/flood_it/flood_it_zone.h"
#include"game/flood_it/flood_it_action.h"

template<class Base>
FloodItEvaluableActionTry1<Base>::FloodItEvaluableActionTry1(const FloodItEvaluableActionTry1& game) : Base(game)
{

}

template<class Base>
FloodItEvaluableActionTry1<Base>::FloodItEvaluableActionTry1(const IGame& game) : Base(game)
{

}

template<class Base>
size_t FloodItEvaluableActionTry1<Base>::evaluate(IAction& action)
{
	FloodItAction& chosen = static_cast<FloodItAction&>(action);
	FloodItCell& current_cell = *(matrix[begin_y][begin_x]);
	FloodItZone& current_zone = current_cell.getZone();

	size_t r = 0;
	size_t current_color;
	size_t count = current_zone.countNeighbors();

    for (size_t i = 0; i < count; ++i)
    {
		current_color = current_zone.getNeighbor(i).getColor();
		if(chosen == current_color)
			r++;
    }

    return r;
}
