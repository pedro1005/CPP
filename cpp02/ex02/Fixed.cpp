#include "Fixed.hpp"

// Constructors

Fixed::Fixed(void) : fixedPointValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const Fixed &fp2) : fixedPointValue(fp2.fixedPointValue)
{
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
    //std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = number << fracBits;
}

Fixed::Fixed(const float number)
{
    //std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(number * (1 << fracBits));
}


// Destructor

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

// Copy assignment

Fixed &Fixed::operator = (const Fixed &fp2)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fp2)
        this->fixedPointValue = fp2.getRawBits();
    return (*this);
}

// Comparison operators

bool Fixed::operator > (const Fixed &fp2) const
{
    return (this->fixedPointValue > fp2.fixedPointValue);
}

bool Fixed::operator < (const Fixed &fp2) const
{
    return (this->fixedPointValue < fp2.fixedPointValue);
}

bool Fixed::operator >= (const Fixed &fp2) const
{
    return (this->fixedPointValue >= fp2.fixedPointValue);
}

bool Fixed::operator <= (const Fixed &fp2) const
{
    return (this->fixedPointValue <= fp2.fixedPointValue);
}

bool Fixed::operator == (const Fixed &fp2) const
{
    return (this->fixedPointValue == fp2.fixedPointValue);
}

bool Fixed::operator != (const Fixed &fp2) const
{
    return (this->fixedPointValue != fp2.fixedPointValue);
}

// Arithmetic operators
Fixed Fixed::operator + (const Fixed &fp2) const
{
    return (Fixed(this->toFloat() + fp2.toFloat()));
}

Fixed Fixed::operator - (const Fixed &fp2) const
{
    return (Fixed(this->toFloat() - fp2.toFloat()));
}

Fixed Fixed::operator * (const Fixed &fp2) const
{
    return (Fixed(this->toFloat() * fp2.toFloat()));
}

Fixed Fixed::operator / (const Fixed &fp2) const
{
    if (fp2.fixedPointValue == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return (Fixed());
    }
    return (Fixed(this->toFloat() / fp2.toFloat()));
}

// Increment/Decrement

Fixed &Fixed::operator++() {
    this->fixedPointValue += 1; // Increment the fixed-point value
    return *this;  // Return the updated object
}

// Post-increment operator (suffix)
Fixed Fixed::operator++(int) {
    Fixed temp = *this;  // Save the current state of the object
    this->fixedPointValue += 1;  // Increment the value (reuse pre-increment)
    return temp;  // Return the original (non-incremented) object
}

// Pre-decrement operator (prefix)
Fixed &Fixed::operator--() {
    this->fixedPointValue -= 1;  // Decrement the fixed-point value
    return *this;  // Return the updated object
}

// Post-decrement operator (suffix)
Fixed Fixed::operator--(int) {
    Fixed temp = *this;  // Save the current state of the object
    this->fixedPointValue -= 1;  // Decrement the value (reuse pre-decrement)
    return temp;  // Return the original (non-decremented) object
}

// Getter
int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

// Setter
void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

// Conversion
float Fixed::toFloat(void) const
{
    float   res;

    res = static_cast<float>(this->fixedPointValue) / (1 << fracBits);
    return (res);
}

// Min function for non-constant references
Fixed &Fixed::min(Fixed &fp1, Fixed &fp2)
{
    return (fp1 < fp2) ? fp1 : fp2;
}

// Min function for constant references
const Fixed &Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
    return (fp1 < fp2) ? fp1 : fp2;
}

// Max function for non-constant references
Fixed &Fixed::max(Fixed &fp1, Fixed &fp2)
{
    return (fp1 > fp2) ? fp1 : fp2;
}

// Max function for constant references
const Fixed &Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
    return (fp1 > fp2) ? fp1 : fp2;
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