#ifndef FLOOD_IT_H
#define FLOOD_IT_H

#include <memory>
#include <vector>
#include "herustic/interfaces/igame.h"
#include "flood_it_cell.h"

class FloodIt : public IGame
{
	protected:
		// attributes
		size_t size;
		size_t nb_colors;
		size_t count_move;
		size_t begin_x;
		size_t begin_y;
		std::vector<std::vector<std::unique_ptr<FloodItCell>>> matrix;
		std::vector<std::unique_ptr<FloodItZone>> all_zones;

		// methods
        virtual void initZone();
		virtual void makeZone(const size_t&, const size_t&, FloodItZone&);

	public:
		static FloodItZone&& temp_zone;

		FloodIt(const size_t&, const size_t&);
		FloodIt(const size_t&, const size_t&, size_t**);
		FloodIt(const FloodIt&);
		FloodIt(const IGame&);
		FloodIt(FloodIt&&) noexcept;
		virtual ~FloodIt() = default;

		// instance methods

		// nb_colors
		virtual size_t getNbColors() const;

		// matrix
		virtual size_t getSize() const;
		virtual bool checkPosition(const size_t&, const size_t&) const;
		virtual FloodItCell& getCell(const size_t&, const size_t&) const;

		// all_zones
		virtual size_t countZones() const;

		// count_move
		virtual size_t getCountMove() const;
		virtual size_t getMaxMove() const;

		// play
		virtual bool isWon() const;
		virtual void play(const size_t&);

		// begin x & y
		virtual size_t getBeginX() const;
		virtual size_t getBeginY() const;
};

#endif // FLOOD_IT_H
