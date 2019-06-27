#ifndef HERUSTIC_H
#define HERUSTIC_H

class IHerustic
{
	public:
		virtual ~IHerustic() = default;
		virtual void play() = 0;
};

#endif // HERUSTIC_H
