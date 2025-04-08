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
        Fixed(void);
        Fixed(const Fixed &fp2);
        Fixed(const int number);
        Fixed(const float number);

        Fixed &operator = (const Fixed &fp2);
        
        
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif
