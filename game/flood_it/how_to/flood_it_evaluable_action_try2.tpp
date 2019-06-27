#include "flood_it_evaluable_action_try2.h"
#include "lib/lib.h"
#include "lib/vector.h"
#include "game/flood_it/flood_it_action.h"

template<class Base>
FloodItEvaluableActionTry2<Base>::FloodItEvaluableActionTry2(const FloodItEvaluableActionTry2& o): Base(o)
{

}

template<class Base>
FloodItEvaluableActionTry2<Base>::FloodItEvaluableActionTry2(const IGame& o): Base(o)
{

}

template<class Base>
size_t FloodItEvaluableActionTry2<Base>::evaluate(IAction& action)
{
	vectorZone temp;
	FloodItCell& current_cell = *(matrix[begin_y][begin_x]);
	FloodItZone& current_zone = current_cell.getZone();

	size_t r = 0;
	size_t i;
	size_t j;
	size_t count_current = current_zone.countNeighbors();
	size_t count_neighbors;
	size_t selected_color = static_cast<FloodItAction&>(action).getColor();
	size_t neighbor_color;

	for (i = 0; i < count_current; ++i)
	{
		temp.emplace_back(current_zone.getNeighbor(i));
	}

	for (i = 0; i < count_current; ++i)
	{
		FloodItZone& neighbor = current_zone.getNeighbor(i);
		count_neighbors = neighbor.countNeighbors();
		neighbor_color = neighbor.getColor();

		if (neighbor_color != selected_color)
		{
			continue;
		}

		for (j = 0; j < count_neighbors; ++j)
		{
			FloodItZone& unlock = neighbor.getNeighbor(j);

			if (vector_has_element(temp, unlock))
			{
				continue;
			}

			temp.emplace_back(unlock);
			r += unlock.countCells();
		}
	}

	return r;
}
