#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>
#include <cstdlib>

template <class T>
class Array
{
private:
    T* _array;
    size_t _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& copy);
    Array& operator=(const Array& copy);
    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;


    size_t size(void) const;

    class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


#include "Array.tpp"
#endif