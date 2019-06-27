#ifndef ACTION_H
#define ACTION_H

class IAction
{
	public:
		virtual ~IAction() = default;
		virtual IAction* clone() const = 0;
};

#endif // ACTION_H
