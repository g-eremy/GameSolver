#ifndef LIB_H
#define LIB_H

#include <vector>
#include <memory>
#include <string>

template <class T>
bool operator==(const std::reference_wrapper<T>&, const T&);

template <class T>
bool operator==(const std::unique_ptr<T>& a, const T* b);

template<typename... T>
inline void unreferenced_vars(T&&...);

void read_directory(const std::string&, std::vector<std::string>&);

#include "lib.tpp"

#endif // LIB_H
