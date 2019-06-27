#include "flood_it_evaluable_game_try2.h"
#include "game/flood_it/flood_it_zone.h"

template<class Base>
FloodItEvaluableGameTry2<Base>::FloodItEvaluableGameTry2(const FloodItEvaluableGameTry2& game) : Base(game)
{

}

template<class Base>
FloodItEvaluableGameTry2<Base>::FloodItEvaluableGameTry2(const IGame& game) : Base(game)
{

}

template<class Base>
size_t FloodItEvaluableGameTry2<Base>::evaluate()
{

	size_t r = 0;
	FloodItCell& cell = *(matrix[begin_y][begin_x]);
	FloodItZone& base = cell.getZone();
	size_t count = base.countNeighbors();

	for (size_t i = 0; i < count; ++i)
	{
		r += base.getNeighbor(i).countCells();
	}

	return r;
}
