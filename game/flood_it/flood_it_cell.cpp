#include <QDebug>
#include "flood_it.h"
#include "flood_it_zone.h"
#include "flood_it_cell.h"

using namespace std;

FloodItCell::FloodItCell(FloodItZone& zone, const size_t& x, const size_t& y, const size_t& color): zone(ref(zone)), x(x), y(y), original_color(color)
{

}

FloodItCell::FloodItCell(FloodItCell&& o) noexcept : zone(move(o.zone)), x(move(o.x)), y(move(o.y)), original_color(move(o.original_color))
{

}

bool FloodItCell::operator==(const FloodItCell& o)
{
	return (this == &o);
}

bool FloodItCell::operator!=(const FloodItCell& o)
{
	return (this != &o);
}

FloodItZone& FloodItCell::getZone() const
{
	return zone.get();
}

void FloodItCell::setZone(FloodItZone& zone)
{
	this->zone = ref(zone);
	zone.addCell(*this);
}

size_t FloodItCell::getX() const
{
	return x;
}

size_t FloodItCell::getY() const
{
	return y;
}

size_t FloodItCell::getOriginalColor() const
{
	return original_color;
}

size_t FloodItCell::getColor() const
{
	return getZone().getColor();
}
