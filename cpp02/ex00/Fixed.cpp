#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &fp2) : fixedPointValue(fp2.fixedPointValue)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fp2;
}

Fixed &Fixed::operator = (const Fixed &fp2)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fp2)
        this->fixedPointValue = fp2.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}