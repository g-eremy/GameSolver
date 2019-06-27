#include "flood_it_playable.h"
#include "game/flood_it/flood_it_action.h"

template<class Base>
FloodItPlayable<Base>::FloodItPlayable(const FloodItPlayable& game): Base(game)
{

}

template<class Base>
FloodItPlayable<Base>::FloodItPlayable(const IGame& game): Base(game)
{

}

template<class Base>
void FloodItPlayable<Base>::play(IAction& action)
{
	size_t new_color = static_cast<FloodItAction&>(action).getColor();
	FloodIt::play(new_color);
}

template<class Base>
bool FloodItPlayable<Base>::isLost() const
{
	return false;
}

template<class Base>
bool FloodItPlayable<Base>::isWon() const
{
	return Base::isWon();
}

template<class Base>
std::vector<std::unique_ptr<IAction>> FloodItPlayable<Base>::getAvailablePlays() const
{
	size_t i;
	size_t color;
	size_t count;
	vectorAction result;
	std::vector<bool> temp (nb_colors, false);

    FloodItCell& cell = *(matrix[begin_y][begin_x]);
	FloodItZone& zone = cell.getZone();
	count = zone.countNeighbors();

	for (i = 0; i < count; ++i)
	{
		color = zone.getNeighbor(i).getColor();
		temp[color] = true;
	}

	for (i = 0; i < nb_colors; ++i)
	{
		if (!temp[i])
		{
			continue;
		}

		result.emplace_back(new FloodItAction(i));
	}

	return result;
}
