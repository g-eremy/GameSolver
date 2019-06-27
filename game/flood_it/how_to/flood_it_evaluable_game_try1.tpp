#include "flood_it_evaluable_game_try1.h"
#include "game/flood_it/flood_it_zone.h"

template<class Base>
FloodItEvaluableGameTry1<Base>::FloodItEvaluableGameTry1(const FloodItEvaluableGameTry1& game) : Base(game)
{

}

template<class Base>
FloodItEvaluableGameTry1<Base>::FloodItEvaluableGameTry1(const IGame& game) : Base(game)
{

}

template<class Base>
size_t FloodItEvaluableGameTry1<Base>::evaluate()
{
	FloodItCell& cell = *(matrix[begin_y][begin_x]);
	FloodItZone& base = cell.getZone();

	return base.countCells();
}
