#ifndef PLAYABLE_H
#define PLAYABLE_H

#include <memory>
#include "iaction.h"
#include "lib/vector.h"

class IPlayable
{
	public:
		virtual ~IPlayable() = default;

		virtual void play(IAction&) = 0;
		virtual bool isLost() const = 0;
		virtual bool isWon() const = 0;
		virtual std::vector<std::unique_ptr<IAction>> getAvailablePlays() const = 0;
};

#endif // PLAYABLE_H
