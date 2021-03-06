#ifndef FLOOD_IT_EVALUABLE_TRY1_H
#define FLOOD_IT_EVALUABLE_TRY1_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/ievaluable_action.h"

template<class Base = FloodIt>
class FloodItEvaluableActionTry1 : public Base, public virtual IEvaluableAction
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
		FloodItEvaluableActionTry1(const FloodItEvaluableActionTry1&);
		FloodItEvaluableActionTry1(const IGame&);

		virtual ~FloodItEvaluableActionTry1() = default;

        virtual size_t evaluate(IAction&);
};

#include "flood_it_evaluable_action_try1.tpp"

#endif // FLOOD_IT_EVALUABLE_TRY1_H
