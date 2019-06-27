#ifndef GLOUTON_H
#define GLOUTON_H

#include "herustic/interfaces/iherustic.h"
#include "glouton_game.h"

template<class Base>
class Glouton : public IHerustic
{       
	using uniqueAction = std::unique_ptr<IAction>;
	using vectorAction = std::vector<uniqueAction>;

    protected:
        GloutonGame<Base>& game;

    public:
        Glouton(GloutonGame<Base>&);
        virtual ~Glouton() = default;
        virtual void play();
};

#include "glouton.tpp"

#endif // GLOUTON_H
