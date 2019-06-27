#ifndef DEEP_GAME_H
#define DEEP_GAME_H

#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"
#include "herustic/interfaces/ievaluable_game.h"

template<class Base>
class DeepGame : public Base, public virtual IPlayable, public virtual IEvaluableGame
{
	private:
		using uniqueAction = std::unique_ptr<IAction>;
		using vectorAction = std::vector<uniqueAction>;

	public:
		DeepGame(const DeepGame<Base>&);
		DeepGame(const IGame&);
		virtual ~DeepGame() = default;
};

#include "deep_game.tpp"

#endif // DEEP_GAME_H
