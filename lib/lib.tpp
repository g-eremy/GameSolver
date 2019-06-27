#include <sys/types.h>
#include <dirent.h>

#include "lib.h"

template <class T>
bool operator==(const std::reference_wrapper<T>& a, const T& b)
{
	return a.get() == b;
}

template <class T>
bool operator==(const std::unique_ptr<T>& a, const T* b)
{
	return a.get() == b;
}

template<typename... T>
inline void unreferenced_vars(T&&...)
{

}
