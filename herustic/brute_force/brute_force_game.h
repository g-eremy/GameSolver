#ifndef BRUTE_FORCE_GAME_H
#define BRUTE_FORCE_GAME_H

#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"

template<class Base>
class BruteForceGame : public Base, public virtual IPlayable
{
	using uniqueAction = std::unique_ptr<IAction>;
	using vectorAction = std::vector<uniqueAction>;

	public:
		BruteForceGame(const BruteForceGame<Base>&);
		BruteForceGame(const IGame&);
		virtual ~BruteForceGame() = default;
};

#include "brute_force_game.tpp"

#endif // BRUTE_FORCE_GAME_H
