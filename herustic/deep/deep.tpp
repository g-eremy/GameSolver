#include "deep.h"
#include <QDebug>
#include "game/flood_it/flood_it_action.h"

template<class Base>
Deep<Base>::Deep(DeepGame<Base>& game, const size_t& k) : game(game), k(k)
{

}

template<class Base>
void Deep<Base>::play()
{
	vectorAction init_current;

	optimal_evaluation = 0;
	k_won = 0;
	optimal_action.reset(nullptr);
	solve(game, init_current);

	IAction& o = *(optimal_action);
	game.play(o);
}

template<class Base>
void Deep<Base>::solve(DeepGame<Base>& e, vectorAction& current)
{
	size_t i;
	size_t count_av_plays;
	size_t current_size;
	size_t evaluate;
    std::unique_ptr<DeepGame<Base>> copy;
	vectorAction array;
	bool lost;
	bool won;
	bool has_won_solution;

	lost = e.isLost();
	won = e.isWon();
	has_won_solution = (k_won != 0);
	current_size = current.size();
	evaluate = e.evaluate();

	if (
			(current_size == k && evaluate > optimal_evaluation && !has_won_solution)
			|| (won && (k_won >= current_size || !has_won_solution))
			|| (lost && optimal_action.get() == nullptr)
		)
	{
		k_won = (won) ? k : 0;
		optimal_evaluation = (lost) ? 0 : evaluate;
		optimal_action.reset(current[0]->clone());
		return;
	}

	if (current_size == k)
	{
		return;
	}

	array = e.getAvailablePlays();
	count_av_plays = array.size();

	for (i = 0; i < count_av_plays; ++i)
	{
		copy.reset(new DeepGame<Base>(e));
		copy->play(*(array[i]));
		current.emplace_back(move(array[i]));
		solve(*copy, current);
		current.pop_back();
	}
}
