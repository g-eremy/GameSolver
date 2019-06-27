#ifndef FLOOD_IT_EVALUABLE_TRY2_H
#define FLOOD_IT_EVALUABLE_TRY2_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/ievaluable_action.h"

template<class Base = FloodIt>
class FloodItEvaluableActionTry2 : public Base, public virtual IEvaluableAction
{
	private:
		using vectorZone = std::vector<std::reference_wrapper<FloodItZone>>;

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
		FloodItEvaluableActionTry2(const FloodItEvaluableActionTry2&);
		FloodItEvaluableActionTry2(const IGame&);

		virtual ~FloodItEvaluableActionTry2() = default;

		virtual size_t evaluate(IAction&);
};

#include "flood_it_evaluable_action_try2.tpp"

#endif // FLOOD_IT_EVALUABLE_TRY2_H
