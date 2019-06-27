#include "deep_game.h"

template<class Base>
DeepGame<Base>::DeepGame(const DeepGame<Base>& o) : Base(o)
{

}

template<class Base>
DeepGame<Base>::DeepGame(const IGame& o) : Base(o)
{

}
