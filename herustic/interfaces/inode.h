#ifndef INODE_H
#define INODE_H

#include <memory>
#include "herustic/interfaces/iaction.h"

class INode
{
	public:
		virtual size_t getIndex() const = 0;
		virtual size_t countNeighbors() const = 0;
		virtual INode& getNeighbor(const size_t&) const = 0;
		virtual double getNeighborWeight(const size_t&) const = 0;
		virtual std::unique_ptr<IAction> getNeighborAction(const size_t&) const = 0;
};

#endif // INODE_H
