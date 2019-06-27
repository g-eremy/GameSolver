#ifndef TABU_GAME_H
#define TABU_GAME_H

#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"
#include "herustic/interfaces/ievaluable_action.h"

template <class Base>
class TabuGame : public Base, public virtual IPlayable, public virtual IEvaluableAction
{
	public:
		TabuGame(const TabuGame<Base>&);
		TabuGame(const IGame&);
		virtual ~TabuGame() = default;
};

#include "tabu_game.tpp"

#endif // TABU_GAME_H
