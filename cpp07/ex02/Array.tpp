#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>

/* Construction with no parameter: Creates an empty array.*/
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

/*Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.*/
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
    std::cout << "Array of size " << n << " was created." << std::endl;
    for (size_t i = 0; i < _size; ++i)
        _array[i] = T();
}

/*Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.*/
template <typename T>
Array<T>::Array(const Array& copy) : _size(copy._size) 
{
    _array = new T[_size];
    for (size_t i = 0; i < _size; ++i)
        _array[i] = copy._array[i];
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

/*Elements can be accessed through the subscript operator: [ ].
When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.*/
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
