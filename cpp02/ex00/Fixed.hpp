#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 fixedPointValue;    // binary point position within the number
        static const int    fracBits = 8;       // width of the number representation
    public:
        Fixed(void);
        Fixed(const Fixed &fp2);
        Fixed &operator = (const Fixed &fp2);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
