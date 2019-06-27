#ifndef FLOOD_IT_ZONE_H
#define FLOOD_IT_ZONE_H

#include <memory>
#include <vector>
#include "flood_it_cell.h"
#include "flood_it_action.h"
#include "herustic/interfaces/inode.h"

class FloodItCell;

class FloodItZone : public INode
{
	protected:
		size_t index;
		size_t color;
		std::vector<std::reference_wrapper<FloodItCell>> cells;
		std::vector<std::reference_wrapper<FloodItZone>> neighbors;

	public:
		FloodItZone(const size_t&, const size_t&);
		FloodItZone(const size_t&, const size_t&, const size_t&, const size_t&);
		FloodItZone(FloodItZone&&) noexcept;
		virtual ~FloodItZone() = default;

		// operators
		virtual bool operator==(const FloodItZone&);
		virtual bool operator!=(const FloodItZone&);

		// instance methods

		// index
		virtual size_t getIndex() const;
		virtual void setIndex(const size_t&);

		//color
		virtual size_t getColor() const;
		virtual void setColor(const size_t&);

		// cells
		virtual size_t countCells() const;
		virtual FloodItCell& getCell(const size_t&) const;
		virtual bool hasCell(FloodItCell&) const;
		virtual void addCell(FloodItCell&);

		// neighbors
		virtual size_t countNeighbors() const;
		virtual double getNeighborWeight(const size_t&) const;
		virtual std::unique_ptr<IAction> getNeighborAction(const size_t&) const;
		virtual FloodItZone& getNeighbor(const size_t&) const;
		virtual bool hasNeighbor(FloodItZone&) const;
		virtual void addNeighbor(FloodItZone&);
		virtual void removeNeighbor(FloodItZone&);

		// static methods
		static void mergeZones(FloodItZone&, FloodItZone&);
};

#endif // ZONE_H
