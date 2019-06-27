#ifndef FLOOD_IT_EVALUABLE_GAME_TRY1_H
#define FLOOD_IT_EVALUABLE_GAME_TRY1_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/ievaluable_game.h"

template<class Base = FloodIt>
class FloodItEvaluableGameTry1 : public Base, public virtual IEvaluableGame
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
		FloodItEvaluableGameTry1(const FloodItEvaluableGameTry1&);
		FloodItEvaluableGameTry1(const IGame&);

		virtual ~FloodItEvaluableGameTry1() = default;

		virtual size_t evaluate();
};

#include "flood_it_evaluable_game_try1.tpp"

#endif // FLOOD_IT_EVALUABLE_GAME_TRY1_H
