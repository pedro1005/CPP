#include "Fixed.hpp"

/*int main( void )
{
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed(1234.4321f);
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}*/

int main() {
    std::cout << "\n--- Testing Constructors ---\n" << std::endl;
    
    Fixed a; // Default constructor
    Fixed b(10); // Constructor with int
    Fixed c(10.5f); // Constructor with float
    Fixed d = c; // Copy constructor
    
    std::cout << "\n--- Testing Output Operator (<<) ---\n" << std::endl;
    std::cout << "Fixed b (int 10): " << b << std::endl;
    std::cout << "Fixed c (float 10.5): " << c << std::endl;
    std::cout << "FixedPointValue of c: " << c.getRawBits() << std::endl;
    
    std::cout << "\n--- Testing Conversion Functions ---\n" << std::endl;
    std::cout << "b.toInt(): " << b.toInt() << std::endl;
    std::cout << "c.toInt(): " << c.toInt() << std::endl;
    std::cout << "c.toFloat(): " << c.toFloat() << std::endl;
    
    std::cout << "\n--- Testing Assignation Operator ---\n" << std::endl;
    Fixed e;
    e = b; // Assignment operator
    std::cout << "Fixed e (assigned from b): " << e << std::endl;
    
    return 0;
}