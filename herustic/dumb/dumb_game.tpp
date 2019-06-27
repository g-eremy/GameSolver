#include "dumb_game.h"

template<class Pl>
DumbGame<Pl>::DumbGame(const DumbGame<Pl>& o): Pl(o)
{

}

template<class Pl>
DumbGame<Pl>::DumbGame(const IGame& o): Pl(o)
{

}
