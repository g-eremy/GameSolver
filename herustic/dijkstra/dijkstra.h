#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <memory>
#include "dijkstra_game.h"
#include "herustic/interfaces/iherustic.h"
#include "herustic/interfaces/iaction.h"

template<class Base>
class Dijkstra : public IHerustic
{
	protected:
		// attributes
		DijkstraGame<Base>& game;
		std::vector<std::unique_ptr<IAction>> actions;
		size_t cursor;

		// static methods
		static size_t getMin(const std::vector<double>&, const std::vector<bool>&, const size_t&);
		static size_t getMax(const std::vector<double>&, const size_t&);

		// instances methods
		void solve();
		void makeAction(const std::vector<double>&, const std::vector<size_t>&, const std::vector<size_t>&);

	public:
		Dijkstra(DijkstraGame<Base>&);
		virtual ~Dijkstra() = default;

		void play();
};

#include "dijkstra.tpp"

#endif // DIJKSTRA_H
