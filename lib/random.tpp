#include "random.h"

template<typename T>
std::mt19937 Random<T>::gen = std::mt19937(std::random_device()());

template<typename T>
Random<T>::Random(const T& from, const T& to): dist(from, to)
{

}

template<typename T>
T Random<T>::generate()
{
	return dist(gen);
}

