#ifndef DUMB_HERUSTIC_H
#define DUMB_HERUSTIC_H

#include "herustic/interfaces/iherustic.h"
#include "dumb_game.h"

template<class Pl>
class Dumb : public IHerustic
{
	protected:
		 DumbGame<Pl>& game;

	public:
		Dumb(DumbGame<Pl>&);
		virtual ~Dumb() = default;

		virtual void play();
};

#include "dumb.tpp"

#endif // DUMB_HERUSTIC_H
