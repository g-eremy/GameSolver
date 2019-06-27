#include "tabu.h"

template <class Base>
Tabu<Base>::Tabu(TabuGame<Base>& game): game(game), cursor(TABU_STACK_MAX)
{
	tabu_stack.reserve(TABU_STACK_MAX);
}

template <class Base>
void Tabu<Base>::play()
{
	if (cursor == tabu_stack.size())
	{
		cursor = 0;
		tabu_stack.clear();
		solve();
	}

	IAction& action = *(tabu_stack[cursor]);
	game.play(action);
	++cursor;
}

template <class Base>
void Tabu<Base>::solve()
{
	size_t current = 0;


}
