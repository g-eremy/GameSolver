#ifndef IEVALUABLE_ACTION_H
#define IEVALUABLE_ACTION_H

#include <memory>
#include "iaction.h"

class IEvaluableAction
{
	public:
		virtual ~IEvaluableAction() = default;

        virtual size_t evaluate(IAction&) = 0;
};

#endif // IEVALUABLE_ACTION_H
