#ifndef DEEP_ACTION_GAME_H
#define DEEP_ACTION_GAME_H

#include "herustic/interfaces/ievaluable_game.h"
#include "herustic/interfaces/ievaluable_action.h"

template<class Base>
class DeepActionGame : public Base, public virtual IEvaluableGame, public virtual IEvaluableAction
{
	protected:
		size_t sum_evaluate;

		// methods
		using Base::evaluate;

	public:
		DeepActionGame(const DeepActionGame<Base>&);
		DeepActionGame(const IGame&);
		virtual ~DeepActionGame() = default;

		virtual void play(IAction&);
		virtual size_t evaluate();
};

#include "deep_action_game.tpp"

#endif // DEEP_ACTION_GAME_H
