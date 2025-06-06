#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    for (size_t i = 0; i < _size; ++i)
        _array[i] = T();
}

template <typename T>
Array<T>::Array(const Array& copy) : _array(NULL), _size(0)
{
    *this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        delete[] _array;
        _size = copy._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            _array[i] = copy._array[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _size)
        throw IndexOutOfBoundsException();
    return _array[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}


#endif
