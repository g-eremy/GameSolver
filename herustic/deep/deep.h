#ifndef DEEP_H
#define DEEP_H

#include <vector>
#include <memory>
#include "herustic/interfaces/iherustic.h"
#include "deep_game.h"

template<class Base>
class Deep : public IHerustic
{
	using uniqueAction = std::unique_ptr<IAction>;
	using vectorAction = std::vector<uniqueAction>;

	protected:
		DeepGame<Base>& game;
		uniqueAction optimal_action;
		size_t optimal_evaluation;
		size_t k;
		size_t k_won;

		virtual void solve(DeepGame<Base>&, vectorAction&);

	public:
		Deep(DeepGame<Base>&, const size_t& = 3);
		virtual ~Deep() = default;
		virtual void play();
};

#include "deep.tpp"

#endif // DEEP_H
