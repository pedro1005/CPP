#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 fixedPointValue;
        static const int    fracBits = 8;
    public:

        // Constructors
        Fixed(void);
        Fixed(const Fixed &fp2);
        Fixed(const int number);
        Fixed(const float number);

        // Destructor
        ~Fixed();

        // Copy Assignement 
        Fixed   &operator = (const Fixed &fp2);

        // Comparison operators
        bool    operator > (const Fixed &fp2) const;
        bool    operator < (const Fixed &fp2) const;
        bool    operator >= (const Fixed &fp2) const;
        bool    operator <= (const Fixed &fp2) const;
        bool    operator == (const Fixed &fp2) const;
        bool    operator != (const Fixed &fp2) const;

        // Arithmetic operators
        Fixed   operator + (const Fixed &fp2) const;
        Fixed   operator - (const Fixed &fp2) const;
        Fixed   operator * (const Fixed &fp2) const;
        Fixed   operator / (const Fixed &fp2) const;

        // Increment/Decrement operators
        Fixed   &operator ++ ();    // Pre-increment
        Fixed   operator ++ (int);  // Post-increment
        Fixed   &operator -- ();    // Pre-decrement
        Fixed   operator -- (int);  // Post-decrement
        
        
        
        // Getter & Setter
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        // Conversion methods
        float   toFloat(void) const;
        int     toInt(void) const;

        // Min/Max functions
        static Fixed        &min(Fixed &fp1, Fixed &fp2);
        static const Fixed  &min(const Fixed &fp1, const Fixed &fp2);
        static Fixed        &max(Fixed &fp1, Fixed &fp2);
        static const Fixed  &max(const Fixed &fp1, const Fixed &fp2);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
