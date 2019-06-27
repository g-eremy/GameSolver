#include <iostream>
#include "lib/lib.h"
#include "lib/vector.h"
#include "flood_it_cell.h"
#include "flood_it_zone.h"

using namespace std;

FloodItZone::FloodItZone(const size_t& index, const size_t& color): index(index), color(color)
{
}

FloodItZone::FloodItZone(const size_t& index, const size_t& color, const size_t& reserve_cells, const size_t& reserve_neighbors):
	index(index),
	color(color)
{
	cells.reserve(reserve_cells);
	neighbors.reserve(reserve_neighbors);
}

FloodItZone::FloodItZone(FloodItZone&& o) noexcept :
	color(move(o.color)),
	cells(move(o.cells)),
	neighbors(move(o.neighbors))
{

}

bool FloodItZone::operator==(const FloodItZone& o)
{
	return (this == &o);
}

bool FloodItZone::operator!=(const FloodItZone& o)
{
	return (this != &o);
}

size_t FloodItZone::getIndex() const
{
	return index;
}

void FloodItZone::setIndex(const size_t& i)
{
	index = i;
}

size_t FloodItZone::getColor() const
{
	return color;
}

void FloodItZone::setColor(const size_t& color)
{
	this->color = color;
}

size_t FloodItZone::countCells() const
{
	return cells.size();
}

FloodItCell& FloodItZone::getCell(const size_t& i) const
{
	return cells[i];
}

bool FloodItZone::hasCell(FloodItCell& e) const
{
	return vector_has_element(cells, e);
}

void FloodItZone::addCell(FloodItCell &cell)
{
	cells.emplace_back(cell);
}

size_t FloodItZone::countNeighbors() const
{
	return neighbors.size();
}

FloodItZone& FloodItZone::getNeighbor(const size_t& i) const
{
	return neighbors[i].get();
}

double FloodItZone::getNeighborWeight(const size_t& i) const
{
	unreferenced_vars(i); // remove warning : i is unused parameter

	return 1;
}

unique_ptr<IAction> FloodItZone::getNeighborAction(const size_t& i) const
{
	FloodItZone& e = neighbors[i];
	size_t color = e.getColor();
	unique_ptr<IAction> r (new FloodItAction(color));

	return r;
}

bool FloodItZone::hasNeighbor(FloodItZone& zone) const
{
	return vector_has_element(neighbors, zone);
}

void FloodItZone::addNeighbor(FloodItZone& zone)
{
	if (&zone == this)
	{
		return;
	}

	// if hasNeighbor(zone) return > need to be check in FloodIt (optimisation)

	neighbors.emplace_back(zone);
}

void FloodItZone::removeNeighbor(FloodItZone& zone)
{
	vector_remove_element(neighbors, zone);
}

void FloodItZone::mergeZones(FloodItZone& to, FloodItZone& from)
{
	size_t i;
	size_t cells_size;
	size_t neighbors_size;

	cells_size = from.countCells();
	neighbors_size = from.countNeighbors();

	for (i = 0; i < cells_size; ++i)
	{
		from.getCell(i).setZone(to);
	}

	for (i = 0; i < neighbors_size; ++i)
	{
		FloodItZone& from_neighbor = from.neighbors[i];

		if (!to.hasNeighbor(from_neighbor))
		{
			to.addNeighbor(from_neighbor);
		}

		if (!from_neighbor.hasNeighbor(to))
		{
			from_neighbor.addNeighbor(to);
		}

		from_neighbor.removeNeighbor(from);
	}
}
