#include <memory>
#include <iostream>
#include "glouton.h"

template<class Base>
Glouton<Base>::Glouton(GloutonGame<Base>& game) : game(game)
{

}

template<class Base>
void Glouton<Base>::play()
{
	vectorAction available_plays = game.getAvailablePlays();
	std::reference_wrapper<IAction> current = std::ref(*available_plays[0]);
	size_t weight;
	size_t max = game.evaluate(current.get());
	size_t count = available_plays.size();

	for(size_t i = 1; i < count; ++i)
	{
		IAction& temp = *(available_plays[i]);
		weight = game.evaluate(temp);
		if(max < weight)
		{
			current = std::ref(temp);
			max = weight;
		}
	}

	game.play(current);
}
