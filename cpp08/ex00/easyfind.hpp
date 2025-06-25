#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <class T>
typename T::iterator easyfind (T &t, int value);

#include "easyfind.tpp"

#endif