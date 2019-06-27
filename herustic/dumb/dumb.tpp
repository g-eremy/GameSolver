#include <iostream>
#include "dumb.h"
#include "lib/random.h"

template <class Pl>
Dumb<Pl>::Dumb(DumbGame<Pl>& game) : game(game)
{

}

template <class Pl>
void Dumb<Pl>::play()
{
	std::vector<std::unique_ptr<IAction>> vector = game.getAvailablePlays();
	Random<size_t> randomizer (0, (vector.size() - 1));
	size_t randomize = randomizer.generate();
	IAction& action = *(vector[randomize]);
	game.play(action);
}
