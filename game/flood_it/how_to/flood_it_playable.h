#ifndef FLOOD_IT_PLAYABLE_H
#define FLOOD_IT_PLAYABLE_H

#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/iaction.h"
#include "herustic/interfaces/iplayable.h"

template<class Base = FloodIt>
class FloodItPlayable : public Base, public virtual IPlayable
{
	private:
		// types
		using uniqueAction = std::unique_ptr<IAction>;
		using vectorAction = std::vector<uniqueAction>;

	protected:
		// attributes
		using Base::size;
		using Base::nb_colors;
		using Base::count_move;
		using Base::begin_x;
		using Base::begin_y;
		using Base::matrix;
		using Base::all_zones;

		// overridden methods
		using Base::play;

	public:
		FloodItPlayable(const FloodItPlayable&);
		FloodItPlayable(const IGame&);

		virtual ~FloodItPlayable() = default;

		virtual void play(IAction&);
		virtual bool isLost() const;
		virtual bool isWon() const;
		virtual vectorAction getAvailablePlays() const;
};

#include "flood_it_playable.tpp"

#endif // FLOOD_IT_PLAYABLE_H
