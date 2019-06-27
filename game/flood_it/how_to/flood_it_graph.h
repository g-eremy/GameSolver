#ifndef FLOOD_IT_GRAPH_H
#define FLOOD_IT_GRAPH_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/igraph.h"

template<class Base = FloodIt>
class FloodItGraph : public Base, public virtual IGraph
{
	protected:
		// attributes
		using Base::size;
		using Base::nb_colors;
		using Base::count_move;
		using Base::begin_x;
		using Base::begin_y;
		using Base::matrix;
		using Base::all_zones;

	public:
		FloodItGraph(const FloodItGraph&);
		FloodItGraph(const IGame&);
		virtual ~FloodItGraph() = default;

		virtual size_t getRoot() const;
		virtual size_t countNodes() const;
		virtual INode& getNode(const size_t&) const;
};

#include "flood_it_graph.tpp"

#endif // FLOOD_IT_GRAPH_H
