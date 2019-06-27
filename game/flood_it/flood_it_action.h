#ifndef FLOOD_IT_ACTION_H
#define FLOOD_IT_ACTION_H

#include <cstddef>
#include "herustic/interfaces/iaction.h"

class FloodItAction : public IAction
{
	private:
		size_t color;

	public:
		FloodItAction(const size_t&);
		FloodItAction(const FloodItAction&);
		FloodItAction(FloodItAction&&) noexcept;
		virtual ~FloodItAction() = default;

		virtual bool operator==(const FloodItAction&);
		virtual bool operator ==(const size_t&);
		virtual size_t getColor() const;
		virtual IAction* clone() const;
};

#endif // FLOOD_IT_ACTION_H
