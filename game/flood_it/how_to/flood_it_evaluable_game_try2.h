#ifndef FLOOD_IT_EVALUABLE_GAME_TRY2_H
#define FLOOD_IT_EVALUABLE_GAME_TRY2_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/ievaluable_game.h"

template<class Base = FloodIt>
class FloodItEvaluableGameTry2 : public Base, public virtual IEvaluableGame
{
	protected:
		// attributes
		using Base::size;
		using Base::nb_colors;
		using Base::count_move;
		using Base::begin_x;
		using Base::begin_y;
		using Base::matrix;
		using Base::all_zones;

	public:
		FloodItEvaluableGameTry2(const FloodItEvaluableGameTry2&);
		FloodItEvaluableGameTry2(const IGame&);

		virtual ~FloodItEvaluableGameTry2() = default;

		virtual size_t evaluate();
};

#include "flood_it_evaluable_game_try2.tpp"

#endif // FLOOD_IT_EVALUABLE_GAME_TRY2_H
