#ifndef GLOUTON_GAME_H
#define GLOUTON_GAME_H

#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"
#include "herustic/interfaces/ievaluable_action.h"

template<class Base>
class GloutonGame : public Base, public virtual IPlayable, public virtual IEvaluableAction
{
    public:
        GloutonGame(const GloutonGame<Base>&);
        GloutonGame(const IGame&);
        virtual ~GloutonGame() = default;
};

#include "glouton_game.tpp"

#endif // GLOUTON_GAME_H
