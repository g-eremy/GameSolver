#include <iostream>
#include "flood_it.h"
#include "lib/lib.h"
#include "lib/random.h"
#include "lib/vector.h"
#include "lib/benchmark.h"

using namespace std;

FloodItZone&& FloodIt::temp_zone = FloodItZone(0, 0);

FloodIt::FloodIt(const size_t& s, const size_t& n):
	size(s),
	nb_colors(n),
	count_move(0),
	begin_x(0),
	begin_y(0),
	matrix(size)
{
	size_t i;
	size_t j;

	Random<size_t> randomizer (0, (nb_colors - 1));

	for (i = 0; i < size; ++i)
	{
		matrix[i].reserve(size);

		for (j = 0; j < size; ++j)
		{
			matrix[i].emplace_back(new FloodItCell(temp_zone, j, i, randomizer.generate()));
		}
	}

    initZone();
}

FloodIt::FloodIt(const size_t& s, const size_t& n, size_t** game):
    size(s),
    nb_colors(n),
    count_move(0),
    begin_x(0),
	begin_y(0),
	matrix(size)
{
   size_t i;
   size_t j;

   for (i = 0; i < size; ++i)
   {
       matrix[i].reserve(size);

       for (j = 0; j < size; ++j)
       {
           matrix[i].emplace_back(new FloodItCell(temp_zone, j, i, game[i][j]));
       }
   }

   initZone();
}

FloodIt::FloodIt(const FloodIt& game):
	size(game.size),
	nb_colors(game.nb_colors),
	count_move(game.count_move),
	begin_x(game.begin_x),
	begin_y(game.begin_y),
	matrix(game.size)
{
	size_t i;
	size_t j;
	size_t cell_x;
	size_t cell_y;
	size_t cell_color;
	size_t all_zones_size;
	size_t cells_size;
	size_t neighbors_size;

	FloodItZone* new_zone;

	for (i = 0; i < size; ++i)
	{
		matrix[i].reserve(size);

		for (j = 0; j < size; ++j)
		{
			matrix[i].emplace_back(nullptr);
		}
	}

	all_zones_size = game.all_zones.size();
	all_zones.reserve(all_zones_size);

	for (i = 0; i < all_zones_size; ++i)
	{
		FloodItZone& old_zone = *(game.all_zones[i]);
		cells_size = old_zone.countCells();
		neighbors_size = old_zone.countNeighbors();

		new_zone = new FloodItZone(old_zone.getIndex(), old_zone.getColor(), old_zone.countCells(), old_zone.countNeighbors());
		all_zones.emplace_back(new_zone);

		for (j = 0; j < cells_size; ++j)
		{
			FloodItCell& old_cell = old_zone.getCell(j);

			cell_x = old_cell.getX();
			cell_y = old_cell.getY();
			cell_color = old_cell.getColor();

			matrix[cell_y][cell_x].reset(new FloodItCell(temp_zone, cell_x, cell_y, cell_color));
			matrix[cell_y][cell_x]->setZone(*new_zone);
		}

		for (j = 0; j < neighbors_size; ++j)
		{
			FloodItZone& old_neighbor = old_zone.getNeighbor(j);
			FloodItCell& temp_cell = old_neighbor.getCell(0);

			cell_x = temp_cell.getX();
			cell_y = temp_cell.getY();

			if (matrix[cell_y][cell_x].get() == nullptr)
			{
				continue;
			}

			FloodItZone& new_neighbor = matrix[cell_y][cell_x]->getZone();

			all_zones[i]->addNeighbor(new_neighbor);
			new_neighbor.addNeighbor(*(all_zones[i]));
		}
	}
}

FloodIt::FloodIt(const IGame& game): FloodIt(static_cast<const FloodIt&>(game))
{

}

FloodIt::FloodIt(FloodIt&& game) noexcept :
	size(move(game.size)),
	nb_colors(move(game.nb_colors)),
	count_move(move(game.count_move)),
	begin_x(move(game.begin_x)),
	begin_y(move(game.begin_y)),
	matrix(move(game.size)),
	all_zones(move(game.all_zones))
{

}

size_t FloodIt::getNbColors() const
{
	return nb_colors;
}

size_t FloodIt::getSize() const
{
	return size;
}

bool FloodIt::checkPosition(const size_t& x, const size_t& y) const
{
	return (x < size && y < size);
}

FloodItCell& FloodIt::getCell(const size_t& x, const size_t& y) const
{
	return *(matrix[y][x]);
}

size_t FloodIt::countZones() const
{
	return all_zones.size();
}

size_t FloodIt::getCountMove() const
{
    return count_move;
}

size_t FloodIt::getMaxMove() const
{
	return 25 * (size * nb_colors) / 84;
}

bool FloodIt::isWon() const
{
	return (all_zones.size() == 1);
}

void FloodIt::play(const size_t& new_color)
{
	if (matrix[begin_y][begin_x]->getColor() == new_color)
	{
		return;
	}

	size_t i = 0;
	size_t new_index;
	FloodItZone& zone = matrix[begin_y][begin_x]->getZone();
	zone.setColor(new_color);
	++count_move;

	while (i < zone.countNeighbors())
	{
		FloodItZone& neighbor = zone.getNeighbor(i);

		if (neighbor.getColor() != zone.getColor())
		{
			++i;
			continue;
		}

		FloodItZone::mergeZones(zone, neighbor);
		new_index = vector_remove_element(all_zones, &neighbor);

		if (new_index != all_zones.size())
		{
			all_zones[new_index]->setIndex(new_index);
		}
	}

}

size_t FloodIt::getBeginX() const
{
	return begin_x;
}


size_t FloodIt::getBeginY() const
{
	return begin_y;
}

void FloodIt::initZone()
{
    size_t i;
    size_t j;
    FloodItZone* zone;

    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            if (matrix[i][j]->getZone() != temp_zone)
            {
                continue;
            }

            zone = new FloodItZone(all_zones.size(), matrix[i][j]->getOriginalColor());
            all_zones.emplace_back(zone);
            makeZone(j, i, *zone);
        }
    }
}

void FloodIt::makeZone(const size_t& x, const size_t& y, FloodItZone& zone)
{
	if (!checkPosition(x, y))
	{
		return;
	}

	FloodItCell& current = *(matrix[y][x]);
	FloodItZone& current_zone = current.getZone();

	if (current_zone != temp_zone && !current_zone.hasNeighbor(zone))
	{
		zone.addNeighbor(current_zone);
		current_zone.addNeighbor(zone);

		return;
	}

	if (zone.getColor() != current.getOriginalColor())
	{
		return;
	}

	current.setZone(zone);

	makeZone(x, y - 1, zone); // top
	makeZone(x + 1, y, zone); // right
	makeZone(x, y + 1, zone); // bottom
	makeZone(x - 1, y, zone); // left
}
