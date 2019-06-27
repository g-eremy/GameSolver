#ifndef DIJKSTRA_GAME_H
#define DIJKSTRA_GAME_H

#include "herustic/interfaces/igraph.h"
#include "herustic/interfaces/igame.h"
#include "herustic/interfaces/iplayable.h"

template<class Base>
class DijkstraGame : public Base, public virtual IGraph, public virtual IPlayable
{
	public:
		DijkstraGame(const DijkstraGame<Base>&);
		DijkstraGame(const IGame&);
		virtual ~DijkstraGame() = default;
};

#include "dijkstra_game.tpp"

#endif // DIJKSTRA_GAME_H
