#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, int length, void (*func)(T const&)) {
    for (int i = 0; i < length; ++i)
        func(array[i]);
}

template <class T>
void printIt(const T &element)
{
    std::cout << element << std::endl;
}
#endif
