#include "dijkstra.h"
#include "lib/vector.h"
#include "herustic/interfaces/inode.h"
#include <algorithm>

template<class Base>
Dijkstra<Base>::Dijkstra(DijkstraGame<Base>& game): game(game), cursor(0)
{

}

template<class Base>
void Dijkstra<Base>::play()
{
	if (cursor == actions.size())
	{
		cursor = 0;
		solve();
	}

	IAction& o = *(actions[cursor]);
	game.play(o);
	++cursor;
}

template<class Base>
size_t Dijkstra<Base>::getMin(const std::vector<double>& distances, const std::vector<bool>& flags, const size_t& count)
{
	size_t r = 0;
	double min = -1;
	double current;

	for (size_t i = 0; i < count; ++i)
	{
		if (flags[i])
		{
			continue;
		}

		current = distances[i];

		if (min == -1 || (current != -1 && current < min))
		{
			r = i;
			min = current;
		}
	}

	return r;
}

template<class Base>
size_t Dijkstra<Base>::getMax(const std::vector<double>& distances, const size_t& count)
{
	size_t r = 0;
	double max = distances[0];
	size_t current;

	for (size_t i = 1; i < count; ++i)
	{
		current = distances[i];

		if (current > max)
		{
			r = i;
			max = current;
		}
	}

	return r;
}

template<class Base>
void Dijkstra<Base>::solve()
{
	size_t count_nodes = game.countNodes();
	size_t count_flagged = 0;
	size_t count_neighbor;
	size_t root = game.getRoot();
	size_t i;
	size_t j;
	size_t k;
	size_t current_distance;
	size_t calc_distance;
	std::vector<bool> flags (count_nodes, false);
	std::vector<double> distances (count_nodes, -1);
	std::vector<size_t> parents;
	std::vector<size_t> neighbors;

	parents.reserve(count_nodes);
	neighbors.reserve(count_nodes);
	distances[root] = 0;
	parents[root] = -1;

	while (count_flagged != count_nodes)
	{
		i = getMin(distances, flags, count_nodes);
		INode& current_node = game.getNode(i);
		current_distance = distances[i];
		count_neighbor = current_node.countNeighbors();
		flags[i] = true;
		++count_flagged;

		for (k = 0; k < count_neighbor; ++k)
		{
			INode& neighbor = current_node.getNeighbor(k);
			j = neighbor.getIndex();

			if (flags[j])
			{
				continue;
			}

			double& neighbor_distance = distances[j];
			calc_distance = current_distance + current_node.getNeighborWeight(k);

			if (neighbor_distance == -1 || neighbor_distance > calc_distance)
			{
				neighbor_distance = calc_distance;
				parents[j] = i;
				neighbors[j] = k;
			}
		}
	}

	makeAction(distances, parents, neighbors);
}

template<class Base>
void Dijkstra<Base>::makeAction(const std::vector<double>& distances, const std::vector<size_t>& parents, const std::vector<size_t>& neighbors)
{
	size_t count_nodes = game.countNodes();
	size_t from = game.getRoot();
	size_t destination = getMax(distances, count_nodes);
	size_t i;
	size_t j;
	size_t k;

	i = destination;
	actions.clear();

	while (i != from)
	{
		j = parents[i];
		k = neighbors[i];
		INode& to = game.getNode(j);
		actions.emplace_back(std::move(to.getNeighborAction(k)));
		i = j;
	}

	std::reverse(actions.begin(), actions.end());
}
