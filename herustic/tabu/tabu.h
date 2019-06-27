#ifndef TABU_H
#define TABU_H

#include "herustic/interfaces/iherustic.h"
#include "tabu_game.h"

#define TABU_STACK_MAX 10

template <class Base>
class Tabu : public IHerustic
{		
	protected:
		TabuGame<Base>& game;
		std::vector<std::unique_ptr<IAction>> tabu_stack;
		size_t cursor;

	public:
		Tabu(TabuGame<Base>&);
		virtual ~Tabu() = default;

		virtual void play();
		virtual void solve();
};

#include "tabu.tpp"

#endif // TABU_H
