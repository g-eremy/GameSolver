#include "flood_it_graph.h"

template<class Base>
FloodItGraph<Base>::FloodItGraph(const FloodItGraph& o): Base(o)
{

}

template<class Base>
FloodItGraph<Base>::FloodItGraph(const IGame& o): Base(o)
{

}

template<class Base>
size_t FloodItGraph<Base>::getRoot() const
{
	FloodItCell& cell = *(matrix[begin_y][begin_x]);
	FloodItZone& zone = cell.getZone();

	return zone.getIndex();
}

template<class Base>
size_t FloodItGraph<Base>::countNodes() const
{
	return all_zones.size();
}

template<class Base>
INode& FloodItGraph<Base>::getNode(const size_t& i) const
{
	return *(all_zones[i]);
}
