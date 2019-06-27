#include <utility>
#include "flood_it_action.h"

using namespace std;

FloodItAction::FloodItAction(const size_t& color): color(color)
{

}

FloodItAction::FloodItAction(const FloodItAction& o): color(o.color)
{

}

FloodItAction::FloodItAction(FloodItAction&& o) noexcept : color(move(o.color))
{

}

bool FloodItAction::operator ==(const FloodItAction& o)
{
	return color == o.color;
}

bool FloodItAction::operator ==(const size_t& o)
{
	return color == o;
}

size_t FloodItAction::getColor() const
{
	return color;
}

IAction* FloodItAction::clone() const
{
	return (new FloodItAction(*this));
}
