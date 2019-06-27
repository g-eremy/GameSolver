#ifndef DUMB_GAME_H
#define DUMB_GAME_H

#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"

template<class Pl>
class DumbGame : public Pl, public virtual IPlayable
{
	using uniqueAction = std::unique_ptr<IAction>;
	using vectorAction = std::vector<uniqueAction>;

	public:
		DumbGame(const DumbGame<Pl>&);
		DumbGame(const IGame&);
		virtual ~DumbGame() = default;
};

#include "dumb_game.tpp"

#endif // DUMB_GAME_H
