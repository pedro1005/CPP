#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

// Base destructor implementation
Base::~Base() {}

// Randomly generate an instance of A, B, or C
Base* generate() {
    
    int r = std::rand() % 3;
    if (r == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A;
    } else if (r == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B;
    } else {
        std::cout << "Generated: C" << std::endl;
        return new C;
    }
}

// Identify type by pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
    else
        std::cout << "Type: Unknown" << std::endl;
}

// Identify type by reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Type: Unknown" << std::endl;
}
