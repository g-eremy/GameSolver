#ifndef IGRAPH_H
#define IGRAPH_H

#include "inode.h"

class IGraph
{
	public:
		virtual size_t getRoot() const = 0;
		virtual size_t countNodes() const = 0;
		virtual INode& getNode(const size_t&) const = 0;
};

#endif // IGRAPH_H
