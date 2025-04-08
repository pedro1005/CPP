#include <iostream>
#include "Fixed.hpp"

/*int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    if (a == b)
        std::cout << "a and b are equal\n";
    else if (a != b)
        std::cout << "a and b are different\n";
    return 0;
}
*/
int main() {
    std::cout << "========== TESTING CONSTRUCTORS ==========" << std::endl;
    
    Fixed a;               // Default constructor, should be 0
    std::cout << "a (default constructor, should be 0): " << a << std::endl;

    Fixed b(10);           // Int constructor
    std::cout << "b (int constructor, initialized with 10): " << b << std::endl;

    Fixed c(42.42f);       // Float constructor
    std::cout << "c (float constructor, initialized with 42.42): " << c << std::endl;

    Fixed d(b);            // Copy constructor
    std::cout << "d (copy constructor, copied from b which is 10): " << d << std::endl;

    std::cout << "\n========== TESTING ASSIGNMENT OPERATOR ==========" << std::endl;
    a = Fixed(2.5f);  // Assign a new float value
    std::cout << "a (assigned new value 2.5): " << a << std::endl;

    std::cout << "\n========== TESTING COMPARISON OPERATORS ==========" << std::endl;
    std::cout << std::boolalpha;  // Print "true"/"false" instead of 1/0

    std::cout << "b > a? (10 > 2.5) Expected: true -> " << (b > a) << std::endl;
    std::cout << "b < c? (10 < 42.42) Expected: true -> " << (b < c) << std::endl;
    std::cout << "b >= d? (10 >= 10) Expected: true -> " << (b >= d) << std::endl;
    std::cout << "b <= c? (10 <= 42.42) Expected: true -> " << (b <= c) << std::endl;
    std::cout << "b == d? (10 == 10) Expected: true -> " << (b == d) << std::endl;
    std::cout << "b != c? (10 != 42.42) Expected: true -> " << (b != c) << std::endl;

    std::cout << "\n========== TESTING ARITHMETIC OPERATORS ==========" << std::endl;
    std::cout << "b + c (10 + 42.42) Expected: 52.42 -> " << (b + c) << std::endl;
    std::cout << "c - b (42.42 - 10) Expected: 32.42 -> " << (c - b) << std::endl;
    std::cout << "b * c (10 * 42.42) Expected: 424.22 -> " << (b * c) << std::endl;
    std::cout << "c / b (42.42 / 10) Expected: 4.24 -> " << (c / b) << std::endl;

    std::cout << "\n========== TESTING INCREMENT & DECREMENT OPERATORS ==========" << std::endl;
    Fixed e; // Starts at 0
    std::cout << "e (before increment, should be 0): " << e.toInt() << std::endl;
    std::cout << "Pre-increment (++e, should increase e to 1): " << (++e).toInt() << std::endl;
    std::cout << "Post-increment (e++, should show 1 but store 2): " << (e++).toInt() << std::endl;
    std::cout << "e (after increments, should be 2): " << e.toInt() << std::endl;

    
    std::cout << "Pre-decrement (--e, should decrease e to 1): " << (--e).toInt() << std::endl;
    std::cout << "Post-decrement (e--, should show 1 but store 0): " << (e--).toInt() << std::endl;
    std::cout << "e (after decrements, should be 0): " << e.toInt() << std::endl;

    std::cout << "\n========== TESTING MIN/MAX FUNCTIONS ==========" << std::endl;
    std::cout << "Min of b (10) and c (42.42) Expected: 10 -> " << Fixed::min(b, c) << std::endl;
    std::cout << "Max of b (10) and c (42.42) Expected: 42.42 -> " << Fixed::max(b, c) << std::endl;
    
    return 0;
}
