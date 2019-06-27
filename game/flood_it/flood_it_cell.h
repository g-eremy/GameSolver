#ifndef FLOOD_IT_CELL_H
#define FLOOD_IT_CELL_H

#include <functional>
#include "flood_it_zone.h"

class FloodItZone;

class FloodItCell
{
	private:
		std::reference_wrapper<FloodItZone> zone;
		const size_t x;
		const size_t y;
		const size_t original_color;

	public:
		FloodItCell(FloodItZone&, const size_t&, const size_t&, const size_t&);
		FloodItCell(FloodItCell&&) noexcept;
		virtual ~FloodItCell() = default;

		// instance methods

		// operators
		virtual bool operator==(const FloodItCell&);
		virtual bool operator!=(const FloodItCell&);

		// zone
		virtual FloodItZone& getZone() const;
		virtual void setZone(FloodItZone&);

		//x
		virtual size_t getX() const;

		// y
		virtual size_t getY() const;

		// color
		virtual size_t getOriginalColor() const;
		virtual size_t getColor() const;
};

#endif // FLOOD_IT_ROW_H
