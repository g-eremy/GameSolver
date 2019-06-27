#include <QDebug>
#include "brute_force.h"

template<class Base>
BruteForce<Base>::BruteForce(BruteForceGame<Base>& game, const size_t& limit_max): game(game), cursor(0), limit_max(limit_max)
{
	vectorAction init_current;

	solve(game, init_current);
}

template<class Base>
void BruteForce<Base>::play()
{
	IAction& o = *(actions[cursor]);
	game.play(o);
	++cursor;
}

template<class Base>
void BruteForce<Base>::selectActions(const vectorAction& array)
{
	size_t i;
	size_t count;

	count = array.size();
	actions.clear();
	actions.reserve(count);

	for (i = 0; i < count; ++i)
	{
		actions.emplace_back(array[i]->clone());
	}
}


template<class Base>
void BruteForce<Base>::solve(BruteForceGame<Base>& e, vectorAction& current)
{
	size_t i;
	size_t count_av_plays;
	std::unique_ptr<BruteForceGame<Base>> copy;
	vectorAction array;
	bool lost;
	bool won;

	if (limit_max != 0 && current.size() >= limit_max)
	{
		return;
	}

	lost = e.isLost();
	won = e.isWon();

	if (lost || won)
	{
		if (won || limit_max == 0)
		{
			limit_max = current.size();
			selectActions(current);
		}

		return;
	}

	array = e.getAvailablePlays();
	count_av_plays = array.size();

	if (count_av_plays == 0)
	{
		return;
	}

	for (i = 0; i < count_av_plays; ++i)
	{
		copy.reset(new BruteForceGame<Base>(e));
		copy->play(*(array[i]));

		current.emplace_back(move(array[i]));

		solve(*copy, current);

		current.pop_back();
	}
}

