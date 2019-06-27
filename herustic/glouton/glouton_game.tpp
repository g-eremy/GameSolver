#include "glouton_game.h"

template<class Base>
GloutonGame<Base>::GloutonGame(const GloutonGame<Base>& o) : Base(o)
{

}

template<class Base>
GloutonGame<Base>::GloutonGame(const IGame& o) : Base(o)
{

}
