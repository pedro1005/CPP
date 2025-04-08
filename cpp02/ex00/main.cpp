#include "Fixed.hpp"

int main(void)
{
    Fixed   a;
    Fixed   b(a);
    Fixed   c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    c.setRawBits(42);
    std::cout << c.getRawBits() << std::endl;

    return (0);
}