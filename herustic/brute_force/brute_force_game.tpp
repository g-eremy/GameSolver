#include "brute_force_game.h"

template<class Base>
BruteForceGame<Base>::BruteForceGame(const BruteForceGame<Base>& o): Base(o)
{

}

template<class Base>
BruteForceGame<Base>::BruteForceGame(const IGame& o): Base(o)
{

}
