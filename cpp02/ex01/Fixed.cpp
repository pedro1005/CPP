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

Fixed::Fixed(const int number) : fixedPointValue(number << fracBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    // scalling factor: 1 << fracBits
    this->fixedPointValue = roundf(number * (1 << fracBits));
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

float Fixed::toFloat(void) const
{
    float   res;

    res = static_cast<float>(this->fixedPointValue) / (1 << fracBits);
    return (res);
}

int Fixed::toInt(void) const
{
    int res;

    res = this->fixedPointValue >> fracBits;
    return (res);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}