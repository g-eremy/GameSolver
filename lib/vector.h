#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <memory>

template <class T, class Container = std::vector<T>>
size_t vector_index_of(const Container&, const T&);

template <class T, class Container = std::vector<T>>
bool vector_has_element(const Container&, const T&);

template <class T, class Container = std::vector<T>>
size_t vector_remove_element(Container&, const T&);

#include "vector.tpp"

#endif // VECTOR_H
