#include <algorithm>
#include <QDebug>
#include "vector.h"
#include <iostream>

template <class T, class Container>
size_t vector_index_of(const Container& vector, const T& e)
{
	return (std::find(vector.begin(), vector.end(), e) - vector.begin());
}

template <class T, class Container>
bool vector_has_element(const Container& vector, const T& e)
{
	return (vector_index_of(vector, e) < vector.size());
}

template <class T, class Container>
size_t vector_remove_element(Container& vector, const T& e)
{
	size_t index = vector_index_of(vector, e);

	if (index >= vector.size())
	{
		return vector.size();
	}

	size_t last = vector.size() - 1;
	std::swap(vector[index], vector[last]);
	vector.pop_back();

	return index;
}

