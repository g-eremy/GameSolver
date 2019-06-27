#include "tabu_game.h"

template<class Base>
TabuGame<Base>::TabuGame(const TabuGame<Base>& o) : Base(o)
{

}

template<class Base>
TabuGame<Base>::TabuGame(const IGame& o) : Base(o)
{

}
