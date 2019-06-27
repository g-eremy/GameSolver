#ifndef RANDOM_H
#define RANDOM_H

#include <random>

template<typename T>
class Random
{
	private:
		static std::mt19937 gen;
		std::uniform_int_distribution<T> dist;

	public:
		Random(const T&, const T&);
		T generate();
};

#include "random.tpp"

#endif // RANDOM_H
