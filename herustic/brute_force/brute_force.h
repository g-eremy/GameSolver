#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H

#include <vector>
#include <memory>
#include "herustic/interfaces/iherustic.h"
#include "brute_force_game.h"

template<class Base>
class BruteForce : public IHerustic
{
	using uniqueAction = std::unique_ptr<IAction>;
	using vectorAction = std::vector<uniqueAction>;

	protected:
		BruteForceGame<Base>& game;
		vectorAction actions;
		size_t cursor;
		size_t limit_max;

		virtual void selectActions(const vectorAction&);
		virtual void solve(BruteForceGame<Base>&, vectorAction&);

	public:
		BruteForce(BruteForceGame<Base>&, const size_t& = 0);
		virtual ~BruteForce() = default;
		virtual void play();
};

#include "brute_force.tpp"

#endif // BRUTE_FORCE_H
